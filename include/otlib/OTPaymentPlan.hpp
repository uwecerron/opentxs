/************************************************************
 *
 *  OTPaymentPlan.hpp
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

#ifndef __OT_PAYMENT_PLAN_HPP__
#define __OT_PAYMENT_PLAN_HPP__

#include "OTAgreement.hpp"


//#define PLAN_PROCESS_INTERVAL		OT_TIME_HOUR_IN_SECONDS // todo put this back.

namespace opentxs {

#define PLAN_PROCESS_INTERVAL		OTTimeGetTimeFromSeconds(10)


/*
 OTPaymentPlan

 This instrument is signed by two parties or more (the first one, I think...)

 While processing payment, BOTH parties to a payment plan will be loaded up and
 their signatures will be checked against the original plan, which is saved as a
 cron receipt.

 There is also a "current version" of the payment plan, which contains updated info
 from processing, and is signed by the server.

 BOTH the original version, and the updated version, are sent to EACH user whenever
 a payment is processed, as his receipt. This way you have the user's signature on
 the terms, and the server's signature whenever it carries out the terms. A receipt
 with both is placed in the inbox of both users after any action.

 As with cheques, the server can use the receipts in the inboxes, plus the last agreed
 balance, to prove the current balance of any account. The user removes the receipt from
 his inbox by accepting it and, in the process, performing a new balance agreement.

 THIS MEANS that the OT server can carry out the terms of contracts!  So far, at least,
 cheques, trades, payment plans... as long as everything is signed off, we're free and
 clear under the same triple-signed system that account transfer uses. (The Users cannot
 repudiate their own signatures later, and the server can prove all balances with the
 user's own signature.)

 Of course, either side is free to CANCEL a payment plan, or to leave their account bereft
 of funds and prone to failed payments. But if they cancel, their signature will appear
 on the cancellation request, and the recipient gets a copy of it in his inbox. And if
 the funds are insufficient, the plan will keep trying to charge, leaving failure notices
 in both inboxes when such things occur.

 You could even have the server manage an issuer account, backed in payment plan revenue,
 that would form a new asset type that can then be traded on markets. (The same as you can
 have the server manage the issuer account for a basket currency now, which is backed with
 reserve accounts managed by the server, and you can then trade the basket currency on markets.)
 */
class OTPaymentPlan : public OTAgreement
{
private:  // Private prevents erroneous use by other classes.
    typedef OTAgreement ot_super;

	// *************************** Methods for generating a payment plan: ***************************

public:
	// From parent:  (This must be called first, before the other two methods below can be called.)
	//
	//	bool		SetAgreement(const int64_t & lTransactionNum,	const OTString & strConsideration,
	//							 const time64_t & VALID_FROM=0,	const time64_t & VALID_TO=0);

	// Then call one (or both) of these:

EXPORT	bool		SetInitialPayment(const int64_t & lAmount, time64_t tTimeUntilInitialPayment=OT_TIME_ZERO); // default: now.

	// These two can be called independent of each other. You can
	// have an initial payment, AND/OR a payment plan.

EXPORT	bool		SetPaymentPlan(const int64_t & lPaymentAmount, time64_t tTimeUntilPlanStart=OT_TIME_MONTH_IN_SECONDS,
							   time64_t tBetweenPayments = OT_TIME_MONTH_IN_SECONDS, // Default: 30 days.
							   time64_t tPlanLength=OT_TIME_ZERO, int32_t nMaxPayments=0);

	// VerifyAgreement()
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
    virtual bool VerifyAgreement(OTPseudonym & RECIPIENT_NYM, OTPseudonym & SENDER_NYM);
    virtual bool CompareAgreement(const OTAgreement & rh) const;


	// ********************* "INITIAL PAYMENT" public GET METHODS	*********************
public:
	inline bool				HasInitialPayment()		const	{ return m_bInitialPayment; }
	inline const time64_t &	GetInitialPaymentDate()	const	{ return m_tInitialPaymentDate; }
	inline const int64_t &		GetInitialPaymentAmount()const	{ return m_lInitialPaymentAmount; }
	inline bool				IsInitialPaymentDone()	const	{ return m_bInitialPaymentDone; }

	inline const time64_t &	GetInitialPaymentCompletedDate() const	{ return m_tInitialPaymentCompletedDate; }
	inline const time64_t &	GetLastFailedInitialPaymentDate() const	{ return m_tFailedInitialPaymentDate; }
	inline int32_t				GetNoInitialFailures()	 const	{ return m_nNumberInitialFailures; }


