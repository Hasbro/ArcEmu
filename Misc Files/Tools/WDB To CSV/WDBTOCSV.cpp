//
// wdbtocsv.cpp :	Converts WDB cache files to comma-delimited CSV files
// Created by:		jb55 (jackbox55@gmail.com)
// Website:			http://www.jb55.com
// License:			see license.txt
//

// includes
#include "stdafx.h"
#include "stdio.h"

#ifdef _SPEED
	#include "time.h"
	#include <sys/timeb.h>
#endif

#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

// typedefs
typedef unsigned long		u32;
typedef unsigned short		u16 ;
typedef unsigned char		u8 ;
typedef signed long			s32;
typedef	signed short		s16 ;
typedef	signed char			s8;

// defines
#define MAXFIELDS 256
#define DELIMETER ","

struct wdbheader_t{
	char signature[4];
	u32 ver;
	char lang[4];
	u32 fields;
	u32 unknown2;
};

union wdbfield_t{
	u32 uival;
	s32 sival;
	float fval;
	char* pchar;
};

enum wdbfieldtypes{
	t_undefined = 1 << 0,
	t_uint = 1 << 1,
	t_sint = 1 << 2,
	t_float = 1 << 3,
	t_bitmask16 = 1 << 4,
	t_bitmask32 = 1 << 5,
	t_str = 1 << 6,
	t_special2byte = 1 << 7
};

char* BM16toString(u32 val){
	char* str = new char[17];

	for(int i=0;i<24;i++){
		if(val & (1<<(15-i)))
			str[i] = '1';
		else
			str[i] = '0';
	}
//	str[16] = 0x00;
	str[24] = 0x00;
	return str;
}


char* BM32toString(u32 val){
	char* str = new char[33];

	for(int i=0;i<32;i++){
		if(val & (1<<(31-i)))
			str[i] = '1';
		else
			str[i] = '0';
	}

	str[32] = 0x00;
	return str;
}

class CWDBDef{
	u16 m_fieldtypes[MAXFIELDS];
	u32 m_fields;
	u16 m_index;
	bool isReadable;
	char signature[4];
	string m_fieldnames[MAXFIELDS];
	string m_wdbname;

public:
	char* getSignature(){ return &signature[0]; }
	char* getFieldName(u32 index){ 
		if( index > m_fields ) 
			return 0;
		if( !m_fieldnames[index-1].c_str() )
			return "";
		return (char*)m_fieldnames[index-1].c_str(); 
	}
	char* getWDBName(){ return (char*)m_wdbname.c_str(); }
	u16 getFieldType(u32 index){
		return m_fieldtypes[index-1];
	}
	u32 getNumFields(){ return m_fields; }

	void addField(u8 fieldtype, char* name){
		m_fieldtypes[m_index] = fieldtype;
		m_fieldnames[m_index] = name;
		m_index++;
		m_fields++;
	}
	void setNumFields(u32 nfields){ 
		m_fields = nfields; 
	}
	void setFieldType(u32 index,u8 fieldtype){ m_fieldtypes[index-1] = fieldtype; }
	void setFieldName(u32 index,char* name){ m_fieldnames[index-1] = name; }
	void setWDBName(char* name){ m_wdbname = name; }
	void setSignature(char* sig){ 
		strcpy(&signature[0],sig); 
		m_index = 0; // HACK: This is terrible, move this...
		m_fields = 0; // HACK: ughkmsdsdfsd
	}

	CWDBDef(u32 fields,char* name){
		m_fields = fields;
		m_wdbname = name;
	}
	CWDBDef(){
		m_fields = 0;
		m_index = 0;
	}
	~CWDBDef(){
	}
};

class CWDBRecord{
	wdbfield_t m_fields[MAXFIELDS];
public:
	wdbfield_t* getField(int index){
		return &m_fields[index-1];
	}
	void addField(wdbfield_t field,int index){
		m_fields[index-1] = field;
	}
};

class CWDB{
	CWDBDef *m_def;
	char *m_data;
	u32 m_datasize;
	vector<CWDBRecord> m_records;
	bool isLoaded;
	wdbheader_t m_header;
public:
	
	bool loadWDB(char* file);

	wdbfield_t* getField(u32 recindex, u32 fieldindex){
		return m_records.at(recindex).getField(fieldindex);
	}
			
