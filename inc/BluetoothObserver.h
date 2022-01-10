/*
* ============================================================================
*  Name     : MBluetoothObserver from BluetoothObserver.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     This class provides a mechanism for passing feedback to the UI
*     in Bluetooth Communications
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef __BLUETOOTHOBSERVER_H__
#define __BLUETOOTHOBSERVER_H__

// CLASS DECLARATION

class MBluetoothObserver
	{
	public:
		virtual void ServerStartedL() = 0;
		virtual void DataReceivedL(const TDesC& aMessage) = 0;
		virtual void ConnectedL() = 0;
		virtual void HandleErrorL(TInt aErrorCode) = 0;
		virtual void DeviceFoundL(TInt aResult) = 0;
	};


#endif // __BLUETOOTHOBSERVER_H__
