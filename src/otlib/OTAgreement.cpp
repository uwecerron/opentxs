/************************************************************
 *    
 *  OTAgreement.cpp
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

#include "stdafx.hpp"

#include "OTAgreement.hpp"

#include "OTAccount.hpp"
#include "OTCron.hpp"
#include "OTLedger.hpp"
#include "OTLog.hpp"
#include "OTPseudonym.hpp"

#include "irrxml/irrXML.hpp"


// OTAgreement is derived from OTCronItem.  It handles re-occuring billing.

namespace opentxs {

bool OTAgreement::SendNoticeToAllParties(bool bSuccessMsg,
                                         OTPseudonym & theServerNym,
                                         const OTIdentifier & theServerID,
                                         const int64_t & lNewTransactionNumber,
//                                       const int64_t & lInReferenceTo,	// Each party has its own opening trans #.
                                         const OTString & strReference,
                                         OTString * pstrNote/*=NULL*/,
                                         OTString * pstrAttachment/*=NULL*/,
                                         OTPseudonym * pActualNym/*=NULL*/)
{
	bool bSuccess = true;  // Success is defined as ALL parties receiving a notice
    // -------------------------------------------------------
    OTPseudonym   theRecipientNym; // Don't use this... use the pointer just below.
    OTPseudonym * pRecipient = NULL;
    
    if (theServerNym.CompareID(this->GetRecipientUserID()))
    {
        pRecipient = &theServerNym; // Just in case the recipient Nym is also the server Nym.
    }
    else if ((NULL != pActualNym) && pActualNym->CompareID(this->GetRecipientUserID()))
    {
        pRecipient = pActualNym;
    }
    // --------------------------------------------------------------------------------------------------
    if (NULL == pRecipient)
    {
        const OTIdentifier NYM_ID(this->GetRecipientUserID());
        theRecipientNym.SetIdentifier(NYM_ID);
        
        if (false == theRecipientNym.LoadPublicKey())
        {
            const OTString strNymID(NYM_ID);
            OTLog::vError("%s: Failure loading Recipient's public key: %s\n",
                          __FUNCTION__, strNymID.Get());
            return false;
        }
        else if (theRecipientNym.VerifyPseudonym() &&
                 theRecipientNym.LoadSignedNymfile(theServerNym)) // ServerNym here is merely the signer on this file.
        {
            pRecipient = &theRecipientNym; //  <=====
        }
        else
        {
            const OTString strNymID(NYM_ID);
            OTLog::vError("%s: Failure verifying Recipient's public key or loading signed nymfile: %s\n",
                          __FUNCTION__, strNymID.Get());
            return false;
        }
    }
    // BY THIS POINT, the Recipient Nym is definitely loaded up and we have
    // a pointer to him (pRecipient.)
    // -------------------------------------------------------
    OTPseudonym   theSenderNym; // Don't use this... use the pointer just below.
    OTPseudonym * pSender = NULL;
    
    if (theServerNym.CompareID(this->GetSenderUserID()))
    {
        pSender = &theServerNym; // Just in case the Sender Nym is also the server Nym.
    }
    else if ((NULL != pActualNym) && pActualNym->CompareID(this->GetSenderUserID()))
    {
        pSender = pActualNym;
    }
    // --------------------------------------------------------------------------------------------------
    if (NULL == pSender)
    {
        const OTIdentifier NYM_ID(this->GetSenderUserID());
        theSenderNym.SetIdentifier(NYM_ID);
        
        if (false == theSenderNym.LoadPublicKey())
        {
            const OTString strNymID(NYM_ID);
            OTLog::vError("%s: Failure loading Sender's public key: %s\n",
                          __FUNCTION__, strNymID.Get());
            return false;
        }
        else if (theSenderNym.VerifyPseudonym() &&
                 theSenderNym.LoadSignedNymfile(theServerNym)) // ServerNym here is merely the signer on this file.
        {
            pSender = &theSenderNym; //  <=====
        }
        else
        {
            const OTString strNymID(NYM_ID);
            OTLog::vError("%s: Failure verifying Sender's public key or loading signed nymfile: %s\n",
                          __FUNCTION__, strNymID.Get());
            return false;
        }
    }
    // BY THIS POINT, the Sender Nym is definitely loaded up and we have
    // a pointer to him (pSender.)
    // -----------------------------------------------------------------
    // (pRecipient and pSender are both good pointers by this point.)
    // -----------------------------------------------------------------
    // Sender
    if (false == OTAgreement::DropServerNoticeToNymbox(bSuccessMsg, // "success" notice? or "failure" notice?
                                                       theServerNym,
                                                       theServerID,
                                                       this->GetSenderUserID(),
                                                       lNewTransactionNumber,
                                                       GetTransactionNum(), // in reference to
                                                       strReference,
                                                       pstrNote,
                                                       pstrAttachment,
                                                       pSender))
        bSuccess = false;
    // Notice I don't break here -- I still allow it to try to notice ALL parties, even if one fails.
    // -----------------------------------------------------------------
    // Recipient
    if (false == OTAgreement::DropServerNoticeToNymbox(bSuccessMsg, // "success" notice? or "failure" notice?
                                                       theServerNym,
                                                       theServerID,
                                                       this->GetRecipientUserID(),
                                                       lNewTransactionNumber,
                                                       GetRecipientOpeningNum(), // in reference to
                                                       strReference,
                                                       pstrNote,
                                                       pstrAttachment,
                                                       pRecipient))
        bSuccess = false;
    // -----------------------------------------------------------------
	return bSuccess;
}


