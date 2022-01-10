/*
* ============================================================================
*  Name     : MBluetoothAttributeObserver from BluetoothAttributeObserver.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     This class implements the Bluetooth Attribute Observer
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef __BLUETOOTHATTRIBUTEOBSERVER_H__
#define __BLUETOOTHATTRIBUTEOBSERVER_H__

// CLASS DECLARATION

class MBluetoothAttributeObserver
	{
	public:
		virtual void SetPort(TInt aPort) = 0;
	};


#endif // __BLUETOOTHATTRIBUTEOBSERVER_H__