	bool toCSV(char* file){

		char *file2 = new char[strlen(file)+5];
		char buff[2048];
		strcpy(file2,file);
		strcat(file2,".csv");

		FILE *pFile = fopen(file2,"w");

		if(!pFile)
			return false;

		// write headers
		for(u32 i=1;i<=m_def->getNumFields();i++){
			if(!strcmp(m_def->getFieldName(i),"\0")){
				fprintf(pFile,"Column %i",i);
			}else{
				fputs(m_def->getFieldName(i),pFile);
			}

			fputs(DELIMETER,pFile);
		}

		fprintf(pFile,"\n");

		// write data
		for(u32 r=0;r<m_records.size();r++){
			for(u32 f=1;f<=m_def->getNumFields();f++){
				
				if(m_def->getFieldType(f) & t_uint){
					fprintf(pFile,"%u",getField(r,f)->uival);
				}else if(m_def->getFieldType(f) & t_sint){
					fprintf(pFile,"%i",getField(r,f)->sival);
				}else if(m_def->getFieldType(f) & t_float){
					fprintf(pFile,"%f",getField(r,f)->fval);
				}else if(m_def->getFieldType(f) & t_str){
					
					// Add quotes around strings to support line breaks and commas
					sprintf(buff,"\x22%s\x22",getField(r,f)->pchar);

					fprintf(pFile,"%s",buff);
				}else if(m_def->getFieldType(f) & t_bitmask16){
					fprintf(pFile,"%s",BM16toString(getField(r,f)->uival));
				}else if(m_def->getFieldType(f) & t_bitmask32){
					fprintf(pFile,"%s",BM32toString(getField(r,f)->uival));
				}else{ // undefined
					fprintf(pFile,"%u",getField(r,f)->uival);
				}

				fputs(DELIMETER,pFile);

			}
			fprintf(pFile,"\n");
		}

		fclose(pFile);

		return true;

	}
	void parseWDB()
	{
		CWDBRecord tRec;
		wdbfield_t tField;
		wdbfield_t recID,recSize;
		wdbfield_t *pm_data = (wdbfield_t*)m_data;
		char *pcm_data;
		u16 *psm_data;
		u32 sLen;
		int i;

		
		// 0xFFFF is just a random number I chose, simply to avoid infinite loops
		// which shouldn't happen anyways...
		for(i=0;i<0xFFFF;i++){
			
			recID = *pm_data; pm_data++;

			if((u32)((char*)pm_data - m_data) >= m_datasize)
				break;

			// break if invalid ID
			if(recID.uival<1)
				break;
			tField.uival = recID.uival;
			tRec.addField(tField,1);

			recSize = *pm_data; pm_data++;
			tField.uival = recSize.uival;

			// break if the size of the record is less then 4 bytes
			if(recSize.uival<4)
				break;
			tRec.addField(tField,2);

			for(u32 j=3;j<=m_def->getNumFields();j++){

				// if the field is a string, the wdbfield will simply contain a pointer to the string
				// in the m_data block
				if(m_def->getFieldType(j) & t_str){
					sLen = strlen((char*)pm_data);
					tField.pchar = (char*)pm_data;

					pcm_data = (char*)pm_data;
					pcm_data += sLen+1;
					pm_data = (wdbfield_t*)pcm_data;
				}
				// special case that occurs in creaturecache.wdb
				else if(m_def->getFieldType(j) & t_special2byte){
					
					u16 sField;
					psm_data = (u16*)pm_data;
					sField = *psm_data;
					tField.uival = (u32)sField;

					psm_data++;
					pm_data = (wdbfield_t*)psm_data;
					
				}else{
					tField = *pm_data; pm_data++;
				}

				tRec.addField(tField,j);
			}
			
			m_records.push_back(tRec);
		}

		printf("%i records loaded.\n",i);

	}
	void setDef(CWDBDef* def){ m_def = def; }
	CWDBDef* getDef(){ return m_def; }
	wdbheader_t getHeader() { return m_header; }

};

// globals
vector<CWDBDef> gDefList;

