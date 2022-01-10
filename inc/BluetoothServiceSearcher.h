/*
* ============================================================================
*  Name     : CBluetoothServiceSearcher from BluetoothServiceSearcher.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     This class performs the donkey work in searching for services on remote
*     devices.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef __BLUETOOTHSERVICESEARCHER_H__
#define __BLUETOOTHSERVICESEARCHER_H__

//includes
#include <btsdp.h>

#include "TBluetoothAttributeParser.h"
#include "BluetoothAttributeObserver.h"

class CAknWaitDialog;

// CLASS DECLARATION

class CBluetoothServiceSearcher : public CBase, public MSdpAgentNotifier, public MBluetoothAttributeObserver
 	{
	public: // Constructors
		static CBluetoothServiceSearcher* 	NewL(TInt& aPort);
		static CBluetoothServiceSearcher* 	NewLC(TInt& aPort);
		~CBluetoothServiceSearcher();

	private: // Constructors
		CBluetoothServiceSearcher(TInt& aPort);
		void					ConstructL();

	public: // Member functions
		void 					CloseL();
		TInt 					FindServiceL(const TBTDevAddr& aDeviceAddress);
		void 					SetPort(TInt aPort);

	public:
		virtual void			NextRecordRequestComplete(TInt aError, TSdpServRecordHandle aHandle, TInt aTotalRecordsCount);
		virtual void			AttributeRequestResult(TSdpServRecordHandle aHandle, TSdpAttributeID aAttrID, CSdpAttrValue* aAttrValue);
		virtual void			AttributeRequestComplete(TSdpServRecordHandle aHandle, TInt aError);

		void					NextRecordRequestCompleteL(TInt aError, TSdpServRecordHandle aHandle, TInt aTotalRecordsCount);
		void					AttributeRequestResultL(TSdpServRecordHandle aHandle, TSdpAttributeID aAttrID, CSdpAttrValue* aAttrValue);
		void					AttributeRequestCompleteL(TSdpServRecordHandle aHandle, TInt aError);

	private:
		void					DisplayProgressDialogL();
		void					RemoveProgressDialogL();

	private: // Member Data 
		CSdpAgent*				iAgent;
		CSdpSearchPattern*		iSdpSearchPattern;
		CSdpAttrIdMatchList* 	iMatchList;
		CAknWaitDialog*			iWaitDialog;
		TInt&					iPort;
		TInt					iSearcherState;
		TBool					iContinueSearching;
		TBool					iAvailable;
	};

#endif // __BLUETOOTHSERVICESEARCHER_H__