/*
* ============================================================================
*  Name     : CAuebTrilizaContainer from AuebTrilizaContainer.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     Declares container control for application.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef AUEBTRILIZACONTAINER_H
#define AUEBTRILIZACONTAINER_H

// INCLUDES
#include "AuebTrilizaAppUi.h"
#include "AuebTrilizaView.h"

#include <coecntrl.h>
#include <fbs.h> // for bitmap
   
// CLASS DECLARATION

/**
*  CAuebTrilizaContainer  container control class.
*  
*/
class CAuebTrilizaContainer : public CCoeControl, MCoeControlObserver
    {
    public: // Constructors and destructor
        
		CAuebTrilizaContainer(CAuebTrilizaAppUi* aUi, CAuebTrilizaView* aView);

        /**
        * EPOC default constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL(const TRect& aRect);

        /**
        * Destructor.
        */
        ~CAuebTrilizaContainer();

    public: // New functions

    public: // Functions from base classes
		/**
		* From CoeControl, OfferKeyEventL.
		* Handles the key-events.
		* @return If key-event is consumed, EKeyWasConsumed. Else
		* EKeyWasNotConsumed.
		* @param aKeyEvent Key event.
		* @param aType Type of key event(EEventKey, EEventKeyUp or
		* EEventKeyDown).
		*/
		TKeyResponse OfferKeyEventL(
			const TKeyEvent& aKeyEvent,
				TEventCode aType );

    private: // Functions from base classes

       /**
        * From CoeControl,SizeChanged.
        */
        void SizeChanged();

       /**
        * From CoeControl,CountComponentControls.
        */
        TInt CountComponentControls() const;

       /**
        * From CCoeControl,ComponentControl.
        */
        CCoeControl* ComponentControl(TInt aIndex) const;

       /**
        * From CCoeControl,Draw.
        */
        void Draw(const TRect& aRect) const;

       /**
        * From ?base_class ?member_description
        */
        // event handling section
        // e.g Listbox events
        void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);

		void LoadBitmapL(CFbsBitmap* aBitMap,const TDesC& aFileName,TInt aId,TBool aShareIfLoaded);
        
    private: //data
        
		CFbsBitmap* iBitmap;

		CAuebTrilizaAppUi* iUi;
		CAuebTrilizaView* iView;
    };

#endif

// End of File
