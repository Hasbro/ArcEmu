<<<<<<< .working
<<<<<<< .working
/*
 * ArcEmu Failure Server
 * Copyright (C) 2008 <http://www.AscentEmu.com/>
 *
 * This program is stolen software. Please visit www.ascentemu.com
 * for the real owners of this emulator.
 * 
 * ArcEmu is a pathetic piece of software which crashes even more
 * than vanilla Ascent. And don't even put it up against Summit.
 * There's no comparison there.
 *
 * SO, why use a project run by an idiot who can't even code?
 * You don't! :D
 *
 */

#ifndef _WOWCRYPT_H
#define _WOWCRYPT_H

#include <stdlib.h>
#include "../Common.h"
#include <vector>

class WowCrypt {
public:
	WowCrypt();
	~WowCrypt();

	const static size_t CRYPTED_SEND_LEN = 4;
	const static size_t CRYPTED_RECV_LEN = 6;

	void Init();

	void SetKey(uint8 *, size_t);

	void DecryptRecv(uint8 *, size_t);
	void EncryptSend(uint8 *, size_t);
    
    // encrypt 4 bytes
    void EncryptFourSend(uint8 * data);
    // decrypt 6 bytes
    void DecryptSixRecv(uint8 *data);

	bool IsInitialized() { return _initialized; }

private:
	std::vector<uint8> _key;
	uint8 _send_i, _send_j, _recv_i, _recv_j;
	bool _initialized;
};

#endif
=======
/*
 * ArcEmu MMORPG Server
 * Copyright (C) 2008 <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _WOWCRYPT_H
#define _WOWCRYPT_H

#include <stdlib.h>
#include "../Common.h"
#include <vector>

class WowCrypt {
public:
	WowCrypt();
	~WowCrypt();

	const static size_t CRYPTED_SEND_LEN = 4;
	const static size_t CRYPTED_RECV_LEN = 6;

	void Init();

	void SetKey(uint8 *, size_t);

	void DecryptRecv(uint8 *, size_t);
	void EncryptSend(uint8 *, size_t);
    
    // encrypt 4 bytes
    void EncryptFourSend(uint8 * data);
    // decrypt 6 bytes
    void DecryptSixRecv(uint8 *data);

	bool IsInitialized() { return _initialized; }

private:
	std::vector<uint8> _key;
	uint8 _send_i, _send_j, _recv_i, _recv_j;
	bool _initialized;
};

#endif
>>>>>>> .merge-right.r249
=======
/*
 * ArcEmu MMORPG Server
 * Copyright (C) 2008 <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _WOWCRYPT_H
#define _WOWCRYPT_H

#include <stdlib.h>
#include "../Common.h"
#include <vector>

class WowCrypt {
public:
	WowCrypt();
	~WowCrypt();

	const static size_t CRYPTED_SEND_LEN = 4;
	const static size_t CRYPTED_RECV_LEN = 6;

	void Init();

	void SetKey(uint8 *, size_t);

	void DecryptRecv(uint8 *, size_t);
	void EncryptSend(uint8 *, size_t);
    
    // encrypt 4 bytes
    void EncryptFourSend(uint8 * data);
    // decrypt 6 bytes
    void DecryptSixRecv(uint8 *data);

	bool IsInitialized() { return _initialized; }

private:
	std::vector<uint8> _key;
	uint8 _send_i, _send_j, _recv_i, _recv_j;
	bool _initialized;
};

#endif
>>>>>>> .merge-right.r249
