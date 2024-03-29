/************************************************************

OT_ME.cpp   -- "OT Made Easy"

This adds functionality to OTAPI.h

This could be wrapped by OTAPI_Basic, just as OTAPI was.

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

#include "ot_me_switch.hpp"

#include "OT_ME.hpp"

#include "OTAPI.hpp"
#include "OTDataFolder.hpp"
#include "OTLog.hpp"
#include "OTMeCpp.hpp"
#include "OTPaths.hpp"
#include "OTStorage.hpp"
#include "OTVariable.hpp"

#ifdef OT_USE_SCRIPT_CHAI
#include "OTMeChai.hpp"
#  include "OTScriptChai.hpp"
#  include <chaiscript/chaiscript.hpp>
#  ifdef OT_USE_CHAI_STDLIB
#  include <chaiscript/chaiscript_stdlib.hpp>
#  endif
#endif

namespace opentxs {

OT_ME * OT_ME::s_pMe = NULL;


OT_ME::OT_ME() : r_pPrev(NULL)
{
    r_pPrev = s_pMe;
    s_pMe = this;

#if USE_OLD_CHAISCRIPT == 1
    m_pImplementation = new OTMeChai(this);
#else
    m_pImplementation = new OTMeCpp;
#endif
}


OT_ME::~OT_ME()
{
    s_pMe = r_pPrev;
}


typedef std::map<std::string, std::string>  mapOfArguments;

//int32_t    OT_CLI_GetArgsCount     (const std::string str_Args);
//std::string OT_CLI_GetValueByKey    (const std::string str_Args, const std::string str_key);
//std::string OT_CLI_GetValueByIndex  (const std::string str_Args, const int32_t nIndex);
//std::string OT_CLI_GetKeyByIndex    (const std::string str_Args, const int32_t nIndex);

// If user-defined script arguments were passed,
// using:  --Args "key value key value key value"
// then this function returns the count of key/value
// pairs available. (In that example, the return
// value would be 3.)
//
int32_t OT_CLI_GetArgsCount(const std::string str_Args)
{
    const OTString strArgs(str_Args);
    int32_t nRetVal = 0;
    mapOfArguments map_values;
    const bool bTokenized = strArgs.TokenizeIntoKeyValuePairs(map_values);
    if (bTokenized)
        nRetVal = static_cast<int32_t> (map_values.size());
    return nRetVal;
}



// If user-defined script arguments were passed,
// using:  --Args "key value key value key value"
// then this function can retrieve any value (by key.)
//
std::string OT_CLI_GetValueByKey(const std::string str_Args, const std::string str_key)
{
    const OTString strArgs(str_Args);
    std::string str_retval = "";
    mapOfArguments map_values;
    const bool bTokenized = strArgs.TokenizeIntoKeyValuePairs(map_values);
    if (bTokenized && (map_values.size() > 0))
    {
        // Okay we now have key/value pairs -- let's look it up!
        mapOfArguments::iterator it = map_values.find(str_key);

        if (map_values.end() != it) // found it
            str_retval = (*it).second;
    }
    return str_retval;
}


// If user-defined script arguments were passed,
// using:  --Args "key value key value key value"
// then this function can retrieve any value (by index.)
//
std::string OT_CLI_GetValueByIndex(const std::string str_Args, const int32_t nIndex)
{
    const OTString strArgs(str_Args);
    std::string str_retval = "";
    mapOfArguments map_values;
    const bool bTokenized = strArgs.TokenizeIntoKeyValuePairs(map_values);
    if (bTokenized && (nIndex < static_cast<int32_t>(map_values.size())))
    {
        int32_t nMapIndex = (-1);
        FOR_EACH(mapOfArguments, map_values)
        {
            ++nMapIndex;
            //   const std::string str_key = (*it).first;
            //   const std::string str_val = (*it).second;
            // BY this point, nMapIndex contains the index we're at on map_values
            // (compare to nIndex.) And str_key and str_val contain the key/value
            // pair for THAT index.
            //
            if (nIndex == nMapIndex)
            {
                str_retval = (*it).second; // Found it!
                break;
            }
        }
    }
    return str_retval;
}



// If user-defined script arguments were passed,
// using:  --Args "key value key value key value"
// then this function can retrieve any key (by index.)
//
std::string OT_CLI_GetKeyByIndex(const std::string str_Args, const int32_t nIndex)
{
    const OTString strArgs(str_Args);
    std::string str_retval = "";
    mapOfArguments map_values;
    const bool bTokenized = strArgs.TokenizeIntoKeyValuePairs(map_values);
    if (bTokenized && (nIndex < static_cast<int32_t>(map_values.size())))
    {
        int32_t nMapIndex = (-1);
        FOR_EACH(mapOfArguments, map_values)
        {
            ++nMapIndex;
            //   const std::string str_key = (*it).first;
            //   const std::string str_val = (*it).second;
            // BY this point, nMapIndex contains the index we're at on map_values
            // (compare to nIndex.) And str_key and str_val contain the key/value
            // pair for THAT index.
            //
            if (nIndex == nMapIndex)
            {
                str_retval = (*it).first; // Found it!
                break;
            }
        }
    }
    return str_retval;
}




// Reads from cin until Newline.
//
std::string OT_CLI_ReadLine()
{
    std::string line;
    if (std::getline(std::cin, line))
    {
        return line;
    }

    return "";
}


// Reads from cin until EOF. (Or until the ~ character as the first character on a line.)
//
std::string OT_CLI_ReadUntilEOF()
{
    // don't skip the whitespace while reading
    // std::cin >> std::noskipws;

    // std::ostringstream oss;
    //
    // oss << std::cin;   // Convert value into a string.
    // s = outs.str();

    // use stream iterators to copy the stream to a string
    // std::istream_iterator<std::string> it(std::cin);
    // std::istream_iterator<std::string> end;
    // std::istream_iterator<char> it(std::cin);
    // std::istream_iterator<char> end;
    // std::string results(it, end);

    // int32_t onechar;

    std::string result("");

    for (;;)
    {
        std::string input_line("");

//      int32_t n;
////    std::string sn;
//      std::stringstream ssn;
//
//      std::getline(std::cin, input_line);
//      ssn << input_line;
//      ssn >> n;

//      std::getline(std::cin, input_line, '\n');
        if (std::getline(std::cin, input_line, '\n'))
        {
            input_line += "\n";

            if (input_line[0] == '~') // This is our special "break" character for multi-line input.
                break;

            result += input_line;
        }
        else
        {
            OTLog::Error("OT_CLI_ReadUntilEOF: getline() was unable to read a string from std::cin\n");
            break;
        }
        if (std::cin.eof())
        {
//          cout << "IT WAS EOF\n";
            std::cin.clear();
            break;
        }
        if (std::cin.fail())
        {
//          cout << "IT WAS FAIL\n";
            std::cin.clear();
            break;
        }
        if (std::cin.bad())
        {
//          cout << "IT WAS BAD\n";
            std::cin.clear();
            break;
        }
//      std::cin.clear();
//      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } // while


    return result;
}





// Note optimization:
// Until the actual C++ high-level API is written, we'll just use this
// as a C++ wrapper to the existing high-level API written in OT Script.
// Tha way, all the other languages can wrap this using swig.
//
// Notice (for those languages) that if you make an instance of OT_ME
// and keep it around (using it for all your server calls) notice that
// it will only have to instantiate and setup the OTScript object ONCE,
// instead of having to do it for every single call.
//
// Therefore, for optimization purposes, we recommend the programmatic
// user to keep an instance of OT_ME around as long as you need to use it,
// and NOT instantiate it for every time you need to use it, as it will
// probably run noticeably faster.
//


bool OT_ME::make_sure_enough_trans_nums(const int32_t nNumberNeeded,
    const std::string & SERVER_ID,
    const std::string & NYM_ID)
{
    return m_pImplementation->make_sure_enough_trans_nums(nNumberNeeded, SERVER_ID, NYM_ID);
}


// REGISTER NYM AT SERVER (or download nymfile, if nym already registered.)
//
std::string OT_ME::register_nym(const std::string & SERVER_ID,
    const std::string & NYM_ID)
{
    return m_pImplementation->register_nym(SERVER_ID, NYM_ID);
}


// CHECK USER (download a public key)
//
std::string OT_ME::check_user(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & TARGET_NYM_ID)
{
    return m_pImplementation->check_user(SERVER_ID, NYM_ID, TARGET_NYM_ID);
}


// CREATE NYM (pseudonym)
// returns new Nym ID
//
std::string OT_ME::create_pseudonym(const int32_t nKeybits,
    const std::string & NYM_ID_SOURCE,
    const std::string & ALT_LOCATION)
{
    return m_pImplementation->create_pseudonym(nKeybits, NYM_ID_SOURCE, ALT_LOCATION);
}


// ISSUE ASSET TYPE
//
std::string OT_ME::issue_asset_type(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & THE_CONTRACT)
{
    return m_pImplementation->issue_asset_type(SERVER_ID, NYM_ID, THE_CONTRACT);
}


// ISSUE BASKET CURRENCY
//
std::string OT_ME::issue_basket_currency(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & THE_BASKET)
{
    return m_pImplementation->issue_basket_currency(SERVER_ID, NYM_ID, THE_BASKET);
}


// EXCHANGE BASKET CURRENCY
//
std::string OT_ME::exchange_basket_currency(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ASSET_TYPE_ID,
    const std::string & THE_BASKET,
    const std::string & ACCOUNT_ID,
    const bool IN_OR_OUT)
{
    return m_pImplementation->exchange_basket_currency(SERVER_ID, NYM_ID, ASSET_TYPE_ID, THE_BASKET, ACCOUNT_ID, IN_OR_OUT);
}


// RETRIEVE CONTRACT
//
std::string OT_ME::retrieve_contract(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & CONTRACT_ID)
{
    return m_pImplementation->retrieve_contract(SERVER_ID, NYM_ID, CONTRACT_ID);
}


// LOAD OR RETRIEVE CONTRACT
//
std::string OT_ME::load_or_retrieve_contract(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & CONTRACT_ID)
{
    return m_pImplementation->load_or_retrieve_contract(SERVER_ID, NYM_ID, CONTRACT_ID);
}


// CREATE ASSET ACCOUNT
//
std::string OT_ME::create_asset_acct(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ASSET_TYPE_ID)
{
    return m_pImplementation->create_asset_acct(SERVER_ID, NYM_ID, ASSET_TYPE_ID);
}


std::string OT_ME::stat_asset_account(const std::string & ACCOUNT_ID)
{
    return m_pImplementation->stat_asset_account(ACCOUNT_ID);
}


// DOWNLOAD ACCOUNT FILES (account balance, inbox, outbox, etc)
//
bool OT_ME::retrieve_account(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCOUNT_ID,
    const bool bForceDownload)
{
    return m_pImplementation->retrieve_account(SERVER_ID, NYM_ID, ACCOUNT_ID, bForceDownload);
}


bool OT_ME::retrieve_nym(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const bool bForceDownload)
{
    return m_pImplementation->retrieve_nym(SERVER_ID, NYM_ID, bForceDownload);
}


// SEND TRANSFER -- TRANSACTION
//
std::string OT_ME::send_transfer(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCT_FROM,
    const std::string & ACCT_TO,
    const int64_t AMOUNT,
    const std::string & NOTE)
{
    return m_pImplementation->send_transfer(SERVER_ID, NYM_ID, ACCT_FROM, ACCT_TO, AMOUNT, NOTE);
}


// PROCESS INBOX -- TRANSACTION
//
std::string OT_ME::process_inbox(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCOUNT_ID,
    const std::string & RESPONSE_LEDGER)
{
    return m_pImplementation->process_inbox(SERVER_ID, NYM_ID, ACCOUNT_ID, RESPONSE_LEDGER);
}


bool OT_ME::accept_inbox_items(const std::string & ACCOUNT_ID,
    int32_t nItemType,
    const std::string & INDICES)
{
    return m_pImplementation->accept_inbox_items(ACCOUNT_ID,
        nItemType, INDICES);
}


bool OT_ME::discard_incoming_payments(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & INDICES)
{
    return m_pImplementation->discard_incoming_payments(SERVER_ID, NYM_ID, INDICES);
}


bool OT_ME::cancel_outgoing_payments(const std::string & NYM_ID,
    const std::string & ACCOUNT_ID,
    const std::string & INDICES)
{
    return m_pImplementation->cancel_outgoing_payments(NYM_ID, ACCOUNT_ID, INDICES);
}


int32_t OT_ME::accept_from_paymentbox(const std::string & ACCOUNT_ID,
    const std::string & INDICES,
    const std::string & PAYMENT_TYPE)
{
    return m_pImplementation->accept_from_paymentbox(ACCOUNT_ID, INDICES, PAYMENT_TYPE);
}


// load_public_key():
//
// Load a public key from local storage, and return it (or null).
//
std::string OT_ME::load_public_encryption_key(const std::string & NYM_ID)
{
    return m_pImplementation->load_public_encryption_key(NYM_ID);
}


std::string OT_ME::load_public_signing_key(const std::string & NYM_ID)
{
    return m_pImplementation->load_public_signing_key(NYM_ID);
}


//
// load_or_retrieve_pubkey()
//
// Load TARGET_NYM_ID from local storage.
// If not there, then retrieve TARGET_NYM_ID from server,
// using NYM_ID to send check_user request. Then re-load
// and return. (Might still return null.)
//
std::string OT_ME::load_or_retrieve_encrypt_key(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & TARGET_NYM_ID)
{
    return m_pImplementation->load_or_retrieve_encrypt_key(SERVER_ID, NYM_ID, TARGET_NYM_ID);
}


std::string OT_ME::load_or_retrieve_signing_key(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & TARGET_NYM_ID)
{
    return m_pImplementation->load_or_retrieve_signing_key(SERVER_ID, NYM_ID, TARGET_NYM_ID);
}


// SEND USER MESSAGE (requires recipient public key)
//
std::string OT_ME::send_user_msg_pubkey(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & RECIPIENT_NYM_ID,
    const std::string & RECIPIENT_PUBKEY,
    const std::string & THE_MESSAGE)
{
    return m_pImplementation->send_user_msg_pubkey(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, RECIPIENT_PUBKEY, THE_MESSAGE);
}


// SEND USER INSTRUMENT (requires recipient public key)
//
std::string OT_ME::send_user_pmnt_pubkey(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & RECIPIENT_NYM_ID,
    const std::string & RECIPIENT_PUBKEY,
    const std::string & THE_INSTRUMENT)
{
    return m_pImplementation->send_user_pmnt_pubkey(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, RECIPIENT_PUBKEY, THE_INSTRUMENT);
}


// SEND USER CASH (requires recipient public key)
//
std::string OT_ME::send_user_cash_pubkey(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & RECIPIENT_NYM_ID,
    const std::string & RECIPIENT_PUBKEY,
    const std::string & THE_INSTRUMENT,
    const std::string & INSTRUMENT_FOR_SENDER)
{
    return m_pImplementation->send_user_cash_pubkey(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, RECIPIENT_PUBKEY, THE_INSTRUMENT, INSTRUMENT_FOR_SENDER);
}


// SEND USER MESSAGE (only requires recipient's ID, and retrieves pubkey automatically)
//
std::string OT_ME::send_user_msg(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & RECIPIENT_NYM_ID,
    const std::string & THE_MESSAGE)
{
    return m_pImplementation->send_user_msg(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, THE_MESSAGE);
}


// SEND USER PAYMENT (only requires recipient's ID, and retrieves pubkey automatically)
//
std::string OT_ME::send_user_payment(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & RECIPIENT_NYM_ID,
    const std::string & THE_PAYMENT)
{
    return m_pImplementation->send_user_payment(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, THE_PAYMENT);
}


// SEND USER CASH (only requires recipient's ID, and retrieves pubkey automatically)
//
std::string OT_ME::send_user_cash(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & RECIPIENT_NYM_ID,
    const std::string & THE_PAYMENT,
    const std::string & SENDERS_COPY)
{
    return m_pImplementation->send_user_cash(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, THE_PAYMENT, SENDERS_COPY);
}


bool OT_ME::withdraw_and_send_cash(const std::string & ACCT_ID,
    const std::string & RECIPIENT_NYM_ID,
    const std::string & MEMO,
    const int64_t AMOUNT)
{
    return m_pImplementation->withdraw_and_send_cash(ACCT_ID, RECIPIENT_NYM_ID, MEMO, AMOUNT);
}


// GET PAYMENT INSTRUMENT (from payments inbox, by index.)
//
std::string OT_ME::get_payment_instrument(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const int32_t nIndex,
    const std::string & PRELOADED_INBOX)
{
    return m_pImplementation->get_payment_instrument(SERVER_ID, NYM_ID, nIndex, PRELOADED_INBOX);
}


// GET BOX RECEIPT
// Note: nBoxType is 0 for Nymbox, 1 for Inbox, and 2 for Outbox.
// Also, if nBoxType is 0 (nymbox) then you have to pass the NymID in the ACCT_ID
// argument, as well as the NYM_ID argument (you have to pass it twice...)
// Otherwise for inbox/outbox, pass the actual ACCT_ID there as normal.
//
std::string OT_ME::get_box_receipt(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCT_ID,
    const int32_t nBoxType,
    const int64_t TRANS_NUM)
{
    return m_pImplementation->get_box_receipt(SERVER_ID, NYM_ID, ACCT_ID, nBoxType, TRANS_NUM);
}


// DOWNLOAD PUBLIC MINT
//
std::string OT_ME::retrieve_mint(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ASSET_ID)
{
    return m_pImplementation->retrieve_mint(SERVER_ID, NYM_ID, ASSET_ID);
}


// LOAD MINT (from local storage)
//
// To load a mint withOUT retrieving it from server, call:
//
// var strMint = OT_API_LoadMint(SERVER_ID, ASSET_ID);
// It returns the mint, or null.
// LOAD MINT (from local storage).
// Also, if necessary, RETRIEVE it from the server first.
//
// Returns the mint, or null.
//
std::string OT_ME::load_or_retrieve_mint(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ASSET_ID)
{
    return m_pImplementation->load_or_retrieve_mint(SERVER_ID, NYM_ID, ASSET_ID);
}


// QUERY ASSET TYPES
//
// See if some asset types are issued on the server.
//
std::string OT_ME::query_asset_types(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ENCODED_MAP)
{
    return m_pImplementation->query_asset_types(SERVER_ID, NYM_ID, ENCODED_MAP);
}


// CREATE MARKET OFFER -- TRANSACTION
//
std::string OT_ME::create_market_offer(const std::string & ASSET_ACCT_ID,
    const std::string & CURRENCY_ACCT_ID,
    const int64_t scale,
    const int64_t minIncrement,
    const int64_t quantity,
    const int64_t price,
    const bool bSelling,
    const int64_t lLifespanInSeconds,
    const std::string & STOP_SIGN,
    const int64_t ACTIVATION_PRICE)
{
    return m_pImplementation->create_market_offer(ASSET_ACCT_ID, CURRENCY_ACCT_ID, scale, minIncrement, quantity, price,
        bSelling, lLifespanInSeconds, STOP_SIGN, ACTIVATION_PRICE);
}


// KILL MARKET OFFER -- TRANSACTION
//
std::string OT_ME::kill_market_offer(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ASSET_ACCT_ID,
    const int64_t TRANS_NUM)
{
    return m_pImplementation->kill_market_offer(SERVER_ID, NYM_ID, ASSET_ACCT_ID, TRANS_NUM);
}


// KILL (ACTIVE) PAYMENT PLAN -- TRANSACTION
//
std::string OT_ME::kill_payment_plan(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCT_ID,
    const int64_t TRANS_NUM)
{
    return m_pImplementation->kill_payment_plan(SERVER_ID, NYM_ID, ACCT_ID, TRANS_NUM);
}


// CANCEL (NOT-YET-RUNNING) PAYMENT PLAN -- TRANSACTION
//
std::string OT_ME::cancel_payment_plan(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & THE_PAYMENT_PLAN)
{
    return m_pImplementation->cancel_payment_plan(SERVER_ID, NYM_ID, THE_PAYMENT_PLAN);
}


// ACTIVATE SMART CONTRACT -- TRANSACTION
//
std::string OT_ME::activate_smart_contract(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCT_ID,
    const std::string & AGENT_NAME,
    const std::string & THE_SMART_CONTRACT)
{
    return m_pImplementation->activate_smart_contract(SERVER_ID, NYM_ID, ACCT_ID, AGENT_NAME, THE_SMART_CONTRACT);
}


// TRIGGER CLAUSE (on running smart contract) -- TRANSACTION
//
std::string OT_ME::trigger_clause(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const int64_t TRANS_NUM,
    const std::string & CLAUSE_NAME,
    const std::string & STR_PARAM)
{
    return m_pImplementation->trigger_clause(SERVER_ID, NYM_ID, TRANS_NUM, CLAUSE_NAME, STR_PARAM);
}


// WITHDRAW CASH -- TRANSACTION
//
std::string OT_ME::withdraw_cash(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCT_ID,
    const int64_t AMOUNT)
{
    return m_pImplementation->withdraw_cash(SERVER_ID, NYM_ID, ACCT_ID, AMOUNT);
}


// Difference between this function and the one above?
// This one automatically retrieves the mint beforehand, if necessary,
// and the account files afterward, if appropriate.
//
int32_t OT_ME::easy_withdraw_cash(const std::string & ACCT_ID,
    const int64_t AMOUNT)
{
    return m_pImplementation->easy_withdraw_cash(ACCT_ID, AMOUNT);
}


// EXPORT CASH (FROM PURSE)
//
std::string OT_ME::export_cash(const std::string & SERVER_ID,
    const std::string & FROM_NYM_ID,
    const std::string & ASSET_TYPE_ID,
    const std::string & TO_NYM_ID,
    const std::string & STR_INDICES,
    bool bPasswordProtected,
    std::string & STR_RETAINED_COPY)
{
    return m_pImplementation->export_cash(SERVER_ID, FROM_NYM_ID, ASSET_TYPE_ID, TO_NYM_ID, STR_INDICES, bPasswordProtected, STR_RETAINED_COPY);
}


// WITHDRAW VOUCHER -- TRANSACTION
//
std::string OT_ME::withdraw_voucher(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCT_ID,
    const std::string & RECIP_NYM_ID,
    const std::string & STR_MEMO,
    const int64_t AMOUNT)
{
    return m_pImplementation->withdraw_voucher(SERVER_ID, NYM_ID, ACCT_ID, RECIP_NYM_ID, STR_MEMO, AMOUNT);
}


// PAY DIVIDEND -- TRANSACTION
//
std::string OT_ME::pay_dividend(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & SOURCE_ACCT_ID,
    const std::string & SHARES_ASSET_ID,
    const std::string & STR_MEMO,
    const int64_t AMOUNT_PER_SHARE)
{
    return m_pImplementation->pay_dividend(SERVER_ID, NYM_ID, SOURCE_ACCT_ID, SHARES_ASSET_ID, STR_MEMO, AMOUNT_PER_SHARE);
}


std::string OT_ME::deposit_cheque(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCT_ID,
    const std::string & STR_CHEQUE)
{

    return m_pImplementation->deposit_cheque(SERVER_ID, NYM_ID, ACCT_ID, STR_CHEQUE);
}


int32_t OT_ME::deposit_cash(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCT_ID,
    const std::string & STR_PURSE)
{
    return m_pImplementation->deposit_cash(SERVER_ID, NYM_ID, ACCT_ID, STR_PURSE);
}


int32_t OT_ME::deposit_local_purse(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & ACCT_ID,
    const std::string & STR_INDICES)
{
    return m_pImplementation->deposit_local_purse(SERVER_ID, NYM_ID, ACCT_ID, STR_INDICES);
}


std::string OT_ME::get_market_list(const std::string & SERVER_ID,
    const std::string & NYM_ID)
{
    return m_pImplementation->get_market_list(SERVER_ID, NYM_ID);
}


std::string OT_ME::get_market_offers(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & MARKET_ID,
    const int64_t MAX_DEPTH)
{
    return m_pImplementation->get_market_offers(SERVER_ID, NYM_ID, MARKET_ID, MAX_DEPTH);
}


std::string OT_ME::get_nym_market_offers(const std::string & SERVER_ID,
    const std::string & NYM_ID)
{
    return m_pImplementation->get_nym_market_offers(SERVER_ID, NYM_ID);
}


std::string OT_ME::get_market_recent_trades(const std::string & SERVER_ID,
    const std::string & NYM_ID,
    const std::string & MARKET_ID)
{
    return m_pImplementation->get_market_recent_trades(SERVER_ID, NYM_ID, MARKET_ID);
}


std::string OT_ME::adjust_usage_credits(const std::string & SERVER_ID,
    const std::string & USER_NYM_ID,
    const std::string & TARGET_NYM_ID,
    const std::string & ADJUSTMENT)
{
    return m_pImplementation->adjust_usage_credits(SERVER_ID, USER_NYM_ID, TARGET_NYM_ID, ADJUSTMENT);
}


//************************************************************************************


int32_t OT_ME::VerifyMessageSuccess(const std::string & str_Message)
{
    if (str_Message.size() < 10)
    {
        OTLog::vOutput(1, "%s: Error str_Message is: Too Short: \n%s\n\n",
            __FUNCTION__, str_Message.c_str());
        return -1;
    }

    int32_t nStatus = OTAPI_Wrap::Message_GetSuccess(str_Message);

    switch (nStatus)
    {
        case (-1):
        OTLog::vOutput(0, "%s: Error calling OT_API_Message_GetSuccess, for message:\n%s\n",
        __FUNCTION__, str_Message.c_str());
        break;
        case (0):
        OTLog::vOutput(1, "%s: Reply received: success == FALSE. Reply message:\n%s\n",
        __FUNCTION__, str_Message.c_str());
        break;
        case (1):
        OTLog::vOutput(1, "%s: Reply received: success == TRUE.\n", __FUNCTION__);
        break;
    default:
        OTLog::vOutput(0, "%s: Error. (This should never happen!) nStatus: %d, Input:\n%s\n",
            __FUNCTION__, static_cast<int32_t>(nStatus), str_Message.c_str());
        nStatus = (-1);
        break;
    }

    return nStatus;
}


int32_t OT_ME::VerifyMsgBalanceAgrmntSuccess(const std::string & SERVER_ID,
    const std::string & USER_ID,
    const std::string & ACCOUNT_ID,
    const std::string & str_Message)
{
    if (str_Message.size() < 10)
    {
        OTLog::vOutput(1, "%s: Error str_Message is: Too Short: \n%s\n\n",
            __FUNCTION__, str_Message.c_str());
        return -1;
    }

    int32_t nStatus = OTAPI_Wrap::Message_GetBalanceAgreementSuccess(SERVER_ID, USER_ID, ACCOUNT_ID, str_Message);

    switch (nStatus)
    {
        case (-1):
        OTLog::vOutput(0, "%s: Error calling Msg_GetBlnceAgrmntSuccess, for message:\n%s\n",
        __FUNCTION__, str_Message.c_str());
        break;
        case (0):
        OTLog::vOutput(1, "%s: Reply received: success == FALSE. Reply message:\n%s\n",
        __FUNCTION__, str_Message.c_str());
        break;
        case (1):
        OTLog::vOutput(1, "%s: Reply received: success == TRUE.\n", __FUNCTION__);
        break;
    default:
        OTLog::vOutput(0, "%s: Error. (This should never happen!) nStatus: %d, Input:\n%s\n",
            __FUNCTION__, static_cast<int32_t>(nStatus), str_Message.c_str());
        nStatus = (-1);
        break;
    }

    return nStatus;
}


int32_t OT_ME::VerifyMsgTrnxSuccess(const std::string & SERVER_ID,
    const std::string & USER_ID,
    const std::string & ACCOUNT_ID,
    const std::string & str_Message)
{
    if (str_Message.size() < 10)
    {
        OTLog::vOutput(1, "%s: Error str_Message is: Too Short: \n%s\n\n",
            __FUNCTION__, str_Message.c_str());
        return -1;
    }

    int32_t nStatus = OTAPI_Wrap::Message_GetTransactionSuccess(SERVER_ID, USER_ID, ACCOUNT_ID, str_Message);

    switch (nStatus)
    {
        case (-1):
        OTLog::vOutput(0, "%s: Error calling Msg_GetTransactionSuccess, for message:\n%s\n",
        __FUNCTION__, str_Message.c_str());
        break;
        case (0):
        OTLog::vOutput(1, "%s: Reply received: success == FALSE. Reply message:\n%s\n",
        __FUNCTION__, str_Message.c_str());
        break;
        case (1):
        OTLog::vOutput(1, "%s: Reply received: success == TRUE.\n", __FUNCTION__);
        break;
    default:
        OTLog::vOutput(0, "%s: Error. (This should never happen!) nStatus: %d, Input:\n%s\n",
            __FUNCTION__, static_cast<int32_t>(nStatus), str_Message.c_str());
        nStatus = (-1);
        break;
    }

    return nStatus;
}


// This code was repeating a lot, so I just added a function for it.
//
// It uses the above functions.
//
int32_t OT_ME::InterpretTransactionMsgReply(const std::string & SERVER_ID,
    const std::string & USER_ID,
    const std::string & ACCOUNT_ID,
    const std::string & str_Attempt,
    const std::string & str_Response)
{
    int32_t nMessageSuccess = VerifyMessageSuccess(str_Response);

    if ((-1) == nMessageSuccess)
    {
        OTLog::vOutput(0, "%s: Message error: %s\n",
            __FUNCTION__, str_Attempt.c_str());
        return (-1);
    }
    else if (0 == nMessageSuccess)
    {
        OTLog::vOutput(0, "%s: Server reply (%s): Message failure.\n",
            __FUNCTION__, str_Attempt.c_str());
        return 0;
    }
    // (else 1.)
    int32_t nBalanceSuccess = VerifyMsgBalanceAgrmntSuccess(SERVER_ID, USER_ID, ACCOUNT_ID, str_Response);

    if ((-1) == nBalanceSuccess)
    {
        OTLog::vOutput(0, "%s: Balance agreement error: %s\n",
            __FUNCTION__, str_Attempt.c_str());
        return (-1);
    }
    else if (0 == nBalanceSuccess)
    {
        OTLog::vOutput(0, "%s: Server reply (%s): Balance agreement failure.\n",
            __FUNCTION__, str_Attempt.c_str());
        return 0;
    }
    // (else 1.)
    int32_t nTransSuccess = VerifyMsgTrnxSuccess(SERVER_ID, USER_ID, ACCOUNT_ID, str_Response);

    if ((-1) == nTransSuccess)
    {
        OTLog::vOutput(0, "%s: Transaction error: %s\n",
            __FUNCTION__, str_Attempt.c_str());
        return (-1);
    }
    else if (0 == nTransSuccess)
    {
        OTLog::vOutput(0, "%s: Server reply (%s): Transaction failure.\n",
            __FUNCTION__, str_Attempt.c_str());
        return 0;
    }
    // (else 1.)
    //
    // Success!
    //
    return 1;
}


bool OT_ME::HaveWorkingScript()
{
    if (m_pScript)
    {
        // already initialized
        return true;
    }

    // note: if there's a choice of language, you must specify here. Perhaps add as a parameter above, when the time comes to add another scripting language.
    m_pScript = OTScriptFactory();
    if (!m_pScript)
    {
        OTLog::vError("%s: Error instantiating script.\n", __FUNCTION__);
        return false;
    }

#ifdef OT_USE_SCRIPT_CHAI
    if (!SetupScriptObject())
    {
        OTLog::vError("%s: Error setting up script object.\n", __FUNCTION__);
        m_pScript.reset(); // Erase the one we just created, since we failed setting it up.
        return false;
    }
#endif

    return true;
}


// used in otd/main.cpp
//
void OT_ME::AddVariable(const std::string & str_var_name, OTVariable & theVar)
{
    if (HaveWorkingScript())
    {
        theVar.RegisterForExecution(*m_pScript); // This sets a pointer to the script so the var can remove itself on destruction.
    }
}

OTVariable * OT_ME::FindVariable(const std::string & str_var_name)
{
    return HaveWorkingScript() ? m_pScript->FindVariable(str_var_name) : NULL;
}

OTVariable * OT_ME::FindVariable2(const std::string & str_var_name)
{
    return s_pMe->FindVariable(str_var_name);
}

std::string OT_ME::ExecuteScript_ReturnString(const std::string & str_Code, std::string str_DisplayName/*="<BLANK>"*/)
{
    std::string str_Return = "";
    if (HaveWorkingScript())
    {
        OTVariable the_return_value("ret_val", str_Return);

        m_pScript->SetScript(str_Code);
        m_pScript->SetDisplayFilename(str_DisplayName);
        m_pScript->ExecuteScript(&the_return_value);  // <====== EXECUTE SCRIPT.

        if (OTVariable::Var_String == the_return_value.GetType())
            str_Return = the_return_value.CopyValueString();
    }
    return str_Return;
}


