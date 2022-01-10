/*
* ============================================================================
*  Name     : CAuebTrilizaView from AuebTrilizaView.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     Declares view for application.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef AUEBTRILIZAVIEW_H
#define AUEBTRILIZAVIEW_H

// INCLUDES
#include "AuebTrilizaAppUi.h"
#include "AuebTrilizaDocument.h"

#include <aknview.h>


// CONSTANTS
// UID of view
const TUid KViewId = {1};

// FORWARD DECLARATIONS
class CAuebTrilizaContainer;

// CLASS DECLARATION

/**
*  CAuebTrilizaView view class.
* 
*/
class CAuebTrilizaView : public CAknView
    {
    public: // Constructors and destructor

		CAuebTrilizaView(CAuebTrilizaAppUi* aUi, CAuebTrilizaDocument* aDocument);

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CAuebTrilizaView();

    public: // Functions from base classes
        
        /**
        * From ?base_class ?member_description
        */
        TUid Id() const;

        /**
        * From ?base_class ?member_description
        */
        void HandleCommandL(TInt aCommand);

        /**
        * From ?base_class ?member_description
        */
        void HandleClientRectChange();

    private:

        /**
        * From AknView, ?member_description
        */
        void DoActivateL(const TVwsViewId& aPrevViewId,TUid aCustomMessageId,
            const TDesC8& aCustomMessage);

        /**
        * From AknView, ?member_description
        */
        void DoDeactivate();

    private: // Data
        CAuebTrilizaContainer* iContainer;
		CAuebTrilizaAppUi* iUi;
		CAuebTrilizaDocument* iDocument;
    };

#endif

// End of File
