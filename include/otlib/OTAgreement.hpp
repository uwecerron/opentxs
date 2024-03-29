/************************************************************
 *
 *  OTAgreement.hpp
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

// OTAgreement is derived from OTCronItem.  It handles re-occuring billing.

#ifndef __OT_AGREEMENT_HPP__
#define __OT_AGREEMENT_HPP__

#include "OTCronItem.hpp"

namespace opentxs {

class OTPseudonym;


// An Agreement occurs between TWO PEOPLE, and is for a CONSIDERATION.
// Thus, we add the RECIPIENT (already have SENDER from OTTrackable.)
//
// While other instruments are derived from OTTrackable (like OTCheque) in order
// to gain a transaction number and sender user/acct, Agreements are derived from
// a further subclass of trackable: OTCronItem.
//
// OTCronItems are allowed to be posted on the OTCron object, which performs regular
// processing on a timely basis to the items that are posted there. In this way,
// payment authorizations can be posted (and expire properly), and trades can be
// posted with valid date ranges, and payment plans can be instituted, and so on.
//
// OTAgreement is derived from OTCronItem because it allows people to post Agreements
// on OTCron until a certain expiration period, so that third parties can query the
// server and verify the agreements, and so that copies of the agreement, stamped
// with the server's signature, can be made available to the parties and to 3rd parties.
//
class OTAgreement : public OTCronItem
{
private:  // Private prevents erroneous use by other classes.
    typedef OTCronItem ot_super;

private:
	OTIdentifier	m_RECIPIENT_ACCT_ID;
	OTIdentifier	m_RECIPIENT_USER_ID;

protected:
	OTString		m_strConsideration;	// Presumably an agreement is in return for some consideration. Memo here.

    OTString        m_strMerchantSignedCopy; // The merchant sends it over, then the payer confirms it, which adds
    // his own transaction numbers and signs it. This, unfortunately, invalidates the merchant's version, so we store
    // a copy of the merchant's signed agreement INSIDE our own. The server can do the hard work of comparing them, though
    // such will probably occur through a comparison function I'll have to add right here in this class.

    virtual void onFinalReceipt(OTCronItem & theOrigCronItem, const int64_t & lNewTransactionNumber,
                                OTPseudonym & theOriginator,
                                OTPseudonym * pRemover);
    virtual void onRemovalFromCron();

    std::deque<int64_t> m_dequeRecipientClosingNumbers; // Numbers used for CLOSING a transaction. (finalReceipt.)

public:
	// --------------------------------------------------------------------------
    const OTString &  GetConsideration() const { return m_strConsideration; }
	// --------------------------------------------------------------------------
    void SetMerchantSignedCopy(const OTString & strMerchantCopy) { m_strMerchantSignedCopy = strMerchantCopy; }
    const OTString & GetMerchantSignedCopy() { return m_strMerchantSignedCopy; }

    // SetAgreement replaced with the 2 functions below. See notes even lower.
    //
//	bool	SetAgreement(const int64_t & lTransactionNum,	const OTString & strConsideration,
//                       const time64_t & VALID_FROM=0,	const time64_t & VALID_TO=0);

EXPORT    bool    SetProposal(OTPseudonym & MERCHANT_NYM, const OTString & strConsideration,
                                const time64_t VALID_FROM = OT_TIME_ZERO, const time64_t VALID_TO = OT_TIME_ZERO);

EXPORT    bool    Confirm(OTPseudonym & PAYER_NYM, OTPseudonym * pMERCHANT_NYM=NULL,
                          const OTIdentifier * p_id_MERCHANT_NYM=NULL);  // Merchant Nym is passed here so we can verify the signature before confirming.

    // What should be the process here?

    /*
        FIRST: (Construction)
     OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID);
       OR:
     OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
                const OTIdentifier & SENDER_ACCT_ID,	const OTIdentifier & SENDER_USER_ID,
                const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID);
       OR:
     OTPaymentPlan * pPlan = new OTPaymentPlan(pAccount->GetRealServerID(),
                                    pAccount->GetAssetTypeID(),
                                    pAccount->GetRealAccountID(),
                                    pAccount->GetUserID(),
                                    RECIPIENT_ACCT_ID, RECIPIENT_USER_ID);
     // --------------------------------------------------------------------------------------------------------
     THEN:  (Agreement)

     bool bSuccessSetAgreement = pPlan->SetAgreement(lTransactionNumber, PLAN_CONSIDERATION, VALID_FROM, VALID_TO);
     // --------------------------------------------------------------------------------------------------------
     THEN, (OTPaymentPlan) adds TWO OPTIONS (additional and independent of each other):

     bool		SetInitialPayment(const int64_t & lAmount, time64_t tTimeUntilInitialPayment=0); // default: now.
     // --------------------------------------------------------------------------------------------------------
     bool		SetPaymentPlan(const int64_t & lPaymentAmount, time64_t tTimeUntilPlanStart=OT_TIME_MONTH_IN_SECONDS,
                                time64_t tBetweenPayments=OT_TIME_MONTH_IN_SECONDS, // Default: 30 days.
                                time64_t tPlanLength=0, int32_t nMaxPayments=0);

     // ********************************************************************************

     The new process is the same, but it adds some additional transaction numbers...

     HERE IS THE WAY I ENVISION IT BEING CALLED:

     ---- The MERCHANT does these steps: -----

     Step one, though it says PaymentPlan, is basically the OTAgreement constructor.
     Its primary concern is with determining the server, payer, payee, accounts, etc.

     1) OTPaymentPlan * pPlan =
        new OTPaymentPlan(pAccount->GetRealServerID(),
            pAccount->GetAssetTypeID(),
            pAccount->GetRealAccountID(),
            pAccount->GetUserID(),
            RECIPIENT_ACCT_ID, RECIPIENT_USER_ID);

    STILL, this is the MERCHANT. Step two is concerned with the specific terms of the offer.

     2) bool bOffer =
            pPlan->SetProposal(MERCHANT_NYM,
                        PLAN_CONSIDERATION, VALID_FROM, VALID_TO);
      (lMerchantTransactionNumber, lMerchantClosingNumber are set internally using the MERCHANT_NYM.)

     ==> Optionally, the merchant also calls SetInitialPayment and/or SetPaymentPlan at this time.
     ==> Next, the merchant signs it, and sends to the recipient.

     THE RECIPIENT:

     3) bool bConfirmation =  pPlan->Confirm(OTPseudonym & PAYER_NYM,
                                             OTPseudonym * pMERCHANT_NYM=NULL,
                                             OTIdentifier * p_id_MERCHANT_NYM=NULL);

     (Transaction number and closing number are retrieved from Nym at this time.)

     NO NEED TO SIGN ANYTHING AFTER THIS POINT, and the Payment Plan should store a copy of itself at this time.
    (That is, STORE A COPY of the Merchant's signed version, since the above call to Confirm will change the plan
     and sign it again. The server is left with the chore of comparing the two against each other, which I will
     probably have to code right here in this class!  TOdo.)

     */

    // This function verifies both Nyms and both signatures.
    // Due to the peculiar nature of how OTAgreement/OTPaymentPlan works, there are two signed
    // copies stored. The merchant signs first, adding his transaction numbers (2), and then he
    // sends it to the customer, who also adds two numbers and signs. (Also resetting the creation date.)
    // The problem is, adding the additional transaction numbers invalidates the first (merchant's)
    // signature.
    // The solution is, when the customer confirms the agreement, he stores an internal copy of the
    // merchant's signed version.  This way later, in VERIFY AGREEMENT, the internal copy can be loaded,
    // and BOTH Nyms can be checked to verify that BOTH transaction numbers are valid for each.
    // The two versions of the contract can also be compared to each other, to make sure that none of
    // the vital terms, values, clauses, etc are different between the two.
    //
    virtual bool VerifyAgreement(OTPseudonym & RECIPIENT_NYM, OTPseudonym & SENDER_NYM)=0;

    virtual bool CompareAgreement(const OTAgreement & rhs) const;

	// --------------------------------------------------------------------------

	inline const OTIdentifier &	GetRecipientAcctID() const { return m_RECIPIENT_ACCT_ID; }
	inline const OTIdentifier &	GetRecipientUserID() const { return m_RECIPIENT_USER_ID; }
	inline void		SetRecipientAcctID(const OTIdentifier & ACCT_ID)	{ m_RECIPIENT_ACCT_ID = ACCT_ID; }
	inline void		SetRecipientUserID(const OTIdentifier & USER_ID)	{ m_RECIPIENT_USER_ID = USER_ID; }

	// --------------------------------------------------------------------------

    // The recipient must also provide an opening and closing transaction number(s).
    //