bool OT_ME::ExecuteScript_ReturnBool(const std::string & str_Code, std::string str_DisplayName/*="<BLANK>"*/)
{
    bool bReturn = false;
    if (HaveWorkingScript())
    {
        OTVariable the_return_value("ret_val", bReturn);

        m_pScript->SetScript(str_Code);
        m_pScript->SetDisplayFilename(str_DisplayName);
        m_pScript->ExecuteScript(&the_return_value);  // <====== EXECUTE SCRIPT.

        if (OTVariable::Var_Bool == the_return_value.GetType())
            bReturn = the_return_value.CopyValueBool();
    }
    return bReturn;
}

int32_t OT_ME::ExecuteScript_ReturnInt(const std::string & str_Code, std::string str_DisplayName/*="<BLANK>"*/)
{
    int32_t nReturn = -1;
    if (HaveWorkingScript())
    {
        OTVariable the_return_value("ret_val", nReturn);

        m_pScript->SetScript(str_Code);
        m_pScript->SetDisplayFilename(str_DisplayName);
        m_pScript->ExecuteScript(&the_return_value);  // <====== EXECUTE SCRIPT.

        if (OTVariable::Var_Integer == the_return_value.GetType())
            nReturn = the_return_value.CopyValueInteger();
    }
    return nReturn;
}