//static
bool OTAgreement::DropServerNoticeToNymbox(bool bSuccessMsg, // Nym receives an OTItem::acknowledgment or OTItem::rejection.
                                           OTPseudonym & theServerNym,
                                           const OTIdentifier & SERVER_ID,
                                           const OTIdentifier & USER_ID,
                                           const int64_t & lNewTransactionNumber,
                                           const int64_t & lInReferenceTo,
                                           const OTString & strReference,
                                           OTString * pstrNote/*=NULL*/,
                                           OTString * pstrAttachment/*=NULL*/,
                                           OTPseudonym * pActualNym/*=NULL*/)
{
    OTLedger theLedger(USER_ID, USER_ID, SERVER_ID);
    
    // Inbox will receive notification of something ALREADY DONE.
	//
    bool bSuccessLoading = theLedger.LoadNymbox();
    // -------------------------------------------------------------------
    if (true == bSuccessLoading)
        bSuccessLoading		= theLedger.VerifyAccount(theServerNym);
    else
		bSuccessLoading		= theLedger.GenerateLedger(USER_ID, SERVER_ID, OTLedger::nymbox, true); // bGenerateFile=true
    // --------------------------------------------------------------------
    if (false == bSuccessLoading)
    {
        OTLog::vError("%s: Failed loading or generating a nymbox. (FAILED WRITING RECEIPT!!) \n",
                      __FUNCTION__);
        return false;
    }
    // --------------------------------------------------------------------
    OTTransaction * pTransaction = OTTransaction::GenerateTransaction(theLedger,
                                                                      OTTransaction::notice,
                                                                      lNewTransactionNumber);
    
    if (NULL != pTransaction) // The above has an OT_ASSERT within, but I just like to check my pointers.
    {
        // The nymbox will get a receipt with the new transaction ID.
        // That receipt has an "in reference to" field containing the original OTScriptable
		
        // Set up the transaction items (each transaction may have multiple items... but not in this case.)
		//
        OTItem * pItem1	= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::notice);
        OT_ASSERT(NULL != pItem1); // This may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave it for now.
        // -------------------------------------------------------------
        pItem1->SetStatus(bSuccessMsg ? OTItem::acknowledgement : OTItem::rejection); // ACKNOWLEDGMENT or REJECTION ?
        // -------------------------------------------------------------
        //
        // Here I make sure that the receipt (the nymbox notice) references the
        // transaction number that the trader originally used to issue the cron item...
        // This number is used to match up offers to trades, and used to track all cron items.
        // (All Cron items require a transaction from the user to add them to Cron in the
        // first place.)
        //
        pTransaction->SetReferenceToNum(lInReferenceTo);
        // -------------------------------------------------
        // The reference on the transaction probably contains a the original cron item or entity contract.
        // Versus the updated item (which, if it exists, is stored on the pItem1 just below.)
        //
        pTransaction->SetReferenceString(strReference);
        // --------------------------------------------
        // The notice ITEM's NOTE probably contains the UPDATED SCRIPTABLE
        // (usually a CRON ITEM. But maybe soon: Entity.)
        if (NULL != pstrNote)
        {
            pItem1->SetNote(*pstrNote);    // in markets, this is updated trade.
        }
        // -----------------------------------------------------------------
        // Nothing is special stored here so far for OTTransaction::notice, but the option is always there.
        //
        if (NULL != pstrAttachment)
        {
            pItem1->SetAttachment(*pstrAttachment);
        }
        // -----------------------------------------------------------------
        // sign the item
        //
        pItem1->SignContract(theServerNym);
        pItem1->SaveContract();
        
        // the Transaction "owns" the item now and will handle cleaning it up.
        pTransaction->AddItem(*pItem1);
        
        pTransaction->SignContract(theServerNym);
        pTransaction->SaveContract();
        
        // Here the transaction we just created is actually added to the ledger.
        theLedger.AddTransaction(*pTransaction);
        
        // Release any signatures that were there before (They won't
        // verify anymore anyway, since the content has changed.)
        theLedger.ReleaseSignatures();
        
        // Sign and save.
        theLedger.SignContract(theServerNym);
        theLedger.SaveContract();
        
        // TODO: Better rollback capabilities in case of failures here:
        // --------------------
        OTIdentifier theNymboxHash;
        
        // Save nymbox to storage. (File, DB, wherever it goes.)
        theLedger.	SaveNymbox(&theNymboxHash);
        
		// Corresponds to the AddTransaction() call just above. These
		// are stored in a separate file now.
		//
		pTransaction->SaveBoxReceipt(theLedger);
        // --------------------------------------------------------
        // Update the NymboxHash (in the nymfile.)
        //
        const
        OTIdentifier    ACTUAL_NYM_ID = USER_ID;
        OTPseudonym     theActualNym; // unused unless it's really not already loaded. (use pActualNym.)
        
        // We couldn't find the Nym among those already loaded--so we have to load
        // it ourselves (so we can update its NymboxHash value.)
        
        if (NULL == pActualNym)
        {
            if ( theServerNym.CompareID(ACTUAL_NYM_ID) )
                pActualNym = &theServerNym;
            // --------------------------
            else
            {
                theActualNym.SetIdentifier(ACTUAL_NYM_ID);
                
                if (false == theActualNym.LoadPublicKey()) // Note: this step may be unnecessary since we are only updating his Nymfile, not his key.
                {
                    OTString strNymID(ACTUAL_NYM_ID);
                    OTLog::vError("%s: Failure loading public key for Nym: %s. "
                                  "(To update his NymboxHash.) \n", __FUNCTION__, strNymID.Get());
                }
                else if (theActualNym.VerifyPseudonym()	&& // this line may be unnecessary.
                         theActualNym.LoadSignedNymfile(theServerNym)) // ServerNym here is not theActualNym's identity, but merely the signer on this file.
                {
                    OTLog::vOutput(3, "%s: Loading actual Nym, since he wasn't already loaded. "
                                   "(To update his NymboxHash.)\n", __FUNCTION__);
                    pActualNym = &theActualNym; //  <=====
                }
                else
                {
                    OTString strNymID(ACTUAL_NYM_ID);
                    OTLog::vError("%s: Failure loading or verifying Actual Nym public key: %s. "
                                  "(To update his NymboxHash.)\n", __FUNCTION__, strNymID.Get());
                }
            }
        }
        // -------------
        // By this point we've made every possible effort to get the proper Nym loaded,
        // so that we can update his NymboxHash appropriately.
        //
        if (NULL != pActualNym)
        {
            pActualNym->SetNymboxHashServerSide( theNymboxHash );
            pActualNym->SaveSignedNymfile(theServerNym);
        }
        // -------------
        // Really this true should be predicated on ALL the above functions returning true.
        // Right?
        //
        return true;    // Really this true should be predicated on ALL the above functions returning true. Right?
    }
    else
        OTLog::vError("%x: Failed trying to create Nymbox.\n", __FUNCTION__);
	
    return false; // unreachable.
}


// Overrides from OTTrackable.
bool OTAgreement::HasTransactionNum(const int64_t & lInput) const
{
    if (lInput == GetTransactionNum())
        return true;
    // --------------------------------------------------
    const size_t nSizeClosing = m_dequeClosingNumbers.size();
    
    for (size_t nIndex = 0; nIndex < nSizeClosing; ++nIndex)
    {
        if (lInput == m_dequeClosingNumbers.at(nIndex))
            return true;
    }
    // --------------------------------------------------
    const size_t nSizeRecipient = m_dequeRecipientClosingNumbers.size();
    
    for (size_t nIndex = 0; nIndex < nSizeRecipient; ++nIndex)
    {
        if (lInput == m_dequeRecipientClosingNumbers.at(nIndex))
            return true;
    }
    // --------------------------------------------------    
    return false;
}


void OTAgreement::GetAllTransactionNumbers(OTNumList & numlistOutput) const
{
    // --------------------------------------------------
    if (GetTransactionNum() > 0)
        numlistOutput.Add(GetTransactionNum());
    // --------------------------------------------------
    const size_t nSizeClosing = m_dequeClosingNumbers.size();
    
    for (size_t nIndex = 0; nIndex < nSizeClosing; ++nIndex)
    {
        const int64_t lTemp = m_dequeClosingNumbers.at(nIndex);
        if (lTemp > 0)
            numlistOutput.Add(lTemp);
    }
    // --------------------------------------------------
    const size_t nSizeRecipient = m_dequeRecipientClosingNumbers.size();
    
    for (size_t nIndex = 0; nIndex < nSizeRecipient; ++nIndex)
    {
        const int64_t lTemp = m_dequeRecipientClosingNumbers.at(nIndex);
        if (lTemp > 0)
            numlistOutput.Add(lTemp);
    }
    // --------------------------------------------------
}