EXPORT    int64_t    GetRecipientClosingTransactionNoAt(uint32_t nIndex) const;
EXPORT    int32_t     GetRecipientCountClosingNumbers() const;

    void    AddRecipientClosingTransactionNo(const int64_t & lClosingTransactionNo);
    // ----------------------------------------------------------------------------

    // This is a higher-level than the above functions. It calls them.
    // Below is the abstraction, above is the implementation.

EXPORT    int64_t    GetRecipientOpeningNum() const;
EXPORT    int64_t    GetRecipientClosingNum() const;

    // ----------------------------------------------------------------------------
	// From OTCronItem (parent class of this)
	/*
	 inline void SetCronPointer(OTCron & theCron) { m_pCron = &theCron; }

	 inline void SetCreationDate(const time64_t & CREATION_DATE) { m_CREATION_DATE = CREATION_DATE; }
	 inline const time64_t & GetCreationDate() const { return m_CREATION_DATE; }

     // ------------------------------------------------------
     // These are for:
     // std::deque<int64_t> m_dequeClosingNumbers;
     //
     // They are numbers used for CLOSING a transaction. (finalReceipt, someday more.)

     int64_t    GetClosingTransactionNoAt(int32_t nIndex) const;
     int32_t     GetCountClosingNumbers() const;

     void    AddClosingTransactionNo(const int64_t & lClosingTransactionNo);
	 */
        virtual bool CanRemoveItemFromCron(OTPseudonym & theNym);

        virtual void HarvestOpeningNumber (OTPseudonym & theNym);