void OT_ME::ExecuteScript_ReturnVoid(const std::string & str_Code, std::string str_DisplayName/*="<BLANK>"*/)
{
    if (HaveWorkingScript())
    {
        m_pScript->SetScript(str_Code);
        m_pScript->SetDisplayFilename(str_DisplayName);
        m_pScript->ExecuteScript();  // <====== EXECUTE SCRIPT.        
    }
}



bool OT_ME::SetupScriptObject()
{
    OTString strDataPath;
    { bool bGetDataPathSuccess = OTDataFolder::Get(strDataPath);
    OT_ASSERT_MSG(bGetDataPathSuccess,"SetupScriptObject: Must set Data Path first!"); }
    const bool bRegistered_OTDB = Register_OTDB_With_Script();
    const bool bRegistered_CLI = Register_CLI_With_Script();
    const bool bRegistered_API = Register_API_With_Script();
    const bool bRegistered_Headers = Register_Headers_With_Script();
    return bRegistered_OTDB && bRegistered_CLI && bRegistered_API && bRegistered_Headers;
}



bool OT_ME::Register_OTDB_With_Script()
{
#ifdef OT_USE_SCRIPT_CHAI
    // See if it's ChaiScript.
    //
    OTScriptChai * pScript = dynamic_cast<OTScriptChai *> (m_pScript.get());

    if (NULL != pScript)
    {
        return Register_OTDB_With_Script_Chai(*pScript);
    }
#endif // OT_USE_SCRIPT_CHAI

    OTLog::vError("%s: Failed dynamic casting OTScript to OTScriptChai \n", __FUNCTION__);
    return false;
}


bool OT_ME::Register_CLI_With_Script()
{
#ifdef OT_USE_SCRIPT_CHAI
    // See if it's ChaiScript.
    //
    OTScriptChai * pScript = dynamic_cast<OTScriptChai *> (m_pScript.get());

    if (NULL != pScript)
    {
        return Register_CLI_With_Script_Chai(*pScript);
    }
#endif // OT_USE_SCRIPT_CHAI

    OTLog::vError("%s: Failed dynamic casting OTScript to OTScriptChai \n", __FUNCTION__);
    return false;
}

bool OT_ME::Register_API_With_Script()
{
#ifdef OT_USE_SCRIPT_CHAI
    // See if it's ChaiScript.
    //
    OTScriptChai * pScript = dynamic_cast<OTScriptChai *> (m_pScript.get());

    if (NULL != pScript)
    {
        return Register_API_With_Script_Chai(*pScript);
    }
#endif // OT_USE_SCRIPT_CHAI

    OTLog::vError("%s: Failed dynamic casting OTScript to OTScriptChai \n", __FUNCTION__);
    return false;
}

bool OT_ME::Register_Headers_With_Script()
{
#ifdef OT_USE_SCRIPT_CHAI
    // See if it's ChaiScript.
    //
    OTScriptChai * pScript = dynamic_cast<OTScriptChai *> (m_pScript.get());

    if (NULL != pScript)
    {
        return Register_Headers_With_Script_Chai(*pScript);
    }
#endif // OT_USE_SCRIPT_CHAI

    OTLog::vError("%s: Failed dynamic casting OTScript to OTScriptChai \n", __FUNCTION__);
    return false;
}










#ifdef OT_USE_SCRIPT_CHAI






//bool OT_ME::Register_OTDB_With_Script_Lua(OTScriptLua & theScript)

