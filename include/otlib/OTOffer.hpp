/************************************************************
 *    
 *  OTOffer.hpp
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

// Each instance of OTOffer represents a Bid or Ask. (A Market has a list of bid offers and a list of ask offers.)

#ifndef __OT_OFFER_HPP__
#define __OT_OFFER_HPP__

#include "OTInstrument.hpp"

namespace opentxs {

class OTTrade;


/*
 OTOffer
 
 Offer MUST STORE:
 
 X 1) Transaction ID (MUST be linked to a trade, so it can expire, and so it can be paid for.)
 X 2) ASSET TYPE ID of whatever I’m trying to BUY or SELL. (Is this the Gold market?)
 X 7) CURRENCY TYPE ID of whatever I’m trying to buy or sell it WITH. (Is it dollars? Euro? Yen?)
 X 8) BUY OR SELL? (BOOL) 
 X 9) Bid/Ask price (limit / per minimum increment.)

 X 4) Total number of assets available for sale or purchase. (4 ounces of gold? 12 ounces of gold?)
 X 5) Number of assets already traded, against the above total.
 X 6) Minimum increment for sale or purchase (if matches “total number of assets for sale”, effectively becomes a FILL OR KILL order. MUST be 1 or greater. CANNOT be zero.)
*/
class OTOffer : public OTInstrument
{
private:  // Private prevents erroneous use by other classes.
    typedef OTInstrument ot_super;

	// From OTInstrument (parent class of this)
	/*
public:
	 inline time64_t GetValidFrom()	const { return m_VALID_FROM; }
	 inline time64_t GetValidTo()		const { return m_VALID_TO; }
	 
	 inline void SetValidFrom(time64_t TIME_FROM)	{ m_VALID_FROM	= TIME_FROM; }
	 inline void SetValidTo(time64_t TIME_TO)		{ m_VALID_TO	= TIME_TO; }
	 
	 
	 inline const OTIdentifier & GetAssetID() const { return m_AssetTypeID; }
	 inline const OTIdentifier & GetServerID() const { return m_ServerID; }
	 
	 inline void SetAssetID(const OTIdentifier & ASSET_ID)  { m_AssetTypeID	= ASSET_ID; }
	 inline void SetServerID(const OTIdentifier & SERVER_ID) { m_ServerID	= SERVER_ID; }
	 
	 bool VerifyCurrentDate(); // Verify the current date against the VALID FROM / TO dates.
	 */
    time64_t          m_tDateAddedToMarket;
// ---------------------------------------------------------
protected:
	OTTrade		*	m_pTrade;		// If this offer is actually connected to a trade, it will have a pointer.
	
	OTIdentifier	m_CURRENCY_TYPE_ID;	// GOLD (Asset) is trading for DOLLARS (Currency).
	bool			m_bSelling;			// true = ask. false = bid.
	// ---------------------------------------------------------
	// If a bid, this is the most I will pay. If an ask, this is the least I will sell for. My limit.
	// (Normally the price I get is whatever is the best one on the market right now.)
	int64_t	m_lPriceLimit;			// Denominated in CURRENCY TYPE, and priced per SCALE. 
									// 1oz market price limit might be 1,300
									// 100oz market price limit might be 130,000 (or 127,987 or whatever)
	
	int64_t	m_lTransactionNum;		// Matches to an OTTrade stored in OTCron.
	int64_t	m_lTotalAssetsOffer;	// Total amount of ASSET TYPE trying to BUY or SELL, this trade. 
	int64_t	m_lFinishedSoFar;		// Number of ASSETs bought or sold already against the above total.
	
