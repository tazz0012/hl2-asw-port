
#ifndef _MArgParser
#define _MArgParser
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MArgParser
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MArgParser)
//
// This class is used to parse and store all of the flags, arguments
// and objects which are passed to a command.  The MArgParser accepts
// an MSyntax object, which describes the format for a command, and uses
// it to parse the command arguments into a form which is easy to query.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>

// *****************************************************************************

// DECLARATIONS

class MSyntax;
class MSelectionList;
class MStringArray;
class MArgList;
class MDistance;
class MAngle;
class MTime;

// *****************************************************************************

// CLASS DECLARATION (MArgParser)

/// Command argument list parser
/**
This class parses argument lists based on a syntax object (MSyntax) 
which describes the format for a command.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MArgParser
{
public:
	///
			MArgParser();
	///
			MArgParser			(const MSyntax &syntax,
								 const MArgList &argList,
								 MStatus *ReturnStatus = NULL);
	///
	virtual ~MArgParser();

	///
	bool	isFlagSet			(const char *flag, 
								 MStatus *ReturnStatus = NULL) const;
	///
	bool	isEdit				(MStatus *ReturnStatus = NULL) const;
	///
	bool	isQuery				(MStatus *ReturnStatus = NULL) const;
 
	///
	unsigned int numberOfFlagsUsed	() const;
 	///
	unsigned int numberOfFlagUses	(const char *flag) const;
	///
	MStatus	getFlagArgument		(const char *flag, unsigned int index, 
								 bool &result) const;
	///
	MStatus	getFlagArgument		(const char *flag, unsigned int index,
								 int &result) const;
	///
	MStatus	getFlagArgument		(const char *flag, unsigned int index, 
								 double &result) const;
	///
	MStatus	getFlagArgument		(const char *flag, unsigned int index, 
								 MString &result) const;
	///
	MStatus getFlagArgument		(const char *flag, unsigned int index, 
								 unsigned int &result) const;
	///
	MStatus	getFlagArgument		(const char *flag, unsigned int index, 
								 MDistance &result) const;
	///
	MStatus	getFlagArgument		(const char *flag, unsigned int index, 
								 MAngle &result) const;
	///
	MStatus	getFlagArgument		(const char *flag, unsigned int index, 
								 MTime &result) const;
	///
	MStatus getFlagArgumentPosition
								(const char *flag, unsigned int i,
								 unsigned int &position) const;
	///
	MStatus getFlagArgumentList	(const char *flag, unsigned int i,
								 MArgList& args) const;

	///
	MStatus	getCommandArgument	(unsigned int index, bool &result) const;
	///
	MStatus	getCommandArgument	(unsigned int index, int &result) const;
	///
	MStatus	getCommandArgument	(unsigned int index, double &result) const;
	///
	MStatus	getCommandArgument	(unsigned int index, MString &result) const;
	///
	MStatus	getCommandArgument	(unsigned int index, MDistance &result) const;
	///
	MStatus	getCommandArgument	(unsigned int index, MAngle &result) const;
	///
	MStatus	getCommandArgument	(unsigned int index, MTime &result) const;

	///
	MStatus	getObjects			(MStringArray &result) const;

protected:
	bool fOwn;
	void *apiData;

private:
	const char *className() const;

	MArgParser (void *);
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MArgParser */

