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

#ifndef _AUTHCODES_H
#define _AUTHCODES_H

// client 2.4.3, 2008/07/17
enum LoginErrorCode
{
	RESPONSE_SUCCESS,
	RESPONSE_FAILURE,
	RESPONSE_CANCELLED,
	RESPONSE_DISCONNECTED,
	RESPONSE_FAILED_TO_CONNECT,
	RESPONSE_CONNECTED,
	RESPONSE_VERSION_MISMATCH,
	
	CSTATUS_CONNECTING,
	CSTATUS_NEGOTIATING_SECURITY,
	CSTATUS_NEGOTIATION_COMPLETE,
	CSTATUS_NEGOTIATION_FAILED,
	CSTATUS_AUTHENTICATING,
	
	AUTH_OK,
	AUTH_FAILED,
	AUTH_REJECT,
	AUTH_BAD_SERVER_PROOF,
	AUTH_UNAVAILABLE,
	AUTH_SYSTEM_ERROR,
	AUTH_BILLING_ERROR,
	AUTH_BILLING_EXPIRED,
	AUTH_VERSION_MISMATCH,
	AUTH_UNKNOWN_ACCOUNT,
	AUTH_INCORRECT_PASSWORD,
	AUTH_SESSION_EXPIRED,
	AUTH_SERVER_SHUTTING_DOWN,
	AUTH_ALREADY_LOGGING_IN,
	AUTH_LOGIN_SERVER_NOT_FOUND,
	AUTH_WAIT_QUEUE,
	AUTH_BANNED,
	AUTH_ALREADY_ONLINE,
	AUTH_NO_TIME,
	AUTH_DB_BUSY,
	AUTH_SUSPENDED,
	AUTH_PARENTAL_CONTROL,
	AUTH_LOCKED_ENFORCED,
	
	REALM_LIST_IN_PROGRESS,
	REALM_LIST_SUCCESS,
	REALM_LIST_FAILED,
	REALM_LIST_INVALID,
	REALM_LIST_REALM_NOT_FOUND,
	
	ACCOUNT_CREATE_IN_PROGRESS,
	ACCOUNT_CREATE_SUCCESS,
	ACCOUNT_CREATE_FAILED,
	
	CHAR_LIST_RETRIEVING,
	CHAR_LIST_RETRIEVED,
	CHAR_LIST_FAILED,
	
	CHAR_CREATE_IN_PROGRESS,
	CHAR_CREATE_SUCCESS,
	CHAR_CREATE_ERROR,
	CHAR_CREATE_FAILED,
	CHAR_CREATE_NAME_IN_USE,
	CHAR_CREATE_DISABLED,
	CHAR_CREATE_PVP_TEAMS_VIOLATION,
	CHAR_CREATE_SERVER_LIMIT,
	CHAR_CREATE_ACCOUNT_LIMIT,
	CHAR_CREATE_SERVER_QUEUE,
	CHAR_CREATE_ONLY_EXISTING,
	CHAR_CREATE_EXPANSION,
	CHAR_CREATE_ERROR_NEED_LVL_55_CHAR,
	
	CHAR_DELETE_IN_PROGRESS,
	CHAR_DELETE_SUCCESS,
	CHAR_DELETE_FAILED,
	CHAR_DELETE_FAILED_LOCKED_FOR_TRANSFER,
	CHAR_DELETE_FAILED_GUILD_LEADER,
	CHAR_DELETE_FAILED_ARENA_CAPTAIN,
	
	CHAR_LOGIN_IN_PROGRESS,
	CHAR_LOGIN_SUCCESS,
	CHAR_LOGIN_NO_WORLD,
	CHAR_LOGIN_DUPLICATE_CHARACTER,
	CHAR_LOGIN_NO_INSTANCES,
	CHAR_LOGIN_FAILED,
	CHAR_LOGIN_DISABLED,
	CHAR_LOGIN_NO_CHARACTER,
	CHAR_LOGIN_LOCKED_FOR_TRANSFER,
	CHAR_LOGIN_LOCKED_BY_BILLING,
	
	CHAR_NAME_SUCCESS,
	CHAR_NAME_FAILURE,
	CHAR_NAME_NO_NAME,
	CHAR_NAME_TOO_SHORT,
	CHAR_NAME_TOO_LONG,
	CHAR_NAME_INVALID_CHARACTER,
	CHAR_NAME_MIXED_LANGUAGES,
	CHAR_NAME_PROFANE,
	CHAR_NAME_RESERVED,
	CHAR_NAME_INVALID_APOSTROPHE,
	CHAR_NAME_MULTIPLE_APOSTROPHES,
	CHAR_NAME_THREE_CONSECUTIVE,
	CHAR_NAME_INVALID_SPACE,
	CHAR_NAME_CONSECUTIVE_SPACES,
	CHAR_NAME_RUSSIAN_CONSECUTIVE_SILENT_CHARACTERS,
	CHAR_NAME_RUSSIAN_SILENT_CHARACTER_AT_BEGINNING_OR_END,
	CHAR_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME,

};
#endif