	int64_t	m_lScale;				// 1oz market? 100oz market? 10,000oz market? This determines size and granularity.
	int64_t	m_lMinimumIncrement;	// Each sale or purchase against the above total must be in minimum increments.
									// Minimum Increment must be evenly divisible by m_lScale. 
	// (This effectively becomes a "FILL OR KILL" order if set to the same value as m_lTotalAssetsOffer. Also, MUST be 1
	// or great. CANNOT be zero. Enforce this at class level. You cannot sell something in minimum increments of 0.)
    // ---------------------------------------------------------
	inline void SetTransactionNum(const int64_t & lTransactionNum) { m_lTransactionNum = lTransactionNum; }
	inline void SetPriceLimit(const int64_t & lPriceLimit) { m_lPriceLimit = lPriceLimit; }
	inline void SetTotalAssetsOnOffer(const int64_t & lTotalAssets) { m_lTotalAssetsOffer = lTotalAssets; }
	inline void SetFinishedSoFar(const int64_t & lFinishedSoFar) { m_lFinishedSoFar = lFinishedSoFar; }
	inline void SetMinimumIncrement(const int64_t & lMinIncrement) 
	{ m_lMinimumIncrement = lMinIncrement; if (m_lMinimumIncrement < 1) m_lMinimumIncrement = 1; }
	inline void SetScale(const int64_t & lScale) 
	{ m_lScale = lScale; if (m_lScale < 1) m_lScale = 1; }
// ---------------------------------------------------------
public:
EXPORT bool MakeOffer(      bool   bBuyingOrSelling,    // True == SELLING, False == BUYING
                      const int64_t & lPriceLimit,         // Per Scale...
                      const int64_t & lTotalAssetsOffer,   // Total assets available for sale or purchase.
                      const int64_t & lMinimumIncrement,   // The minimum increment that must be bought or sold for each transaction
                      const int64_t & lTransactionNum,     // The transaction number authorizing this trade.
                      const time64_t & VALID_FROM = OT_TIME_ZERO,    // defaults to RIGHT NOW
                      const time64_t & VALID_TO = OT_TIME_ZERO);   // defaults to 24 hours (a "Day Order")
	// ---------------------------------------------------------
	inline void IncrementFinishedSoFar(const int64_t & lFinishedSoFar) { m_lFinishedSoFar += lFinishedSoFar; }
	
	inline int64_t			GetAmountAvailable()    const { return GetTotalAssetsOnOffer() - GetFinishedSoFar(); }
	inline const int64_t & GetTransactionNum()     const { return m_lTransactionNum; }

	inline const int64_t & GetPriceLimit()         const { return m_lPriceLimit; }
	inline const int64_t & GetTotalAssetsOnOffer() const { return m_lTotalAssetsOffer; }
	inline const int64_t & GetFinishedSoFar()      const { return m_lFinishedSoFar; }
	inline const int64_t & GetMinimumIncrement() 
        { if (m_lMinimumIncrement < 1) m_lMinimumIncrement = 1; return m_lMinimumIncrement; }
	inline const int64_t & GetScale() 
        { if (m_lScale < 1) m_lScale = 1; return m_lScale; }
	
	inline const OTIdentifier & GetCurrencyID() const { return m_CURRENCY_TYPE_ID; }
	inline void SetCurrencyID(const OTIdentifier & CURRENCY_ID) { m_CURRENCY_TYPE_ID = CURRENCY_ID; }	

	// Buying or selling?
	inline bool IsBid() { return !m_bSelling; }
	inline bool IsAsk() { return  m_bSelling; }
	
    bool IsMarketOrder() const;
    bool IsLimitOrder () const;
    
	// Stores a pointer to theTrade for later use. (Not responsible to clean up, just convenient.)
	inline OTTrade * GetTrade() { return m_pTrade; }
	inline void SetTrade(const OTTrade & theTrade) { m_pTrade = &((OTTrade &)theTrade); }
    // ---------------------------------------------------------
    // Note: m_tDateAddedToMarket is not saved in the Offer Contract, but OTMarket sets/saves/loads it.
    //
EXPORT    time64_t GetDateAddedToMarket() const;       // Used in OTMarket::GetOfferList and GetNymOfferList.
EXPORT    void   SetDateAddedToMarket(time64_t tDate); // Used in OTCron when adding/loading offers.
	// ----------------------------------------------------------
EXPORT	OTOffer();		// The constructor contains the 3 variables needed to identify any market.
EXPORT	OTOffer(const OTIdentifier & SERVER_ID,
                const OTIdentifier & ASSET_ID, const OTIdentifier & CURRENCY_ID, const int64_t & MARKET_SCALE);
EXPORT	virtual ~OTOffer();

	// Overridden from OTContract.
	virtual void GetIdentifier(OTIdentifier & theIdentifier);

	void InitOffer();

	virtual void Release();
	void Release_Offer();

	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int32_t ProcessXMLNode(irr::io::IrrXMLReader*& xml);

	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 

	virtual bool SaveContractWallet(std::ofstream & ofs);
};



} // namespace opentxs

#endif // __OT_OFFER_HPP__
