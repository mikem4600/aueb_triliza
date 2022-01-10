/*
* ============================================================================
*  Name     : CBluetoothAdvertiser from BluetoothAdvertiser.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     This class contains all the functionality for advertising Bluetooth
      Services on remote devices via the Bluetooth Service Discovery Database
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef __BLUETOOTHADVERTISER_H__
#define __BLUETOOTHADVERTISER_H__

#include <btsdp.h>

// CLASS DECLARATION

class CBluetoothAdvertiser : public CBase
	{
	public: // Constructors
		static CBluetoothAdvertiser* 		NewL();
		static CBluetoothAdvertiser* 		NewLC();
		~CBluetoothAdvertiser();

	private: // Constructors
		CBluetoothAdvertiser();
		void					ConstructL();

	public:
		void					StartAdvertisingL(TInt aPort);
		void					StopAdvertisingL();

	public:
		inline TBool				IsAdvertising();
		void					UpdateAvailabilityL(TBool aAvailability);

	private:
		void					BuildProtocolDescriptionL(CSdpAttrValueDES* aProtocolDescriptor, TInt aPort);
		void					ConnectL();

	private: // Data
		RSdp					iSdpSession;
		RSdpDatabase				iSdpDatabase;
		TSdpServRecordHandle			iRecord;
		TInt					iRecordState;
		TBool					iIsConnected;
	};


inline TBool CBluetoothAdvertiser::IsAdvertising()
	{
	return iRecord != 0;
	}

#endif // __BLUETOOTHADVERTISER_H__






