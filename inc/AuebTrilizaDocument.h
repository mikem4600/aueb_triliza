/*
* ============================================================================
*  Name     : CAuebTrilizaDocument from AuebTrilizaDocument.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     Declares document for application.
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef AUEBTRILIZADOCUMENT_H
#define AUEBTRILIZADOCUMENT_H

// INCLUDES
#include <akndoc.h>

// CONSTANTS

// FORWARD DECLARATIONS
class  CAuebTrilizaAppUi;

// CLASS DECLARATION

/**
*  CAuebTrilizaDocument application class.
*/
class CAuebTrilizaDocument : public CAknDocument
    {
    public: // Constructors and destructor
        /**
        * Two-phased constructor.
        */
        static CAuebTrilizaDocument* NewL(CEikApplication& aApp);

        /**
        * Destructor.
        */
        virtual ~CAuebTrilizaDocument();

		enum TPiece {EX, EO, EEmpty};

		enum TPlayer {ECurrentPlayer, EOpponent};

		enum TDifficulty {EEasy, EHard};

    private:

        /**
        * EPOC default constructor.
        */
        CAuebTrilizaDocument(CEikApplication& aApp);

        void ConstructL();

		void CheckTableFull();

		TBool CheckVictoryCondition(TPiece aColor);

		TPiece GetOpponentsColor();

    private:

        /**
        * From CEikDocument, create CAuebTrilizaAppUi "App UI" object.
        */
        CEikAppUi* CreateAppUiL();

	public:

		/**
        * Dimiourgei ena neo paixnidi (dil. kanei reset tin taksi)
        */
		void NewGame(TPlayer aWhoPlaysFirst, TPiece aCurrentPlayersColor, TBool aMultiplayer = ETrue);

		/**
        * Epistrefei ena simeio tis "skakieras"
        */
		TPiece GetPiece(TInt aPosition) {return iTable.At(aPosition);}

		/**
        * Epistrefei to xrwma tou trexontis paikti
        */
		TPiece GetPlayersColor(){return iPlayersColor;}

		/**
        * Ektelei mia kinsi, dil. prosthetei ena "pioni" stin "skakiera"
		* elegxontas gia tin egyrotita tis kinisis.
        */
		TBool PerformMove(TInt aPosition);

		/**
        * Elegxei an i "skakiera" einai gemati
        */
		TBool IsTableFull(){return iTableFull;}

		/**
        * Epistrefei ton nikiti, an yparxei.
        */
		TPiece GetWinner(){return iWinner;}

		/**
        * Epistrefei dyo akraia simeia (2x0-8) tis skakieras
		* opou nikise o nikitis.
        */
		TPoint GetWinnerPoints(){return iWinnerPoints;}

		/**
        * Thetei an o trexwn paiktis einai server.
		* Den exei noima sta single-player paixnidia.
        */
		void IsServer(TBool aIsServer);

		/**
        * Epistrefei an o trexwn paiktis einai server.
		* Den exei noima sta single-player paixnidia.
        */
		TBool IsServer();

		/**
        * Epistrefei mia kinisi tis AI (texnitis noimisynis)
		* me basi tin trexousa katastasi tis "skakieras".
        */
		TInt GetAIMove();

		/**
        * Thetei an o trexwn paiktis einai server.
		* Den exei noima sta single-player paixnidia.
        */
		TBool CheckVictoryCondition(TFixedArray<TPiece, 9> aRealTable, TInt aPosition, CAuebTrilizaDocument::TPiece aColor);

		/**
        * Elegxei gia apeili apo kapoion paikti.
        */
		TInt FindThreat(TFixedArray<TPiece, 9> aTable, TPiece aColor);

		TInt WinningMove(TFixedArray<TPiece, 9> aTable, TPiece aColor);

		TInt CAuebTrilizaDocument::FindDoubleThreat(TFixedArray<TPiece, 9> aTable, TPiece aColor);

		TInt CAuebTrilizaDocument::FindOpDoubleThreat(TFixedArray<TPiece, 9> aTable, TPiece aColor);

		/**
        * Epistrefei tin trexousa seira.
        */
		TPlayer GetCurrentTurn(){return iCurrentTurn;}

		/**
        * Thetei ton bathmo dyskolias
        */
		void SetDifficulty(TDifficulty aDifficulty);

	public:

		TInt iCurrentPos;

		TBool iMultiplayer;

	private:

		TPiece iWinner;

		TPoint iWinnerPoints;

		TBool iTableFull;

		TFixedArray<TPiece, 9> iTable;

		TPlayer iCurrentTurn;

		TPiece iPlayersColor;

		TDifficulty iDifficulty;

		CAuebTrilizaAppUi* iUi;

		TBool isServer;

		TInt64* iSeed;

    };

#endif

// End of File