// Used to be I could just call pAgreement->VerifySignature(theNym), which is what
// I still call here, inside this function. But that's a special case -- an override
// from the OTScriptable / OTSmartContract version, which verifies parties and agents, etc.
//
bool OTAgreement::VerifyNymAsAgent(OTPseudonym & theNym,
                                   OTPseudonym & theSignerNym, // Not needed in this override.
                                   mapOfNyms	 * pmap_ALREADY_LOADED/*=NULL*/)
{
	return this->VerifySignature(theNym);
}


// This is an override. See note above.
//
bool OTAgreement::VerifyNymAsAgentForAccount(OTPseudonym & theNym, OTAccount & theAccount)
{
	return theAccount.VerifyOwner(theNym);
}


// This is called by OTCronItem::HookRemovalFromCron
// (After calling this method, HookRemovalFromCron then calls onRemovalFromCron.)
//
void OTAgreement::onFinalReceipt(OTCronItem  & theOrigCronItem,
                                 const int64_t  & lNewTransactionNumber,
                                 OTPseudonym & theOriginator,
                                 OTPseudonym * pRemover)
{    
    // -------------------------------------------------
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    // -------------------------------------------------
    const char * szFunc = "OTAgreement::onFinalReceipt";
    // -------------------------------------------------
    // The finalReceipt Item's ATTACHMENT contains the UPDATED Cron Item.
    // (With the SERVER's signature on it!)
    //
    OTString strUpdatedCronItem(*this);
    OTString * pstrAttachment=&strUpdatedCronItem;
    
    const OTString strOrigCronItem(theOrigCronItem);
    // -----------------------------------------------------------------
    OTPseudonym theRecipientNym; // Don't use this... use the pointer just below.
    
    // The Nym who is actively requesting to remove a cron item will be passed in as pRemover.
    // However, sometimes there is no Nym... perhaps it just expired and pRemover is NULL.
    // The originating Nym (if different than remover) is loaded up. Otherwise the originator
    // pointer just pointers to *pRemover.
    //
    OTPseudonym * pRecipient = NULL;
    
    if (pServerNym->CompareID(this->GetRecipientUserID()))
    {
        pRecipient = pServerNym; // Just in case the recipient Nym is also the server Nym.
    }
    // *******************************************************
    //
    // If pRemover is NOT NULL, and he has the Recipient's ID...
    // then set the pointer accordingly.
    //
    else if ((NULL != pRemover) && (true == pRemover->CompareID(this->GetRecipientUserID())))
    {
        pRecipient = pRemover; // <======== now both pointers are set (to same Nym). DONE!
    }
    // --------------------------------------------------------------------------------------------------
    if (NULL == pRecipient)
    {
        // GetSenderUserID() should be the same on THIS (updated version of the same cron item) 
        // but for whatever reason, I'm checking the userID on the original version. Sue me.
        //
        const OTIdentifier NYM_ID(this->GetRecipientUserID());
        
        theRecipientNym.SetIdentifier(NYM_ID);  
        
        if (false == theRecipientNym.LoadPublicKey())
        {
            const OTString strNymID(NYM_ID);
            OTLog::vError("%s: Failure loading Recipient's public key:\n%s\n", 
                          szFunc, strNymID.Get());
        }		
        else if (theRecipientNym.VerifyPseudonym() && 
                 theRecipientNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is merely the signer on this file.
        {
            pRecipient = &theRecipientNym; //  <=====
        }
        else 
        {
            const OTString strNymID(NYM_ID);
            OTLog::vError("%s: Failure verifying Recipient's public key or loading signed nymfile: %s\n",
                          szFunc, strNymID.Get());
        }
    }
    // -------------------------------
    // First, we are closing the transaction number ITSELF, of this cron item,
    // as an active issued number on the originating nym. (Changing it to CLOSED.)
    //
    // Second, we're verifying the CLOSING number, and using it as the closing number
    // on the FINAL RECEIPT (with that receipt being "InReferenceTo" this->GetTransactionNum())
    //
    const int64_t lRecipientOpeningNumber = this->GetRecipientOpeningNum();
    const int64_t lRecipientClosingNumber = this->GetRecipientClosingNum();
    // -----------------------------------------------------------------------------------
    const int64_t lSenderOpeningNumber = theOrigCronItem.GetTransactionNum();

    const int64_t lSenderClosingNumber = (theOrigCronItem.GetCountClosingNumbers() > 0) ? 
        theOrigCronItem.GetClosingTransactionNoAt(0) : 0; // index 0 is closing number for sender, since GetTransactionNum() is his opening #.
    // ----------------------------------
    const OTString strServerID(GetServerID());
    // -----------------------------------------------------------------
    OTPseudonym *   pActualNym    = NULL; // use this. DON'T use theActualNym.
    OTPseudonym     theActualNym;         // unused unless it's really not already loaded. (use pActualNym.)
    // -----------------------------------------------------------------
    //
    if ((lSenderOpeningNumber > 0) &&
        theOriginator.VerifyIssuedNum(strServerID, lSenderOpeningNumber))
    {
        // The Nym (server side) stores a list of all opening and closing cron #s.
        // So when the number is released from the Nym, we also take it off that list.
        //
        std::set<int64_t> & theIDSet = theOriginator.GetSetOpenCronItems();
        theIDSet.erase(lSenderOpeningNumber);
        
        // the RemoveIssued call means the original transaction# (to find this cron item on cron) is now CLOSED.
        // But the Transaction itself is still OPEN. How? Because the CLOSING number is still signed out.
        // The closing number is also USED, since the NotarizePaymentPlan or NotarizeMarketOffer call, but it
        // remains ISSUED, until the final receipt itself is accepted during a process inbox.
        //
        theOriginator.RemoveIssuedNum(*pServerNym, strServerID, lSenderOpeningNumber, false); //bSave=false
        theOriginator.SaveSignedNymfile(*pServerNym);
        // ------------------------------------
        const OTIdentifier ACTUAL_NYM_ID = GetSenderUserID();
        
        if ( (NULL != pServerNym) && pServerNym->CompareID(ACTUAL_NYM_ID) )
            pActualNym = pServerNym;
        else if (theOriginator.CompareID(ACTUAL_NYM_ID))
            pActualNym = &theOriginator;
        else if ( (NULL != pRemover) && pRemover->CompareID(ACTUAL_NYM_ID) )
            pActualNym = pRemover;
        // --------------------------
        else    // We couldn't find the Nym among those already loaded--so we have to load
        {       // it ourselves (so we can update its NymboxHash value.)
            theActualNym.SetIdentifier(ACTUAL_NYM_ID);
            
            if (false == theActualNym.LoadPublicKey()) // Note: this step may be unnecessary since we are only updating his Nymfile, not his key.
            {
                OTString strNymID(ACTUAL_NYM_ID);
                OTLog::vError("%s: Failure loading public key for Nym: %s. "
                              "(To update his NymboxHash.) \n", szFunc, strNymID.Get());
            }
            else if (theActualNym.VerifyPseudonym()	&& // this line may be unnecessary.
                     theActualNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is not theActualNym's identity, but merely the signer on this file.
            {
                OTLog::vOutput(3, "%s: Loading actual Nym, since he wasn't already loaded. "
                              "(To update his NymboxHash.)\n", szFunc);
                pActualNym = &theActualNym; //  <=====
            }
            else
            {
                OTString strNymID(ACTUAL_NYM_ID);
                OTLog::vError("%s: Failure loading or verifying Actual Nym public key: %s. "
                              "(To update his NymboxHash.)\n", szFunc, strNymID.Get());
            }
        }
        // -------------
        if (false == this->DropFinalReceiptToNymbox(GetSenderUserID(),
                                                    lNewTransactionNumber,
                                                    strOrigCronItem,
                                                    NULL,
                                                    pstrAttachment,
                                                    pActualNym))
        {
            OTLog::vError("%s: Failure dropping sender final receipt into nymbox.\n", szFunc);
        }        
    }
    else
    {
        OTLog::vError("%s: Failure verifying sender's opening number.\n", szFunc);
    }
    
    // -----------------------------------------------------------------
    
    if ((lSenderClosingNumber > 0) &&
        theOriginator.VerifyIssuedNum(strServerID, lSenderClosingNumber)         
        ) // ---------------------------------------------------------------
    {        
        // In this case, I'm passing NULL for pstrNote, since there is no note.
        // (Additional information would normally be stored in the note.) 
        //
        if (false == this->DropFinalReceiptToInbox(GetSenderUserID(),
                                                   GetSenderAcctID(),
                                                   lNewTransactionNumber,
                                                   lSenderClosingNumber, // The closing transaction number to put on the receipt.
                                                   strOrigCronItem,
                                                   NULL, 
                                                   pstrAttachment)) // pActualAcct=NULL by default. (This call will load it up and update its inbox hash.)
            OTLog::vError("%s: Failure dropping receipt into sender's inbox.\n", szFunc);

        // This part below doesn't happen until theOriginator ACCEPTS the final receipt (when processing his inbox.)
        //
//      theOriginator.RemoveIssuedNum(strServerID, lSenderClosingNumber, true); //bSave=false
    }
    else
    {
        OTLog::vError("%s: Failed verifying lSenderClosingNumber=theOrigCronItem.GetClosingTransactionNoAt(0)>0 &&  "
                      "theOriginator.VerifyTransactionNum(lSenderClosingNumber)\n", szFunc);
    }
    // -----------------------------------------------------------------
    //
    if ((NULL != pRecipient) && (lRecipientOpeningNumber > 0) && 
        pRecipient->VerifyIssuedNum(strServerID, lRecipientOpeningNumber)
        )
    {
        // The Nym (server side) stores a list of all opening and closing cron #s.
        // So when the number is released from the Nym, we also take it off that list.
        //
        std::set<int64_t> & theIDSet = pRecipient->GetSetOpenCronItems();
        theIDSet.erase(lRecipientOpeningNumber);
        
        // the RemoveIssued call means the original transaction# (to find this cron item on cron) is now CLOSED.
        // But the Transaction itself is still OPEN. How? Because the CLOSING number is still signed out.
        // The closing number is also USED, since the NotarizePaymentPlan or NotarizeMarketOffer call, but it
        // remains ISSUED, until the final receipt itself is accepted during a process inbox.
        //
        pRecipient->RemoveIssuedNum(*pServerNym, strServerID, lRecipientOpeningNumber, false); //bSave=false       
//      pRecipient->SaveSignedNymfile(*pServerNym); // Moved lower.
        // -----------------------------------------------------
        if (false == this->DropFinalReceiptToNymbox(GetRecipientUserID(),
                                                    lNewTransactionNumber,
                                                    strOrigCronItem,
                                                    NULL,
                                                    pstrAttachment,
                                                    pRecipient)) // NymboxHash is updated here in pRecipient.
        {
            OTLog::vError("%s: Failure dropping recipient final receipt into nymbox.\n", szFunc);
        }
        // -----------------------------------------------------

        // Saving both the Removed Issued Number, as well as the new NymboxHash.
        // NOTE: Todo: if the NymboxHash WAS updated (as it should have been) then
        // it was probably saved at that time. Below is therefore a redundant save.
        // Need to fix by making certain objects savable and dirty, and then let them
        // autosave before destruction, IF they are dirty.
        //
        pRecipient->SaveSignedNymfile(*pServerNym); 
    }
    else
    {
        OTLog::vError("%s: Failed verifying "
                      "lRecipientClosingNumber=this->GetRecipientClosingTransactionNoAt(1)>0 &&  "
                      "pRecipient->VerifyTransactionNum(lRecipientClosingNumber) && VerifyIssuedNum(lRecipientOpeningNumber)\n",
                      szFunc);
    }
    // -----------------------------------------------------------------
    //
    if ((NULL != pRecipient) && (lRecipientClosingNumber > 0) && 
        pRecipient->VerifyIssuedNum(strServerID, lRecipientClosingNumber)
        )
    {
        if (false == this->DropFinalReceiptToInbox(GetRecipientUserID(),
                                                   GetRecipientAcctID(),
                                                   lNewTransactionNumber,
                                                   lRecipientClosingNumber, // The closing transaction number to put on the receipt.
                                                   strOrigCronItem,
                                                   NULL,
                                                   pstrAttachment))
            OTLog::vError("%s: Failure dropping receipt into recipient's inbox.\n", szFunc);

        // This part below doesn't happen until pRecipient ACCEPTs the final receipt (when processing his inbox.)
        //
//      pRecipient->RemoveIssuedNum(strServerID, lRecipientClosingNumber, true); //bSave=false
    }
    else
    {
        OTLog::vError("%s: Failed verifying "
                      "lRecipientClosingNumber=this->GetRecipientClosingTransactionNoAt(1)>0 &&  "
                      "pRecipient->VerifyTransactionNum(lRecipientClosingNumber) && VerifyIssuedNum(lRecipientOpeningNumber)\n",
                      szFunc);
    }
    
    // QUESTION: Won't there be Cron Items that have no asset account at all?
    // In which case, there'd be no need to drop a final receipt, but I don't think
    // that's the case, since you have to use a transaction number to get onto cron
    // in the first place.
    // -----------------------------------------------------------------
}


/*
 inline const OTIdentifier &	GetRecipientAcctID() const { return m_RECIPIENT_ACCT_ID; }
 inline const OTIdentifier &	GetRecipientUserID() const { return m_RECIPIENT_USER_ID; }
 */

bool OTAgreement::IsValidOpeningNumber(const int64_t & lOpeningNum) const
{
	if (GetRecipientOpeningNum() == lOpeningNum)
		return true;
	
	return ot_super::IsValidOpeningNumber(lOpeningNum);
}


void OTAgreement::onRemovalFromCron()
{
    // Not much needed here.
    // Actually: Todo:  (unless it goes in payment plan code) need to set receipts
    // in inboxes, and close out the closing transaction numbers.
    //
    
}


// You usually wouldn't want to use this, since if the transaction failed, the opening number
// is already burned and gone. But there might be cases where it's not, and you want to retrieve it.
// So I added this function.
//
void OTAgreement::HarvestOpeningNumber(OTPseudonym & theNym)
{
    // since we overrode the parent, we give it a chance to harvest also.
    // IF theNym is the original sender, the opening number will be harvested
    // inside this call.
    //
    ot_super::HarvestOpeningNumber(theNym);

    // The Nym is the original recipient. (If Compares true).
    // IN CASES where GetTransactionNum() isn't already burned, we can harvest it here.
    //
    if (theNym.CompareID(GetRecipientUserID()))
    {
        // This function will only "add it back" if it was really there in the first place.
        // (Verifies it is on issued list first, before adding to available list.)
        //
        const bool bClawedBack =
            theNym.ClawbackTransactionNumber(GetServerID(), GetRecipientOpeningNum(), true); //bSave=true
        
        if (!bClawedBack)
        {
//          OTLog::vError("OTAgreement::HarvestOpeningNumber: Number (%lld) failed as issued. (Thus didn't bother 'adding it back'.)\n", GetRecipientOpeningNum());
        }
    }
    
    // NOTE: if the message failed (transaction never actually ran) then the sender AND recipient
    // can both reclaim their opening numbers. But if the message SUCCEEDED and the transaction FAILED,
    // then only the recipient can claim his opening number -- the sender's is already burned. So then,
    // what if you mistakenly call this function and pass the sender, when that number is already burned?
    // There's nothing this function can do, because we have no way of telling, from inside here,
    // whether the message succeeded or not, and whether the transaction succeeded or not. Therefore,
    // ==> we MUST rely on the CALLER to know this, and to avoid calling this function in the first place, 
    // if he's sitting on a sender with a failed transaction.
}


// Used for adding transaction numbers back to a Nym, after deciding not to use this agreement
// or failing in trying to use it. Client side.
//
void OTAgreement::HarvestClosingNumbers(OTPseudonym & theNym)
{
    // Since we overrode the parent, we give it a chance to harvest also.
    // If theNym is the sender, then his closing numbers will be harvested
    // inside here. But what if the transaction was a success? The numbers
    // will still be harvested, since they are still on the sender's issued
    // list, but they should not have been harvested, regardless, since the
    // transaction was a success and the server therefore has them marked as
    // "used." So clearly you cannot just blindly call this function unless
    // you know beforehand whether the message and transaction were a success.
    //
    ot_super::HarvestClosingNumbers(theNym);

    // The Nym is the original recipient. (If Compares true).
	// FYI, if Nym is the original sender, then the above call will handle him.
	//
    // GetTransactionNum() is burned, but we can harvest the closing
    // numbers from the "Closing" list, which is only for the sender's numbers.
    // Subclasses will have to override this function for recipients, etc.
    //
    if (theNym.CompareID(GetRecipientUserID()))
    {
//      OTLog::vOutput(0, "%s: Harvesting RECIPIENT...\n", __FUNCTION__);
        
        // This function will only "add it back" if it was really there in the first place.
        // (Verifies it is on issued list first, before adding to available list.)
        //
        const bool bClawedBack =
            theNym.ClawbackTransactionNumber(GetServerID(), GetRecipientClosingNum(), true); //bSave=true

        if (!bClawedBack)
        {
//          OTLog::vError("OTAgreement::HarvestClosingNumbers: Number (%lld) failed as issued. (Thus didn't bother 'adding it back'.)\n", GetRecipientClosingTransactionNoAt(i));
        }
    }
}


int64_t OTAgreement::GetOpeningNumber(const OTIdentifier & theNymID) const
{
	const OTIdentifier & theRecipientNymID = this->GetRecipientUserID();
	
	if (theNymID == theRecipientNymID)
		return GetRecipientOpeningNum();
	// else...
	return ot_super::GetOpeningNumber(theNymID);
}


int64_t OTAgreement::GetClosingNumber(const OTIdentifier & theAcctID) const
{
	const OTIdentifier & theRecipientAcctID = this->GetRecipientAcctID();
	
	if (theAcctID == theRecipientAcctID)
		return GetRecipientClosingNum();
	// else...
	return ot_super::GetClosingNumber(theAcctID);
}


int64_t OTAgreement::GetRecipientOpeningNum() const
{
    return (GetRecipientCountClosingNumbers() > 0) ? GetRecipientClosingTransactionNoAt(0) : 0; // todo stop hardcoding.
}


int64_t OTAgreement::GetRecipientClosingNum() const
{
    return (GetRecipientCountClosingNumbers() > 1) ? GetRecipientClosingTransactionNoAt(1) : 0; // todo stop hardcoding.
}


// ------------------------------------------------------------
// These are for finalReceipt
// The Cron Item stores a list of these closing transaction numbers,
// used for closing a transaction.
//

int64_t OTAgreement::GetRecipientClosingTransactionNoAt(uint32_t nIndex) const
{
    OT_ASSERT_MSG((nIndex < m_dequeRecipientClosingNumbers.size()) && (nIndex >= 0),
                  "OTAgreement::GetClosingTransactionNoAt: index out of bounds.");
    
    return m_dequeRecipientClosingNumbers.at(nIndex);
}


int32_t OTAgreement::GetRecipientCountClosingNumbers() const
{
	return static_cast<int32_t> (m_dequeRecipientClosingNumbers.size());
}


void OTAgreement::AddRecipientClosingTransactionNo(const int64_t & lClosingTransactionNo)
{
    m_dequeRecipientClosingNumbers.push_back(lClosingTransactionNo);
}


// OTCron calls this regularly, which is my chance to expire, etc.
// Child classes will override this, AND call it (to verify valid date range.)
bool OTAgreement::ProcessCron()
{
	// END DATE --------------------------------
	// First call the parent's version (which this overrides) so it has
	// a chance to check its stuff. Currently it checks IsExpired().
	if (!ot_super::ProcessCron())
		return false;	// It's expired or flagged--removed it from Cron.
	
	
	// START DATE --------------------------------
	// Okay, so it's NOT expired. But might not have reached START DATE yet...
	// (If not expired, yet current date is not verified, that means it hasn't
	// ENTERED the date range YET.)
	//
	if (!VerifyCurrentDate())
		return true;	// The Trade is not yet valid, so we return. BUT, we return 
						//  true, so it will stay on Cron until it BECOMES valid.
	
	
	// Process my Agreement-specific stuff below.--------------------------------
	
	
	return true;
}


/// See if theNym has rights to remove this item from Cron.
///
bool OTAgreement::CanRemoveItemFromCron(OTPseudonym & theNym)
{
    // You don't just go willy-nilly and remove a cron item from a market unless you check first
    // and make sure the Nym who requested it actually has said number (or a related closing number)
    // signed out to him on his last receipt...
    //
    if (true == ot_super::CanRemoveItemFromCron(theNym))
        return true;
    
    const OTString strServerID(GetServerID());

    // Usually the Nym is the originator. (Meaning GetTransactionNum() on this agreement
    // is still verifiable as an issued number on theNum, and belongs to him.) In that case,
    // the above call will discover this, and return true.
    // In other cases, theNym has the right to Remove the item even though theNym didn't originate it.
    // (Like if he is the recipient -- not the sender -- in a payment plan.) We check such things
    // HERE in this function (see below.)
    //
    if (false == theNym.CompareID(GetRecipientUserID()))
    {
        OTLog::vOutput(0, "OTAgreement::%s Weird: Nym tried to remove agreement (payment plan), even "
                      "though he apparently wasn't the sender OR recipient.\n", __FUNCTION__);
        return false;
    }
    
    else if (this->GetRecipientCountClosingNumbers() < 2)
    {
        OTLog::vOutput(0, "OTAgreement::%s: Weird: Recipient tried to remove agreement "
                       "(or payment plan); expected 2 closing numbers to be available--that weren't. (Found %d).\n",
                       __FUNCTION__, this->GetRecipientCountClosingNumbers());
        return false;
    }
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetRecipientClosingNum()))
    {
        OTLog::vOutput(0, "OTAgreement::%s: Recipient Closing number didn't verify (for removal from cron).\n",
                       __FUNCTION__);
        return false;
    }
    
    // By this point, we KNOW theNym is the sender, and we KNOW there are the proper number of transaction
    // numbers available to close. We also know that this cron item really was on the cron object, since
    // that is where it was looked up from, when this function got called! So I'm pretty sure, at this point,
    // to authorize removal, as long as the transaction num is still issued to theNym (this check here.)
    //
    return theNym.VerifyIssuedNum(strServerID, this->GetRecipientOpeningNum());
    
    // Normally this will be all we need to check. The originator will have the transaction
    // number signed-out to him still, if he is trying to close it. BUT--in some cases, someone
    // who is NOT the originator can cancel. Like in a payment plan, the sender is also the depositor,
    // who would normally be the person cancelling the plan. But technically, the RECIPIENT should
    // also have the ability to cancel that payment plan.  BUT: the transaction number isn't signed
    // out to the RECIPIENT... In THAT case, the below VerifyIssuedNum() won't work! In those cases,
    // expect that the special code will be in the subclasses override of this function. (OTPaymentPlan::CanRemoveItem() etc)
    
    // P.S. If you override this function, MAKE SURE to call the parent (OTCronItem::CanRemoveItem) first, 
    // for the VerifyIssuedNum call above. Only if that fails, do you need to dig deeper...

}


