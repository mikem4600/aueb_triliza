/*
* ============================================================================
*  Name     : CAuebTrilizaApp from AuebTrilizaApp.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     Declares main application class.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef AUEBTRILIZAAPP_H
#define AUEBTRILIZAAPP_H

// INCLUDES
#include <aknapp.h>

// CONSTANTS
// UID of the application
const TUid KUidAuebTriliza = { 0x0ABCDEF4 };  // Please request a UID from Symbian

// CLASS DECLARATION

/**
* CAuebTrilizaApp application class.
* Provides factory to create concrete document object.
* 
*/
class CAuebTrilizaApp : public CAknApplication
    {
    
    public: // Functions from base classes
    private:

        /**
        * From CApaApplication, creates CAuebTrilizaDocument document object.
        * @return A pointer to the created document object.
        */
        CApaDocument* CreateDocumentL();
        
        /**
        * From CApaApplication, returns application's UID (KUidAuebTriliza).
        * @return The value of KUidAuebTriliza.
        */
        TUid AppDllUid() const;
    };

#endif

// End of File

