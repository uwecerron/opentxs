/************************************************************************************
*
* OTAPI.cpp   --	A C++ Low-Level API (wraps OT_API)
*
* This is a C++ class that contains many helper functions.
*
*/

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <stdafx.hpp>

#include "OTAPI_Exec.hpp"

#include <OpenTransactions.hpp>

#include "OTAgent.hpp"
#include "OTAssetContract.hpp"
#include "OTAsymmetricKey.hpp"
#include "OTAmount.hpp"
#include "OTBasket.hpp"
#include "OTBylaw.hpp"
#include "OTCheque.hpp"
#include "OTClause.hpp"
#include "OTCredential.hpp"
#include "OTEnvelope.hpp"
#include "OTLedger.hpp"
#include "OTLog.hpp"
#include "OTMessage.hpp"
#include "OTMint.hpp"
#include "OTParty.hpp"
#include "OTPartyAccount.hpp"
#include "OTPassword.hpp"
#include "OTPasswordData.hpp"
#include "OTPaths.hpp"
#include "OTPayment.hpp"
#include "OTPaymentPlan.hpp"
#include "OTPseudonym.hpp"
#include "OTPurse.hpp"
#include "OTServerContract.hpp"
#include "OTStorage.hpp"
#include "OTSymmetricKey.hpp"
#include "OTToken.hpp"
#include "OTWallet.hpp"

#include "OTAccount.hpp"  //included in OTSmartContract.hpp


namespace opentxs {

#ifndef OT_BOOL
#define OT_BOOL int32_t
#endif

#ifndef OT_FALSE
const int32_t OT_FALSE = 0;
#endif

#ifndef OT_TRUE
const int32_t OT_TRUE = 1;
#endif


#ifndef OT_ERROR
const int32_t OT_ERROR = (-1);
#endif

// ---------------------------------------------------------------


bool OTAPI_Exec::bInitOTApp = false;
bool OTAPI_Exec::bCleanupOTApp = false;
// ---------------------------------------------------------------


OTAPI_Exec::OTAPI_Exec() : p_OTAPI(NULL)
{
}

OTAPI_Exec::~OTAPI_Exec()
{
}


// **********************************************************************

bool OTAPI_Exec::AppInit()    // Call this ONLY ONCE, when your App first starts up.
{
	if (!OTAPI_Exec::bCleanupOTApp)
	{
		if (!OTAPI_Exec::bInitOTApp)
		{
			OTAPI_Exec::bInitOTApp = true;
			if (OT_API::InitOTApp())
			{
				OT_API * tmpOTAPI = new OT_API();
				if (NULL != tmpOTAPI)
				{
					if (tmpOTAPI->IsInitialized())
					{
						if (tmpOTAPI->SetTransportCallback(new TransportCallback(*tmpOTAPI)))
						{
							p_OTAPI = tmpOTAPI; // success
							return true;
						}
					}
					delete tmpOTAPI;
					tmpOTAPI = NULL;
				}
			}
		}
	}
	return false;
}

bool OTAPI_Exec::AppCleanup() // Call this ONLY ONCE, when your App is shutting down.
{
	if (!OTAPI_Exec::bCleanupOTApp) // if we haven't cleaned up already
	{
		if (OTAPI_Exec::bInitOTApp) // and have had a ctx.
		{
			// will cleanup everything.
			if (NULL != p_OTAPI) delete p_OTAPI;
			p_OTAPI = NULL;

			OTAPI_Exec::bCleanupOTApp = true;
			return OT_API::CleanupOTApp();
		}
	}
	return false;
}




// --------------------------------------------------------------------
// SetAppBinaryFolder
// OPTIONAL. Used in Android and Qt.
//
// Certain platforms use this to override the Prefix folder.
// Basically /usr/local is the prefix folder by default, meaning
// /usr/local/lib/opentxs will be the location of the scripts. But
// if you override AppBinary folder to, say, "res/raw"
// (Android does something like that) then even though the prefix remains
// as /usr/local, the scripts folder will be res/raw
//
//
void OTAPI_Exec::SetAppBinaryFolder(const std::string & strFolder)
{
    OTPaths::SetAppBinaryFolder(strFolder.c_str());
}

// --------------------------------------------------------------------
// SetHomeFolder
// OPTIONAL. Used in Android.
//
// The AppDataFolder, such as /Users/au/.ot, is constructed from the home
// folder, such as /Users/au.
//
// Normally the home folder is auto-detected, but certain platforms, such as
// Android, require us to explicitly set this folder from the Java code. Then
// the AppDataFolder is constructed from it. (It's the only way it can be done.)
//
// In Android, you would SetAppBinaryFolder to the path to "/data/app/packagename/res/raw",
// and you would SetHomeFolder to "/data/data/[app package]/files/"
//
void OTAPI_Exec::SetHomeFolder(const std::string & strFolder)
{
    OTPaths::SetHomeFolder(strFolder.c_str());
}




OT_API * OTAPI_Exec::OTAPI()
{
	return p_OTAPI;
}


int64_t OTAPI_Exec::StringToLong(const std::string &strNumber)
{
    return OTString::StringToLong(strNumber);
}


std::string OTAPI_Exec::LongToString(const int64_t & lNumber)
{
	std::string strNumber;
	std::stringstream strstream;

	strstream << lNumber;
	strstream >> strNumber;

	return strNumber;
}


uint64_t OTAPI_Exec::StringToUlong(const std::string &strNumber)
{
    return OTString::StringToUlong(strNumber);
}


std::string OTAPI_Exec::UlongToString(const uint64_t & lNumber)
{
    std::string strNumber;
    std::stringstream strstream;

    strstream << lNumber;
    strstream >> strNumber;

    return strNumber;
}


// --------------------------------------------------------------------
/** Output to the screen (stderr.)
(This is so stdout can be left clean for the ACTUAL output.)
Log level is 0 (least verbose) to 5 (most verbose.)
*/
void OTAPI_Exec::Output(const int32_t & nLogLevel, const std::string & strOutput)
{
	const OTString otstrOutput(!strOutput.empty() ? strOutput : "\n");

	OTLog::Output(nLogLevel, otstrOutput.Get());
}




bool OTAPI_Exec::SetWallet(const std::string & strWalletFilename)
{
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized)
	{
		OTLog::sError("%s: Error: OT_API not Initialized!!\n", __FUNCTION__);
		OT_FAIL;
	}
	else
	{
		OTString sWalletFilename(strWalletFilename);

		if (sWalletFilename.Exists())
		{
			return OTAPI()->SetWalletFilename(strWalletFilename);
		}
		else
		{
			OTLog::sError("%s: Error:: Wallet Filename is Null!\n", __FUNCTION__);
		}
		OT_FAIL;
	}
}

// --------------------------------------------------------------------
/**
WALLET EXISTS

Just Checks if the m_pWallet pointer is not null.

WalletExists();

*/
bool OTAPI_Exec::WalletExists()
{
	return OTAPI()->WalletExists();
}

bool OTAPI_Exec::LoadWallet()
{
	return OTAPI()->LoadWallet();
}




bool OTAPI_Exec::SwitchWallet()
{
	return OTAPI()->LoadWallet();
}


// ----------------------------------------------------------------


int32_t OTAPI_Exec::GetMemlogSize()
{
	return OTLog::GetMemlogSize();
}


std::string OTAPI_Exec::GetMemlogAtIndex(const int32_t & nIndex)
{
	return OTLog::GetMemlogAtIndex(nIndex).Get();
}


std::string OTAPI_Exec::PeekMemlogFront()
{
	return OTLog::PeekMemlogFront().Get();
}


std::string OTAPI_Exec::PeekMemlogBack()
{
	return OTLog::PeekMemlogBack().Get();
}


bool OTAPI_Exec::PopMemlogFront()
{
	return OTLog::PopMemlogFront();
}


bool OTAPI_Exec::PopMemlogBack()
{
	return OTLog::PopMemlogBack();
}



// OpenTransactions.h
//bool      NumList_Add        (OTNumList & theList, const OTNumList & theNewNumbers);
//bool      NumList_Remove     (OTNumList & theList, const OTNumList & theOldNumbers);
//bool      NumList_VerifyQuery(OTNumList & theList, const OTNumList & theQueryNumbers);
//bool      NumList_VerifyAll  (OTNumList & theList, const OTNumList & theQueryNumbers);
//int32_t   NumList_Count      (OTNumList & theList);

// OTAPI_funcdef.h
//std::string      OTAPI_Exec::NumList_Add        (const std::string & strNumList, const std::string & strNumbers);
//std::string      OTAPI_Exec::NumList_Remove     (const std::string & strNumList, const std::string & strNumbers);
//int32_t          OTAPI_Exec::NumList_VerifyQuery(const std::string & strNumList, const std::string & strNumbers); // returns bool
//int32_t          OTAPI_Exec::NumList_VerifyAll  (const std::string & strNumList, const std::string & strNumbers); // returns bool
//int32_t          OTAPI_Exec::NumList_Count      (const std::string & strNumList);


// Returns new list if ALL strNumbers are successfully added to strNumList.
// Otherwise returns "" and doesn't change anything.
//
std::string OTAPI_Exec::NumList_Add(const std::string & strNumList, const std::string & strNumbers)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized)    { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }
	if (strNumbers.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers"       ); OT_FAIL; }

	// strNumList can be null, (create a new one).
	// -----------------------------------------------------
	OTNumList theList, theNewNumbers(strNumbers);

	if ("" != strNumList)
	{
		const OTString otstrNumList(strNumList);
		theList.Add(otstrNumList);
	}

	const bool & bAdded = OTAPI()->NumList_Add(theList, theNewNumbers);

	OTString strOutput;
	if (bAdded && theList.Output(strOutput))
	{
		std::string pBuf = strOutput.Get();

		return pBuf;
	}

	return "";
}

// Returns new list if ALL strNumbers are successfully removed from strNumList.
// Otherwise returns "" and doesn't change anything.
//
std::string OTAPI_Exec::NumList_Remove(const std::string & strNumList, const std::string & strNumbers)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

	if (strNumList.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList" ); OT_FAIL; }
	if (strNumbers.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers" ); OT_FAIL; }
	// -----------------------------------------------------

	OTNumList theList(strNumList), theNewNumbers(strNumbers);

	const bool & bRemoved = OTAPI()->NumList_Remove(theList, theNewNumbers);

	OTString strOutput;
	if (bRemoved && theList.Output(strOutput))
	{
		std::string pBuf = strOutput.Get();

		return pBuf;
	}

	return "";
}

// Verifies strNumbers as a SUBSET of strNumList.
//
bool OTAPI_Exec::NumList_VerifyQuery(const std::string & strNumList, const std::string & strNumbers)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }

	if (strNumList.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList" ); OT_FAIL; }
	if (strNumbers.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers" ); OT_FAIL; }
	// -----------------------------------------------------

	OTNumList theList(strNumList), theNewNumbers(strNumbers);

	const bool & bVerified = OTAPI()->NumList_VerifyQuery(theList, theNewNumbers);

	return bVerified ? true : false;
}

// Verifies COUNT and CONTENT but NOT ORDER.
//
bool OTAPI_Exec::NumList_VerifyAll(const std::string & strNumList, const std::string & strNumbers)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized)    { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__  ); OT_FAIL; }
	if (strNumList.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_FAIL; }
	if (strNumbers.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers"			); OT_FAIL; }
	// -----------------------------------------------------
	OTNumList theList(strNumList), theNewNumbers(strNumbers);

	const bool & bVerified = OTAPI()->NumList_VerifyAll(theList, theNewNumbers);

	return bVerified ? true : false;
}

int32_t OTAPI_Exec::NumList_Count(const std::string & strNumList)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized)    { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__  ); OT_FAIL; }
	if (strNumList.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_FAIL; }
	// -----------------------------------------------------
	OTNumList theList(strNumList);

	return OTAPI()->NumList_Count(theList);
}




// --------------------------------------------------
// CREATE NYM  -- Create new User
//
// Creates a new Nym and adds it to the wallet.
// (Including PUBLIC and PRIVATE KEYS.)
//
// Returns a new User ID (with files already created)
// or "" upon failure.
//
// Once it exists, use OTAPI_Exec::createUserAccount() to
// register your new Nym at any given Server. (Nearly all
// server requests require this...)
//
std::string OTAPI_Exec::CreateNym(const int32_t     & nKeySize, // must be 1024, 2048, 4096, or 8192
                                  const std::string & NYM_ID_SOURCE, // Can be empty.
                                  const std::string & ALT_LOCATION)  // Can be empty.
{
	if (0 >= nKeySize) { OTLog::vError("%s: Keysize is 0 or less, will fail! Try 1024.\n",__FUNCTION__); OT_FAIL; }
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->CreateNym(nKeySize, NYM_ID_SOURCE, ALT_LOCATION);
	if (NULL == pNym) // Creation failed.
	{
		OTLog::vOutput(0, "%s: Failed trying to create Nym.\n", __FUNCTION__);
		return "";
	}
	// -----------------------------------------------------}
	OTString strOutput;
	pNym->GetIdentifier(strOutput); // We're returning the new Nym ID.
	// --------------------------------
	if (strOutput.Exists()) return strOutput.Get();
	// --------------------------------
	return "";
}


std::string OTAPI_Exec::GetNym_ActiveCronItemIDs(const std::string & NYM_ID,
    const std::string & SERVER_ID)
{
    if (NYM_ID.empty())    { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID");    OT_FAIL; }
    if (SERVER_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "SERVER_ID"); OT_FAIL; }
    // ---------------------------------------------------------
    const OTIdentifier nymId(NYM_ID), serverId(SERVER_ID);
    // ---------------------------------------------------------
    OTNumList   numlist;
    std::string str_return;

    if (OTCronItem::GetActiveCronTransNums(numlist, nymId, serverId))
    {
        OTString strOutput;
        numlist.Output(strOutput);
        str_return = strOutput.Get();
    }

    return str_return;
}

std::string OTAPI_Exec::GetActiveCronItem(const std::string & SERVER_ID, int64_t lTransNum)
{
    if (SERVER_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "SERVER_ID"); OT_FAIL; }
    if (0 > lTransNum)     { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "lTransNum"); OT_FAIL; }
    // --------------------------------------
    const OTIdentifier serverId(SERVER_ID);
    std::string        str_return;
    // --------------------------------------
    const int64_t lTransactionNum = static_cast<int64_t>(lTransNum);

    OTCronItem * pCronItem = OTCronItem::LoadActiveCronReceipt(lTransactionNum, serverId);
    OTCleanup<OTCronItem> theCronItemAngel(pCronItem);
    // --------------------------------------
    if (NULL != pCronItem)
    {
        const OTString strCronItem(*pCronItem);

        str_return = strCronItem.Get();
    }
    // --------------------------------------
    return str_return;
}


std::string OTAPI_Exec::GetNym_SourceForID(const std::string & NYM_ID)
{
    if (NYM_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    const std::string str_return(pNym->GetNymIDSource().Get());
    return str_return;
}


std::string OTAPI_Exec::GetNym_AltSourceLocation(const std::string & NYM_ID)
{
    if (NYM_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    const std::string str_return(pNym->GetAltLocation().Get());
    return str_return;
}

int32_t OTAPI_Exec::GetNym_CredentialCount(const std::string & NYM_ID)
{
    if (NYM_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return (-1);
	// ---------------------------------------------------------
    const int32_t nReturnValue = static_cast<int32_t>(pNym->GetMasterCredentialCount());
    return nReturnValue;
}


std::string OTAPI_Exec::GetNym_CredentialID(const std::string & NYM_ID,
                                            const int32_t     & nIndex)
{
    if (NYM_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    std::string    str_return;
    const OTCredential * pCredential = pNym->GetMasterCredentialByIndex(static_cast<const int32_t>(nIndex));

    if (NULL != pCredential)
        str_return = pCredential->GetMasterCredID().Get();
	// ---------------------------------------------------------
    return str_return;
}


std::string OTAPI_Exec::GetNym_CredentialContents(const std::string & NYM_ID,
                                                  const std::string & CREDENTIAL_ID)
{
    if (NYM_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    std::string    str_return;
    const OTString strCredID(CREDENTIAL_ID);
    OTCredential * pCredential = pNym->GetMasterCredential(strCredID);

    if (NULL != pCredential) // Found the master credential...
        str_return = pCredential->GetPubCredential().Get();
	// ---------------------------------------------------------
    return str_return;
}


int32_t OTAPI_Exec::GetNym_RevokedCredCount(const std::string & NYM_ID)
{
    if (NYM_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return (-1);
	// ---------------------------------------------------------
    const int32_t nReturnValue = static_cast<int32_t>(pNym->GetRevokedCredentialCount());
    return nReturnValue;
}


std::string OTAPI_Exec::GetNym_RevokedCredID(const std::string & NYM_ID,
                                             const int32_t     & nIndex)
{
    if (NYM_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    std::string str_return;
    const OTCredential * pCredential = pNym->GetRevokedCredentialByIndex(static_cast<const int32_t>(nIndex));

    if (NULL != pCredential)
    {
        str_return = pCredential->GetMasterCredID().Get();
    }
	// ---------------------------------------------------------
    return str_return;
}


std::string OTAPI_Exec::GetNym_RevokedCredContents(const std::string & NYM_ID,
                                                   const std::string & CREDENTIAL_ID)
{
    if (NYM_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    std::string str_return;
    const OTString strCredID(CREDENTIAL_ID);
    const OTCredential * pCredential = pNym->GetRevokedCredential(strCredID);

    if (NULL != pCredential) // Found the (revoked) master credential...
        str_return = pCredential->GetPubCredential().Get();
	// ---------------------------------------------------------
    return str_return;
}


int32_t OTAPI_Exec::GetNym_SubcredentialCount(const std::string & NYM_ID,
                                              const std::string & MASTER_CRED_ID)
{
    if (NYM_ID.empty())         { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID");         OT_FAIL; }
    if (MASTER_CRED_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "MASTER_CRED_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return (-1);
	// ---------------------------------------------------------
    const OTString strCredID(MASTER_CRED_ID);
    OTCredential * pCredential = pNym->GetMasterCredential(strCredID);

    if (NULL != pCredential) // Found the master credential...
    {
        const size_t nSubCredCount = pCredential->GetSubcredentialCount();

        const int32_t nReturnValue = static_cast<const int32_t>(nSubCredCount);
        return nReturnValue;
    }

    return (-1);
}


std::string OTAPI_Exec::GetNym_SubCredentialID(const std::string & NYM_ID,
                                               const std::string & MASTER_CRED_ID,
                                               const int32_t     & nIndex)
{
    if (NYM_ID.empty())         { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID");         OT_FAIL; }
    if (MASTER_CRED_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "MASTER_CRED_ID"); OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    const OTString strCredID(MASTER_CRED_ID);
    OTCredential * pCredential = pNym->GetMasterCredential(strCredID);

    if (NULL != pCredential) // Found the master credential...
        return pCredential->GetSubcredentialIDByIndex(static_cast<const int32_t>(nIndex));

    return "";
}


std::string OTAPI_Exec::GetNym_SubCredentialContents(const std::string & NYM_ID,
                                                     const std::string & MASTER_CRED_ID,
                                                     const std::string & SUB_CRED_ID)
{
    if (NYM_ID.empty())         { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID");         OT_FAIL; }
    if (MASTER_CRED_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "MASTER_CRED_ID"); OT_FAIL; }
    if (SUB_CRED_ID.empty())    { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "SUB_CRED_ID");    OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    const OTString strCredID(MASTER_CRED_ID);
    OTCredential * pCredential = pNym->GetMasterCredential(strCredID);

    if (NULL != pCredential) // Found the master credential...
    {
        const OTString strSubID(SUB_CRED_ID);
        const OTSubcredential * pSub = pCredential->GetSubcredential(strSubID);

        if (NULL != pSub)
            return pSub->GetPubCredential().Get();
    }
    // --------------
    return "";
}



std::string OTAPI_Exec::AddSubcredential(const std::string & NYM_ID, const std::string & MASTER_CRED_ID, const int32_t & nKeySize)
{
    if (NYM_ID.empty())         { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID");         OT_FAIL; }
    if (MASTER_CRED_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "MASTER_CRED_ID"); OT_FAIL; }
    if (0 >= nKeySize)          { OTLog::vError("%s: Keysize is 0 or less, will fail! Try 1024.\n",__FUNCTION__);     OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadPrivateNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    const OTString strCredID(MASTER_CRED_ID);
    OTCredential * pCredential = pNym->GetMasterCredential(strCredID);

    if (NULL == pCredential)
        OTLog::vOutput(0, "%s: Sorry, (Nym %s) no master credential found with the ID: %s\n",
                       __FUNCTION__, NYM_ID.c_str(), strCredID.Get());
    else // Found the master credential...
    {
        const OTIdentifier idMasterCredential(strCredID);
        OTString strNewSubcredID;

        const bool bAdded = pNym->AddNewSubkey(idMasterCredential, nKeySize, NULL, &thePWData, &strNewSubcredID);

        if (bAdded)
        {
            return strNewSubcredID.Get();
        }
        else
            OTLog::vError("%s: Failed trying to add new subcredential.\n", __FUNCTION__);
    }
    // --------------
    return "";
}


bool OTAPI_Exec::RevokeSubcredential(const std::string & NYM_ID, const std::string & MASTER_CRED_ID, const std::string & SUB_CRED_ID)
{
    if (NYM_ID.empty())         { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "NYM_ID");         OT_FAIL; }
    if (MASTER_CRED_ID.empty()) { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "MASTER_CRED_ID"); OT_FAIL; }
    if (SUB_CRED_ID.empty())    { OTLog::vError("%s: NULL %s passed in!\n", __FUNCTION__, "SUB_CRED_ID");    OT_FAIL; }
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     nym_id(NYM_ID);
    // This tries to get, then tries to load as public, then tries to load as private.
    OTPseudonym    * pNym = OTAPI()->GetOrLoadPrivateNym(nym_id, false, __FUNCTION__, &thePWData);
    if (NULL == pNym) return false;
	// ---------------------------------------------------------
    const OTString strCredID(MASTER_CRED_ID);
    OTCredential * pCredential = pNym->GetMasterCredential(strCredID);

    if (NULL == pCredential)
        OTLog::vOutput(0, "%s: Sorry, (Nym %s) no master credential found with the ID: %s\n",
                       __FUNCTION__, NYM_ID.c_str(), strCredID.Get());
    else // Found the master credential...
    {
        const OTString strSubID(SUB_CRED_ID);
        const OTSubcredential * pSub = pCredential->GetSubcredential(strSubID);

        if (NULL == pSub)
            OTLog::vOutput(0, "%s: Found master credential (%s), but unable to find subcredential with ID: %s\n",
                           __FUNCTION__, strCredID.Get(), strSubID.Get());
        else
        {


            // TODO: Okay we found master AND subcredential. Now let's revoke it...
            //



            OTLog::vError("\n\n\nOTAPI_Wrap::%s: TODO: REVOKING IS NOT YET CODED. ADD FUNCTION CALL HERE TO REVOKE SUB-CREDENTIAL!\n\n\n", __FUNCTION__);



//          return true;
        }
    }
    // --------------
    return false;
}



std::string OTAPI_Exec::CalculateAssetContractID(const std::string & str_Contract)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);  OT_FAIL; }
	// -----------------------------------------------------
	if (str_Contract.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "str_Contract" ); OT_FAIL; }
	// -----------------------------------------------------
	std::string str_Trim(str_Contract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

	if (strContract.GetLength() < 2)
	{
		OTLog::vOutput(0, "%s: Empty contract passed in!\n", __FUNCTION__);
		return "";
	}
	// -------------------------------------------
	OTAssetContract theContract;

    if (theContract.LoadContractFromString(strContract))
    {
        // -------------------------------------------
        OTIdentifier idOutput;
        theContract.CalculateContractID(idOutput);
        const OTString strOutput(idOutput);
        // -------------------------------------------
        std::string pBuf = strOutput.Get();

        return pBuf;
    }
    // ----------------
    return "";
}


std::string OTAPI_Exec::CalculateServerContractID(const std::string & str_Contract)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);  OT_FAIL; }
	// -----------------------------------------------------
	if (str_Contract.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "str_Contract" ); OT_FAIL; }
	// -----------------------------------------------------
	std::string str_Trim(str_Contract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

	if (strContract.GetLength() < 2)
	{
		OTLog::vOutput(0, "%s: Empty contract passed in!\n", __FUNCTION__);
		return "";
	}
	// -------------------------------------------
	OTServerContract theContract;

    if (theContract.LoadContractFromString(strContract))
    {
        // -------------------------------------------
        OTIdentifier idOutput;
        theContract.CalculateContractID(idOutput);
        const OTString strOutput(idOutput);
        // -------------------------------------------
        std::string pBuf = strOutput.Get();

        return pBuf;
    }
    // ----------------
    return "";
}


// Creates a contract based on the contents passed in,
// then sets the contract key based on the NymID,
// and signs it with that Nym.
// This function will also ADD the contract to the wallet.
// Returns: the new contract ID, or "" if failure.
//
std::string OTAPI_Exec::CreateServerContract(const std::string & NYM_ID, const std::string & strXMLcontents)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

	if (NYM_ID.empty())         { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"         ); OT_FAIL; }
	if (strXMLcontents.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strXMLcontents" ); OT_FAIL; }
	// -----------------------------------------------------

	OTWallet * pWallet = OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return "";
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------------------------
	std::string str_Trim(strXMLcontents);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

	if (strContract.GetLength() < 2)
	{
		OTLog::vOutput(0, "%s: Empty XML contents passed in! (Failure.)\n", __FUNCTION__);
		return "";
	}
	// -------------------------------------------
	OTServerContract * pContract = new OTServerContract;
	OT_ASSERT(NULL != pContract);
	OTCleanup<OTServerContract> theAngel(*pContract);
	pContract->CreateContract(strContract, *pNym); // <==========  **** CREATE CONTRACT!! ****
	// -------------------------------------------
	// But does it meet our requirements?
	//
	const OTPseudonym * pContractKeyNym = pContract->GetContractPublicNym();
//  const OTAsymmetricKey * pKey = pContract->GetContractPublicKey();

	if (NULL == pContractKeyNym)
	{
		OTLog::vOutput(0, "%s: Missing 'key' tag with name=\"contract\" and text value containing "
			"the public cert or public key of the signer Nym. (Please add it first. Failure.)\n",
			__FUNCTION__);
		return "";
	}
	else if (false == pNym->CompareID(*pContractKeyNym))
	{
		OTLog::vOutput(0, "%s: Found 'key' tag with name=\"contract\" and text value, but it apparently does NOT contain "
			"the public cert or public key of the signer Nym. Please fix that first; see the sample data. (Failure.)\n",
			__FUNCTION__);
		return "";
	}
	/*
	<key name="contract">
	- -----BEGIN CERTIFICATE-----
	MIICZjCCAc+gAwIBAgIJAO14L19TJgzcMA0GCSqGSIb3DQEBBQUAMFcxCzAJBgNV
	BAYTAlVTMREwDwYDVQQIEwhWaXJnaW5pYTEQMA4GA1UEBxMHRmFpcmZheDERMA8G
	A1UEChMIWm9yay5vcmcxEDAOBgNVBAMTB1Jvb3QgQ0EwHhcNMTAwOTI5MDUyMzAx
	WhcNMjAwOTI2MDUyMzAxWjBeMQswCQYDVQQGEwJVUzERMA8GA1UECBMIVmlyZ2lu
	aWExEDAOBgNVBAcTB0ZhaXJmYXgxETAPBgNVBAoTCFpvcmsub3JnMRcwFQYDVQQD
	Ew5zaGVsbC56b3JrLm9yZzCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEA3vD9
	fO4ov4854L8wXrgfv2tltDz0ieVrTNSLuy1xuQyb//+MwZ0EYwu8jMMQrqbUaYG6
	y8zJu32yBKrBNPPwJ+fJE+tfgVg860dGVbwMd4KhpkKtppJXmZaGqLqvELaXa4Uw
	9N3qg/faj0NMEDIBhv/tD/B5U65vH+U0JlRJ07kCAwEAAaMzMDEwCQYDVR0TBAIw
	ADAkBgNVHREEHTAbgg5zaGVsbC56b3JrLm9yZ4IJbG9jYWxob3N0MA0GCSqGSIb3
	DQEBBQUAA4GBALLXPa/naWsiXsw0JwlSiG7aOmvMF2romUkcr6uObhN7sghd38M0
	l2kKTiptnA8txrri8RhqmQgOgiyKFCKBkxY7/XGot62cE8Y1+lqGXlhu2UHm6NjA
	pRKvng75J2HTjmmsbCHy+nexn4t44wssfPYlGPD8sGwmO24u9tRfdzJE
	- -----END CERTIFICATE-----
	</key>
	*/
	// -------------------------------------------
	OTString strHostname; int32_t nPort=0;

	if (false == pContract->GetConnectInfo(strHostname, nPort))
	{
		OTLog::vOutput(0, "%s: Unable to retrieve connection info from this contract. Please "
			"fix that first; see the sample data. (Failure.)\n", __FUNCTION__);
		return "";
	}
	// -------------------------------------------
	// By this point, we know that the "contract" key is properly attached
	// to the raw XML contents, AND that the NymID for that key matches
	// the NymID passed into this function.
	// We also know that the connect info was properly attached to this
	// server contract.
	// So we can proceed to add it to the wallet...
	//
	// -----------------------------------------------------
    OTIdentifier idOutput;
	pContract->CalculateContractID(idOutput);
	const OTString strOutput(idOutput);

	pWallet->AddServerContract(*pContract);
	theAngel.SetCleanupTargetPointer(NULL); // (No need to cleanup anymore.)
	pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
	// -------------------------------------------
	std::string pBuf = strOutput.Get();

	return pBuf;
}


std::string OTAPI_Exec::CreateAssetContract (const std::string & NYM_ID, const std::string & strXMLcontents )
{
	bool bIsInitialized = OTAPI()->IsInitialized();
	// -----------------------------------------------------
	if (!bIsInitialized)        { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }
	if (NYM_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			  ); OT_FAIL; }
	if (strXMLcontents.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strXMLcontents"   ); OT_FAIL; }
	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return "";
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------------------------
	std::string str_Trim(strXMLcontents);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

	if (strContract.GetLength() < 2)
	{
		OTLog::vOutput(0, "%s: Empty XML contents passed in! (Failure.)\n", __FUNCTION__);
		return "";
	}
	// -------------------------------------------
	OTAssetContract * pContract = new OTAssetContract;
	OT_ASSERT(NULL != pContract);
	OTCleanup<OTAssetContract> theAngel(*pContract);
	pContract->CreateContract(strContract, *pNym); // <==========  **** CREATE CONTRACT!! ****
	// -------------------------------------------
	// But does it meet our requirements?
	//
	const OTPseudonym * pContractKeyNym = pContract->GetContractPublicNym();
//  const OTAsymmetricKey * pKey = pContract->GetContractPublicKey();

	if (NULL == pContractKeyNym)
	{
		OTLog::vOutput(0, "%s: Missing 'key' tag with name=\"contract\" and text value containing "
			"the public cert or public key of the signer Nym. (Please add it first. Failure.)\n",
			__FUNCTION__);
		return "";
	}
	else if (false == pNym->CompareID(*pContractKeyNym))
	{
		OTLog::vOutput(0, "%s: Found 'key' tag with name=\"contract\" and text value, but it apparently does NOT contain "
			"the public cert or public key of the signer Nym. Please fix that first; see the sample data. (Failure.)\n",
			__FUNCTION__);
		return "";
	}
	/*
	<key name="contract">
	- -----BEGIN CERTIFICATE-----
	MIICZjCCAc+gAwIBAgIJAO14L19TJgzcMA0GCSqGSIb3DQEBBQUAMFcxCzAJBgNV
	BAYTAlVTMREwDwYDVQQIEwhWaXJnaW5pYTEQMA4GA1UEBxMHRmFpcmZheDERMA8G
	A1UEChMIWm9yay5vcmcxEDAOBgNVBAMTB1Jvb3QgQ0EwHhcNMTAwOTI5MDUyMzAx
	WhcNMjAwOTI2MDUyMzAxWjBeMQswCQYDVQQGEwJVUzERMA8GA1UECBMIVmlyZ2lu
	aWExEDAOBgNVBAcTB0ZhaXJmYXgxETAPBgNVBAoTCFpvcmsub3JnMRcwFQYDVQQD
	Ew5zaGVsbC56b3JrLm9yZzCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEA3vD9
	fO4ov4854L8wXrgfv2tltDz0ieVrTNSLuy1xuQyb//+MwZ0EYwu8jMMQrqbUaYG6
	y8zJu32yBKrBNPPwJ+fJE+tfgVg860dGVbwMd4KhpkKtppJXmZaGqLqvELaXa4Uw
	9N3qg/faj0NMEDIBhv/tD/B5U65vH+U0JlRJ07kCAwEAAaMzMDEwCQYDVR0TBAIw
	ADAkBgNVHREEHTAbgg5zaGVsbC56b3JrLm9yZ4IJbG9jYWxob3N0MA0GCSqGSIb3
	DQEBBQUAA4GBALLXPa/naWsiXsw0JwlSiG7aOmvMF2romUkcr6uObhN7sghd38M0
	l2kKTiptnA8txrri8RhqmQgOgiyKFCKBkxY7/XGot62cE8Y1+lqGXlhu2UHm6NjA
	pRKvng75J2HTjmmsbCHy+nexn4t44wssfPYlGPD8sGwmO24u9tRfdzJE
	- -----END CERTIFICATE-----
	</key>
	*/
	// -------------------------------------------
	// By this point, we know that the "contract" key is properly attached
	// to the raw XML contents, AND that the NymID for that key matches
	// the NymID passed into this function.
	// So we can proceed to add it to the wallet...
	//
	// -----------------------------------------------------
    OTIdentifier idOutput;
	pContract->CalculateContractID(idOutput);
	const OTString strOutput(idOutput);

	pWallet->AddAssetContract(*pContract);
	theAngel.SetCleanupTargetPointer(NULL); // (No need to cleanup anymore.)
	pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
	// -------------------------------------------
	std::string pBuf = strOutput.Get();

	return pBuf;
}



// Use these below functions to get the new contract ITSELF, using its ID
// that was returned by the above two functions:
//
//std::string OTAPI_Exec::GetServer_Contract(const std::string & SERVER_ID); // Return's Server's contract (based on server ID)
//std::string OTAPI_Exec::GetAssetType_Contract(const std::string & ASSET_TYPE_ID); // Returns currency contract based on Asset Type ID


std::string OTAPI_Exec::GetServer_Contract(const std::string & SERVER_ID) // Return's Server's contract (based on server ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();

	if (!bIsInitialized)   { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"        ); OT_FAIL; }
	// -----------------------------------------------------

	// --------------------------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID);
	OTServerContract * pServer = OTAPI()->GetServer(theServerID, __FUNCTION__);
	if (NULL == pServer) return "";
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTString strOutput(*pServer);
	std::string pBuf = strOutput.Get();

	return pBuf;
}


// Returns amount from formatted string, based on currency contract and locale.
//
int64_t OTAPI_Exec::StringToAmount(const std::string & ASSET_TYPE_ID, const std::string & str_input)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized)       { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Empty %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"    ); OT_FAIL; }
	// -----------------------------------------------------
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	OTAssetContract * pContract = OTAPI()->GetAssetType(theAssetID, __FUNCTION__);
	if (NULL == pContract) return 0;
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	OTAmount        theResult;
    const int64_t   lBackup = StringToLong(str_input);
	const bool      bParsed = pContract->StringToAmount(theResult, str_input); // Convert $5.45 to 545.

    if (bParsed)
        return theResult.GetAmount();

    return lBackup;
}

// Returns formatted string for output, for a given amount, based on currency contract and locale.
//
std::string OTAPI_Exec::FormatAmount(const std::string & ASSET_TYPE_ID, const int64_t & THE_AMOUNT)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized)       { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Empty %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"    ); OT_FAIL; }
	// -----------------------------------------------------
    // NOTE: probably just remove this. I think we now allow negative amounts to be formatted.
//	if (0 > THE_AMOUNT)
//  {
//      OTLog::vError("%s: Negative: %s passed in: %s\n", __FUNCTION__, "THE_AMOUNT", OTAPI_Exec::LongToString(THE_AMOUNT).c_str());
//      OT_FAIL;
//  }
	// -----------------------------------------------------
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	OTAssetContract * pContract = OTAPI()->GetAssetType(theAssetID, __FUNCTION__);
	if (NULL == pContract) return "";
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const int64_t    lAmount = THE_AMOUNT;
	OTAmount         theAmount(lAmount);
	OTString         strBackup(LongToString(THE_AMOUNT));
	std::string      str_result;
	const bool       bFormatted = pContract->FormatAmount(theAmount, str_result); // Convert 545 to $5.45.
	const OTString   strOutput(bFormatted ? str_result.c_str() : strBackup.Get());

	std::string pBuf = strOutput.Get();
	return pBuf;
}

std::string OTAPI_Exec::GetAssetType_Contract(const std::string & ASSET_TYPE_ID) // Returns currency contract based on Asset Type ID
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	// -----------------------------------------------------

	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	OTAssetContract * pContract = OTAPI()->GetAssetType(theAssetID, __FUNCTION__);
	if (NULL == pContract) return "";
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTString strOutput(*pContract);
	std::string pBuf = strOutput.Get();
	return pBuf;
}



// ---------------------------------------------------------------




// If you have a server contract that you'd like to add
// to your wallet, call this function.
//
int32_t OTAPI_Exec::AddServerContract(const std::string & strContract)
{
	if (strContract.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strContract" ); OT_FAIL; }
	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OT_ASSERT("" != strContract);
	std::string str_Trim(strContract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString otstrContract(str_Trim2.c_str());
	// -----------------------------------------------------
	OTServerContract * pContract = new OTServerContract;
	OT_ASSERT(NULL != pContract);

	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
	//	if (pContract->LoadContract() && pContract->VerifyContract())
	if (otstrContract.Exists() && pContract->LoadContractFromString(otstrContract))
	{
		OTIdentifier theContractID;

		pContract->CalculateContractID(theContractID);
		pContract->SetIdentifier(theContractID);

		pWallet->AddServerContract(*pContract);
		pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
	}
	// cleanup
	if (pContract)
	{
		delete pContract;
		pContract = NULL;

		return false;
	}

	return true;
}


// If you have an asset contract that you'd like to add
// to your wallet, call this function.
//
int32_t OTAPI_Exec::AddAssetContract(const std::string & strContract)
{
	if (strContract.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strContract" ); OT_FAIL; }
	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OT_ASSERT("" != strContract);
	std::string str_Trim(strContract);
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString otstrContract(str_Trim2.c_str());

	OTAssetContract * pContract = new OTAssetContract;
	OT_ASSERT(NULL != pContract);

	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
	//	if (pContract->LoadContract() && pContract->VerifyContract())
	if (otstrContract.Exists() && pContract->LoadContractFromString(otstrContract))
	{
		OTIdentifier theContractID;

		pContract->CalculateContractID(theContractID);
		pContract->SetIdentifier(theContractID);

		// Next make sure the wallet has this contract on its list...
		pWallet->AddAssetContract(*pContract);
		pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
	}
	// cleanup
	if (pContract)
	{
		delete pContract;
		pContract = NULL;

		return false;
	}
	return true;
}



// --------------------------------------------------




int32_t OTAPI_Exec::GetNymCount(void)
{
	return OTAPI()->GetNymCount();
}

int32_t OTAPI_Exec::GetServerCount(void)
{
	return OTAPI()->GetServerCount();
}

int32_t OTAPI_Exec::GetAssetTypeCount(void)
{
	return OTAPI()->GetAssetTypeCount();
}

int32_t OTAPI_Exec::GetAccountCount(void)
{
	return OTAPI()->GetAccountCount();
}



// ----------------------------------------------------------------


// *** FUNCTIONS FOR REMOVING VARIOUS CONTRACTS AND NYMS FROM THE WALLET ***

// Can I remove this server contract from my wallet?
//
// You cannot remove the server contract from your wallet if there are accounts (or nyms) in there using it.
// This function tells you whether you can remove the server contract or not. (Whether there are accounts or nyms using it...)
//
// returns bool
//
bool OTAPI_Exec::Wallet_CanRemoveServer(const std::string & SERVER_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized)   { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	// -----------------------------------------------------
	OTIdentifier theID(SERVER_ID);
	// ------------------------------------------
	const int32_t & nCount = OTAPI_Exec::GetAccountCount();

	// Loop through all the accounts.
	for (int32_t i = 0; i < nCount; i++)
	{
		std::string pAcctID = OTAPI_Exec::GetAccountWallet_ID(i);
		OTString strAcctID(pAcctID);

		std::string pID = OTAPI_Exec::GetAccountWallet_ServerID(strAcctID.Get());
		OTIdentifier theCompareID(pID);

		if (theID == theCompareID)
		{
			OTLog::vOutput(0, "%s: Unable to remove server contract %s from wallet, because Account %s uses it.\n",__FUNCTION__, SERVER_ID.c_str(), strAcctID.Get());
			return false;
		}
	}
	// ------------------------------------------
	const int32_t & nNymCount = OTAPI_Exec::GetNymCount();

	// Loop through all the Nyms. (One might be registered on that server.)
	//
	for (int32_t i = 0; i < nNymCount; i++)
	{
		std::string pNymID = OTAPI_Exec::GetNym_ID(i);
		OTString strNymID(pNymID);

		if (true == OTAPI_Exec::IsNym_RegisteredAtServer(strNymID.Get(), SERVER_ID))
		{
			OTLog::vOutput(0, "%s: Unable to remove server contract %s from wallet, because Nym %s is registered there. (Delete that first...)\n",
				__FUNCTION__, SERVER_ID.c_str(), strNymID.Get());
			return false;
		}
	}
	return true;
}

// Remove this server contract from my wallet!
//
// Try to remove the server contract from the wallet.
// This will not work if there are any accounts in the wallet for the same server ID.
// returns bool
//
bool OTAPI_Exec::Wallet_RemoveServer(const std::string & SERVER_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	// -----------------------------------------------------

	// Make sure there aren't any dependent accounts..
	if (false == OTAPI_Exec::Wallet_CanRemoveServer(SERVER_ID))
		return false;

	// TODO: the above call proves that there are no accounts laying around
	// for this server ID. (No need to worry about "orphaned accounts.")
	//
	// However, there may still be Nyms registered at the server! Therefore,
	// we need to loop through the Nyms, and make sure none of them has been
	// registered at this server ID. If it has, then we need to message the server
	// to "deregister" the Nym, which is much cleaner.  Otherwise server's only
	// other alternative is to expire Nyms that have gone unused for some specific
	// period of time, presumably those terms are described in the server contract.
	//
	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI()->GetWallet(__FUNCTION__);

	if (NULL == pWallet) {
		OTLog::vError("%s:  No wallet found...\n",__FUNCTION__);
		OT_FAIL;
	}

	OTIdentifier theID(SERVER_ID);

	if (pWallet->RemoveServerContract(theID))
	{
		pWallet->SaveWallet();
		OTLog::vOutput(0, "%s: Removed server contract from the wallet: %s\n", __FUNCTION__, SERVER_ID.c_str());
		return true;
	}
	return false;
}



// Can I remove this asset contract from my wallet?
//
// You cannot remove the asset contract from your wallet if there are accounts in there using it.
// This function tells you whether you can remove the asset contract or not. (Whether there are accounts...)
// returns bool
//
bool	OTAPI_Exec::Wallet_CanRemoveAssetType(const std::string & ASSET_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }

	if (ASSET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_FAIL; }
	// -----------------------------------------------------

	OTIdentifier theID(ASSET_ID);
	// ------------------------------------------
	const int32_t & nCount = OTAPI_Exec::GetAccountCount();

	// Loop through all the accounts.
	for (int32_t i = 0; i < nCount; i++)
	{
		std::string pAcctID = OTAPI_Exec::GetAccountWallet_ID(i);
		OTString strAcctID(pAcctID);

		std::string pID = OTAPI_Exec::GetAccountWallet_AssetTypeID(strAcctID.Get());
		OTIdentifier theCompareID(pID);

		if (theID == theCompareID)
		{
			OTLog::vOutput(0, "%s: Unable to remove asset contract %s from wallet: Account %s uses it.\n", __FUNCTION__,
				ASSET_ID.c_str(), strAcctID.Get());
			return false;
		}
	}
	return true;
}




// Remove this asset contract from my wallet!
//
// Try to remove the asset contract from the wallet.
// This will not work if there are any accounts in the wallet for the same asset type ID.
// returns bool
//
bool	OTAPI_Exec::Wallet_RemoveAssetType(const std::string & ASSET_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }

	if (ASSET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_FAIL; }
	// -----------------------------------------------------

	// Make sure there aren't any dependent accounts..
	if (false == OTAPI_Exec::Wallet_CanRemoveAssetType(ASSET_ID))
		return false;

	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI()->GetWallet(__FUNCTION__);

	if (NULL == pWallet) {
		OTLog::vError("%s: No wallet found...!\n",__FUNCTION__);
		OT_FAIL;
	}

	OTIdentifier theID(ASSET_ID);

	if (pWallet->RemoveAssetContract(theID))
	{
		pWallet->SaveWallet();
		OTLog::vOutput(0, "%s: Removed asset contract from the wallet: %s\n",__FUNCTION__, ASSET_ID.c_str());
		return true;
	}
	return false;
}




// Can I remove this Nym from my wallet?
//
// You cannot remove the Nym from your wallet if there are accounts in there using it.
// This function tells you whether you can remove the Nym or not. (Whether there are accounts...)
// It also checks to see if the Nym in question is registered at any servers.
//
// returns bool
//
bool OTAPI_Exec::Wallet_CanRemoveNym(const std::string & NYM_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }

	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }
	// -----------------------------------------------------

	OTIdentifier theID(NYM_ID);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetNym(theID, __FUNCTION__);
	if (NULL == pNym) return false;
	// ------------------------------------------
	// Make sure the Nym doesn't have any accounts in the wallet.
	// (Client must close those before calling this.)
	//
	const int32_t & nCount = OTAPI_Exec::GetAccountCount();

	// Loop through all the accounts.
	for (int32_t i = 0; i < nCount; i++)
	{
		std::string pAcctID = OTAPI_Exec::GetAccountWallet_ID(i);
		OTString strAcctID(pAcctID);

		std::string pID = OTAPI_Exec::GetAccountWallet_NymID(strAcctID.Get());

		if (pID.empty())
		{
			OTLog::vError("%s: Bug in OTAPI_Exec::Wallet_CanRemoveNym / OTAPI_Exec::GetAccountWallet_NymID\n", __FUNCTION__);
			return false;
		}

		OTIdentifier theCompareID(pID);

		// Looks like the Nym still has some accounts in this wallet.
		if (theID == theCompareID)
		{
			OTLog::vOutput(0, "%s: Nym cannot be removed because there are still accounts in the wallet for that Nym.\n", __FUNCTION__);
			return false;
		}
	}

	// ------------------------------------------
	// Make sure the Nym isn't registered at any servers...
	// (Client must unregister at those servers before calling this function..)
	//
	const int32_t & nServerCount = OTAPI_Exec::GetServerCount();

	for (int32_t i = 0; i < nServerCount; i++)
	{
		std::string str_ServerID = OTAPI_Exec::GetServer_ID(i);

		if ("" != str_ServerID)
		{
			const OTString strServerID(str_ServerID);

			if (pNym->IsRegisteredAtServer(strServerID))
			{
				OTLog::vOutput(0, "%s: Nym cannot be removed because there are still servers in the wallet that the Nym is registered at.\n", __FUNCTION__);
				return false;
			}
		}
	}

	// ------------------------------------------

	// TODO:  Make sure Nym doesn't have any cash in any purses...

	return true;
}

// Remove this Nym from my wallet!
//
// Try to remove the Nym from the wallet.
// This will fail if the Nym is registered at any servers, or has any accounts.
//
// returns bool
//
bool	OTAPI_Exec::Wallet_RemoveNym(const std::string & NYM_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }

	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }
	// -----------------------------------------------------

	// ------------------------------------------
	// DONE: The below call proves already that there are no accounts laying around
	// for this Nym. (No need to worry about "orphaned accounts.")
	//
	// DONE (finally):
	// However, the Nym might still be registered at various servers, even without asset accounts.
	// Therefore, we need to iterate through the server contracts, and if the Nym is registered at
	// any of the servers, then "deregister" (before deleting the Nym entirely.) This is much
	// cleaner for the server side, who otherwise has to expired unused nyms based on some rule
	// presumably to be found in the server contract.
	// ------------------------------------------
	if (false == OTAPI_Exec::Wallet_CanRemoveNym(NYM_ID))
		return false;

	// -----------------------------------------------------
	OTWallet * pWallet = OTAPI()->GetWallet(__FUNCTION__);

	if (NULL == pWallet) {
		OTLog::vError("%s: No wallet found...!\n",__FUNCTION__);
		OT_FAIL;
	}

	OTIdentifier theID(NYM_ID);

	if (pWallet->RemoveNym(theID))
	{
		OTLog::vOutput(0, "%s: Success erasing Nym from wallet: %s\n", __FUNCTION__, NYM_ID.c_str());
		pWallet->SaveWallet();
		return true;
	}
	else
		OTLog::vOutput(0, "%s: Failure erasing Nym from wallet: %s\n", __FUNCTION__, NYM_ID.c_str());

	return false;
}




// Can I remove this Account from my wallet?
//
// You cannot remove the Account from your wallet if there are transactions still open.
// This function tells you whether you can remove the Account or not. (Whether there are transactions...)
// Also, balance must be zero to do this.
//
// returns bool
//
bool	OTAPI_Exec::Wallet_CanRemoveAccount(const std::string & ACCOUNT_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }

	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	// -----------------------------------------------------

	// -----------------------------------------------------------------
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// -----------------------------------------------------
	OTAccount * pAccount = OTAPI()->GetAccount(theAccountID, __FUNCTION__);
	if (NULL == pAccount) return false;
	// -----------------------------------------------------
	// Balance must be zero in order to close an account!
	else if (pAccount->GetBalance() != 0)
	{
		OTLog::vOutput(0, "%s: Account balance MUST be zero in order to close an asset account: %s.\n", __FUNCTION__, ACCOUNT_ID.c_str());
		return false;
	}
	// -----------------------------------------------------------------
	bool BOOL_RETURN_VALUE = false;

	const OTIdentifier & theServerID	= pAccount->GetPurportedServerID();
	const OTIdentifier & theUserID		= pAccount->GetUserID();

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pInbox   = OTAPI()->LoadInbox(theServerID, theUserID, theAccountID);
	OTLedger * pOutbox  = OTAPI()->LoadOutbox(theServerID, theUserID, theAccountID);

	// Make sure it gets cleaned up pInbox this goes out of scope.
	OTCleanup<OTLedger>	theInboxAngel(pInbox); // I pass the pointer, in case it's "".
	OTCleanup<OTLedger>	theOutboxAngel(pOutbox); // I pass the pointer, in case it's "".

	if (NULL == pInbox){
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadInbox.\n Account ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else if (NULL == pOutbox) {
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadOutbox.\n Account ID: %s\n",__FUNCTION__ , ACCOUNT_ID.c_str());
	}
	else if ( (pInbox->GetTransactionCount() > 0) || (pOutbox->GetTransactionCount() > 0) ) {
		OTLog::vOutput(0, "%s: Failure: You cannot remove an asset account if there are inbox/outbox items still waiting to be processed.\n", __FUNCTION__);
	}
	else BOOL_RETURN_VALUE = true; // SUCCESS!

	return BOOL_RETURN_VALUE;
}



// So the client side knows which ones he has in storage, vs which ones he
// still needs to download.
//
bool OTAPI_Exec::DoesBoxReceiptExist(const std::string & SERVER_ID,
                                     const std::string & USER_ID,	// Unused here for now, but still convention.
                                     const std::string & ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
                                     const int32_t &	nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
                                     const int64_t & TRANSACTION_NUMBER)
{

	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }
	// --------------------------------------
	if ( ! ( (0 == nBoxType)	|| (1 == nBoxType) || (2 == nBoxType) ) ){
		OTLog::vError("%s: nBoxType is of wrong type: value: %d\n", __FUNCTION__, nBoxType);
		OT_FAIL;
	}
	// --------------------------------------
	if (0 > TRANSACTION_NUMBER) { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_FAIL; }
	// --------------------------------------
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	const int64_t		lTransactionNum = TRANSACTION_NUMBER;
	// --------------------------------------
	switch (nBoxType)
	{
	case 0:		// nymbox
	case 1:		// inbox
	case 2:		// outbox
		break;
	default:
		OTLog::vError("%s: Error: bad nBoxType: %d for UserID: %s AcctID: %s (expected one of: 0/nymbox, 1/inbox, 2/outbox)\n",
			__FUNCTION__, nBoxType, USER_ID.c_str(), ACCOUNT_ID.c_str());
		return false;
	}
	// --------------------------------------
	return OTAPI()->DoesBoxReceiptExist(theServerID,
		theUserID,
		theAccountID,   // If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
		nBoxType,       // 0/nymbox, 1/inbox, 2/outbox
		static_cast<int64_t>(lTransactionNum));
}




// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getBoxReceipt(const std::string & SERVER_ID,
						 const std::string & USER_ID,
						 const std::string & ACCOUNT_ID,		// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
						 const int32_t & nBoxType,		// 0/nymbox, 1/inbox, 2/outbox
						 const int64_t & TRANSACTION_NUMBER)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }
	// --------------------------------------
	if ( ! ( (0 == nBoxType)	|| (1 == nBoxType) || (2 == nBoxType) ) )
    {
		OTLog::vError("%s: nBoxType is of wrong type: value: %d\n", __FUNCTION__, nBoxType);
		OT_FAIL;
	}
	// --------------------------------------
	if (0 > TRANSACTION_NUMBER) { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_FAIL; }
	// --------------------------------------
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	const int64_t			lTransactionNum = TRANSACTION_NUMBER;
	// --------------------------------------
	switch (nBoxType)
	{
	case 0:		// nymbox
	case 1:		// inbox
	case 2:		// outbox
		break;
	default:
		OTLog::vError("%s: Error: bad nBoxType: %d for UserID: %s AcctID: %s"
			"(expected one of: 0/nymbox, 1/inbox, 2/outbox)\n", __FUNCTION__,
                      nBoxType, USER_ID.c_str(), ACCOUNT_ID.c_str());
		return -1;
	}

	return OTAPI()->getBoxReceipt(theServerID,
		theUserID,
		theAccountID, // If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
		nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
		static_cast<int64_t>(lTransactionNum));
}




// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::deleteAssetAccount(const std::string & SERVER_ID,
							 const std::string & USER_ID,
							 const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }

	if (false == OTAPI_Exec::Wallet_CanRemoveAccount(ACCOUNT_ID))
		return 0;

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	return OTAPI()->deleteAssetAccount(theServerID, theUserID, theAccountID);
}





// --------------------------------------------



// OT has the capability to export a Nym (normally stored in several files) as an encoded
// object (in base64-encoded form) and then import it again.
// Returns: Exported Nym in String Form.
//
std::string OTAPI_Exec::Wallet_ExportNym(const std::string & NYM_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

	if (NYM_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			); OT_FAIL; }

	const OTIdentifier theNymID(NYM_ID);

	// Create a StringMap object with these values:
	//
	// id:      The NymID.
	// name:    The display name from the wallet.
	// cert:    The public / private certfile in openssl format.
	// nymfile: The contents of the nymfile.
	//
	// Make sure to use master key when accessing them, but then put that on
	// pause while saving them to string. (Then unpause again.)
	//
	// Then Encode the StringMap into packed string form, and return it
	// from this function (or "".)
	//
	OTString strOutput;

	const bool & bExported = OTAPI()->Wallet_ExportNym(theNymID, strOutput);

	if (bExported)
	{
		std::string pBuf = strOutput.Get();

		return pBuf;
	}

	return "";
}

std::string OTAPI_Exec::Wallet_ExportCert(const std::string & NYM_ID)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

	if (NYM_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			); OT_FAIL; }

	const OTIdentifier theNymID(NYM_ID);

	OTString strOutput;

	const bool & bExported = OTAPI()->Wallet_ExportCert(theNymID, strOutput);

	if (bExported)
	{
		std::string pBuf = strOutput.Get();

        return pBuf;
	}

	return "";
}



// OT has the capability to export a Nym (normally stored in several files) as an encoded
// object (in base64-encoded form) and then import it again.
//
// Returns: Nym ID of newly-imported Nym (or "".)
//
std::string OTAPI_Exec::Wallet_ImportNym(const std::string & FILE_CONTENTS)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

	if (FILE_CONTENTS.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "FILE_CONTENTS"		); OT_FAIL; }
	// -----------------------------------------------------

	// Pause the master key, since this Nym is coming from outside
	// the wallet.
	//
	const OTString strFileContents(FILE_CONTENTS);

	OTIdentifier theNymID;

	const bool & bImported = OTAPI()->Wallet_ImportNym(strFileContents, &theNymID);

	// Decode the FILE_CONTENTS into a StringMap object,
	// and if success, make sure it contains these values:
	//
	// id:      The NymID.
	// name:    The display name from the wallet.
	// cert:    The public / private certfile in openssl format.
	// nymfile: The contents of the nymfile.
	//
	// Unpause the master key.
	//
	// Do various verifications on the values to make sure there's no funny business.
	//
	// Make sure the Nym with this ID isn't ALREADY in the wallet. If not, then add it.
	//
	//
	//

	if (bImported)
	{
		const OTString strNymID(theNymID);

		std::string pBuf = strNymID.Get();



		return pBuf;
	}

	return "";
}



// In this case, instead of importing a special "OT Nym all-in-one exported" file format,
// we are importing the public/private keys only, from their Cert file contents, and then
// creating a blank Nymfile to go aint64_t with it. This is for when people wish to import
// pre-existing keys to create a new Nym.
//
// Returns: Nym ID of newly-imported Nym (or "".)
//
std::string OTAPI_Exec::Wallet_ImportCert(const std::string & DISPLAY_NAME, const std::string & FILE_CONTENTS)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

//	if (DISPLAY_NAME.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "DISPLAY_NAME"		); OT_FAIL; }
	if (FILE_CONTENTS.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "FILE_CONTENTS"		); OT_FAIL; }

	const OTString strDisplayName (DISPLAY_NAME),
                   strFileContents(FILE_CONTENTS);

	OTIdentifier theNymID;

	const bool & bImported = OTAPI()->Wallet_ImportCert(strDisplayName, strFileContents, &theNymID);

	if (bImported)
	{
		const OTString strNymID(theNymID);

		std::string pBuf = strNymID.Get();

		return pBuf;
	}

	return "";
}





/*
CHANGE MASTER KEY and PASSWORD.

Normally your passphrase is used to derive a key, which is used to unlock
a random number (a symmetric key), which is used as the passphrase to open the
master key, which is used as the passphrase to any given Nym.

Since all the Nyms are encrypted to the master key, and since we can change the
passphrase on the master key without changing the master key itself, then we don't
have to do anything to update all the Nyms, since that part hasn't changed.

But we might want a separate "Change Master Key" function that replaces that key
itself, in which case we'd HAVE to load up all the Nyms and re-save them.

UPDATE: Seems the easiest thing to do is to just change both the key and passphase
at the same time here, by loading up all the private nyms, destroying the master key,
and then saving all the private Nyms. (With master key never actually being "paused.")
This will automatically cause it to generate a new master key during the saving process.
(Make sure to save the wallet also.)
*/
bool OTAPI_Exec::Wallet_ChangePassphrase()
{
	return OTAPI()->Wallet_ChangePassphrase();
}


//bool OTPseudonym::Savex509CertAndPrivateKeyToString(OTString & strOutput, OTString * pstrReason/*=""*/)

//bool OTPseudonym::Savex509CertAndPrivateKey(bool       bCreateFile/*=true*/,
//                                            OTString * pstrReason/*=""*/)

// ------------------------------------------------------------------------------------------------




// Attempts to find a full ID in the wallet, based on a partial of the same ID.
// Returns "" on failure, otherwise returns the full ID.
//
std::string OTAPI_Exec::Wallet_GetNymIDFromPartial(const std::string & PARTIAL_ID)
{
//  OTPseudonym *	GetNym(const OTIdentifier & NYM_ID, const std::string & strFuncName="");
//  OTPseudonym *	GetNymByIDPartialMatch(const std::string &PARTIAL_ID, const std::string & strFuncName="");
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized)    { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n" ,__FUNCTION__); OT_FAIL; }
	if (PARTIAL_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"        ); OT_FAIL; }
	// -----------------------------------------------------
	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID.
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTPseudonym * pObject = OTAPI()->GetNym(thePartialID, "OTAPI_Exec::Wallet_GetNymIDFromPartial");

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);
		std::string pBuf = strID_Output.Get();

		return pBuf;
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI()->GetNymByIDPartialMatch(PARTIAL_ID, "OTAPI_Exec::Wallet_GetNymIDFromPartial");

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);
		std::string pBuf = strID_Output.Get();
		return pBuf;
	}

	return "";
}

// Attempts to find a full ID in the wallet, based on a partial of the same ID.
// Returns "" on failure, otherwise returns the full ID.
//
std::string OTAPI_Exec::Wallet_GetServerIDFromPartial(const std::string & PARTIAL_ID)
{
//    OTServerContract *	GetServer(const OTIdentifier & THE_ID, const std::string & strFuncName="");
//    OTServerContract *	GetServerContractPartialMatch(const std::string &PARTIAL_ID, const std::string & strFuncName="");
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_FAIL; }

	if (PARTIAL_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_FAIL; }
	// -----------------------------------------------------
	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID.
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTServerContract * pObject = OTAPI()->GetServer(thePartialID, "OTAPI_Exec::Wallet_GetServerIDFromPartial");

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);
		std::string pBuf = strID_Output.Get();

		return pBuf;
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI()->GetServerContractPartialMatch(PARTIAL_ID, "OTAPI_Exec::Wallet_GetServerIDFromPartial");

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);
		std::string pBuf = strID_Output.Get();

		return pBuf;
	}

	return "";
}

// Attempts to find a full ID in the wallet, based on a partial of the same ID.
// Returns "" on failure, otherwise returns the full ID.
//
std::string OTAPI_Exec::Wallet_GetAssetIDFromPartial(const std::string & PARTIAL_ID)
{
	//    OTAssetContract *	GetAssetType(const OTIdentifier & THE_ID, const std::string & strFuncName="");
	//    OTAssetContract *	GetAssetContractPartialMatch(const std::string &PARTIAL_ID, const std::string & strFuncName="");

	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_FAIL; }

	if (PARTIAL_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_FAIL; }
	// -----------------------------------------------------

	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID.
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTAssetContract * pObject = OTAPI()->GetAssetType(thePartialID, "OTAPI_Exec::Wallet_GetAssetIDFromPartial");

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);
		std::string pBuf = strID_Output.Get();

		return pBuf;
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI()->GetAssetContractPartialMatch(PARTIAL_ID, "OTAPI_Exec::Wallet_GetAssetIDFromPartial");

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);
		std::string pBuf = strID_Output.Get();

		return pBuf;
	}

	return "";
}

std::string OTAPI_Exec::Wallet_GetAccountIDFromPartial(const std::string & PARTIAL_ID)
{
	//    OTAccount *   GetAccount(const OTIdentifier & THE_ID, const std::string & strFuncName="");
	//    OTAccount *   GetAccountPartialMatch(const std::string &PARTIAL_ID, const std::string & strFuncName="");

	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_FAIL; }

	if (PARTIAL_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_FAIL; }
	// -----------------------------------------------------

	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID.
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTAccount * pObject = OTAPI()->GetAccount(thePartialID, "OTAPI_Exec::Wallet_GetNymIDFromPartial");

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);
		std::string pBuf = strID_Output.Get();

		return pBuf;
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI()->GetAccountPartialMatch(PARTIAL_ID, "OTAPI_Exec::Wallet_GetNymIDFromPartial");

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);
		std::string pBuf = strID_Output.Get();

		return pBuf;
	}

	return "";
}


// ----------------------------------------------------------------

/// based on Index this returns the Nym's ID
std::string OTAPI_Exec::GetNym_ID(const int32_t & nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	OTIdentifier	theNymID;
	OTString		strName;

	bool bGetNym = OTAPI()->GetNym(nIndex, theNymID, strName);

	if (bGetNym)
	{
		OTString strNymID(theNymID);

		std::string pBuf = strNymID.Get();



		return pBuf;
	}

	return "";
}

/// Returns Nym Name (based on NymID)
std::string OTAPI_Exec::GetNym_Name(const std::string & NYM_ID)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null NYM_ID passed in!\n" ,__FUNCTION__); OT_FAIL; }
    // ---------------------------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym   * pNym = OTAPI()->GetNym(theNymID);

	if (NULL != pNym)
	{
		OTString & strName = pNym->GetNymName();
		std::string pBuf = strName.Get();

		return pBuf;
	}
    // ---------------------------------------------
	return "";
}



bool OTAPI_Exec::IsNym_RegisteredAtServer(const std::string & NYM_ID, const std::string & SERVER_ID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }

	const OTIdentifier	theNymID(NYM_ID),
		theServerID(SERVER_ID);

	bool bSuccess = OTAPI()->IsNym_RegisteredAtServer(theNymID, theServerID);

	return (bSuccess) ? true : false;
}


//--------------------------------------------------------



// Returns Nym data (based on NymID)
//
std::string OTAPI_Exec::GetNym_Stats(const std::string & NYM_ID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTString strOutput;

		pNym->DisplayStatistics(strOutput);

		std::string pBuf = strOutput.Get();



		return pBuf;
	}

	return "";
}


// Returns NymboxHash (based on ServerID)
//
std::string OTAPI_Exec::GetNym_NymboxHash(const std::string & SERVER_ID, const std::string & NYM_ID) // Returns NymboxHash (based on ServerID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTIdentifier    theNymboxHash;
		const
			std::string     str_server_id(SERVER_ID);
		const bool &      bGothash = pNym->GetNymboxHash(str_server_id, theNymboxHash); // (theNymboxHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't passconst std::string & in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::vOutput(1, "%s: NymboxHash not found, on client side, "
				"for server %s and nym %s. (Returning "".)\n",
				__FUNCTION__, str_server_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theNymboxHash);

			std::string pBuf = strOutput.Get();



			return pBuf;
		}
	}

	return "";
}

//--------------------------------------------------------

// Returns RecentHash (based on ServerID)
//
std::string OTAPI_Exec::GetNym_RecentHash(const std::string & SERVER_ID, const std::string & NYM_ID) // Returns RecentHash (based on ServerID)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTIdentifier    theHash;
		const
			std::string     str_server_id(SERVER_ID);
		const bool &      bGothash = pNym->GetRecentHash(str_server_id, theHash); // (theHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't passconst std::string & in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::vOutput(1, "%s: RecentHash not found, on client side, "
				"for server %s and nym %s. (Returning "".)\n",
				__FUNCTION__, str_server_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theHash);

			std::string pBuf = strOutput.Get();



			return pBuf;
		}
	}

	return "";
}



std::string OTAPI_Exec::GetNym_InboxHash(const std::string & ACCOUNT_ID, const std::string & NYM_ID) // InboxHash for "most recently DOWNLOADED" Inbox (by AccountID)
{
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTIdentifier    theHash;
		const
			std::string     str_acct_id(ACCOUNT_ID);
		const bool &      bGothash = pNym->GetInboxHash(str_acct_id, theHash); // (theHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't passconst std::string & in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::vOutput(1, "%s: InboxHash not found, on client side, "
				"for account %s and nym %s. (Returning "".)\n",
				__FUNCTION__, str_acct_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theHash);

			std::string pBuf = strOutput.Get();


			return pBuf;
		}
	}

	return "";
}

std::string OTAPI_Exec::GetNym_OutboxHash(const std::string & ACCOUNT_ID, const std::string & NYM_ID) // OutboxHash for "most recently DOWNLOADED" Outbox (by AccountID)
{
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
	{
		OTIdentifier    theHash;
		const
			std::string     str_acct_id(ACCOUNT_ID);
		const bool &      bGothash = pNym->GetOutboxHash(str_acct_id, theHash); // (theHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't passconst std::string & in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::vOutput(1, "%s: OutboxHash not found, on client side, "
				"for account %s and nym %s. (Returning "".)\n",
				__FUNCTION__, str_acct_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theHash);

			std::string pBuf = strOutput.Get();



			return pBuf;
		}
	}

	return "";
}


//--------------------------------------------------------



int32_t	OTAPI_Exec::GetNym_MailCount(const std::string & NYM_ID)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID" ); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return 0;
	// -------------------------
	return pNym->GetMailCount();
}


// returns the message, optionally with Subject: as first line.
std::string OTAPI_Exec::GetNym_MailContentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"  ); OT_FAIL; }
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
		//
		OTEnvelope	theEnvelope;
		OTString	strEnvelopeContents;

		// Decrypt the Envelope.
		if (theEnvelope.SetAsciiArmoredData(pMessage->m_ascPayload) &&
			theEnvelope.Open(*pNym, strEnvelopeContents))
		{
			std::string pBuf = strEnvelopeContents.Get();
			return pBuf;
		}
	}
	return "";
}



// returns the sender ID for a piece of mail. (NymID).
//
std::string OTAPI_Exec::GetNym_MailSenderIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"  ); OT_FAIL; }
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)

		std::string pBuf = pMessage->m_strNymID.Get();
		return pBuf;
	}
	return "";
}



// returns the server ID that a piece of mail came from.
//
std::string OTAPI_Exec::GetNym_MailServerIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)

		std::string pBuf = pMessage->m_strServerID.Get();
		return pBuf;
	}
	return "";
}



// --------------------------------------------------------


bool OTAPI_Exec::Nym_RemoveMailByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				 ); OT_FAIL; }
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------
	OTPseudonym * pSignerNym = pNym;

	if (pNym->RemoveMailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return true;
		else
			OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID.c_str());
	}
	return false;
}



// Returns true (1) if the Sender ID on this piece of Mail (by index)
// loads a public key from my wallet, and if the signature on the message
// verifies with that public key.
// (Not only must the signature be good, but I must have added the nym to
// my wallet sometime in the past, since this func returns false if it's not there.)
//
// A good wallet might be designed to automatically download any keys that
// it doesn't already have, using OTAPI_Exec::checkUser(). I'll probably need to
// add something to OTClient where the @checkUser response auto-saves the new
// key into the wallet. That way you can wait for a tenth of a second and then
// just read the Nym (by ID) straight out of your own wallet. Nifty, eh?
//
// All the wallet has to do is fire off a "check user" whenever this call fails,
// then come back when that succeeds and try this again. If STILL failure, then
// you've got a signature problem. Otherwise it'll usually download the nym
// and verify the signature all in an instant, without the user even noticing
// what happened.
//
bool OTAPI_Exec::Nym_VerifyMailByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				 ); OT_FAIL; }
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------
	OTMessage * pMessage = pNym->GetMailByIndex(nIndex);

	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);

		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym * pSenderNym = OTAPI()->GetNym(theSenderNymID, __FUNCTION__);

		// If it's there, use it to verify the signature on the message.
		// return true if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return true;
		}
	}
	return false;
}


// --------------------------------------------------------------------------
//
// OUTMAIL!!

int32_t	OTAPI_Exec::GetNym_OutmailCount(const std::string & NYM_ID)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID" ); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return 0;
	// -------------------------
	return pNym->GetOutmailCount();
}


// returns the message, optionally with Subject: as first line.
std::string OTAPI_Exec::GetNym_OutmailContentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				 ); OT_FAIL; }
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
		OTString	strMailContents;

		if (pMessage->m_ascPayload.Exists() &&
			pMessage->m_ascPayload.GetString(strMailContents))
		{
			std::string pBuf = strMailContents.Get();
			return pBuf;
		}
	}
	return "";
}



// returns the recipient ID for a piece of mail. (NymID).
//
std::string OTAPI_Exec::GetNym_OutmailRecipientIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"                  ); OT_FAIL; }
	if (0 > nIndex)     { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload

		std::string pBuf = pMessage->m_strNymID2.Get();
		return pBuf;
	}
	return "";
}



// returns the server ID that a piece of mail came from.
//
std::string OTAPI_Exec::GetNym_OutmailServerIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				     ); OT_FAIL; }
	if (0 > nIndex)     { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload

		std::string pBuf = pMessage->m_strServerID.Get();
		return pBuf;

	}
	return "";
}



// --------------------------------------------------------


bool OTAPI_Exec::Nym_RemoveOutmailByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"  ); OT_FAIL; }
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------
	OTPseudonym * pSignerNym = pNym;

	if (pNym->RemoveOutmailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return true;
		else
			OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID.c_str());
	}
	return false;
}



// Returns true (1) if the Sender ID on this piece of Mail (by index)
// loads a public key from my wallet, and if the signature on the message
// verifies with that public key.
// (Not only must the signature be good, but I must have added the nym to
// my wallet sometime in the past, since this func returns false if it's not there.)
//
// A good wallet might be designed to automatically download any keys that
// it doesn't already have, using OTAPI_Exec::checkUser(). I'll probably need to
// add something to OTClient where the @checkUser response auto-saves the new
// key into the wallet. That way you can wait for a tenth of a second and then
// just read the Nym (by ID) straight out of your own wallet. Nifty, eh?
//
// All the wallet has to do is fire off a "check user" whenever this call fails,
// then come back when that succeeds and try this again. If STILL failure, then
// you've got a signature problem. Otherwise it'll usually download the nym
// and verify the signature all in an instant, without the user even noticing
// what happened.
//
bool OTAPI_Exec::Nym_VerifyOutmailByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"              ); OT_FAIL; }
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------
	OTMessage * pMessage = pNym->GetOutmailByIndex(nIndex);
	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);

		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym * pSenderNym = OTAPI()->GetNym(theSenderNymID, __FUNCTION__);

		// If it's there, use it to verify the signature on the message.
		// return true if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return true;
		}
	}
	return false;
}



// --------------------------------------------------------------------------
//
// OUTPAYMENTS!!
//
// (Outbox on payments screen.)
//
// Todo: Move these and all functions to OpenTransactions.cpp.  This should ONLY
// be a wrapper for that class.  That way we can eventually phase this file out
// entirely and replace it with OTAPI_Wrapper.cpp directly on OpenTransactions.cpp

int32_t	OTAPI_Exec::GetNym_OutpaymentsCount(const std::string & NYM_ID)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID" ); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return 0;
	// -------------------------
	return pNym->GetOutpaymentsCount();
}


// Returns the payment instrument that was sent.
//
std::string OTAPI_Exec::GetNym_OutpaymentsContentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID" );                  OT_FAIL; }
	if (0 > nIndex)     { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:     pMessage->m_strNymID
		// RECIPIENT:  pMessage->m_strNymID2
		// INSTRUMENT: pMessage->m_ascPayload (in an OTEnvelope)
		OTString	strPayment;

		// There isn't any encrypted envelope this time, since it's my outPayments box.
		//
		if (pMessage->m_ascPayload.Exists() &&
			pMessage->m_ascPayload.GetString(strPayment) &&
			strPayment.Exists())
		{
			OTPayment thePayment(strPayment);
			// ---------------------------------------------
			if (thePayment.IsValid())
			{
				std::string pBuf = strPayment.Get();
				return pBuf;
			}
		}
	}
	return "";
}



// returns the recipient ID for a piece of payments outmail. (NymID).
//
std::string OTAPI_Exec::GetNym_OutpaymentsRecipientIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID" );              OT_FAIL; }
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload

		std::string pBuf = pMessage->m_strNymID2.Get();
		return pBuf;
	}
	return "";
}



// returns the server ID that a piece of payments outmail came from.
//
std::string OTAPI_Exec::GetNym_OutpaymentsServerIDByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID" );                  OT_FAIL; }
	if (0 > nIndex)     { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier  theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload

		int32_t bServerIdLength = pMessage->m_strServerID.GetLength();
		if (1 >= bServerIdLength)
        {
			OTLog::vError("%s: m_strServerID Length is 1 or less!\n", __FUNCTION__);
			OT_FAIL;
		}

		std::string pBuf = pMessage->m_strServerID.Get();
		return pBuf;
	}
	return "";
}



// --------------------------------------------------------


bool OTAPI_Exec::Nym_RemoveOutpaymentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				     ); OT_FAIL; }
	if (0 > nIndex)     { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------
	OTPseudonym * pSignerNym = pNym;

	if (pNym->RemoveOutpaymentsByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a payment outmail was erased.
			return true;
		else
			OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID.c_str());
	}
	return false;
}



// Returns true (1) if the Sender ID on this piece of Mail (by index)
// loads a public key from my wallet, and if the signature on the message
// verifies with that public key.
// (Not only must the signature be good, but I must have added the nym to
// my wallet sometime in the past, since this func returns false if it's not there.)
//
// A good wallet might be designed to automatically download any keys that
// it doesn't already have, using OTAPI_Exec::checkUser(). I'll probably need to
// add something to OTClient where the @checkUser response auto-saves the new
// key into the wallet. That way you can wait for a tenth of a second and then
// just read the Nym (by ID) straight out of your own wallet. Nifty, eh?
//
// All the wallet has to do is fire off a "check user" whenever this call fails,
// then come back when that succeeds and try this again. If STILL failure, then
// you've got a signature problem. Otherwise it'll usually download the nym
// and verify the signature all in an instant, without the user even noticing
// what happened.
//
bool OTAPI_Exec::Nym_VerifyOutpaymentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
	if (NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID" ); OT_FAIL; }
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }
	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);
	if (NULL == pNym) return false;
	// -------------------------
	OTMessage * pMessage = pNym->GetOutpaymentsByIndex(nIndex);
	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);

		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym * pSenderNym = OTAPI()->GetNym(theSenderNymID, __FUNCTION__);

		// If it's there, use it to verify the signature on the message.
		// return true if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return true;
		}
	}
	return false;
}





// ******************************************************************************





//
//
// THESE FUNCTIONS were added for the PAYMENTS screen. (They are fairly new.)
//
// Basically there was a need to have DIFFERENT instruments, but to be able to
// treat them as though they are a single type.
//
// In keeping with that, the below functions will work with disparate types.
// You can pass [ CHEQUES / VOUCHERS / INVOICES ] and PAYMENT PLANS, and
// SMART CONTRACTS, and PURSEs into these functions, and they should be able
// to handle any of those types.
//
//

int64_t OTAPI_Exec::Instrmnt_GetAmount(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString      strOutput;
	int64_t          lOutput  = 0;
	const bool &  bGotData = thePayment.GetAmount(lOutput); // <========

	return bGotData ? lOutput : -1;
}



int64_t OTAPI_Exec::Instrmnt_GetTransNum(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)
	OTString      strOutput;
	int64_t          lOutput = 0;
	const bool &  bGotData = thePayment.GetTransactionNum(lOutput); // <========

	return bGotData ? lOutput : -1;
}




time64_t OTAPI_Exec::Instrmnt_GetValidFrom(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
        return OTTimeGetTimeFromSeconds(-1);
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
        return OTTimeGetTimeFromSeconds(-1);
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString strOutput;
    time64_t tOutput = OT_TIME_ZERO;
	const bool &  bGotData = thePayment.GetValidFrom(tOutput); // <========

    return bGotData ? tOutput : OTTimeGetTimeFromSeconds(-1);
}




time64_t OTAPI_Exec::Instrmnt_GetValidTo(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
        return OTTimeGetTimeFromSeconds(-1);
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
        return OTTimeGetTimeFromSeconds(-1);
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
    time64_t      tOutput = OT_TIME_ZERO;
	const bool &  bGotData = thePayment.GetValidTo(tOutput); // <========

    return bGotData ? tOutput : OTTimeGetTimeFromSeconds(-1);
}




// ------------------------------------------------




std::string OTAPI_Exec::Instrmnt_GetType(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	const OTString strOutput(thePayment.GetTypeString());

	if (strOutput.Exists())
	{
		std::string pBuf = strOutput.Get();


		return pBuf;
	}

	return "";
}



// ------------------------------------------------




std::string OTAPI_Exec::Instrmnt_GetMemo(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	const bool &  bGotData = thePayment.GetMemo(strOutput); // <========

	if (bGotData)
	{
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}


// ------------------------------------------------



std::string OTAPI_Exec::Instrmnt_GetServerID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n", __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n", __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetServerID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




std::string OTAPI_Exec::Instrmnt_GetAssetID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n", __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n", __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetAssetTypeID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




std::string OTAPI_Exec::Instrmnt_GetRemitterUserID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetRemitterUserID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}





std::string OTAPI_Exec::Instrmnt_GetRemitterAcctID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetRemitterAcctID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




std::string OTAPI_Exec::Instrmnt_GetSenderUserID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetSenderUserID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}





std::string OTAPI_Exec::Instrmnt_GetSenderAcctID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &    bGotData = thePayment.GetSenderAcctID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}





std::string OTAPI_Exec::Instrmnt_GetRecipientUserID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &  bGotData = thePayment.GetRecipientUserID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}





std::string OTAPI_Exec::Instrmnt_GetRecipientAcctID(const std::string & THE_INSTRUMENT)
{
	if (THE_INSTRUMENT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT" ); OT_FAIL; }
	// ------------------------------------
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::vOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	const bool & bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::vOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool &  bGotData = thePayment.GetRecipientAcctID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}





// -----------------------------------------------------------------------------







// -----------------------------------
// SET NYM NAME
//
// You might have 40 of your friends' public nyms in
// your wallet. You might have labels on each of them.
// But whenever you change a label (and thus re-sign the
// file for that Nym when you save it), you only SIGN
// using one of your OWN nyms, for which you have a private
// key available for signing.
//
// When testing, there is only one nym, so you just pass it
// twice.  But in real production, a user will have a default
// signing nym, the same way that he might have a default
// signing key in PGP, and that must be passed in whenever
// he changes the name on any of the other nyms in his wallet.
// (In order to properly sign and save the change.)
//
// Returns true (1) or false (0)
//
bool OTAPI_Exec::SetNym_Name(const std::string & NYM_ID, const std::string & SIGNER_NYM_ID, const std::string & NYM_NEW_NAME)
{
	if (NYM_ID.empty())        { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"        ); OT_FAIL; }
	if (SIGNER_NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID" ); OT_FAIL; }
	if (NYM_NEW_NAME.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_NEW_NAME"  ); OT_FAIL; }

	const OTIdentifier	theNymID(NYM_ID),
                        theSignerNymID(SIGNER_NYM_ID);
	const OTString		strNymName(NYM_NEW_NAME);

	bool bSuccess = OTAPI()->SetNym_Name(theNymID, theSignerNymID, strNymName);

	return bSuccess;
}


// Merely a client-side label
bool OTAPI_Exec::SetServer_Name(const std::string & SERVER_ID,
							 const std::string & STR_NEW_NAME)
{
	if (SERVER_ID.empty())    { OTLog::vError("%s: Null SERVER_ID passed in!\n"    ,__FUNCTION__); OT_FAIL; }
	if (STR_NEW_NAME.empty()) { OTLog::vError("%s: Null STR_NEW_NAME passed in!\n" ,__FUNCTION__); OT_FAIL; }

	const OTIdentifier	theContractID(SERVER_ID);
	const OTString		strNewName(STR_NEW_NAME);

	bool bSuccess = OTAPI()->SetServer_Name(theContractID, strNewName);

	return bSuccess;
}



// Merely a client-side label
bool OTAPI_Exec::SetAssetType_Name(const std::string & ASSET_ID,
								const std::string & STR_NEW_NAME)
{
	if (ASSET_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"     ); OT_FAIL; }
	if (STR_NEW_NAME.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "STR_NEW_NAME" ); OT_FAIL; }

	const OTIdentifier	theContractID(ASSET_ID);
	const OTString		strNewName(STR_NEW_NAME);

	bool bSuccess = OTAPI()->SetAssetType_Name(theContractID, strNewName);

	return bSuccess;
}




//----------------------------------------------------------
// GET NYM TRANSACTION NUM COUNT
// How many transaction numbers does the Nym have (for a given server?)
//
// This function returns the count of numbers available. If 0, then no
// transactions will work until you call OTAPI_Exec::getTransactionNumber()
// to replenish your Nym's supply for that ServerID...
//
// Returns a count (0 through N numbers available),
// or -1 for error (no nym found.)
//
int32_t OTAPI_Exec::GetNym_TransactionNumCount(const std::string & SERVER_ID, const std::string & NYM_ID)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (NYM_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"    ); OT_FAIL; }

	OTIdentifier	theServerID(SERVER_ID);
	OTIdentifier	theNymID(NYM_ID);

	int32_t nReturnValue = 0;
	// -------------------------
	OTPseudonym * pNym = OTAPI()->GetNym(theNymID, __FUNCTION__);

	if (NULL != pNym)
		nReturnValue = pNym->GetTransactionNumCount(theServerID);
	else
		nReturnValue = -1;

	return nReturnValue;
}



// based on Index (above 4 functions) this returns the Server's ID
std::string OTAPI_Exec::GetServer_ID(const int32_t & nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	OTIdentifier	theID;
	OTString		strName;
	bool bGetServer = OTAPI()->GetServer(nIndex, theID, strName);

	if (bGetServer)
	{
		OTString strID(theID);

		std::string pBuf = strID.Get();



		return pBuf;
	}
	return "";
}


// Return's Server's name (based on server ID)
std::string OTAPI_Exec::GetServer_Name(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_FAIL; }
	OTIdentifier	theID(THE_ID);

	// -------------------------
	OTServerContract * pServer = OTAPI()->GetServer(theID, __FUNCTION__);
	if (NULL == pServer) return "";
	// -------------------------
	OTString strName;
	pServer->GetName(strName);
	std::string pBuf = strName.Get();

	return pBuf;
}

// returns Asset Type ID (based on index from GetAssetTypeCount)
std::string OTAPI_Exec::GetAssetType_ID(const int32_t & nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	OTIdentifier	theID;
	OTString		strName;

	bool bGetServer = OTAPI()->GetAssetType(nIndex, theID, strName);

	if (bGetServer)
	{
		OTString strID(theID);
		std::string pBuf = strID.Get();

		return pBuf;
	}
	return "";
}

// Returns asset type Name based on Asset Type ID
std::string OTAPI_Exec::GetAssetType_Name(const std::string & THE_ID)
{
	if (THE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID" ); OT_FAIL; }

	OTIdentifier	theID(THE_ID);
	// -------------------------
	OTAssetContract * pContract = OTAPI()->GetAssetType(theID, __FUNCTION__);
	if (NULL == pContract) return "";
	// -------------------------
	OTString strName;
	pContract->GetName(strName);
	std::string pBuf = strName.Get();

	return pBuf;
}

// Returns asset type TLA based on Asset Type ID
std::string OTAPI_Exec::GetAssetType_TLA(const std::string & THE_ID)
{
    if (THE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"); OT_FAIL; }

    OTIdentifier	theID(THE_ID);
    // -------------------------
    OTAssetContract * pContract = OTAPI()->GetAssetType(theID, __FUNCTION__);
    if (NULL == pContract) return "";
    // -------------------------
    OTString strTLA;
    strTLA = pContract->GetCurrencyTLA();
    std::string pBuf = strTLA.Get();

    return pBuf;
}


// -------------------------------------------------------------


// returns a string containing the account ID, based on index.
std::string OTAPI_Exec::GetAccountWallet_ID(const int32_t & nIndex)
{
	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	OTIdentifier	theID;
	OTString		strName;

	bool bGetServer = OTAPI()->GetAccount(nIndex, theID, strName);

	if (bGetServer)
	{
		OTString strID(theID);

		std::string pBuf = strID.Get();

		return pBuf;
	}
	return "";
}



// returns the account name, based on account ID.
std::string OTAPI_Exec::GetAccountWallet_Name(const std::string & THE_ID)
{
	if (THE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID" ); OT_FAIL; }

	OTIdentifier	theID(THE_ID);

	std::string strFunc = "OTAPI_Exec::GetAccountWallet_Name";
	// -------------------------
	OTAccount * pAccount = OTAPI()->GetAccount(theID, strFunc.c_str());
	if (NULL == pAccount) return "";
	// -------------------------
	OTString strName;
	pAccount->GetName(strName);
	std::string pBuf = strName.Get();

	return pBuf;
}


std::string OTAPI_Exec::GetAccountWallet_InboxHash (const std::string & ACCOUNT_ID)	 // returns latest InboxHash according to the account file. (Usually more recent than: OTAPI_Exec::GetNym_InboxHash)
{
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------

	OTIdentifier theOutput;
	const bool & bGotHash = pAccount->GetInboxHash(theOutput);

	OTString strOutput;

	if (bGotHash)
		theOutput.GetString(strOutput);

	std::string pBuf = strOutput.Get();

	return pBuf;
}



std::string OTAPI_Exec::GetAccountWallet_OutboxHash(const std::string & ACCOUNT_ID)	 // returns latest OutboxHash according to the account file. (Usually more recent than: OTAPI_Exec::GetNym_OutboxHash)
{
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------

	OTIdentifier theOutput;
	const bool & bGotHash = pAccount->GetOutboxHash(theOutput);

	OTString strOutput;

	if (bGotHash)
		theOutput.GetString(strOutput);

	std::string pBuf = strOutput.Get();

	return pBuf;
}



// --------------------------------------------------------------------
/** TIME (in seconds, as string)

This will return the current time in seconds, as a string.
Returns "" if failure.

Todo:  consider making this available on the server side as well,
so the smart contracts can see what time it is.

*/
time64_t OTAPI_Exec::GetTime(void)
{
    return OTAPI()->GetTime();
}





// --------------------------------------------------------------------
/** OT-encode a plaintext string.  (NOT ENCRYPT)

std::string OTAPI_Exec::Encode(const std::string & strPlaintext);

This will pack, compress, and base64-encode a plain string.
Returns the base64-encoded string, or "".

Internally:
OTString		strPlain(strPlaintext);
OTASCIIArmor	ascEncoded(thePlaintext);	// ascEncoded now contains the OT-encoded string.
return			ascEncoded.Get();			// We return it.
*/
std::string OTAPI_Exec::Encode(const std::string & strPlaintext, const bool & bLineBreaks) // bLineBreaks should usually be set to true.
{
	if (strPlaintext.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strPlaintext"		); OT_FAIL; }

	if ( (true != bLineBreaks			) && (false != bLineBreaks			) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bLineBreaks"			); OT_FAIL; }

	const	OTString otstrPlaintext(strPlaintext);
	OTString strOutput;

	bool bEncoded = OTAPI()->Encode(otstrPlaintext, strOutput, (true == bLineBreaks) ? true : false);

	if (!bEncoded)
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;
}






// --------------------------------------------------------------------
/** Decode an OT-encoded string (back to plaintext.)  (NOT DECRYPT)

std::string OTAPI_Exec::Decode(const std::string & strEncoded);

This will base64-decode, uncompress, and unpack an OT-encoded string.
Returns the plaintext string, or "".

Internally:
OTASCIIArmor	ascEncoded(strEncoded);
OTString		strPlain(ascEncoded);	// strPlain now contains the decoded plaintext string.
return			strPlain.Get();			// We return it.
*/
std::string OTAPI_Exec::Decode(const std::string & strEncoded, const bool & bLineBreaks)
{
	if (strEncoded.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strEncoded"			); OT_FAIL; }

	if ( (true != bLineBreaks			) && (false != bLineBreaks			) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bLineBreaks"			); OT_FAIL; }

	const	OTString otstrEncoded(strEncoded);
	OTString strOutput;

	bool bDecoded = OTAPI()->Decode(otstrEncoded, strOutput,  (true == bLineBreaks) ? true : false);

	if (!bDecoded)
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;
}






// --------------------------------------------------------------------
/** OT-ENCRYPT a plaintext string.  ASYMMETRIC

std::string OTAPI_Exec::Encrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strPlaintext);

This will encode, ENCRYPT, and encode a plain string.
Returns the base64-encoded ciphertext, or "".

Internally the C++ code is:
OTString		strPlain(strPlaintext);
OTEnvelope		theEnvelope;
if (theEnvelope.Seal(RECIPIENT_NYM, strPlain)) {	// Now it's encrypted (in binary form, inside the envelope), to the recipient's nym.
OTASCIIArmor	ascCiphertext(theEnvelope);		// ascCiphertext now contains the base64-encoded ciphertext (as a string.)
return ascCiphertext.Get();
}
*/
std::string OTAPI_Exec::Encrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strPlaintext)
{
	if (RECIPIENT_NYM_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_NYM_ID"	); OT_FAIL; }
	if (strPlaintext.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strPlaintext"		); OT_FAIL; }
	// --------------------------------------------------------------------
	const OTString		otstrPlaintext(strPlaintext);
	const OTIdentifier	theRecipientNymID(RECIPIENT_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	bool bEncrypted = OTAPI()->Encrypt(theRecipientNymID, otstrPlaintext, strOutput);

	if (!bEncrypted || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;
}






// --------------------------------------------------------------------
/** OT-DECRYPT an OT-encrypted string back to plaintext.  ASYMMETRIC

std::string OTAPI_Exec::Decrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strCiphertext);

Decrypts the base64-encoded ciphertext back into a normal string plaintext.
Returns the plaintext string, or "".

Internally the C++ code is:
OTEnvelope		theEnvelope;					// Here is the envelope object. (The ciphertext IS the data for an OTEnvelope.)
OTASCIIArmor	ascCiphertext(strCiphertext);	// The base64-encoded ciphertext passed in. Next we'll try to attach it to envelope object...
if (theEnvelope.SetAsciiArmoredData(ascCiphertext)) {	// ...so that we can open it using the appropriate Nym, into a plain string object:
OTString	strServerReply;					// This will contain the output when we're done.
const bool	bOpened =						// Now we try to decrypt:
theEnvelope.Open(RECIPIENT_NYM, strServerReply);
if (bOpened) {
return strServerReply.Get();
}
}
*/
std::string OTAPI_Exec::Decrypt(const std::string & RECIPIENT_NYM_ID, const std::string & strCiphertext)
{
	if (RECIPIENT_NYM_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_NYM_ID"	); OT_FAIL; }
	if (strCiphertext.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "strCiphertext"		); OT_FAIL; }
	// --------------------------------------------------------------------
	const OTString		otstrCiphertext(strCiphertext);
	const OTIdentifier	theRecipientNymID(RECIPIENT_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	bool bDecrypted = OTAPI()->Decrypt(theRecipientNymID, otstrCiphertext, strOutput);

	if (!bDecrypted || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;
}






// -----------------------------------------------

// SYMMETRIC


// Generates a new symmetric key, based on a passphrase,
// and returns it (or "".)
//
std::string OTAPI_Exec::CreateSymmetricKey()
{
	OTString  strOutput;
	// -----------------------------------------------
	std::string    strDisplay = "OTAPI: Creating a new symmetric key.";
	const OTString  otstrDisplay(strDisplay);
	// -----------------------------------------------
	const bool & bSuccess = OTSymmetricKey::CreateNewKey(strOutput, &otstrDisplay);//pAlreadyHavePW=""

	if (!bSuccess)
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;
}

// -----------------------------------------------

// OTEnvelope:
//     bool Encrypt(const OTString & theInput,        OTSymmetricKey & theKey, const OTPassword & thePassword);
//     bool Decrypt(      OTString & theOutput, const OTSymmetricKey & theKey, const OTPassword & thePassword);


// Returns the CIPHERTEXT_ENVELOPE (the Envelope encrypted with the Symmetric Key.)
//
std::string OTAPI_Exec::SymmetricEncrypt(const std::string & SYMMETRIC_KEY, const std::string & PLAINTEXT)
{
	if (SYMMETRIC_KEY.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SYMMETRIC_KEY" ); OT_FAIL; }
	if (PLAINTEXT.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PLAINTEXT"     ); OT_FAIL; }
	// ---------------------------
	const OTString  strKey(SYMMETRIC_KEY);
	const OTString  strPlaintext(PLAINTEXT);
	// -----------------------------------
	OTString  strOutput;
	// ---------------------------
	std::string    strDisplay = "OTAPI: Password-protecting a plaintext.";
	const OTString  otstrDisplay(strDisplay);
	// ---------------------------
	const bool & bSuccess = OTSymmetricKey::Encrypt(strKey, strPlaintext, strOutput, &otstrDisplay); //bBookends=true, pAlreadyHavePW=""

	if (!bSuccess)
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;
}

// -----------------------------------------------

// Returns the PLAINTEXT.
//
std::string OTAPI_Exec::SymmetricDecrypt(const std::string & SYMMETRIC_KEY, const std::string & CIPHERTEXT_ENVELOPE)
{
	if (SYMMETRIC_KEY.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SYMMETRIC_KEY"		); OT_FAIL; }
	if (CIPHERTEXT_ENVELOPE.empty()){ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CIPHERTEXT_ENVELOPE"); OT_FAIL; }
	// ---------------------------
	const OTString  strKey(SYMMETRIC_KEY);
	OTString  strCiphertext(CIPHERTEXT_ENVELOPE);
	// ---------------------------
	OTString  strOutput;
	// ---------------------------
	std::string     strDisplay = "OTAPI: Decrypting a password-protected ciphertext.";
	const OTString  otstrDisplay(strDisplay);
	// ---------------------------
	const bool & bSuccess = OTSymmetricKey::Decrypt(strKey, strCiphertext, strOutput, &otstrDisplay);//pAlreadyHavePW=""

	if (!bSuccess)
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;
}

// -----------------------------------------------







// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.  (First signature)

std::string OTAPI_Exec::SignContract(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT);

Tries to instantiate the contract object, based on the string passed in.
Releases all signatures, and then signs the contract.
Returns the signed contract, or "" if failure.

NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
this function. Why not? because, anytime a signature is needed on something,
the relevant OT API call will require you to pass in the Nym, and the API already
signs internally wherever it deems appropriate. Thus, this function is only for
advanced uses, for OT-Scripts, server operators, etc.

*/
std::string OTAPI_Exec::SignContract(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT)
{
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }

	// --------------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	const bool & bSigned  = OTAPI()->SignContract(theSignerNymID, strContract, strOutput);

	if (!bSigned || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;
}



// Instead of signing an existing contract, this is for just signing a flat message.
// Or, for example, for signing a new contract that has no signature yet. Let's say you
// have a ledger, for example, with no signatures yet. Pass "LEDGER" as the CONTRACT_TYPE
// and the resulting output will start like this: -----BEGIN OT SIGNED LEDGER----- ...
// Returns the signed output, or "".
//
std::string OTAPI_Exec::FlatSign(const std::string & SIGNER_NYM_ID, const std::string & THE_INPUT, const std::string & CONTRACT_TYPE)
{
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (THE_INPUT.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INPUT"			); OT_FAIL; }
	if (CONTRACT_TYPE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CONTRACT_TYPE"		); OT_FAIL; }


	// --------------------------------------------------------------------
	const OTString		strContract(THE_INPUT);
	const OTString		strContractType(CONTRACT_TYPE);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	const bool & bSigned  = OTAPI()->FlatSign(theSignerNymID,  strContract,
		strContractType, strOutput);

	if (!bSigned || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;
}



// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.  (Add a signature)

std::string OTAPI_Exec::AddSignature(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT);

Tries to instantiate the contract object, based on the string passed in.
Signs the contract, without releasing any signatures that are already there.
Returns the signed contract, or "" if failure.

NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
this function. Why not? because, anytime a signature is needed on something,
the relevant OT API call will require you to pass in the Nym, and the API already
signs internally wherever it deems appropriate. Thus, this function is only for
advanced uses, for OT-Scripts, server operators, etc.

Internally the C++ code is:
*/
std::string OTAPI_Exec::AddSignature(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT)
{
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; }

	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }

	// --------------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	const bool & bSigned  = OTAPI()->AddSignature(theSignerNymID, strContract, strOutput);

	if (!bSigned || !strOutput.Exists())
		return "";

	std::string pBuf = strOutput.Get();

	return pBuf;

}





// --------------------------------------------------------------------
/** OT-Verify the signature on a CONTRACT stored in a string.

Returns bool -- true (1) or false (0)
*/
bool	OTAPI_Exec::VerifySignature(const std::string & SIGNER_NYM_ID, const std::string & THE_CONTRACT)
{
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }
	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	const bool & bVerified = OTAPI()->VerifySignature(strContract, theNymID); /*ppContract="" (optional third parameter for retrieving loaded contract.)*/
	// -----------------------------------------------------
	return bVerified ? true : false;
}





// --------------------------------------------------
// Verify and Retrieve XML Contents.
//
// Pass in a contract and a user ID, and this function will:
// -- Load the contract up and verify it.
// -- Verify the user's signature on it.
// -- Remove the PGP-style bookends (the signatures, etc)
//    and return the XML contents of the contract in string form.
//
std::string OTAPI_Exec::VerifyAndRetrieveXMLContents(const std::string & THE_CONTRACT,
												const std::string & SIGNER_ID)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }
	if (SIGNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_FAIL; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerID(SIGNER_ID);
	// -----------------------------------------------------
	OTString strOutput;

	if (false == OTAPI()->VerifyAndRetrieveXMLContents(strContract, theSignerID, strOutput))
	{
		OTLog::vOutput(0, "%s: Failure: OTAPI()->VerifyAndRetrieveXMLContents() returned false.\n",__FUNCTION__);
		return "";
	}
	// -----------------------------------------------------
	std::string pBuf = strOutput.Get();



	return pBuf;
}





// === Verify Account Receipt ===
// Returns bool. Verifies any asset account (intermediary files) against its own last signed receipt.
// Obviously this will fail for any new account that hasn't done any transactions yet, and thus has no receipts.
//
bool OTAPI_Exec::VerifyAccountReceipt(const std::string & SERVER_ID, const std::string & NYM_ID, const std::string & ACCT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (NYM_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_FAIL; }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theNymID(NYM_ID), theAcctID(ACCT_ID);
	// -----------------------------------------------------
	const bool & bVerified = OTAPI()->VerifyAccountReceipt(theServerID, theNymID, theAcctID);
	// -----------------------------------------------------
	return bVerified ? true : false;
}






// -------------------------------------------------------
// SET ACCOUNT NAME (client side only. Server cares not about such labels.)
//
// Returns true (1) or false (0)
//
bool OTAPI_Exec::SetAccountWallet_Name(const std::string & ACCT_ID, const std::string & SIGNER_NYM_ID, const std::string & ACCT_NEW_NAME)
{
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_FAIL; }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (ACCT_NEW_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NEW_NAME"		); OT_FAIL; }

	OTIdentifier	theAcctID(ACCT_ID),
		theSignerNymID(SIGNER_NYM_ID);
	OTString		strAcctNewName(ACCT_NEW_NAME);

	bool bSuccess = OTAPI()->SetAccount_Name(theAcctID, theSignerNymID, strAcctNewName);

	return bSuccess ? true : false;
}



// returns the account balance, based on account ID.
int64_t OTAPI_Exec::GetAccountWallet_Balance(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_FAIL; }

	OTIdentifier	theID(THE_ID);
	// -------------------------
	OTAccount * pAccount = OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return -1;
	// -------------------------
	int64_t lBalance = pAccount->GetBalance();
	return lBalance;
}



// returns an account's "account type", (simple, issuer, etc.)
std::string OTAPI_Exec::GetAccountWallet_Type(const std::string & THE_ID)
{
	if (THE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID" ); OT_FAIL; }

	OTIdentifier	theID(THE_ID);
	// -------------------------
	OTAccount * pAccount = OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------
	std::string pBuf = pAccount->GetTypeString();


	return pBuf;
}



// Returns an account's asset type ID.
// (Which is a hash of the contract used to issue the asset type.)
std::string OTAPI_Exec::GetAccountWallet_AssetTypeID(const std::string & THE_ID)
{
	if (THE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID" ); OT_FAIL; }

	OTIdentifier theID(THE_ID);
	// -------------------------
	OTAccount * pAccount = OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------
	OTIdentifier theAssetID(pAccount->GetAssetTypeID());

	OTString strAssetTypeID(theAssetID);

	OTLog::vOutput(1, "%s: Returning asset type %s for account %s\n", __FUNCTION__, strAssetTypeID.Get(), THE_ID.c_str());

	std::string pBuf = strAssetTypeID.Get();

	return pBuf;
}



// Returns an account's Server ID.
// (Which is a hash of the server contract.)
std::string OTAPI_Exec::GetAccountWallet_ServerID(const std::string & THE_ID)
{
	if (THE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID" ); OT_FAIL; }

	OTIdentifier	theID(THE_ID);
	// -------------------------
	OTAccount * pAccount = OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------
	OTIdentifier theServerID(pAccount->GetPurportedServerID());
	OTString strServerID(theServerID);

	std::string pBuf = strServerID.Get();

	return pBuf;
}




// Returns an account's Nym ID.
// (Which is a hash of the Nym's public key for the owner of this account.)
std::string OTAPI_Exec::GetAccountWallet_NymID(const std::string & THE_ID)
{
	if (THE_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_FAIL; }

	const OTIdentifier	theID(THE_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------
	OTIdentifier theUserID(pAccount->GetUserID());
	OTString strUserID(theUserID);

	std::string pBuf = strUserID.Get();

	return pBuf;
}




/*
// ----------------------------------------------------------------------

WRITE A CHEQUE  --- (Returns the cheque in string form.)

==> OTAPI_Exec::WriteCheque() internally constructs an OTCheque and issues it, like so:

OTCheque theCheque( SERVER_ID, ASSET_TYPE_ID );

theCheque.IssueCheque( AMOUNT // The amount of the cheque, in string form, which OTAPI
// will convert to a int64_t integer. Negative amounts
// allowed, since that is how OT implements invoices.
// (An invoice is just a cheque with a negative amount.)

lTransactionNumber,   // The API will supply this automatically, as long as
// there are some transaction numbers in the wallet. (Call
// OTAPI_Exec::getTransactionNumber() if your wallet needs more.)

VALID_FROM, VALID_TO, // Valid date range (in seconds since Jan 1970...)

ACCOUNT_ID, USER_ID,  // User ID and Acct ID for SENDER.

CHEQUE_MEMO,  // The memo for the cheque.

RECIPIENT_USER_ID); // Recipient User ID is optional. (You can use an
// empty string here, to write a blank cheque.)
*/
std::string OTAPI_Exec::WriteCheque(const std::string & SERVER_ID,
                                    const int64_t & CHEQUE_AMOUNT,
                                    const time64_t & VALID_FROM,
                                    const time64_t & VALID_TO,
                                    const std::string & SENDER_ACCT_ID,
                                    const std::string & SENDER_USER_ID,
                                    const std::string & CHEQUE_MEMO,
                                    const std::string & RECIPIENT_USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (0 == CHEQUE_AMOUNT)         { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_AMOUNT"		); OT_FAIL; }
    if (OT_TIME_ZERO > VALID_FROM)  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VALID_FROM"); OT_FAIL; }
    if (OT_TIME_ZERO > VALID_TO)    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VALID_TO"); OT_FAIL; }
	if (SENDER_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_FAIL; }
	if (SENDER_USER_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_FAIL; }
//	if (CHEQUE_MEMO.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_MEMO"		); OT_FAIL; } // optional
//	if (RECIPIENT_USER_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_FAIL; } // optional

	const int64_t lAmount = CHEQUE_AMOUNT;
	const time64_t  time_From = static_cast<time64_t>(VALID_FROM), time_To = static_cast<time64_t>(VALID_TO);

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);
          OTIdentifier theRecipientUserID;
	bool  bHasRecipient = !RECIPIENT_USER_ID.empty();
	if (bHasRecipient)
		theRecipientUserID.SetString(RECIPIENT_USER_ID);
	// ----------------------------------------------------
	OTString strMemo;

	if (!CHEQUE_MEMO.empty())
		strMemo.Set(CHEQUE_MEMO);

	OTCheque * pCheque = OTAPI()->WriteCheque(theServerID,
		static_cast<int64_t>(lAmount),
		time_From, time_To,
		theSenderAcctID,
		theSenderUserID,
		strMemo,
		bHasRecipient ? &(theRecipientUserID) : NULL);

	OTCleanup<OTCheque> theChequeAngel(pCheque); // Handles cleanup. (If necessary.)

	if (NULL == pCheque)
	{
		OTLog::vError("%s: OT_API::WriteCheque failed.\n",__FUNCTION__);
		return "";
	}
    // ------------------------------------------------
	// At this point, I know pCheque is good (and will be cleaned up automatically.)

	OTString strCheque(*pCheque); // Extract the cheque to string form.

	std::string pBuf = strCheque.Get();

	return pBuf;
}



bool OTAPI_Exec::DiscardCheque(const std::string & SERVER_ID,
                               const std::string & USER_ID,
                               const std::string & ACCT_ID,
                               const std::string & THE_CHEQUE)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCT_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"    ); OT_FAIL; }
	if (THE_CHEQUE.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CHEQUE" ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strCheque(THE_CHEQUE);

	const bool bDiscarded = OTAPI()->DiscardCheque(theServerID, theUserID, theAcctID, strCheque);

	return (bDiscarded ? true : false);
}



// -----------------------------------------------------------------
// PROPOSE PAYMENT PLAN
//
// (Return as STRING)
//
// PARAMETER NOTES:
// -- Payment Plan Delay, and Payment Plan Period, both default to 30 days (if you pass 0.)
//
// -- Payment Plan Length, and Payment Plan Max Payments, both default to 0, which means
//    no maximum length and no maximum number of payments.
//
// -----------------------------------------------------------------
// FYI, the payment plan creation process (finally) is:
//
// 1) Payment plan is written, and signed, by the recipient.  (This function: OTAPI_Exec::ProposePaymentPlan)
// 2) He sends it to the sender, who signs it and submits it. (OTAPI_Exec::ConfirmPaymentPlan and OTAPI_Exec::depositPaymentPlan)
// 3) The server loads the recipient nym to verify the transaction
//    number. The sender also had to burn a transaction number (to
//    submit it) so now, both have verified trns#s in this way.
//
std::string OTAPI_Exec::ProposePaymentPlan(
	const std::string	& SERVER_ID,
	// ----------------------------------------
    const time64_t        & VALID_FROM,	// Default (0 or NULL) == current time measured in seconds since Jan 1970.
    const time64_t        & VALID_TO,     // Default (0 or NULL) == no expiry / cancel anytime. Otherwise this is ADDED to VALID_FROM (it's a length.)
    // ----------------------------------------
	const std::string	& SENDER_ACCT_ID,			// Mandatory parameters.
	const std::string	& SENDER_USER_ID,			// Both sender and recipient must sign before submitting.
	// ----------------------------------------
	const std::string	& PLAN_CONSIDERATION,		// Like a memo.
	// ----------------------------------------
	const std::string	& RECIPIENT_ACCT_ID,		// NOT optional.
	const std::string	& RECIPIENT_USER_ID,		// Both sender and recipient must sign before submitting.
	// -------------------------------
	const int64_t		& INITIAL_PAYMENT_AMOUNT,	// zero or "" is no initial payment.
	const time64_t		& INITIAL_PAYMENT_DELAY,	// seconds from creation date. Default is zero or "".
	// ----------------------------------------
	const int64_t		& PAYMENT_PLAN_AMOUNT,		// Zero or "" is no regular payments.
	const time64_t		& PAYMENT_PLAN_DELAY,		// No. of seconds from creation date. Default is zero or "".
	const time64_t		& PAYMENT_PLAN_PERIOD,		// No. of seconds between payments. Default is zero or "".
	// ---------------------------------------
	const time64_t		& PAYMENT_PLAN_LENGTH,		// In seconds. Defaults to 0 or "" (no maximum length.)
	const int32_t		& PAYMENT_PLAN_MAX_PAYMENTS	// Integer. Defaults to 0 or "" (no maximum payments.)
	)
{
	if (SERVER_ID.empty())				{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SERVER_ID"                 ); OT_FAIL; }
    if (OT_TIME_ZERO > VALID_FROM)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "VALID_FROM"); OT_FAIL; }
    if (OT_TIME_ZERO > VALID_TO)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "VALID_TO"); OT_FAIL; }
	if (SENDER_ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SENDER_ACCT_ID"            ); OT_FAIL; }
	if (SENDER_USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SENDER_USER_ID"            ); OT_FAIL; }
	if (PLAN_CONSIDERATION.empty())		{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "PLAN_CONSIDERATION"        ); OT_FAIL; }
	if (RECIPIENT_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "RECIPIENT_ACCT_ID"         ); OT_FAIL; }
	if (RECIPIENT_USER_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "RECIPIENT_USER_ID"         ); OT_FAIL; }
	if (0 > INITIAL_PAYMENT_AMOUNT)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "INITIAL_PAYMENT_AMOUNT"    ); OT_FAIL; }
    if (OT_TIME_ZERO > INITIAL_PAYMENT_DELAY)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "INITIAL_PAYMENT_DELAY"); OT_FAIL; }
	if (0 > PAYMENT_PLAN_AMOUNT)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_AMOUNT"       ); OT_FAIL; }
    if (OT_TIME_ZERO > PAYMENT_PLAN_DELAY)			{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_DELAY"); OT_FAIL; }
    if (OT_TIME_ZERO > PAYMENT_PLAN_PERIOD)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_PERIOD"); OT_FAIL; }
    if (OT_TIME_ZERO > PAYMENT_PLAN_LENGTH)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_LENGTH"); OT_FAIL; }
	if (0 > PAYMENT_PLAN_MAX_PAYMENTS)	{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN_MAX_PAYMENTS" ); OT_FAIL; }
    // ---------------------------------------
	OTPaymentPlan * pPlan(OTAPI()->ProposePaymentPlan(
		OTIdentifier(SERVER_ID),
		// ----------------------------------------
		VALID_FROM,		// Default (0) == NOW
		VALID_TO,		// Default (0) == no expiry / cancel anytime
		// ----------------------------------------
		OTIdentifier(SENDER_ACCT_ID),
		OTIdentifier(SENDER_USER_ID),
		// ----------------------------------------
		PLAN_CONSIDERATION.empty() ? "(Consideration for the agreement between the parties is meant to be recorded here.)" : PLAN_CONSIDERATION, // Like a memo.
		// ----------------------------------------
		OTIdentifier(RECIPIENT_ACCT_ID),
		OTIdentifier(RECIPIENT_USER_ID),
		// ----------------------------------------
		static_cast<int64_t>(INITIAL_PAYMENT_AMOUNT),
		INITIAL_PAYMENT_DELAY,
		// ----------------------------------------
		static_cast<int64_t>(PAYMENT_PLAN_AMOUNT),
		PAYMENT_PLAN_DELAY,
		PAYMENT_PLAN_PERIOD,
		// ----------------------------------------
		PAYMENT_PLAN_LENGTH,
		static_cast<int32_t>(PAYMENT_PLAN_MAX_PAYMENTS)
		));
    // ---------------------------------------
	OTCleanup<OTPaymentPlan> theAngel(pPlan); // Handles cleanup. (If necessary.)
	if (NULL == pPlan)
	{
		OTLog::vError("%s: failed in OTAPI_Exec::ProposePaymentPlan.\n",__FUNCTION__);
		return "";
	}
	// At this point, I know pPlan is good (and will be cleaned up automatically.)
    // ---------------------------------------
	OTString strOutput(*pPlan); // Extract the payment plan to string form.
    // ---------------------------------------
	std::string pBuf = strOutput.Get();
	return pBuf;
}






// TODO RESUME:
// 1. Find out what DiscardCheque is used for.
// 2. Make sure we don't need a "Discard Payment Plan" and "Discard Smart Contract" as well.
// 3. Add "EasyProposePlan" to the rest of the API like OTAPI_Basic
// 4. Add 'propose' and 'confirm' (for payment plan) commands to opentxs client.
// 5. Finish opentxs basket commands, so opentxs is COMPLETE.








std::string OTAPI_Exec::EasyProposePlan(
    const std::string & SERVER_ID,
    // ----------------------------------------
    const std::string & DATE_RANGE,         // "from,to"  Default 'from' (0 or "") == NOW, and default 'to' (0 or "") == no expiry / cancel anytime
    // ----------------------------------------
    const std::string & SENDER_ACCT_ID,     // Mandatory parameters.
    const std::string & SENDER_USER_ID,     // Both sender and recipient must sign before submitting.
    // ----------------------------------------
    const std::string & PLAN_CONSIDERATION,	// Like a memo.
    // ----------------------------------------
    const std::string & RECIPIENT_ACCT_ID,	// NOT optional.
    const std::string & RECIPIENT_USER_ID,	// Both sender and recipient must sign before submitting.
    // -------------------------------
    const std::string & INITIAL_PAYMENT,	// "amount,delay"  Default 'amount' (0 or "") == no initial payment. Default 'delay' (0 or NULL) is seconds from creation date.
    // -------------------------------
    const std::string & PAYMENT_PLAN,       // "amount,delay,period" 'amount' is a recurring payment. 'delay' and 'period' cause 30 days if you pass 0 or "".
    // -------------------------------
    const std::string & PLAN_EXPIRY         // "length,number" 'length' is maximum lifetime in seconds. 'number' is maximum number of payments in seconds. 0 or "" is unlimited.
    )
{
	if (SERVER_ID.empty())          { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"          ); OT_FAIL; }
	if (SENDER_ACCT_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"     ); OT_FAIL; }
	if (SENDER_USER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"     ); OT_FAIL; }
	if (PLAN_CONSIDERATION.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PLAN_CONSIDERATION" ); OT_FAIL; }
	if (RECIPIENT_ACCT_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_ACCT_ID"  ); OT_FAIL; }
	if (RECIPIENT_USER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"  ); OT_FAIL; }
    // ----------------------------------------
    time64_t  VALID_FROM                = OT_TIME_ZERO;
    time64_t  VALID_TO                  = OT_TIME_ZERO;
    // ----------------------------------------
    int64_t INITIAL_PAYMENT_AMOUNT      = 0;
    time64_t  INITIAL_PAYMENT_DELAY     = OT_TIME_ZERO;
    // ----------------------------------------
    int64_t PAYMENT_PLAN_AMOUNT         = 0;
    time64_t  PAYMENT_PLAN_DELAY        = OT_TIME_ZERO;
    time64_t  PAYMENT_PLAN_PERIOD       = OT_TIME_ZERO;
    // ---------------------------------------
    time64_t  PAYMENT_PLAN_LENGTH       = OT_TIME_ZERO;
    int32_t PAYMENT_PLAN_MAX_PAYMENTS   = 0;
    // ---------------------------------------
    if (!DATE_RANGE.empty())
    {
        OTNumList       theList;
        const OTString  otstrNumList(DATE_RANGE);
        // ----------------------
        theList.Add(otstrNumList);
        // ----------------------
        // VALID_FROM
        if (theList.Count() > 0)
        {
            int64_t lVal = 0;
            if (theList.Peek(lVal))
                VALID_FROM = OTTimeGetTimeFromSeconds(lVal);
            theList.Pop();
        }
        // ----------------------
        // VALID_TO
        if (theList.Count() > 0)
        {
            int64_t lVal = 0;
            if (theList.Peek(lVal))
                VALID_TO = OTTimeGetTimeFromSeconds(lVal);
            theList.Pop();
        }
    }
    // ---------------------------------------
    if (!INITIAL_PAYMENT.empty())
    {
        OTNumList       theList;
        const OTString  otstrNumList(INITIAL_PAYMENT);
        // ----------------------
        theList.Add(otstrNumList);
        // ----------------------
        // INITIAL_PAYMENT_AMOUNT
        if (theList.Count() > 0)
        {
            int64_t lVal = 0;
            if (theList.Peek(lVal))
                INITIAL_PAYMENT_AMOUNT = static_cast<int64_t>(lVal);
            theList.Pop();
        }
        // ----------------------
        // INITIAL_PAYMENT_DELAY
        if (theList.Count() > 0)
        {
            int64_t lVal = 0;
            if (theList.Peek(lVal))
                INITIAL_PAYMENT_DELAY = OTTimeGetTimeFromSeconds(lVal);
            theList.Pop();
        }
    }
    // ---------------------------------------
    if (!PAYMENT_PLAN.empty())
    {
        OTNumList       theList;
        const OTString  otstrNumList(PAYMENT_PLAN);
        // ----------------------
        theList.Add(otstrNumList);
        // ----------------------
        // PAYMENT_PLAN_AMOUNT
        if (theList.Count() > 0)
        {
            int64_t lVal = 0;
            if (theList.Peek(lVal))
                PAYMENT_PLAN_AMOUNT = static_cast<int64_t>(lVal);
            theList.Pop();
        }
        // ----------------------
        // PAYMENT_PLAN_DELAY
        if (theList.Count() > 0)
        {
            int64_t lVal = 0;
            if (theList.Peek(lVal))
                PAYMENT_PLAN_DELAY = OTTimeGetTimeFromSeconds(lVal);
            theList.Pop();
        }
        // ----------------------
        // PAYMENT_PLAN_PERIOD
        if (theList.Count() > 0)
        {
            int64_t lVal = 0;
            if (theList.Peek(lVal))
                PAYMENT_PLAN_PERIOD = OTTimeGetTimeFromSeconds(lVal);
            theList.Pop();
        }
    }
    // ---------------------------------------
    if (!PLAN_EXPIRY.empty())
    {
        OTNumList       theList;
        const OTString  otstrNumList(PLAN_EXPIRY);
        // ----------------------
        theList.Add(otstrNumList);
        // ----------------------
        // PAYMENT_PLAN_LENGTH
        if (theList.Count() > 0)
        {
            int64_t lVal = 0;
            if (theList.Peek(lVal))
                PAYMENT_PLAN_LENGTH = OTTimeGetTimeFromSeconds(lVal);
            theList.Pop();
        }
        // ----------------------
        // PAYMENT_PLAN_MAX_PAYMENTS
        if (theList.Count() > 0)
        {
            int64_t lVal = 0;
            if (theList.Peek(lVal))
                PAYMENT_PLAN_MAX_PAYMENTS = static_cast<int32_t>(lVal);
            theList.Pop();
        }
    }
    // ---------------------------------------
    return OTAPI_Exec::ProposePaymentPlan(SERVER_ID,
                                          VALID_FROM, VALID_TO,
                                          SENDER_ACCT_ID,
                                          SENDER_USER_ID,
                                          PLAN_CONSIDERATION,
                                          RECIPIENT_ACCT_ID,
                                          RECIPIENT_USER_ID,
                                          INITIAL_PAYMENT_AMOUNT, INITIAL_PAYMENT_DELAY,
                                          PAYMENT_PLAN_AMOUNT,    PAYMENT_PLAN_DELAY,       PAYMENT_PLAN_PERIOD,
                                          PAYMENT_PLAN_LENGTH,    PAYMENT_PLAN_MAX_PAYMENTS);
}


// Called by CUSTOMER.
// "PAYMENT_PLAN" is the output of the above function (ProposePaymentPlan)
// Customer should call OTAPI_Exec::depositPaymentPlan after this.
//
std::string OTAPI_Exec::ConfirmPaymentPlan(const std::string & SERVER_ID,
                                           const std::string & SENDER_USER_ID,
                                           const std::string & SENDER_ACCT_ID,
                                           const std::string & RECIPIENT_USER_ID,
                                           const std::string & PAYMENT_PLAN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (SENDER_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_FAIL; }
	if (SENDER_USER_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_FAIL; }
	if (RECIPIENT_USER_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_FAIL; }
	if (PAYMENT_PLAN.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN"		); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theRecipientUserID(RECIPIENT_USER_ID);

	OTPaymentPlan thePlan;
	const OTString strPlan(PAYMENT_PLAN);

	if (!strPlan.Exists() || (false == thePlan.LoadContractFromString(strPlan)))
	{
		OTLog::vOutput(0, "%s: Failure loading payment plan from string.\n",__FUNCTION__);
		return "";
	}
	// --------------------------------------
	bool bConfirmed = OTAPI()->ConfirmPaymentPlan(theServerID,
		theSenderUserID,
		theSenderAcctID,
		theRecipientUserID,
		thePlan);
	if (false == bConfirmed)
	{
		OTLog::vOutput(0, "%s: failed in OTAPI_Exec::ConfirmPaymentPlan().\n",__FUNCTION__);
		return "";
	}

	OTString strOutput(thePlan); // Extract the payment plan to string form.

	std::string pBuf = strOutput.Get();

	return pBuf;
}




// RETURNS:  the Smart Contract itself. (Or "".)
//
std::string OTAPI_Exec::Create_SmartContract(const std::string & SIGNER_NYM_ID, // Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
                                             // ----------------------------------------
                                             const time64_t & VALID_FROM,	// Default (0 or "") == NOW
                                             const time64_t & VALID_TO)	// Default (0 or "") == no expiry / cancel anytime
{
	if (SIGNER_NYM_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"  ); OT_FAIL; }
    if (OT_TIME_ZERO > VALID_FROM) { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "VALID_FROM"); OT_FAIL; }
    if (OT_TIME_ZERO > VALID_TO)   { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "VALID_TO"); OT_FAIL; }
	// -----------------------------------------------------
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	time64_t tValidFrom = VALID_FROM;
	time64_t tValidTo   = VALID_TO;
	// --------------------------------------
	OTString strOutput;

	const bool & bCreated = OTAPI()->Create_SmartContract(theSignerNymID,
                                                                      tValidFrom,	// Default (0 or "") == NOW
                                                                      tValidTo,     // Default (0 or "") == no expiry / cancel anytime
                                                                      strOutput);
	if (!bCreated || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();
	return pBuf;
}
// ----------------------------------------






//
// todo: Someday add a parameter here BYLAW_LANGUAGE so that people can use
// custom languages in their scripts.  For now I have a default language, so
// I'll just make that the default. (There's only one language right now anyway.)
//
// returns: the updated smart contract (or "")
std::string OTAPI_Exec::SmartContract_AddBylaw(const std::string & THE_CONTRACT,	// The contract, about to have the bylaw added to it.
                                               const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
                                               // ----------------------------------------
                                               const std::string & BYLAW_NAME)	// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
{
	if (THE_CONTRACT.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"  ); OT_FAIL; }
	if (SIGNER_NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID" ); OT_FAIL; }
	if (BYLAW_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"    ); OT_FAIL; }
	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strBylawName(BYLAW_NAME);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI()->SmartContract_AddBylaw(strContract,		// The contract, about to have the bylaw added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		strBylawName,		// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();

	return pBuf;
}







// returns: the updated smart contract (or "")
std::string OTAPI_Exec::SmartContract_AddClause(const std::string & THE_CONTRACT,	// The contract, about to have the clause added to it.
											const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
											// ----------------------------------------
											const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
											// ----------------------------------------
											const std::string & CLAUSE_NAME,	// The Clause's name as referenced in the smart contract. (And the scripts...)
											const std::string & SOURCE_CODE)	// The actual source code for the clause.
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (BYLAW_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_FAIL; }
	if (CLAUSE_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_FAIL; }
	if (SOURCE_CODE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SOURCE_CODE"		); OT_FAIL; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME),
		strClauseName(CLAUSE_NAME),	strSourceCode(SOURCE_CODE);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI()->SmartContract_AddClause(strContract,	// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strClauseName,	// The Clause's name as referenced in the smart contract. (And the scripts...)
		strSourceCode,	// The actual source code for the clause.
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();



	return pBuf;
}



// returns: the updated smart contract (or "")
std::string OTAPI_Exec::SmartContract_AddVariable(const std::string & THE_CONTRACT,	// The contract, about to have the variable added to it.
											 const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
											  // ----------------------------------------
											 const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
											  // ----------------------------------------
											 const std::string & VAR_NAME,	// The Variable's name as referenced in the smart contract. (And the scripts...)
											 const std::string & VAR_ACCESS,	// "constant", "persistent", or "important".
											 const std::string & VAR_TYPE,	// "string", "int64_t", or "bool"
											 const std::string & VAR_VALUE)	// Contains a string. If type is int64_t, StringToLong() will be used to convert value to a int64_t. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
{
	if (THE_CONTRACT.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"  ); OT_FAIL; }
	if (SIGNER_NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID" ); OT_FAIL; }
	if (BYLAW_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"    ); OT_FAIL; }
	if (VAR_NAME.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_NAME"      ); OT_FAIL; }
	if (VAR_ACCESS.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_ACCESS"    ); OT_FAIL; }
	if (VAR_TYPE.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_TYPE"      ); OT_FAIL; }
//	if (VAR_VALUE.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_VALUE"     ); OT_FAIL; }
	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME),
                        strVarName(VAR_NAME),		strVarAccess(VAR_ACCESS),
                        strVarType(VAR_TYPE),		strVarValue(VAR_VALUE);
	const OTIdentifier  theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI()->SmartContract_AddVariable(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strVarName,		// The Variable's name as referenced in the smart contract. (And the scripts...)
		strVarAccess,	// "constant", "persistent", or "important".
		strVarType,		// "string", "int64_t", or "bool"
		strVarValue,		// Contains a string. If type is int64_t, StringToLong() will be used to convert value to a int64_t. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
		// ----------------------------------------
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();
	return pBuf;
}





// returns: the updated smart contract (or "")
std::string OTAPI_Exec::SmartContract_AddCallback(const std::string & THE_CONTRACT,	// The contract, about to have the callback added to it.
											 const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
											  // ----------------------------------------
											 const std::string & BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
											  // ----------------------------------------
											 const std::string & CALLBACK_NAME,	// The Callback's name as referenced in the smart contract. (And the scripts...)
											 const std::string & CLAUSE_NAME)	// The actual clause that will be triggered by the callback. (Must exist.)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (BYLAW_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_FAIL; }
	if (CALLBACK_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CALLBACK_NAME"		); OT_FAIL; }
	if (CLAUSE_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_FAIL; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME),
		strCallbackName(CALLBACK_NAME),	strClauseName(CLAUSE_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI()->SmartContract_AddCallback(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strCallbackName,	// The Callback's name as referenced in the smart contract. (And the scripts...)
		strClauseName,	// The actual clause that will be triggered by the callback. (Must exist.)
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();



	return pBuf;
}





// returns: the updated smart contract (or "")
std::string OTAPI_Exec::SmartContract_AddHook(const std::string & THE_CONTRACT,	// The contract, about to have the hook added to it.
										 const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
										  // ----------------------------------------
										 const std::string & BYLAW_NAME,		// Should already be on the contract. (This way we can find it.)
										  // ----------------------------------------
										 const std::string & HOOK_NAME,		// The Hook's name as referenced in the smart contract. (And the scripts...)
										 const std::string & CLAUSE_NAME)		// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (BYLAW_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_FAIL; }
	if (HOOK_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "HOOK_NAME"			); OT_FAIL; }
	if (CLAUSE_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_FAIL; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME),
		strHookName(HOOK_NAME),		strClauseName(CLAUSE_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI()->SmartContract_AddHook(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strHookName,		// The Hook's name as referenced in the smart contract. (And the scripts...)
		strClauseName,	// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();



	return pBuf;
}



// --------------------------------------------------------------



// RETURNS: Updated version of THE_CONTRACT. (Or "".)
std::string OTAPI_Exec::SmartContract_AddParty(const std::string & THE_CONTRACT, // The contract, about to have the party added to it.
										  const std::string & SIGNER_NYM_ID,     // Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
										   // ----------------------------------------
										  const std::string & PARTY_NAME,        // The Party's NAME as referenced in the smart contract. (And the scripts...)
										   // ----------------------------------------
										  const std::string & AGENT_NAME)        // An AGENT will be added by default for this party. Need Agent NAME.
										   // (FYI, that is basically the only option, until I code Entities and Roles. Until then, a party can ONLY be
										   // a Nym, with himself as the agent representing that same party. Nym ID is supplied on ConfirmParty() below.)
{
	if (THE_CONTRACT.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
	if (SIGNER_NYM_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"); OT_FAIL; }
	if (PARTY_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
	if (AGENT_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strPartyName(PARTY_NAME),
		strAgentName(AGENT_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI()->SmartContract_AddParty(strContract,		// The contract, about to have the bylaw added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strPartyName,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
		strAgentName,		// An AGENT will be added by default for this party. Need Agent NAME.
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();
	return pBuf;
}




// ----------------------------------------



// Used when creating a theoretical smart contract (that could be used over and over again with different parties.)
//
// returns: the updated smart contract (or "")
std::string OTAPI_Exec::SmartContract_AddAccount(const std::string & THE_CONTRACT,		// The contract, about to have the account added to it.
											const std::string & SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
											 // ----------------------------------------
											const std::string & PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
											 // ----------------------------------------
											const std::string & ACCT_NAME,		// The Account's name as referenced in the smart contract
											const std::string & ASSET_TYPE_ID)	// Asset Type ID for the Account.
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (PARTY_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_FAIL; }
	if (ACCT_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"			); OT_FAIL; }
//	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strPartyName(PARTY_NAME),
		strAcctName(ACCT_NAME),		strAssetTypeID(ASSET_TYPE_ID);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bAdded = OTAPI()->SmartContract_AddAccount(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		strPartyName,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
		// ----------------------------------------
		strAcctName,		// The Account's name as referenced in the smart contract
		strAssetTypeID,	// Asset Type ID for the Account.
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();



	return pBuf;
}





// This function returns the count of how many trans#s a Nym needs in order to confirm as
// a specific agent for a contract. (An opening number is needed for every party of which
// agent is the authorizing agent, plus a closing number for every acct of which agent is the
// authorized agent.)
//
// Otherwise a Nym might try to confirm a smart contract and be unable to, since he doesn't
// have enough transaction numbers, yet he would have no way of finding out HOW MANY HE *DOES*
// NEED. This function allows him to find out, before confirmation, so he can first grab however
// many transaction#s he will need in order to confirm this smart contract.
//
int32_t OTAPI_Exec::SmartContract_CountNumsNeeded(const std::string & THE_CONTRACT,	// The smart contract, about to be queried by this function.
										const std::string & AGENT_NAME)
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }
	if (AGENT_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_FAIL; }
	// -------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strAgentName(AGENT_NAME);
	// -------------------------------------------------------------
	//
	const int32_t & nCount = OTAPI()->SmartContract_CountNumsNeeded(strContract, strAgentName);

	return nCount;
}

// ----------------------------------------

// Used when taking a theoretical smart contract, and setting it up to use specific Nyms and accounts.
// This function sets the ACCT ID and the AGENT NAME for the acct specified by party name and acct name.
// Returns the updated smart contract (or "".)
//
std::string OTAPI_Exec::SmartContract_ConfirmAccount(const std::string & THE_CONTRACT,
                                                     const std::string & SIGNER_NYM_ID,
                                                     // ----------------------------------------
                                                     const std::string & PARTY_NAME,	// Should already be on the contract.
                                                     const std::string & ACCT_NAME,     // Should already be on the contract.
                                                     // ----------------------------------------
                                                     const std::string & AGENT_NAME,	// The agent name for this asset account.
                                                     const std::string & ACCT_ID)		// AcctID for the asset account. (For acct_name).
{
	if (THE_CONTRACT.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_FAIL; }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (PARTY_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_FAIL; }
	if (ACCT_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"			); OT_FAIL; }
	if (AGENT_NAME.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_FAIL; }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_FAIL; }
	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strPartyName(PARTY_NAME);
	const OTString		strAccountID(ACCT_ID), strAcctName(ACCT_NAME), strAgentName(AGENT_NAME);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID), theAcctID(strAccountID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bConfirmed = OTAPI()->SmartContract_ConfirmAccount(strContract,
                                                                                theSignerNymID,
                                                                                strPartyName,
                                                                                strAcctName,
                                                                                strAgentName,
                                                                                strAccountID,
                                                                                strOutput);
	if (!bConfirmed || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();
	return pBuf;
}




// Called by each Party. Pass in the smart contract obtained in the above call.
// Call OTAPI_Exec::SmartContract_ConfirmAccount() first, as much as you need to, THEN call this (for final signing.)
// This is the last call you make before either passing it on to another party to confirm, or calling OTAPI_Exec::activateSmartContract().
// Returns the updated smart contract (or "".)
std::string OTAPI_Exec::SmartContract_ConfirmParty(const std::string & THE_CONTRACT, // The smart contract, about to be changed by this function.
                                                   const std::string & PARTY_NAME,   // Should already be on the contract. This way we can find it.
                                                   // ----------------------------------------
                                                   const std::string & NYM_ID)       // Nym ID for the party, the actual owner,
                                                   // ===> AS WELL AS for the default AGENT of that party. (For now, until I code entities)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
	if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
	if (NYM_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"       ); OT_FAIL; }
	// -----------------------------------------------------
	const OTIdentifier	theNymID(NYM_ID);
	const OTString		strContract(THE_CONTRACT), strPartyName(PARTY_NAME);
	// -----------------------------------------------------
	OTString strOutput;

	const bool & bConfirmed = OTAPI()->SmartContract_ConfirmParty(strContract,	// The smart contract, about to be changed by this function.
		strPartyName,	// Should already be on the contract. This way we can find it.
		// ----------------------------------------
		theNymID,		// Nym ID for the party, the actual owner,
		strOutput);
	if (!bConfirmed || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	std::string pBuf = strOutput.Get();
	return pBuf;
}





// ----------------------------------------------------------

bool OTAPI_Exec::Smart_AreAllPartiesConfirmed(const std::string & THE_CONTRACT)  // true or false?
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        const bool bConfirmed = pScriptable->AllPartiesHaveSupposedlyConfirmed();
        const bool bVerified  = pScriptable->VerifyThisAgainstAllPartiesSignedCopies();
        // -----------------------------------------------------
        if (false == bConfirmed)
        {
//          OTLog::vOutput(0, "%s: Smart contract loaded up, but all parties are NOT confirmed:\n\n%s\n\n",
//                         __FUNCTION__, strContract.Get());
            OTLog::vOutput(1, "%s: Smart contract loaded up, but all parties are NOT confirmed.\n",
                           __FUNCTION__);
            return false;
        }
        else if (bVerified)
        {
//          OTLog::vOutput(0, "%s: Success: Smart contract loaded up, and all parties have confirmed,\n"
//                         "AND their signed versions verified also.\n", __FUNCTION__);

            // Todo security: We have confirmed that all parties have provided signed copies, but we have
            // not actually verified the signatures themselves. (Though we HAVE verified that their copies of
            // the contract match the main copy.)
            // The server DOES verify this before activation, but the client should as well, just in case. Todo.
            // (I'd want MY client to do it...)
            //
            return true;
        }
        OTLog::vOutput(0, "%s: Suspicious: Smart contract loaded up, and is supposedly confirmed by all parties, "
                       "but failed to verify:\n\n%s\n\n", __FUNCTION__, strContract.Get());
    }
    // -----------------------------------------------------------
    return false;
}


bool OTAPI_Exec::Smart_IsPartyConfirmed(const std::string & THE_CONTRACT,
                                        const std::string & PARTY_NAME)  // true or false?
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to find a party with the name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            //...is he confirmed?
            //
            if (false == pParty->GetMySignedCopy().Exists())
            {
                OTLog::vOutput(1, "%s: Smart contract loaded up, and party %s was found, "
                               "but didn't find a signed copy of the agreement for that party.\n",
                               __FUNCTION__, PARTY_NAME.c_str());
            }
            else // FYI, this block comes from OTScriptable::VerifyThisAgainstAllPartiesSignedCopies.
            {
                OTScriptable * pPartySignedCopy = OTScriptable::InstantiateScriptable(pParty->GetMySignedCopy());
                OTCleanup<OTScriptable> theCopyAngel;

                if (NULL == pPartySignedCopy)
                {
                    const std::string current_party_name(pParty->GetPartyName());
                    OTLog::vError("%s: Error loading party's (%s) signed copy of agreement. Has it been executed?\n",
                                  __FUNCTION__, current_party_name.c_str());
                }
                else
                {
                    theCopyAngel.SetCleanupTarget(*pPartySignedCopy);
                    // ----------------------
                    if ( false == pScriptable->Compare(*pPartySignedCopy) )
                    {
                        const std::string current_party_name(pParty->GetPartyName());
                        OTLog::vError("%s: Suspicious: Party's (%s) signed copy of agreement doesn't match the contract.\n",
                                      __FUNCTION__, current_party_name.c_str());
                    }
                    else
                    {
                        // TODO Security: This function doesn't actually verify the party's SIGNATURE on his signed
                        // version, only that it exists and it matches the main contract.
                        //
                        // The actual signatures are all verified by the server before activation, but I'd still like the client
                        // to have the option to do so as well. I can imagine getting someone's signature on something (without
                        // signing it yourself) and then just retaining the OPTION to sign it later -- but he might not have
                        // actually signed it if he knew that you hadn't either. He'd want his client to tell him, if this were
                        // the case. Todo.

                        return true;
                    }
                }
            }
        }
    }
    // -----------------------------------------------------------
    return false;
}




// ----------------------------------------------------------
int32_t OTAPI_Exec::Smart_GetPartyCount(const std::string & THE_CONTRACT)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        const int32_t nReturnValue = static_cast<int32_t>(pScriptable->GetPartyCount());
        return nReturnValue;
    }
    // -----------------------------------------------------------
    return -1; // Error condition.
}


int32_t OTAPI_Exec::Smart_GetBylawCount(const std::string & THE_CONTRACT)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        const int32_t nReturnValue = static_cast<int32_t>(pScriptable->GetBylawCount());
        return nReturnValue;
    }
    // -----------------------------------------------------------
    return -1; // Error condition.
}


// ----------------------------------------------------------


/// returns the name of the party.
std::string OTAPI_Exec::Smart_GetPartyByIndex(const std::string & THE_CONTRACT,
                                                      const int32_t     & nIndex)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        const int32_t nTempIndex = static_cast<const int32_t>(nIndex);
        OTParty * pParty = pScriptable->GetPartyByIndex(nTempIndex); // has range-checking built-in.
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the party using index: %d\n",
                           __FUNCTION__, nTempIndex);
        }
        else // We found the party...
        {
            return pParty->GetPartyName();
        }
    }
    // -----------------------------------------------------------
    return "";
}

/// returns the name of the bylaw.
std::string OTAPI_Exec::Smart_GetBylawByIndex(const std::string & THE_CONTRACT,
                                                      const int32_t     & nIndex)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        const int32_t nTempIndex = static_cast<const int32_t>(nIndex);
        OTBylaw * pBylaw = pScriptable->GetBylawByIndex(nTempIndex); // has range-checking built-in.
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw using index: %d\n",
                           __FUNCTION__, nTempIndex);
        }
        else // We found the bylaw...
        {
            const std::string str_name(pBylaw->GetName().Get());  // Success.
            return str_name;
        }
    }
    // -----------------------------------------------------------
    return "";
}


// ----------------------------------------------------------

std::string OTAPI_Exec::Bylaw_GetLanguage(const std::string & THE_CONTRACT,
                                          const std::string & BYLAW_NAME)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to find a bylaw with the name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            const std::string str_return(NULL == pBylaw->GetLanguage() ? "error_no_language" : pBylaw->GetLanguage());
            return str_return;
        }
    }
    // -----------------------------------------------------------
    return "";
}

int32_t OTAPI_Exec::Bylaw_GetClauseCount(const std::string & THE_CONTRACT,
                                         const std::string & BYLAW_NAME)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to find a bylaw with the name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            const int32_t nReturnValue = static_cast<int32_t>(pBylaw->GetClauseCount());
            return nReturnValue;
        }
    }
    // -----------------------------------------------------------
    return (-1);
}


int32_t OTAPI_Exec::Bylaw_GetVariableCount(const std::string & THE_CONTRACT,
                                           const std::string & BYLAW_NAME)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to find a bylaw with the name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            const int32_t nReturnValue = static_cast<int32_t>(pBylaw->GetVariableCount());
            return nReturnValue;
        }
    }
    // -----------------------------------------------------------
    return (-1);
}


int32_t OTAPI_Exec::Bylaw_GetHookCount(const std::string & THE_CONTRACT,
                                       const std::string & BYLAW_NAME)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to find a bylaw with the name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            const int32_t nReturnValue = static_cast<int32_t>(pBylaw->GetHookCount());
            return nReturnValue;
        }
    }
    // -----------------------------------------------------------
    return (-1);
}


int32_t OTAPI_Exec::Bylaw_GetCallbackCount(const std::string & THE_CONTRACT,
                                           const std::string & BYLAW_NAME)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to find a bylaw with the name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            const int32_t nReturnValue = static_cast<int32_t>(pBylaw->GetCallbackCount());
            return nReturnValue;
        }
    }
    // -----------------------------------------------------------
    return (-1);
}


// ----------------------------------------------------------

std::string OTAPI_Exec::Clause_GetNameByIndex(const std::string & THE_CONTRACT,
                                              const std::string & BYLAW_NAME,
                                              const int32_t     & nIndex) // returns the name of the clause.
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            const int32_t nTempIndex = static_cast<const int32_t>(nIndex);

            OTClause * pClause = pBylaw->GetClauseByIndex(nTempIndex);

            if (NULL == pClause)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and bylaw found, but failed to retrieve the clause at index: %d\n",
                               __FUNCTION__, nTempIndex);
            }
            else // We found the clause...
            {
                const std::string str_name(pClause->GetName().Get());  // Success.
                return str_name;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}


std::string OTAPI_Exec::Clause_GetContents(const std::string & THE_CONTRACT,
                                           const std::string & BYLAW_NAME,
                                           const std::string & CLAUSE_NAME)  // returns the contents of the clause.
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
    if (CLAUSE_NAME.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"  ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            OTClause * pClause = pBylaw->GetClause(CLAUSE_NAME);

            if (NULL == pClause)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and bylaw found, but failed to retrieve the clause with name: %s\n",
                               __FUNCTION__, CLAUSE_NAME.c_str());
            }
            else // We found the clause...
            {
                const std::string str_return(pClause->GetCode());  // Success.
                return str_return;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}

// ----------------------------------------------------------

std::string OTAPI_Exec::Variable_GetNameByIndex(const std::string & THE_CONTRACT,
                                                const std::string & BYLAW_NAME,
                                                const int32_t     & nIndex) // returns the name of the variable.
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            const int32_t nTempIndex = static_cast<const int32_t>(nIndex);

            OTVariable * pVar = pBylaw->GetVariableByIndex(nTempIndex);

            if (NULL == pVar)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and bylaw found, but failed to retrieve the variable at index: %d\n",
                               __FUNCTION__, nTempIndex);
            }
            else // We found the variable...
            {
                const std::string str_name(pVar->GetName().Get());  // Success.
                return str_name;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}


std::string OTAPI_Exec::Variable_GetType(const std::string & THE_CONTRACT,
                                         const std::string & BYLAW_NAME,
                                         const std::string & VARIABLE_NAME) // returns the type of the variable.
{
	if (THE_CONTRACT.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
    if (VARIABLE_NAME.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VARIABLE_NAME"); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            OTVariable * pVar = pBylaw->GetVariable(VARIABLE_NAME);

            if (NULL == pVar)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and bylaw found, but failed to retrieve the variable with name: %s\n",
                               __FUNCTION__, VARIABLE_NAME.c_str());
            }
            else // We found the variable...
            {
                const std::string str_return(  pVar->IsInteger() ? "integer" :
                                             ( pVar->IsBool()    ? "boolean" :
                                              (pVar->IsString()  ? "string"  : "error_type" )) ); // Success.
                return str_return;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}

std::string OTAPI_Exec::Variable_GetAccess(const std::string & THE_CONTRACT,
                                           const std::string & BYLAW_NAME,
                                           const std::string & VARIABLE_NAME) // returns the access level of the variable.
{
	if (THE_CONTRACT.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
    if (VARIABLE_NAME.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VARIABLE_NAME"); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            OTVariable * pVar = pBylaw->GetVariable(VARIABLE_NAME);

            if (NULL == pVar)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and bylaw found, but failed to retrieve the variable with name: %s\n",
                               __FUNCTION__, VARIABLE_NAME.c_str());
            }
            else // We found the variable...
            {
                const std::string str_return(  pVar->IsConstant()   ? "constant"    :
                                             ( pVar->IsImportant()  ? "important"   :
                                              (pVar->IsPersistent() ? "persistent"  : "error_access" )) ); // Success.
                return str_return;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}


std::string OTAPI_Exec::Variable_GetContents(const std::string & THE_CONTRACT,
                                             const std::string & BYLAW_NAME,
                                             const std::string & VARIABLE_NAME) // returns the contents of the variable.
{
	if (THE_CONTRACT.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
    if (VARIABLE_NAME.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "VARIABLE_NAME"); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            OTVariable * pVar = pBylaw->GetVariable(VARIABLE_NAME);

            if (NULL == pVar)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and bylaw found, but failed to retrieve the variable with name: %s\n",
                               __FUNCTION__, VARIABLE_NAME.c_str());
            }
            else // We found the variable...
            {
                std::string  str_return;

                switch (pVar->GetType())
                {
                    case OTVariable::Var_String  : str_return = pVar->GetValueString(); break;
                    case OTVariable::Var_Integer : str_return = OTAPI_Exec::LongToString(static_cast<int64_t>(pVar->GetValueInteger())); break;
                    case OTVariable::Var_Bool    : str_return = pVar->GetValueBool() ? "true" : "false"; break;
                    default                      : OTLog::vError("%s: Error: Unknown variable type.\n", __FUNCTION__); break;
                }
                return str_return;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}


// ----------------------------------------------------------

std::string OTAPI_Exec::Hook_GetNameByIndex(const std::string & THE_CONTRACT,
                                            const std::string & BYLAW_NAME,
                                            const int32_t     & nIndex) // returns the name of the hook.
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            const int32_t nTempIndex = static_cast<const int32_t>(nIndex);
            const std::string str_name(pBylaw->GetHookNameByIndex(nTempIndex));
            return str_name;
        }
    }
    // -----------------------------------------------------------
    return "";
}

/// Returns the number of clauses attached to a specific hook.
int32_t OTAPI_Exec::Hook_GetClauseCount(const std::string & THE_CONTRACT,
                                        const std::string & BYLAW_NAME,
                                        const std::string & HOOK_NAME)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"  ); OT_FAIL; }
    if (HOOK_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "HOOK_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            mapOfClauses theResults;
            const bool bGotHooks = pBylaw->GetHooks(HOOK_NAME, theResults); // Look up all clauses matching a specific hook.
            const int32_t nReturnValue = bGotHooks ? static_cast<const int32_t>(theResults.size()) : (-1);
            return nReturnValue;
        }
    }
    // -----------------------------------------------------------
    return (-1);
}

/// Multiple clauses can trigger from the same hook.
/// Hook_GetClauseCount and Hook_GetClauseAtIndex allow you to iterate through them.
/// This function returns the name for the clause at the specified index.
///
std::string OTAPI_Exec::Hook_GetClauseAtIndex(const std::string & THE_CONTRACT,
                                              const std::string & BYLAW_NAME,
                                              const std::string & HOOK_NAME,
                                              const int32_t     & nIndex)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"  ); OT_FAIL; }
    if (HOOK_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "HOOK_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            mapOfClauses theResults;

            if (pBylaw->GetHooks(HOOK_NAME, theResults)) // Look up all clauses matching a specific hook.
            {
                if ((nIndex >= 0) && (nIndex < static_cast<int64_t>(theResults.size())))
                {
                    int32_t nLoopIndex = -1;

                    FOR_EACH(mapOfClauses, theResults)
                    {
                        OTClause * pClause = (*it).second;
                        OT_ASSERT(NULL != pClause);
                        // ---------------------------
                        ++nLoopIndex; // on first iteration, this is now 0.

                        if (nLoopIndex == nIndex)
                        {
                            const std::string str_return(pClause->GetName().Get());
                            return str_return;
                        }
                    }
                }
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}


// ----------------------------------------------------------
std::string OTAPI_Exec::Callback_GetNameByIndex(const std::string & THE_CONTRACT,
                                                const std::string & BYLAW_NAME,
                                                const int32_t     & nIndex) // returns the name of the callback.
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            const int32_t nTempIndex = static_cast<const int32_t>(nIndex);
            const std::string str_name(pBylaw->GetCallbackNameByIndex(nTempIndex));
            return str_name;
        }
    }
    // -----------------------------------------------------------
    return "";
}


std::string OTAPI_Exec::Callback_GetClause(const std::string & THE_CONTRACT,
                                           const std::string & BYLAW_NAME,
                                           const std::string & CALLBACK_NAME) // returns name of clause attached to callback.
{
	if (THE_CONTRACT.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (BYLAW_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"   ); OT_FAIL; }
    if (CALLBACK_NAME.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CALLBACK_NAME"); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTBylaw * pBylaw = pScriptable->GetBylaw(BYLAW_NAME);
        // -----------------------------------------------------
        if (NULL == pBylaw)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the bylaw with name: %s\n",
                           __FUNCTION__, BYLAW_NAME.c_str());
        }
        else // We found the bylaw...
        {
            OTClause * pClause = pBylaw->GetCallback(CALLBACK_NAME);

            if (NULL == pClause)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and bylaw found, but failed to retrieve the clause for callback: %s\n",
                               __FUNCTION__, CALLBACK_NAME.c_str());
            }
            else // We found the clause...
            {
                const std::string str_return(pClause->GetName().Get());
                return str_return;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}

// ----------------------------------------------------------

int32_t OTAPI_Exec::Party_GetAcctCount(const std::string & THE_CONTRACT,
                                       const std::string & PARTY_NAME)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to find a party with the name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            const int32_t nReturnValue = static_cast<int32_t>(pParty->GetAccountCount());
            return nReturnValue;
        }
    }
    // -----------------------------------------------------------
    return (-1);
}


int32_t OTAPI_Exec::Party_GetAgentCount(const std::string & THE_CONTRACT,
                                        const std::string & PARTY_NAME)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to find a party with the name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            const int32_t nReturnValue = static_cast<int32_t>(pParty->GetAgentCount());
            return nReturnValue;
        }
    }
    // -----------------------------------------------------------
    return (-1);
}


// ----------------------------------------------------------

std::string OTAPI_Exec::Party_GetID(const std::string & THE_CONTRACT,
                                    const std::string & PARTY_NAME) // returns either NymID or Entity ID. (If there is one... Contract might not be signed yet.)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to find a party with the name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            return pParty->GetPartyID();
        }
    }
    // -----------------------------------------------------------
    return "";
}


// ----------------------------------------------------------
std::string OTAPI_Exec::Party_GetAcctNameByIndex(const std::string & THE_CONTRACT,
                                                 const std::string & PARTY_NAME,
                                                 const int32_t     & nIndex) // returns the name of the clause.
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the party with name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            const int32_t nTempIndex   = static_cast<const int32_t>(nIndex);
            OTPartyAccount * pAcct = pParty->GetAccountByIndex(nTempIndex);

            if (NULL == pAcct)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and party found, but failed to retrieve the account at index: %d\n",
                               __FUNCTION__, nTempIndex);
            }
            else // We found the account...
            {
                const std::string str_name(pAcct->GetName().Get());  // Success.
                return str_name;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}



std::string OTAPI_Exec::Party_GetAcctID(const std::string & THE_CONTRACT,
                                        const std::string & PARTY_NAME,
                                        const std::string & ACCT_NAME) // returns the account ID based on the account name. (If there is one yet...)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
    if (ACCT_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"    ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the party with name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            const OTPartyAccount * pAcct = pParty->GetAccount(ACCT_NAME);

            if (NULL == pAcct)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and party found, but failed to retrieve party's account named: %s\n",
                               __FUNCTION__, ACCT_NAME.c_str());
            }
            else // We found the account...
            {
                const std::string str_return(pAcct->GetAcctID().Get());  // Success.
                return str_return;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}


std::string OTAPI_Exec::Party_GetAcctAssetID(const std::string & THE_CONTRACT,
                                             const std::string & PARTY_NAME,
                                             const std::string & ACCT_NAME) // returns the asset type ID based on the account name.
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
    if (ACCT_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"    ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the party with name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            const OTPartyAccount * pAcct = pParty->GetAccount(ACCT_NAME);

            if (NULL == pAcct)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and party found, but failed to retrieve party's account named: %s\n",
                               __FUNCTION__, ACCT_NAME.c_str());
            }
            else // We found the account...
            {
                const std::string str_return(pAcct->GetAssetTypeID().Get());  // Success.
                return str_return;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}

// ----------------------------------------------------------

std::string OTAPI_Exec::Party_GetAcctAgentName(const std::string & THE_CONTRACT,
                                               const std::string & PARTY_NAME,
                                               const std::string & ACCT_NAME) // returns the authorized agent for the named account.
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
    if (ACCT_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"    ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the party with name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            const OTPartyAccount * pAcct = pParty->GetAccount(ACCT_NAME);

            if (NULL == pAcct)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and party found, but failed to retrieve party's account named: %s\n",
                               __FUNCTION__, ACCT_NAME.c_str());
            }
            else // We found the account...
            {
                const std::string str_return(pAcct->GetAgentName().Get());  // Success.
                return str_return;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}

// ----------------------------------------------------------

std::string OTAPI_Exec::Party_GetAgentNameByIndex(const std::string & THE_CONTRACT,
                                                  const std::string & PARTY_NAME,
                                                  const int32_t     & nIndex) // returns the name of the agent.
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the party with name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            const int32_t nTempIndex   = static_cast<const int32_t>(nIndex);
            OTAgent * pAgent = pParty->GetAgentByIndex(nTempIndex);

            if (NULL == pAgent)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and party found, but failed to retrieve the agent at index: %d\n",
                               __FUNCTION__, nTempIndex);
            }
            else // We found the agent...
            {
                const std::string str_name(pAgent->GetName().Get());  // Success.
                return str_name;
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}


// ----------------------


std::string OTAPI_Exec::Party_GetAgentID(const std::string & THE_CONTRACT,
                                         const std::string & PARTY_NAME,
                                         const std::string & AGENT_NAME) // returns ID of the agent. (If there is one...)
{
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }
    if (PARTY_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"   ); OT_FAIL; }
    if (AGENT_NAME.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"   ); OT_FAIL; }
	// -----------------------------------------------------
    const OTString strContract(THE_CONTRACT);
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(strContract);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Failed trying to load smart contract from string:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
	}
	else
    {
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
        // -----------------------------------------------------
        OTParty * pParty = pScriptable->GetParty(PARTY_NAME);
        // -----------------------------------------------------
        if (NULL == pParty)
        {
            OTLog::vOutput(0, "%s: Smart contract loaded up, but failed to retrieve the party with name: %s\n",
                           __FUNCTION__, PARTY_NAME.c_str());
        }
        else // We found the party...
        {
            OTAgent * pAgent = pParty->GetAgent(AGENT_NAME);

            if (NULL == pAgent)
            {
                OTLog::vOutput(0, "%s: Smart contract loaded up, and party found, but failed to retrieve party's agent named: %s\n",
                               __FUNCTION__, AGENT_NAME.c_str());
            }
            else // We found the agent...
            {
                std::string str_return;
                OTIdentifier theAgentID;
                if (pAgent->IsAnIndividual() && pAgent->GetNymID(theAgentID))
                {
                    const OTString strTemp(theAgentID);
                    str_return = strTemp.Get();
                    return str_return;
                }
            }
        }
    }
    // -----------------------------------------------------------
    return "";
}

// ----------------------------------------------------------







// --------------------------------------------------
// ACTIVATE SMART CONTRACT   (This is a transaction, and messages the server.)
// Take an existing smart contract, which has already been set up, confirmed, etc,
// and then activate it on the server so it can start processing.
//
// See OTAPI_Exec::Create_SmartContract (etc.)
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::activateSmartContract(const std::string & SERVER_ID,
                                          const std::string & USER_ID,
                                          const std::string & THE_SMART_CONTRACT)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (THE_SMART_CONTRACT.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_SMART_CONTRACT"	); OT_FAIL; }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strContract(THE_SMART_CONTRACT);

	return OTAPI()->activateSmartContract(theServerID, theUserID, strContract);
}





// If a smart contract is already running on the server, this allows a party
// to trigger clauses on that smart contract, by name. This is NOT a transaction,
// but it DOES message the server.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::triggerClause(const std::string & SERVER_ID,
                                  const std::string & USER_ID,
                                  const int64_t & TRANSACTION_NUMBER,
                                  const std::string & CLAUSE_NAME,
                                  const std::string & STR_PARAM) // optional param
{
	if (SERVER_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())        { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (0 > TRANSACTION_NUMBER) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_FAIL; }
	if (CLAUSE_NAME.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_FAIL; }
//	if (STR_PARAM.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "STR_PARAM"			); OT_FAIL; }  // optional param
	const OTIdentifier	theServerID(SERVER_ID),
                        theUserID(USER_ID);
	const OTString		strClauseName(CLAUSE_NAME);
	const int64_t       lTransactionNum = TRANSACTION_NUMBER;
	const OTString strParam((STR_PARAM.empty()) ? "" : STR_PARAM);
	return OTAPI()->triggerClause(theServerID,
                                              theUserID,
                                              static_cast<int64_t>(lTransactionNum),
                                              strClauseName,
                                              STR_PARAM.empty() ? NULL : &strParam);
}



/*
OTAPI_Exec::Msg_HarvestTransactionNumbers

This function will load up the cron item (which is either a market offer, a payment plan,
or a SMART CONTRACT.)  UPDATE: this function operates on messages, not cron items.

Then it will try to harvest all of the closing transaction numbers for NYM_ID that are
available to be harvested from THE_CRON_ITEM. (There might be zero #s available for that
Nym, which is still a success and will return true. False means error.)

YOU MIGHT ASK:

WHY WOULD I WANT to harvest ONLY the closing numbers for the Nym, and not the OPENING
numbers as well? The answer is because for this Nym, the opening number might already
be burned. For example, if Nym just tried to activate a smart contract, and the activation
FAILED, then maybe the opening number is already gone, even though his closing numbers, on the
other hand, are still valid for retrieval. (I have to double check this.)

HOWEVER, what if the MESSAGE failed, before it even TRIED the transaction? In which case,
the opening number is still good also, and should be retrieved.

Remember, I have to keep signing for my transaction numbers until they are finally closed out.
They will appear on EVERY balance agreement and transaction statement from here until the end
of time, whenever I finally close out those numbers. If some of them are still good on a failed
transaction, then I want to retrieve them so I can use them, and eventually close them out.

==> Whereas, what if I am the PARTY to a smart contract, but I am not the actual ACTIVATOR / ORIGINATOR
(who activated the smart contract on the server).  Therefore I never sent any transaction to the
server, and I never burned my opening number. It's probably still a good #. If my wallet is not a piece
of shit, then I should have a stored copy of any contract that I signed. If it turns out in the future
that that contract wasn't activated, then I can retrieve not only my closing numbers, but my OPENING
number as well! IN THAT CASE, I would call OTAPI_Exec::HarvestAllNumbers() instead of OTAPI_Exec::HarvestClosingNumbers().

// -----------------

UPDATE: The above logic is now handled automatically in OTAPI_Exec::HarvestTransactionNumbers.
Therefore OTAPI_Exec::HarvestClosingNumbers and OTAPI_Exec::HarvestAllNumbers have been removed.

*/

bool OTAPI_Exec::Msg_HarvestTransactionNumbers(const std::string & THE_MESSAGE,
                                               const std::string & USER_ID,
                                               const bool        & bHarvestingForRetry,
                                               const bool        & bReplyWasSuccess,
                                               const bool        & bReplyWasFailure,
                                               const bool        & bTransactionWasSuccess,
                                               const bool        & bTransactionWasFailure)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }
	// -----------------------------------------------------
	if (THE_MESSAGE.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"  ); OT_FAIL; }
	if (USER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"      ); OT_FAIL; }
	// -----------------------------------------------------
	if ( (true != bHarvestingForRetry	 ) && (false != bHarvestingForRetry	  ))  { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bHarvestingForRetry"   ); OT_FAIL; }
	if ( (true != bReplyWasSuccess		 ) && (false != bReplyWasSuccess	  ))  { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bReplyWasSuccess"      ); OT_FAIL; }
	if ( (true != bReplyWasFailure		 ) && (false != bReplyWasFailure	  ))  { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bReplyWasFailure"      ); OT_FAIL; }
	if ( (true != bTransactionWasSuccess ) && (false != bTransactionWasSuccess))  { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bTransactionWasSuccess"); OT_FAIL; }
	if ( (true != bTransactionWasFailure ) && (false != bTransactionWasFailure))  { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bTransactionWasFailure"); OT_FAIL; }
	// -----------------------------------------------------
	const OTIdentifier theUserID(USER_ID);
	// -----------------------------------------------------
    OTMessage theMessage;
	const OTString  strMsg(THE_MESSAGE);
	if (!strMsg.Exists())
	{
		OTLog::vError("%s: Failed trying to load message from empty string.\n", __FUNCTION__);
		return false;
	}
	// -----------------------------------
    // Maybe it's not a message at all. Maybe it's a cron item
    // (smart contract... payment plan...)
    //
    if (strMsg.Contains("PAYMENT PLAN") || strMsg.Contains("SMARTCONTRACT"))
    {
        const OTString & strCronItem = strMsg;

        OTLog::vOutput(0, "%s: Attempting to harvest transaction numbers from cron item...\n",
                       __FUNCTION__);
		// -----------------------------------------------------
		// Unfortunately the ONLY reason we are loading up this cron item here,
		// is so we can get the server ID off of it.
		//
		OTCronItem * pCronItem = OTCronItem::NewCronItem(strCronItem);
		OTCleanup<OTCronItem> theContractAngel;
		if (NULL == pCronItem)
		{
			OTLog::vError("%s: Failed trying to load message from string.", __FUNCTION__);

			OTLog::vOutput(0, "%s: Error trying to load the cron item from string (a cron item is a smart contract, or "
				"some other recurring transaction such as a market offer, or a payment plan.) Contents:\n\n%s\n\n",
				__FUNCTION__, strCronItem.Get());
			return false;
		}
		else
			theContractAngel.SetCleanupTarget(*pCronItem);  // Auto-cleanup.
		// -----------------------------------------------------
        // NOTE:
		// If a CronItem is passed in here instead of a Message, that means the client
		// didn't even TRY to send the message. He failed before reaching that point.
		// Therefore in this one, strange case, we don't really care about all the bools
		// that were passed in here. We're just going to harvest ALL the numbers, and
		// ASSUME all the bools were false.
		// Here goes...
		//
		return OTAPI()->HarvestAllNumbers(pCronItem->GetServerID(), theUserID, strCronItem);
    }
    // ----------------------------------------------------------------
    // Maybe it's not a message at all. Maybe it's a basket exchange request that never
    // even got sent as a message...
    //
    if (strMsg.Contains("currencyBasket"))
    {
        const OTString & strBasket = strMsg;

        OTLog::vOutput(0, "%s: Attempting to harvest transaction numbers from a basket currency exchange request...\n",
                       __FUNCTION__);
		// -----------------------------------------------------
        OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__);
        if (NULL == pNym) return false;
        // ---------------------------------
        OTBasket theRequestBasket;

        if (theRequestBasket.LoadContractFromString(strBasket))
        {
            if (!theRequestBasket.IsExchanging())
            {
                OTLog::vError("%s: Error: This is apparently NOT a basket exchange request!\nContents:\n%s\n",
                              __FUNCTION__, strBasket.Get());
                return false;
            }
            // -------------------------------------------------
            // Now we need to find the account ID (so we can find the server ID...)
            //
            OTAccount *	pAccount = OTAPI()->GetAccount(theRequestBasket.GetRequestAccountID(),
                                                                   __FUNCTION__);
            if (NULL == pAccount)
            {
                const OTString strAcctID(theRequestBasket.GetRequestAccountID());
                OTLog::vError("%s: Error: Unable to find the main account based on the ID from the exchange request: %s\n",
                              __FUNCTION__, strAcctID.Get());
                return false;
            }
            // -------------------------------------------------
            // Now let's get the server ID...
            //
            OTServerContract * pServer = OTAPI()->GetServer(pAccount->GetPurportedServerID(), __FUNCTION__);

            if (NULL == pServer)
            {
                const OTString strServerID(pAccount->GetPurportedServerID());
                OTLog::vError("%s: Error: Unable to find the server based on the exchange request: %s\n",
                              __FUNCTION__, strServerID.Get());
                return false;
            }
            // -------------------------------------------------
            theRequestBasket.HarvestClosingNumbers(*pNym, pAccount->GetPurportedServerID(), true); // bSave=true
            return true;
        }
        else
            OTLog::vError("%s: Error loading original basket request.\n", __FUNCTION__);

        return false;
    }
	// ---------------------------------------------------
	else if (false == theMessage.LoadContractFromString(strMsg))
	{
        OTLog::vError("%s: Failed trying to load message from string.\n", __FUNCTION__);
        return false;
	}
	// ---------------------------------------------------
	// By this point, we have the actual message loaded up.
	//
	const bool & bSuccess = OTAPI()->Msg_HarvestTransactionNumbers(theMessage,
                                                                               theUserID,
                                                                               bHarvestingForRetry,
                                                                               bReplyWasSuccess,
                                                                               bReplyWasFailure,
                                                                               bTransactionWasSuccess,
                                                                               bTransactionWasFailure);
	return bSuccess ? true : false;
}




//bool OTAPI_Exec::HarvestClosingNumbers(const std::string & SERVER_ID,
//									const std::string & NYM_ID,
//									const std::string & THE_CRON_ITEM)
//{
//	OT_ASSERT_MSG("" != SERVER_ID, "OTAPI_Exec::HarvestClosingNumbers: Null SERVER_ID passed in.");
//	OT_ASSERT_MSG("" != NYM_ID, "OTAPI_Exec::HarvestClosingNumbers: Null NYM_ID passed in.");
//	OT_ASSERT_MSG("" != THE_CRON_ITEM, "OTAPI_Exec::HarvestClosingNumbers: Null THE_CRON_ITEM passed in.");
//	// -----------------------------------------------------
//	const OTIdentifier	theNymID(NYM_ID), theServerID(SERVER_ID);
//	const OTString		strContract(THE_CRON_ITEM);
//	// -----------------------------------------------------
//	const bool & bHarvested = OTAPI()->HarvestClosingNumbers(theServerID, theNymID, strContract);
//
//	return bHarvested ? true : false;
//}
//
//
// NOTE: usually you will want to call OTAPI_Exec::HarvestClosingNumbers, since the Opening number is usually
// burned up from some failed transaction or whatever. You don't want to harvest the opening number usually,
// just the closing numbers. (If the opening number is burned up, yet you still harvest it, then your OT wallet
// will end up using that number again on some other transaction, which will obviously then fail since the number
// isn't good anymore.)
// This function is only for those cases where you are sure that the opening transaction # hasn't been burned yet,
// such as when the message failed and the transaction wasn't attempted (because it never got that far) or such as
// when the contract simply never got signed or activated by one of the other parties, and so you want to claw your
// #'s back, and since in that case your opening number is still good, you would use the below function to get it back.
//
//bool OTAPI_Exec::HarvestAllNumbers(const std::string & SERVER_ID,
//								const std::string & NYM_ID,
//								const std::string & THE_CRON_ITEM)
//{
//	OT_ASSERT_MSG("" != SERVER_ID, "OTAPI_Exec::HarvestAllNumbers: Null SERVER_ID passed in.");
//	OT_ASSERT_MSG("" != NYM_ID, "OTAPI_Exec::HarvestAllNumbers: Null NYM_ID passed in.");
//	OT_ASSERT_MSG("" != THE_CRON_ITEM, "OTAPI_Exec::HarvestAllNumbers: Null THE_CRON_ITEM passed in.");
//	// -----------------------------------------------------
//	const OTIdentifier	theNymID(NYM_ID), theServerID(SERVER_ID);
//	const OTString		strContract(THE_CRON_ITEM);
//	// -----------------------------------------------------
//	const bool & bHarvested = OTAPI()->HarvestAllNumbers(theServerID, theNymID, strContract);
//
//	return bHarvested ? true : false;
//}







// -----------------------------------------------------------------
// LOAD PUBLIC KEY (of other users, where no private key is available)
// This is the "address book" versus the private Nym.
// If nothing found in the address book, it still tries to load
// a Private Nym (just to get the pubkey from it.)
// -- from local storage
//
// Return as STRING (NOT escaped.)
//
// Users will most likely store public keys of OTHER users, and they will need
// to load those from time to time, especially to verify signatures, etc.
//
std::string OTAPI_Exec::LoadPubkey_Encryption(const std::string & USER_ID) // returns "", or a public key.
{
	if (USER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"); OT_FAIL; }
	// ---------------------------------------------------------
	OTString strPubkey; // For the output
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     NYM_ID(USER_ID);
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(NYM_ID, false, __FUNCTION__, &thePWData); // This tries to get, then tries to load as public, then tries to load as private.
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
	if (false == pNym->GetPublicEncrKey().GetPublicKey(strPubkey, false)) // bEscaped defaults to true. 6/13/12
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "%s: Failure retrieving encryption pubkey from Nym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else // success
	{
		std::string pBuf = strPubkey.Get();
		return pBuf;
	}
	return "";
}

std::string OTAPI_Exec::LoadPubkey_Signing(const std::string & USER_ID) // returns "", or a public key.
{
	if (USER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"); OT_FAIL; }
	// ---------------------------------------------------------
	OTString strPubkey; // For the output
	// ---------------------------------------------------------
    OTPasswordData   thePWData(OT_PW_DISPLAY);
	OTIdentifier     NYM_ID(USER_ID);
    OTPseudonym    * pNym = OTAPI()->GetOrLoadNym(NYM_ID, false, __FUNCTION__, &thePWData); // This tries to get, then tries to load as public, then tries to load as private.
    if (NULL == pNym) return "";
	// ---------------------------------------------------------
    if (false == pNym->GetPublicSignKey().GetPublicKey(strPubkey, false)) // bEscaped defaults to true. 6/13/12
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "%s: Failure retrieving signing pubkey from Nym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else // success
	{
		std::string pBuf = strPubkey.Get();
		return pBuf;
	}
	return "";
}



// -----------------------------------------------------------------
// LOAD USER PUBLIC KEY  -- from local storage
//
// (return as STRING)
//
std::string OTAPI_Exec::LoadUserPubkey_Encryption(const std::string & USER_ID) // returns "", or a public key.
{
	if (USER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"); OT_FAIL; }
    // -----------------------------------------------------------------
	OTString strPubkey; // For the output
    // -----------------------------------------------------------------
	OTIdentifier	NYM_ID(USER_ID);
	OTPseudonym   * pNym = OTAPI()->GetOrLoadPrivateNym(NYM_ID); // No need to cleanup.
	if (NULL == pNym) return "";
    // -----------------------------------------------------------------
	if (false == pNym->GetPublicEncrKey().GetPublicKey(strPubkey))
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "%s: Failure retrieving encryption pubkey from Nym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else // success
	{
		std::string pBuf = strPubkey.Get();
		return pBuf;
	}
	return "";
}

std::string OTAPI_Exec::LoadUserPubkey_Signing(const std::string & USER_ID) // returns "", or a public key.
{
	if (USER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"); OT_FAIL; }
    // -----------------------------------------------------------------
	OTString strPubkey; // For the output
    // -----------------------------------------------------------------
	OTIdentifier	NYM_ID(USER_ID);
	OTPseudonym   * pNym = OTAPI()->GetOrLoadPrivateNym(NYM_ID); // No need to cleanup.
	if (NULL == pNym) return "";
    // -----------------------------------------------------------------
    if (false == pNym->GetPublicSignKey().GetPublicKey(strPubkey))
	{
		OTString strNymID(NYM_ID);
		OTLog::vOutput(0, "%s: Failure retrieving signing pubkey from Nym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else // success
	{
		std::string pBuf = strPubkey.Get();
		return pBuf;
	}
	return "";
}


// ------------------------------------------------------------------------
//
// Verify that USER_ID (including its Private Key) is an
// available and verified user in local storage.
//
// Loads the user's private key, verifies, then returns true or false.
//
bool OTAPI_Exec::VerifyUserPrivateKey(const std::string & USER_ID) // returns bool
{
	if (USER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"); OT_FAIL; }
    // -----------------------------------------------------------------
	OTIdentifier	NYM_ID(USER_ID);
	OTPseudonym   * pNym = OTAPI()->GetOrLoadPrivateNym(NYM_ID); // No need to cleanup.
	if (NULL == pNym) return false;
    // -----------------------------------------------------------------
    return true;
}



// --------------------------------------------------
//
// Is Mint32_t Still Good ?   true  (1) == Yes, this mint32_t is still good.
//                        false (0) == No: expired or other error.
//
bool OTAPI_Exec::Mint_IsStillGood(const std::string & SERVER_ID,
								const std::string & ASSET_TYPE_ID)
{
	if (SERVER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"     ); OT_FAIL; }
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theAssetID(ASSET_TYPE_ID);
	// -----------------------------------------------------
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTMint * pMint = OTAPI()->LoadMint(theServerID, theAssetID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's "".

	if (NULL == pMint)
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadMint.\nServer: %s\n Asset Type: %s\n",
                       __FUNCTION__, SERVER_ID.c_str(), ASSET_TYPE_ID.c_str());
	else // success
	{
		bool bExpired = pMint->Expired();

		if (!bExpired)
			return true;
	}
	// -----------------------------------------------------
	return false;
}



std::string OTAPI_Exec::LoadMint(const std::string & SERVER_ID,
							const std::string & ASSET_TYPE_ID) // returns "", or a mint
{
	if (SERVER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"     ); OT_FAIL; }
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTMint * pMint = OTAPI()->LoadMint(theServerID, theAssetID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's "".

	if (NULL == pMint)
		OTLog::vOutput(0, "OTAPI_Exec::LoadMint: Failure calling OT_API::LoadMint.\nServer: %s\n Asset Type: %s\n",
                       __FUNCTION__, SERVER_ID.c_str(), ASSET_TYPE_ID.c_str());
	else // success
	{
		OTString strOutput(*pMint); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}
	return "";
}


std::string OTAPI_Exec::LoadAssetContract(const std::string & ASSET_TYPE_ID) // returns "", or an asset contract
{
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null ASSET_TYPE_ID passed in!\n", __FUNCTION__); OT_FAIL; }

	const OTIdentifier theAssetID(ASSET_TYPE_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTAssetContract * pContract = OTAPI()->LoadAssetContract(theAssetID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAssetContract>	theAngel(pContract); // I pass the pointer, in case it's "".

	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadAssetContract.\n Asset Type: %s\n",
                       __FUNCTION__, ASSET_TYPE_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pContract); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}
	return "";
}


std::string OTAPI_Exec::LoadServerContract(const std::string & SERVER_ID) // returns "", or an asset contract
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null SERVER_ID passed in!\n", __FUNCTION__); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTServerContract * pContract = OTAPI()->LoadServerContract(theServerID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTServerContract>	theAngel(pContract); // I pass the pointer, in case it's "".

	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadServerContract.\nServer ID: %s\n",
                       __FUNCTION__, SERVER_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pContract); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}
	return "";
}


// --------------------------------------------------------------
// LOAD ACCOUNT / INBOX / OUTBOX   --  (from local storage)
//
// Loads an acct, or inbox or outbox, based on account ID, (from local storage)
// and returns it as string (or returns "" if it couldn't load it.)
//
std::string OTAPI_Exec::LoadAssetAccount(const std::string & SERVER_ID,
									const std::string & USER_ID,
									const std::string & ACCOUNT_ID) // Returns "", or an account.
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTAccount * pAccount = OTAPI()->LoadAssetAccount(theServerID, theUserID, theAccountID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAccount>	theAngel(pAccount); // I pass the pointer, in case it's "".

	if (NULL == pAccount)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadAssetAccount.\nAccount ID: %s\n",
                       __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pAccount); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}
	return "";
}

// -----------------------------------------------------------------------------


// Some server replies (to your messages) are so important that a notice is dropped
// into your Nymbox with a copy of the server's reply. It's called a replyNotice.
// Since the server is usually replying to a message, I've added this function for
// quickly looking up the message reply, if it's there, based on the requestNumber.
// This is the only example in the entire OT API where a Transaction is looked-up from
// a ledger, based on a REQUEST NUMBER. (Normally transactions use transaction numbers,
// and messages use request numbers. But in this case, it's a transaction that carries
// a copy of a message.)
// Note: Make sure you call this AFTER you download the box receipts, but BEFORE
// you process the Nymbox (because the reply notice will have disappeared.) Basically this
// function will be used for cases where you missed a server reply, and you need to
// search your Nymbox and see if a copy of the missed reply is still there. (Which it
// won't be, once you process the box.)
//
std::string OTAPI_Exec::Nymbox_GetReplyNotice(const std::string & SERVER_ID,
                                              const std::string & USER_ID,
                                              const int64_t     & REQUEST_NUMBER) // returns replyNotice transaction by requestNumber.
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SERVER_ID"      ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "USER_ID"        ); OT_FAIL; }
	if (0 > REQUEST_NUMBER) { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	const int64_t lRequestNumber = REQUEST_NUMBER;
	// -----------------------------------------
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.

	OTLedger * pLedger = OTAPI()->LoadNymboxNoVerify(theServerID, theUserID);
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadNymboxNoVerify.\n", __FUNCTION__);
		return "";
	}
	// -----------------------------------
	OTTransaction * pTransaction = pLedger->GetReplyNotice(static_cast<int64_t>(lRequestNumber));
	// No need to cleanup this transaction, the ledger owns it already.

	if (NULL == pTransaction)
	{
		OTLog::vOutput(4, "%s: No replyNotice transactions found in ledger with request number: %lld\n", __FUNCTION__, lRequestNumber);
		return ""; // Maybe he was just looking; this isn't necessarily an error.
	}
	// -----------------------------------
	// At this point, I actually have the transaction pointer to the replyNotice,
	// so let's return it in string form...
	//
	const int64_t lTransactionNum = pTransaction->GetTransactionNum();

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point32_t with abbreviated transactions in a ledger is that they
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//

	 OTString strOutput(*pTransaction); // we only have the Abbreviated, so we have to use this one.

	if (pTransaction->IsAbbreviated())
	{
		pLedger->LoadBoxReceipt(static_cast<int64_t>(lTransactionNum));
		OTTransaction * pFullTransaction = pLedger->GetTransaction(static_cast<int64_t>(lTransactionNum));
		// -------------------------

		if (NULL != pFullTransaction)
		{
			strOutput.Release();
			strOutput.zeroMemory();
			strOutput.Set(*pFullTransaction); // we have the FullTransaction, lets use that one.
		}
		else // NULL == pFullTransaction
		{
			OTLog::vError("%s: good index but uncovered \"\" pointer after trying to load full "
				"version of receipt (from abbreviated.) Thus, saving abbreviated version instead, "
				"so I can still return SOMETHING.\n", __FUNCTION__);
			// ----------------------------------
			OTPseudonym * pNym = OTAPI()->GetNym(theUserID, __FUNCTION__);
			if (NULL == pNym) return "";
			// -------------------------
			pTransaction->ReleaseSignatures();
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			// ------------------------
		}
		strOutput.Release();
		pTransaction->SaveContractRaw(strOutput); // if it was abbreviated before, now it either IS the box receipt, or it's the abbreviated version.
	}
	// ------------------------------------------------
	// We return the abbreviated version because the developer using the OT API
	// needs to know if that receipt is there, whether it's abbreviated or not.
	// So rather than passing "" when it's abbreviated, and thus leading him
	// astray, we give him the next-best thing: the abbreviated version. That
	// way at least he knows for sure that the receipt is there, the one he is
	// asking about.

	std::string pBuf = strOutput.Get();

	return pBuf;
}



// If the client-side has ALREADY seen the server's reply to a specific
// request number, he stores that number in a list which can be queried
// using this function.  A copy of that list is sent with nearly every request
// message sent to the server.  This way the server can see which replies you
// have already received. The server will mirror every number it sees (it sends
// its own list in all its replies.) Whenever you see a number mirrored in the
// server's reply, that means the server now knows you got its original reply
// (the one referenced by the number) and the server removed any replyNotice
// of that from your Nymbox (so you don't have to download it.) Basically that
// means you can go ahead and remove it from your list, and once you do, the server
// will remove its matching copy as well.
//
// *** When you are downloading your box receipts, you can skip any receipts where
// you have ALREADY seen the reply. So you can use this function to see if you already
// saw it, and if you did, then you can skip downloading that box receipt.
// Warning: this function isn't "perfect", in the sense that it cannot tell you definitively
// whether you have actually seen a server reply, but it CAN tell you if you have seen
// one until it finishes the above-described protocol (it will work in that way, which is
// how it was intended.) But after that, it will no int64_ter know if you got the reply since
// it has removed it from its list.
//
bool OTAPI_Exec::HaveAlreadySeenReply(const std::string & SERVER_ID,
									  const std::string & USER_ID,
									  const int64_t & REQUEST_NUMBER) // returns bool
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (0 > REQUEST_NUMBER) { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER" ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID);
	OTIdentifier theUserID(USER_ID);

	const int64_t lRequestNumber = REQUEST_NUMBER;

	// const std::string & strFunc = "OTAPI_Exec::HaveAlreadySeenReply";
	// -----------------------------------------
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.

	const bool & bTemp = OTAPI()->HaveAlreadySeenReply(theServerID, theUserID, static_cast<int64_t>(lRequestNumber));
	return bTemp;
}


// -----------------------------------------------------------------------------



std::string OTAPI_Exec::LoadNymbox(const std::string & SERVER_ID,
                                   const std::string & USER_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadNymbox(theServerID, theUserID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadNymbox.\n", __FUNCTION__);
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}



std::string OTAPI_Exec::LoadNymboxNoVerify(const std::string & SERVER_ID,
									       const std::string & USER_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadNymboxNoVerify(theServerID, theUserID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadNymboxNoVerify.\n", __FUNCTION__);
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




std::string OTAPI_Exec::LoadInbox(const std::string & SERVER_ID,
                                  const std::string & USER_ID,
                                  const std::string & ACCOUNT_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadInbox(theServerID, theUserID, theAccountID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadInbox.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




std::string OTAPI_Exec::LoadInboxNoVerify(const std::string & SERVER_ID,
                                          const std::string & USER_ID,
                                          const std::string & ACCOUNT_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadInboxNoVerify(theServerID, theUserID, theAccountID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadInboxNoVerify.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




std::string OTAPI_Exec::LoadOutbox(const std::string & SERVER_ID,
                                   const std::string & USER_ID,
                                   const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadOutbox(theServerID, theUserID, theAccountID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadOutbox().\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




std::string OTAPI_Exec::LoadOutboxNoVerify(const std::string & SERVER_ID,
                                           const std::string & USER_ID,
                                           const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadOutboxNoVerify(theServerID, theUserID, theAccountID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadOutboxNoVerify.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




// --------------------------------------------------------------




// --------------------------------------------------------------


std::string OTAPI_Exec::LoadPaymentInbox(const std::string & SERVER_ID,
                                         const std::string & USER_ID) // Returns "", or an inbox.
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadPaymentInbox(theServerID, theUserID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadPaymentInbox.\n User ID: %s\n", __FUNCTION__, USER_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




std::string OTAPI_Exec::LoadPaymentInboxNoVerify(const std::string & SERVER_ID,
                                                 const std::string & USER_ID) // Returns "", or a paymentInbox.
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadPaymentInboxNoVerify(theServerID, theUserID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadPaymentInboxNoVerify.\nUser ID: %s\n", __FUNCTION__, USER_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}





// --------------------------------------------------------------



std::string OTAPI_Exec::LoadRecordBox(const std::string & SERVER_ID,
                                      const std::string & USER_ID,
                                      const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadRecordBox(theServerID, theUserID, theAccountID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadRecordBox.\n",__FUNCTION__);
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}
	return "";
}


std::string OTAPI_Exec::LoadRecordBoxNoVerify(const std::string & SERVER_ID,
                                              const std::string & USER_ID,
                                              const std::string & ACCOUNT_ID)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadRecordBoxNoVerify(theServerID, theUserID, theAccountID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadRecordBoxNoVerify.\n", __FUNCTION__);
	}
	else // success
	{
		const OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}
	return "";
}

// --------------------------------------------------------------

std::string OTAPI_Exec::LoadExpiredBox(const std::string & SERVER_ID,
                                       const std::string & USER_ID)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadExpiredBox(theServerID, theUserID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadExpiredBox.\n",__FUNCTION__);
	}
	else // success
	{
		OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}
	return "";
}

// --------------------------------------------------------------

std::string OTAPI_Exec::LoadExpiredBoxNoVerify(const std::string & SERVER_ID,
                                               const std::string & USER_ID) // Returns NULL, or a ExpiredBox.
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.
	OTLedger * pLedger = OTAPI()->LoadExpiredBoxNoVerify(theServerID, theUserID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's "".

	if (NULL == pLedger)
	{
		OTLog::vOutput(1, "%s: Failure calling OT_API::LoadExpiredBoxNoVerify.\n", __FUNCTION__);
	}
	else // success
	{
		const OTString strOutput(*pLedger); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}
	return "";
}

// --------------------------------------------------------------

bool OTAPI_Exec::RecordPayment(const std::string & SERVER_ID,
                               const std::string & USER_ID,
                               const bool        & bIsInbox, // true == payments inbox. false == payments outbox.
                               const int32_t     & nIndex,   // removes payment instrument (from payments in or out box) and moves to record box.
                               const bool        & bSaveCopy) // If false, then will NOT save a copy to record box.
{
    OT_ASSERT(nIndex >= 0);
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID  (USER_ID);

    return OTAPI()->RecordPayment(theServerID, theUserID, bIsInbox, nIndex, bSaveCopy);
}

// --------------------------------------------------------------

bool OTAPI_Exec::ClearRecord(const std::string & SERVER_ID,
                             const std::string & USER_ID,
                             const std::string & ACCOUNT_ID, // USER_ID can be passed here as well.
                             const int32_t     & nIndex,
                             const bool        & bClearAll)  // if true, nIndex is ignored.
{
    OT_ASSERT(nIndex >= 0);
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }

    const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID  (USER_ID);
	const OTIdentifier theAcctID  (ACCOUNT_ID);

    return OTAPI()->ClearRecord(theServerID, theUserID, theAcctID, nIndex, bClearAll);
}

// --------------------------------------------------------------

bool OTAPI_Exec::ClearExpired(const std::string & SERVER_ID,
                              const std::string & USER_ID,
                              const int32_t     & nIndex,
                              const bool        & bClearAll) // if true, nIndex is ignored.
{
    OT_ASSERT(nIndex >= 0);
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }

    const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID  (USER_ID);

    return OTAPI()->ClearExpired(theServerID, theUserID, nIndex, bClearAll);
}

// --------------------------------------------------------------

/**
SO HOW WOULD YOU **USE** THIS?  To process your inbox...

-- First you call OTAPI_Exec::getInbox to grab the latest inbox from the server.
(You will also want to call OTAPI_Exec::getOutbox as well as
OTAPI_Exec::getAccount, since you need to have the latest versions of
those files, or your balance agreement will be calculated wrong,
causing your transaction to fail.)

-- Then you call OTAPI_Exec::LoadInbox to load it from local storage.

During this time, your user has the opportunity to peruse the
inbox, and to decide which transactions therein he wishes to
accept or reject.  If you want to display the inbox items on
the screen, use these functions to loop through them:
OTAPI_Exec::Ledger_GetCount
OTAPI_Exec::Ledger_GetTransactionByIndex
OTAPI_Exec::Ledger_GetTransactionIDByIndex

You will probably ask me for more introspection on the transactions themselves.
(Just ask -- No problem.)  Here's what you have right now:
OTAPI_Exec::Transaction_GetType

-- Then call OTAPI_Exec::Ledger_CreateResponse in order to create a
'response' ledger for that inbox, which will be sent to the server.

-- Then call OTAPI_Exec::Ledger_GetCount (pass it the inbox) to find out how many
transactions are inside of it.  Use that count to LOOP through them...

-- Use OTAPI_Exec::Ledger_GetTransactionByIndex to grab each transaction as
you iterate through the inbox.

-- Call OTAPI_Exec::Transaction_CreateResponse to create a response for each
transaction, accepting or rejecting it, and adding it to the response
ledger.

-- Penultimately, call OTAPI_Exec::Ledger_FinalizeResponse() which will create
a Balance Agreement for the ledger.

-- Finally, call OTAPI_Exec::processInbox to send that response ledger to the
server and process the various items.
*/


// Returns number of transactions within, or -1 for error.
int32_t OTAPI_Exec::Ledger_GetCount(const std::string & SERVER_ID,
                                    const std::string & USER_ID,
                                    const std::string & ACCOUNT_ID,
                                    const std::string & THE_LEDGER)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }
	if (THE_LEDGER.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	return theLedger.GetTransactionCount();
}




// -----------------------------------------------------------------------
// Creates a new 'response' ledger, set up with the right Server ID, etc, so you
// can add the 'response' items to it, one by one. (Pass in the original ledger
// that you are responding to, as it uses the data from it to set up the response.)
// The original ledger is your inbox. Inbox receipts are the only things you would
// ever create a "response" to, as part of your "process inbox" process.
//
std::string OTAPI_Exec::Ledger_CreateResponse(const std::string & SERVER_ID,
                                              const std::string & USER_ID,
                                              const std::string & ACCOUNT_ID,
                                              const std::string & ORIGINAL_LEDGER)
{
	if (SERVER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"       ); OT_FAIL; }
	if (USER_ID.empty())         { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"         ); OT_FAIL; }
	if (ACCOUNT_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"      ); OT_FAIL; }
	if (ORIGINAL_LEDGER.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ORIGINAL_LEDGER" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------
	// Let's load up the ledger (an inbox) that was passed in...
	OTString strOriginalLedger(ORIGINAL_LEDGER);
	OTLedger theOriginalLedger(theUserID, theAccountID, theServerID);

	if (false == theOriginalLedger.LoadLedgerFromString(strOriginalLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	if (false == theOriginalLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error verifying original ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	// By this point, the ledger is loaded properly from the string,
	// Let's create the response to it.
	OTLedger * pResponseLedger = OTLedger::GenerateLedger(theUserID, theAccountID,
		theServerID, OTLedger::message);// bCreateFile=false
	OTCleanup<OTLedger> theResponseAngel(pResponseLedger); // Angel will handle cleanup.

	if (NULL == pResponseLedger)
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error generating response ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	pResponseLedger->SignContract(*pNym);
	pResponseLedger->SaveContract();

	OTString strOutput(*pResponseLedger); // For the output

	std::string pBuf = strOutput.Get();

	return pBuf;
}



// -------------------------------------------------------------------------
// Lookup a transaction or its ID (from within a ledger) based on index or
// transaction number.
//
// The transaction number is returned as a string, because I return ALL int64_t
// ints as a string (in the API.)  In C, you can just call StringToLong to convert it back.
// This makes it easier for the guys who use scripting languages. (This file is
// primarily for them. If you are lower-level, you should use OpenTransactions.h/.cpp
// and then use this one as a model for how to do it. Or use this one if you insist
// on straight C, since all these functions are extern "C".)
//
std::string OTAPI_Exec::Ledger_GetTransactionByIndex(const std::string & SERVER_ID,
                                                     const std::string & USER_ID,
                                                     const std::string & ACCOUNT_ID,
                                                     const std::string & THE_LEDGER,
                                                     const int32_t & nIndex) // returns transaction by index (from ledger)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_FAIL; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	//	std::set<int64_t> setUnloaded;

	if (	!theLedger.LoadLedgerFromString(strLedger)
//		||	!theLedger.LoadBoxReceipts(&setUnloaded)	// This is done below, for the individual transaction, for better optimization.
			)
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string, or loading box receipts subsequently. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded successfully.

	if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("%s: out of bounds: %d\n", __FUNCTION__, nIndex);
		return ""; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(nIndex);
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.

	if (NULL == pTransaction)
	{
		OTLog::vError("%s: Failure: good index but uncovered \"\" pointer: %d\n", __FUNCTION__, nIndex);
		return ""; // Weird.
	}

	const int64_t lTransactionNum = pTransaction->GetTransactionNum();
	// At this point, I actually have the transaction pointer, so let's return it in string form...

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point32_t with abbreviated transactions in a ledger is that they
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//
	if (pTransaction->IsAbbreviated())
	{
		theLedger.LoadBoxReceipt(static_cast<int64_t>(lTransactionNum)); // I don't check return val here because I still want it to send the abbreviated form, if this fails.
		pTransaction = theLedger.GetTransaction(static_cast<int64_t>(lTransactionNum));
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good index but uncovered \"\" pointer after trying to load full version of receipt (from abbreviated): %d\n", __FUNCTION__, nIndex);
			return ""; // Weird.
		}
		// I was doing this when it was abbreviated. But now (above) I just
		// load the box receipt itself. (This code is a hack that creates a
		// serialized abbreviated version.)
		//		OTPseudonym * pNym = OTAPI()->GetNym(theUserID, "OTAPI_Exec::Ledger_GetTransactionByIndex");
		//		if (NULL == pNym) return "";
		//		// -------------------------
		//		pTransaction->ReleaseSignatures();
		//		pTransaction->SignContract(*pNym);
		//		pTransaction->SaveContract();
	}
	// ------------------------------------------------

	const OTString strOutput(*pTransaction); // For the output
	std::string pBuf = strOutput.Get();



	return pBuf;
}



// Returns transaction by ID (transaction numbers are int64_t ints, and thus
// they are passed as strings in this OT high-level API.)
// Note: If this function returns "" for a transaction you KNOW is on
// the ledger, then you probably just need to download it. (The box receipts
// are stored in separate files and downloaded separately as well.)
//
std::string OTAPI_Exec::Ledger_GetTransactionByID(const std::string & SERVER_ID,
											 const std::string & USER_ID,
											 const std::string & ACCOUNT_ID,
											 const std::string & THE_LEDGER,
											 const int64_t & TRANSACTION_NUMBER)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_FAIL; }
	if (0 > TRANSACTION_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_FAIL; }

	const int64_t lTransactionNumber = TRANSACTION_NUMBER;

	if (0 > lTransactionNumber) { OTLog::vError("%s: Bad transaction number passed in (negative value)\n", __FUNCTION__); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);

	// -----------------------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// At this point, I know theLedger loaded successfully.
	// -----------------------------------------------------

	OTTransaction * pTransaction = theLedger.GetTransaction(static_cast<int64_t>(lTransactionNumber));
	// No need to cleanup this transaction, the ledger owns it already.

	if (NULL == pTransaction)
	{
		OTLog::vOutput(0, "%s: No transaction found in ledger with that number: %lld.\n", __FUNCTION__, lTransactionNumber);
		return ""; // Maybe he was just looking; this isn't necessarily an error.
	}
	// -----------------------------------------------------

	// At this point, I actually have the transaction pointer, so let's return it in string form...
	//
	const int64_t lTransactionNum = pTransaction->GetTransactionNum();
	OT_ASSERT(lTransactionNum == lTransactionNumber);

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point32_t with abbreviated transactions in a ledger is that they
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//
	if (pTransaction->IsAbbreviated())
	{
		// First we see if we are able to load the full version of this box receipt.
		// (Perhaps it has already been downloaded sometime in the past, and simply
		// needs to be loaded up. Worth a shot.)
		//
		const bool & bLoadedBoxReceipt = theLedger.LoadBoxReceipt(static_cast<int64_t>(lTransactionNum)); // I still want it to send the abbreviated form, if this fails.

		// Grab this pointer again, since the object was re-instantiated
		// in the case of a successful LoadBoxReceipt.
		//
		if (bLoadedBoxReceipt)
			pTransaction = theLedger.GetTransaction(static_cast<int64_t>(lTransactionNum));

		// (else if false == bLoadedBoxReceipt, then pTransaction ALREADY points
		// to the abbreviated version.)
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good ID, but uncovered \"\" pointer after trying to load full version "
				"of receipt (from abbreviated.) Probably just need to download this one...\n",
				__FUNCTION__);
			return ""; // Weird.
		}
		// If it's STILL abbreviated after the above efforts, then there's nothing else I can do
		// except return the abbreviated version. The caller may still need the info available on
		// the abbreviated version. (And the caller may yet download the full version...)
		//
		else if (pTransaction->IsAbbreviated())
		{
			OTPseudonym * pNym = OTAPI()->GetNym(theUserID, __FUNCTION__);
			if (NULL == pNym) return ""; // Weird.
			// -------------------------
			pTransaction->ReleaseSignatures();
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
		}
	}
	// ------------------------------------------------
	const OTString strOutput(*pTransaction); // For the output
	std::string pBuf = strOutput.Get();

	return pBuf;
}


// -------------------------------------------------------------------------
// OTAPI_Exec::Ledger_GetInstrument (by index)
//
// Lookup a financial instrument (from within a transaction that is inside
// a paymentInbox ledger) based on index.
/*
sendUserInstrument does this:
-- Puts instrument (a contract string) as encrypted Payload on an OTMessage(1).
-- Also puts instrument (same contract string) as CLEAR payload on an OTMessage(2).
-- (1) is sent to server, and (2) is added to Outpayments messages.
-- (1) gets added to recipient's Nymbox as "in ref to" string on a "instrumentNotice" transaction.
-- When recipient processes Nymbox, the "instrumentNotice" transaction (containing (1) in its "in ref to"
field) is copied and added to the recipient's paymentInbox.
-- When recipient iterates through paymentInbox transactions, they are ALL "instrumentNotice" OTMessages.
Each transaction contains an OTMessage in its "in ref to" field, and that OTMessage object contains an
encrypted payload of the instrument itself (a contract string.)
-- When sender gets Outpayments contents, the original instrument (contract string) is stored IN THE
CLEAR as payload on an OTMessage.

THEREFORE:
TO EXTRACT INSTRUMENT FROM PAYMENTS INBOX:
-- Iterate through the transactions in the payments inbox.
-- (They should all be "instrumentNotice" transactions.)
-- Each transaction contains (1) OTMessage in the "in ref to" field, which in turn contains an encrypted
instrument in the messagePayload field.
-- *** Therefore, this function, based purely on ledger index (as we iterate) extracts the
OTMessage from the Transaction "in ref to" field (for the transaction at that index), then decrypts
the payload on that message and returns the decrypted cleartext.
*/



// DONE:  Move most of the code in the below function into OTLedger::GetInstrument.
//
// DONE: Finish writing OTClient::ProcessDepositResponse



std::string OTAPI_Exec::Ledger_GetInstrument(const std::string & SERVER_ID,
                                             const std::string & USER_ID,
                                             const std::string & ACCOUNT_ID,
                                             const std::string & THE_LEDGER,
                                             const int32_t     & nIndex) // returns financial instrument by index.
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" );  OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID" );    OT_FAIL; }
	if (ACCOUNT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID" ); OT_FAIL; }
	if (THE_LEDGER.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetNym(theUserID, __FUNCTION__);
	if (NULL == pNym) return "";
	// -------------------------
	OTString strLedger(THE_LEDGER);
	OTLedger theLedger(theUserID, theAccountID, theServerID);
//	std::set<int64_t> setUnloaded;

	if (	!theLedger.LoadLedgerFromString(strLedger)
//		||	!theLedger.LoadBoxReceipts(&setUnloaded)	// This is now done below, for the individual transaction, for better optimization.
			)                                           // Update: now in the theLedger.GetInstrument call.
	{
		OTString strUserID(theUserID);
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. UserID / Acct ID: %s / %s\n", __FUNCTION__,
			strUserID.Get(), strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	// At this point, I know theLedger loaded successfully.
    //
    OTPayment * pPayment = theLedger.GetInstrument(*pNym, nIndex); // caller is responsible to delete.
    OTCleanup<OTPayment> thePaymentAngel(pPayment);

    if ((NULL == pPayment) || !pPayment->IsValid())
    {
        OTLog::vOutput(0, "%s: theLedger.GetInstrument either returned NULL, or an invalid instrument.\n",
                       __FUNCTION__);
    }
    else
    {
        // NOTE: instead of loading up an OTPayment, and then loading a cheque/purse/etc from it,
        // we just send the cheque/purse/etc directly and use it to construct the OTPayment.
        // (Saves a step.)
        //
        OTString strPaymentContents;

        if (false == pPayment->GetPaymentContents(strPaymentContents))
        {
            OTLog::vOutput(0, "%s: Failed retrieving payment instrument from OTPayment object.\n",
                           __FUNCTION__);
            return "";
        }
        // ------------------------------------------------------
        std::string gBuf = strPaymentContents.Get();
        return gBuf;
    }

	return "";
}




/*

// returns the message, optionally with Subject: as first line.

 std::string OTAPI_Exec::GetNym_MailContentsByIndex(const std::string & NYM_ID, const int32_t & nIndex)
{
    OT_ASSERT_MSG("" != NYM_ID, "Null NYM_ID passed to OTAPI_Exec::GetNym_MailContentsByIndex");

    std::string strFunc = "OTAPI_Exec::GetNym_MailContentsByIndex";
    // -------------------------
    OTIdentifier	theNymID(NYM_ID);
    OTPseudonym * pNym = OTAPI()->GetNym(theNymID, strFunc);
    if (NULL == pNym) return "";
    // -------------------------
    OTMessage * pMessage = pNym->GetMailByIndex(nIndex);

    if (NULL != pMessage)
    {
        // SENDER:    pMessage->m_strNymID
        // RECIPIENT: pMessage->m_strNymID2
        // MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
        //
        OTEnvelope	theEnvelope;
        OTString	strEnvelopeContents;

        // Decrypt the Envelope.
        if (theEnvelope.SetAsciiArmoredData(pMessage->m_ascPayload) &&
            theEnvelope.Open(*pNym, strEnvelopeContents))
        {
            std::string pBuf = strEnvelopeContents.Get();

            return pBuf;
        }
    }
    return "";
}

*/


// Returns a transaction number, or -1 for error.
int64_t OTAPI_Exec::Ledger_GetTransactionIDByIndex(const std::string & SERVER_ID,
												  const std::string & USER_ID,
												  const std::string & ACCOUNT_ID,
												  const std::string & THE_LEDGER,
												   const int32_t & nIndex) // returns transaction number by index.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_FAIL; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTString strOutput("-1"); // For the output

	int64_t lTransactionNumber = 0;
	OTTransaction * pTransaction = NULL;

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
	}

	// At this point, I know theLedger loaded successfully.

	else if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("%s: out of bounds: %d\n", __FUNCTION__, nIndex);
		// out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	else if (NULL == (pTransaction = theLedger.GetTransactionByIndex(nIndex)))
	{
		OTLog::vError("%s: good index but uncovered \"\" pointer: %d\n", __FUNCTION__, nIndex);
	} // NO NEED TO CLEANUP the transaction, since it is already "owned" by theLedger.

	// At this point, I actually have the transaction pointer, so let's get the ID...

	else if (0 >= (lTransactionNumber = pTransaction->GetTransactionNum()))
	{
		OTLog::vError("%s: negative or zero transaction num: %lld\n", __FUNCTION__, lTransactionNumber);
		return -1;
	}
	else // success
	{
		return lTransactionNumber;
	}

	return -1;
}


// --------------------------------------------------------------
// Add a transaction to a ledger.
// (Returns the updated ledger.)
//
std::string OTAPI_Exec::Ledger_AddTransaction(const std::string & SERVER_ID,
										 const std::string & USER_ID,
										 const std::string & ACCOUNT_ID,
										 const std::string & THE_LEDGER,
										 const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error verifying ledger in OTAPI_Exec::Ledger_AddTransaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded and verified successfully.
	// -----------------------------------------------------

	OTTransaction * pTransaction = new OTTransaction(theUserID, theAccountID, theServerID);
	if (NULL == pTransaction)	{ OTLog::vError("%s: Error allocating memory in the OTAPI: %s !\n", __FUNCTION__, "pTransaction"	); OT_FAIL; }

	if (false == pTransaction->LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		delete pTransaction; pTransaction = NULL;
		return "";
	}
	else if (false == pTransaction->VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error verifying transaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		delete pTransaction; pTransaction = NULL;
		return "";
	}
	// -----------------------------------------------------
	// At this point, I know pTransaction loaded and verified successfully.
	// So let's add it to the ledger, save, and return updated ledger in string form.

	theLedger.AddTransaction(*pTransaction); // Ledger now "owns" it and will handle cleanup.

	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();

	OTString strOutput(theLedger); // For the output

	std::string pBuf = strOutput.Get();



	return pBuf;
}



// --------------------------------------------------------------
// Create a 'response' transaction, that will be used to indicate my
// acceptance or rejection of another transaction. Usually an entire
// ledger full of these is sent to the server as I process the various
// transactions in my inbox.
//
// The original transaction is passed in, and I generate a response transaction based on it.
// Also, the response ledger is passed in, so I load it, add the response transaction, save
// it back to string, and return the string.
//
// This way, users can call this function multiple times, adding transactions until done.
//
std::string OTAPI_Exec::Transaction_CreateResponse(const std::string & SERVER_ID,
                                                   const std::string & USER_ID,
                                                   const std::string & ACCOUNT_ID,
                                                   const std::string & THE_LEDGER, // 'Response' ledger be sent to the server...
                                                   const std::string & THE_TRANSACTION, // Responding to...?
                                                   const bool & BOOL_DO_I_ACCEPT)   // 0 or 1  (true or false.)
{
	if (SERVER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"       ); OT_FAIL; }
	if (USER_ID.empty())         { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"         ); OT_FAIL; }
	if (ACCOUNT_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"      ); OT_FAIL; }
	if (THE_LEDGER.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"      ); OT_FAIL; }
	if (THE_TRANSACTION.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION" ); OT_FAIL; }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------
	OTServerContract * pServer = OTAPI()->GetServer(theServerID, __FUNCTION__);
	if (NULL == pServer) return "";
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();

	if (NULL == pServerNym)
	{
		OTLog::vOutput(0, "%s: No Contract Nym found in that Server Contract.\n", __FUNCTION__);
		return "";
	}
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // This logs, ASSERTs, etc.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger theLedger(theUserID, theAcctID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error verifying ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded and verified successfully.
	// (This is the 'response' ledger that the user previously generated,
	// and now he is loading it up with responses that this function will
	// generate on his behalf.)
	// -----------------------------------------------------
	OTTransaction theTransaction(theUserID, theAcctID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// --------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(OTLedger::inbox));

		if (NULL == pTransaction)
		{
			OTString strAcctID(theAcctID);
			OTLog::vError("%s: Error loading full transaction from abbreviated version of inbox receipt. Acct ID: %s\n",
                          __FUNCTION__, strAcctID.Get());
			return "";
		}
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// --------------------------------------
	// BELOW THIS POINT, only use pTransaction, not theTransaction.

	// This transaction is presumably from the server, since we are in this
	// function in order to generate a response back to the server. So therefore
	// I want to verify that the server has actually signed the thing, before
	// I go off responding to it like a damned fool.
	//
	if (false == pTransaction->VerifyAccount(*((OTPseudonym *)pServerNym)))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error verifying transaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// -----------------------------------------------------

	if (
            (OTTransaction::pending         != pTransaction->GetType())
		&&	(OTTransaction::chequeReceipt   != pTransaction->GetType())
		&&	(OTTransaction::voucherReceipt  != pTransaction->GetType())
		&&	(OTTransaction::transferReceipt != pTransaction->GetType())
		&&	(OTTransaction::marketReceipt   != pTransaction->GetType())
		&&	(OTTransaction::paymentReceipt  != pTransaction->GetType())
		&&	(OTTransaction::finalReceipt    != pTransaction->GetType())
		&&	(OTTransaction::basketReceipt   != pTransaction->GetType())
		)
	{
		OTLog::vError("%s: wrong transaction type: %s.\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";
	}
	// -----------------------------------------------------
	// At this point, I know pTransaction loaded and verified successfully.
	// So let's generate a response item based on it, and add it to a processInbox
	// transaction to be added to that ledger (if one's not already there...)

	// First, check to see if there is a processInbox transaction already on
	// the ledger...
	OTTransaction * pResponse = theLedger.GetTransaction(OTTransaction::processInbox);

	// If it's not already there, create it and add it.
	if (NULL == pResponse)
	{
		OTString strServerID(theServerID);
		int64_t lTransactionNumber=0;
		bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lTransactionNumber);

		if (false == bGotTransNum)
		{
			OTString strNymID(theUserID);
			OTLog::vOutput(0, "%s: User is all out of transaction numbers:\n%s\n",
                           __FUNCTION__, strNymID.Get());
			return "";
		}

		pResponse = OTTransaction::GenerateTransaction(theUserID, theAcctID, theServerID,
			OTTransaction::processInbox, lTransactionNumber);

		if (NULL == pResponse)
		{
			OTString strAcctID(theAcctID);
			OTLog::vError("%s: Error generating processInbox transaction for AcctID: %s\n", __FUNCTION__, strAcctID.Get());

			pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true.  Have to add this back since we failed to use it.

			return "";
		}

		theLedger.AddTransaction(*pResponse); // Ledger now "owns" it and will handle cleanup.
	}

	// At this point32_t I know pResponse is a processInbox transaction, ready to go,
	// and that theLedger will handle any cleanup issues related to it.

	// -----------------------------------------------------

	// Next let's create a new item that responds to pTransaction, and add that
	// item to pResponse. Then we'll return the updated ledger.

	OTItem::itemType theAcceptItemType = OTItem::error_state;
	OTItem::itemType theRejectItemType = OTItem::error_state;

	switch (pTransaction->GetType())
	{
	case OTTransaction::pending:
		theAcceptItemType = OTItem::acceptPending;
		theRejectItemType = OTItem::rejectPending;
		break;


	case OTTransaction::marketReceipt:
	case OTTransaction::paymentReceipt:
		theAcceptItemType = OTItem::acceptCronReceipt;
		theRejectItemType = OTItem::disputeCronReceipt;
		break;

    case OTTransaction::chequeReceipt:
    case OTTransaction::voucherReceipt:
	case OTTransaction::transferReceipt:
		theAcceptItemType = OTItem::acceptItemReceipt;
		theRejectItemType = OTItem::disputeItemReceipt;
		break;

	case OTTransaction::finalReceipt:
		theAcceptItemType = OTItem::acceptFinalReceipt;
		theRejectItemType = OTItem::disputeFinalReceipt;
		break;

	case OTTransaction::basketReceipt:
		theAcceptItemType = OTItem::acceptBasketReceipt;
		theRejectItemType = OTItem::disputeBasketReceipt;
		break;

	default:
		theAcceptItemType = OTItem::error_state;
		theRejectItemType = OTItem::error_state;
		OTLog::vError("%s: Unexpected transaction type in: %s\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";
	}
    // -------------------------------------------------
	int64_t  lReferenceTransactionNum = 0;
    int64_t     lNumberOfOrigin          = 0;
    OTString strNote;
    // -------------------------------------------------
	switch (pTransaction->GetType())
	{
	case OTTransaction::marketReceipt:
	case OTTransaction::paymentReceipt:
	case OTTransaction::finalReceipt:
	case OTTransaction::basketReceipt:
            lNumberOfOrigin          = pTransaction->GetReferenceToNum();
            lReferenceTransactionNum = pTransaction->GetTransactionNum();   // <=== References the receipt in my inbox.
		break;

    case OTTransaction::transferReceipt: // Contains "in ref to" acceptPending item from someone who processed their inbox to accept my transfer.
	case OTTransaction::pending:         // Contains "in ref to" transfer item from someone who sent me a transfer.
    case OTTransaction::chequeReceipt:   // Contains "in ref to" depositCheque item from someone who deposited my cheque.
    case OTTransaction::voucherReceipt:  // Contains "in ref to" depositCheque item from someone who deposited my voucher.
		{
			// -----------------------------------------------------
			// Here's some code in case you need to load up the item.
			OTString strReference;
			pTransaction->GetReferenceString(strReference);

			if (!strReference.Exists())
			{
				OTLog::vError("%s: No reference string found on transaction.\n", __FUNCTION__);
				return "";
			}
			// -----------------------------------------------------
			OTItem * pOriginalItem = OTItem::CreateItemFromString(strReference, theServerID, pTransaction->GetReferenceToNum());
			OTCleanup<OTItem> theAngel(pOriginalItem);

			if (NULL == pOriginalItem)
			{
				OTLog::vError("%s: Failed loading transaction item from string.\n",__FUNCTION__);
				return "";
			}
			// pItem will be automatically cleaned up when it goes out of scope.
			// -----------------------------------------------------
			if (
				(OTItem::request != pOriginalItem->GetStatus())
				||
				(
				(OTItem::acceptPending	!= pOriginalItem->GetType())  && // I'm accepting a transfer receipt that was created by someone's acceptPending (from a transfer I sent.)
                 (OTItem::transfer		!= pOriginalItem->GetType())  && // I'm accepting a pending transfer that was created by someone's transfer to me.
				(OTItem::depositCheque	!= pOriginalItem->GetType())	 // I'm accepting a cheque or voucher receipt that was created by someone's depositCheque (of a cheque I wrote or a voucher I remitted.)
				)
				)
			{
				OTLog::vError("%s: Wrong item type or status attached as reference on transaction.\n", __FUNCTION__);
				return "";
			}
            // -----------------------------------------------------------
            if (OTItem::transfer == pOriginalItem->GetType())
                pOriginalItem->GetNote(strNote);
            // -----------------------------------------------------------
            lNumberOfOrigin          = pOriginalItem->GetNumberOfOrigin();
			lReferenceTransactionNum = pTransaction-> GetTransactionNum();  // <=== References the receipt in my inbox.
//			lReferenceTransactionNum = pOriginalItem->GetReferenceToNum();  // <=== References the original transfer I sent, or N/A (for pending), or cheque I wrote.
//			lReferenceTransactionNum = pOriginalItem->GetTransactionNum();  // <=== References someone else's transaction that put the receipt into my inbox.
		}
		// -----------------------------------------------------
		break;

	default:
		OTLog::vError("%s: Unexpected transaction type in: %s\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";
	}
    // ------------------------------------------------------------------
	OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pResponse,
		(true == BOOL_DO_I_ACCEPT) ? theAcceptItemType : theRejectItemType); // set above.
    // ------------------------------------------------------------------
    pAcceptItem->SetNumberOfOrigin(lNumberOfOrigin);
    // ------------------------------------------------------------------
	// Set up the "accept" transaction item to be sent to the server
	// (this item references and accepts another item by its transaction number--
	//  one that is already there in my inbox)
	pAcceptItem->SetReferenceToNum(static_cast<int64_t>(lReferenceTransactionNum)); // This is critical. Server needs this to look up the original.
	// Don't need to set transaction num on item since the constructor already got it off the owner transaction.
    // ------------------------------------------------------------------
	pAcceptItem->SetAmount(pTransaction->GetReceiptAmount()); // Server validates this, so make sure it's right.
    // ------------------------------------------------------------------
    if (strNote.Exists())
        pAcceptItem->SetNote(strNote);
    // ------------------------------------------------------------------
    // sign the item
	pAcceptItem->SignContract(*pNym);
	pAcceptItem->SaveContract();
    // ----------------------------------------------------------------------------------
    // Make sure there's not already a response item in reference to the same receipt.
    //
    // UPDATE, NOTE: Turns out, it's normal to have multiple receipts in reference to the same thing.
    // For example, I might have two transfer receipts that are both in reference to the same notarizeInbox.
    //
//    OTItem * pExistingItem = pResponse->GetItemInRefTo(lReferenceTransactionNum);
//    if (NULL != pExistingItem)
//    {
//        OTLog::vError("%s: Error: There's already a response item in reference to the same receipt! (In Ref: %lld User: %s Account: %s) Failure.\n\n",
//                      __FUNCTION__, static_cast<int64_t>(lReferenceTransactionNum), USER_ID.c_str(), ACCOUNT_ID.c_str());
//
//        const OTString strAccept(*pAcceptItem);
//        OTLog::vError("===> Failed accept item:\n%s\n\n", strAccept.Get());
//
//        const OTString strExisting(*pExistingItem);
//        OTLog::vError("===> Pre-existing item:\n%s\n\n", strExisting.Get());
//
//        return "";
//    }
    // ----------------------------------------------------------------------------------
	// the transaction will handle cleaning up the transaction item.
	pResponse->AddItem(*pAcceptItem);

	// I don't attach the original item here because I already reference it by transaction num,
	// and because the server already has it and sent it to me. SO I just need to give the server
	// enough info to look it up again.

	pResponse->ReleaseSignatures();
	pResponse->SignContract(*pNym);
	pResponse->SaveContract();

	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();

	OTString strOutput(theLedger); // For the output

	std::string pBuf = strOutput.Get();

	return pBuf;
}



// -------------------------------------------------------------------------
// (Response Ledger) LEDGER FINALIZE RESPONSE
//
// AFTER you have set up all the transaction responses, call THIS function
// to finalize them by adding a BALANCE AGREEMENT.
//
// MAKE SURE you have the latest copy of the account file, inbox file, and
// outbox file, since we will need those in here to create the balance statement
// properly.
//
// (Client software may wish to check those things, when downloaded, against
// the local copies and the local signed receipts. In this way, clients can
// protect themselves against malicious servers.)
//
std::string OTAPI_Exec::Ledger_FinalizeResponse(const std::string & SERVER_ID,
                                                const std::string & USER_ID,
                                                const std::string & ACCOUNT_ID,
                                                const std::string & THE_LEDGER) // 'Response' ledger be sent to the server...
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_LEDGER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_FAIL; }

	const OTIdentifier	theServerID(SERVER_ID),
                        theUserID(USER_ID),
                        theAcctID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER), strServerID(theServerID);
	// --------------------------------------------------------------------
	OTServerContract * pServer = OTAPI()->GetServer(theServerID, __FUNCTION__);
	if (NULL == pServer) return "";
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();

	if (NULL == pServerNym)
	{
		OTLog::vOutput(0, "%s: No Contract Nym found in that Server Contract.\n", __FUNCTION__);
		return "";
	}
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // This logs, ASSERTs, etc.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger theLedger(theUserID, theAcctID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error verifying ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded and verified successfully.
	// (This is the 'response' ledger that the user previously generated
	// in response to the various inbox receipts, and now he is loading
	// it up with responses that this function will finalize for sending.)
	// -----------------------------------------------------

	// First, check to see if there is a processInbox transaction already on
	// the ledger...
	OTTransaction * pTransaction = theLedger.GetTransaction(OTTransaction::processInbox);

	// If it's not already there, create it and add it.
	if (NULL == pTransaction)
	{
		OTString strAcctID(theAcctID);
		OTLog::vError("%s: Error finding processInbox transaction for AcctID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// At this point32_t I know pTransaction is a processInbox transaction, ready to go,
	// and that theLedger will handle any cleanup issues related to it.
	// -----------------------------------------------------
	// If balance statement is already there, return.
	if (NULL != pTransaction->GetItem(OTItem::balanceStatement))
	{
		OTLog::vError("%s: this response has already been finalized.\n", __FUNCTION__);
		return "";
	}
	// -------------------------------------------------------------
	// Get the account.
	OTAccount *	pAccount = OTAPI()->GetAccount(theAcctID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------------------------------------------
	// Load the inbox and outbox.

	OTLedger theInbox (theUserID, theAcctID, theServerID);
	OTLedger theOutbox(theUserID, theAcctID, theServerID);

	if (!theInbox.LoadInbox() || !theInbox.VerifyAccount(*pNym))
	{
		OTLog::vOutput(0, "%s: Unable to load or verify Inbox for acct %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
		return "";
	}

	if (!theOutbox.LoadOutbox() || !theOutbox.VerifyAccount(*pNym))
	{
		OTLog::vOutput(0, "%s: Unable to load or verify Outbox for acct %s\n", __FUNCTION__, ACCOUNT_ID.c_str());
		return "";
	}

	// -------------------------------------------------------------

	// Setup balance agreement item here!
	// Adapting code from OTServer... with comments:
	//
	// This transaction accepts various incoming pending transfers.
	// So when it's all done, my balance will be higher.
	// AND pending inbox items will be removed from my inbox.
	//
	// I would like to not even process the whole giant loop below,
	// if I can verify here now that the balance agreement is wrong.
	//
	// Thus I will actually loop through the acceptPending items in pTransaction, and then for each one, I'll
	// lookup the ACTUAL transaction in the inbox, and get its ACTUAL value. (And total them all up.)
	//
	// The total of those, (WITHOUT the user having to tell me what it will be, since I'm looking them all up),
	// should equal the difference in the account balance! Meaning the current balance plus that total will be
	// the expected NEW balance, according to this balance agreement -- if it wants to be approved, that is.
	//
	//

	bool bSuccessFindingAllTransactions = true;
	int64_t lTotalBeingAccepted = 0;

	std::list<int64_t> theListOfInboxReceiptsBeingRemoved;

	OTPseudonym theTempNym;

	FOR_EACH_IT(listOfItems, pTransaction->GetItemList(), it_bigloop)
	{
		OTItem * pItem = *it_bigloop;
		if (NULL == pItem)	{ OTLog::vError("%s: Pointer: %s should not have been \"\".\n",
                                            __FUNCTION__, "pItem" ); OT_FAIL; }

		if ((pItem->GetType() == OTItem::acceptPending) ||
			(pItem->GetType() == OTItem::acceptItemReceipt))
		{

//            if (theInbox.GetTransactionCountInRefTo(pItem->GetReferenceToNum()) > 1)
//                OTLog::vError("%s: WARNING: There are MULTIPLE receipts 'in reference to' %lld. (It will return the first one...)\n",
//                              __FUNCTION__, pItem->GetReferenceToNum());


			OTTransaction * pServerTransaction = theInbox.GetTransaction(pItem->GetReferenceToNum());

			OTLog::vOutput(1, "%s: Checking inbox for expected pending or receipt (%lld) Nym: %s\n",
                           __FUNCTION__, pItem->GetReferenceToNum(), USER_ID.c_str()); // temp remove

			if (NULL == pServerTransaction)
			{
				bSuccessFindingAllTransactions = false;
				OTLog::vOutput(0, "%s: Expected receipt %lld NOT found! (Do you have the latest inbox?)\n",
                               __FUNCTION__, pItem->GetReferenceToNum());
				break;
			}
			else
			{
				bSuccessFindingAllTransactions = true;

				// IF I'm accepting a pending transfer, then add the amount to my counter of total amount being accepted.
				//
				// ELSE if I'm accepting an item receipt (which will remove my responsibility for that item) then add it
				// to the temp Nym (which is a list of transaction numbers that will be removed from my responsibility if
				// all is successful.)  Also remove all the Temp Nym numbers from pNym, so we can verify the Balance
				// Statement AS IF they were already removed. Add them
				//
				if (pItem->GetType() == OTItem::acceptPending) // acceptPending
					lTotalBeingAccepted += pServerTransaction->GetReceiptAmount();   // <============================

				else if (pItem->GetType() == OTItem::acceptItemReceipt) // acceptItemReceipt
				{
					// What number do I remove here? the user is accepting a transfer receipt, which
					// is in reference to the recipient's acceptPending. THAT item is in reference to
					// my original transfer (or contains a cheque with my original number.) (THAT's the # I need.)
					//
					OTString strOriginalItem;
					pServerTransaction->GetReferenceString(strOriginalItem);

					OTItem * pOriginalItem = OTItem::CreateItemFromString(strOriginalItem, SERVER_ID.c_str(),
						pServerTransaction->GetReferenceToNum());
					OTCleanup<OTItem> theOrigItemGuardian(pOriginalItem); // So I don't have to clean it up later. No memory leaks.

					if (NULL != pOriginalItem)
					{
						// If pOriginalItem is acceptPending, that means the client is accepting the transfer receipt from the server, (from his inbox),
						// which has the recipient's acceptance inside of the client's transfer as the original item. This means the transfer that
						// the client originally sent is now finally closed!
						//
						// If it's a depositCheque, that means the client is accepting the cheque receipt from the server,
						// (from his inbox)
						// which has the recipient's deposit inside of it as the original item. This means that the cheque that
						// the client originally wrote is now finally closed!
						//
						// In both cases, the "original item" itself is not from the client, but from the recipient! Therefore,
						// the number on that item is useless for removing numbers from the client's list of issued numbers.
						// Rather, I need to load that original cheque, or pending transfer, from WITHIN the original item,
						// in order to get THAT number, to remove it from the client's issued list. (Whether for real, or for
						// setting up dummy data in order to verify the balance agreement.) *sigh*
						//
						// ----------------------------
						if (OTItem::depositCheque == pOriginalItem->GetType()) // client is accepting a cheque receipt, which has a depositCheque (from the recipient) as the original item within.
						{
							// Get the cheque from the Item and load it up into a Cheque object.
							OTString strCheque;
							pOriginalItem->GetAttachment(strCheque);

							OTCheque theCheque; // allocated on the stack :-)

							if (false == ((strCheque.GetLength() > 2) &&
								theCheque.LoadContractFromString(strCheque)))
							{
								OTLog::vError("%s: ERROR loading cheque from string:\n%s\n", __FUNCTION__, strCheque.Get());
							}
							else	// Since the client wrote the cheque, and he is now accepting the cheque receipt, he can be cleared for that transaction number...
							{
								if (pNym->VerifyIssuedNum  (strServerID, theCheque.GetTransactionNum()))
									theTempNym.AddIssuedNum(strServerID, theCheque.GetTransactionNum());
								else
									OTLog::vError("%s: cheque receipt, trying to 'remove' an issued "
									"number (%lld) that already wasn't on my issued list. (So what is this in my inbox, "
									"then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__,
									theCheque.GetTransactionNum());
							}
						}
						// ----------------------------
						// client is accepting a transfer receipt, which has an acceptPending from the recipient
						// as the original item within.
						//
						else if (OTItem::acceptPending == pOriginalItem->GetType()) // (which is in reference to the client's outgoing original transfer.)
						{
							if (pNym->VerifyIssuedNum  (strServerID, pOriginalItem->GetNumberOfOrigin()))
								theTempNym.AddIssuedNum(strServerID, pOriginalItem->GetNumberOfOrigin());
							else
								OTLog::vError("%s: transferReceipt, trying to 'remove' an issued "
								"number (%lld) that already wasn't on my issued list. (So what is this in my inbox, "
								"then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__,
								pOriginalItem->GetNumberOfOrigin());
						}
						// ----------------------------
						else // wrong type.
						{
							OTString strOriginalItemType;
							pOriginalItem->GetTypeString(strOriginalItemType);
							OTLog::vError("%s: Original item has wrong type, while accepting item receipt:\n%s\n",
                                          __FUNCTION__, strOriginalItemType.Get());
						}
					}
					else
					{
						OTLog::vError("%s: Unable to load original item from string while accepting item receipt:\n%s\n",
                                      __FUNCTION__, strOriginalItem.Get());
					}
				} // acceptItemReceipt


				// I'll also go ahead and remove each transaction from theInbox, and pass said inbox into the VerifyBalanceAgreement call...
				// (So it can simulate as if the inbox was already changed, and the total is already calculated, and if it succeeds,
				// then we can allow the giant loop below to do it all for real.)
				// (I'm not saving this copy of the inbox anyway--there's another one below.)
                //
				//theInbox.RemoveTransaction(pServerTransaction->GetTransactionNum());	// <================
				// Now this is done AFTER this loop...
				//
				theListOfInboxReceiptsBeingRemoved.push_back(pServerTransaction->GetTransactionNum());

			} // pServerTransaction != ""
		} // if pItem type is accept pending or item receipt.

		// ---------------------------------------------------------------

		else if ((pItem->GetType() == OTItem::acceptCronReceipt)   ||
                 (pItem->GetType() == OTItem::acceptFinalReceipt)  ||
                 (pItem->GetType() == OTItem::acceptBasketReceipt)
                )
		{
			OTTransaction * pServerTransaction = theInbox.GetTransaction(pItem->GetReferenceToNum());

			OTLog::vOutput(2, "%s: Checking client-side inbox for expected cron or final or basket receipt: %lld... ",
                           __FUNCTION__, pItem->GetReferenceToNum()); // temp remove

			if (NULL == pServerTransaction)
			{
				bSuccessFindingAllTransactions = false;
				OTLog::vOutput(2, "%s: NOT found! (Do you have the latest inbox?)\n", __FUNCTION__); // temp remove
				break;
			}
			else
			{
				bSuccessFindingAllTransactions = true;

				switch (pItem->GetType())
				{
					// ************************************************************

				case OTItem::acceptCronReceipt:
					// pServerTransaction is a marketReceipt or paymentReceipt
					//

					// When accepting a cron receipt from the inbox, you don't have to clear the issued transaction number.
					// In this case, the original trans# is cleared when the finalReceipt is generated,
					// and the closing trans# is cleared when the finalReceipt is cleared.

					// So NO issued numbers being removed or added in this case.
					// (But we still remove the receipt from our copy of the inbox, below,
					// so that the balance agreement will reflect as if it had already been
					// successfully removed. (Because balance agreement is meant to show the new
					// state of things, in the event of success--a signed record of those things.)
					break;

					// ************************************************************

				case OTItem::acceptFinalReceipt:
					// pServerTransaction is a finalReceipt


					// IN THIS CASE: If we're accepting a finalReceipt, that means all the OTHER receipts related to it
					// (sharing the same "in reference to") must ALSO be cleared from the inbox aint64_t with it! That's the
					// whole point32_t of the finalReceipt -- to make sure all related receipts are cleared, when IT is.
					//
					// The server WILL verify this also (I tested it)... That's why we check here, to save the trouble
					// of being rejected by the server.
					//
					// So let's see if the number of related receipts on this process inbox (pTransaction) matches
					// the number of related receipts in the actual inbox (theInbox), as found by the finalReceipt's
					// (pServerTransaction) "in reference to" value, which should be the same as on the related receipts.

					// (Below) pTransaction is the processInbox transaction. Each item on it is in ref to a DIFFERENT receipt,
					// even though, if they are marketReceipts, all of THOSE receipts are in ref to the original transaction#.
					{
//                      int32_t nRefCount = 0;
						std::set<int64_t> setOfRefNumbers; // we'll store them here, to disallow duplicates, to make sure they are all unique IDs

						//
						// I need to loop through all items on pTransaction (my processInbox request)
						// For each, look it up on the inbox. (Each item may be "in reference to"
						// one original transaction or another.) FIND THE ONES that are in reference to
						// the same # as pServerTransaction is.
						//
						FOR_EACH(listOfItems, pTransaction->GetItemList())
						{
							OTItem * pItemPointer = *it;
							if (NULL == pItemPointer)	{ OTLog::vError("%s: Pointer: %s should not have been "".\n", __FUNCTION__, "pItemPointer" ); OT_FAIL; }

							// pItemPointer->GetReferenceToNum() is the server's transaction number for the receipt
							// that it dropped into my inbox. pTransPointer is the receipt itself (hopefully.)
							OTTransaction * pTransPointer = theInbox.GetTransaction(pItemPointer->GetReferenceToNum());

							// Careful on the logic here...
							// ONCE EACH INBOX RECEIPT IS DEFINITELY NOT-"", and
							// if *IT* is "in reference to" pServerTransaction->GetReferenceToNum(),
							// Then increment the count for the transaction.  COMPARE *THAT* to theInbox.GetCount and we're golden!!
							// Perhaps the finalReceipt is in reference to #10, and there are 6 others that are ALSO in reference to #10.
							// That's a total of 7 receipts in the inbox that are in reference to #10, so my request had better have the
							// same count :-)
							//
							if ((NULL != pTransPointer) &&
								(pTransPointer->GetReferenceToNum() == pServerTransaction->GetReferenceToNum()))
							{
//                              nRefCount++;
								// std::set doesn't allow duplicates.
								setOfRefNumbers.insert(pItemPointer->GetReferenceToNum());
							}
						}

						// ---------------------------------------------
						//
						if (static_cast<int32_t>(setOfRefNumbers.size())
							!=   // IS NOT EQUAL TO...
							theInbox.GetTransactionCountInRefTo(pServerTransaction->GetReferenceToNum()))
							/* todo: Notice I'm not making sure the count is entirely composed of ACCEPTED receipts. (vs DISPUTED...)
							I probably should add code to GetItemCountInRefTo() so it only counts ACCEPTED receipts.*/
						{
							OTLog::vOutput(0,
								"%s: When accepting a finalReceipt, you MUST accept all "
								"related receipts (ones that share the same IN REFERENCE TO transaction number as the finalReceipt %lld)\n"
								"Transaction item count (in ref to): %d    Inbox transaction count (in ref to): %d.\n", __FUNCTION__,
								pServerTransaction->GetReferenceToNum(),
								setOfRefNumbers.size(),
								theInbox.GetTransactionCountInRefTo(pServerTransaction->GetReferenceToNum()));

							bSuccessFindingAllTransactions = false;
							break;
						}
						// Else NO BREAK;
						//break;  FALLING THROUGH TO BELOW, to do the pNym/theTempNym stuff in the BASKET section...

						// pServerTransaction->GetReferenceToNum() is the OPENING number and should already be closed.
						//
						// IN fact, since the "in reference to" is supposedly already closed, then let's just
						// MAKE SURE of that, since otherwise it'll screw up my future balance agreements. (The
						// instant a finalReceipt appears, the "in ref to" is already gone on the server's side.)
						//
						if (OTTransaction::finalReceipt	== pServerTransaction->GetType())
						{
							if (pNym->RemoveIssuedNum(*pNym, strServerID, pServerTransaction->GetReferenceToNum(), true)) // bool bSave=true
								OTLog::vOutput(1, "%s: **** Due to finding a finalReceipt, REMOVING OPENING NUMBER FROM NYM:  %lld \n", __FUNCTION__, pServerTransaction->GetReferenceToNum());
							else
								OTLog::vOutput(1, "%s: **** Noticed a finalReceipt, but Opening Number %lld had ALREADY been removed from nym. \n", __FUNCTION__, pServerTransaction->GetReferenceToNum());
						}
						else
							OTLog::vError("%s: Expected pServerTransaction to be a final receipt (while finalizing for process inbox.)\n", __FUNCTION__);
						//
						// pNym won't actually save unless it actually removes that #. If the #'s already NOT THERE,
						// then the removal will fail, and thus it won't bother saving here.
					}

					// ... (FALL THROUGH) ...

				case OTItem::acceptBasketReceipt:
					// pServerTransaction is a basketReceipt (or finalReceipt, since falling through from above.)
					//
					// Remove the proper issued number, based on the CLOSING TRANSACTION NUMBER
					// of the finalReceipt/basketReceipt I'm accepting...
					//

					if (pNym->VerifyIssuedNum(strServerID, pServerTransaction->GetClosingNum()))
						theTempNym.AddIssuedNum(strServerID, pServerTransaction->GetClosingNum());
					else
						OTLog::vError("%s: final or basket Receipt, trying to 'remove' an issued "
						"number (%lld) that already wasn't on my issued list. (So what is this in my inbox, "
						"then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__,
						pServerTransaction->GetClosingNum());
					break;

					// ************************************************************

				default:
					{
						OTString strTempType;
						pItem->GetTypeString(strTempType);
						OTLog::vError("%s: Unexpected item type: %s\n", __FUNCTION__, strTempType.Get());
						break;
					}
				}

				// I'll also go ahead and remove each transaction from theInbox, and pass said inbox into the VerifyBalanceAgreement call...
				// (So it can simulate as if the inbox was already changed, and the total is already calculated, and if it succeeds,
				// then we can allow the giant loop below to do it all for real.)
				// (I'm not saving this copy of the inbox anyway--there's another one below.)
				//
				//theInbox.RemoveTransaction(pItem->GetReferenceToNum());
				// Let's remove it this way instead:
				//
//				theInbox.RemoveTransaction(pServerTransaction->GetTransactionNum());	// <================
				//
				// Actually, let's remove it this way:
				theListOfInboxReceiptsBeingRemoved.push_back(pServerTransaction->GetTransactionNum());

			} // else if pServerTransaction NOT "".
		} // If acceptCronReceipt/acceptFinalReceipt/acceptBasketReceipt
	}
	// ------------------------------------------
	if (false == bSuccessFindingAllTransactions) // failure.
	{
		OTLog::vOutput(0, "%s: transactions in processInbox message do not match actual inbox.\n", __FUNCTION__);

		return "";		// RETURN.
	}
	// ---------------------------------------------------------------------
	// SUCCESS finding all transactions

	while (!theListOfInboxReceiptsBeingRemoved.empty())
	{
		int64_t lTemp = theListOfInboxReceiptsBeingRemoved.front();
		theListOfInboxReceiptsBeingRemoved.pop_front();

		if (false == theInbox.RemoveTransaction(static_cast<int64_t>(lTemp)))    // <================
			OTLog::vError("%s: Failed removing receipt from temporary Inbox: %lld \n", __FUNCTION__, lTemp);
	}

	// *****************************************************************

	// SET UP NYM FOR BALANCE AGREEMENT.

	// By this point, theTempNym contains a list of all the transaction numbers that are issued to me,
	// but that will NOT be issued to me anymore once this processInbox is processed.
	// Therefore I need to REMOVE those items from my issued list (at least temporarily) in order to
	// calculate the balance agreement properly. So I used theTempNym as a temp variable to store those
	// numbers, so I can remove them from my Nym and them add them again after generating the statement.
	//
	for (int32_t i = 0; i < theTempNym.GetIssuedNumCount(theServerID); i++)
	{
		int64_t lTemp = theTempNym.GetIssuedNum(theServerID, i);
		pNym->RemoveIssuedNum(strServerID, static_cast<int64_t>(lTemp));
	}
	// -----------------------------------------
	// BALANCE AGREEMENT
	//
	// The item is signed and saved within this call as well. No need to do that again.
	//
	OTItem * pBalanceItem = theInbox.GenerateBalanceStatement(static_cast<int64_t>(lTotalBeingAccepted), *pTransaction, *pNym, *pAccount, theOutbox);
	// -----------------------------------------
	// Here I am adding these numbers back again, since I removed them to generate the balance agreement.
	// (They won't be removed for real until I receive the server's acknowledgment that those numbers
	// really were removed. theTempNym then I have to keep them and use them for my balance agreements.)
	//
	for (int32_t i = 0; i < theTempNym.GetIssuedNumCount(theServerID); i++)
	{
		int64_t lTemp = theTempNym.GetIssuedNum(theServerID, i);
		pNym->AddIssuedNum(strServerID, static_cast<int64_t>(lTemp));
	}

	// *****************************************************************

	if (NULL == pBalanceItem)
	{
		OTLog::vOutput(0, "%s: ERROR generating balance statement.\n", __FUNCTION__);

		return "";
	}

	// the transaction will handle cleaning up the transaction item.
	pTransaction->AddItem(*pBalanceItem);
	// -----------------------------------------
	// sign the item
	// This already happens in the GenerateBalanceStatement() call above.
	// I would actually have to RELEASE the signatures if I wanted to sign again!
	// (Unless I WANT two signatures...)
	//
//	pBalanceItem->SignContract(*pNym);
//	pBalanceItem->SaveContract();

	pTransaction->ReleaseSignatures();
	pTransaction->SignContract(*pNym);
	pTransaction->SaveContract();

	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();

	OTString strOutput(theLedger); // For the output

	std::string pBuf = strOutput.Get();

	return pBuf;
}





// --------------------------------------------------------------------
// Retrieve Voucher from Transaction
//
// If you withdrew into a voucher instead of cash, this function allows
// you to retrieve the actual voucher cheque from the reply transaction.
// (A voucher is a cheque drawn on an internal server account instead
// of a user's asset account, so the voucher cannot ever bounce due to
// insufficient funds. We are accustomed to this functionality already
// in our daily lives, via "money orders" and "cashier's cheques".)
//
// How would you use this in full?
//
// First, call OTAPI_Exec::withdrawVoucher() in order to send the request
// to the server. (You may optionally call OTAPI_Exec::FlushMessageBuffer()
// before doing this.)
//
// Then, call OTAPI_Exec::PopMessageBuffer() to retrieve any server reply.
//
// If there is a message from the server in reply, then call
// OTAPI_Exec::Message_GetCommand to verify that it's a reply to the message
// that you sent, and call OTAPI_Exec::Message_GetSuccess to verify whether
// the message was a success.
//
// If it was a success, next call OTAPI_Exec::Message_GetLedger to retrieve
// the actual "reply ledger" from the server.
//
// Penultimately, call OTAPI_Exec::Ledger_GetTransactionByID() and then,
// finally, call OTAPI_Exec::Transaction_GetVoucher() (below) in order to
// retrieve the voucher cheque itself from the transaction.
//
std::string OTAPI_Exec::Transaction_GetVoucher(const std::string & SERVER_ID,
                                               const std::string & USER_ID,
                                               const std::string & ACCOUNT_ID,
                                               const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"       ); OT_FAIL; }
	if (USER_ID.empty())         { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"         ); OT_FAIL; }
	if (ACCOUNT_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"      ); OT_FAIL; }
	if (THE_TRANSACTION.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	OTString strOutput;

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// No need to check if transaction is abbreviated, since it's coming from a message ledger.
	// (Those always contain the full version of the transactions, automatically.)
	// -----------------------------------------------------

	if (OTTransaction::atWithdrawal != theTransaction.GetType())
	{
		OTLog::vError("%s: Error: tried to retrieve voucher from wrong transaction (not atWithdrawal).\n", __FUNCTION__);
		return "";
	}

	// -----------------------------------------------------

	// loop through the ALL items that make up this transaction and check to see if a response to withdrawal.

	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	FOR_EACH(listOfItems, theTransaction.GetItemList())
	{
		OTItem * pItem = *it;
		if (NULL == pItem)	{ OTLog::vError("%s: Pointer: %s should not have been "".\n", __FUNCTION__, "pItem" ); OT_FAIL; }

		if ((OTItem::atWithdrawVoucher	== pItem->GetType()) &&
			(OTItem::acknowledgement	== pItem->GetStatus()))
		{
			OTString	strVoucher;
			pItem->GetAttachment(strVoucher);

			OTCheque	theVoucher;
			if (theVoucher.LoadContractFromString(strVoucher)) // Todo additional verification here on the cheque.
			{
				theVoucher.SaveContractRaw(strOutput);
				break;
			}
		}
	}

	// -----------------------------------------------------

	// Didn't find one.
	if (!strOutput.Exists())
		return "";

	// We found a voucher -- let's return it!
	//
	std::string pBuf = strOutput.Get();

	return pBuf;
}








std::string OTAPI_Exec::Transaction_GetSenderUserID(const std::string & SERVER_ID,
												const std::string & USER_ID,
												const std::string & ACCOUNT_ID,
												const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

             if (theTransaction.Contains("nymboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else if (theTransaction.Contains("expiredBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::expiredBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type.\n", __FUNCTION__);
			return "";
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return "";
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------
	OTIdentifier theOutput;

	bool bSuccess = pTransaction->GetSenderUserIDForDisplay(theOutput);
	// -----------------------------------------------------

	if (bSuccess)
	{
		OTString strOutput(theOutput);

		// Didn't find one.
		if (!strOutput.Exists())
			return "";

		// We found it -- let's return the user ID
		//
		std::string pBuf = strOutput.Get();



		return pBuf;
	}
	else
		return "";
}






std::string OTAPI_Exec::Transaction_GetRecipientUserID(const std::string & SERVER_ID,
												  const std::string & USER_ID,
												  const std::string & ACCOUNT_ID,
												  const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------

	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else if (theTransaction.Contains("expiredBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::expiredBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return "";
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.", __FUNCTION__);
			return "";
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------

	OTIdentifier theOutput;

	bool bSuccess = pTransaction->GetRecipientUserIDForDisplay(theOutput);

	// -----------------------------------------------------

	// Normally, there IS NO recipient user ID for a transfer (only a recipient acct ID.)
	// But here, as a special trick, I'll see if the account is in my address book.
	// THIS MEANS THE ADDRESS BOOK needs to store nyms (for other people, their public nym)
	// as well as a list of acct IDs that I have associated with each Nym. That way, I can
	// later look up the Nym ID based on the acct ID, and then look up my display label for
	// that Nym.
	//
	//	if (!bSuccess && (theTransaction.GetType() == OTTransaction::pending))
	//	{
	//		// AS SOON AS ADDRESS BOOK FEATURE IS ADDED, THEN THIS CAN BE COMPLETED HERE.
	//	}

	// -----------------------------------------------------

	if (bSuccess)
	{
		OTString strOutput(theOutput);

		// Didn't find one.
		if (!strOutput.Exists())
			return "";

		// We found it -- let's return the user ID
		//
		std::string pBuf = strOutput.Get();



		return pBuf;
	}
	else
		return "";
}






std::string OTAPI_Exec::Transaction_GetSenderAcctID(const std::string & SERVER_ID,
												const std::string & USER_ID,
												const std::string & ACCOUNT_ID,
												const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else if (theTransaction.Contains("expiredBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::expiredBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type.\n", __FUNCTION__);
			return "";
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return "";
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------

	OTIdentifier theOutput;

	bool bSuccess = pTransaction->GetSenderAcctIDForDisplay(theOutput);

	// -----------------------------------------------------

	if (bSuccess)
	{
		OTString strOutput(theOutput);

		// Didn't find one.
		if (!strOutput.Exists())
			return "";

		// We found it -- let's return the user ID
		//
		std::string pBuf = strOutput.Get();



		return pBuf;
	}
	else
		return "";
}






std::string OTAPI_Exec::Transaction_GetRecipientAcctID(const std::string & SERVER_ID,
												  const std::string & USER_ID,
												  const std::string & ACCOUNT_ID,
												  const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string in OTAPI_Exec::Transaction_GetRecipientAcctID. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else if (theTransaction.Contains("expiredBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::expiredBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return "";
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return "";
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------
	OTIdentifier theOutput;

	bool bSuccess = pTransaction->GetRecipientAcctIDForDisplay(theOutput);

	// -----------------------------------------------------

	if (bSuccess)
	{
		OTString strOutput(theOutput);

		// Didn't find one.
		if (!strOutput.Exists())
			return "";

		// We found it -- let's return the user ID
		//
		std::string pBuf = strOutput.Get();



		return pBuf;
	}
	else
		return "";
}








// -------------------------------------------------------------


// --------------------------------------------------
//
// PENDING TRANSFER (various functions)
//
// When someone has sent you a PENDING TRANSFER (a form of transaction
// that will be sitting in your inbox waiting for you to accept/reject it)
// then, as you are reading the inbox, you can use these functions in
// order to get data from the pending transfer.
//



std::string OTAPI_Exec::Pending_GetNote(const std::string & SERVER_ID,
                                        const std::string & USER_ID,
                                        const std::string & ACCOUNT_ID,
                                        const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"       ); OT_FAIL; }
	if (USER_ID.empty())         { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"         ); OT_FAIL; }
	if (ACCOUNT_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"      ); OT_FAIL; }
	if (THE_TRANSACTION.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else if (theTransaction.Contains("expiredBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::expiredBox);
		else
		{
			OTLog::vError("%s Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return "";
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return "";
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------
	if (OTTransaction::pending != pTransaction->GetType())
	{
		OTLog::vError("%s: wrong transaction type: %s. (Expected \"pending\".)\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";
	}
	// -----------------------------------------------------
	OTString strReference;
	pTransaction->GetReferenceString(strReference);

	if (!strReference.Exists())
	{
		OTLog::vError("%s: No reference string found on transaction.\n", __FUNCTION__);
		return "";
	}
	// -----------------------------------------------------
	OTItem * pItem = OTItem::CreateItemFromString(strReference, theServerID, pTransaction->GetReferenceToNum());
	OTCleanup<OTItem> theAngel(pItem);

	if (NULL == pItem)
	{
		OTLog::vError("%s: Failed loading transaction item from string.\n", __FUNCTION__);
		return "";
	}

	// pItem will be automatically cleaned up when it goes out of scope.
	// -----------------------------------------------------
	if ((OTItem::transfer	!= pItem->GetType()) ||
		(OTItem::request	!= pItem->GetStatus()))
	{
		OTLog::vError("%s: Wrong item type or status attached as reference on transaction.\n", __FUNCTION__);
		return "";
	}
	// -----------------------------------------------------
	OTString strOutput;

	pItem->GetNote(strOutput);
	// -----------------------------------------------------
	// Didn't find one.
	if (!strOutput.Exists())
		return "";

	// We found a note -- let's return it!
	//
	std::string pBuf = strOutput.Get();

	return pBuf;
}




int64_t OTAPI_Exec::Transaction_GetAmount(const std::string & SERVER_ID,
										 const std::string & USER_ID,
										 const std::string & ACCOUNT_ID,
										 const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		int64_t lBoxType = 0;

             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else if (theTransaction.Contains("expiredBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::expiredBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return -1;
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return -1;
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------

	OTString strOutput;
	const int64_t lAmount = pTransaction->GetReceiptAmount();

	return lAmount;
}




// There is a notice in my inbox, from the server, informing me of
// a pending transfer.
// Oh? And this notice is in reference to what transaction ID?
// This function will return the ID of the original transaction
// that the sender used to send me the transfer in the first place.
// Since his actual request is attached to the pending transaction,
// I can use this function to look up the number.
//
// Returns cheque #, or market offer #, or payment plan #, or pending transfer #
// (Meant to be used on inbox items.)
//
int64_t OTAPI_Exec::Transaction_GetDisplayReferenceToNum(const std::string & SERVER_ID,
														const std::string & USER_ID,
														const std::string & ACCOUNT_ID,
														const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	// -----------------------------------------------------
	// NO need to load abbreviated version here, since it already stores this number.
	//
	const int64_t lDisplayNum = theTransaction.GetReferenceNumForDisplay();
	return lDisplayNum;
}







// --------------------------------------------------
//
// Get Transaction Type  (internally uses GetTransactionTypeString().)
//
std::string OTAPI_Exec::Transaction_GetType(const std::string & SERVER_ID,
                                            const std::string & USER_ID,
                                            const std::string & ACCOUNT_ID,
                                            const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	// NO need to load abbreviated version, since it already stores this number.

	std::string pBuf = theTransaction.GetTypeString();

	return pBuf;
}


// Transactions do not have request numbers. However, if you have a replyNotice
// in your Nymbox, which is an OTTransaction object, it will CONTAIN a server
// reply to some previous message. This function will only work on a replyNotice,
// and it returns the actual request number of the server reply inside that notice.
// Used for calling OTAPI_Exec::HaveAlreadySeenReply() in order to see if we've already
// processed the reply for that message.
// Returns "" on Error.
//
int64_t OTAPI_Exec::ReplyNotice_GetRequestNum(const std::string & SERVER_ID,
											 const std::string & USER_ID,
											 const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID),
		theAccountID(USER_ID); // account IS user, for Nymbox (the only box that carries replyNotices...)

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strUserID(theUserID);
		OTLog::vError("%s: Error loading transaction from string. User ID: %s\n",__FUNCTION__, strUserID.Get());
		return -1;
	}

	// -----------------------------------------------------
	if (OTTransaction::replyNotice != theTransaction.GetType())
	{
		OTString strUserID(theUserID);
		OTLog::vError("%s: Unexpected transaction type: %s. (Expected: %s) User: %s\n",__FUNCTION__, theTransaction.GetTypeString(), "replyNotice", strUserID.Get());
		return -1;
	}
	// -----------------------------------------------------
	// NO need to load abbreviated version, since it already stores this number.

	const int64_t lRequestNumber = theTransaction.GetRequestNum();

	return lRequestNumber;
}




// --------------------------------------------------
//
// Get Transaction Date Signed  (internally uses OTTransaction::GetDateSigned().)
//
time64_t OTAPI_Exec::Transaction_GetDateSigned(const std::string & SERVER_ID,
											 const std::string & USER_ID,
											 const std::string & ACCOUNT_ID,
											 const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
    if (NULL == pNym) return OTTimeGetTimeFromSeconds(-1);
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
        return OTTimeGetTimeFromSeconds(-1);
	}
	// NO need to load abbreviated version here, since it already stores the date.
	// -----------------------------------------------------

	OTString strOutput;
	return theTransaction.GetDateSigned();
}


// --------------------------------------------------
//
// Get TransactionSuccess
//
// OT_TRUE  (1) == acknowledgment
// OT_FALSE (0) == rejection
// OT_ERROR(-1) == error_state (such as dropped message.)
//
// Returns OT_BOOL.
//
OT_BOOL OTAPI_Exec::Transaction_GetSuccess(const std::string & SERVER_ID,
                                           const std::string & USER_ID,
                                           const std::string & ACCOUNT_ID,
                                           const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return OT_ERROR;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated()) // Abbreviated.
	{
		int64_t lBoxType = 0;

		// --------------
             if (theTransaction.Contains("nymboxRecord"))           lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))            lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))           lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else if (theTransaction.Contains("expiredBoxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::expiredBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return OT_ERROR;
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return OT_ERROR;
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else  // NOT abbreviated.
		pTransaction = &theTransaction;
	// -----------------------------------------------------

	if (pTransaction->GetSuccess())
	{
		return OT_TRUE;
	}
	else
	{
		const int64_t lTransactionNum = pTransaction->GetTransactionNum();

		OTLog::vError("%s: ** FYI, this transaction has a 'failure' status from the server. TransNum: %lld\n", __FUNCTION__, lTransactionNum);
	}

	return OT_FALSE;
}


OT_BOOL OTAPI_Exec::Transaction_IsCanceled(const std::string & SERVER_ID,
                                           const std::string & USER_ID,
                                           const std::string & ACCOUNT_ID,
                                           const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return OT_ERROR;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

    // Note: This is an artifact from Transaction_GetSuccess, whose code was copied to make
    // this function. In reality, a cancelled transaction will never be abbreviated, since it
    // won't be used as any kind of box receipt in the first place. Rather, a canceled transaction
    // will only occur as a server reply to a transaction request. For example, if you cancel a
    // cheque, or cancel a payment plan, and that cancellation is successful, then the server
    // will return a "reply transaction" to that request, which has 'cancelled' set to true.
    // So why am I leaving this code here for now? We can trim it down later I suppose.
    //
	if (theTransaction.IsAbbreviated()) // Abbreviated.
	{
		int64_t lBoxType = 0;

		// --------------
             if (theTransaction.Contains("nymboxRecord"))           lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))            lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))           lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else if (theTransaction.Contains("expiredBoxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::expiredBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return OT_ERROR;
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return OT_ERROR;
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else  // NOT abbreviated.
		pTransaction = &theTransaction;
	// -----------------------------------------------------
	if (pTransaction->IsCancelled())
	{
		return OT_TRUE;
	}

	return OT_FALSE;
}



// --------------------------------------------------
//
// Get Balance Agreement Success
// (from a TRANSACTION.)
//                              true  (1) == acknowledgment
//                              false (0) == rejection
// NEW: -1 (-1) for error
//
OT_BOOL OTAPI_Exec::Transaction_GetBalanceAgreementSuccess(const std::string & SERVER_ID,
                                                           const std::string & USER_ID,
                                                           const std::string & ACCOUNT_ID,
                                                           const std::string & THE_TRANSACTION)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_TRANSACTION.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theUserID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return OT_ERROR;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())  // IF TRANSACTION IS ABBREVIATED (Ledger may only contain stubs, not full records...)
	{
		int64_t lBoxType = 0;

		// ----------------
             if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<int64_t>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<int64_t>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<int64_t>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::recordBox);
		else if (theTransaction.Contains("expiredBoxRecord"))	lBoxType = static_cast<int64_t>(OTLedger::expiredBox);
		else
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return OT_ERROR;
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<int64_t>(lBoxType));
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return OT_ERROR;
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------
	// At this point, I actually have the transaction pointer, so let's return its success status
	OTItem * pReplyItem = pTransaction->GetItem(OTItem::atBalanceStatement);

	if (NULL == pReplyItem)
		pReplyItem = pTransaction->GetItem(OTItem::atTransactionStatement);

	if (NULL == pReplyItem)
	{
		OTLog::vError("%s: good transaction (could have been abbreviated though) "
                      "but uncovered \"\" item pointer.\n", __FUNCTION__);
		return OT_ERROR; // Weird.
	}

	return (pReplyItem->GetStatus() == OTItem::acknowledgement) ? OT_TRUE : OT_FALSE;
}




// -----------------------------------------------------------
// GET BALANCE AGREEMENT SUCCESS (From a MESSAGE.)
//
// Returns true (1) for Success and false (0) for Failure.
// New: returns -1 (-1) for error.
//
OT_BOOL OTAPI_Exec::Message_GetBalanceAgreementSuccess(const std::string & SERVER_ID,
                                                       const std::string & USER_ID,
                                                       const std::string & ACCOUNT_ID,
                                                       const std::string & THE_MESSAGE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCOUNT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_FAIL; }
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return OT_ERROR;
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@processNymbox")) &&
		(false == theMessage.m_strCommand.Compare("@processInbox"))
		)
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return OT_ERROR;
	}

	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strLedger(theMessage.m_ascPayload);

	if (!strLedger.Exists())
	{
		OTLog::vOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return OT_ERROR;
	}

	// ------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}

	// At this point, I know theLedger loaded successfully.

	if (theLedger.GetTransactionCount() <= 0)
	{
		OTLog::vError("%s bad count in message ledger: %d\n", __FUNCTION__, theLedger.GetTransactionCount());
		return OT_ERROR; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	OTTransaction * pReplyTransaction = theLedger.GetTransactionByIndex(0); // Right now this is a defacto standard. (only 1 transaction per message ledger, excepting process inbox. <== why? That's one as well I thought. And has multiple items attached.)
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.

	if (NULL == pReplyTransaction)
	{
		OTLog::vError("%s good index but uncovered \"\" pointer there: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
	}

	// At this point, I actually have the transaction pointer, so let's return its success status
	OTItem * pReplyItem = pReplyTransaction->GetItem(OTItem::atBalanceStatement);

	if (NULL == pReplyItem)
		pReplyItem = pReplyTransaction->GetItem(OTItem::atTransactionStatement);

	if (NULL == pReplyItem)
	{
		OTLog::vError("%s good index but uncovered \"\" item pointer: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
	}

	if (pReplyItem->GetStatus() == OTItem::acknowledgement)
	{
		return OT_TRUE;
	}

	return OT_FALSE;
}









/*
std::string OTAPI_Exec::LoadPurse(const std::string & SERVER_ID,
                                  std::string ASSET_TYPE_ID,
                                  std::string USER_ID) // returns "", or a purse.
{
    OT_ASSERT_MSG("" != SERVER_ID, "Null SERVER_ID passed in.");
    OT_ASSERT_MSG("" != ASSET_TYPE_ID, "Null ASSET_TYPE_ID passed in.");
    OT_ASSERT_MSG("" != USER_ID, "Null USER_ID passed in.");

    const OTIdentifier theServerID(SERVER_ID);
    const OTIdentifier theAssetID(ASSET_TYPE_ID);
    const OTIdentifier theUserID(USER_ID);

    // There is an OT_ASSERT in here for memory failure,
    // but it still might return "" if various verification fails.
    OTPurse * pPurse = OTAPI()->LoadPurse(theServerID, theAssetID, theUserID);

    // Make sure it gets cleaned up when this goes out of scope.
    OTCleanup<OTPurse>	thePurseAngel(pPurse); // I pass the pointer, in case it's "".

    if (NULL == pPurse)
    {
        OTLog::vOutput(0, "Failure calling OT_API::LoadPurse in OTAPI_Exec::LoadPurse.\n "
                       "Server: %s\n Asset Type: %s\n", SERVER_ID, ASSET_TYPE_ID);
    }
    else // success
    {
        OTString strOutput(*pPurse); // For the output

        std::string pBuf = strOutput.Get();



        return pBuf;
    }

    return "";
}
*/








// --------------------------------------------------




// PURSE FUNCTIONS





// Warning! This will overwrite whatever purse is there.
// The proper way to use this function is, LOAD the purse,
// then IMPORT whatever other purse you want into it, then
// SAVE it again.
bool OTAPI_Exec::SavePurse(const std::string & SERVER_ID,
						const std::string & ASSET_TYPE_ID,
						const std::string & USER_ID,
						const std::string & THE_PURSE) // returns bool
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__;
	// -------------------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theUserID(USER_ID);
	const OTString     strPurse(THE_PURSE);
	// -------------------------------------------------------------
	bool bSuccess = false;
	// -------------------------------------------------------------
	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);

	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
		// NOTE: no need to verify the server / asset ID here, since the call
		// to SavePurse already does that.
		//
		//      if ((theServerID    != thePurse.GetServerID()) ||
		//          (theAssetTypeID != thePurse.GetAssetID()))
		//      {
		//          OTLog::vOutput(0, "%s: Failure loading purse from string; server "
		//                         "or asset ID didn't match what was expected:\n%s\n",
		//                         strFunc, strPurse.Get());
		//      }
		if (OTAPI()->SavePurse(theServerID, theAssetTypeID, theUserID, thePurse))
		{
			bSuccess = true;
		}
		else
		{
			OTLog::vOutput(0, "%s: Failure saving purse:\n%s\n", strFunc.c_str(), strPurse.Get());
		}
	}
	else
	{
		OTLog::vOutput(0, "%s: Failure loading purse from string:\n%s\n", strFunc.c_str(), strPurse.Get());
	}

	return bSuccess;
}


// --------------------------------------------------------------
// LOAD PURSE -- (from local storage)
//
// Based on Asset Type ID: load a purse, a public mint, or an asset contract
// and return it as a string -- or return "" if it wasn't found.
//
std::string OTAPI_Exec::LoadPurse(const std::string & SERVER_ID,
							 const std::string & ASSET_TYPE_ID,
							 const std::string & USER_ID) // returns "", or a purse.
{
	if (SERVER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"     ); OT_FAIL; }
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID" ); OT_FAIL; }
	if (USER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"       ); OT_FAIL; }
	// -----------------------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	const OTIdentifier theUserID(USER_ID);
	// -----------------------------------------------------------------
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return "" if various verification fails.

	OTPurse * pPurse = OTAPI()->LoadPurse(theServerID, theAssetID, theUserID);

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPurse>	thePurseAngel(pPurse); // I pass the pointer, in case it's "".

	if (NULL == pPurse)
	{
		OTLog::vOutput(2, "OTAPI_Exec::LoadPurse() received null when called OT_API::LoadPurse(). "
			"Server: %s Asset Type: %s\n", SERVER_ID.c_str(), ASSET_TYPE_ID.c_str());
	}
	else // success
	{
		OTString strOutput(*pPurse); // For the output
		std::string pBuf = strOutput.Get();
		return pBuf;
	}

	return "";
}




// --------------------------------------------------------------------
// Get Purse Total Value  (internally uses GetTotalValue().)
//
// Returns the purported sum of all the tokens within.
//
int64_t OTAPI_Exec::Purse_GetTotalValue(const std::string & SERVER_ID,
										const std::string & ASSET_TYPE_ID,
										const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }
	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	// -----------------------------------------------------
	OTString strPurse(THE_PURSE);
	OTPurse  thePurse(theServerID, theAssetTypeID);

	if (false == thePurse.LoadContractFromString(strPurse))
	{
		OTString strAssetTypeID(theAssetTypeID);
		OTLog::vError("%s: Error loading purse from string. Asset Type ID: %s\n",
			__FUNCTION__, strAssetTypeID.Get());
		return -1;
	}
	// -----------------------------------------------------
	int64_t lTotalValue = 0;

	if (thePurse.GetTotalValue() > 0)
		lTotalValue = thePurse.GetTotalValue();

	return lTotalValue;
}



// ---

// Returns a count of the tokens inside this purse. (Coins.)
// or -1 in case of error.
//
int32_t OTAPI_Exec::Purse_Count(const std::string & SERVER_ID,
                                const std::string & ASSET_TYPE_ID,
                                const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID),
                    theAssetTypeID(ASSET_TYPE_ID);
	const OTString     strPurse(THE_PURSE);
	// -------------------------------------------------------------
	OTPurse thePurse(theServerID, theAssetTypeID);

	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse) &&
		// --------------------------------------
			(thePurse.GetServerID() == theServerID) &&
			(thePurse.GetAssetID()  == theAssetTypeID))
	{
		return thePurse.Count();
	}

	return OT_ERROR;
}


// ---------
// Some purses are encrypted to a specific Nym.
// Whereas other purses are encrypted to a passphrase.
// This function returns bool and lets you know, either way.
//
bool OTAPI_Exec::Purse_HasPassword(const std::string & SERVER_ID,
                                      const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID);
	const OTString     strPurse(THE_PURSE);
	// -------------------------------------------------------------
	OTPurse thePurse(theServerID);

	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse) &&
		// --------------------------------------
			(thePurse.GetServerID() == theServerID))
	{
		return thePurse.IsPasswordProtected();
	}

	return false;
}





// returns "", or a purse.
//
std::string OTAPI_Exec::CreatePurse(const std::string & SERVER_ID,
								const std::string & ASSET_TYPE_ID,
								const std::string & OWNER_ID,
								const std::string & SIGNER_ID)
{
	if (SERVER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"     ); OT_FAIL; }
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID" ); OT_FAIL; }
	if (OWNER_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_ID"      ); OT_FAIL; }
	if (SIGNER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"     ); OT_FAIL; }

	std::string strFunc = __FUNCTION__;

	const OTIdentifier  theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theOwnerID(OWNER_ID),
		theSignerID(SIGNER_ID);
	// -----------------------------------------------------
	OTPasswordData thePWData("Creating a cash purse. Enter wallet master password.");
	// -----------------------------------------------------
	OTPseudonym * pOwnerNym  = OTAPI()->GetOrLoadNym(theOwnerID, false, strFunc.c_str(), &thePWData);
	if (NULL == pOwnerNym) return "";
	// -----------------------------------------------------
	OTPseudonym * pSignerNym = OTAPI()->GetOrLoadPrivateNym(theSignerID, false, strFunc.c_str(), &thePWData); // These copiously log, and ASSERT.
	if (NULL == pSignerNym) return "";
	// By this point, pSignerNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI()->CreatePurse(theServerID, theAssetTypeID, theOwnerID);
	OTCleanup<OTPurse> theAngel(pPurse);

	if (NULL != pPurse)
	{
		pPurse->SignContract(*pSignerNym, &thePWData);
		pPurse->SaveContract();
		// -------------
		const OTString strOutput(*pPurse);
		// -------------
		std::string pBuf = strOutput.Get();

		return pBuf;
	}
	return "";
}




// When we create a password-protected purse, OWNER_ID has changed to SIGNER_ID,
// since we still need a Nym to sign it (in order to save it to string.) But this
// Nym will not be the owner. There is no owner, and the tokens are not encrypted
// to any Nym (but instead to a passphrase.)
//
// returns "", or a purse.
//
std::string OTAPI_Exec::CreatePurse_Passphrase(const std::string & SERVER_ID,
										  const std::string & ASSET_TYPE_ID,
										  const std::string & SIGNER_ID)
{
	if (SERVER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (SIGNER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_FAIL; }
	// -----------------------------------------------------
	const OTIdentifier
        theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theSignerID(SIGNER_ID);
	// -----------------------------------------------------
	OTPasswordData thePWData("Creating a password-protected cash purse.");
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theSignerID, false, __FUNCTION__, &thePWData); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI()->CreatePurse_Passphrase(theServerID, theAssetTypeID);
	OTCleanup<OTPurse> theAngel(pPurse);

	if (NULL != pPurse)
	{
		pPurse->SignContract(*pNym, &thePWData);
		pPurse->SaveContract();
		// -------------
		const OTString strOutput(*pPurse);
		// -------------
		std::string pBuf = strOutput.Get();

		return pBuf;
	}
	return "";
}




// Returns the TOKEN on top of the stock (LEAVING it on top of the stack,
// but giving you a decrypted string copy of it.)
//
// OWNER_ID can be "", **if** the purse is password-protected.
// (It's just ignored in that case.) Otherwise MUST contain the NymID for
// the Purse owner (necessary to decrypt the token.)
//
// returns "" if failure.
//
std::string OTAPI_Exec::Purse_Peek(const std::string & SERVER_ID,
							  const std::string & ASSET_TYPE_ID,
							  const std::string & OWNER_ID, // This should be "", **IF** purse is password-protected. Otherwise MUST contain the NymID for the Purse owner (necessary to decrypt the token.)
							  const std::string & THE_PURSE)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	//if (OWNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_ID"			); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Exec::Purse_Peek";
	// -----------------------------------------------------
    OTPasswordData thePWData("Peeking at cash purse contents.");
	// -----------------------------------
	const bool & bDoesOwnerIDExist = (("" != OWNER_ID) && ('\0' != OWNER_ID[0])); // If bDoesOwnerIDExist is not true, then the purse MUST be password-protected.
	// -----------------------------------
	OTIdentifier  theOwnerID;
	OTPseudonym * pNym = NULL;
	if (bDoesOwnerIDExist)
	{
		const OTString strOwnerID(OWNER_ID);

		if (strOwnerID.Exists())
		{
			theOwnerID.SetString(strOwnerID);
			pNym = OTAPI()->GetOrLoadPrivateNym(theOwnerID, false, strFunc.c_str(), &thePWData); // These copiously log, and ASSERT.
		}
		if (NULL == pNym) return "";
	}
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID);
	const OTString     strPurse(THE_PURSE);
	// -----------------------------------------------------
	OTToken * pToken = OTAPI()->Purse_Peek(theServerID, theAssetTypeID,
		strPurse,
		bDoesOwnerIDExist ? &theOwnerID : NULL,
		NULL);
	OTCleanup<OTToken> theTokenAngel(pToken);
	// -----------------------------------------------------
	if (NULL != pToken)
	{
		pToken->SaveContractRaw(strOutput);

		std::string pBuf = strOutput.Get();

		return pBuf;
	}
	else
		OTLog::vOutput(0, "%s: Failed peeking at a token on a cash purse.\n", strFunc.c_str());

	return "";
}



// Removes the token from the top of the stock and DESTROYS IT,
// and RETURNS THE UPDATED PURSE (with the token now missing from it.)
//
// WARNING: Do not call this function unless you have PEEK()d FIRST!!
// Otherwise you will lose the token and get left "holding the bag".
//
// returns "" if failure.
//
std::string OTAPI_Exec::Purse_Pop(const std::string & SERVER_ID,
							 const std::string & ASSET_TYPE_ID,
							 const std::string & OWNER_OR_SIGNER_ID, // The purse, in order to be changed, must be re-signed, which requires a private Nym. If the purse is password-protected, then there's no owner, but you still need to pass a Nym in here to sign it (doesn't really matter which one, as long as the private key is available, for signing.) In that case, he's the signer. But if the purse DOES have a Nym owner, then you MUST pass the owner's Nym ID here, in order for this action to be successful. (Because we must be able to load the private key for that Nym, in order to perform the pop. In which case we might as well use the same Nym for signing...)
							 const std::string & THE_PURSE)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (OWNER_OR_SIGNER_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_OR_SIGNER_ID"	); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Exec::Purse_Pop";
	// -----------------------------------------------------
	const OTString strReason("Popping a token off of a cash purse.");
	OTPasswordData thePWData(strReason);
	// -----------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theNymID(OWNER_OR_SIGNER_ID);
	const OTString     strPurse(THE_PURSE);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theNymID, false, strFunc.c_str(), &thePWData); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI()->Purse_Pop(theServerID, theAssetTypeID,
		strPurse,
		&theNymID, // Note: if the purse is password-protected, then this parameter is ignored.
		&strReason);
	OTCleanup<OTPurse> thePurseAngel(pPurse);
	// -----------------------------------------------------
	if (NULL != pPurse)
	{
		pPurse->ReleaseSignatures();
		pPurse->SignContract(*pNym, &thePWData);
		pPurse->SaveContract();

		pPurse->SaveContractRaw(strOutput);
		std::string pBuf = strOutput.Get();

		return pBuf;
	}
	else
		OTLog::vOutput(0, "%s: Failed popping a token off of a cash purse.\n", strFunc.c_str());

	return "";
}



// Makes an exact copy of a purse, except with no tokens inside. (Value of zero.)
// Useful when you need to create a temporary purse for moving tokens around, and
// you don't want some new symmetric/master key being generated for that purse as
// though it were really some new "other purse."
// For example, if you have a password-protected purse, you might want to pop all of
// the tokens off of it, and as you iterate, re-assign half of them to new ownership,
// push those onto a new purse owned by that new owner. But you only want to do this
// with half of the tokens... the other half of the tokens, you just want to push onto
// a temp purse (for the loop) that's owned by the original owner, so you can then save
// it back over the original in storage (since it contains "all the tokens that WEREN'T
// deposited" or "all the tokens that WEREN'T exported" etc.
//
// The point? If the "original owner" is a password-protected purse with a symmetric
// key, then you can't just generate some new "temp purse" without also generating a
// whole new KEY, which you DO NOT want to do. You also don't want to have to deal with
// re-assigning ownership back and forth between the two purses -- you just want to
// shove some tokens into one temporarily so you can finish your loop.
// You could take the original purse and make a copy of it, and then just pop all the
// tokens off of it one-by-one, but that is very cumbersome and expensive. But that'd
// be the only way to get a copy of the original purse with the SAME symmetric key,
// except empty, so you can use it as a temp purse.
// Therefore, to make that easier and solve that whole dilemma, I present: OTAPI_Exec::Purse_Empty.
// OTAPI_Exec::Purse_Empty takes a purse and returns an empty version of it (except if there's
// a symmetric/master key inside, those are preserved, so you can use it as a temp purse.)
//
// This function is effectively the same thing as calling Pop until the purse is empty.
// Returns: the empty purse, or "" if failure.
//
std::string OTAPI_Exec::Purse_Empty(const std::string & SERVER_ID,
								const std::string & ASSET_TYPE_ID,
								const std::string & SIGNER_ID,
								const std::string & THE_PURSE)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (SIGNER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Exec::Purse_Empty";
	// -----------------------------------------------------
	const OTString strReason("Creating an empty copy of a cash purse.");
	OTPasswordData thePWData(strReason);
	// -----------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theNymID(SIGNER_ID);
	const OTString     strPurse(THE_PURSE);
	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theNymID, false, strFunc.c_str(), &thePWData); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI()->Purse_Empty(theServerID, theAssetTypeID, strPurse, &strReason);
	OTCleanup<OTPurse> thePurseAngel(pPurse);
	// -----------------------------------------------------
	if (NULL != pPurse)
	{
		pPurse->ReleaseSignatures();
		pPurse->SignContract(*pNym, &thePWData);
		pPurse->SaveContract();

		pPurse->SaveContractRaw(strOutput);
		std::string pBuf = strOutput.Get();

		return pBuf;
	}
	else
		OTLog::vOutput(0, "%s: Failed emptying a cash purse.\n", strFunc.c_str());

	return "";

}


// Pushes a token onto the stack (of the purse.)
// Returns the updated purse (now including the token.)
//
// Returns "" if failure.
//
std::string OTAPI_Exec::Purse_Push(const std::string & SERVER_ID,
							  const std::string & ASSET_TYPE_ID,
							  const std::string & SIGNER_ID, // The purse, in order to be changed, must be re-signed, which requires a private Nym. Even if the purse is password-protected, then there's no owner, but you still need to pass a Nym in here to sign it (doesn't really matter which one, but must have private key for signing.)
							  const std::string & OWNER_ID, // If the purse is password-protected, then there's no owner, and this owner parameter should be "". However, if the purse DOES have a Nym owner, then you MUST pass the owner's Nym ID here, in order for this action to be successful. Furthermore, the public key for that Nym must be available, in order to encrypt the token being pushed into the purse. (Private key NOT necessary for owner, in this case.) If this fails due to public key not being available, just download it from the server and try again.
							  const std::string & THE_PURSE,
							  const std::string & THE_TOKEN)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"     ); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID" ); OT_FAIL; }
	if (SIGNER_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"     ); OT_FAIL; }
//	if (OWNER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OWNER_ID"      ); OT_FAIL; }
	if (THE_PURSE.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"     ); OT_FAIL; }
	if (THE_TOKEN.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"     ); OT_FAIL; }

	// -------------------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Exec::Purse_Push";
	// -----------------------------------------------------
	const OTString strReason("Pushing a token onto a cash purse.");
	OTPasswordData thePWData(strReason);
	// -----------------------------------
	const bool & bDoesOwnerIDExist = (("" != OWNER_ID) && ('\0' != OWNER_ID[0])); // If bDoesOwnerIDExist is not true, then the purse MUST be password-protected.
	// -----------------------------------
	OTIdentifier  theOwnerID;
	OTPseudonym * pOwnerNym = NULL;
	if (bDoesOwnerIDExist)
	{
		const OTString strOwnerID(OWNER_ID);

		if (strOwnerID.Exists())
		{
			theOwnerID.SetString(strOwnerID);
			pOwnerNym = OTAPI()->GetOrLoadNym(theOwnerID, false, strFunc.c_str(), &thePWData); // These copiously log, and ASSERT.
		}
		if (NULL == pOwnerNym) return "";
	}
	// By this point, pOwnerNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID);
	const OTString     strPurse(THE_PURSE), strToken(THE_TOKEN);
	// -----------------------------------------------------
	OTPurse * pPurse = OTAPI()->Purse_Push(theServerID, theAssetTypeID,
		strPurse, strToken,
		bDoesOwnerIDExist ? &theOwnerID : NULL, // Note: if the purse is password-protected, then this parameter should be "".
		&strReason);
	OTCleanup<OTPurse> thePurseAngel(pPurse);
	// -----------------------------------------------------
	if (NULL != pPurse)
	{
		const OTIdentifier theSignerID(SIGNER_ID);
		OTPseudonym * pSignerNym = OTAPI()->GetOrLoadPrivateNym(theSignerID, false, strFunc.c_str(), &thePWData); // These copiously log, and ASSERT.
		if (NULL == pSignerNym) return "";
		// By this point, pSignerNym is a good pointer, and is on the wallet. (No need to cleanup.)
		// -----------------------------------------------------
		pPurse->ReleaseSignatures();
		pPurse->SignContract(*pSignerNym, &thePWData);
		pPurse->SaveContract();

		pPurse->SaveContractRaw(strOutput);
		std::string pBuf = strOutput.Get();

		return pBuf;
	}
	else
		OTLog::vOutput(0, "%s: Failed pushing a token onto a cash purse.\n", strFunc.c_str());

	return "";

}


// ------------------


//
// Returns bool
// Should handle duplicates. Should load, merge, and save.
//
bool OTAPI_Exec::Wallet_ImportPurse(const std::string & SERVER_ID,
								 const std::string & ASSET_TYPE_ID,
								 const std::string & USER_ID,
								  // -----------------------
								 const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }

	// -----------------------------------------------------
	std::string strFunc = __FUNCTION__; //"OTAPI_Exec::Wallet_ImportPurse";
	// -----------------------------------------------------
	OTString strReason("Importing a cash purse into the wallet.");
	//  OTPasswordData thePWData(strReason);
	// -----------------------------------------------------
	const
		OTIdentifier  theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);
	const
		OTString      strNewPurse(THE_PURSE);
	// -----------------------------------------------------
	// THE_PURSE (the new purse) either is for a Nym, or a Symmetric Key.
	// If it's for a Nym, it either has a NymID, or the ID is left blank.
	//
	// This call already logs on failure, so I won't bother logging again here.
	//
	OTString strDisplay("");

	const bool & bImported = OTAPI()->Wallet_ImportPurse(theServerID, theAssetTypeID, theUserID,
		strNewPurse, &strDisplay);
	// --------------------------------------------------------------
	return bImported ? true : false;
}












// TODO:!!!!!  NEW!!!!!

// Messages the server. If failure, make sure you didn't lose that purse!!
// If success, the new tokens will be returned shortly and saved into the appropriate purse.
// Note that an asset account isn't necessary to do this... just a nym operating cash-only.
// The same as exchanging a 20-dollar bill at the teller window for a replacement bill.
//
// You could also have a webpage operated by the transaction server, where a dummy nym
// performs cash exchanges using a single page with a text area (for copying and pasting
// cash tokens.) This way all cash token exchanges can go through the same Nym. (Although
// it must be stressed, that the cash is untraceable whether you use your own Nym or not.)
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::exchangePurse(const std::string & SERVER_ID,
                                  const std::string & ASSET_TYPE_ID,
                                  const std::string & USER_ID,
                                  const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }

	// todo:  exchange message.
	OTLog::vError("%s: TODO (NOT CODED YET) OTAPI_Exec::exchangePurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", __FUNCTION__, SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str());

	return -1;
}






// the GUI needs to be able to export cash from one Nym to another,
// so a function has been provided for doing so to the actual Token IDs (not just the purse.
// Understand that even when you decrypt a token out of a purse, the token ID itself is still
// encrypted within that token. That is what this function is for.
//
// returns: the updated token itself in string form.
//

//
// ALLOW the caller to pass a symmetric key here, instead of either Nym ID.
// We'll load it up and use it instead of a Nym. Update: make that a purse.
// These tokens already beint64_t to specific purses, so just pass the purse here
//
// Done: Also, add a key cache with a timeout (similar to Master Key) where we can stash
// any already-loaded symmetric keys, and a thread wipes them out later. That way
// even if we have to load the key each time this func is called, we still avoid the
// user having to enter the passphrase more than once per timeout period.
//
// Done also: allow a "Signer ID" to be passed in here, since either Nym could potentially
// now be a symmetric key.

std::string OTAPI_Exec::Token_ChangeOwner(const std::string & SERVER_ID,
									 const std::string & ASSET_TYPE_ID,
									 const std::string & THE_TOKEN,
									 const std::string & SIGNER_NYM_ID,
									 const std::string & OLD_OWNER, // Pass a NymID here, or a purse.
									 const std::string & NEW_OWNER) // Pass a NymID here, or a purse.
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_FAIL; }
	if (SIGNER_NYM_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_FAIL; }
	if (OLD_OWNER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "OLD_OWNER"			); OT_FAIL; }
	if (NEW_OWNER.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NEW_OWNER"			); OT_FAIL; }

	// -----------------------------------------------------
	std::string strFunc = __FUNCTION__; //OTAPI_Exec::Token_ChangeOwner
	// -----------------------------------------------------
	const
		OTIdentifier	theServerID(SERVER_ID),
		theAssetTypeID(ASSET_TYPE_ID),
		theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	const
		OTString      strOldOwner(OLD_OWNER), // Either of these MIGHT contain a Nym ID, OR might contain a purse...
		strNewOwner(NEW_OWNER); // (purse is passed in cases where the token is encrypted with a passphrase aka symmetric crypto, versus being encrypted to a Nym's public key.)
	// -----------------------------------------------------
	OTString      strToken   (THE_TOKEN);
	// -----------------------------------------------------
	OTToken * pToken = OTAPI()->Token_ChangeOwner(theServerID, theAssetTypeID,
		strToken, theSignerNymID,
		strOldOwner,  // Pass a NymID here as a string, or a purse. (IF symmetrically encrypted, the relevant key is in the purse.)
		strNewOwner); // Pass a NymID here as a string, or a purse. (IF symmetrically encrypted, the relevant key is in the purse.)
	OTCleanup<OTToken> theTokenAngel(pToken);
	// -----------------------------------------------------
	if (NULL != pToken) // Success!
	{
		const OTString strOutput(*pToken);

		std::string pBuf = strOutput.Get();

		return pBuf;
	}

	return "";
}


// --------------


// Returns an encrypted form of the actual blinded token ID.
// (There's no need to decrypt the ID until redeeming the token, when
// you re-encrypt it to the server's public key, or until spending it,
// when you re-encrypt it to the recipient's public key, or exporting
// it, when you create a dummy recipient and attach it to the purse.)
//
std::string OTAPI_Exec::Token_GetID(const std::string & SERVER_ID,
								const std::string & ASSET_TYPE_ID,
								const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput("0");

    OTString strToken(THE_TOKEN);
    OTToken * pToken = OTToken::TokenFactory(strToken, theServerID, theAssetTypeID);
    OTCleanup<OTToken> theTokenAngel(pToken);

    if (NULL != pToken) // TokenFactory instantiates AND loads from string.
	{
		const OTASCIIArmor & ascSpendable = pToken->GetSpendable(); // encrypted version of Token ID, used as an "ID" on client side.

		strOutput.Format("%s", ascSpendable.Get());
	}

	std::string pBuf = strOutput.Get();

	return pBuf;
}



// The actual cash value of the token. Returns a int64_t int32_t as a string.
//
int64_t OTAPI_Exec::Token_GetDenomination(const std::string & SERVER_ID,
										 const std::string & ASSET_TYPE_ID,
										 const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput("0");

    OTString strToken(THE_TOKEN);
    OTToken * pToken = OTToken::TokenFactory(strToken, theServerID, theAssetTypeID);
    OTCleanup<OTToken> theTokenAngel(pToken);

    if (NULL != pToken) // TokenFactory instantiates AND loads from string.
	{
		return pToken->GetDenomination();
	}
	else return -1;
}



// OTAPI_Exec::Token_GetSeries
// Returns -1 for error.
// Otherwise returns the series number of this token. (Int.)
//
int32_t OTAPI_Exec::Token_GetSeries(const std::string & SERVER_ID,
						  const std::string & ASSET_TYPE_ID,
						  const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput;

    OTString strToken(THE_TOKEN);
    OTToken * pToken = OTToken::TokenFactory(strToken, theServerID, theAssetTypeID);
    OTCleanup<OTToken> theTokenAngel(pToken);

    if (NULL != pToken) // TokenFactory instantiates AND loads from string.
		return pToken->GetSeries();

	return -1;
}




// the date is seconds since Jan 1970, but returned as a string.
//
time64_t OTAPI_Exec::Token_GetValidFrom(const std::string & SERVER_ID,
									  const std::string & ASSET_TYPE_ID,
									  const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput;

    OTString strToken(THE_TOKEN);
    OTToken * pToken = OTToken::TokenFactory(strToken, theServerID, theAssetTypeID);
    OTCleanup<OTToken> theTokenAngel(pToken);

    if (NULL != pToken) // TokenFactory instantiates AND loads from string.
	{
		return pToken->GetValidFrom();
	}
    return OTTimeGetTimeFromSeconds(-1);
}


// the date is seconds since Jan 1970, but returned as a string.
//
time64_t OTAPI_Exec::Token_GetValidTo(const std::string & SERVER_ID,
									const std::string & ASSET_TYPE_ID,
									const std::string & THE_TOKEN)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strOutput;

    OTString strToken(THE_TOKEN);
    OTToken * pToken = OTToken::TokenFactory(strToken, theServerID, theAssetTypeID);
    OTCleanup<OTToken> theTokenAngel(pToken);

    if (NULL != pToken) // TokenFactory instantiates AND loads from string.
	{
		return pToken->GetValidTo();
	}
    return OTTimeGetTimeFromSeconds(-1);
}

// ---------

std::string OTAPI_Exec::Token_GetAssetID(const std::string & THE_TOKEN)
{
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_FAIL; }

	OTString strOutput;

    OTString strToken(THE_TOKEN);
    OTToken * pToken = OTToken::TokenFactory(strToken);
    OTCleanup<OTToken> theTokenAngel(pToken);

    if (NULL != pToken) // TokenFactory instantiates AND loads from string.
	{
		const OTIdentifier & theID = pToken->GetAssetID();
		theID.GetString(strOutput);
	}

	std::string pBuf = strOutput.Get();

	return pBuf;
}


std::string OTAPI_Exec::Token_GetServerID(const std::string & THE_TOKEN)
{
	if (THE_TOKEN.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_FAIL; }

	OTString strOutput;

    OTString strToken(THE_TOKEN);
    OTToken * pToken = OTToken::TokenFactory(strToken);
    OTCleanup<OTToken> theTokenAngel(pToken);

    if (NULL != pToken) // TokenFactory instantiates AND loads from string.
	{
		const OTIdentifier & theID = pToken->GetServerID();
		theID.GetString(strOutput);
	}

	std::string pBuf = strOutput.Get();

	return pBuf;
}












// --------------------------------------------------------------
// IS BASKET CURRENCY ?
//
// Tells you whether or not a given asset type is actually a basket currency.
//
// returns bool (true or false aka 1 or 0.)
//
bool OTAPI_Exec::IsBasketCurrency(const std::string & ASSET_TYPE_ID)
{
	if (ASSET_TYPE_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_FAIL; }

	const OTIdentifier theAssetTypeID(ASSET_TYPE_ID);

	if (OTAPI()->IsBasketCurrency(theAssetTypeID))
		return true;
	else
		return false;
}



// --------------------------------------------------------------------
// Get Basket Count (of backing asset types.)
//
// Returns the number of asset types that make up this basket.
// (Or zero.)
//
int32_t OTAPI_Exec::Basket_GetMemberCount(const std::string & ASSET_TYPE_ID)
{
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID" ); OT_FAIL; }

	const OTIdentifier theAssetTypeID(ASSET_TYPE_ID);

	return OTAPI()->GetBasketMemberCount(theAssetTypeID);
}



// --------------------------------------------------------------------
// Get Asset Type of a basket's member currency, by index.
//
// (Returns a string containing Asset Type ID, or "").
//
std::string OTAPI_Exec::Basket_GetMemberType(const std::string & BASKET_ASSET_TYPE_ID,
                                             const int32_t & nIndex)
{
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_FAIL; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	OTIdentifier theOutputMemberType;

	bool bGotType = OTAPI()->GetBasketMemberType(theAssetTypeID,
		nIndex,
		theOutputMemberType);
	if (false == bGotType)
		return "";

	OTString strOutput(theOutputMemberType);

	std::string pBuf = strOutput.Get();

	return pBuf;
}




// ----------------------------------------------------
// GET BASKET MINIMUM TRANSFER AMOUNT
//
// Returns a int64_t (as string) containing the minimum transfer
// amount for the entire basket.
//
// FOR EXAMPLE:
// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
// then the minimum transfer amount for the basket is 10. This function
// would return a string containing "10", in that example.
//
int64_t OTAPI_Exec::Basket_GetMinimumTransferAmount(const std::string & BASKET_ASSET_TYPE_ID)
{
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_FAIL; }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	int64_t lMinTransAmount = OTAPI()->GetBasketMinimumTransferAmount(theAssetTypeID);

	if (0 >= lMinTransAmount)
	{
		OTLog::vError("%s: returned 0 (or negitive). Strange... what basket is this?\n", __FUNCTION__);
		return -1;
	}

	return lMinTransAmount;
}



// ----------------------------------------------------
// GET BASKET MEMBER's MINIMUM TRANSFER AMOUNT
//
// Returns a int64_t (as string) containing the minimum transfer
// amount for one of the member currencies in the basket.
//
// FOR EXAMPLE:
// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
// then the minimum transfer amount for the member currency at index
// 0 is 2, the minimum transfer amount for the member currency at
// index 1 is 5, and the minimum transfer amount for the member
// currency at index 2 is 8.
//
int64_t OTAPI_Exec::Basket_GetMemberMinimumTransferAmount(const std::string & BASKET_ASSET_TYPE_ID,
														  const int32_t & nIndex)
{
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_FAIL; }

	if (0 > nIndex) { OTLog::vError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	int64_t lMinTransAmount = OTAPI()->GetBasketMemberMinimumTransferAmount(theAssetTypeID, nIndex);

	if (0 >= lMinTransAmount)
	{
		OTLog::vError("%s: returned 0 (or negitive). Strange... what basket is this?\n", __FUNCTION__);
		return -1;
	}

	return lMinTransAmount;
}



// ----------------------------------------------------




// --------------------------------------------------

// MESSAGES BEING SENT TO THE SERVER:




// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::checkServerID(const std::string & SERVER_ID,
						const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI()->checkServerID(theServerID, theUserID);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::createUserAccount(const std::string & SERVER_ID,
							const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI()->createUserAccount(theServerID, theUserID);
}

// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::deleteUserAccount(const std::string & SERVER_ID,
							const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI()->deleteUserAccount(theServerID, theUserID);
}



// If THE_MESSAGE is of command type @usageCredits, and IF it was a SUCCESS,
// then this function returns the usage credits BALANCE (it's a int64_t int32_t, but
// passed as a string). If you adjusted the balance using the usageCredits
// message (THE_MESSAGE being the server's reply to that) then you will see
// the balance AFTER the adjustment. (The "Current" Usage Credits balance.)
//
// UPDATE: Notice that we now return -2 in the case of all errors.
//         This is because the lowest possible actual value is -1.
//
//         - Basically a 0 or positive value means that usage credits are
//           actually turned on (on the server side) and that you are seeing
//           the actual usage credits value for that Nym.
//
//         - Whereas a -2 value means there was an error.
//
//         - Whereas a -1 value means that usage credits are turned off (on
//           the server side) OR that the Nym has been given the special -1
//           setting for usage credits, which enables him to operate as if he
//           has unlimited usage credits.
//
int64_t OTAPI_Exec::Message_GetUsageCredits(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"); OT_FAIL; }

	OTString  strMessage(THE_MESSAGE);
	OTMessage theMessage;

	if (!strMessage.Exists())
	{
		OTLog::vError("%s: Error: THE_MESSAGE doesn't exist.\n", __FUNCTION__);
        return -2;
	}

	if (!theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vError("%s: Failed loading message from string.\n", __FUNCTION__);
        return -2;
	}

	if (false == theMessage.m_bSuccess)
	{
        OTLog::vError("%s: Message success == false, thus unable to report Usage Credits balance. (Returning -2.)\n", __FUNCTION__);
        return -2;
	}

	if (false == theMessage.m_strCommand.Compare("@usageCredits"))
	{
        OTLog::vError("%s: THE_MESSAGE is supposed to be of command type \"@usageCredits\", but instead it's a: %s\n (Failure. Returning -2.)",
            __FUNCTION__, theMessage.m_strCommand.Get());
        return -2;
	}

	// ----------------------------------------------
	// By this point, we know the message was a successful @usageCredits, loaded
	// properly from the string that was passed in. Let's return the usage credits
	// balance (a int64_t int32_t, returned in string format.)

	return theMessage.m_lDepth;
}



// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::usageCredits(const std::string & SERVER_ID,
                                 const std::string & USER_ID,
                                 const std::string & USER_ID_CHECK,
                                 const int64_t     & ADJUSTMENT)	// can be "0", or "", if you just want to check the current balance without adjusting it.
{
	if (SERVER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"    ); OT_FAIL; }
	if (USER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"      ); OT_FAIL; }
	if (USER_ID_CHECK.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_CHECK"); OT_FAIL; }

//	OT_ASSERT_MSG("" != ADJUSTMENT, "OTAPI_Exec::usageCredits: Null ADJUSTMENT passed in."); // "" is allowed here.

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);

	const int64_t lAdjustment = ADJUSTMENT; // "" resolves as 0.

	return OTAPI()->usageCredits(theServerID, theUserID, theOtherUserID, static_cast<int64_t>(lAdjustment));
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::checkUser(const std::string & SERVER_ID,
                              const std::string & USER_ID,
                              const std::string & USER_ID_CHECK)
{
	if (SERVER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"    ); OT_FAIL; }
	if (USER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"      ); OT_FAIL; }
	if (USER_ID_CHECK.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_CHECK"); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);

	return OTAPI()->checkUser(theServerID, theUserID, theOtherUserID);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::sendUserMessage(const std::string & SERVER_ID,
                                    const std::string & USER_ID,
                                    const std::string & USER_ID_RECIPIENT,
                                    const std::string & RECIPIENT_PUBKEY,
                                    const std::string & THE_MESSAGE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (USER_ID_RECIPIENT.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_RECIPIENT"	); OT_FAIL; }
	if (RECIPIENT_PUBKEY.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_PUBKEY"	); OT_FAIL; }
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_RECIPIENT);
	OTString        strRecipPubkey(RECIPIENT_PUBKEY);
	OTString		strMessage(THE_MESSAGE);

	return OTAPI()->sendUserMessage(theServerID, theUserID, theOtherUserID, strRecipPubkey, strMessage);
}



// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::sendUserInstrument(const std::string & SERVER_ID,
                                       const std::string & USER_ID,
                                       const std::string & USER_ID_RECIPIENT,
                                       const std::string & RECIPIENT_PUBKEY,
                                       const std::string & THE_INSTRUMENT,
                                       const std::string & INSTRUMENT_FOR_SENDER) // Can be empty. Special version for the sender's outpayments box. Only used for cash: THE_INSTRUMENT contains tokens already encrypted to the recipient's key. So this version contains tokens encrypted to the sender's key instead.
{
	if (SERVER_ID.empty())			   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"            ); OT_FAIL; }
	if (USER_ID.empty())			   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"              ); OT_FAIL; }
	if (USER_ID_RECIPIENT.empty())	   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_RECIPIENT"    ); OT_FAIL; }
	if (RECIPIENT_PUBKEY.empty())	   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_PUBKEY"     ); OT_FAIL; }
	if (THE_INSTRUMENT.empty())		   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"       ); OT_FAIL; }
//	if (INSTRUMENT_FOR_SENDER.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "INSTRUMENT_FOR_SENDER"); OT_FAIL; }
    // (INSTRUMENT_FOR_SENDER is optional, so we allow it to be empty.)

	OTIdentifier    theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_RECIPIENT);
    // -----------------------------------------------------
	OTString    strRecipPubkey(RECIPIENT_PUBKEY),
                strInstrument(THE_INSTRUMENT);
    // -----------------------------------------------------
    // Note: this was removed and can be deleted from the code.
    //
    // Why? Because we pass the string version of the public key,
    // not the OTASCIIArmor version. The bookends are passed intact
    // into the OpenSSL call since the key is expected that way.
    // Whereas loading it into ascii-armor is just going to strip off
    // the bookends and pass the raw base64-encoded pubkey to OpenSSL
    // which is NOT what OpenSSL is expecting. FYI.
    //
    // Todo, security: Should we do this anyway, just purely for validation purposes?
    //
//  OTASCIIArmor ascRecipPubkey;
//  const bool bLoadedArmor = OTASCIIArmor::LoadFromString(ascRecipPubkey, strRecipPubkey); // str_bookend="-----BEGIN" by default
//	// -----------------------------------------------------
//  if (!bLoadedArmor || !ascRecipPubkey.Exists())
//  {
//      OTLog::vError("%s: Failure loading string into OTASCIIArmor object:\n\n%s\n\n",
//                    __FUNCTION__, strRecipPubkey.Get());
//      return OT_ERROR;
//  }
	// -----------------------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid() || !thePayment.SetTempValues())
	{
		OTLog::vOutput(0, "%s: Failure loading payment instrument (intended for recipient) from string:\n\n%s\n\n",
                       __FUNCTION__, strInstrument.Get());
		return OT_ERROR;
	}
	// -----------------------------------------------------
    const bool bSenderCopyIncluded = (INSTRUMENT_FOR_SENDER.size() > 0);

    if (bSenderCopyIncluded)
    {
        OTString  strInstrumentForSender(INSTRUMENT_FOR_SENDER);
        // -----------------------------------------------------
        OTPayment theSenderPayment(strInstrumentForSender);

        if (!theSenderPayment.IsValid() || !theSenderPayment.SetTempValues())
        {
            OTLog::vOutput(0, "%s: Failure loading payment instrument (copy intended for sender's records) from string:\n\n%s\n\n",
                           __FUNCTION__, strInstrumentForSender.Get());
            return OT_ERROR;
        }
        return OTAPI()->sendUserInstrument(theServerID, theUserID, theOtherUserID, strRecipPubkey, thePayment, &theSenderPayment);
    }
	// -----------------------------------------------------
	return OTAPI()->sendUserInstrument(theServerID, theUserID, theOtherUserID, strRecipPubkey, thePayment);
}



// Returns int32_t:
// -1 means error; no message was sent.
//  0 means NO error, but also: no message was sent.
//  1 means the "getRequest" message was successfully SENT.
//
int32_t OTAPI_Exec::getRequest(const std::string & SERVER_ID,
                               const std::string & USER_ID)
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI()->getRequest(theServerID, theUserID);
}



// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::issueAssetType(const std::string & SERVER_ID,
                                   const std::string & USER_ID,
                                   const std::string & THE_CONTRACT)
{
	if (SERVER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"    ); OT_FAIL; }
	if (USER_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"      ); OT_FAIL; }
	if (THE_CONTRACT.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT" ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	OTString strContract(THE_CONTRACT);

	return OTAPI()->issueAssetType(theServerID, theUserID, strContract);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getContract(const std::string & SERVER_ID,
                                const std::string & USER_ID,
                                const std::string & ASSET_ID)
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }
	if (ASSET_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"  ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OTAPI()->getContract(theServerID, theUserID, theAssetID);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getMint(const std::string & SERVER_ID,
                            const std::string & USER_ID,
                            const std::string & ASSET_ID)
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }
	if (ASSET_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"  ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OTAPI()->getMint(theServerID, theUserID, theAssetID);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::createAssetAccount(const std::string & SERVER_ID,
                                       const std::string & USER_ID,
                                       const std::string & ASSET_ID)
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }
	if (ASSET_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"  ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OTAPI()->createAssetAccount(theServerID, theUserID, theAssetID);
}



// Sends a message to the server to retrieve latest copy of an asset acct.
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
// NOTE: Deprecated. Replaced by getAccountFiles
int32_t OTAPI_Exec::getAccount(const std::string & SERVER_ID,
                               const std::string & USER_ID,
                               const std::string & ACCT_ID)
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }
	if (ACCT_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"   ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI()->getAccount(theServerID, theUserID, theAcctID);
}



// Sends a message to the server to retrieve latest copy of an asset acct.
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getAccountFiles(const std::string & SERVER_ID,
                                    const std::string & USER_ID,
                                    const std::string & ACCT_ID)
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID" ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"   ); OT_FAIL; }
	if (ACCT_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"   ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI()->getAccountFiles(theServerID, theUserID, theAcctID);
}




// ----------------------------------------------------
// GENERATE BASKET CREATION REQUEST
//
// (returns the basket in string form.)
//
// Call OTAPI_Exec::AddBasketCreationItem multiple times to add
// the various currencies to the basket, and then call
// OTAPI_Exec::issueBasket to send the request to the server.
//
std::string OTAPI_Exec::GenerateBasketCreation(const std::string & USER_ID,
										  const int64_t & MINIMUM_TRANSFER)
{
	if (USER_ID.empty())      { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (0 > MINIMUM_TRANSFER) { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MINIMUM_TRANSFER"	); OT_FAIL; }

	const OTIdentifier theUserID(USER_ID);

	// ----------------------------------------------
	int64_t lMinimumTransfer = MINIMUM_TRANSFER == 0 ? 10 : MINIMUM_TRANSFER;
	// ----------------------------------------------

	OTBasket * pBasket = OTAPI()->GenerateBasketCreation(theUserID, static_cast<int64_t>(lMinimumTransfer)); // Must be above zero. If <= 0, defaults to 10.

	OTCleanup<OTBasket> theAngel(pBasket);

	if (NULL == pBasket)
		return "";

	// At this point, I know pBasket is good (and will be cleaned up automatically.)
	// ----------------------------------------------


	OTString strOutput(*pBasket);
	//	pBasket->SaveContract(strOutput); // Extract the basket to string form.

	std::string pBuf = strOutput.Get();



	return pBuf;
}




// ----------------------------------------------------
// ADD BASKET CREATION ITEM
//
// (returns the updated basket in string form.)
//
// Call OTAPI_Exec::GenerateBasketCreation first (above), then
// call this function multiple times to add the various
// currencies to the basket, and then call OTAPI_Exec::issueBasket
// to send the request to the server.
//
std::string OTAPI_Exec::AddBasketCreationItem(const std::string & USER_ID, // for signature.
                                              const std::string & THE_BASKET, // created in above call.
                                              const std::string & ASSET_TYPE_ID, // Adding an asset type to the new basket.
                                              const int64_t & MINIMUM_TRANSFER)
{

	if (USER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "USER_ID"          ); OT_FAIL; }
	if (THE_BASKET.empty())    { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "THE_BASKET"       ); OT_FAIL; }
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "ASSET_TYPE_ID"    ); OT_FAIL; }
	if (0 > MINIMUM_TRANSFER)  { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MINIMUM_TRANSFER" ); OT_FAIL; }

	OTString strBasket(THE_BASKET);
	// ----------------------------------------------------
	const OTIdentifier theUserID(USER_ID), theAssetTypeID(ASSET_TYPE_ID);
	// ----------------------------------------------
	int64_t lMinimumTransfer = MINIMUM_TRANSFER == 0 ? 10 : MINIMUM_TRANSFER;
	// ----------------------------------------------
	OTBasket theBasket;

	bool bAdded = false;

	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (theBasket.LoadContractFromString(strBasket))
	{
		bAdded = OTAPI()->AddBasketCreationItem(theUserID, // for signature.
			theBasket, // created in above call.
			theAssetTypeID, // Adding an asset type to the new basket.
			static_cast<int64_t>(lMinimumTransfer)); // The amount of the asset type that is in the basket (per).
	}

	if (false == bAdded)
		return "";
	// ----------------------------------------
	OTString strOutput(theBasket); // Extract the updated basket to string form.

	std::string pBuf = strOutput.Get();

	return pBuf;
}



// --------------------------------------------------------------------------
// ISSUE BASKET CURRENCY
//
// Issue a new asset type based on a BASKET of other asset types!
// You cannot call this function until you first set up the BASKET_INFO object.
// I will provide functions for setting up that object, so that you can then
// call this function to actually message the server with your request.
//
// ANYONE can issue a new basket type, but they will have no control over the
// issuer account. Normally when issuing a currency, you therefore control the
// issuer account. But with baskets, that is managed internally by the server.
// This means anyone can define a basket, and all may use it -- but no one
// controls it except the server.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::issueBasket(const std::string & SERVER_ID,
                                const std::string & USER_ID,
                                const std::string & THE_BASKET)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (THE_BASKET.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET" ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	OTString strBasketInfo(THE_BASKET);

	return OTAPI()->issueBasket(theServerID, theUserID, strBasketInfo);
}







// ----------------------------------------------------
// GENERATE BASKET EXCHANGE REQUEST
//
// (Returns the new basket exchange request in string form.)
//
// Call this function first. Then call OTAPI_Exec::AddBasketExchangeItem
// multiple times, and then finally call OTAPI_Exec::exchangeBasket to
// send the request to the server.
//
std::string OTAPI_Exec::GenerateBasketExchange(const std::string & SERVER_ID,
										  const std::string & USER_ID,
										  const std::string & BASKET_ASSET_TYPE_ID,
										  const std::string & BASKET_ASSET_ACCT_ID,
										   // -------------------------------------
										   const int32_t & TRANSFER_MULTIPLE)	// 1			2			 3
										   // 5=2,3,4  OR  10=4,6,8  OR 15=6,9,12
{
	if (SERVER_ID.empty())			  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"           ); OT_FAIL; }
	if (USER_ID.empty())              { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"             ); OT_FAIL; }
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID"); OT_FAIL; }
	if (BASKET_ASSET_ACCT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_ACCT_ID"); OT_FAIL; }

	const OTIdentifier	theUserID(USER_ID), theServerID(SERVER_ID),
                        theBasketAssetTypeID(BASKET_ASSET_TYPE_ID),
                        theBasketAssetAcctID(BASKET_ASSET_ACCT_ID);
	// ----------------------------------------------
	int32_t nTransferMultiple = 1; // Just a default value.

	if (TRANSFER_MULTIPLE > 0)
		nTransferMultiple = TRANSFER_MULTIPLE;
	// ----------------------------------------------
	OTBasket * pBasket = OTAPI()->GenerateBasketExchange(theServerID,
		theUserID,
		theBasketAssetTypeID,
		theBasketAssetAcctID,
		nTransferMultiple);	// 1			2			 3
	// 5=2,3,4  OR  10=4,6,8  OR 15=6,9,12
	OTCleanup<OTBasket> theAngel(pBasket);

	if (NULL == pBasket)
		return "";

	// At this point, I know pBasket is good (and will be cleaned up automatically.)
	// ----------------------------------------------
	OTString strOutput(*pBasket); // Extract the basket to string form.

	std::string pBuf = strOutput.Get();

	return pBuf;
}

// ----------------------------------------------------
// ADD BASKET EXCHANGE ITEM
//
// Returns the updated basket exchange request in string form.
// (Or "".)
//
// Call the above function first. Then call this one multiple
// times, and then finally call OTAPI_Exec::exchangeBasket to send
// the request to the server.
//
std::string OTAPI_Exec::AddBasketExchangeItem(const std::string & SERVER_ID,
                                              const std::string & USER_ID,
                                              const std::string & THE_BASKET,
                                              const std::string & ASSET_TYPE_ID,
                                              const std::string & ASSET_ACCT_ID)
{
	if (SERVER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"     ); OT_FAIL; }
	if (USER_ID.empty())       { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"       ); OT_FAIL; }
	if (THE_BASKET.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"    ); OT_FAIL; }
	if (ASSET_TYPE_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID" ); OT_FAIL; }
	if (ASSET_ACCT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID" ); OT_FAIL; }

	OTString strBasket(THE_BASKET);
	// ----------------------------------------------------
	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID),
                        theAssetTypeID(ASSET_TYPE_ID),
                        theAssetAcctID(ASSET_ACCT_ID);
	// ----------------------------------------------
	OTBasket theBasket;

	bool bAdded = false;

	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (theBasket.LoadContractFromString(strBasket))
	{
		bAdded = OTAPI()->AddBasketExchangeItem(theServerID,
			theUserID,
			theBasket,
			theAssetTypeID,
			theAssetAcctID);
	}

	if (false == bAdded)
		return "";

	OTString strOutput(theBasket); // Extract the updated basket to string form.

	std::string pBuf = strOutput.Get();

	return pBuf;
}


// --------------------------------------------------------------------------
// EXCHANGE BASKET
//
// Send a request to the server asking to exchange in or out of a basket
// currency.
//
// For example, maybe you have 3 gold, 2 silver, and 5 dollars, and those are
// the ingredients of the "Rand" basket currency. This message allows you to
// ask the server to convert from your gold, silver, and dollar accounts into
// your Rand account. (Or convert from your Rand account back into your gold,
// silver, and dollar accounts.)
//
// Other than this conversion process, (with the reserves stored internally by
// the server) basket accounts are identical to normal asset accounts -- they
// are merely another asset type ID, and you can use them the same as you would
// use any other asset type (open accounts, write cheques, withdraw cash, trade
// on markets, etc.)
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//

int32_t OTAPI_Exec::exchangeBasket(const std::string & SERVER_ID,
                                   const std::string & USER_ID,
                                   const std::string & BASKET_ASSET_ID,
                                   const std::string & THE_BASKET,
                                   const bool & BOOL_EXCHANGE_IN_OR_OUT) // exchanging in == true (1), out == false (0).
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (BASKET_ASSET_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_ID"	); OT_FAIL; }
	if (THE_BASKET.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_FAIL; }

	if ( (true != BOOL_EXCHANGE_IN_OR_OUT ) && (false != BOOL_EXCHANGE_IN_OR_OUT ) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "BOOL_EXCHANGE_IN_OR_OUT" ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theBasketAssetID(BASKET_ASSET_ID);

	OTString strBasketInfo(THE_BASKET);

	// exchanging in == true, out == false.
	const bool & bExchangeInOrOut = ((true == BOOL_EXCHANGE_IN_OR_OUT) ? true : false);

	return OTAPI()->exchangeBasket(theServerID, theUserID, theBasketAssetID, strBasketInfo, bExchangeInOrOut);
}

// ----------------------------------------------------










// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getTransactionNumber(const std::string & SERVER_ID,
								const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);


	return OTAPI()->getTransactionNumber(theServerID, theUserID);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::notarizeWithdrawal(const std::string & SERVER_ID,
							 const std::string & USER_ID,
							 const std::string & ACCT_ID,
							 const int64_t & AMOUNT)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_FAIL; }
	if (0 > AMOUNT)					{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "AMOUNT"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI()->notarizeWithdrawal(theServerID, theUserID, theAcctID, static_cast<int64_t>(AMOUNT));
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::notarizeDeposit(const std::string & SERVER_ID,
						  const std::string & USER_ID,
						  const std::string & ACCT_ID,
						  const std::string & THE_PURSE)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_FAIL; }
	if (THE_PURSE.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strPurse(THE_PURSE);

	return OTAPI()->notarizeDeposit(theServerID, theUserID, theAcctID, strPurse);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::notarizeTransfer(const std::string & SERVER_ID,
							const std::string & USER_ID,
							const std::string & ACCT_FROM,
							const std::string & ACCT_TO,
							const int64_t & AMOUNT,
							const std::string & NOTE)
{
	if (SERVER_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCT_FROM.empty()) { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "ACCT_FROM"  ); OT_FAIL; }
	if (ACCT_TO.empty())   { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "ACCT_TO"    ); OT_FAIL; }
	if (0 > AMOUNT)        { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "AMOUNT"     ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	OTIdentifier theFromAcct(ACCT_FROM), theToAcct(ACCT_TO);

	OTString strNote(NOTE.empty() ? "" : NOTE);

	int64_t lAmount = AMOUNT;

	return OTAPI()->notarizeTransfer(theServerID, theUserID, theFromAcct, theToAcct, static_cast<int64_t>(lAmount), strNote);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getInbox(const std::string & SERVER_ID,
					const std::string & USER_ID,
					const std::string & ACCT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI()->getInbox(theServerID, theUserID, theAcctID);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getNymbox(const std::string & SERVER_ID,
					const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI()->getNymbox(theServerID, theUserID);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getOutbox(const std::string & SERVER_ID,
					const std::string & USER_ID,
					const std::string & ACCT_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI()->getOutbox(theServerID, theUserID, theAcctID);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::processInbox(const std::string & SERVER_ID,
						const std::string & USER_ID,
						const std::string & ACCT_ID,
						const std::string & ACCT_LEDGER)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_FAIL; }
	if (ACCT_LEDGER.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_LEDGER"		); OT_FAIL; }

//	OTLog::vOutput(0, "%s: \n"
//		"SERVER_ID: %s \n"
//		"USER_ID: %s \n"
//		"ACCT_ID: %s \n"
//		"ACCT_LEDGER:\n%s\n\n",
//		__FUNCTION__, SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), ACCT_LEDGER.c_str());

	OTIdentifier    theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString        strLedger(ACCT_LEDGER);

//	OTString temp1(SERVER_ID), temp2(USER_ID), temp3(ACCT_ID), temp4(ACCT_LEDGER);
//	OTLog::vOutput(0,  "%s: \n"
//		"\n\nSERVER_ID: %s \n"
//		"USER_ID: %s \n"
//		"ACCT_ID: %s \n"
//		"ACCT_LEDGER:\n%s\n\n",
//		__FUNCTION__, temp1.Get(), temp2.Get(), temp3.Get(), temp4.Get());

	return OTAPI()->processInbox(theServerID, theUserID, theAcctID, strLedger);
}


// Returns:
// -1 if error.
//  0 if Nymbox is empty.
//  1 or more: (OLD: Count of items in Nymbox before processing.)
//  UPDATE: This now returns the request number of the message sent, if success.
//
int32_t OTAPI_Exec::processNymbox(const std::string & SERVER_ID,
						const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI()->processNymbox(theServerID, theUserID);
}


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::withdrawVoucher(const std::string & SERVER_ID,
                                    const std::string & USER_ID,
                                    const std::string & ACCT_ID,
                                    const std::string & RECIPIENT_USER_ID,
                                    const std::string & CHEQUE_MEMO,
                                    const int64_t     & AMOUNT)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ACCT_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "ACCT_ID"			); OT_FAIL; }
	if (RECIPIENT_USER_ID.empty())	{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "RECIPIENT_USER_ID"	); OT_FAIL; }
//	if (CHEQUE_MEMO.empty())		{ OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "CHEQUE_MEMO"		); OT_FAIL; }
	if (0 > AMOUNT)					{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "AMOUNT"             ); OT_FAIL; }

	OTIdentifier	theServerID(SERVER_ID),	theUserID(USER_ID),
                    theAcctID(ACCT_ID),		theRecipientUserID(RECIPIENT_USER_ID);

	OTString strMemo(CHEQUE_MEMO);
	int64_t  lAmount = AMOUNT;

	return OTAPI()->withdrawVoucher(theServerID, theUserID, theAcctID, theRecipientUserID, strMemo, static_cast<int64_t>(lAmount));
}


// PAY DIVIDEND -- to shareholders
//
int32_t OTAPI_Exec::payDividend(const std::string & SERVER_ID,
					  const std::string & ISSUER_USER_ID,        // must be issuer of SHARES_ASSET_TYPE_ID
					  const std::string & DIVIDEND_FROM_ACCT_ID, // if dollars paid for pepsi shares, then this is the issuer's dollars account.
					  const std::string & SHARES_ASSET_TYPE_ID,  // if dollars paid for pepsi shares, then this is the pepsi shares asset type id.
					  const std::string & DIVIDEND_MEMO,         // user-configurable note that's added to the payout request message.
					  const int64_t     & AMOUNT_PER_SHARE)      // number of dollars to be paid out PER SHARE (multiplied by total number of shares issued.)
{
	if (SERVER_ID.empty())			   { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SERVER_ID"			 ); OT_FAIL; }
	if (ISSUER_USER_ID.empty())		   { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "ISSUER_USER_ID"		 ); OT_FAIL; }
	if (DIVIDEND_FROM_ACCT_ID.empty()) { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "DIVIDEND_FROM_ACCT_ID"); OT_FAIL; }
	if (SHARES_ASSET_TYPE_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "SHARES_ASSET_TYPE_ID" ); OT_FAIL; }
//	if (DIVIDEND_MEMO.empty())		   { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "DIVIDEND_MEMO"		 ); OT_FAIL; }
	if (0 > AMOUNT_PER_SHARE)		   { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "AMOUNT_PER_SHARE"	 ); OT_FAIL; }

	OTIdentifier	theServerID           (SERVER_ID),
                    theIssuerUserID       (ISSUER_USER_ID),
                    theDividendFromAcctID (DIVIDEND_FROM_ACCT_ID),
                    theSharesAssetTypeID  (SHARES_ASSET_TYPE_ID);

	OTString  strMemo  (DIVIDEND_MEMO);
	int64_t   lAmount = AMOUNT_PER_SHARE;

	return OTAPI()->payDividend(theServerID,
		theIssuerUserID,
		theDividendFromAcctID,
		theSharesAssetTypeID,
		strMemo,
		static_cast<int64_t>(lAmount));
}



// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::depositCheque(const std::string & SERVER_ID,
                                  const std::string & USER_ID,
                                  const std::string & ACCT_ID,
                                  const std::string & THE_CHEQUE)
{
	if (SERVER_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"  ); OT_FAIL; }
	if (USER_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"    ); OT_FAIL; }
	if (ACCT_ID.empty())    { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"    ); OT_FAIL; }
	if (THE_CHEQUE.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CHEQUE" ); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID),
                 theUserID(USER_ID),
                 theAcctID(ACCT_ID);

	OTString strCheque(THE_CHEQUE);

	return OTAPI()->depositCheque(theServerID, theUserID, theAcctID, strCheque);
}




// --------------------------------------------------
// DEPOSIT PAYMENT PLAN
//
// See OTAPI_Exec::WritePaymentPlan as well.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::depositPaymentPlan(const std::string & SERVER_ID,
                                       const std::string & USER_ID,
                                       const std::string & THE_PAYMENT_PLAN)
{
	if (SERVER_ID.empty())        { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"        ); OT_FAIL; }
	if (USER_ID.empty())          { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"          ); OT_FAIL; }
	if (THE_PAYMENT_PLAN.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PAYMENT_PLAN" ); OT_FAIL; }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strPlan(THE_PAYMENT_PLAN);

	return OTAPI()->depositPaymentPlan(theServerID, theUserID, strPlan);
}



// DONE: Remove Market ID.
// DONE: Change inner call from cancelNymMarketOffer to cancelCronItem
// DONE: Make a copy of this function called cancelPaymentPlan.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::killMarketOffer(const std::string & SERVER_ID,
                                    const std::string & USER_ID,
                                    const std::string & ASSET_ACCT_ID,
                                    const int64_t & TRANSACTION_NUMBER)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ASSET_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_FAIL; }
	if (0 > TRANSACTION_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_FAIL; }

	const int64_t lTransactionNumber = TRANSACTION_NUMBER;

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetAcctID(ASSET_ACCT_ID);

	return OTAPI()->cancelCronItem(theServerID, theUserID, theAssetAcctID, static_cast<int64_t>(lTransactionNumber));
}

// OTAPI_Exec::cancelPaymentPlan
// Cancel a payment plan by transaction number.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::killPaymentPlan(const std::string & SERVER_ID,
                                    const std::string & USER_ID,
                                    const std::string & FROM_ACCT_ID,
                                    const int64_t & TRANSACTION_NUMBER)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (FROM_ACCT_ID.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "FROM_ACCT_ID"		); OT_FAIL; }
	if ( 0 > TRANSACTION_NUMBER)	{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_FAIL; }

	const int64_t lTransactionNumber = TRANSACTION_NUMBER;

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theFromAcctID(FROM_ACCT_ID);

	return OTAPI()->cancelCronItem(theServerID, theUserID, theFromAcctID, static_cast<int64_t>(lTransactionNumber));
}


// --------------------------------------------------
// ISSUE MARKET OFFER
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::issueMarketOffer(const std::string & ASSET_ACCT_ID,     // Perhaps this is the wheat market.
                                     const std::string & CURRENCY_ACCT_ID,  // Perhaps I'm buying the wheat with rubles.
                                     // -------------------------------------------
                                     const int64_t     & MARKET_SCALE,			// Defaults to minimum of 1. Market granularity.
                                     const int64_t     & MINIMUM_INCREMENT,		// This will be multiplied by the Scale. Min 1.
                                     const int64_t     & TOTAL_ASSETS_ON_OFFER,	// Total assets available for sale or purchase. Will be multiplied by minimum increment.
                                     const int64_t     & PRICE_LIMIT,			// Per Minimum Increment...
                                     const bool        & bBuyingOrSelling,      // SELLING == true, BUYING == false.
                                     const time64_t      & LIFESPAN_IN_SECONDS,   // Pass 0 for the default behavior: 86400 seconds aka 1 day.
                                     // -------------------------------------------
                                     const std::string & STOP_SIGN,             // Must be "" (for market/limit orders) or "<" or ">"  (for stop orders.)
                                     const int64_t     & ACTIVATION_PRICE)      // Must be provided if STOP_SIGN is also set. Determines the price threshold for stop orders.
{
	if (ASSET_ACCT_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "ASSET_ACCT_ID"   ); OT_FAIL; }
	if (CURRENCY_ACCT_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n",     __FUNCTION__, "CURRENCY_ACCT_ID"); OT_FAIL; }
	// -------------------------------------------
	if (0 > MARKET_SCALE)          { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MARKET_SCALE"         ); OT_FAIL; }
	if (0 > MINIMUM_INCREMENT)     { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MINIMUM_INCREMENT"    ); OT_FAIL; }
	if (0 > TOTAL_ASSETS_ON_OFFER) { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "TOTAL_ASSETS_ON_OFFER"); OT_FAIL; }
	if (0 > PRICE_LIMIT)           { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "PRICE_LIMIT"          ); OT_FAIL; }
	if (0 > ACTIVATION_PRICE)      { OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "ACTIVATION_PRICE"     ); OT_FAIL; }
	// -------------------------------------------
    char cStopSign = 0;

    if (0 == STOP_SIGN.compare("<"))
        cStopSign = '<';
    else if (0 == STOP_SIGN.compare(">"))
        cStopSign = '>';
	// -------------------------------------------
    if (!STOP_SIGN.empty() &&
        (
        (ACTIVATION_PRICE == 0) ||
        ((cStopSign != '<') && (cStopSign != '>'))
        )) { OTLog::vError("%s: If STOP_SIGN is provided, it must be \"<\" or \">\", and in that case ACTIVATION_PRICE must be non-zero.\n", __FUNCTION__); OT_FAIL; }
	// -------------------------------------------
	const OTIdentifier	theAssetAcctID(ASSET_ACCT_ID),  theCurrencyAcctID(CURRENCY_ACCT_ID);
	// -------------------------------------------
    const std::string str_asset_server_id    = OTAPI_Exec::GetAccountWallet_ServerID(ASSET_ACCT_ID);
    const std::string str_currency_server_id = OTAPI_Exec::GetAccountWallet_ServerID(CURRENCY_ACCT_ID);
	// -------------------------------------------
    const std::string str_asset_nym_id       = OTAPI_Exec::GetAccountWallet_NymID(ASSET_ACCT_ID);
    const std::string str_currency_nym_id    = OTAPI_Exec::GetAccountWallet_NymID(CURRENCY_ACCT_ID);
	// -------------------------------------------
    if (str_asset_server_id.empty() || str_currency_server_id.empty() || str_asset_nym_id.empty() || str_currency_nym_id.empty())
    { OTLog::vError("%s: Failed determining server or nym ID for either asset or currency account.\n", __FUNCTION__); OT_FAIL; }
	// -------------------------------------------
    const OTIdentifier	theAssetServerID    (str_asset_server_id),
                        theAssetUserID      (str_asset_nym_id),
                        theCurrencyServerID (str_currency_server_id),
                        theCurrencyUserID   (str_currency_nym_id);
	// -------------------------------------------
    if (theAssetServerID != theCurrencyServerID) { OTLog::vError("%s: The accounts provided are on two different servers.\n",    __FUNCTION__); OT_FAIL; }
    if (theAssetUserID   != theCurrencyUserID)   { OTLog::vError("%s: The accounts provided are owned by two different nyms.\n", __FUNCTION__); OT_FAIL; }
	// -------------------------------------------
    // 1 is the minimum value here.
    //
	int64_t lMarketScale		= (0 == MARKET_SCALE)           ? 1 : MARKET_SCALE;
	int64_t lMinIncrement		= (0 == MINIMUM_INCREMENT)      ? 1 : MINIMUM_INCREMENT;
	int64_t lTotalAssetsOnOffer	= (0 == TOTAL_ASSETS_ON_OFFER)  ? 1 : TOTAL_ASSETS_ON_OFFER;
	int64_t lPriceLimit			=                                     PRICE_LIMIT; // 0 is allowed now, for market orders.
	// -------------------------------------------
	return OTAPI()->issueMarketOffer(theAssetServerID, theAssetUserID,
                                                 // -------------------------------------------
                                                 theAssetAcctID,
                                                 theCurrencyAcctID,
                                                 // -------------------------------------------
                                                 static_cast<int64_t>(lMarketScale),
                                                 static_cast<int64_t>(lMinIncrement),
                                                 static_cast<int64_t>(lTotalAssetsOnOffer),
                                                 static_cast<int64_t>(lPriceLimit),
                                                 bBuyingOrSelling,
                                                 LIFESPAN_IN_SECONDS,
                                                 cStopSign,
                                                 static_cast<int64_t>(ACTIVATION_PRICE));
}



// -----------------------------------------------------------


// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getMarketList(const std::string & SERVER_ID,
                                  const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI()->getMarketList(theServerID, theUserID);
}


// -----------------------------------------------------------

// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getMarketOffers(const std::string & SERVER_ID,
						  const std::string & USER_ID,
						  const std::string & MARKET_ID,
						  const int64_t & MAX_DEPTH)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (0 > MAX_DEPTH)				{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MAX_DEPTH"		); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);

	const int64_t lDepth = MAX_DEPTH;
	if (0 > lDepth) { OTLog::vError("%s: lDepth is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_FAIL; }

	return OTAPI()->getMarketOffers(theServerID, theUserID, theMarketID, static_cast<int64_t>(lDepth));
}

// -----------------------------------------------------------

// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getMarketRecentTrades(const std::string & SERVER_ID,
								const std::string & USER_ID,
								const std::string & MARKET_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (MARKET_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "MARKET_ID"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);

	return OTAPI()->getMarketRecentTrades(theServerID, theUserID, theMarketID);
}

// -----------------------------------------------------------

// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::getNym_MarketOffers(const std::string & SERVER_ID,
							  const std::string & USER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI()->getNym_MarketOffers(theServerID, theUserID);
}






// -----------------------------------------------------------
// POP MESSAGE BUFFER
//
// If there are any replies from the server, they are stored in
// the message buffer. This function will return those messages
// (and remove them from the list) one-by-one, newest first.
//
// Returns the message as a string.
//
// Update: added arguments for: ServerID AND NymID AND request number
// NOTE: Any messages, when popping, which have the CORRECT serverID
// and the CORRECT NymID, but the wrong Request number, will be discarded.
//
// (Why? Because the client using the OT API will have already treated
// that message as "dropped" by now, if it's already on to the next one,
// and the protocol is designed to move forward properly based specifically
// on this function returning the one EXPECTED... outgoing messages flush
// the incoming buffer anyway, so the client will have assumed the wrong
// reply was flushed by now anyway.)
//
// However, if the Server ID and the User ID are wrong, this just means that
// some other code is still expecting that reply, and hasn't even popped yet!
// Therefore, we do NOT want to discard THOSE replies, but put them back if
// necessary -- only discarding the ones where the IDs match.
//
//
std::string OTAPI_Exec::PopMessageBuffer(const int64_t & REQUEST_NUMBER,
									const std::string & SERVER_ID,
									const std::string & USER_ID)
{
	if (0 > REQUEST_NUMBER)			{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"	); OT_FAIL; }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }

	// ------------------------------------------------
	const int64_t          lRequestNum = REQUEST_NUMBER;
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	// ------------------------------------------------
	OTMessage * pMsg = OTAPI()->PopMessageBuffer(static_cast<int64_t>(lRequestNum), theServerID, theUserID); // caller responsible to delete.
	OTCleanup<OTMessage> theAngel(pMsg);  // Just making sure it gets cleaned up.

	if (NULL == pMsg) // The buffer was empty.
	{
		OTLog::vError("%s:  Reply not found, sorry.\n", __FUNCTION__);
		return "";
	}

	const OTString strOutput(*pMsg);

	std::string pBuf = strOutput.Get();
	return pBuf;
}


// -----------------------------------------------------------

// Just flat-out empties the thing.
//
void OTAPI_Exec::FlushMessageBuffer(void)
{
	OTAPI()->FlushMessageBuffer();
}


// -----------------------------------------------------------


// Message OUT-BUFFER
//
// (for messages I--the client--have sent the server.)
/*
class OTMessageOutbuffer:
void        Clear();
void        AddSentMessage      (OTMessage & theMessage);   // Allocate theMsg on the heap (takes ownership.) Mapped by request num.
OTMessage * GetSentMessage      (const int64_t & lRequestNum); // null == not found. caller NOT responsible to delete.
bool        RemoveSentMessage   (const int64_t & lRequestNum); // true == it was removed. false == it wasn't found.
*/



// -----------------------------------------------------------
// GET SENT MESSAGE
//
// If there were any messages sent to the server, copies are
// stored here, so the developer using the OT API can access
// them by request number.
//
// Returns the message as a string.
//
std::string OTAPI_Exec::GetSentMessage(const int64_t & REQUEST_NUMBER,
								  const std::string & SERVER_ID,
								  const std::string & USER_ID)
{
	if (0 > REQUEST_NUMBER)			{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"	); OT_FAIL; }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",    __FUNCTION__, "SERVER_ID"		); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n",    __FUNCTION__, "USER_ID"			); OT_FAIL; }
	// ------------------------------------------------
	const int64_t          lRequestNum = REQUEST_NUMBER;
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	// ------------------------------------------------
	OTMessage * pMsg = OTAPI()->GetSentMessage(static_cast<int64_t>(lRequestNum), theServerID, theUserID);
	//	OTCleanup<OTMessage> theAngel(pMsg);    // caller NOT responsible to delete.

	if (NULL == pMsg) // The message wasn't found with that request number.
	{
		OTLog::vOutput(1, "%s: Message not found with request number %lld, sorry.\n", __FUNCTION__, lRequestNum);
		return "";
	}
	// ------------------------------------------------
	const OTString strOutput(*pMsg); // No need to cleanup the message since it's still in the buffer until explicitly removed.

	std::string pBuf = strOutput.Get();

	return pBuf;
}


// -----------------------------------------------------------
// REMOVE SENT MESSAGE
//
// If there were any messages sent to the server, copies are
// stored until removed via this function.
//
// Returns bool based on whether message was found (and removed.)
//
bool OTAPI_Exec::RemoveSentMessage(const int64_t & REQUEST_NUMBER,
								const std::string & SERVER_ID,
								const std::string & USER_ID)
{
	if (0 > REQUEST_NUMBER)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"	); OT_FAIL; }
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	// ------------------------------------------------
	const int64_t          lRequestNum = REQUEST_NUMBER;
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	// ------------------------------------------------
	const bool & bSuccess = OTAPI()->RemoveSentMessage(static_cast<int64_t>(lRequestNum), theServerID, theUserID);

	return bSuccess;
}


// -----------------------------------------------------------
// OTAPI_Exec::FlushSentMessages
//
// Make sure to call this directly after a successful @getNymbox.
// (And ONLY at that time.)
//
// This empties the buffer of sent messages.
// (Harvesting any transaction numbers that are still there.)
//
// NOTE: You normally ONLY call this immediately after receiving
// a successful @getNymbox. It's only then that you can see which
// messages a server actually received or not -- which transactions
// it processed (success or fail) vs which transactions did NOT
// process (and thus did NOT leave any success/fail receipt in the
// nymbox.)
//
// I COULD have just flushed myself IN the @getNymbox code (where
// the reply is processed.) But then the developer using the OT API
// would never have the opportunity to see whether a message was
// replied to, and harvest it for himself (say, just before attempting
// a re-try, which I plan to do in the high-level Java API, which is
// why I'm coding it this way.)
//
// This way, he can do that if he wishes, THEN call this function,
// and harvesting will still occur properly, and he will also thus have
// his chance to check for his own replies to harvest before then.
// This all depends on the developer using the API being smart enough
// to call this function after a successful @getNymbox!
//
void OTAPI_Exec::FlushSentMessages(const bool & bHarvestingForRetry,
							 const std::string & SERVER_ID,
							 const std::string & USER_ID,
							 const std::string & THE_NYMBOX)
{
	if ( (true != bHarvestingForRetry) && (false != bHarvestingForRetry) ) { OTLog::vError("%s: Bad: %s \n", __FUNCTION__, "bHarvestingForRetry"); OT_FAIL; return; }

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; return; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; return; }
	if (THE_NYMBOX.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_NYMBOX"			); OT_FAIL; return; }

	// ------------------------------------------------
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	const OTString      strLedger(THE_NYMBOX);
	OTLedger      theLedger(theUserID, theUserID, theServerID);
	// ------------------------------------------------
	if (strLedger.Exists() && theLedger.LoadContractFromString(strLedger))
		OTAPI()->FlushSentMessages(bHarvestingForRetry,
                                               theServerID,
                                               theUserID,
                                               theLedger);
	else
		OTLog::vError("%s: Failure: Unable to load Nymbox from string:\n\n%s\n\n", __FUNCTION__, strLedger.Get());
}



// -----------------------------------------------------------






// Sometimes you just need a quick nap between messages.
//
void OTAPI_Exec::Sleep(const int64_t & MILLISECONDS)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_FAIL; return; }

	if (0 > MILLISECONDS)		{ OTLog::vError("%s: Negative: %s passed in!\n", __FUNCTION__, "MILLISECONDS"		); OT_FAIL; return; }
	// -----------------------------------------------

	const int64_t lMilliseconds = MILLISECONDS;

	OTLog::SleepMilliseconds(static_cast<int64_t>(lMilliseconds));
}



// -----------------------------------------------------------



// Make sure you download your Nymbox (getNymbox) before calling this,
// so when it loads the Nymbox it will have the latest version of it.
//
// Also, call createUserAccount() and pass the server reply message in
// here, so that it can read theMessageNym (to sync the transaction
// numbers.)
//
bool OTAPI_Exec::ResyncNymWithServer(const std::string & SERVER_ID, const std::string & USER_ID, const std::string & THE_MESSAGE)
{
	// -----------------------------------------------------
	bool bIsInitialized = OTAPI()->IsInitialized();
	if (!bIsInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__); OT_FAIL; }

	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }
	// -----------------------------------------------


	OTIdentifier	theServerID(SERVER_ID), theNymID(USER_ID);
	const OTString	strMessage(THE_MESSAGE), strNymID(theNymID);

	// -----------------------------------------------------
	OTPseudonym * pNym = OTAPI()->GetOrLoadPrivateNym(theNymID, false);
	if (NULL == pNym) return false;
	// -----------------------------------------------------------------
	OTMessage theMessage;

	if (false == theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vError("%s: Failed trying to load @createUserAccount() message from string (it's a server reply.) Contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	if (false == strNymID.Compare(theMessage.m_strNymID))
	{
		OTLog::vError("%s: Failed. Though success loading message from string, it had the wrong NymID. "
			"(Expected %s, but found %s.) Message contents:\n\n%s\n\n", __FUNCTION__,
			strNymID.Get(), theMessage.m_strNymID.Get(), strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	if (false == theMessage.m_strCommand.Compare("@createUserAccount"))
	{
		OTLog::vError("%s: Failed. Though success loading message from string, it had the wrong command type. "
			"(Expected @createUserAccount, but found %s.) Message contents:\n\n%s\n\n", __FUNCTION__,
			theMessage.m_strCommand.Get(), strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	if (false == theMessage.m_ascPayload.Exists())
	{
		OTLog::vError("%s: Failed. Though success loading @createUserAccount() message, the payload was empty. "
			"(Expected theMessageNym to be there, so I could re-sync client side to server.) Message contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	OTString strMessageNym;

	if (false == theMessage.m_ascPayload.GetString(strMessageNym))
	{
		OTLog::vError("%s: Failed decoding message payload in server reply: @createUserAccount(). "
			"(Expected theMessageNym to be there, so I could re-sync client side to server.) Message contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	OTPseudonym theMessageNym; // <====================

	if (false == theMessageNym.LoadFromString(strMessageNym))
	{
		OTLog::vError("%s: Failed loading theMessageNym from a string. String contents:\n\n%s\n\n", __FUNCTION__, strMessageNym.Get());
		return false;
	}
	// -----------------------------------------------------------------
	// Based on serverID and UserID, load the Nymbox.
	//
	OTLedger theNymbox(theNymID, theNymID, theServerID); // <===========

	bool bSynced		= false;
	bool bLoadedNymbox	= (theNymbox.LoadNymbox() && theNymbox.VerifyAccount(*pNym));

	if (bLoadedNymbox)
		bSynced = OTAPI()->ResyncNymWithServer(*pNym, theNymbox, theMessageNym);
	else
		OTLog::vError("%s: Failed while loading or verifying Nymbox for User %s, on Server %s \n", __FUNCTION__, strNymID.Get(), SERVER_ID.c_str());
	// -----------------------------------------------------------------

	return bSynced;
}




// -----------------------------------------------------------
// QUERY ASSET TYPES (server message)
//
// This way you can ask the server to confirm whether various
// asset types are issued there. You must prepare the encoded
// StringMap in advance of calling this function.
//

// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call OTAPI_Exec::GetLargeRequestNum.
//  0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits into an integer...
//  ...and in fact the requestNum IS the return value!
//  ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Exec::queryAssetTypes(const std::string & SERVER_ID, const std::string & USER_ID, const std::string & ENCODED_MAP)
{
	if (SERVER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_FAIL; }
	if (USER_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_FAIL; }
	if (ENCODED_MAP.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ENCODED_MAP"		); OT_FAIL; }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	OTASCIIArmor theArmor(ENCODED_MAP);

	return OTAPI()->queryAssetTypes(theServerID, theUserID, theArmor);
}




// -----------------------------------------------------------
// GET MESSAGE PAYLOAD
//
// This way you can retrieve the payload from any message.
// Useful, for example, for getting the encoded StringMap object
// from the queryAssetTypes and @queryAssetTypes messages, which both
// use the m_ascPayload field to transport it.
//
std::string OTAPI_Exec::Message_GetPayload(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTString	strMessage(THE_MESSAGE);
	OTMessage	theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return "";

	std::string pBuf = theMessage.m_ascPayload.Get();



	return pBuf;
}




// -----------------------------------------------------------
// GET MESSAGE COMMAND TYPE
//
// This way you can discover what kind of command it was.
// All server replies are pre-pended with the @ sign. For example, if
// you send a "getAccount" message, the server reply is "@getAccount",
// and if you send "getMint" the reply is "@getMint", and so on.
//
std::string OTAPI_Exec::Message_GetCommand(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return "";

	OTString strOutput(theMessage.m_strCommand);

	std::string pBuf = strOutput.Get();

	return pBuf;
}


// -----------------------------------------------------------
// GET MESSAGE LEDGER
//
// If you just received a server response to a transaction, and
// you want to actually iterate through the transactions in the
// response ledger for that transaction, this function will retrieve
// that ledger for you.
//
std::string OTAPI_Exec::Message_GetLedger(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if ((false == theMessage.m_strCommand.Compare("notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strOutput(theMessage.m_ascPayload);

	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return "";
	}

	std::string pBuf = strOutput.Get();



	return pBuf;
}



// -----------------------------------------------------------
// GET NEW ASSET TYPE ID
//
// If you just issued a new asset type, you'll want to read the
// server reply and get the new asset type ID out of it.
// Otherwise how will you ever open accounts in that new type?
//
std::string OTAPI_Exec::Message_GetNewAssetTypeID(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if ((false == theMessage.m_strCommand.Compare("@issueAssetType")) &&
		(false == theMessage.m_strCommand.Compare("@issueBasket")))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strAssetID);

	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No new asset type ID found on message.\n", __FUNCTION__);
		return "";
	}

	std::string pBuf = strOutput.Get();



	return pBuf;
}


// -----------------------------------------------------------
// GET NEW ISSUER ACCOUNT ID
//
// If you just issued a new asset type, you'll want to read the
// server reply and get the new issuer acct ID out of it.
// Otherwise how will you ever issue anything with it?
//
std::string OTAPI_Exec::Message_GetNewIssuerAcctID(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not an issue asset type response, so the m_strAcctID wouldn't
	// contain an issuer account ID. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@issueAssetType"))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n",  __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strAcctID);

	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No issuer account ID found on message.\n", __FUNCTION__);
		return "";
	}

	std::string pBuf = strOutput.Get();



	return pBuf;
}




// -----------------------------------------------------------
// GET NEW ACCOUNT ID
//
// If you just created a new asset account, you'll want to read the
// server reply and get the new acct ID out of it.
// Otherwise how will you ever use it?
// This function allows you to get the new account ID out of the
// server reply message.
//
std::string OTAPI_Exec::Message_GetNewAcctID(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not a response to createAccount, so the m_strAcctID wouldn't
	// contain a new account ID anyway, right? (Don't want to pass back whatever
	// it DOES contain in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@createAccount"))
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strAcctID);

	if (!strOutput.Exists())
	{
		OTLog::vOutput(0, "%s: No asset account ID found on message.\n", __FUNCTION__);
		return "";
	}

	std::string pBuf = strOutput.Get();



	return pBuf;
}




// -----------------------------------------------------------
// GET NYMBOX HASH
//
// Some messages include a copy of the Nymbox Hash. This helps the
// server to quickly ascertain whether some messages will fail, and
// also allows the client to query the server for this information
// for syncronicity purposes.
//
std::string OTAPI_Exec::Message_GetNymboxHash(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// So far these are the only messages that use m_strNymboxHash:
	if (
		(false == theMessage.m_strCommand.Compare("processNymbox")) &&
		(false == theMessage.m_strCommand.Compare("notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("getTransactionNum")) &&
		(false == theMessage.m_strCommand.Compare("processInbox")) &&
		(false == theMessage.m_strCommand.Compare("triggerClause")) &&
		(false == theMessage.m_strCommand.Compare("@getNymbox")) &&
		(false == theMessage.m_strCommand.Compare("@getRequest")) &&
		(false == theMessage.m_strCommand.Compare("@getTransactionNum"))
		)
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s \nFYI, with m_strNymboxHash: %s\n", __FUNCTION__, theMessage.m_strCommand.Get(), theMessage.m_strNymboxHash.Get());
		return "";
	}

	if (!theMessage.m_strNymboxHash.Exists())
	{
		OTLog::vOutput(0, "%s: No NymboxHash found on message: %s\n", __FUNCTION__, strMessage.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strNymboxHash);
	std::string pBuf = strOutput.Get();



	return pBuf;
}




// -----------------------------------------------------------
// GET MESSAGE SUCCESS (True or False)
//
// Returns true (1) for Success and false (0) for Failure.
//
// NEW: returns (-1) for error!
//
OT_BOOL OTAPI_Exec::Message_GetSuccess(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTMessage   theMessage;
	OTString    strMessage(THE_MESSAGE);

	if (!strMessage.Exists())
	{
		OTLog::vError("%s: Error: THE_MESSAGE doesn't exist.\n", __FUNCTION__);
		return OT_ERROR;
	}

	if (!theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vError("%s: Error: Failed loading message from string:\n\n%s\n\n", __FUNCTION__, THE_MESSAGE.c_str());
		return OT_ERROR;
	}
	// ---------------------------------------------
	if (true == theMessage.m_bSuccess)
	{
		OTLog::vOutput(2, "%s: Server reply for RequestNum %lld (Message_GetSuccess was successful, but any transaction inside could have failed OR succeeded. Use Message_GetTransactionSuccess for that.)\n",// Contents: \n\n%s\n\n",
			__FUNCTION__, StringToLong(theMessage.m_strRequestNum.Get()));//, THE_MESSAGE);
		return OT_TRUE;
	}
	else
	{
		OTLog::vOutput(1, "%s: ** FYI, server reply was received, and "
			"it said 'No.' (Status = failed). RequestNum: %lld\n",// Contents: \n\n%s\n\n",
			__FUNCTION__, StringToLong(theMessage.m_strRequestNum.Get()));//, THE_MESSAGE);
	}
	return OT_FALSE;
}



// -----------------------------------------------------------
// GET MESSAGE "DEPTH"   (USED FOR MARKET-SPECIFIC MESSAGES.)
//
// Returns the count of relevant items, so you know whether to bother reading the payload.
// Returns -1 if error.
//
// The "depth" variable stores the count of items being returned.
// For example, if I call getMarketList, and 10 markets are returned,
// then depth will be set to 10. OR, if I call getNym_MarketOffers, and
// the Nym has 16 offers on the various markets, then the depth will be 16.
//
// This value is important when processing server replies to market inquiries.
// If the depth is 0, then you are done. End. BUT! if it contains a number, such as 10,
// then that means you will want to next READ those 10 markets (or offers, or trades, etc)
// out of the server reply's payload.
//
// Whereas if success is TRUE, but depth is 0, that means while the message processed
// successfully, the list was simply empty (and thus it would be a waste of time trying
// to unpack the non-existent, empty list of data items from the payload of your successful
// reply.)
//
int32_t OTAPI_Exec::Message_GetDepth(const std::string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_FAIL; }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return OT_ERROR;

	return static_cast<int32_t>(theMessage.m_lDepth);
}



// -----------------------------------------------------------
// GET MESSAGE TRANSACTION "IS CANCELLED" (True or False)
//
// Returns true (1) for Success and false (0) for Failure.
//         also returns (-1) for Error
//
OT_BOOL OTAPI_Exec::Message_IsTransactionCanceled(
                                                  const std::string & SERVER_ID,
                                                  const std::string & USER_ID,
                                                  const std::string & ACCOUNT_ID,
                                                  const std::string & THE_MESSAGE
                                                  )
{
	if (SERVER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"   ); OT_FAIL; }
	if (USER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"     ); OT_FAIL; }
	if (ACCOUNT_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"  ); OT_FAIL; }
	if (THE_MESSAGE.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n",__FUNCTION__);
		return OT_ERROR;
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@processInbox")) &&
		(false == theMessage.m_strCommand.Compare("@processNymbox"))
		)
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return OT_ERROR;
	}

	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strLedger(theMessage.m_ascPayload);

	if (!strLedger.Exists())
	{
		OTLog::vOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return OT_ERROR;
	}

	// ------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}

	// At this point, I know theLedger loaded successfully.

	if (theLedger.GetTransactionCount() <= 0)
	{
		OTLog::vError("%s: bad count in message ledger: %d\n", __FUNCTION__, theLedger.GetTransactionCount());
		return OT_ERROR; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(0); // Right now this is a defacto standard. (only 1 transaction per message ledger, excepting process inbox.)
//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.

	if (NULL == pTransaction)
	{
		OTLog::vError("%s: good index but uncovered \"\" pointer: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
	}

	// At this point, I actually have the transaction pointer, so let's return its 'canceled' status
	//
	if (pTransaction->IsCancelled())
		return OT_TRUE;

	return OT_FALSE;
}

// -----------------------------------------------------------
// GET MESSAGE TRANSACTION SUCCESS (True or False)
//
// Returns true (1) for Success and false (0) for Failure.
//         also returns (-1) for Error
//
OT_BOOL OTAPI_Exec::Message_GetTransactionSuccess(const std::string & SERVER_ID,
                                                  const std::string & USER_ID,
                                                  const std::string & ACCOUNT_ID,
                                                  const std::string & THE_MESSAGE)
{
	if (SERVER_ID.empty())   { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"   ); OT_FAIL; }
	if (USER_ID.empty())     { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"     ); OT_FAIL; }
	if (ACCOUNT_ID.empty())  { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"  ); OT_FAIL; }
	if (THE_MESSAGE.empty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE" ); OT_FAIL; }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::vOutput(0, "%s: Unable to load message.\n",__FUNCTION__);
		return OT_ERROR;
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@processInbox")) &&
		(false == theMessage.m_strCommand.Compare("@processNymbox"))
		)
	{
		OTLog::vOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return OT_ERROR;
	}

	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strLedger(theMessage.m_ascPayload);

	if (!strLedger.Exists())
	{
		OTLog::vOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return OT_ERROR;
	}

	// ------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::vError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return OT_ERROR;
	}

	// At this point, I know theLedger loaded successfully.

	if (theLedger.GetTransactionCount() <= 0)
	{
		OTLog::vError("%s: bad count in message ledger: %d\n", __FUNCTION__, theLedger.GetTransactionCount());
		return OT_ERROR; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(0); // Right now this is a defacto standard. (only 1 transaction per message ledger, excepting process inbox.)
//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.

	if (NULL == pTransaction)
	{
		OTLog::vError("%s: good index but uncovered \"\" pointer: %d\n", __FUNCTION__, 0);
		return OT_ERROR; // Weird.
	}

	// At this point, I actually have the transaction pointer, so let's return its success status
	//
	if (pTransaction->GetSuccess())
		return OT_TRUE;
	else
	{
		const int64_t lRequestNum     = StringToLong(theMessage.m_strRequestNum.Get());
		const int64_t lTransactionNum = pTransaction->GetTransactionNum();

		OTLog::vOutput(1, "%s: ** FYI, server reply was received, and it said 'No.' (Status = failed). "
                      "RequestNum: %lld, TransNum: %lld\n",// Contents: \n\n%s\n\n",
			__FUNCTION__, lRequestNum, lTransactionNum);//, THE_MESSAGE);
	}

	return OT_FALSE;
}




} // namespace opentxs
