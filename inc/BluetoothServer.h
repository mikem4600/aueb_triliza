/*
* ============================================================================
*  Name     : CBluetoothServer from BluetoothServer.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*		This is the Bluetooth Server and handles setting up sockets for 
*       Bluetooth communications, setting security settings, and
*       advertising services
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef __BLUETOOTHSERVER_H__
#define __BLUETOOTHSERVER_H__

// Includes
#include <es_sock.h>
#include <btmanclient.h>

#include "BluetoothDefinitions.h"
#include "BluetoothObserver.h"

class CBluetoothAdvertiser;
class MBluetoothObserver;

// CLASS DECLARATION

class CBluetoothServer : public CActive
	{
	public: // Constructors
		static CBluetoothServer* 	NewL(MBluetoothObserver& aObserver);
		static CBluetoothServer* 	NewLC(MBluetoothObserver& aObserver);
		~CBluetoothServer();

	private: // Consturctors 
		CBluetoothServer(MBluetoothObserver& aObserver);
		void 				ConstructL();

	public:
		void 				StartServerL();
		void				StartAdvertisingL();
		void 				StopL();
		void 				Send(const TDesC& aMessage);
		TBool 				IsConnected();
		TBool 				AvailableToSend();

	public:
		void RunL();
		void DoCancel();

	private: // Member functions
		void 				RequestData();
		void 				SetSecurityOnChannelL(TBool aAuthentication, TBool aEncryption, TBool aAuthorisation);
		void				AcceptConnectionsL();
		void 				SendL(const TDesC& aMessage);

	private: // Member data
		CBluetoothAdvertiser*							iAdvertiser;
		RSocketServ										iSocketServer;
		RSocket											iListeningSocket;
		RSocket											iAcceptedSocket;
		TSockXfrLength									iLen;
		TBuf8<KMaxMessageSizeDesc16 + sizeof (TInt)>	iMessage;
		RBTMan											iSecManager;
		MBluetoothObserver&								iObserver;
		RBTSecuritySettings								iSecSettingsSession;
		TInt											iChannel;


	private:
		enum TState
			{
			EDisconnected,
			ESettingSecurity,
			EConnecting,
			EConnected,
			EWaitingForMessage,
			ESendData
			};

		TState				iState;
	};

#endif // __BLUETOOTHSERVER_H__