bool CWDB::loadWDB(char *file)
{

	ifstream fin(file, ios_base::in | ios_base::binary);
	bool isMatch = false;
	if(!fin.is_open())
		return false;

	u32 tlength;

	fin.read((char*)&m_header,sizeof(wdbheader_t));

	// sometimes the number of fields can be deceiving! Did I mention I hate WDB files?
	if(m_header.fields < ((MAXFIELDS-2)*4) ){
		m_header.fields /= 4;
		m_header.fields += 2;
	}

	// Set definition based on signature
	for(u32 i=0;i<gDefList.size();i++){
		if(!memcmp(&m_header.signature,gDefList.at(i).getSignature(),4)){
			isMatch = true;
			printf("Signature matches %s\n",gDefList.at(i).getWDBName());
			m_def = &gDefList.at(i);
			
			// if fieldsize is incorrect, adjust accordingly
			if(m_header.fields < ((MAXFIELDS-2)*4)){
				if(m_def->getNumFields() != m_header.fields){
					printf("WARNING: Number of fields does not match definition,\n");
					printf("         Temporarily adjusting fieldsize, this may be an older/newer version.\n\n");
					printf("NEW FIELD INFO:\n\tNew fields: %i\n\n",m_header.fields - m_def->getNumFields());

					// adjust fieldsize
					m_def->setNumFields(m_header.fields);
				}
			}
		}
	}

	if(!isMatch){
		printf("Header does not match any known WDB file.\n");
		return false;
	}

	fin.seekg(0,ios_base::end);
	tlength = fin.tellg();
	tlength -= sizeof(wdbheader_t);

	m_data = new char[tlength];
	m_datasize = tlength;

	fin.seekg(sizeof(wdbheader_t));
	fin.read(m_data,tlength);

	fin.close();

	return true;

}

void LoadDefinitions(){

	CWDBDef def;

	// creaturecache.wdb (BOMW)
	def.setWDBName("creaturecache.wdb");
	def.setSignature("BOMW");

    // 15 fields
	def.addField(t_uint,"CreatureID");
	def.addField(t_uint,"Entry Size");
	def.addField(t_str,"Name 1");
	def.addField(t_str,"Name 2");
	def.addField(t_str,"Name 3");
	def.addField(t_str,"Name 4");
	def.addField(t_str,"Description");
	def.addField(t_str,""); // unknown
	def.addField(t_uint,"TypeID");
	def.addField(t_uint,"FamilyID");
	def.addField(t_uint,"FlagID");
	def.addField(t_str,""); // unknown
	def.addField(t_uint,"SpellDataID");
	def.addField(t_uint,"IconID");
	def.addField(t_uint,"");
	def.addField(t_uint,"");
	def.addField(t_uint,"");
	def.addField(t_special2byte | t_uint,""); // stupid 2byte field!
	def.addField(t_uint,"");
	def.addField(t_uint,"");
	def.addField(t_uint,"");
	def.addField(t_str,"");
	def.addField(t_uint,"");

	gDefList.push_back(def);

	// gameobjectcache.wdb (BOGW)
	def.setWDBName("gameobjectcache.wdb");
	def.setSignature("BOGW");
	
	// 33 fields
	def.addField(t_uint,"ObjectID");
	def.addField(t_uint,"Entry Size");
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_str,"Name 1");
	def.addField(t_str,"Name 2");
	def.addField(t_str,"Name 3");
	def.addField(t_str,"Name 4");
	def.addField(t_str,"Str?");
#ifdef _BC
	def.addField(t_str,"Str?");
	def.addField(t_str,"Str?");
#endif
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown

	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown
	def.addField(t_undefined,""); // unknown

	gDefList.push_back(def);

	// itemcache.wdb (BDIW)
	def.setWDBName("itemcache.wdb");
	def.setSignature("BDIW");

#ifdef _BC
	// 131 fields
#else
	// 130 fields
#endif

	def.addField(t_uint,"ItemID");
	def.addField(t_uint,"Entry Size");
	def.addField(t_uint,"ItemClassID");
	def.addField(t_uint,"ItemSubClassID");
#ifdef _BC
	def.addField(t_sint,"Unknown");