bool OTAgreement::CompareAgreement(const OTAgreement & rhs) const
{
    // Compare OTAgreement specific info here.
    
    if ( 
        (   m_strConsideration.Compare(rhs.m_strConsideration) ) &&
        (   GetRecipientAcctID() == rhs.GetRecipientAcctID()   ) &&
        (   GetRecipientUserID() == rhs.GetRecipientUserID()   ) &&
//        (   m_dequeClosingNumbers == rhs.m_dequeClosingNumbers ) && // The merchant wouldn't know the customer's trans#s.
                                                                      // (Thus wouldn't expect them to be set in BOTH versions...)
        (   m_dequeRecipientClosingNumbers == rhs.m_dequeRecipientClosingNumbers   ) &&
//      (   GetTransactionNum()  == rhs.GetTransactionNum()   ) && // (commented out for same reason as above.)
//      (   GetSenderAcctID()    == rhs.GetSenderAcctID()     ) && // Same here -- we should let the merchant leave these blank,
//      (   GetSenderUserID()    == rhs.GetSenderUserID()     ) && // and then allow the customer to add them in his version, 
        (   GetAssetID()         == rhs.GetAssetID()          ) && // (and this Compare function still still verify it.)
        (   GetServerID()        == rhs.GetServerID()         ) &&
        (   GetValidFrom()       == rhs.GetValidFrom()        ) &&
        (   GetValidTo()         == rhs.GetValidTo()          )
       )
        return true;
    
    return false;
}


