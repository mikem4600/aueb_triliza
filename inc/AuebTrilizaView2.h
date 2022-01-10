/*
* ============================================================================
*  Name     : CAuebTrilizaView2 from AuebTrilizaView2.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     Declares view for application.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef AUEBTRILIZAVIEW2_H
#define AUEBTRILIZAVIEW2_H

// INCLUDES
#include <aknview.h>

#include "AuebTrilizaAppUi.h"
#include "AuebTrilizaDocument.h"


// CONSTANTS
// UID of view
const TUid KView2Id = {2};

// FORWARD DECLARATIONS
class CAuebTrilizaContainer2;

// CLASS DECLARATION

/**
*  CAuebTrilizaView2 view class.
* 
*/
class CAuebTrilizaView2 : public CAknView
    {
    public: // Constructors and destructor

		CAuebTrilizaView2(CAuebTrilizaAppUi* aUi, CAuebTrilizaDocument* aDocument);

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CAuebTrilizaView2();

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

		CAuebTrilizaContainer2* GetContainer(){return iContainer;}

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
        CAuebTrilizaContainer2* iContainer;
		CAuebTrilizaAppUi* iUi;
		CAuebTrilizaDocument* iDocument;
    };

#endif

// End of File