#endif
	def.addField(t_str,"Name 1");
	def.addField(t_str,"Name 2");
	def.addField(t_str,"Name 3");
	def.addField(t_str,"Name 4");
	def.addField(t_uint,"ItemDisplayID");
	def.addField(t_uint,"Quality");
	def.addField(t_uint,"Type Flags");
	def.addField(t_uint,"Buy Price");
	def.addField(t_uint,"Sell Price");
	def.addField(t_uint,"Inventory Slot");
	def.addField(t_uint,"Class Flags");
	def.addField(t_uint,"Race Flags");
	def.addField(t_uint,"Item Level");
	def.addField(t_uint,"Req Level");
	def.addField(t_uint,"Req Skill");
	def.addField(t_uint,"Req Skill Level");
	def.addField(t_uint,"Req Spell");
	def.addField(t_uint,"Req Rank");
	def.addField(t_uint,"Req Rank2");
	def.addField(t_uint,"Req Faction");
	def.addField(t_uint,"Req Faction LvL");
	def.addField(t_uint,"isUnique");
	def.addField(t_uint,"Stack Amount");
	def.addField(t_uint,"Container Slots");
	def.addField(t_sint,"Stat1");
	def.addField(t_uint,"Stat1 Val");
	def.addField(t_sint,"Stat2");
	def.addField(t_uint,"Stat2 Val");
	def.addField(t_sint,"Stat3");
	def.addField(t_uint,"Stat3 Val");
	def.addField(t_sint,"Stat4");
	def.addField(t_uint,"Stat4 Val");
	def.addField(t_sint,"Stat5");
	def.addField(t_uint,"Stat5 Val");
	def.addField(t_sint,"Stat6");
	def.addField(t_uint,"Stat6 Val");
	def.addField(t_sint,"Stat7");
	def.addField(t_uint,"Stat7 Val");
	def.addField(t_sint,"Stat8");
	def.addField(t_uint,"Stat8 Val");
	def.addField(t_sint,"Stat9");
	def.addField(t_uint,"Stat9 Val");
	def.addField(t_sint,"Stat10");
	def.addField(t_uint,"Stat10 Val");
	def.addField(t_float,"Damage1 Min");
	def.addField(t_float,"Damage1 Max");
	def.addField(t_uint ,"Damage1 Type");
	def.addField(t_float,"Damage2 Min");
	def.addField(t_float,"Damage2 Max");
	def.addField(t_uint ,"Damage2 Type");
	def.addField(t_float,"Damage3 Min");
	def.addField(t_float,"Damage3 Max");
	def.addField(t_uint ,"Damage3 Type");
	def.addField(t_float,"Damage4 Min");
	def.addField(t_float,"Damage4 Max");
	def.addField(t_uint ,"Damage4 Type");
	def.addField(t_float,"Damage5 Min");
	def.addField(t_float,"Damage5 Max");
	def.addField(t_uint ,"Damage5 Type");
	def.addField(t_uint,"Physical Resist");
	def.addField(t_uint,"Holy Resist");
	def.addField(t_uint,"Fire Resist");
	def.addField(t_uint,"Nature Resist");
	def.addField(t_uint,"Frost Resist");
	def.addField(t_uint,"Shadow Resist");
	def.addField(t_uint,"Arcane Resist");
	def.addField(t_uint,"Weapon Delay");
	def.addField(t_uint,"Ammo Type");
	def.addField(t_float,"Range Mod");
	def.addField(t_uint,"Spell1 ID");
	def.addField(t_uint,"Spell1 Trigger");
	def.addField(t_uint,"Spell1 Charges");
	def.addField(t_sint,"Spell1 Cooldown");
	def.addField(t_uint,"Spell1 Category");
	def.addField(t_sint,"Spell1 Category Cooldown");
	def.addField(t_uint,"Spell2 ID");
	def.addField(t_uint,"Spell2 Trigger");
	def.addField(t_uint,"Spell2 Charges");
	def.addField(t_sint,"Spell2 Cooldown");
	def.addField(t_uint,"Spell2 Category");
	def.addField(t_sint,"Spell2 Category Cooldown");
	def.addField(t_uint,"Spell3 ID");
	def.addField(t_uint,"Spell3 Trigger");
	def.addField(t_uint,"Spell3 Charges");
	def.addField(t_sint,"Spell3 Cooldown");
	def.addField(t_uint,"Spell3 Category");
	def.addField(t_sint,"Spell3 Category Cooldown");
	def.addField(t_uint,"Spell4 ID");
	def.addField(t_uint,"Spell4 Trigger");
	def.addField(t_uint,"Spell4 Charges");
	def.addField(t_sint,"Spell4 Cooldown");
	def.addField(t_uint,"Spell4 Category");
	def.addField(t_sint,"Spell4 Category Cooldown");
	def.addField(t_uint,"Spell5 ID");
	def.addField(t_uint,"Spell5 Trigger");
	def.addField(t_uint,"Spell5 Charges");
	def.addField(t_sint,"Spell5 Cooldown");
	def.addField(t_uint,"Spell5 Category");
	def.addField(t_sint,"Spell5 Category Cooldown");
	def.addField(t_uint,"BondID");
	def.addField(t_str,"Description");
	def.addField(t_uint,"BookTextID");
	def.addField(t_uint,"Book Pages");
	def.addField(t_uint,"BookStationaryID");
	def.addField(t_uint,"BeginQuestID");
	def.addField(t_uint,"reqLockPickSkill");
	def.addField(t_sint,"Material");
	def.addField(t_uint,"SheathID");
	def.addField(t_uint,"RandomPropertyID");