// THIS FUNCTION IS CALLED BY THE MERCHANT
//
// (lMerchantTransactionNumber, lMerchantClosingNumber are set internally in this call, from MERCHANT_NYM.)
bool OTAgreement::SetProposal(OTPseudonym & MERCHANT_NYM,    const OTString & strConsideration,
                              const time64_t VALID_FROM/*=0*/, const time64_t VALID_TO/*=0*/) //VALID_TO is a length here. (i.e. it's ADDED to valid_from)
{
    // ----------------------------------------------------------------------------
    OTIdentifier id_MERCHANT_NYM;
    MERCHANT_NYM.GetIdentifier(id_MERCHANT_NYM);
    
    if (GetRecipientUserID() != id_MERCHANT_NYM)
    {
        OTLog::vOutput(0, "%s: Merchant has wrong NymID (should be same as RecipientUserID.)\n",
                       __FUNCTION__);
        return false;        
    }
    else if (GetRecipientUserID() == GetSenderUserID())
    {
        OTLog::vOutput(0, "%s: Error: Sender and recipient have the same Nym ID (not allowed.)\n",
                       __FUNCTION__);
        return false;        
    }
    else if (MERCHANT_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::vOutput(0, "%s: Failure. You need at least 2 transaction numbers available to do this.\n",
                       __FUNCTION__);
		return false;
    }
    // ------------------------------------------- 
	// Set the CREATION DATE
    //
	const time64_t CURRENT_TIME = OTTimeGetCurrentTime();
	
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);
    // -----------------------------------------
    // Putting this above here so I don't have to put the transaction numbers back if this fails:
    // ------------------------------------------- 
    // VALID_FROM
    //
	// The default "valid from" time is NOW.
    if (OT_TIME_ZERO >= VALID_FROM) // if it's 0 or less, set to current time.
		SetValidFrom(CURRENT_TIME);
	else // Otherwise use whatever was passed in.
		SetValidFrom(VALID_FROM);
    // ------------------------------------------- 
    // VALID_TO
    //
	// The default "valid to" time is 0 (which means no expiration date / cancel anytime.)
    if (OT_TIME_ZERO == VALID_TO) // VALID_TO is 0
	{
		SetValidTo(VALID_TO); // Keep it at zero then, so it won't expire.
	}
    else if (OT_TIME_ZERO < VALID_TO) // VALID_TO is ABOVE zero...
	{
		SetValidTo(OTTimeAddTimeInterval(GetValidFrom(), OTTimeGetSecondsFromTime(VALID_TO))); // Set it to itself + valid_from.
	}
	else // VALID_TO is a NEGATIVE number... Error.
	{
        int64_t lValidTo = OTTimeGetSecondsFromTime(VALID_TO);
		OTLog::vError("%s: Negative value for valid_to: %lld\n", __FUNCTION__, lValidTo);
        
		return false;
	}
    // ----------------------------------------------------------------------------
    // Since we'll be needing 2 transaction numbers to do this, let's grab 'em...
    //
    OTString strServerID(GetServerID());
    
	int64_t lTransactionNumber=0, lClosingTransactionNo=0;
	
    if (MERCHANT_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::vOutput(0, "%s: Failure. You need at least 2 transaction numbers available to do this.\n",
                       __FUNCTION__);
		return false;
    }
	else if (false == MERCHANT_NYM.GetNextTransactionNum(MERCHANT_NYM, strServerID, lTransactionNumber))
	{
		OTLog::vError("%s: Error: Strangely unable to get a transaction number.\n",
                      __FUNCTION__);
		return false;
	}
	else if (false == MERCHANT_NYM.GetNextTransactionNum(MERCHANT_NYM, strServerID, lClosingTransactionNo))
	{
 		OTLog::vError("%s: Error: Strangely unable to get a closing transaction number.\n",
                      __FUNCTION__);
        MERCHANT_NYM.AddTransactionNum(MERCHANT_NYM, strServerID, lTransactionNumber, true); // bSave=true
        // (Since the first one was successful, we just put it back before returning.)
		return false;
	}

    // At this point we now have 2 transaction numbers...
    // We can't return without either USING THEM, or PUTTING THEM BACK.
    //
    // ---------------------------------------------------------
	// Set the Transaction Number and the Closing transaction number... (for merchant / recipient.)
    //
    this->AddRecipientClosingTransactionNo(lTransactionNumber);
    this->AddRecipientClosingTransactionNo(lClosingTransactionNo);
    // (They just both go onto this same list.)
	// -------------------------------------------
	// Set the Consideration memo...
	m_strConsideration.Set(strConsideration);
	// -------------------------------------------
	OTLog::Output(4, "Successfully performed SetProposal.\n");	
	return true;
}


