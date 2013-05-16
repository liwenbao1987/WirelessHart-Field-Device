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

#include "C808_ReadTimeToLive.h"

uint8_t Compose_C808_ReadTimeToLive_Req ( C808_ReadTimeToLive_Req* request,
                                    BinaryStream* toStream )
{
  return RCS_N00_Success; // success
}

uint8_t Parse_C808_ReadTimeToLive_Req ( C808_ReadTimeToLive_Req* request,
                                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
  if (STREAM_GetRemainingSize(fromStream) > 0)
    return RCS_E01_Undefined1; // too many bytes
#endif

  return RCS_N00_Success; // success
}

uint8_t Compose_C808_ReadTimeToLive_Resp ( C808_ReadTimeToLive_Resp* response,
                                    BinaryStream* toStream )
{
  STREAM_WRITE_UINT8(toStream, response->m_ucTimeToLive);

  return RCS_N00_Success; // success
}

uint8_t Parse_C808_ReadTimeToLive_Resp ( C808_ReadTimeToLive_Resp* response,
                                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
  if (STREAM_GetRemainingSize(fromStream) > C808_RespSize)
    return RCS_E01_Undefined1; // too many bytes
#endif

  STREAM_READ_UINT8(fromStream, &response->m_ucTimeToLive);

  return RCS_N00_Success; // success
}