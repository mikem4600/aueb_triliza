/*
* ============================================================================
*  Name     : BluetoothDefinitions.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     Various definitions and variables used by classes of AUEB Triliza
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef __BLUETOOTHDEFINITIONS_H__
#define __BLUETOOTHDEFINITIONS_H__


#include <e32std.h>

_LIT(KServiceName,"AUEB Triliza");
_LIT(KServiceDescription,"AUEB Triliza Bluetooth Application");
_LIT(KServerTransportName,"RFCOMM");

const TInt KListeningQueSize = 1;
const TInt KMaxMessageLength = 60;
const TInt KMaxMessageSizeDesc16 = KMaxMessageLength * 2;


enum TAuebTrilizaPanic
    {
    EInvalidClientState,
    EInvalidServerState,
    EErrorStoppingServer,
    EErrorInNextRecordRequestComplete,
    EErrorInAttributeRequestResult,
    EErrorInAttributeRequestComplete,
    EBadAttributeValue
    };

_LIT(KAuebTrilizaPanicString, "AUEBTRILIZA");

inline void Panic(TAuebTrilizaPanic aPanicCode)
    {
    User::Panic(KAuebTrilizaPanicString, (TInt)(aPanicCode));
    }


#endif // __BLUETOOTHDEFINITIONS_H__






