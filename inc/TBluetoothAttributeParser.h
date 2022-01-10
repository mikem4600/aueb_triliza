/*
* ============================================================================
*  Name     : TBluetoothAttributeParser from BluetoothAttributeParser.h
*  Part of  : AuebTriliza
*  Created  : 11/12/2004 by Makidis Mixalis & Karakatsiotis Giorgos
*  Description:
*     This class provides a mechanism for parsing a CSdpAttrValueDES type
*     object. It requires a reference to a MBluetoothAttributeObserver
*  Copyright: Makidis Mixalis & Karakatsiotis Giorgos 2004-2005
* ============================================================================
*/

#ifndef __TBLUETOOTHATTRIBUTEPARSER_H__
#define __TBLUETOOTHATTRIBUTEPARSER_H__

// System includes
#include <btsdp.h>

class MBluetoothAttributeObserver;

// CLASS DECLARATION

class TBluetoothAttributeParser : public MSdpAttributeValueVisitor
	{
	public: // Constructors
		TBluetoothAttributeParser(MBluetoothAttributeObserver& aObserver, TBool& aContinueSearching);

	public: 
		inline TBool 			Finished() const { return ( iProcessingState == EFinished ); }

	public: 
		void 				VisitAttributeValueL(CSdpAttrValue& aValue, TSdpElementType aType);
		void 				StartListL(CSdpAttrValueList& aList);
		void 				EndListL();

	private: 
		enum EProcessingState
			{
			EStartOfDesOne,
			EStartOfDesTwo,
			EL2Cap,
			EEndOfDesTwo,
			EStartDesThree,
			ERFComm,
			ERFCommPort,
			EEndOfDesThree,
			EEndOfDesOne,
			EFinished
			};

	private: // Member functions 
		void				Next();
		void				CompareRFCOMM( CSdpAttrValue& aAttrValue );
		void				GetPort( CSdpAttrValue& aAttrValue );

	private: // Member data
		EProcessingState		iProcessingState;
		TBool				iFinished;
		MBluetoothAttributeObserver&	iObserver;
		TUint				iPort;
		TBool&				iContinueSearching;
	};

#endif // __TBLUETOOTHATTRIBUTEPARSER_H__