bool OT_ME::Register_OTDB_With_Script_Chai(OTScriptChai & theScript)
{
    OT_ASSERT(NULL != theScript.chai)

    using namespace chaiscript;
    {
        // ADD ENUMS
        theScript.chai->add(user_type<OTDB::StoredObjectType>(), "OTDB_StoredObjectType");

        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_STRING), "STORED_OBJ_STRING");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_BLOB), "STORED_OBJ_BLOB");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_STRING_MAP), "STORED_OBJ_STRING_MAP");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_WALLET_DATA), "STORED_OBJ_WALLET_DATA");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_BID_DATA), "STORED_OBJ_BID_DATA");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_ASK_DATA), "STORED_OBJ_ASK_DATA");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_MARKET_DATA), "STORED_OBJ_MARKET_DATA");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_MARKET_LIST), "STORED_OBJ_MARKET_LIST");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_OFFER_LIST_MARKET), "STORED_OBJ_OFFER_LIST_MARKET");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_TRADE_DATA_MARKET), "STORED_OBJ_TRADE_DATA_MARKET");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_TRADE_LIST_MARKET), "STORED_OBJ_TRADE_LIST_MARKET");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_OFFER_DATA_NYM), "STORED_OBJ_OFFER_DATA_NYM");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_OFFER_LIST_NYM), "STORED_OBJ_OFFER_LIST_NYM");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_TRADE_DATA_NYM), "STORED_OBJ_TRADE_DATA_NYM");
        theScript.chai->add_global_const(const_var(OTDB::STORED_OBJ_TRADE_LIST_NYM), "STORED_OBJ_TRADE_LIST_NYM");

        // ADD OBJECT TYPES
        theScript.chai->add(user_type<OTDB::Storage>(), "OTDB_Storage");
        theScript.chai->add(user_type<OTDB::Storable>(), "OTDB_Storable");
        theScript.chai->add(user_type<OTDB::OTDBString>(), "OTDB_String");
        theScript.chai->add(user_type<OTDB::Blob>(), "OTDB_Blob");
        theScript.chai->add(user_type<OTDB::StringMap>(), "OTDB_StringMap");
        theScript.chai->add(user_type<OTDB::Displayable>(), "OTDB_Displayable");
        theScript.chai->add(user_type<OTDB::MarketData>(), "OTDB_MarketData");
        theScript.chai->add(user_type<OTDB::MarketList>(), "OTDB_MarketList");
        theScript.chai->add(user_type<OTDB::OfferDataMarket>(), "OTDB_OfferDataMarket");
        theScript.chai->add(user_type<OTDB::BidData>(), "OTDB_BidData");
        theScript.chai->add(user_type<OTDB::AskData>(), "OTDB_AskData");
        theScript.chai->add(user_type<OTDB::OfferListMarket>(), "OTDB_OfferListMarket");
        theScript.chai->add(user_type<OTDB::TradeDataMarket>(), "OTDB_TradeDataMarket");
        theScript.chai->add(user_type<OTDB::TradeListMarket>(), "OTDB_TradeListMarket");
        theScript.chai->add(user_type<OTDB::OfferDataNym>(), "OTDB_OfferDataNym");
        theScript.chai->add(user_type<OTDB::OfferListNym>(), "OTDB_OfferListNym");
        theScript.chai->add(user_type<OTDB::TradeDataNym>(), "OTDB_TradeDataNym");
        theScript.chai->add(user_type<OTDB::TradeListNym>(), "OTDB_TradeListNym");
//      theScript.chai->add(user_type<OTDB::Acct>(),               "OTDB_Acct");
//      theScript.chai->add(user_type<OTDB::BitcoinAcct>(),        "OTDB_BitcoinAcct");
//      theScript.chai->add(user_type<OTDB::ServerInfo>(),         "OTDB_ServerInfo");
//      theScript.chai->add(user_type<OTDB::Server>(),             "OTDB_Server");
//      theScript.chai->add(user_type<OTDB::BitcoinServer>(),      "OTDB_BitcoinServer");
//      theScript.chai->add(user_type<OTDB::RippleServer>(),       "OTDB_RippleServer");
//      theScript.chai->add(user_type<OTDB::LoomServer>(),         "OTDB_LoomServer");
//      theScript.chai->add(user_type<OTDB::ContactNym>(),         "OTDB_ContactNym");
//      theScript.chai->add(user_type<OTDB::WalletData>(),         "OTDB_WalletData");
//      theScript.chai->add(user_type<OTDB::ContactAcct>(),        "OTDB_ContactAcct");
//      theScript.chai->add(user_type<OTDB::Contact>(),            "OTDB_Contact");
//      theScript.chai->add(user_type<OTDB::AddressBook>(),        "OTDB_AddressBook");


        // SHOW INHERITANCE
        theScript.chai->add(chaiscript::base_class<OTDB::Storable, OTDB::OTDBString>());
        theScript.chai->add(chaiscript::base_class<OTDB::Storable, OTDB::Blob>());
        theScript.chai->add(chaiscript::base_class<OTDB::Storable, OTDB::StringMap>());
        theScript.chai->add(chaiscript::base_class<OTDB::Storable, OTDB::Displayable>());
        theScript.chai->add(chaiscript::base_class<OTDB::Displayable, OTDB::MarketData>());
        theScript.chai->add(chaiscript::base_class<OTDB::Storable, OTDB::MarketList>());
        theScript.chai->add(chaiscript::base_class<OTDB::Displayable, OTDB::OfferDataMarket>());
        theScript.chai->add(chaiscript::base_class<OTDB::OfferDataMarket, OTDB::BidData>());
        theScript.chai->add(chaiscript::base_class<OTDB::OfferDataMarket, OTDB::AskData>());
        theScript.chai->add(chaiscript::base_class<OTDB::Storable, OTDB::OfferListMarket>());
        theScript.chai->add(chaiscript::base_class<OTDB::Displayable, OTDB::TradeDataMarket>());
        theScript.chai->add(chaiscript::base_class<OTDB::Storable, OTDB::TradeListMarket>());
        theScript.chai->add(chaiscript::base_class<OTDB::Displayable, OTDB::OfferDataNym>());
        theScript.chai->add(chaiscript::base_class<OTDB::Storable, OTDB::OfferListNym>());
        theScript.chai->add(chaiscript::base_class<OTDB::Displayable, OTDB::TradeDataNym>());
        theScript.chai->add(chaiscript::base_class<OTDB::Storable, OTDB::TradeListNym>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Displayable,      OTDB::Acct>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Acct,             OTDB::BitcoinAcct>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Displayable,      OTDB::ServerInfo>());
//      theScript.chai->add(chaiscript::base_class<OTDB::ServerInfo,       OTDB::Server>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Server,           OTDB::BitcoinServer>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Server,           OTDB::RippleServer>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Server,           OTDB::LoomServer>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Displayable,      OTDB::ContactNym>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Storable,         OTDB::WalletData>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Displayable,      OTDB::ContactAcct>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Displayable,      OTDB::Contact>());
//      theScript.chai->add(chaiscript::base_class<OTDB::Storable,         OTDB::AddressBook>());




        // ADD STORAGE FUNCTIONS
        theScript.chai->add(fun(&OTDB::CreateObject), "OTDB_CreateObject");

//      theScript.chai->add(fun(&OTDB::Exists),           "OTDB_Exists");
        theScript.chai->add(fun<bool(std::string, std::string, std::string, std::string)>(&OTDB::Exists), "OTDB_Exists");
//      theScript.chai->add(fun<bool (std::string, std::string, std::string)>(&OTDB::Exists), "OTDB_Exists");
//      theScript.chai->add(fun<bool (std::string, std::string)>(&OTDB::Exists), "OTDB_Exists");
//      theScript.chai->add(fun<bool (std::string)>(&OTDB::Exists), "OTDB_Exists");


//      theScript.chai->add(fun(&OTDB::StoreString),      "OTDB_StoreString");
        theScript.chai->add(fun<bool(std::string, std::string, std::string, std::string, std::string)>(&OTDB::StoreString), "OTDB_StoreString");
//      theScript.chai->add(fun<bool (std::string, std::string, std::string, std::string)>(&OTDB::StoreString), "OTDB_StoreString");
//      theScript.chai->add(fun<bool (std::string, std::string, std::string)>(&OTDB::StoreString), "OTDB_StoreString");
//      theScript.chai->add(fun<bool (std::string, std::string)>(&OTDB::StoreString), "OTDB_StoreString");


//      theScript.chai->add(fun(&OTDB::QueryString),      "OTDB_QueryString");
        theScript.chai->add(fun<std::string(std::string, std::string, std::string, std::string)>(&OTDB::QueryString), "OTDB_QueryString");
//      theScript.chai->add(fun<std::string (std::string, std::string, std::string)>(&OTDB::QueryString), "OTDB_QueryString");
//      theScript.chai->add(fun<std::string (std::string, std::string)>(&OTDB::QueryString), "OTDB_QueryString");
//      theScript.chai->add(fun<std::string (std::string)>(&OTDB::QueryString), "OTDB_QueryString");


//      theScript.chai->add(fun(&OTDB::StorePlainString), "OTDB_StorePlainString");
        theScript.chai->add(fun<bool(std::string, std::string, std::string, std::string, std::string)>(&OTDB::StorePlainString), "OTDB_StorePlainString");
//      theScript.chai->add(fun<bool (std::string, std::string, std::string, std::string)>(&OTDB::StorePlainString), "OTDB_StorePlainString");
//      theScript.chai->add(fun<bool (std::string, std::string, std::string)>(&OTDB::StorePlainString), "OTDB_StorePlainString");
//      theScript.chai->add(fun<bool (std::string, std::string)>(&OTDB::StorePlainString), "OTDB_StorePlainString");


//      theScript.chai->add(fun(&OTDB::QueryPlainString), "OTDB_QueryPlainString");
        theScript.chai->add(fun<std::string(std::string, std::string, std::string, std::string)>(&OTDB::QueryPlainString), "OTDB_QueryPlainString");
//      theScript.chai->add(fun<std::string (std::string, std::string, std::string)>(&OTDB::QueryPlainString), "OTDB_QueryPlainString");
//      theScript.chai->add(fun<std::string (std::string, std::string)>(&OTDB::QueryPlainString), "OTDB_QueryPlainString");
//      theScript.chai->add(fun<std::string (std::string)>(&OTDB::QueryPlainString), "OTDB_QueryPlainString");


//      theScript.chai->add(fun(&OTDB::StoreObject),      "OTDB_StoreObject");
        theScript.chai->add(fun<bool(OTDB::Storable &, std::string, std::string, std::string, std::string)>(&OTDB::StoreObject), "OTDB_StoreObject");
//      theScript.chai->add(fun<bool (OTDB::Storable &, std::string, std::string, std::string)>(&OTDB::StoreObject), "OTDB_StoreObject");
//      theScript.chai->add(fun<bool (OTDB::Storable &, std::string, std::string)>(&OTDB::StoreObject), "OTDB_StoreObject");
//      theScript.chai->add(fun<bool (OTDB::Storable &, std::string)>(&OTDB::StoreObject), "OTDB_StoreObject");


//      theScript.chai->add(fun(&OTDB::QueryObject),      "OTDB_QueryObject");
        theScript.chai->add(fun<OTDB::Storable * (OTDB::StoredObjectType, std::string, std::string, std::string, std::string)>(&OTDB::QueryObject), "OTDB_QueryObject");
//      theScript.chai->add(fun<OTDB::Storable * (OTDB::StoredObjectType, std::string, std::string, std::string)>(&OTDB::QueryObject), "OTDB_QueryObject");
//      theScript.chai->add(fun<OTDB::Storable * (OTDB::StoredObjectType, std::string, std::string)>(&OTDB::QueryObject), "OTDB_QueryObject");
//      theScript.chai->add(fun<OTDB::Storable * (OTDB::StoredObjectType, std::string)>(&OTDB::QueryObject), "OTDB_QueryObject");


        theScript.chai->add(fun(&OTDB::EncodeObject), "OTDB_EncodeObject");
        theScript.chai->add(fun(&OTDB::DecodeObject), "OTDB_DecodeObject");


//      theScript.chai->add(fun(&OTDB::EraseValueByKey),  "OTDB_EraseValueByKey");


        // ADD DYNAMIC CASTING.
        //
//      theScript.chai->add(fun<OTDB::OTDBString * (OTDB::Storable *)>(&OTDB::OTDBString::ot_dynamic_cast),       "OTDB_CAST_STRING");
        theScript.chai->add(fun(&OTDB::OTDBString::ot_dynamic_cast), "OTDB_CAST_STRING");
        theScript.chai->add(fun(&OTDB::Blob::ot_dynamic_cast), "OTDB_CAST_BLOB");
        theScript.chai->add(fun(&OTDB::StringMap::ot_dynamic_cast), "OTDB_CAST_STRING_MAP");
        theScript.chai->add(fun(&OTDB::Displayable::ot_dynamic_cast), "OTDB_CAST_DISPLAYABLE");
        theScript.chai->add(fun(&OTDB::MarketData::ot_dynamic_cast), "OTDB_CAST_MARKET_DATA");



//      theScript.chai->add(fun<OTDB::MarketList * (OTDB::Storable *)>(&OTDB::MarketList::ot_dynamic_cast),       "OTDB_CAST_MARKET_LIST");
        theScript.chai->add(fun(&OTDB::MarketList::ot_dynamic_cast), "OTDB_CAST_MARKET_LIST");
        theScript.chai->add(fun(&OTDB::OfferDataMarket::ot_dynamic_cast), "OTDB_CAST_OFFER_DATA_MARKET");
        theScript.chai->add(fun(&OTDB::BidData::ot_dynamic_cast), "OTDB_CAST_BID_DATA");
        theScript.chai->add(fun(&OTDB::AskData::ot_dynamic_cast), "OTDB_CAST_ASK_DATA");
        theScript.chai->add(fun(&OTDB::OfferListMarket::ot_dynamic_cast), "OTDB_CAST_OFFER_LIST_MARKET");
        theScript.chai->add(fun(&OTDB::TradeDataMarket::ot_dynamic_cast), "OTDB_CAST_TRADE_DATA_MARKET");
        theScript.chai->add(fun(&OTDB::TradeListMarket::ot_dynamic_cast), "OTDB_CAST_TRADE_LIST_MARKET");
        theScript.chai->add(fun(&OTDB::OfferDataNym::ot_dynamic_cast), "OTDB_CAST_OFFER_DATA_NYM");
        theScript.chai->add(fun(&OTDB::OfferListNym::ot_dynamic_cast), "OTDB_CAST_OFFER_LIST_NYM");
        theScript.chai->add(fun(&OTDB::TradeDataNym::ot_dynamic_cast), "OTDB_CAST_TRADE_DATA_NYM");
        theScript.chai->add(fun(&OTDB::TradeListNym::ot_dynamic_cast), "OTDB_CAST_TRADE_LIST_NYM");