#ifdef _BC
	def.addField(t_uint,"Unknown");
#endif
	def.addField(t_uint,"Block Value");
	def.addField(t_uint,"ItemSetID");
	def.addField(t_uint,"Durability");
	def.addField(t_uint,"ItemAreaID");
	def.addField(t_uint,"ItemMapID");
	def.addField(t_uint,"Bag Family");
	def.addField(t_uint,"Totem Category");
	def.addField(t_uint,"Socket Color 1");
	def.addField(t_uint,"Unknown");
	def.addField(t_uint,"Socket Color 2");
	def.addField(t_uint,"Unknown");
	def.addField(t_uint,"Socket Color 3");
	def.addField(t_uint,"Unknown");
	def.addField(t_uint,"SpellItemEnchantment");
	def.addField(t_uint,"Gem Properties");
	def.addField(t_uint,"Honor cost");
	def.addField(t_uint,"Unknown");

	gDefList.push_back(def);

	// itemnamecache.wdb (BDNW)
	def.setWDBName("itemnamecache.wdb");
	def.setSignature("BDNW");
	 
	// 3 fields
	def.addField(t_uint,"ItemID");
	def.addField(t_uint,"Entry Size");
	def.addField(t_str,"Item Name");

	gDefList.push_back(def);

	// itemtextcache.wdb (XTIW)
	def.setWDBName("itemnamecache.wdb");
	def.setSignature("XTIW");

	// 3 fields
	def.addField(t_uint,"EntryID");
	def.addField(t_uint,"Entry Size");
	def.addField(t_str,"Text");

	gDefList.push_back(def);

	// npccache.wdb (CPNW)
	def.setWDBName("npccache.wdb");
	def.setSignature("CPNW");

	// 82 fields
	def.addField(t_uint,"EntryID");
	def.addField(t_uint,"Entry Size");

	for(int i=3;i<=73;i+=10){
		def.addField(t_float,"");
		def.addField(t_str,"");
		def.addField(t_str,"");
		def.addField(t_uint,"");
		def.addField(t_uint,"");
		def.addField(t_uint,"");
		def.addField(t_uint,"");
		def.addField(t_uint,"");
		def.addField(t_uint,"");
		def.addField(t_uint,"");
	} // unknowns
	
	gDefList.push_back(def);

	// pagetextcache.wdb (XTPW)

	def.setWDBName("pagetextcache.wdb");
	def.setSignature("XTPW");

	// 4 fields
	def.addField(t_uint,"ItemID");
	def.addField(t_uint,"Entry Size");
	def.addField(t_str,"Page Text");
	def.addField(t_uint,"NextPageID");

	gDefList.push_back(def);

	// questcache.wdb (TSQW)

	def.setWDBName("questcache.wdb");
	def.setSignature("TSQW");

	// 66 fields
	// 67 BC fields
	def.addField(t_uint,"QuestID");
	def.addField(t_uint,"Entry Size");
	def.addField(t_uint,"QuestID2");
	def.addField(t_uint,"");
	def.addField(t_uint,"Level");
	def.addField(t_uint,"AreaID");
	def.addField(t_uint,"InfoID");
	def.addField(t_undefined,"");
	def.addField(t_undefined,"");
	def.addField(t_undefined,"");
	def.addField(t_undefined,"");

#ifdef _BC
	def.addField(t_undefined,"");