// THIS FUNCTION IS CALLED BY THE CUSTOMER
//
// (Transaction number and closing number are retrieved from Nym at this time.)
bool OTAgreement::Confirm(OTPseudonym & PAYER_NYM, OTPseudonym * pMERCHANT_NYM/*=NULL*/, const OTIdentifier * p_id_MERCHANT_NYM/*=NULL*/)
{
    // ----------------------------------------------------------------------------
    OTIdentifier id_PAYER_NYM;
    PAYER_NYM.GetIdentifier(id_PAYER_NYM);
    
    if (GetRecipientUserID() == GetSenderUserID())
    {
        OTLog::vOutput(0, "%s: Error: Sender and recipient have the same Nym ID (not allowed.)\n", __FUNCTION__);
        return false;        
    }
    else if ((NULL != p_id_MERCHANT_NYM) && (this->GetRecipientUserID() != *p_id_MERCHANT_NYM))
    {
        OTLog::vOutput(0, "%s: Merchant has wrong NymID (should be same as RecipientUserID.)\n", __FUNCTION__);
        return false;
    }
    else if ((NULL != pMERCHANT_NYM) && (this->GetRecipientUserID() != pMERCHANT_NYM->GetConstID()))
    {
        OTLog::vOutput(0, "%s: Merchant has wrong NymID (should be same as RecipientUserID.)\n", __FUNCTION__);
        return false;
    }
    else if (GetSenderUserID() != id_PAYER_NYM)
    {
        OTLog::vOutput(0, "%s: Payer has wrong NymID (should be same as SenderUserID.)\n", __FUNCTION__);
        return false;        
    }
    else if (PAYER_NYM.GetTransactionNumCount(GetServerID()) < 2) // Need opening and closing numbers (that's 2)... 
    {
        OTLog::vOutput(0, "%s: Failure. You need at least 2 transaction numbers available to do this.\n", __FUNCTION__);
		return false;
    }
    else if (GetRecipientCountClosingNumbers() < 2)
    {
        OTLog::vOutput(0, "%s: Failure. (The merchant was supposed to attach 2 transaction numbers.)\n", __FUNCTION__);
		return false;
    }
    // ----------------------------------------------------------------------------
    // This is the single reason why MERCHANT_NYM was even passed in here!
    // Supposedly merchant has already signed.  Let's verify this!!
    //
    if ((NULL != pMERCHANT_NYM) && (false == this->VerifySignature(*pMERCHANT_NYM)))
    {
        OTLog::vOutput(0, "%s: Merchant's signature failed to verify.\n", __FUNCTION__);
        return false;
    }
    // ----------------------------------------------------------------------------
    
    // Now that we KNOW the merchant signed it... SAVE MERCHANT's COPY.
    // Let's save a copy of the one the merchant signed, before changing it and re-signing it,
    // (to add my own transaction numbers...)
    //
    OTString strTemp;
    this->SaveContractRaw(strTemp);
    this->SetMerchantSignedCopy(strTemp);

    // *******************************************************************
    
    // The payer has to submit TWO transaction numbers in order to activate this agreement...
    //
    OTString strServerID(GetServerID());
	int64_t lTransactionNumber=0, lClosingTransactionNo=0;
	
	if (false == PAYER_NYM.GetNextTransactionNum(PAYER_NYM, strServerID, lTransactionNumber))
	{
		OTLog::vError("%s: Error: Strangely unable to get a transaction number.\n", __FUNCTION__);
		return false;
	}
	else if (false == PAYER_NYM.GetNextTransactionNum(PAYER_NYM, strServerID, lClosingTransactionNo))
	{
 		OTLog::vError("%s: Error: Strangely unable to get a closing transaction number.\n", __FUNCTION__);
        PAYER_NYM.AddTransactionNum(PAYER_NYM, strServerID, lTransactionNumber, true); // bSave=true
        // (Since the first one was successful, we just put it back before returning.)
		return false;
	}
    
    // At this point we now HAVE 2 transaction numbers (for payer / sender)...
    // We can't return without USING THEM or PUTTING THEM BACK.
    //
    // ---------------------------------------------------------
	this->SetTransactionNum(lTransactionNumber); // Set the Transaction Number
    this->AddClosingTransactionNo(lClosingTransactionNo); // and the Closing Number (both for sender)...
	// ------------------------------------------- 
    // CREATION DATE was set in the Merchant's proposal, and it's RESET here in the Confirm.
    // This way, (since we still have the original proposal) we can see BOTH times.
    //
	time64_t CURRENT_TIME = OTTimeGetCurrentTime();
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);
	// -------------------------------------------
	OTLog::vOutput(4, "%s(): Success!\n", __FUNCTION__);
    
	return true;
}


