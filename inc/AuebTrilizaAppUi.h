/*
* ============================================================================
*  Name     : CAuebTrilizaAppUi from AuebTrilizaAppUi.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     Declares UI class for application.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef AUEBTRILIZAAPPUI_H
#define AUEBTRILIZAAPPUI_H

// INCLUDES
#include <eikapp.h>
#include <eikdoc.h>
#include <e32std.h>
#include <coeccntx.h>
#include <aknviewappui.h>
#include <akntabgrp.h>
#include <aknnavide.h>

#include "AuebTrilizaDocument.h"

#include "BluetoothDeviceSearcher.h"	// CBluetoothDeviceSearcher
#include "BluetoothServiceSearcher.h"	// CBluetoothServiceSearcher
#include "BluetoothClient.h"		// CBluetoothClient
#include "BluetoothServer.h"		// CBluetoothServer

// FORWARD DECLARATIONS
class CAuebTrilizaContainer;
class CAuebTrilizaView;
class CAuebTrilizaView2;


// CONSTANTS
//const ?type ?constant_var = ?constant;


// CLASS DECLARATION

/**
* Application UI class.
* Provides support for the following features:
* - EIKON control architecture
* - view architecture
* - status pane
*
*/
class CAuebTrilizaAppUi : public CAknViewAppUi, public MBluetoothObserver
    {
    public: // // Constructors and destructor

		CAuebTrilizaAppUi(CAuebTrilizaDocument* aDocument);

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CAuebTrilizaAppUi();

    public: // New functions

		void ShowDefaultNaviPaneL();

		void ShowAtNaviPanelL(TPtrC message);

		void FindRemoteDeviceL();

		void DeviceFoundL(TInt result);

		void ServerStartedL();
		void DataReceivedL(const TDesC& aMessage);
		void ConnectedL();
		void HandleErrorL(TInt aErrorCode);
		void StartReceivingL();

    public: // Functions from base classes
		/**
        * From CEikAppUi, takes care of command handling.
        * @param aCommand command to be handled
        */
        void HandleCommandL(TInt aCommand);

    private:

        /**
        * From CEikAppUi, handles key events.
        * @param aKeyEvent Event to handled.
        * @param aType Type of the key event.
        * @return Response code (EKeyWasConsumed, EKeyWasNotConsumed).
        */
        virtual TKeyResponse HandleKeyEventL(
            const TKeyEvent& aKeyEvent,TEventCode aType);

        // From MEikMenuObserver
        void DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane);

    private:

		TInt GetNew2pGameOptions();

		TInt GetNewPieceGameOptions();

		void New1PGame();

    private: //Data
        CAknNavigationControlContainer* iNaviPane;
        CAknNavigationDecorator* iNaviDecorator;

		CAuebTrilizaDocument* iDocument;

		CAuebTrilizaView* iView1;
		CAuebTrilizaView2* iView2;


		HBufC*			iMessage;
		TBTDeviceResponseParamsPckg*	iDeviceSelectionResponse; // large object - allocate on heap
		CBluetoothDeviceSearcher*		iDeviceSearcher;
		CAknWaitDialog*		iWaitDialog;

	public:
		CBluetoothClient*	iClient;
		CBluetoothServer*	iServer;

    };
#endif

// End of File
