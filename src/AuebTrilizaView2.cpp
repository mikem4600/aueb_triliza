/*
* ============================================================================
*  Name     : CAuebTrilizaView2 from AuebTrilizaView2.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Implementation notes:
*     Initial content was generated by Series 60 AppWizard.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

// INCLUDE FILES
#include  <aknviewappui.h>
#include  <avkon.hrh>
#include  <AuebTriliza.rsg>
#include  "AuebTrilizaView2.h"
#include  "AuebTrilizaContainer2.h"
#include  "auebtriliza.hrh" // for commands
#include  <aknmessagequerydialog.h> // for query dialog

// ================= MEMBER FUNCTIONS =======================

CAuebTrilizaView2::CAuebTrilizaView2(CAuebTrilizaAppUi* aUi, CAuebTrilizaDocument* aDocument)
: iUi(aUi), iDocument(aDocument)
{}

// ---------------------------------------------------------
// CAuebTrilizaView2::ConstructL(const TRect& aRect)
// EPOC two-phased constructor
// ---------------------------------------------------------
//
void CAuebTrilizaView2::ConstructL()
    {
    BaseConstructL( R_AUEBTRILIZA_VIEW2 );
    }

// ---------------------------------------------------------
// CAuebTrilizaView2::~CAuebTrilizaView2()
// ?implementation_description
// ---------------------------------------------------------
//
CAuebTrilizaView2::~CAuebTrilizaView2()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    }

// ---------------------------------------------------------
// TUid CAuebTrilizaView2::Id()
// ?implementation_description
// ---------------------------------------------------------
//
TUid CAuebTrilizaView2::Id() const
    {
    return KView2Id;
    }

// ---------------------------------------------------------
// CAuebTrilizaView2::HandleCommandL(TInt aCommand)
// ?implementation_description
// ---------------------------------------------------------
//
void CAuebTrilizaView2::HandleCommandL(TInt aCommand)
    {
    switch ( aCommand )
        {
        case EAknSoftkeyBack:
		case EEndGame:
            {
				if ( iDocument->GetWinner() != CAuebTrilizaDocument::EEmpty ||
						iDocument->IsTableFull())
				{
					AppUi()->HandleCommandL( EShowWelcomeScreen );
				}
				else
				{
					CAknQueryDialog* confirmDialog = CAknQueryDialog::NewL(CAknQueryDialog::ENoTone);
					if (confirmDialog->ExecuteLD(R_END_GAME_DIALOG))
					{
						AppUi()->HandleCommandL( EShowWelcomeScreen );
					}
				}
            break;
            }
		case EExit:
			{
				if ( iDocument->GetWinner() != CAuebTrilizaDocument::EEmpty ||
						iDocument->IsTableFull())
				{
					AppUi()->HandleCommandL( aCommand );
				}
				else
				{
					CAknQueryDialog* confirmDialog = CAknQueryDialog::NewL(CAknQueryDialog::ENoTone);
					if (confirmDialog->ExecuteLD(R_END_GAME_DIALOG))
					{
						AppUi()->HandleCommandL( aCommand );
					}
				}
				break;
			}
        default:
            {
            AppUi()->HandleCommandL( aCommand );
            break;
            }
        }
    }

// ---------------------------------------------------------
// CAuebTrilizaView2::HandleClientRectChange()
// ---------------------------------------------------------
//
void CAuebTrilizaView2::HandleClientRectChange()
    {
    if ( iContainer )
        {
        iContainer->SetRect( ClientRect() );
        }
    }

// ---------------------------------------------------------
// CAuebTrilizaView2::DoActivateL(...)
// ?implementation_description
// ---------------------------------------------------------
//
void CAuebTrilizaView2::DoActivateL(
   const TVwsViewId& /*aPrevViewId*/,TUid /*aCustomMessageId*/,
   const TDesC8& /*aCustomMessage*/)
    {
    if (!iContainer)
        {
        iContainer = new (ELeave) CAuebTrilizaContainer2(iUi, iDocument);
        iContainer->SetMopParent(this);
        iContainer->ConstructL( ClientRect() );
        AppUi()->AddToStackL( *this, iContainer );
        }
        iContainer->UpdateDisplay();
   }

// ---------------------------------------------------------
// CAuebTrilizaView2::HandleCommandL(TInt aCommand)
// ?implementation_description
// ---------------------------------------------------------
//
void CAuebTrilizaView2::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromViewStack( *this, iContainer );
        }

    delete iContainer;
    iContainer = NULL;
    }

// End of File

