/*
* ============================================================================
*  Name     : CBluetoothDeviceSearcher from BluetoothDeviceSearcher.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     This class performs the search for Remote Bluetooth devices.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef __BLUETOOTHDEVICESEARCHER_H__
#define __BLUETOOTHDEVICESEARCHER_H__

// System includes
#include <btextnotifiers.h>

class MBluetoothObserver;

// CLASS DECLARATION

class CBluetoothDeviceSearcher : public CActive
	{
	public: // Constructors
		static CBluetoothDeviceSearcher* NewL(MBluetoothObserver &aBluetoothObserver);
		static CBluetoothDeviceSearcher* NewLC(MBluetoothObserver &aBluetoothObserver);
		~CBluetoothDeviceSearcher();

	private: // Constructors
		CBluetoothDeviceSearcher(MBluetoothObserver &aBluetoothObserver);
		void	ConstructL();
		void	RunL();
		void	DoCancel();

	public: // Member functions
		void SelectDeviceL(TBTDeviceResponseParamsPckg& aResponse);

	private: // Member Data
		TBTDeviceResponseParamsPckg*	iResponse;
		RNotifier						iNotifier;
		MBluetoothObserver&				iObserver;
	};

#endif // __BLUETOOTHDEVICESEARCHER_H__