//      theScript.chai->add(fun(&OTDB::MarketList::GetMarketDataCount), "GetMarketDataCount");
//      theScript.chai->add(fun(&OTDB::MarketList::GetMarketData),      "GetMarketData");
//      theScript.chai->add(fun(&OTDB::MarketList::RemoveMarketData),   "RemoveMarketData");
//      theScript.chai->add(fun(&OTDB::MarketList::AddMarketData),      "AddMarketData");
//
//      theScript.chai->add(fun(&OTDB::MarketList::Get##name##Count), "Get" #name "Count");
//      theScript.chai->add(fun(&OTDB::MarketList::Get##name),      "Get" #name );
//      theScript.chai->add(fun(&OTDB::MarketList::Remove##name),   "Remove" #name);
//      theScript.chai->add(fun(&OTDB::MarketList::Add##name),      "Add" #name);
//
//      EXPORT size_t Get##name##Count(); \
//      EXPORT name * Get##name(size_t nIndex); \
//      EXPORT bool Remove##name(size_t nIndex##name); \
//      EXPORT bool Add##name(name & disownObject)

#define OT_CHAI_CONTAINER(container, name) \
    theScript.chai->add(fun(&OTDB::container::Get##name##Count), "Get" #name "Count"); \
    theScript.chai->add(fun(&OTDB::container::Get##name), "Get" #name); \
    theScript.chai->add(fun(&OTDB::container::Remove##name), "Remove" #name); \
    theScript.chai->add(fun(&OTDB::container::Add##name), "Add" #name)

        // ADD MEMBERS OF THE VARIOUS OBJECTS

        theScript.chai->add(fun(&OTDB::OTDBString::m_string), "m_string");
        theScript.chai->add(fun(&OTDB::Blob::m_memBuffer), "m_memBuffer");
        theScript.chai->add(fun(&OTDB::StringMap::the_map), "the_map");
        theScript.chai->add(fun(&OTDB::StringMap::SetValue), "SetValue");
        theScript.chai->add(fun(&OTDB::StringMap::GetValue), "GetValue");
        theScript.chai->add(fun(&OTDB::Displayable::gui_label), "gui_label");
//      theScript.chai->add(fun(&OTDB::MarketData::gui_label),         "gui_label");
        theScript.chai->add(fun(&OTDB::MarketData::server_id), "server_id");
        theScript.chai->add(fun(&OTDB::MarketData::market_id), "market_id");
        theScript.chai->add(fun(&OTDB::MarketData::asset_type_id), "asset_type_id");
        theScript.chai->add(fun(&OTDB::MarketData::currency_type_id), "currency_type_id");
        theScript.chai->add(fun(&OTDB::MarketData::scale), "scale");
        theScript.chai->add(fun(&OTDB::MarketData::total_assets), "total_assets");
        theScript.chai->add(fun(&OTDB::MarketData::number_bids), "number_bids");
        theScript.chai->add(fun(&OTDB::MarketData::number_asks), "number_asks");
        theScript.chai->add(fun(&OTDB::MarketData::last_sale_price), "last_sale_price");
        theScript.chai->add(fun(&OTDB::MarketData::last_sale_date), "last_sale_date");
        theScript.chai->add(fun(&OTDB::MarketData::current_bid), "current_bid");
        theScript.chai->add(fun(&OTDB::MarketData::current_ask), "current_ask");

        OT_CHAI_CONTAINER(MarketList, MarketData);
//      theScript.chai->add(fun(&OTDB::OfferDataMarket::gui_label),         "gui_label");
        theScript.chai->add(fun(&OTDB::OfferDataMarket::transaction_id), "transaction_id");
        theScript.chai->add(fun(&OTDB::OfferDataMarket::price_per_scale), "price_per_scale");
        theScript.chai->add(fun(&OTDB::OfferDataMarket::available_assets), "available_assets");
        theScript.chai->add(fun(&OTDB::OfferDataMarket::minimum_increment), "minimum_increment");
        theScript.chai->add(fun(&OTDB::OfferDataMarket::date), "date");

//      theScript.chai->add(fun(&OTDB::BidData::gui_label),         "gui_label");
//      theScript.chai->add(fun(&OTDB::BidData::transaction_id),    "transaction_id");
//      theScript.chai->add(fun(&OTDB::BidData::price_per_scale),   "price_per_scale");
//      theScript.chai->add(fun(&OTDB::BidData::available_assets),  "available_assets");
//      theScript.chai->add(fun(&OTDB::BidData::minimum_increment), "minimum_increment");

//      theScript.chai->add(fun(&OTDB::AskData::gui_label),         "gui_label");
//      theScript.chai->add(fun(&OTDB::AskData::transaction_id),    "transaction_id");
//      theScript.chai->add(fun(&OTDB::AskData::price_per_scale),   "price_per_scale");
//      theScript.chai->add(fun(&OTDB::AskData::available_assets),  "available_assets");
//      theScript.chai->add(fun(&OTDB::AskData::minimum_increment), "minimum_increment");

        OT_CHAI_CONTAINER(OfferListMarket, BidData);
        OT_CHAI_CONTAINER(OfferListMarket, AskData);
//      theScript.chai->add(fun(&OTDB::TradeDataMarket::gui_label),      "gui_label");
        theScript.chai->add(fun(&OTDB::TradeDataMarket::transaction_id), "transaction_id");
        theScript.chai->add(fun(&OTDB::TradeDataMarket::date), "date");
        theScript.chai->add(fun(&OTDB::TradeDataMarket::price), "price");
        theScript.chai->add(fun(&OTDB::TradeDataMarket::amount_sold), "amount_sold");

        OT_CHAI_CONTAINER(TradeListMarket, TradeDataMarket);
//      theScript.chai->add(fun(&OTDB::OfferDataNym::gui_label),      "gui_label");
        theScript.chai->add(fun(&OTDB::OfferDataNym::valid_from), "valid_from");
        theScript.chai->add(fun(&OTDB::OfferDataNym::valid_to), "valid_to");
        theScript.chai->add(fun(&OTDB::OfferDataNym::server_id), "server_id");
        theScript.chai->add(fun(&OTDB::OfferDataNym::asset_type_id), "asset_type_id");
        theScript.chai->add(fun(&OTDB::OfferDataNym::asset_acct_id), "asset_acct_id");
        theScript.chai->add(fun(&OTDB::OfferDataNym::currency_type_id), "currency_type_id");
        theScript.chai->add(fun(&OTDB::OfferDataNym::currency_acct_id), "currency_acct_id");
        theScript.chai->add(fun(&OTDB::OfferDataNym::selling), "selling");
        theScript.chai->add(fun(&OTDB::OfferDataNym::scale), "scale");
        theScript.chai->add(fun(&OTDB::OfferDataNym::price_per_scale), "price_per_scale");
        theScript.chai->add(fun(&OTDB::OfferDataNym::transaction_id), "transaction_id");
        theScript.chai->add(fun(&OTDB::OfferDataNym::total_assets), "total_assets");
        theScript.chai->add(fun(&OTDB::OfferDataNym::finished_so_far), "finished_so_far");
        theScript.chai->add(fun(&OTDB::OfferDataNym::minimum_increment), "minimum_increment");
        theScript.chai->add(fun(&OTDB::OfferDataNym::stop_sign), "stop_sign");
        theScript.chai->add(fun(&OTDB::OfferDataNym::stop_price), "stop_price");
        theScript.chai->add(fun(&OTDB::OfferDataNym::date), "date");

        OT_CHAI_CONTAINER(OfferListNym, OfferDataNym);
//      theScript.chai->add(fun(&OTDB::TradeDataNym::gui_label),       "gui_label");
        theScript.chai->add(fun(&OTDB::TradeDataNym::transaction_id), "transaction_id");
        theScript.chai->add(fun(&OTDB::TradeDataNym::completed_count), "completed_count");
        theScript.chai->add(fun(&OTDB::TradeDataNym::date), "date");
        theScript.chai->add(fun(&OTDB::TradeDataNym::price), "price");
        theScript.chai->add(fun(&OTDB::TradeDataNym::amount_sold), "amount_sold");
        theScript.chai->add(fun(&OTDB::TradeDataNym::updated_id), "updated_id");
        theScript.chai->add(fun(&OTDB::TradeDataNym::offer_price), "offer_price");
        theScript.chai->add(fun(&OTDB::TradeDataNym::finished_so_far), "finished_so_far");
        theScript.chai->add(fun(&OTDB::TradeDataNym::asset_id), "asset_id");
        theScript.chai->add(fun(&OTDB::TradeDataNym::currency_id), "currency_id");
        theScript.chai->add(fun(&OTDB::TradeDataNym::currency_paid), "currency_paid");

        OT_CHAI_CONTAINER(TradeListNym, TradeDataNym);
        return true; // Success (hopefully!)
    }
}


//bool OT_ME::Register_CLI_With_Script_Lua(OTScriptLua & theScript)

bool OT_ME::Register_CLI_With_Script_Chai(OTScriptChai & theScript)
{
    using namespace chaiscript;
    {
        // ADD THE OT CLI FUNCTIONS
        theScript.chai->add(fun(&OT_CLI_ReadLine), "OT_CLI_ReadLine");   // String OT_CLI_ReadLine()  // Reads from cin until Newline.
        theScript.chai->add(fun(&OT_CLI_ReadUntilEOF), "OT_CLI_ReadUntilEOF"); // String OT_CLI_ReadUntilEOF() // Reads from cin until EOF or ~ on a line by itself.
        // For command-line option (for SCRIPTS):  ot --script <filename> [--args "key value key value ..."]
        theScript.chai->add(fun(&OT_CLI_GetArgsCount), "OT_CLI_GetArgsCount");	// Get a count of key/value pairs from a string. Returns int32_t.
        theScript.chai->add(fun(&OT_CLI_GetValueByKey), "OT_CLI_GetValueByKey");	// Returns a VALUE as string, BY KEY, from a map of key/value pairs (stored in a string.)
        theScript.chai->add(fun(&OT_CLI_GetValueByIndex), "OT_CLI_GetValueByIndex");	// Returns a VALUE as string, BY INDEX, from a map of key/value pairs (stored in a string.)
        theScript.chai->add(fun(&OT_CLI_GetKeyByIndex), "OT_CLI_GetKeyByIndex");	// Returns a KEY as string, BY INDEX, from a map of key/value pairs (stored in a string.)
        return true; // Success (hopefully!)
    }
}



//bool OT_ME::Register_API_With_Script_Lua(OTScriptLua & theScript)

bool OT_ME::Register_API_With_Script_Chai(OTScriptChai & theScript)
{
    using namespace chaiscript;
    {
        theScript.chai->add(fun(&OTAPI_Wrap::Output), "OT_API_Output");
        theScript.chai->add(fun(&OTAPI_Wrap::GetTime), "OT_API_GetTime");


        theScript.chai->add(fun(&OTAPI_Wrap::NumList_Add), "OT_API_NumList_Add");
        theScript.chai->add(fun(&OTAPI_Wrap::NumList_Remove), "OT_API_NumList_Remove");
        theScript.chai->add(fun(&OTAPI_Wrap::NumList_VerifyQuery), "OT_API_NumList_VerifyQuery");
        theScript.chai->add(fun(&OTAPI_Wrap::NumList_VerifyAll), "OT_API_NumList_VerifyAll");
        theScript.chai->add(fun(&OTAPI_Wrap::NumList_Count), "OT_API_NumList_Count");


        theScript.chai->add(fun(&OTAPI_Wrap::Encode), "OT_API_Encode");
        theScript.chai->add(fun(&OTAPI_Wrap::Decode), "OT_API_Decode");
        theScript.chai->add(fun(&OTAPI_Wrap::Encrypt), "OT_API_Encrypt");
        theScript.chai->add(fun(&OTAPI_Wrap::Decrypt), "OT_API_Decrypt");


        theScript.chai->add(fun(&OTAPI_Wrap::CreateSymmetricKey), "OT_API_CreateSymmetricKey");
        theScript.chai->add(fun(&OTAPI_Wrap::SymmetricEncrypt), "OT_API_SymmetricEncrypt");
        theScript.chai->add(fun(&OTAPI_Wrap::SymmetricDecrypt), "OT_API_SymmetricDecrypt");
        theScript.chai->add(fun(&OTAPI_Wrap::CreateServerContract), "OT_API_CreateServerContract");
        theScript.chai->add(fun(&OTAPI_Wrap::CreateAssetContract), "OT_API_CreateAssetContract");
        theScript.chai->add(fun(&OTAPI_Wrap::GetServer_Contract), "OT_API_GetServer_Contract");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAssetType_Contract), "OT_API_GetAssetType_Contract");

        theScript.chai->add(fun(&OTAPI_Wrap::FormatAmount), "OT_API_FormatAmount");
        theScript.chai->add(fun(&OTAPI_Wrap::StringToAmount), "OT_API_StringToAmount");


        theScript.chai->add(fun(&OTAPI_Wrap::FlatSign), "OT_API_FlatSign");
        theScript.chai->add(fun(&OTAPI_Wrap::SignContract), "OT_API_SignContract");
        theScript.chai->add(fun(&OTAPI_Wrap::AddSignature), "OT_API_AddSignature");
        theScript.chai->add(fun(&OTAPI_Wrap::VerifySignature), "OT_API_VerifySignature");

        theScript.chai->add(fun(&OTAPI_Wrap::CreateNym), "OT_API_CreateNym");

        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_ActiveCronItemIDs), "OT_API_GetNym_ActiveCronItemIDs");
        theScript.chai->add(fun(&OTAPI_Wrap::GetActiveCronItem), "OT_API_GetActiveCronItem");

        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_SourceForID), "OT_API_GetNym_SourceForID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_AltSourceLocation), "OT_API_GetNym_AltSourceLocation");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_CredentialCount), "OT_API_GetNym_CredentialCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_CredentialID), "OT_API_GetNym_CredentialID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_CredentialContents), "OT_API_GetNym_CredentialContents");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_RevokedCredCount), "OT_API_GetNym_RevokedCredCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_RevokedCredID), "OT_API_GetNym_RevokedCredID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_RevokedCredContents), "OT_API_GetNym_RevokedCredContents");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_SubcredentialCount), "OT_API_GetNym_SubcredentialCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_SubCredentialID), "OT_API_GetNym_SubCredentialID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_SubCredentialContents), "OT_API_GetNym_SubCredentialContents");

        theScript.chai->add(fun(&OTAPI_Wrap::AddSubcredential), "OT_API_AddSubcredential");
        theScript.chai->add(fun(&OTAPI_Wrap::RevokeSubcredential), "OT_API_RevokeSubcredential");

        theScript.chai->add(fun(&OTAPI_Wrap::AddServerContract), "OT_API_AddServerContract");
        theScript.chai->add(fun(&OTAPI_Wrap::AddAssetContract), "OT_API_AddAssetContract");
        theScript.chai->add(fun(&OTAPI_Wrap::GetServerCount), "OT_API_GetServerCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAssetTypeCount), "OT_API_GetAssetTypeCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountCount), "OT_API_GetAccountCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNymCount), "OT_API_GetNymCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetServer_ID), "OT_API_GetServer_ID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetServer_Name), "OT_API_GetServer_Name");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAssetType_ID), "OT_API_GetAssetType_ID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAssetType_Name), "OT_API_GetAssetType_Name");

        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountWallet_ID), "OT_API_GetAccountWallet_ID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountWallet_Name), "OT_API_GetAccountWallet_Name");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountWallet_Balance), "OT_API_GetAccountWallet_Balance");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountWallet_Type), "OT_API_GetAccountWallet_Type");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountWallet_AssetTypeID), "OT_API_GetAccountWallet_AssetTypeID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountWallet_ServerID), "OT_API_GetAccountWallet_ServerID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountWallet_NymID), "OT_API_GetAccountWallet_NymID");

        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountWallet_InboxHash), "OT_API_GetAccountWallet_InboxHash");
        theScript.chai->add(fun(&OTAPI_Wrap::GetAccountWallet_OutboxHash), "OT_API_GetAccountWallet_OutboxHash");

        theScript.chai->add(fun(&OTAPI_Wrap::VerifyAccountReceipt), "OT_API_VerifyAccountReceipt");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_TransactionNumCount), "OT_API_GetNym_TransactionNumCount");

        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_ID), "OT_API_GetNym_ID");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_Name), "OT_API_GetNym_Name");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_Stats), "OT_API_GetNym_Stats");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_NymboxHash), "OT_API_GetNym_NymboxHash");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_RecentHash), "OT_API_GetNym_RecentHash");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_InboxHash), "OT_API_GetNym_InboxHash");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_OutboxHash), "OT_API_GetNym_OutboxHash");

        theScript.chai->add(fun(&OTAPI_Wrap::IsNym_RegisteredAtServer), "OT_API_IsNym_RegisteredAtServer");

        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_MailCount), "OT_API_GetNym_MailCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_MailContentsByIndex), "OT_API_GetNym_MailContentsByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_MailSenderIDByIndex), "OT_API_GetNym_MailSenderIDByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_MailServerIDByIndex), "OT_API_GetNym_MailServerIDByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Nym_RemoveMailByIndex), "OT_API_Nym_RemoveMailByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Nym_VerifyMailByIndex), "OT_API_Nym_VerifyMailByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_OutmailCount), "OT_API_GetNym_OutmailCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_OutmailContentsByIndex), "OT_API_GetNym_OutmailContentsByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_OutmailRecipientIDByIndex), "OT_API_GetNym_OutmailRecipientIDByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_OutmailServerIDByIndex), "OT_API_GetNym_OutmailServerIDByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Nym_RemoveOutmailByIndex), "OT_API_Nym_RemoveOutmailByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Nym_VerifyOutmailByIndex), "OT_API_Nym_VerifyOutmailByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_OutpaymentsCount), "OT_API_GetNym_OutpaymentsCount");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_OutpaymentsContentsByIndex), "OT_API_GetNym_OutpaymentsContentsByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_OutpaymentsRecipientIDByIndex), "OT_API_GetNym_OutpaymentsRecipientIDByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::GetNym_OutpaymentsServerIDByIndex), "OT_API_GetNym_OutpaymentsServerIDByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Nym_RemoveOutpaymentsByIndex), "OT_API_Nym_RemoveOutpaymentsByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Nym_VerifyOutpaymentsByIndex), "OT_API_Nym_VerifyOutpaymentsByIndex");

        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_CanRemoveServer), "OT_API_Wallet_CanRemoveServer");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_RemoveServer), "OT_API_Wallet_RemoveServer");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_CanRemoveAssetType), "OT_API_Wallet_CanRemoveAssetType");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_RemoveAssetType), "OT_API_Wallet_RemoveAssetType");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_CanRemoveNym), "OT_API_Wallet_CanRemoveNym");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_RemoveNym), "OT_API_Wallet_RemoveNym");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_CanRemoveAccount), "OT_API_Wallet_CanRemoveAccount");


        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_ChangePassphrase), "OT_API_Wallet_ChangePassphrase");

        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_ExportNym), "OT_API_Wallet_ExportNym");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_ImportNym), "OT_API_Wallet_ImportNym");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_ImportCert), "OT_API_Wallet_ImportCert");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_ExportCert), "OT_API_Wallet_ExportCert");


        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_GetNymIDFromPartial), "OT_API_Wallet_GetNymIDFromPartial");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_GetServerIDFromPartial), "OT_API_Wallet_GetServerIDFromPartial");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_GetAssetIDFromPartial), "OT_API_Wallet_GetAssetIDFromPartial");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_GetAccountIDFromPartial), "OT_API_Wallet_GetAccountIDFromPartial");


        theScript.chai->add(fun(&OTAPI_Wrap::SetNym_Name), "OT_API_SetNym_Name");
        theScript.chai->add(fun(&OTAPI_Wrap::SetAccountWallet_Name), "OT_API_SetAccountWallet_Name");
        theScript.chai->add(fun(&OTAPI_Wrap::SetAssetType_Name), "OT_API_SetAssetType_Name");
        theScript.chai->add(fun(&OTAPI_Wrap::SetServer_Name), "OT_API_SetServer_Name");

        theScript.chai->add(fun(&OTAPI_Wrap::VerifyAndRetrieveXMLContents), "OT_API_VerifyAndRetrieveXMLContents");
        theScript.chai->add(fun(&OTAPI_Wrap::WriteCheque), "OT_API_WriteCheque");
        theScript.chai->add(fun(&OTAPI_Wrap::DiscardCheque), "OT_API_DiscardCheque");
        theScript.chai->add(fun(&OTAPI_Wrap::EasyProposePlan), "OT_API_EasyProposePlan");
        theScript.chai->add(fun(&OTAPI_Wrap::ConfirmPaymentPlan), "OT_API_ConfirmPaymentPlan");

        theScript.chai->add(fun(&OTAPI_Wrap::LoadUserPubkey_Encryption), "OT_API_LoadUserPubkey_Encryption");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadPubkey_Encryption), "OT_API_LoadPubkey_Encryption");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadUserPubkey_Signing), "OT_API_LoadUserPubkey_Signing");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadPubkey_Signing), "OT_API_LoadPubkey_Signing");
        theScript.chai->add(fun(&OTAPI_Wrap::VerifyUserPrivateKey), "OT_API_VerifyUserPrivateKey");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadPurse), "OT_API_LoadPurse");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadMint), "OT_API_LoadMint");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadAssetContract), "OT_API_LoadAssetContract");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadServerContract), "OT_API_LoadServerContract");
        theScript.chai->add(fun(&OTAPI_Wrap::Mint_IsStillGood), "OT_API_Mint_IsStillGood");

        theScript.chai->add(fun(&OTAPI_Wrap::IsBasketCurrency), "OT_API_IsBasketCurrency");
        theScript.chai->add(fun(&OTAPI_Wrap::Basket_GetMemberCount), "OT_API_Basket_GetMemberCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Basket_GetMemberType), "OT_API_Basket_GetMemberType");
        theScript.chai->add(fun(&OTAPI_Wrap::Basket_GetMinimumTransferAmount), "OT_API_Basket_GetMinimumTransferAmount");
        theScript.chai->add(fun(&OTAPI_Wrap::Basket_GetMemberMinimumTransferAmount), "OT_API_Basket_GetMemberMinimumTransferAmount");

        theScript.chai->add(fun(&OTAPI_Wrap::LoadAssetAccount), "OT_API_LoadAssetAccount");

        theScript.chai->add(fun(&OTAPI_Wrap::LoadInbox), "OT_API_LoadInbox");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadOutbox), "OT_API_LoadOutbox");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadPaymentInbox), "OT_API_LoadPaymentInbox");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadRecordBox), "OT_API_LoadRecordBox");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadExpiredBox), "OT_API_LoadExpiredBox");

        theScript.chai->add(fun(&OTAPI_Wrap::LoadInboxNoVerify), "OT_API_LoadInboxNoVerify");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadOutboxNoVerify), "OT_API_LoadOutboxNoVerify");

        theScript.chai->add(fun(&OTAPI_Wrap::LoadPaymentInboxNoVerify), "OT_API_LoadPaymentInboxNoVerify");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadRecordBoxNoVerify), "OT_API_LoadRecordBoxNoVerify");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadExpiredBoxNoVerify), "OT_API_LoadExpiredBoxNoVerify");

        theScript.chai->add(fun(&OTAPI_Wrap::Ledger_GetCount), "OT_API_Ledger_GetCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Ledger_CreateResponse), "OT_API_Ledger_CreateResponse");
        theScript.chai->add(fun(&OTAPI_Wrap::Ledger_GetTransactionByIndex), "OT_API_Ledger_GetTransactionByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Ledger_GetTransactionByID), "OT_API_Ledger_GetTransactionByID");
        theScript.chai->add(fun(&OTAPI_Wrap::Ledger_GetTransactionIDByIndex), "OT_API_Ledger_GetTransactionIDByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Ledger_GetInstrument), "OT_API_Ledger_GetInstrument");

        theScript.chai->add(fun(&OTAPI_Wrap::Ledger_AddTransaction), "OT_API_Ledger_AddTransaction");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_CreateResponse), "OT_API_Transaction_CreateResponse");
        theScript.chai->add(fun(&OTAPI_Wrap::Ledger_FinalizeResponse), "OT_API_Ledger_FinalizeResponse");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetType), "OT_API_Transaction_GetType");

        theScript.chai->add(fun(&OTAPI_Wrap::RecordPayment), "OT_API_RecordPayment");
        theScript.chai->add(fun(&OTAPI_Wrap::ClearRecord), "OT_API_ClearRecord");
        theScript.chai->add(fun(&OTAPI_Wrap::ClearExpired), "OT_API_ExpiredRecord");

        theScript.chai->add(fun(&OTAPI_Wrap::ReplyNotice_GetRequestNum), "OT_API_ReplyNotice_GetRequestNum");

        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetVoucher), "OT_API_Transaction_GetVoucher");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetSuccess), "OT_API_Transaction_GetSuccess");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_IsCanceled), "OT_API_Transaction_IsCanceled");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetBalanceAgreementSuccess), "OT_API_Transaction_GetBlnceAgrmntSuccess");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetDateSigned), "OT_API_Transaction_GetDateSigned");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetAmount), "OT_API_Transaction_GetAmount");
        theScript.chai->add(fun(&OTAPI_Wrap::Pending_GetNote), "OT_API_Pending_GetNote");

        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetSenderUserID), "OT_API_Transaction_GetSenderUserID");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetSenderAcctID), "OT_API_Transaction_GetSenderAcctID");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetRecipientUserID), "OT_API_Transaction_GetRecipientUserID");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetRecipientAcctID), "OT_API_Transaction_GetRecipientAcctID");
        theScript.chai->add(fun(&OTAPI_Wrap::Transaction_GetDisplayReferenceToNum), "OT_API_Transaction_GetDisplayReferenceToNum");

        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetAmount), "OT_API_Instrmnt_GetAmount");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetTransNum), "OT_API_Instrmnt_GetTransNum");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetValidFrom), "OT_API_Instrmnt_GetValidFrom");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetValidTo), "OT_API_Instrmnt_GetValidTo");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetMemo), "OT_API_Instrmnt_GetMemo");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetType), "OT_API_Instrmnt_GetType");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetServerID), "OT_API_Instrmnt_GetServerID");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetAssetID), "OT_API_Instrmnt_GetAssetID");

        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetSenderUserID), "OT_API_Instrmnt_GetSenderUserID");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetSenderAcctID), "OT_API_Instrmnt_GetSenderAcctID");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetRemitterUserID), "OT_API_Instrmnt_GetRemitterUserID");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetRemitterAcctID), "OT_API_Instrmnt_GetRemitterAcctID");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetRecipientUserID), "OT_API_Instrmnt_GetRecipientUserID");
        theScript.chai->add(fun(&OTAPI_Wrap::Instrmnt_GetRecipientAcctID), "OT_API_Instrmnt_GetRecipientAcctID");

        theScript.chai->add(fun(&OTAPI_Wrap::CreatePurse), "OT_API_CreatePurse");
        theScript.chai->add(fun(&OTAPI_Wrap::CreatePurse_Passphrase), "OT_API_CreatePurse_Passphrase");
        theScript.chai->add(fun(&OTAPI_Wrap::SavePurse), "OT_API_SavePurse");
        theScript.chai->add(fun(&OTAPI_Wrap::Purse_GetTotalValue), "OT_API_Purse_GetTotalValue");
        theScript.chai->add(fun(&OTAPI_Wrap::Purse_HasPassword), "OT_API_Purse_HasPassword");
        theScript.chai->add(fun(&OTAPI_Wrap::Purse_Count), "OT_API_Purse_Count");
        theScript.chai->add(fun(&OTAPI_Wrap::Purse_Peek), "OT_API_Purse_Peek");
        theScript.chai->add(fun(&OTAPI_Wrap::Purse_Pop), "OT_API_Purse_Pop");
        theScript.chai->add(fun(&OTAPI_Wrap::Purse_Empty), "OT_API_Purse_Empty");
        theScript.chai->add(fun(&OTAPI_Wrap::Purse_Push), "OT_API_Purse_Push");
        theScript.chai->add(fun(&OTAPI_Wrap::Wallet_ImportPurse), "OT_API_Wallet_ImportPurse");
        theScript.chai->add(fun(&OTAPI_Wrap::exchangePurse), "OT_API_exchangePurse");
        theScript.chai->add(fun(&OTAPI_Wrap::Token_ChangeOwner), "OT_API_Token_ChangeOwner");

        theScript.chai->add(fun(&OTAPI_Wrap::Token_GetID), "OT_API_Token_GetID");
        theScript.chai->add(fun(&OTAPI_Wrap::Token_GetDenomination), "OT_API_Token_GetDenomination");
        theScript.chai->add(fun(&OTAPI_Wrap::Token_GetSeries), "OT_API_Token_GetSeries");
        theScript.chai->add(fun(&OTAPI_Wrap::Token_GetValidFrom), "OT_API_Token_GetValidFrom");
        theScript.chai->add(fun(&OTAPI_Wrap::Token_GetValidTo), "OT_API_Token_GetValidTo");
        theScript.chai->add(fun(&OTAPI_Wrap::Token_GetAssetID), "OT_API_Token_GetAssetID");
        theScript.chai->add(fun(&OTAPI_Wrap::Token_GetServerID), "OT_API_Token_GetServerID");

        theScript.chai->add(fun(&OTAPI_Wrap::checkServerID), "OT_API_checkServerID");
        theScript.chai->add(fun(&OTAPI_Wrap::createUserAccount), "OT_API_createUserAccount");
        theScript.chai->add(fun(&OTAPI_Wrap::deleteUserAccount), "OT_API_deleteUserAccount");
        theScript.chai->add(fun(&OTAPI_Wrap::deleteAssetAccount), "OT_API_deleteAssetAccount");
        theScript.chai->add(fun(&OTAPI_Wrap::checkUser), "OT_API_checkUser");
        theScript.chai->add(fun(&OTAPI_Wrap::usageCredits), "OT_API_usageCredits");
        theScript.chai->add(fun(&OTAPI_Wrap::sendUserMessage), "OT_API_sendUserMessage");
        theScript.chai->add(fun(&OTAPI_Wrap::sendUserInstrument), "OT_API_sendUserInstrument");

        theScript.chai->add(fun(&OTAPI_Wrap::getRequest), "OT_API_getRequest");
        theScript.chai->add(fun(&OTAPI_Wrap::getTransactionNumber), "OT_API_getTransactionNumber");
        theScript.chai->add(fun(&OTAPI_Wrap::issueAssetType), "OT_API_issueAssetType");
        theScript.chai->add(fun(&OTAPI_Wrap::getContract), "OT_API_getContract");
        theScript.chai->add(fun(&OTAPI_Wrap::getMint), "OT_API_getMint");
        theScript.chai->add(fun(&OTAPI_Wrap::createAssetAccount), "OT_API_createAssetAccount");
        theScript.chai->add(fun(&OTAPI_Wrap::getAccount), "OT_API_getAccount"); // Deprecated
        theScript.chai->add(fun(&OTAPI_Wrap::getAccountFiles), "OT_API_getAccountFiles"); // Replaces getAccount, getInbox, getOutbox.
        theScript.chai->add(fun(&OTAPI_Wrap::GenerateBasketCreation), "OT_API_GenerateBasketCreation");

        theScript.chai->add(fun(&OTAPI_Wrap::AddBasketCreationItem), "OT_API_AddBasketCreationItem");
        theScript.chai->add(fun(&OTAPI_Wrap::issueBasket), "OT_API_issueBasket");
        theScript.chai->add(fun(&OTAPI_Wrap::GenerateBasketExchange), "OT_API_GenerateBasketExchange");
        theScript.chai->add(fun(&OTAPI_Wrap::AddBasketExchangeItem), "OT_API_AddBasketExchangeItem");
        theScript.chai->add(fun(&OTAPI_Wrap::exchangeBasket), "OT_API_exchangeBasket");
        theScript.chai->add(fun(&OTAPI_Wrap::notarizeWithdrawal), "OT_API_notarizeWithdrawal");
        theScript.chai->add(fun(&OTAPI_Wrap::notarizeDeposit), "OT_API_notarizeDeposit");
        theScript.chai->add(fun(&OTAPI_Wrap::notarizeTransfer), "OT_API_notarizeTransfer");

        theScript.chai->add(fun(&OTAPI_Wrap::getInbox), "OT_API_getInbox"); // Deprecated
        theScript.chai->add(fun(&OTAPI_Wrap::getOutbox), "OT_API_getOutbox"); // Deprecated
        theScript.chai->add(fun(&OTAPI_Wrap::getNymbox), "OT_API_getNymbox");

        theScript.chai->add(fun(&OTAPI_Wrap::Nymbox_GetReplyNotice), "OT_API_Nymbox_GetReplyNotice");

        theScript.chai->add(fun(&OTAPI_Wrap::getBoxReceipt), "OT_API_getBoxReceipt");
        theScript.chai->add(fun(&OTAPI_Wrap::DoesBoxReceiptExist), "OT_API_DoesBoxReceiptExist");

        theScript.chai->add(fun(&OTAPI_Wrap::LoadNymbox), "OT_API_LoadNymbox");
        theScript.chai->add(fun(&OTAPI_Wrap::LoadNymboxNoVerify), "OT_API_LoadNymboxNoVerify");

        theScript.chai->add(fun(&OTAPI_Wrap::processInbox), "OT_API_processInbox");
        theScript.chai->add(fun(&OTAPI_Wrap::processNymbox), "OT_API_processNymbox");
        theScript.chai->add(fun(&OTAPI_Wrap::withdrawVoucher), "OT_API_withdrawVoucher");
        theScript.chai->add(fun(&OTAPI_Wrap::payDividend), "OT_API_payDividend");

        theScript.chai->add(fun(&OTAPI_Wrap::depositCheque), "OT_API_depositCheque");
        theScript.chai->add(fun(&OTAPI_Wrap::depositPaymentPlan), "OT_API_depositPaymentPlan");
        theScript.chai->add(fun(&OTAPI_Wrap::issueMarketOffer), "OT_API_issueMarketOffer");
        theScript.chai->add(fun(&OTAPI_Wrap::getMarketList), "OT_API_getMarketList");
        theScript.chai->add(fun(&OTAPI_Wrap::getMarketOffers), "OT_API_getMarketOffers");
        theScript.chai->add(fun(&OTAPI_Wrap::getMarketRecentTrades), "OT_API_getMarketRecentTrades");
        theScript.chai->add(fun(&OTAPI_Wrap::getNym_MarketOffers), "OT_API_getNym_MarketOffers");
        theScript.chai->add(fun(&OTAPI_Wrap::killMarketOffer), "OT_API_killMarketOffer");
        theScript.chai->add(fun(&OTAPI_Wrap::killPaymentPlan), "OT_API_killPaymentPlan");

        theScript.chai->add(fun(&OTAPI_Wrap::PopMessageBuffer), "OT_API_PopMessageBuffer");
        theScript.chai->add(fun(&OTAPI_Wrap::FlushMessageBuffer), "OT_API_FlushMessageBuffer");

        theScript.chai->add(fun(&OTAPI_Wrap::GetSentMessage), "OT_API_GetSentMessage");
        theScript.chai->add(fun(&OTAPI_Wrap::RemoveSentMessage), "OT_API_RemoveSentMessage");
        theScript.chai->add(fun(&OTAPI_Wrap::FlushSentMessages), "OT_API_FlushSentMessages");

        theScript.chai->add(fun(&OTAPI_Wrap::HaveAlreadySeenReply), "OT_API_HaveAlreadySeenReply");

        theScript.chai->add(fun(&OTAPI_Wrap::Sleep), "OT_API_Sleep");

        theScript.chai->add(fun(&OTAPI_Wrap::ResyncNymWithServer), "OT_API_ResyncNymWithServer");

        theScript.chai->add(fun(&OTAPI_Wrap::queryAssetTypes), "OT_API_queryAssetTypes");

        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetPayload), "OT_API_Message_GetPayload");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetCommand), "OT_API_Message_GetCommand");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetSuccess), "OT_API_Message_GetSuccess");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetDepth), "OT_API_Message_GetDepth");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetUsageCredits), "OT_API_Message_GetUsageCredits");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetTransactionSuccess), "OT_API_Msg_GetTransactionSuccess");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_IsTransactionCanceled), "OT_API_Msg_IsTransactionCanceled");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetBalanceAgreementSuccess), "OT_API_Msg_GetBlnceAgrmntSuccess");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetLedger), "OT_API_Message_GetLedger");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetNewAssetTypeID), "OT_API_Message_GetNewAssetTypeID");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetNewIssuerAcctID), "OT_API_Message_GetNewIssuerAcctID");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetNewAcctID), "OT_API_Message_GetNewAcctID");
        theScript.chai->add(fun(&OTAPI_Wrap::Message_GetNymboxHash), "OT_API_Message_GetNymboxHash");

        theScript.chai->add(fun(&OTAPI_Wrap::Create_SmartContract), "OT_API_Create_SmartContract");

        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_AddBylaw), "OT_API_SmartContract_AddBylaw");
        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_AddClause), "OT_API_SmartContract_AddClause");
        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_AddVariable), "OT_API_SmartContract_AddVariable");
        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_AddCallback), "OT_API_SmartContract_AddCallback");
        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_AddHook), "OT_API_SmartContract_AddHook");

        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_AddParty), "OT_API_SmartContract_AddParty");
        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_AddAccount), "OT_API_SmartContract_AddAccount");

        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_ConfirmAccount), "OT_API_SmartContract_ConfirmAccount");
        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_ConfirmParty), "OT_API_SmartContract_ConfirmParty");

        theScript.chai->add(fun(&OTAPI_Wrap::SmartContract_CountNumsNeeded), "OT_API_SmartContract_CountNumsNeeded");

        theScript.chai->add(fun(&OTAPI_Wrap::Msg_HarvestTransactionNumbers), "OT_API_Msg_HarvestTransactionNumbers");

