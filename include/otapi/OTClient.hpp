/************************************************************************************
* 
* OTClient.h
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

#ifndef __OTCLIENT_HPP__
#define __OTCLIENT_HPP__

#include "OTCommon.hpp"

#include "OTServerConnection.hpp"

#include "OTMessageOutBuffer.hpp"


namespace opentxs {

struct TransportCallback;

class OTAccount;
class OTAssetContract;
class OTLedger;
class OTMessage;
class OTPayload;
class OTPseudonym;
class OTServerContract;
class OTTransaction;
class OTWallet;


// This class represents the "test client"
//
// I have it separate from the wallet because I would like to be
// able to use the wallet in a "nice client" too, so I'm forcing
// the separation to keep it designed that way.
//

class OTClient
{
private:
	OTWallet * m_pWallet; // NOT owned, but this pointer is here for convenience.

	OTMessageBuffer     m_MessageBuffer;    // Incoming server replies are copied here for easy access.
	OTMessageOutbuffer  m_MessageOutbuffer; // Outgoing messages are copied here for easy access. 

	bool m_bRunningAsScript; // This is used to determine whether to activate certain messages automatically in
	// the client based on various server replies to previous requests (based on what mode it's being used in...
	// if we're using the API, then NO auto-messages!) Similarly, if we're using the interpreted script, then NO auto
	// messages. But if we are using the test client, aka the command line in --prompt mode, and the --script switch
	// wasn't used to startup, (which would mean we're executing a script) then it's A-Okay to fire those auto messages.

public:

	/// Any time a message is sent to the server, its request number is copied here.
	/// Most server message functions return int32_t, but technically a request number can
	/// be int64_t. So if the number being returned is too large for that int32_t, it will return
	/// -2 instead, and then another function can be called that returns lMostRecentRequestNumber
	/// in string form, or whatever is easiest.
	///
	int64_t m_lMostRecentRequestNumber;
	// ---------------------------------------------
	int32_t  CalcReturnVal(const int64_t & lRequestNumber);
	// ---------------------------------------------
	bool IsRunningAsScript() const { return m_bRunningAsScript; }
	void SetRunningAsScript()      { m_bRunningAsScript = true; } // (default is false.)
	// ------------------------
	enum OT_CLIENT_CMD_TYPE 
	{
		checkServerID, // Your public key is sent along with this message so the server can reply to 
                       // you even without your being a registered user. Other than these top two commands,
                       // all other commands can only be executed by registered users.
                       //
                       // The server ID is a hash of the server contract. The signature on the contract
                       // can be verified by a public key that appears in a standard section of any server
                       // contract. The URL/port information is also derived from the contract.
                       //
                       // Simply by importing the server contract into your wallet, you are able to connect
                       // to it and encrypt all of your communications to it.
                       //
                       // Thus, the check server ID command really just confirms what you should already know...
                       // Your wallet still wants to see that the server agrees with the server ID, and that
                       // the server is able to read messages that were encrypted to the public key in the
                       // contract, and that the server is able to sign all of its future correspondence with
                       // the same public key.
                       //
                       // It is the server operator's responsibility to secure the domain name and web host
                       // that users will connect to when they import the contract, as well as the private
                       // key that matches the public key from the contract.
		createUserAccount, // Create user account on a specific server, with public key. User ID will be hash of said public key.
		deleteUserAccount, // Delete user account from a specific server.
		checkUser, // Request a user's public key based on User ID included with the request.
                   // (If you want to send him cash or a check, your wallet will encrypt portions
                   // of the tokens, etc, to the Nym of the recipient.)
		sendUserMessage, // Send a message to another user, encrypted to his public key and dropped into his nymbox.
		getRequest, // Get the next request number from the server (for this user). Most requests must be
                    // accompanied by a request number, which increments for each Nym with each request.
		issueAssetType, // Upload a currency contract to the server and create an asset ID from a hash of that. 
		                // contract. Also creates an issuer account for that asset ID. This ONLY works if public
		                // key of the user matches the contract key found in the currency contract, AND if the
		                // contract is signed by the same key.
		createAccount,  // Create an asset account for a certain serverID, UserID, and Asset Type ID.
                        // These accounts are where users actually store their digital assets of various
		                // types. Account files are stored on user's computer, signed by notary server.
		                // Server also maintains its own copy. Users can create an unlimited number of accounts
		                // for any asset type that they choose.
		issueBasket, // Create a basket account, which is like an issuer account, but based on a basket of 
                     // other asset types. This way, users can trade with what is apparently a single currency,
                     // when in fact the issuence is delegated and distributed across multiple issuers.
		exchangeBasket, // Use this to exchange assets in and out of a basket currency.
		getTransactionNum, // Every transaction requires a transaction number. If your wallet doesn't have one,
                           // then here it can request the server to send one over. (Or several.)
		getNymbox, // Grab a copy of my nymbox (contains messages and new transaction numbers)
		getInbox, // Grab a copy of my inbox from the server so I can decide what to do with it.
		getOutbox, // Grab a copy of my outbox from the server so I can decide what to do with it.
		processNymbox, // Used by AcceptEntireNymbox() as it's setting everything up.
		processEntireNymbox,// Instruct the server what to do with the various items sitting in my nymbox. (per user)
		processInbox, // Instruct the server what to do with the various items sitting in my inbox. (per asset acct)
		processEntireInbox, // Just accept everything in the server (used in the command line test client.)
		getAccount, // Grab the server's copy of my asset account file, in case mine is lost.
		getContract, // Grab the server's copy of any asset contract. Input is the asset type ID.
		getMint, // Grab the server's copy of any mint based on Asset ID. (For blinded tokens.)
		// ------------------------------------------------------------------------------
		writeCheque, // Write a cheque. (Actually sends no message to the server -- returns false.)
		signContract, // Sign a contract. (Sends no message to the server.)
		proposePaymentPlan, // (Merchant) Propose a payment plan. (Sends no message to the server.)
		confirmPaymentPlan, // (Customer) Confirm a payment plan. (Sends no message to the server.)
		// ------------------------------------------------------------------------------
		notarizeTransfer, // Request the server to transfer from one account to another.
		notarizeWithdrawal, // Request the server to withdraw from an asset account and return digital cash tokens to the wallet.
		withdrawVoucher, // Request the server to withdraw from an asset account and issue a voucher (cashier's cheque)
		notarizeDeposit, // Request the server to accept some digital cash and deposit it to an asset account.
		notarizePurse, // Same as the above, but sends an entire purse of tokens at once instead of sending individual tokens.
		notarizeCheque, // Deposit like the above, but deposits a cheque instead of cash tokens.
		// ------------------------------------------------------------------------------
		marketOffer, // Create an Offer object and add it to one of the server's Market objects.
		// This will also create a Trade object and add it to the server's Cron object.
		// (The Trade provides the payment authorization for the Offer, as well as the rules
		// for processing and expiring it.)

		paymentPlan, // Send a payment plan to the server (request to activate one onto yourself, basically.)
		// The test client will ask you to input the plan, which you must already have (like a cheque).
		// The Payee must create it and sign it, then he sends it to the Payer, who uses this command
		// to sign it and submit it to the server.
		// ------------------------------------------------------------------------------
		setAccountName, // For setting the client-side label on an asset account.
		setNymName, // For setting the client-side label on a Nym.
		setServerName, // For setting the client-side label on a server contract.
		setAssetName, // For setting the client-side label on an asset contract.
		// ------------------------------------------------------------------------------
		badID
	};

	// Right now this wallet just supports a SINGLE server connection.
	// Eventually it will be a whole list of server connections.
	// For now one is good enough for testing.
	// All commands for the server will be sent here.
	//
	// Here was the problem, you see: You can't attach the connection to the Nym,
	// because the same Nym might have connections to different servers. And you can't
	// attach it to the server contract, because the user might access that server
	// through multiple nym accounts on the same server.
	// So I decided the wallet should manage the connections, and when new connections
	// are made, the serverconnection object will be given a pointer at that time to
	// the server and nym for that connection. That way the two are always available
	// for processing the commands.

	OTServerConnection * m_pConnection;

	inline OTMessageBuffer & GetMessageBuffer() { return m_MessageBuffer; }
	inline OTMessageOutbuffer & GetMessageOutbuffer() { return m_MessageOutbuffer; }

//  inline bool IsConnected() { return m_pConnection->IsConnected(); }

	// For RPC mode
	EXPORT bool SetFocusToServerAndNym(OTServerContract & theServerContract, OTPseudonym & theNym, TransportCallback * pCallback);

	// For the test client in SSL / TCP mode.
	bool ConnectToTheFirstServerOnList(OTPseudonym & theNym, OTString & strCA_FILE, OTString & strKEY_FILE, OTString & strKEY_PASSWORD);

	// Eventually, the wallet will have a LIST of these server connections,
	// and any use of the connection will first require to look up the right one
	// on that list, based on ID. This will return a pointer, and then you do the
	// same call you normally did from there.

	OTClient();
	~OTClient();

	bool InitClient(OTWallet & theWallet); // Need to call this before using.
	bool m_bInitialized; // this will be false until InitClient() is called.
	// ------------------------------------------------------------
	// These functions manipulate the internal m_pConnection member:
	void ProcessMessageOut(char *buf, int32_t * pnExpectReply);
	void ProcessMessageOut(OTMessage & theMessage);
	bool ProcessInBuffer(OTMessage & theServerReply);
	// ------------------------------------------------------------
	// These functions are for command processing:

	EXPORT int32_t ProcessUserCommand(
		OT_CLIENT_CMD_TYPE requestedCommand,
		OTMessage & theMessage,
		OTPseudonym & theNym,
		// OTAssetContract & theContract,
		OTServerContract & theServer,
		OTAccount * pAccount=NULL,
		int64_t lTransactionAmount = 0,
		OTAssetContract * pMyAssetContract=NULL,
		OTIdentifier * pHisNymID=NULL,
		OTIdentifier * pHisAcctID=NULL
		);

	bool ProcessServerReply(OTMessage & theReply, OTLedger * pNymbox=NULL); // IF the Nymbox is passed in, then use that one, where appropriate, instead of loading it internally.
	void ProcessIncomingTransactions(OTServerConnection & theConnection, OTMessage & theReply);
	void ProcessWithdrawalResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply);
	void ProcessDepositResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply);
	void ProcessPayDividendResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply);

//  void AcceptEntireInbox (OTLedger & theInbox,  OTServerConnection & theConnection);
//  void AcceptEntireNymbox(OTLedger & theNymbox, OTServerConnection & theConnection);

	bool AcceptEntireInbox(
		OTLedger & theInbox, 
		const OTIdentifier & theServerID,
		OTServerContract & theServerContract, 
		OTPseudonym & theNym,
		OTMessage & theMessage,
		OTAccount & theAccount
		);

	bool AcceptEntireNymbox(
		OTLedger & theNymbox, 
		const OTIdentifier & theServerID,
		OTServerContract & theServerContract, 
		OTPseudonym & theNym,
		OTMessage & theMessage
		);

	// void HarvestTransactionNumbers(OTTransaction & theTransaction, OTPseudonym & theNym); 

};


} // namespace opentxs

#endif // __OTCLIENT_HPP__
