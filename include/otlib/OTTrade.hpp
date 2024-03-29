/************************************************************
 *
 *  OTTrade.hpp
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

// An OTTrade is derived from OTCronItem. OTCron has a list of items,
// which may be trades or agreements or who knows what next.

#ifndef __OT_TRADE_HPP__
#define __OT_TRADE_HPP__

#include "OTCronItem.hpp"

namespace opentxs {

class OTIdentifier;
class OTPseudonym;


/*
 OTTrade

 Standing Order (for Trades) MUST STORE:

 X 1) Transaction ID // It took a transaction number to create this trade. We record it here and use it to uniquely identify the trade, like any other transaction.
 X 4) CURRENCY TYPE ID  (Currency type ID of whatever I’m trying to buy or sell WITH. Dollars? Euro?)
 X 5) Account ID SENDER (for above currency type. This is the account where I make my payments from, to satisfy the trades.)
 X 6) Valid date range. (Start. Expressed as an absolute date.)
 X 7) Valid date range. ( End. Expressed as an absolute date.)

 X 2) Creation date.
 X 3) INTEGER: Number of trades that have processed through this order.

 X 8) STOP ORDER — SIGN (NULL if not a stop order — otherwise GREATER THAN or LESS THAN…)
 X 9) STOP ORDER — PRICE (…AT X PRICE, POST THE OFFER TO THE MARKET.)

 Cron for these orders must check expiration dates and stop order prices.

 ———————————————————————————————
 */

class OTTrade : public OTCronItem
{
private:  // Private prevents erroneous use by other classes.
    typedef OTCronItem ot_super;

private:
    OTIdentifier    m_CURRENCY_TYPE_ID;     // GOLD (Asset) is trading for DOLLARS (Currency).
    OTIdentifier    m_CURRENCY_ACCT_ID;     // My Dollar account, used for paying for my Gold (say) trades.

    OTOffer		*   m_pOffer;               // The pointer to the Offer (NOT responsible for cleaning this up!!!
                                            // The offer is owned by the market and I only keep a pointer here for convenience.

    bool            m_bHasTradeActivated;	// Has the offer yet been first added to a market?

    int64_t            m_lStopPrice;			// The price limit that activates the STOP order.
    char            m_cStopSign;			// Value is 0, or '<', or '>'.
    bool            m_bHasStopActivated;	// If the Stop Order has already activated, I need to know that.

    int32_t             m_nTradesAlreadyDone;	// How many trades have already processed through this order? We keep track.

    OTString        m_strOffer;				// The market offer associated with this trade.

protected:
    virtual void onFinalReceipt(OTCronItem & theOrigCronItem, const int64_t & lNewTransactionNumber,
                                OTPseudonym & theOriginator,
                                OTPseudonym * pRemover);
    virtual void onRemovalFromCron();

public:
EXPORT	bool  VerifyOffer(OTOffer & theOffer);
EXPORT	bool  IssueTrade(OTOffer & theOffer, char cStopSign=0, int64_t lStopPrice=0);

	// The Trade always stores the original, signed version of its Offer.
	// This method allows you to grab a copy of it.
	inline bool GetOfferString(OTString & strOffer)
	{ strOffer.Set(m_strOffer); return m_strOffer.Exists() ? true : false; }

	inline bool	IsStopOrder() const { if ((m_cStopSign == '<') || (m_cStopSign == '>')) return true; return false; }

	inline const int64_t & GetStopPrice() const { return m_lStopPrice; }

	inline bool IsGreaterThan()	const { if ((m_cStopSign == '>')) return true; return false; }
	inline bool IsLessThan()	const { if ((m_cStopSign == '<')) return true; return false; }

	// optionally returns the offer's market ID and a pointer to the market.
	OTOffer	* GetOffer(OTIdentifier * pOFFER_MARKET_ID=NULL, OTMarket ** ppMarket=NULL);
	// --------------------------------------------------------------------------
	inline const OTIdentifier & GetCurrencyID() const { return m_CURRENCY_TYPE_ID; }
	inline void SetCurrencyID(const OTIdentifier & CURRENCY_ID) { m_CURRENCY_TYPE_ID = CURRENCY_ID; }

	inline const OTIdentifier & GetCurrencyAcctID() const { return m_CURRENCY_ACCT_ID; }
	inline void SetCurrencyAcctID(const OTIdentifier & CURRENCY_ACCT_ID) { m_CURRENCY_ACCT_ID = CURRENCY_ACCT_ID; }
	// --------------------------------------------------------------------------
	inline void IncrementTradesAlreadyDone() { m_nTradesAlreadyDone++;      }
	inline int32_t  GetCompletedCount()          { return m_nTradesAlreadyDone; }
	// --------------------------------------------------------------------------
EXPORT    int64_t GetAssetAcctClosingNum() const;
EXPORT    int64_t GetCurrencyAcctClosingNum() const;