//		theScript.chai->add(fun(&OTAPI_Wrap::HarvestClosingNumbers), "OT_API_HarvestClosingNumbers");
//		theScript.chai->add(fun(&OTAPI_Wrap::HarvestAllNumbers), "OT_API_HarvestAllNumbers");

        theScript.chai->add(fun(&OTAPI_Wrap::Smart_AreAllPartiesConfirmed), "OT_API_Smart_AreAllPartiesConfirmed");
        theScript.chai->add(fun(&OTAPI_Wrap::Smart_IsPartyConfirmed), "OT_API_Smart_IsPartyConfirmed");
        theScript.chai->add(fun(&OTAPI_Wrap::Smart_GetBylawCount), "OT_API_Smart_GetBylawCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Smart_GetBylawByIndex), "OT_API_Smart_GetBylawByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Bylaw_GetLanguage), "OT_API_Bylaw_GetLanguage");
        theScript.chai->add(fun(&OTAPI_Wrap::Bylaw_GetClauseCount), "OT_API_Bylaw_GetClauseCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Clause_GetNameByIndex), "OT_API_Clause_GetNameByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Clause_GetContents), "OT_API_Clause_GetContents");
        theScript.chai->add(fun(&OTAPI_Wrap::Bylaw_GetVariableCount), "OT_API_Bylaw_GetVariableCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Variable_GetNameByIndex), "OT_API_Variable_GetNameByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Variable_GetType), "OT_API_Variable_GetType");
        theScript.chai->add(fun(&OTAPI_Wrap::Variable_GetAccess), "OT_API_Variable_GetAccess");
        theScript.chai->add(fun(&OTAPI_Wrap::Variable_GetContents), "OT_API_Variable_GetContents");
        theScript.chai->add(fun(&OTAPI_Wrap::Bylaw_GetHookCount), "OT_API_Bylaw_GetHookCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Hook_GetNameByIndex), "OT_API_Hook_GetNameByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Hook_GetClauseCount), "OT_API_Hook_GetClauseCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Hook_GetClauseAtIndex), "OT_API_Hook_GetClauseAtIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Bylaw_GetCallbackCount), "OT_API_Bylaw_GetCallbackCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Callback_GetNameByIndex), "OT_API_Callback_GetNameByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Callback_GetClause), "OT_API_Callback_GetClause");
        theScript.chai->add(fun(&OTAPI_Wrap::Smart_GetPartyCount), "OT_API_Smart_GetPartyCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Smart_GetPartyByIndex), "OT_API_Smart_GetPartyByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Party_GetID), "OT_API_Party_GetID");
        theScript.chai->add(fun(&OTAPI_Wrap::Party_GetAcctCount), "OT_API_Party_GetAcctCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Party_GetAcctNameByIndex), "OT_API_Party_GetAcctNameByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Party_GetAcctID), "OT_API_Party_GetAcctID");
        theScript.chai->add(fun(&OTAPI_Wrap::Party_GetAcctAssetID), "OT_API_Party_GetAcctAssetID");
        theScript.chai->add(fun(&OTAPI_Wrap::Party_GetAcctAgentName), "OT_API_Party_GetAcctAgentName");
        theScript.chai->add(fun(&OTAPI_Wrap::Party_GetAgentCount), "OT_API_Party_GetAgentCount");
        theScript.chai->add(fun(&OTAPI_Wrap::Party_GetAgentNameByIndex), "OT_API_Party_GetAgentNameByIndex");
        theScript.chai->add(fun(&OTAPI_Wrap::Party_GetAgentID), "OT_API_Party_GetAgentID");

        theScript.chai->add(fun(&OTAPI_Wrap::activateSmartContract), "OT_API_activateSmartContract");
        theScript.chai->add(fun(&OTAPI_Wrap::triggerClause), "OT_API_triggerClause");

        // ******************************************************************

        return true; // Success (hopefully!)
    }
}