// (Make sure to set Creation date here.)
// THIS FUNCTION IS DEPRECATED
//
/*
bool OTAgreement::SetAgreement(const int64_t & lTransactionNum,	const OTString & strConsideration,
							   const time64_t & VALID_FROM=0,	const time64_t & VALID_TO=0)
{
	// Set the Transaction Number...
	SetTransactionNum(lTransactionNum);

	// Set the Consideration memo...
	m_strConsideration.Set(strConsideration);

	// ------------------------------------------- 
	
	time64_t CURRENT_TIME = OTTimeGetCurrentTime();
	
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);

	// ------------------------------------------- 

	// The default "valid from" time is NOW.
	if (0 >= VALID_FROM) // if it's 0 or less, set to current time.
		SetValidFrom(CURRENT_TIME);
	else // Otherwise use whatever was passed in.
		SetValidFrom(VALID_FROM);

	// ------------------------------------------- 

	// The default "valid to" time is 0 (which means no expiration date / cancel anytime.)
	if (0 == VALID_TO) // VALID_TO is 0
	{
		SetValidTo(VALID_TO); // Keep it at zero then, so it won't expire.
	}
	else if (0 < VALID_TO) // VALID_TO is ABOVE zero...
	{
		if (VALID_TO < VALID_FROM) // If Valid-To date is EARLIER than Valid-From date...
		{
			int64_t lValidTo = VALID_TO, lValidFrom = VALID_FROM;
			OTLog::vError("VALID_TO is earlier than VALID_FROM in SetAgreement: %lld, %lld\n", lValidTo, lValidFrom);
			return false;
		}
		
		SetValidTo(VALID_TO); // Set it to whatever it is, since it is now validated as higher than Valid-From.
	}
	else // VALID_TO is a NEGATIVE number... Error.
	{
		int64_t lValidTo = VALID_TO;
		OTLog::vError("Negative value for valid_to in SetAgreement: %lld\n", lValidTo);
		return false;
	}

	// ------------------------------------------- 
	
	OTLog::Output(4, "Successfully performed SetAgreement()\n");
	
	return true;
}
*/


