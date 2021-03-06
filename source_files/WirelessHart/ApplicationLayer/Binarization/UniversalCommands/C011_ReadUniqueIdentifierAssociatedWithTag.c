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

#include "C011_ReadUniqueIdentifierAssociatedWithTag.h"
#include "C000_ReadUniqueIdentifier.h"


uint8_t Compose_C011_ReadUniqueIdentifierAssociatedWithTag_Req(C011_ReadUniqueIdentifierAssociatedWithTag_Req* request,
		 BinaryStream* toStream)
{
//	STREAM_WRITE_PACKED(toStream, request->tag, sizeof(request->tag)); // on NM/GW???
	STREAM_WRITE_BYTES(toStream, request->tag, sizeof(request->tag)); // on device

	return RCS_N00_Success;
}

uint8_t Parse_C011_ReadUniqueIdentifierAssociatedWithTag_Req(C011_ReadUniqueIdentifierAssociatedWithTag_Req* request,
		 BinaryStream* fromStream)
{
        if (STREAM_GetRemainingSize(fromStream) < sizeof(request->tag))
          return RCS_N255_MakeNoResponse;

	STREAM_READ_BYTES(fromStream, request->tag, sizeof(request->tag));

	return RCS_N00_Success;
}

uint8_t Compose_C011_ReadUniqueIdentifierAssociatedWithTag_Resp(
		C011_ReadUniqueIdentifierAssociatedWithTag_Resp* response,  BinaryStream* toStream)
{
	uint8_t result = Compose_C000_ReadUniqueIdentifier_Resp((C000_ReadUniqueIdentifier_Resp*)response, toStream);
	return result;
}

uint8_t Parse_C011_ReadUniqueIdentifierAssociatedWithTag_Resp(
		C011_ReadUniqueIdentifierAssociatedWithTag_Resp* response,  BinaryStream* fromStream)
{
	return Parse_C000_ReadUniqueIdentifier_Resp((C000_ReadUniqueIdentifier_Resp*)response, fromStream);
}