#endif // OT_USE_SCRIPT_CHAI


// ********************************************************************

// Used in RegisterAPIWithScript.
// (In D, this would be a nested function, but C++ doesn't support that
// without using a nested class as a kludge.)
//
bool NewScriptExists(const OTString & strScriptFilename, bool bIsHeader, OTString & out_ScriptFilepath)
{
    //            
    // "so $(prefix)/lib/opentxs for the headers, 
    // and others:
    // 1st priorty: $(data_dir)/scripts
    // 2nd priorty: $(prefix)/lib/opentxs/scripts
    //
    int64_t lFileLength(0);

    OT_ASSERT_MSG(strScriptFilename.Exists(), "NewScriptHeaderExists: Error! Filename not Supplied!");
    if (3 > strScriptFilename.GetLength())
    {
        OTLog::vError("NewScriptHeaderExists: Filename: %s  is too short!\n", strScriptFilename.Get());
        OT_FAIL;
    }

    OTString strScriptsFolder(OTPaths::ScriptsFolder()); //	/usr/local / lib / opentxs  OR (android) res/raw
    { bool bGetFolderSuccess = strScriptsFolder.Exists() && 3 < strScriptsFolder.GetLength();
    OT_ASSERT_MSG(bGetFolderSuccess, "NewScriptHeaderExists: Unalbe to Get Scripts Path"); }

    if (bIsHeader) {

        { bool bBuildFullPathSuccess = OTPaths::AppendFile(out_ScriptFilepath, strScriptsFolder, strScriptFilename);
        OT_ASSERT_MSG(bBuildFullPathSuccess, "NewScriptHeaderExists: Unalbe to Build Full Script Path"); }

        return OTPaths::FileExists(out_ScriptFilepath, lFileLength);
    }
    else {
        OTString strDataFolder(OTDataFolder::Get()), strDataScriptsFolder;

        { bool bGetFolderSuccess = strDataFolder.Exists() && 3 < strDataFolder.GetLength();
        OT_ASSERT_MSG(bGetFolderSuccess, "NewScriptHeaderExists: Unalbe to Get Scripts Path"); }

        { bool bBuildScriptPath = OTPaths::RelativeToCanonical(strDataScriptsFolder, strDataFolder, "scripts");
        OT_ASSERT_MSG(bBuildScriptPath, "NewScriptHeaderExists: Unalbe to Build Full Script Path"); }

        { bool bBuildFullPathSuccess = OTPaths::RelativeToCanonical(out_ScriptFilepath, strDataScriptsFolder, strScriptFilename);
        OT_ASSERT_MSG(bBuildFullPathSuccess, "NewScriptHeaderExists: Unalbe to Build Full Script Path"); }

        if (OTPaths::FileExists(out_ScriptFilepath, lFileLength)) return true;
        else {
            OTString strGlobalScriptsFolder;

            { bool bBuildScriptPath = OTPaths::RelativeToCanonical(strGlobalScriptsFolder, strScriptsFolder, "scripts");
            OT_ASSERT_MSG(bBuildScriptPath, "NewScriptHeaderExists: Unalbe to Build Full Script Path"); }
            { bool bBuildFullPathSuccess = OTPaths::RelativeToCanonical(out_ScriptFilepath, strGlobalScriptsFolder, strScriptFilename);
            OT_ASSERT_MSG(bBuildFullPathSuccess, "NewScriptHeaderExists: Unalbe to Build Full Script Path"); }

            return OTPaths::FileExists(out_ScriptFilepath, lFileLength);
        }
    }
}