	// From OTCronItem (parent class of this)
	/*
	 inline void SetCronPointer(OTCron & theCron) { m_pCron = &theCron; }

	 inline void SetCreationDate(const time64_t & CREATION_DATE) { m_CREATION_DATE = CREATION_DATE; }
	 inline const time64_t & GetCreationDate() const { return m_CREATION_DATE; }
	 */
	// Return True if should stay on OTCron's list for more processing.
	// Return False if expired or otherwise should be removed.
	virtual bool ProcessCron(); // OTCron calls this regularly, which is my chance to expire, etc.
	virtual bool CanRemoveItemFromCron(OTPseudonym & theNym);
	// --------------------------------------------------------------------------
	// From OTTrackable (parent class of OTCronItem, parent class of this)
	/*
	 inline int64_t GetTransactionNum() const { return m_lTransactionNum; }
	 inline void SetTransactionNum(int64_t lTransactionNum) { m_lTransactionNum = lTransactionNum; }

	 inline const OTIdentifier & GetSenderAcctID()	{ return m_SENDER_ACCT_ID; }
	 inline const OTIdentifier & GetSenderUserID()	{ return m_SENDER_USER_ID; }
	 inline void	SetSenderAcctID(const OTIdentifier & ACCT_ID)	{ m_SENDER_ACCT_ID = ACCT_ID; }
	 inline void	SetSenderUserID(const OTIdentifier & USER_ID)	{ m_SENDER_USER_ID = USER_ID; }
	 */
	// --------------------------------------------------------------------------
	// From OTInstrument (parent class of OTTrackable, parent class of OTCronItem, parent class of this)
	/*
	 OTInstrument(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : OTContract()

	 inline const OTIdentifier &	GetAssetID() const { return m_AssetTypeID; }
	 inline const OTIdentifier &	GetServerID() const { return m_ServerID; }

	 inline void					SetAssetID(const OTIdentifier & ASSET_ID)  { m_AssetTypeID	= ASSET_ID; }
	 inline void					SetServerID(const OTIdentifier & SERVER_ID) { m_ServerID	= SERVER_ID; }

	 inline time64_t					GetValidFrom()	const { return m_VALID_FROM; }
	 inline time64_t					GetValidTo()		const { return m_VALID_TO; }

	 inline void					SetValidFrom(time64_t TIME_FROM)	{ m_VALID_FROM	= TIME_FROM; }
	 inline void					SetValidTo(time64_t TIME_TO)		{ m_VALID_TO	= TIME_TO; }

	 bool VerifyCurrentDate(); // Verify the current date against the VALID FROM / TO dates.
	 */
	//----------------------------------------------------------------------
	// From OTScriptable, we override this function. OTScriptable now does fancy stuff like checking to see
	// if the Nym is an agent working on behalf of a party to the contract. That's how all OTScriptable-derived
	// objects work by default.  But OTAgreement (payment plan) and OTTrade do it the old way: they just check to
	// see if theNym has signed *this.
	//
	virtual bool VerifyNymAsAgent(OTPseudonym & theNym,
                                  OTPseudonym & theSignerNym,
                                  mapOfNyms	* pmap_ALREADY_LOADED=NULL);

	virtual bool VerifyNymAsAgentForAccount(OTPseudonym & theNym, OTAccount & theAccount);
	//----------------------------------------------------------------------
EXPORT  OTTrade();
        OTTrade(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
EXPORT  OTTrade(const OTIdentifier & SERVER_ID,
                const OTIdentifier & ASSET_ID, const OTIdentifier & ASSET_ACCT_ID,
                const OTIdentifier & USER_ID,
                const OTIdentifier & CURRENCY_ID, const OTIdentifier & CURRENCY_ACCT_ID);
EXPORT	virtual ~OTTrade();

	void InitTrade();

	void Release_Trade();
	virtual void Release();
	// ------------------------------------------------------
	virtual int64_t GetClosingNumber(const OTIdentifier	& theAcctID) const;
	// ------------------------------------------------------
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int32_t ProcessXMLNode(irr::io::IrrXMLReader*& xml);

	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents

	virtual bool SaveContractWallet(std::ofstream & ofs);
};



} // namespace opentxs

#endif // __OT_TRADE_HPP__
