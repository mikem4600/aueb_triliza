/*
* ============================================================================
*  Name     : CBluetoothClient from BluetoothClient.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     This is the Bluetooth Client and handles setting up sockets for
*     Bluetooth communications
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef __BLUETOOTHCLIENT_H__
#define __BLUETOOTHCLIENT_H__

// System Includes
#include <bt_sock.h>

#include "BluetoothDefinitions.h" // KMaxMessageLength

class MBluetoothObserver;

// CLASS DECLARATION

class CBluetoothClient : public CActive
	{
	public: // Constructors
		static CBluetoothClient* 	NewL(MBluetoothObserver& aObserver);
		~CBluetoothClient();

	private: // Constructors
		CBluetoothClient(MBluetoothObserver& aObserver);
		void 				ConstructL();

	public: // Member functions
		void 				ConnectToServerL(const TBTDevAddr& aBTDevAddr, const TInt aPort);
		void 				Send(const TDesC& aMessage);
		TBool 				IsConnected();
		TBool 				AvailableToSend();
		void 				RequestData();

	public:
		void 				RunL();
		void 				DoCancel();
		void 				Disconnect();

	private:
		void 				SendL(const TDesC& aMessage);

	private: // Private member data
		RSocketServ										iSocketServer;
		RSocket											iSendingSocket;
		TBTSockAddr										iSocketAddress;
		TBuf8<KMaxMessageSizeDesc16 + sizeof (TInt)>	iMessage;
		TSockXfrLength 									iLen;
		MBluetoothObserver&								iObserver;

	private:
		enum TState 
			{
			EDisconnected,
			EConnecting,
			EConnected,
			EWaitingForMessage,
			ESendData
			};
	
		TState				iState;
	};

#endif // __BLUETOOTHCLIENT_H__