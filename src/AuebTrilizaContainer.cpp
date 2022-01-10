/*
* ============================================================================
*  Name     : CAuebTrilizaContainer from AuebTrilizaContainer.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Implementation notes:
*     Initial content was generated by Series 60 AppWizard.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

// INCLUDE FILES
#include "AuebTrilizaContainer.h"
#include "AuebTrilizaAppUi.h"
#include "auebtriliza.hrh"  // for commands
#include <AuebTriliza.mbg> // for bitmap
#include <AuebTriliza.rsg>     // for resources
#include <stringloader.h>  // for StringLoader

// ================= MEMBER FUNCTIONS =======================

CAuebTrilizaContainer::CAuebTrilizaContainer(CAuebTrilizaAppUi* aUi, CAuebTrilizaView* aView)
  : iUi(aUi), iView(aView)
{}

// ---------------------------------------------------------
// CAuebTrilizaContainer::ConstructL(const TRect& aRect)
// EPOC two phased constructor
// ---------------------------------------------------------
//
void CAuebTrilizaContainer::ConstructL(const TRect& aRect)
    {
    CreateWindowL();

    SetRect(aRect);
    ActivateL();

	// load the bitmap
	_LIT(KTxtMBMname,"AuebTriliza.mbm");
	iBitmap = new (ELeave) CFbsBitmap();
	HBufC* textResource = StringLoader::LoadLC(R_LANG);
		if(*textResource == _L("gr"))
		{
		LoadBitmapL(iBitmap, KTxtMBMname, EMbmAuebtrilizaLogogr, ETrue);
		}
		else
		{
		LoadBitmapL(iBitmap, KTxtMBMname, EMbmAuebtrilizaLogoen, ETrue);
		}
	CleanupStack::PopAndDestroy(textResource);
    }

// Destructor
CAuebTrilizaContainer::~CAuebTrilizaContainer()
    {
	delete iBitmap;
    }

// ---------------------------------------------------------
// CAuebTrilizaContainer::SizeChanged()
// Called by framework when the view size is changed
// ---------------------------------------------------------
//
void CAuebTrilizaContainer::SizeChanged()
    {
    }

// ---------------------------------------------------------
// CAuebTrilizaContainer::CountComponentControls() const
// ---------------------------------------------------------
//
TInt CAuebTrilizaContainer::CountComponentControls() const
    {
    return 0; // return nbr of controls inside this container
    }

// ---------------------------------------------------------
// CAuebTrilizaContainer::ComponentControl(TInt aIndex) const
// ---------------------------------------------------------
//
CCoeControl* CAuebTrilizaContainer::ComponentControl(TInt /*aIndex*/) const
    {
		return NULL;
    }

// ---------------------------------------------------------
// CAuebTrilizaContainer::Draw(const TRect& aRect) const
// ---------------------------------------------------------
//
void CAuebTrilizaContainer::Draw(const TRect& /*aRect*/) const
    {
    CWindowGc& gc = SystemGc();
    gc.Clear();

	// Bitmap
	TRect rect(0,0,177,140);
	gc.DrawBitmap(rect, iBitmap);
    }

// ---------------------------------------------------------
// CAuebTrilizaContainer::HandleControlEventL(
//     CCoeControl* aControl,TCoeEvent aEventType)
// ---------------------------------------------------------
//
void CAuebTrilizaContainer::HandleControlEventL(
    CCoeControl* /*aControl*/,TCoeEvent /*aEventType*/)
    {
    }

// based on a Forum Nokia Discussion topic
void CAuebTrilizaContainer::LoadBitmapL(CFbsBitmap* aBitMap,const TDesC& aFileName,TInt aId,TBool aShareIfLoaded)
	{
	TFileName DefaultPath;

	// This gives complete path name to the application
	DefaultPath.Copy(CEikonEnv::Static()->EikAppUi()->Application()->AppFullName());

	// now parse and strip of the application name
	TParsePtr parse(DefaultPath);

	// Copy back only drive and path
	DefaultPath.Copy(parse.DriveAndPath()); 

	// Append the filename
	DefaultPath.Append(aFileName);

	User::LeaveIfError(aBitMap->Load(DefaultPath, aId, aShareIfLoaded));
	}

// ---------------------------------------------------------
// CAuebTrilizaContainer::OfferKeyEventL(...)
// Notify key events to editors.
// ---------------------------------------------------------
//
TKeyResponse CAuebTrilizaContainer::OfferKeyEventL(
    const TKeyEvent& aKeyEvent, TEventCode /*aType*/)
    {
        switch ( aKeyEvent.iCode )
        {
		case EKeyOK:
		case EKeyEnter:
			{
			iUi->HandleCommandL( ENewGame2P );
			return EKeyWasConsumed;
			}
        default:
			{
			return EKeyWasNotConsumed;
            break;
			}
        }
    }

// End of File  
