/************************************************************
 *
 *  OTMint.hpp
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

#ifndef __OT_MINT_HPP__
#define __OT_MINT_HPP__

#include "OTContract.hpp"

namespace opentxs {

class OTAccount;
class OTASCIIArmor;
class OTToken;

typedef std::map <int64_t, OTASCIIArmor *> mapOfArmor;


class OTMint : public OTContract
{
private:  // Private prevents erroneous use by other classes.
    typedef OTContract ot_super;
// ------------------------------------------------------------------------------
protected:
	virtual int32_t ProcessXMLNode(irr::io::IrrXMLReader*& xml);

	void InitMint();

	mapOfArmor		  m_mapPrivate;	// An ENVELOPE. You need to pass the Pseudonym to every method that uses this. Private.
									// Then you have to set it into an envelope and then open it using the Nym. Encrypted.
	mapOfArmor		  m_mapPublic;	// An Ascii-armored string of the mint Public information. Base64-encoded only.


	OTIdentifier	  m_ServerID;           // The Server ID, (a hash of the server contract whose public key is m_keyPublic)
	OTIdentifier	  m_ServerNymID;        // The Nym ID of the Server, whose public key is m_keyPublic

	OTAsymmetricKey * m_pKeyPublic;         // The server's public key.

	OTIdentifier	  m_AssetID;            // Each Asset type has its own mint.

	int32_t				  m_nDenominationCount; // How many denominations of the currency are issued by this Mint?
                                            // (Each requires its own key pair.)

	bool			  m_bSavePrivateKeys;   // Determines whether it serializes private keys (no if false).
                                            // Set this to 'true' before signing, if you want the private keys included.
                                            // (The signing process will then automatically set it back to false again.)

	// --- MINT SERIES with EXPIRATION DATES ------------------
	int32_t				  m_nSeries;		// Each series of the mint has a valid from and to date. Series should rotate.
                                        // (That is, the new one should be introduced halfway through the validity period
                                        // of the current one, and so on...)

	time64_t			  m_VALID_FROM;     // All tokens generated by this series will have the same From and To dates.
	time64_t			  m_VALID_TO;		// This way they cannot be tracked by expiration date.

	time64_t			  m_EXPIRATION;     // The Mint itself expires before the tokens do. (As the new series rotates in...)

	OTIdentifier	  m_CashAccountID;  // The Account ID for the cash reserve account. (Pointer below.)

	OTAccount	 	* m_pReserveAcct;	// When you withdraw cash, the Mint removes X dollars from your account, then
                                        // it puts those X dollars into this reserve account, and then issues you the
                                        // blinded tokens. When the tokens are deposited again, the money comes back out
                                        // of the same reserve account and goes into the depositor's account. This way,
                                        // all tokens will have 1-for-1 funds backing them, and any funds left over after
                                        // the tokens expire, is the server operator's money to keep!
// ------------------------------------------------------------------------------
public:
	inline	int32_t		GetSeries()		const { return m_nSeries; }		// The series ID
	inline	time64_t	GetValidFrom()	const { return m_VALID_FROM; }	// The token "valid from" date for this series
	inline	time64_t	GetValidTo()	const { return m_VALID_TO; }	// The token "valid until" date for this series
	inline	time64_t	GetExpiration()	const { return m_EXPIRATION; }	// The date the mint expires (should be halfway
																	// between the above two dates.)
EXPORT	bool Expired() const;	// true or false. Expired?
                                // Valid range is GetValidFrom() through GetExpiration().
    // Server-side only.
	inline OTAccount * GetCashReserveAccount() const { return m_pReserveAcct; }
// ------------------------------------------------------------------------------
public:
    // Caller is responsible to delete.
    //
EXPORT    static OTMint * MintFactory();
EXPORT    static OTMint * MintFactory(const OTString & strServerID, const OTString & strAssetTypeID);
EXPORT    static OTMint * MintFactory(const OTString & strServerID, const OTString & strServerNymID, const OTString & strAssetTypeID);
// ------------------------------------------------------------------------------
protected:
        OTMint();
EXPORT	OTMint(const OTString & strServerID, const OTString & strAssetTypeID);
EXPORT	OTMint(const OTString & strServerID, const OTString & strServerNymID, const OTString & strAssetTypeID);
// ------------------------------------------------------------------------------
public:
EXPORT	virtual ~OTMint();
	virtual void Release();
	void Release_Mint();
	void ReleaseDenominations();
// ------------------------------------------------------------------------------
EXPORT	bool LoadMint(const char * szAppend=NULL);
EXPORT	bool SaveMint(const char * szAppend=NULL);

	virtual bool LoadContract();

	// Will save the private keys on next serialization (not just public keys)
	// (SignContract sets m_bSavePrivateKeys back to false again.)
	inline void SetSavePrivateKeys(bool bDoIt=true) { m_bSavePrivateKeys = bDoIt; }

	// The denomination indicated here is the actual denomination...1, 5, 20, 50, 100, etc
	bool GetPrivate(OTASCIIArmor & theArmor, int64_t lDenomination);
	bool GetPublic (OTASCIIArmor & theArmor, int64_t lDenomination);

        int64_t GetDenomination(int32_t nIndex);
EXPORT	int64_t GetLargestDenomination(int64_t lAmount);
virtual bool AddDenomination(OTPseudonym & theNotary, int64_t lDenomination, int32_t nPrimeLength=1024)=0;

	inline int32_t GetDenominationCount() const { return m_nDenominationCount; }

	virtual bool VerifyContractID();

EXPORT	bool VerifyMint(const OTPseudonym & theOperator);

	virtual void UpdateContents(); // Before transmission or serialization, this is where the token saves its contents

	inline void SetAssetID(const OTIdentifier & newID) { m_AssetID = newID; }

	// Lucre step 1: generate new mint
EXPORT	void GenerateNewMint(int32_t nSeries, time64_t VALID_FROM, time64_t VALID_TO,  time64_t MINT_EXPIRATION,
						 const OTIdentifier & theAssetID, const OTIdentifier & theServerID,
						 OTPseudonym & theNotary,
						 int64_t nDenom1=0, int64_t nDenom2=0, int64_t nDenom3=0, int64_t nDenom4=0, int64_t nDenom5=0,
						 int64_t nDenom6=0, int64_t nDenom7=0, int64_t nDenom8=0, int64_t nDenom9=0, int64_t nDenom10=0);

	// step 2: (coin request is in OTToken)

	// Lucre step 3: mint signs token
EXPORT	virtual bool SignToken(OTPseudonym & theNotary, OTToken & theToken, OTString & theOutput, int32_t nTokenIndex)=0;

	// step 4: (unblind coin is in OTToken)

	// Lucre step 5: mint verifies token when it is redeemed by merchant.
EXPORT	virtual bool VerifyToken(OTPseudonym & theNotary, OTString & theCleartextToken, int64_t lDenomination)=0;

	virtual bool SaveContractWallet(std::ofstream & ofs);
};



} // namespace opentxs

#endif // __OT_MINT_HPP__