OTAgreement::OTAgreement() : ot_super()
{
	InitAgreement();
}


OTAgreement::OTAgreement(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) :
			ot_super(SERVER_ID, ASSET_ID)
{
	InitAgreement();
}


OTAgreement::OTAgreement(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
						 const OTIdentifier & SENDER_ACCT_ID,		const OTIdentifier & SENDER_USER_ID,
						 const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID) :
			ot_super(SERVER_ID, ASSET_ID, SENDER_ACCT_ID, SENDER_USER_ID)
{
	InitAgreement();
	
	SetRecipientAcctID(RECIPIENT_ACCT_ID);
	SetRecipientUserID(RECIPIENT_USER_ID);
}


OTAgreement::~OTAgreement()
{
	Release_Agreement();
}


void OTAgreement::InitAgreement()
{
	m_strContractType = "AGREEMENT";
	
}


void OTAgreement::Release_Agreement()
{
    // If there were any dynamically allocated objects, clean them up here.
    //
	m_RECIPIENT_ACCT_ID.Release();	
	m_RECIPIENT_USER_ID.Release();
	
	m_strConsideration.Release();
	m_strMerchantSignedCopy.Release();
	
    m_dequeRecipientClosingNumbers.clear();
}


// the framework will call this at the right time.
//
void OTAgreement::Release()
{
    Release_Agreement();
    
    // -----------------------
    
	ot_super::Release(); // since I've overridden the base class (OTCronItem), so I call it now...
	
    // -----------------------

	// Then I call this to re-initialize everything
	InitAgreement();
}


void OTAgreement::UpdateContents()
{
    // See OTPaymentPlan::UpdateContents.
}


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int32_t OTAgreement::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
    int32_t nReturnVal = 0;
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do below, in the case of OTAccount.
	if (0 != (nReturnVal = ot_super::ProcessXMLNode(xml)))
		return nReturnVal;

    // -------------------------------------------------
    
    if (!strcmp("agreement", xml->getNodeName())) 
	{		
		m_strVersion		   = xml->getAttributeValue("version");
		SetTransactionNum(	atol(xml->getAttributeValue("transactionNum")) );
        // -------------------------------------------------------------------
        const OTString strCreation = xml->getAttributeValue("creationDate");
        int64_t tCreation = strCreation.ToLong();
        
        SetCreationDate(OTTimeGetTimeFromSeconds(tCreation));
        // -------------------------------------------------------------------
        const OTString str_valid_from = xml->getAttributeValue("validFrom");
        const OTString str_valid_to   = xml->getAttributeValue("validTo");
        
        int64_t tValidFrom = str_valid_from.ToLong();
        int64_t tValidTo   = str_valid_to.ToLong();
        
        SetValidFrom(OTTimeGetTimeFromSeconds(tValidFrom));
        SetValidTo(OTTimeGetTimeFromSeconds(tValidTo));
		// ---------------------
		const OTString	strServerID       (xml->getAttributeValue("serverID")),
                        strAssetTypeID    (xml->getAttributeValue("assetTypeID")),
                        strSenderAcctID   (xml->getAttributeValue("senderAcctID")),
                        strSenderUserID   (xml->getAttributeValue("senderUserID")),
                        strRecipientAcctID(xml->getAttributeValue("recipientAcctID")),
                        strRecipientUserID(xml->getAttributeValue("recipientUserID")),
                        strCanceled       (xml->getAttributeValue("canceled")),
                        strCancelerUserID (xml->getAttributeValue("cancelerUserID"));
        // ----------------------
        if (strCanceled.Exists() && strCanceled.Compare("true"))
        {
            m_bCanceled = true;
            
            if (strCancelerUserID.Exists())
                m_pCancelerNymID->SetString(strCancelerUserID);
            // else log
        }
        else
        {
            m_bCanceled = false;
            m_pCancelerNymID->Release();
        }
        // ----------------------
		const OTIdentifier	SERVER_ID(strServerID),					ASSET_ID(strAssetTypeID),
                            SENDER_ACCT_ID(strSenderAcctID),		SENDER_USER_ID(strSenderUserID),
                            RECIPIENT_ACCT_ID(strRecipientAcctID),	RECIPIENT_USER_ID(strRecipientUserID);
		
		SetServerID(SERVER_ID);
		SetAssetID(ASSET_ID);
		SetSenderAcctID(SENDER_ACCT_ID);
		SetSenderUserID(SENDER_USER_ID);
		SetRecipientAcctID(RECIPIENT_ACCT_ID);
		SetRecipientUserID(RECIPIENT_USER_ID);
		// ---------------------
		OTLog::vOutput(1, "\n\n%sgreement. Transaction Number: %lld\n",
                       m_bCanceled ? "Canceled a" : "A", m_lTransactionNum);
		
		OTLog::vOutput(2,
					   " Creation Date: %" PRId64"   Valid From: %" PRId64"\n Valid To: %" PRId64"\n"
					   " AssetTypeID: %s\n ServerID: %s\n"
					   " senderAcctID: %s\n senderUserID: %s\n "
					   " recipientAcctID: %s\n recipientUserID: %s\n ", 
					   tCreation, tValidFrom, tValidTo,
					   strAssetTypeID.Get(), strServerID.Get(),
					   strSenderAcctID.Get(), strSenderUserID.Get(), 
					   strRecipientAcctID.Get(), strRecipientUserID.Get());
		
		nReturnVal = 1;
	}
    
	else if (!strcmp("consideration", xml->getNodeName())) 
	{		
		if (false == OTContract::LoadEncodedTextField(xml, m_strConsideration))
		{
			OTLog::Error("Error in OTPaymentPlan::ProcessXMLNode: consideration field without value.\n");
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}
    
	else if (!strcmp("merchantSignedCopy", xml->getNodeName())) 
	{		
		if (false == OTContract::LoadEncodedTextField(xml, m_strMerchantSignedCopy))
		{
			OTLog::Error("Error in OTPaymentPlan::ProcessXMLNode: merchant_signed_copy field without value.\n");
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}

    // -------------------------------------------
//  std::deque<int64_t>   m_dequeRecipientClosingNumbers; // Numbers used for CLOSING a transaction. (finalReceipt.)

    else if (!strcmp("closingRecipientNumber", xml->getNodeName())) 
	{		
        OTString strClosingNumber = xml->getAttributeValue("value");
        
        if (strClosingNumber.Exists())
        {
            const int64_t lClosingNumber = atol(strClosingNumber.Get());					

            this->AddRecipientClosingTransactionNo(lClosingNumber);
        }
        else
		{
			OTLog::Error("Error in OTAgreement::ProcessXMLNode: closingRecipientNumber field without value.\n");
			return (-1); // error condition
		}
        
		nReturnVal = 1;
	}

	return nReturnVal;
}


bool OTAgreement::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}

} // namespace opentxs