#endif

	def.addField(t_uint,"NextQuestID");
	def.addField(t_sint,"CoinReward");
	def.addField(t_uint,"CoinRewardOnExp");
	def.addField(t_uint,"SpellReward");
	def.addField(t_undefined,"");
	def.addField(t_uint,"StartItemID");
	def.addField(t_uint,"QuestFlags");
	def.addField(t_uint,"ItemReward1");
	def.addField(t_uint,"ItemAmount1");
	def.addField(t_uint,"ItemReward2");
	def.addField(t_uint,"ItemAmount2");
	def.addField(t_uint,"ItemReward3");
	def.addField(t_uint,"ItemAmount3");
	def.addField(t_uint,"ItemReward4");
	def.addField(t_uint,"ItemAmount4");
	def.addField(t_uint,"ItemChoice1");
	def.addField(t_uint,"ItemChoiceAmount1");
	def.addField(t_uint,"ItemChoice2");
	def.addField(t_uint,"ItemChoiceAmount2");
	def.addField(t_uint,"ItemChoice3");
	def.addField(t_uint,"ItemChoiceAmount3");
	def.addField(t_uint,"ItemChoice4");
	def.addField(t_uint,"ItemChoiceAmount4");
	def.addField(t_uint,"ItemChoice5");
	def.addField(t_uint,"ItemChoiceAmount5");
	def.addField(t_uint,"ItemChoice6");
	def.addField(t_uint,"ItemChoiceAmount6");
	def.addField(t_undefined,"");
	def.addField(t_undefined,"");
	def.addField(t_undefined,"");
	def.addField(t_undefined,"");

	def.addField(t_str,"Name");
	def.addField(t_str,"Description");
	def.addField(t_str,"Details");
	def.addField(t_str,"Subdescription");
	def.addField(t_uint,"KillCreature1");
	def.addField(t_uint,"KillCreature1Amount");
	def.addField(t_uint,"CollectItem1");
	def.addField(t_uint,"CollectItem1Amount");
	def.addField(t_uint,"KillCreature2");
	def.addField(t_uint,"KillCreature2Amount");
	def.addField(t_uint,"CollectItem2");
	def.addField(t_uint,"CollectItem2Amount");
	def.addField(t_uint,"KillCreature3");
	def.addField(t_uint,"KillCreature3Amount");
	def.addField(t_uint,"CollectItem3");
	def.addField(t_uint,"CollectItem3Amount");
	def.addField(t_uint,"KillCreature4");
	def.addField(t_uint,"KillCreature4Amount");
	def.addField(t_uint,"CollectItem4");
	def.addField(t_uint,"CollectItem4Amount");
	def.addField(t_str,"Objective1");
	def.addField(t_str,"Objective2");
	def.addField(t_str,"Objective3");
	def.addField(t_str,"Objective4");

	gDefList.push_back(def);

	// wowcache.wdb (NDRW)
	def.setWDBName("wowcache.wdb");
	def.setSignature("NDRW");

	// 4 fields
	def.addField(t_undefined,"");
	def.addField(t_undefined,"");
	def.addField(t_undefined,"");
	def.addField(t_undefined,"");

	gDefList.push_back(def);

}

void doexit(){
	gDefList.empty();
	//printf("\nPress any key to exit.");
	//char trash = getch();
}

int main(int argc, char* argv[])
{
	printf("** WDB to CSV**\nby:      Jb55\nWebsite: http://www.jb55.com\nContact: jackbox55@gmail.com\n\n");
	if(argc<2){
		printf("usage: wdbtocsv.exe <file.wdb> (drag the wdb onto this file)\n");
		doexit();
		return 0;
	}
	CWDB wdb;

	LoadDefinitions();

#ifdef _SPEED
	_timeb starttime;
	_timeb endtime;
	unsigned short diff;
	_ftime( &starttime );
#endif	

	if(!wdb.loadWDB(argv[1]))
	{
		doexit();
		printf("There was an error loading the WDB.\n");
		return 0;
	}
	wdb.parseWDB();
	if(!wdb.toCSV(argv[1]))
	{
		doexit();
		printf("There was an error creating the CSV file.\n");
		return 0;
	}

#ifdef _SPEED
	_ftime( &endtime );
	diff = endtime.millitm - starttime.millitm;
	printf("Time elapsed parsing and building csv (milliseconds): %i\n",diff);
#endif

	doexit();
	return 0;
}