	// "INITIAL PAYMENT" private MEMBERS
private:
	bool	m_bInitialPayment;				// Will there be an initial payment?
	time64_t	m_tInitialPaymentDate;			// Date of the initial payment, measured seconds after creation.
	time64_t	m_tInitialPaymentCompletedDate;	// Date the initial payment was finally transacted.
	time64_t	m_tFailedInitialPaymentDate;	// Date of the last failed payment, measured seconds after creation.
	int64_t	m_lInitialPaymentAmount;		// Amount of the initial payment.
	bool	m_bInitialPaymentDone;			// Has the initial payment been made?
	int32_t		m_nNumberInitialFailures;		// If we've tried to process this multiple times, we'll know.

	// --------------------------------------------------------------------------
	// "INITIAL PAYMENT" protected SET METHODS
protected:
	inline void SetInitialPaymentDate(const time64_t & tInitialPaymentDate) { m_tInitialPaymentDate = tInitialPaymentDate; }
	inline void SetInitialPaymentAmount(const int64_t & lAmount)	{ m_lInitialPaymentAmount = lAmount; }

	// Sets the bool that officially the initial payment has been done. (Checks first to make sure not already done.)
	bool SetInitialPaymentDone();

	inline void SetInitialPaymentCompletedDate(const time64_t & tInitialPaymentDate)
	{ m_tInitialPaymentCompletedDate = tInitialPaymentDate; }
	inline void SetLastFailedInitialPaymentDate(const time64_t & tFailedInitialPaymentDate)
	{ m_tFailedInitialPaymentDate = tFailedInitialPaymentDate; }

	inline void	SetNoInitialFailures(const int32_t & nNoFailures)	{ m_nNumberInitialFailures = nNoFailures; }
	inline void	IncrementNoInitialFailures()					{ m_nNumberInitialFailures++; }


// --------------------------------------------------------------------------



	// ********************* "PAYMENT PLAN" public GET METHODS *********************
public:
	inline bool				HasPaymentPlan()		 const	{ return m_bPaymentPlan; }
	inline const int64_t &		GetPaymentPlanAmount()	 const	{ return m_lPaymentPlanAmount; }
	inline const time64_t &	GetTimeBetweenPayments() const	{ return m_tTimeBetweenPayments; }
	inline const time64_t &	GetPaymentPlanStartDate()const	{ return m_tPaymentPlanStartDate; }
	inline const time64_t &	GetPaymentPlanLength()	 const	{ return m_tPaymentPlanLength; }
	inline int32_t				GetMaximumNoPayments()	 const	{ return m_nMaximumNoPayments; }

	inline const time64_t &	GetDateOfLastPayment()	 const	{ return m_tDateOfLastPayment; }
	inline const time64_t &	GetDateOfLastFailedPayment() const { return m_tDateOfLastFailedPayment; }

	inline int32_t				GetNoPaymentsDone()		 const	{ return m_nNoPaymentsDone; }
	inline int32_t				GetNoFailedPayments()	 const	{ return m_nNoFailedPayments; }

	// --------------------------------------------------------------------------
	// "PAYMENT PLAN" private MEMBERS
private:
	bool	m_bPaymentPlan;			// Will there be a payment plan?
	int64_t	m_lPaymentPlanAmount;	// Amount of each payment.
	time64_t	m_tTimeBetweenPayments;	// How much time between each payment?
	time64_t	m_tPaymentPlanStartDate;// Date for the first payment plan payment.
	time64_t	m_tPaymentPlanLength;	// Optional. Plan length measured in seconds since plan start.
	int32_t		m_nMaximumNoPayments;	// Optional. The most number of payments that are authorized.

	time64_t	m_tDateOfLastPayment;	// Recording of date of the last payment.
	time64_t	m_tDateOfLastFailedPayment;	// Recording of date of the last failed payment.
	int32_t		m_nNoPaymentsDone;		// Recording of the number of payments already processed.
	int32_t		m_nNoFailedPayments;	// Every time a payment fails, we record that here.

	// --------------------------------------------------------------------------
	// "PAYMENT PLAN" protected SET METHODS
protected:
	inline void SetPaymentPlanAmount(const		 int64_t &	lAmount)		{ m_lPaymentPlanAmount		= lAmount; }
	inline void SetTimeBetweenPayments(const	 time64_t & tTimeBetween)	{ m_tTimeBetweenPayments	= tTimeBetween; }
	inline void SetPaymentPlanStartDate(const	 time64_t & tPlanStartDate)	{ m_tPaymentPlanStartDate	= tPlanStartDate; }
	inline void SetPaymentPlanLength(const		 time64_t & tPlanLength)	{ m_tPaymentPlanLength		= tPlanLength; }
	inline void SetMaximumNoPayments(			 int32_t	nMaxNoPayments)	{ m_nMaximumNoPayments		= nMaxNoPayments; }