#ifdef OT_USE_SCRIPT_CHAI

//bool OT_ME::Register_Headers_With_Script_Lua(OTScriptLua & theScript)

// Note: Private method. Assumes theScript is m_pScript (but now as
// a specific type, aka OTScriptChai, vs just being an OTScript.)
//
bool OT_ME::Register_Headers_With_Script_Chai(OTScriptChai & theScript)
{
    using namespace chaiscript;
    {
        /// What does it do?  First, ot_utility.ot adds some much-needed utility functions for
        /// commonly repeated actions while using the OTAPI, such as for grabbing the request
        /// number, syncing the transaction number, sending a request or a transaction to a
        /// server, etc. Next, a higher layer is added in otapi.ot, which uses a functor to
        /// provide a much simpler interface to all of the use cases of OT. Meaning, if you
        /// want to withdraw some cash, or put an offer on a market, you don't have to deal
        /// with timeouts, retries, flushing the message buffer, popping the server reply after
        /// a set delay, blah blah blah. Instead, you just invoke a single functor call, and
        /// it returns either a string containing the server's reply, or null.
        /// Finally, an ULTRA-HIGH LEVEL interface is added on top of that, in ot_made_easy.ot
        /// which aims to provide one-call interfaces for an entire script-based OT client.
        /// (Whereas otapi.ot offers one-call interfaces to all of the OTAPI server messages
        /// and transaction requests, ot_made_easy.ot then USES that in order to provide a
        /// one-call interface of a real client who sends such messages and makes such requests.
        /// FOR EXAMPLE:  otapi might have a "Withdraw Cash" function which handles the entire
        /// message and returns the server's response. Whereas ot_made_easy would have the complete
        /// implementation, in script form, of an actual OT client that USES that "Withdraw Cash"
        /// message, along with manipulating its own local purse, pulling coins off or pushing them
        /// on based on transfers from other users, etc etc etc.  Just like Moneychanger uses
        /// the OTAPI_Func, so does the ot_made_easy class use the OTAPI_Func. Therefore ot_made_easy
        /// is aiming to be a script-based replacement for Moneychanger itself. It is the GUI.
        /// The Client.
        // There were many path problems with including these scripts inside the user scripts,
        // so I am forcing the issue here, to keep things clean. This way, the entire OT API,
        // both the C++ functions, as well as the below script functions, grows together as one
        // and will be seen as one from inside the scripts, where script programmers can
        // pick and choose which level of abstraction that they need.
        // 
        // ******************************************************************
        //
        //  SCRIPT HEADERS
        //
 
        OTLog::vOutput(1, "\n%s: Using Script Headers:\n", __FUNCTION__);

        OTString strHeaderFilePath_01;
        if (NewScriptExists("ot_utility.ot", true, strHeaderFilePath_01)) { OTLog::vOutput(1, " %s\n", strHeaderFilePath_01.Get()); }
        else { OTLog::vError("%s: Header script not found: %s\n", __FUNCTION__, strHeaderFilePath_01.Get()); return false; }

        OTString strHeaderFilePath_02;
        if (NewScriptExists("otapi.ot", true, strHeaderFilePath_02)) { OTLog::vOutput(1, " %s\n", strHeaderFilePath_02.Get()); }
        else { OTLog::vError("%s: Header script not found: %s\n", __FUNCTION__, strHeaderFilePath_02.Get()); return false; }

#if USE_OLD_CHAISCRIPT == 1
        OTString strHeaderFilePath_03;
        if (NewScriptExists("ot_made_easy.ot", true, strHeaderFilePath_03)) { OTLog::vOutput(1, " %s\n", strHeaderFilePath_03.Get()); }
        else { OTLog::vError("%s: Header script not found: %s\n", __FUNCTION__, strHeaderFilePath_03.Get()); return false; }

        OTString strHeaderFilePath_04;
        if (NewScriptExists("ot_commands.ot", true, strHeaderFilePath_04)) { OTLog::vOutput(1, " %s\n\n", strHeaderFilePath_04.Get()); }
        else { OTLog::vError("%s: Header script not found: %s\n", __FUNCTION__, strHeaderFilePath_04.Get()); return false; }
#endif

        try
        {
            theScript.chai->use(strHeaderFilePath_01.Get());
            theScript.chai->use(strHeaderFilePath_02.Get());
#if USE_OLD_CHAISCRIPT == 1
            theScript.chai->use(strHeaderFilePath_03.Get());
            theScript.chai->use(strHeaderFilePath_04.Get());
#endif
        }
        catch (const chaiscript::exception::eval_error &ee)
        {
            // Error in script parsing / execution
            OTLog::vError("%s: Caught chaiscript::exception::eval_error : %s. \n"
                "   File: %s\n"
                "   Start position, line: %d column: %d\n"
                "   End position,   line: %d column: %d\n", __FUNCTION__,
                ee.reason.c_str(), ee.filename.c_str(),
                ee.start_position.line, ee.start_position.column,
                ee.end_position.line, ee.end_position.column);

            std::cout << ee.what();
            if (ee.call_stack.size() > 0)
            {
                std::cout << "during evaluation at (" << ee.call_stack[0]->start.line << ", " << ee.call_stack[0]->start.column << ")";
            }
            std::cout << std::endl << std::endl;

            if (ee.call_stack.size() > 0)
            {
                for (size_t j = 1; j < ee.call_stack.size(); ++j) {
                    if (ee.call_stack[j]->identifier != chaiscript::AST_Node_Type::Block
                        && ee.call_stack[j]->identifier != chaiscript::AST_Node_Type::File)
                    {
                        std::cout << std::endl;
                        std::cout << "  from " << *(ee.call_stack[j]->filename) << " (" << ee.call_stack[j]->start.line << ", " << ee.call_stack[j]->start.column << ") : ";
                        std::cout << ee.call_stack[j]->text << std::endl;
                    }
                }
            }
            std::cout << std::endl;
            return false;
        }
        catch (const chaiscript::exception::bad_boxed_cast &e) {
            // Error unboxing return value
            OTLog::vError("%s: Caught chaiscript::exception::bad_boxed_cast : %s.\n", __FUNCTION__,
                (e.what() != NULL) ? e.what() : "e.what() returned null, sorry");
            return false;
        }
        catch (const std::exception &e) {
            // Error explicitly thrown from script
            OTLog::vError("%s: Caught std::exception exception: %s\n", __FUNCTION__,
                (e.what() != NULL) ? e.what() : "e.what() returned null, sorry");
            return false;
        }
        //          catch (chaiscript::Boxed_Value bv) {}
        catch (...)
        {
            OTLog::vError("%s: Caught exception.\n", __FUNCTION__);
            return false;
        }

        return true; // Success (hopefully!)
    }
}

#endif // OT_USE_SCRIPT_CHAI

} // namespace opentxs