EXPORT  virtual void HarvestClosingNumbers(OTPseudonym & theNym);

    // Return True if should stay on OTCron's list for more processing.
	// Return False if expired or otherwise should be removed.
	virtual bool ProcessCron(); // OTCron calls this regularly, which is my chance to expire, etc.

	// --------------------------------------------------------------------------

	// From OTTrackable (parent class of OTCronItem, parent class of this)
	/*
	 inline int64_t GetTransactionNum() const { return m_lTransactionNum; }
	 inline void SetTransactionNum(int64_t lTransactionNum) { m_lTransactionNum = lTransactionNum; }

	 inline const OTIdentifier &	GetSenderAcctID()		{ return m_SENDER_ACCT_ID; }
	 inline const OTIdentifier &	GetSenderUserID()		{ return m_SENDER_USER_ID; }
	 inline void			SetSenderAcctID(const OTIdentifier & ACCT_ID)		{ m_SENDER_ACCT_ID = ACCT_ID; }
	 inline void			SetSenderUserID(const OTIdentifier & USER_ID)		{ m_SENDER_USER_ID = USER_ID; }
	 */

    virtual bool HasTransactionNum(const int64_t & lInput) const;
    virtual void GetAllTransactionNumbers(OTNumList & numlistOutput) const;

	// --------------------------------------------------------------------------

	// From OTInstrument (parent class of OTTrackable, parent class of OTCronItem, parent class of this)
	/*
	 OTInstrument(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : OTContract()

	 inline const OTIdentifier & GetAssetID() const { return m_AssetTypeID; }
	 inline const OTIdentifier & GetServerID() const { return m_ServerID; }

	 inline void SetAssetID(const OTIdentifier & ASSET_ID)  { m_AssetTypeID	= ASSET_ID; }
	 inline void SetServerID(const OTIdentifier & SERVER_ID) { m_ServerID	= SERVER_ID; }

	 inline time64_t GetValidFrom()	const { return m_VALID_FROM; }
	 inline time64_t GetValidTo()		const { return m_VALID_TO; }

	 inline void SetValidFrom(time64_t TIME_FROM)	{ m_VALID_FROM	= TIME_FROM; }
	 inline void SetValidTo(time64_t TIME_TO)		{ m_VALID_TO	= TIME_TO; }

	 bool VerifyCurrentDate(); // Verify the current date against the VALID FROM / TO dates.
	 */

	// From OTScriptable, we override this function. OTScriptable now does fancy stuff like checking to see
	// if the Nym is an agent working on behalf of a party to the contract. That's how all OTScriptable-derived
	// objects work by default.  But OTAgreement (payment plan) and OTTrade do it the old way: they just check to
	// see if theNym has signed *this.
	//
	virtual bool VerifyNymAsAgent(OTPseudonym & theNym,
								  OTPseudonym & theSignerNym,
								  mapOfNyms	* pmap_ALREADY_LOADED=NULL);

	virtual bool VerifyNymAsAgentForAccount(OTPseudonym & theNym, OTAccount & theAccount);

    /*
     From OTContract, I have:

     virtual bool SignContract (const OTPseudonym & theNym);

     */
EXPORT	bool SendNoticeToAllParties(bool bSuccessMsg,
                                    OTPseudonym & theServerNym,
                                    const OTIdentifier & theServerID,
                                    const int64_t & lNewTransactionNumber,
//                                  const int64_t & lInReferenceTo, // each party has its own opening trans #.
                                    const OTString & strReference,
                                    OTString * pstrNote=NULL,
                                    OTString * pstrAttachment=NULL,
                                    OTPseudonym * pActualNym=NULL);

	// -----------------------------------------------
EXPORT static bool DropServerNoticeToNymbox(bool bSuccessMsg, // Nym receives an OTItem::acknowledgment or OTItem::rejection.
                                            OTPseudonym & theServerNym,
                                            const OTIdentifier & SERVER_ID,
                                            const OTIdentifier & USER_ID,
                                            const int64_t & lNewTransactionNumber,
                                            const int64_t & lInReferenceTo,
                                            const OTString & strReference,
                                            OTString * pstrNote=NULL,
                                            OTString * pstrAttachment=NULL,
                                            OTPseudonym * pActualNym=NULL);
	// -----------------------------------------------
	OTAgreement();
	OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID);
	OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
				const OTIdentifier & SENDER_ACCT_ID,	const OTIdentifier & SENDER_USER_ID,
				const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID);
	virtual ~OTAgreement();

	void InitAgreement();

	virtual void Release();
	void Release_Agreement();
    // ------------------------------------------------------
	virtual bool IsValidOpeningNumber(const int64_t & lOpeningNum) const;
    // ------------------------------------------------------
EXPORT	virtual int64_t GetOpeningNumber(const OTIdentifier & theNymID) const;
    virtual int64_t GetClosingNumber(const OTIdentifier & theAcctID) const;
    // ------------------------------------------------------
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int32_t  ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents
	virtual bool SaveContractWallet(std::ofstream & ofs);
};



} // namespace opentxs

#endif // __OT_AGREEMENT_HPP__