	inline void SetDateOfLastPayment(const		 time64_t&tDateOfLast)	{ m_tDateOfLastPayment		= tDateOfLast; }
	inline void SetDateOfLastFailedPayment(const time64_t&tDateOfLast)	{ m_tDateOfLastFailedPayment= tDateOfLast; }

	inline void SetNoPaymentsDone(				 int32_t	nNoPaymentsDone){ m_nNoPaymentsDone			= nNoPaymentsDone; }
	inline void SetNoFailedPayments(			 int32_t	nNoFailed)		{ m_nNoFailedPayments		= nNoFailed; }

	inline void IncrementNoPaymentsDone()								{ m_nNoPaymentsDone++; }
	inline void IncrementNoFailedPayments()								{ m_nNoFailedPayments++; }

// --------------------------------------------------------------------------------------------------

private:	// These are NOT stored as part of the payment plan. They are merely used during execution.
	bool	m_bProcessingInitialPayment;
	bool	m_bProcessingPaymentPlan;

public:
	// --------------------------------------------------------------------------

	// From OTAgreement (parent class of this)
	/*
	 inline OTIdentifier &	GetRecipientAcctID()		{ return m_RECIPIENT_ACCT_ID; }
	 inline OTIdentifier &	GetRecipientUserID()		{ return m_RECIPIENT_USER_ID; }
	 inline void			SetRecipientAcctID(OTIdentifier & ACCT_ID)	{ m_RECIPIENT_ACCT_ID = ACCT_ID; }
	 inline void			SetRecipientUserID(OTIdentifier & USER_ID)	{ m_RECIPIENT_USER_ID = USER_ID; }

     const OTString &  GetConsideration() const { return m_strConsideration; }
	 */
	// Return True if should stay on OTCron's list for more processing.
	// Return False if expired or otherwise should be removed.
	virtual bool ProcessCron(); // OTCron calls this regularly, which is my chance to expire, etc.

	// --------------------------------------------------------------------------

	// From OTCronItem (parent class of OTAgreement, parent class of this)

	/*
	 inline void SetCronPointer(OTCron & theCron) { m_pCron = &theCron; }

	 inline void SetCreationDate(const time64_t & CREATION_DATE) { m_CREATION_DATE = CREATION_DATE; }
	 inline const time64_t & GetCreationDate() const { return m_CREATION_DATE; }
	 */

	// --------------------------------------------------------------------------

	// From OTTrackable (parent class of OTCronItem, parent class of OTAgreement, parent of this)
	/*
	 inline int64_t GetTransactionNum() const { return m_lTransactionNum; }
	 inline void SetTransactionNum(int64_t lTransactionNum) { m_lTransactionNum = lTransactionNum; }

	 inline const   OTIdentifier &	GetSenderAcctID()               { return m_SENDER_ACCT_ID; }
	 inline const   OTIdentifier &	GetSenderUserID()               { return m_SENDER_USER_ID; }
	 inline void	SetSenderAcctID(const OTIdentifier & ACCT_ID)	{ m_SENDER_ACCT_ID = ACCT_ID; }
	 inline void	SetSenderUserID(const OTIdentifier & USER_ID)	{ m_SENDER_USER_ID = USER_ID; }
	 */

	// --------------------------------------------------------------------------

	// From OTInstrument (parent of OTTrackable, parent of OTCronItem, parent of OTAgreement, parent of this)
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
	 bool IsExpired()
	 */
    // --------------------------------------------
protected:
//  virtual void onFinalReceipt();        // Now handled in the parent class.
//  virtual void onRemovalFromCron();     // Now handled in the parent class.

	bool ProcessPayment(const int64_t & lAmount);
	void ProcessInitialPayment();
	void ProcessPaymentPlan();
	// --------------------------------------------
public:
EXPORT  OTPaymentPlan();
EXPORT  OTPaymentPlan(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID);
EXPORT  OTPaymentPlan(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
                      const OTIdentifier & SENDER_ACCT_ID,		const OTIdentifier & SENDER_USER_ID,
                      const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID);
EXPORT	virtual ~OTPaymentPlan();
    // --------------------------------------------
	void InitPaymentPlan();
    // --------------------------------------------
	virtual void Release();
	void Release_PaymentPlan();
	// --------------------------------------------
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int32_t ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents
	virtual bool SaveContractWallet(std::ofstream & ofs);
};



} // namespace opentxs

#endif // __OT_PAYMENT_PLAN_HPP__
