/*
* Copyright (C) 2013 Nivis LLC.
* Email:   opensource@nivis.com
* Website: http://www.nivis.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
* 
* Redistribution and use in source and binary forms must retain this
* copyright notice.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "C837_WriteUpdateNotificationBitMask.h"


uint8_t Compose_C837_WriteUpdateNotificationBitMask_Req(C837_WriteUpdateNotificationBitMask_Req* request, 
		BinaryStream* toStream)
{
	STREAM_WRITE_BYTES(toStream, &request->UniqueID, 5);
	STREAM_WRITE_BYTES(toStream, &request->ChangeNotificationFlags, 2);

	return RCS_N00_Success;
}

/**
 * @Debinarize
 */
uint8_t Parse_C837_WriteUpdateNotificationBitMask_Req(C837_WriteUpdateNotificationBitMask_Req* request, 
		BinaryStream* fromStream)
{
#ifdef _DEBUG
	if (7 > STREAM_GetRemainingSize(fromStream))
		return RCS_E05_TooFewDataBytesReceived;
#endif
	STREAM_READ_BYTES(fromStream, &request->UniqueID, 5);
	STREAM_READ_BYTES(fromStream, &request->ChangeNotificationFlags, 2);

	return RCS_N00_Success;
}

/**
 *
 */
uint8_t Compose_C837_WriteUpdateNotificationBitMask_Resp(C837_WriteUpdateNotificationBitMask_Resp* response, 
		BinaryStream* toStream)
{
	STREAM_WRITE_BYTES(toStream, &response->UniqueID, 5);
	STREAM_WRITE_BYTES(toStream, &response->ChangeNotificationFlags, 2);

	return RCS_N00_Success;
}

/**
 *
 */
uint8_t Parse_C837_WriteUpdateNotificationBitMask_Resp(C837_WriteUpdateNotificationBitMask_Resp* response, 
		BinaryStream* fromStream)
{
#ifdef _DEBUG
	if (7 > STREAM_GetRemainingSize(fromStream))
		return RCS_E05_TooFewDataBytesReceived;
#endif

	STREAM_READ_BYTES(fromStream, &response->UniqueID, 5);
	STREAM_READ_BYTES(fromStream, &response->ChangeNotificationFlags, 2);

	return RCS_N00_Success;
}
