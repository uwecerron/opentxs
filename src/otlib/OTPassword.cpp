/************************************************************
 *
 *  OTPassword.cpp
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

#include "OTPassword.hpp"

#include "OTCrypto.hpp"
#include "OTLog.hpp"


// For SecureZeroMemory
#ifdef _WIN32
#else // not _WIN32

// for mlock and munlock
#include <sys/types.h>
#include <sys/mman.h>
#include <limits.h>

#ifndef PAGESIZE
    #include <unistd.h>
    #define PAGESIZE sysconf(_SC_PAGESIZE)
#endif

// FT: Credit to the Bitcoin team for the mlock / munlock defines.

#define mlock(a,b) \
  mlock(((void *)(((size_t)(a)) & (~((PAGESIZE)-1)))),\
  (((((size_t)(a)) + (b) - 1) | ((PAGESIZE) - 1)) + 1) - (((size_t)(a)) & (~((PAGESIZE) - 1))))
#define munlock(a,b) \
  munlock(((void *)(((size_t)(a)) & (~((PAGESIZE)-1)))),\
  (((((size_t)(a)) + (b) - 1) | ((PAGESIZE) - 1)) + 1) - (((size_t)(a)) & (~((PAGESIZE) - 1))))
#endif


namespace opentxs {

// For everything but Windows:
//
#ifndef _WIN32
extern "C" void *ot_secure_memset(void *v, uint8_t c, uint32_t n);

// This function securely overwrites the contents of a memory buffer
// (which can otherwise be optimized out by an overzealous compiler...)
//
void *ot_secure_memset(void *v, uint8_t c, uint32_t n)
{
    OT_ASSERT((NULL != v) && (n > 0));

	volatile uint8_t * p = static_cast<volatile uint8_t *>(v);
	while (n--)
		*p++ = c;

	return v;
}
#endif // _WIN32


// TODO, security: Generate a session key, and encrypt the password string to that key whenever setting it,
// and decrypt it using that key whenever getting it. Also make sure to use the lock / unlock functions
// at that time (below). Also change so that the contents are dynamically allocated.
// NOTE: Given that OTSymmetricKey works with OTPassword, this is a bit circular in logic. Therefore might
// need to add a function to OTEnvelope so that it takes a const char * instead of an OTPassword, in order
// to handle this specific case! Might also need to duplicate some code between OTSymmetricKey and OTPassword
// in order to make sure both have the same protections. I'll see if there's a way to do this without duplication,
// as I get deeper into it.

/*
#ifdef _WIN64
   //define something for Windows (64-bit)
#elif _WIN32
   //define something for Windows (32-bit)
#elif __APPLE__
    #include "TargetConditionals.h"
    #ifdef TARGET_OS_IPHONE
         // iOS
    #elif TARGET_IPHONE_SIMULATOR
        // iOS Simulator
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
        // Unsupported platform
    #endif
#elif __linux
    // linux
#elif __unix // all unices not caught above
    // Unix
#elif __posix
    // POSIX
#endif
 */

// THE PURPOSE OF LOCKING A PAGE:
//
// "So that it won't get swapped to disk, where the secret
// could be recovered maliciously from the swap file."
//
bool ot_lockPage(void* addr, size_t len)
{
    static bool bWarned = false;

#ifdef _WIN32
	//return VirtualLock(addr, len);
#elif defined(PREDEF_PLATFORM_UNIX)
	if (mlock(addr, len) && !bWarned)
    {
        bWarned = true;
        OTLog::Error("ot_lockPage: WARNING: unable to lock memory. \n"
                     "   (Passwords / secret keys may be swapped to disk!)\n");
    }
    return true;
#else
	OT_FAIL_MSG("ASSERT: ot_lockPage unable to lock memory.");
#endif
    return false;
}


// TODO:  Note: may need to add directives here so that mlock and munlock are not
// used except where the user is running as a privileged process. (Because that
// may be the only way we CAN use those functions...)

bool ot_unlockPage(void* addr, size_t len)
{
    static bool bWarned = false;

#ifdef _WIN32
//	return VirtualUnlock(addr, len);
#elif defined(PREDEF_PLATFORM_UNIX)
	if (munlock(addr, len) && !bWarned)
    {
        bWarned = true;
        OTLog::Error("ot_unlockPage: WARNING: unable to unlock memory used for storing secrets.\n");
    }
    return true;
#else
	OT_FAIL_MSG("ASSERT: ot_unlockPage unable to unlock secret memory.");
#endif
    return false;
}


// PURPOSE OF ZERO'ING MEMORY:
//
// So the secret is not stored in memory any longer than absolutely necessary.
// Once it has been used, we want to wipe it from memory ASAP. (The least amount
// of time spent in memory, the better.)

void OTPassword::zeroMemory()
{
	m_nPasswordSize = 0;
    // -------------------
    OTPassword::zeroMemory(static_cast<void *>(&(m_szPassword[0])), static_cast<uint32_t>(getBlockSize()));
    // -------------------
    //
#ifndef _WIN32
    // UNLOCK the page, now that we're AFTER the point where
    // the memory was safely ZERO'd out.
    //
    if (m_bIsPageLocked)
    {
        if (ot_unlockPage(static_cast<void *>(&(m_szPassword[0])), static_cast<uint32_t>(getBlockSize())))
        {
            m_bIsPageLocked = false;
        }
        else
            OTLog::Error("OTPassword::zeroMemory: Error: Memory page was locked, but then failed to unlock it.\n");
    }
#endif
    // -------------------
}


//static
void OTPassword::zeroMemory(void * vMemory, uint32_t theSize)
{
//  OT_ASSERT_MSG((NULL != vMemory) && (theSize > 0),"OTPassword::zeroMemory: ASSERT: vMemory is NULL or theSize is 0.");

    if ((NULL != vMemory) && (theSize > 0))
    {
        uint8_t * szMemory = static_cast<uint8_t *>(vMemory);
        OTPassword::zeroMemory(szMemory, theSize);
    }
}


//static
void OTPassword::zeroMemory(uint8_t * szMemory, uint32_t theSize)
{
#ifdef _WIN32
	// ------
	//
	SecureZeroMemory(szMemory, theSize);

	// NOTE: Both SecureZeroMemory, and the pragma solution commented-out below,
	// are acceptable for Windows. I put both here for my notes.
	//
//#pragma optimize("", off)
//	memset(szMemory, 0, theSize);
//#pragma optimize("", on)
	// -------------------------
	// Dr. UNIX, I presume? So, we meet again...
#else
	ot_secure_memset(szMemory, static_cast<uint8_t>(0), theSize);
#endif
}


/* WINDOWS:
 errno_t memcpy_s(
     void   * dest,
     size_t   numberOfElements,
     const
     void   * src,
     size_t   count
     );

 FT: Apparently numberOfElements is similar to strcpy_s (where it's the maximum size of destination buffer.)
 "numberOfElements is the Maximum number of characters destination string can accomodate including the NULL character"
 (Then count is the actual size being copied.)
 */
// UNIX:
//    void * memcpy(void *restrict s1, const void *restrict s2, size_t n);
//
//static
void * OTPassword::safe_memcpy(void   * dest,
                               uint32_t dest_size,
                               const
                               void   * src,
                               uint32_t src_length,
                               bool     bZeroSource/*=false*/) // if true, sets the source buffer to zero after copying is done.
{
    bool bSuccess = false;

    // Make sure they aren't null.
    OT_ASSERT(NULL != dest);
    OT_ASSERT(NULL != src);

    // Make sure they aren't the same pointer.
    OT_ASSERT(src != dest);

    // Make sure it will fit.
    OT_ASSERT_MSG(src_length <= dest_size, "ASSERT: safe_memcpy: destination buffer too small.\n");

    // Make sure they don't overlap.
    // First assert does the beginning of the string, makes sure it's not within the bounds of the destination
    // string. Second assert does the same thing for the end of the string. Finally a third is needed to make sure
    // we're not in a situation where the beginning is less than the dest beginning, yet the end is also more than
    // the dest ending!
    //
    OT_ASSERT_MSG(false == ((static_cast<const uint8_t *>(src) >   static_cast<uint8_t *>(dest)) &&
                            (static_cast<const uint8_t *>(src) <  (static_cast<uint8_t *>(dest) + dest_size))),
                  "ASSERT: safe_memcpy: Unexpected memory overlap, start of src.\n");
    OT_ASSERT_MSG(false == (((static_cast<const uint8_t *>(src) + src_length) >   static_cast<uint8_t *>(dest)) &&
                            ((static_cast<const uint8_t *>(src) + src_length) <  (static_cast<uint8_t *>(dest) + dest_size))),
                  "ASSERT: safe_memcpy: Unexpected memory overlap, end of src.\n");
    OT_ASSERT(false ==  ((static_cast<const uint8_t *>(src) <= static_cast<uint8_t *>(dest)) &&
                        ((static_cast<const uint8_t *>(src) + src_length) >= (static_cast<uint8_t *>(dest) + dest_size))));

#ifdef _WIN32
    bSuccess = (0 == memcpy_s(dest,         // destination
                              static_cast<size_t>(dest_size),    // size of destination buffer.
                              src,          // source
                              static_cast<size_t>(src_length))); // length of source.
#else
    bSuccess = (memcpy(dest, src, static_cast<size_t>(src_length)) == dest);
#endif

    if (bSuccess)
    {
        if (bZeroSource)
        {
            OTPassword::zeroMemory(const_cast<void *>(src), src_length);
        }
        // ------------------------
        return dest;
    }

    return NULL;
}


// OTPassword thePass; will create a text password.
// But use the below function if you want one that has
// a text buffer of size (versus a 0 size.) This is for
// cases where you need the buffer to pre-exist so that
// some other function can populate that buffer directly.
// (Such as the OpenSSL password callback...)
// CALLER IS RESPONSIBLE TO DELETE.
//
//static
OTPassword * OTPassword::CreateTextBuffer() // asserts already.
{
    // Caller MUST delete!
    // ---------------------------------------------------
    char  throwaway_text[OT_DEFAULT_BLOCKSIZE];
    for (int32_t tt = 0; tt < OT_DEFAULT_BLOCKSIZE; ++tt)
    {
        throwaway_text[tt] = 'A'; // todo optimization...
    }
    throwaway_text[OT_DEFAULT_BLOCKSIZE-1] = '\0';
    // We don't use the above memory, except to force OTPassword to create itself
    // at a certain password size, so we can pass that buffer and size on to any
    // C-style function that needs them to "already exist."
    //
    OTPassword * pPassUserInput = new OTPassword(&(throwaway_text[0]), OT_DEFAULT_BLOCKSIZE-1); // text mode.
    OT_ASSERT_MSG(NULL != pPassUserInput, "OTPassword::CreateTextBuffer: ASSERT: OTPassword * pPassUserInput = new OTPassword(&(throwaway_text[0]), OT_DEFAULT_BLOCKSIZE-1);");
    // Below this point, pPassUserInput must be returned, or deleted. (Or it will leak.)
    // -----------------------------------------------
    return pPassUserInput;
}


OTPassword::OTPassword(OTPassword::BlockSize theBlockSize/*=DEFAULT_SIZE*/)
:	m_nPasswordSize(0),
    m_bIsText(true),
    m_bIsBinary(false),
    m_bIsPageLocked(false),
	m_theBlockSize(theBlockSize) // The buffer has this size+1 as its static size.
{
	m_szPassword[0] = '\0';

    setPassword_uint8(reinterpret_cast<const uint8_t*>(""), 0);
}


OTPassword & OTPassword::operator=(const OTPassword & rhs)
{
    if (rhs.isPassword())
    {
        setPassword_uint8(rhs.getPassword_uint8(), rhs.getPasswordSize());
    }
    else if (rhs.isMemory())
    {
        setMemory(rhs.getMemory_uint8(), rhs.getMemorySize());
    }

    return *this;
}


OTPassword::OTPassword(const OTPassword & rhs)
:	m_nPasswordSize(0),
    m_bIsText(rhs.isPassword()),
    m_bIsBinary(rhs.isMemory()),
    m_bIsPageLocked(false),
    m_theBlockSize(rhs.m_theBlockSize) // The buffer has this size+1 as its static size.
{
    if (m_bIsText)
    {
        m_szPassword[0] = '\0';
        setPassword_uint8(rhs.getPassword_uint8(), rhs.getPasswordSize());
    }
    else if (m_bIsBinary)
    {
        setMemory(rhs.getMemory_uint8(), rhs.getMemorySize());
    }
}


OTPassword::OTPassword(const char * szInput, uint32_t nInputSize, OTPassword::BlockSize theBlockSize/*=DEFAULT_SIZE*/)
:	m_nPasswordSize(0),
    m_bIsText(true),
    m_bIsBinary(false),
    m_bIsPageLocked(false),
    m_theBlockSize(theBlockSize) // The buffer has this size+1 as its static size.
{
	m_szPassword[0] = '\0';

	setPassword_uint8(reinterpret_cast<const uint8_t*>(szInput), nInputSize);
}


OTPassword::OTPassword(const uint8_t * szInput, uint32_t nInputSize, OTPassword::BlockSize theBlockSize/*=DEFAULT_SIZE*/)
:	m_nPasswordSize(0),
    m_bIsText(true),
    m_bIsBinary(false),
    m_bIsPageLocked(false),
    m_theBlockSize(theBlockSize) // The buffer has this size+1 as its static size.
{
	m_szPassword[0] = '\0';

	setPassword_uint8(szInput, nInputSize);
}


OTPassword::OTPassword(const void * vInput, uint32_t nInputSize, OTPassword::BlockSize theBlockSize/*=DEFAULT_SIZE*/)
:	m_nPasswordSize(0),
    m_bIsText(false),
    m_bIsBinary(true),
    m_bIsPageLocked(false),
    m_theBlockSize(theBlockSize) // The buffer has this size+1 as its static size.
{
	setMemory(vInput, nInputSize);
}


OTPassword::~OTPassword()
{
	if (m_nPasswordSize > 0)
		zeroMemory();
}


bool OTPassword::isPassword() const
{
    return m_bIsText;
}


bool OTPassword::isMemory() const
{
    return m_bIsBinary;
}


const char * OTPassword::getPassword() const // asserts if m_bIsText is false.
{
    return reinterpret_cast<const char *>(this->getPassword_uint8());

}


// getPassword returns "" if empty, otherwise returns the password.
//
const uint8_t * OTPassword::getPassword_uint8() const
{
    OT_ASSERT(m_bIsText);
	return (m_nPasswordSize <= 0) ? reinterpret_cast<const uint8_t *>("") : &(m_szPassword[0]);
}


uint8_t * OTPassword::getPasswordWritable()
{
    OT_ASSERT(m_bIsText);
	return (m_nPasswordSize <= 0) ? NULL : static_cast<uint8_t *>(static_cast<void *>(&(m_szPassword[0])));
}


char * OTPassword::getPasswordWritable_char()
{
    OT_ASSERT(m_bIsText);
	return (m_nPasswordSize <= 0) ? NULL : static_cast<char *>(static_cast<void *>(&(m_szPassword[0])));
}


// getMemory returns NULL if empty, otherwise returns the password.
//
const void * OTPassword::getMemory() const
{
    return reinterpret_cast<const void *>(this->getMemory_uint8());
}


const uint8_t * OTPassword::getMemory_uint8() const
{
    OT_ASSERT(m_bIsBinary);
	return (m_nPasswordSize <= 0) ? NULL : static_cast<const uint8_t *>(&(m_szPassword[0]));
}


// getMemoryWritable returns NULL if empty, otherwise returns the password.
//
void * OTPassword::getMemoryWritable()
{
    OT_ASSERT(m_bIsBinary);
	return (m_nPasswordSize <= 0) ? NULL : static_cast<void *>(&(m_szPassword[0]));
}


uint32_t OTPassword::getBlockSize() const
{
    uint32_t nReturn = 0;

    switch(m_theBlockSize)
    {
        case OTPassword::DEFAULT_SIZE:
            nReturn =  static_cast<uint32_t>(OT_DEFAULT_BLOCKSIZE);
            break;
        case OTPassword::LARGER_SIZE:
            nReturn =  static_cast<uint32_t>(OT_LARGE_BLOCKSIZE);
            break;
        default:
            break;
    }

	return nReturn;
}


uint32_t OTPassword::getPasswordSize() const
{
    OT_ASSERT(m_bIsText);
	return m_nPasswordSize;
}


uint32_t OTPassword::getMemorySize() const
{
    OT_ASSERT(m_bIsBinary);
	return m_nPasswordSize;
}


bool OTPassword::addChar(uint8_t theChar)
{
    OT_ASSERT(isPassword());
    if (getPasswordSize() < getBlockSize())
    {
        m_szPassword[m_nPasswordSize] = theChar;
        ++m_nPasswordSize;
        m_szPassword[m_nPasswordSize] = '\0';
        return true;
    }
    return false;
}


bool OTPassword::Compare(OTPassword & rhs) const
{
    OT_ASSERT(this->isPassword() || this->isMemory());
    OT_ASSERT(rhs.isPassword()   || rhs.isMemory());

    if (this->isPassword() && !rhs.isPassword())
        return false;
    if (this->isMemory() && !rhs.isMemory())
        return false;

    const uint32_t nThisSize = this->isPassword() ? this->getPasswordSize() : this->getMemorySize();
    const uint32_t nRhsSize  = rhs.isPassword()   ? rhs.getPasswordSize()   : rhs.getMemorySize();

    if (nThisSize != nRhsSize)
        return false;

    if (0 == memcmp(this->isPassword() ? this->getPassword_uint8() : this->getMemory_uint8(),
                    rhs.  isPassword() ? rhs.  getPassword_uint8() : rhs.  getMemory_uint8(),
                    rhs.  isPassword() ? rhs.  getPasswordSize()   : rhs.  getMemorySize()) )
        return true;

    return false;
}


// Returns size of password (in case truncation is necessary.)
// Returns -1 in case of error.
//
int32_t OTPassword::setPassword(const char * szInput, int32_t nInputSize)
{
    return static_cast<int32_t>(this->setPassword_uint8(
                reinterpret_cast<const uint8_t *>(szInput),
                static_cast<uint32_t>(nInputSize)));
}


// This adds a null terminator.
//
int32_t OTPassword::setPassword_uint8(const uint8_t * szInput, uint32_t nInputSize)
{
    OT_ASSERT(NULL != szInput);

    const char * szFunc = "OTPassword::setPassword";
    // ---------------------------------
	// Wipe whatever was in there before.
    //
	if (m_nPasswordSize > 0)
		zeroMemory();
	// ---------------------------------
    m_bIsBinary = false;
    m_bIsText   = true;
	// ---------------------------------
	if (0 == nInputSize)
		return 0;
	// ---------------------------------

	// Make sure no input size is larger than our block size
	//
	if (nInputSize > getBlockSize())
		nInputSize = getBlockSize(); // Truncated password beyond max size.
	// ---------------------------------
	// The szInput string passed into this function should never
	// be a different size than what is passed in. For example it shouldn't
	// be SMALLER than what the user claims either. If it is, we error out.
	//
	if (OTString::safe_strlen(reinterpret_cast<const char *>(szInput), static_cast<size_t>(nInputSize)) < static_cast<size_t>(nInputSize))
	{
        OTLog::vError("%s: ERROR: string length of szInput did not match nInputSize.\n", szFunc);
		return (-1);
	}

#ifndef _WIN32
	// ---------------------------------
    //
    // Lock the memory page, before we copy the data over.
    // (If it's not already locked, which I doubt it will be.)
    //
    if (!m_bIsPageLocked) // it won't be locked already, since we just zero'd it (above.) But I check this anyway...
    {
        if (ot_lockPage(static_cast<void *>(&(m_szPassword[0])), getBlockSize()))
        {
            m_bIsPageLocked = true;
        }
        else
            OTLog::vError("%s: Error: Failed attempting to lock memory page.\n", szFunc);
    }
#endif
	// ---------------------------------
#ifdef _WIN32
	strncpy_s(reinterpret_cast<char *>(m_szPassword), (1 + nInputSize), reinterpret_cast<const char *>(szInput), nInputSize);
#else
	strncpy(reinterpret_cast<char *>(m_szPassword), reinterpret_cast<const char *>(szInput), nInputSize);
#endif

	// ---------------------------------
	// force a null terminator in the 129th byte (at index 128.)
	// (Or at the 6th byte (at index 5), if the size is 5 bytes int64_t.)
	//
	m_szPassword[nInputSize] = '\0';
    m_nPasswordSize          = nInputSize;
	// ---------------------------------

	return m_nPasswordSize;
}


// OTPassword::SetSize   (Low-level)
//
// There are certain weird cases, like in OTSymmetricKey::GetPassphraseFromUser,
// where we set the password using the getPassword_writable, and it's properly
// null-terminated, yet this instance still doesn't know its actual size (even though
// the size is known.) Therefore I added this call in order to set the size in
// those odd cases where it's necessary. That being said, YOU should normally NEVER
// need to use this function, so just pretend it doesn't exist.
//
// This adds a null terminator, IF we're in text mode (not binary mode.)
//
bool OTPassword::SetSize(uint32_t uSize)
{
    if (m_bIsBinary)
    {
        if (uSize > getBlockSize())
            uSize = getBlockSize(); // Truncated password beyond max size.
        m_nPasswordSize = uSize;
        return true;
    }
    else if (m_bIsText)
    {
        if (uSize >= getBlockSize())  // Cannot be as much as the blocksize, because no room for null-terminator.
            uSize = getBlockSize()-1; // Truncated password to blocksize-1.
        m_szPassword[uSize] = '\0';   // The actual null-terminator.
        m_nPasswordSize     = uSize;  // If size is 3, the terminator is at m_szPassword[3] (which is the 4th byte.)
        return true;
    }
    OTLog::vError("%s: Error: m_bIsBinary and m_bIsText are both false. (Should never happen.)\n", __FUNCTION__);
    return false;
}


//static
bool OTPassword::randomizePassword(char * szDestination, uint32_t nNewSize)
{
    return OTPassword::randomizePassword_uint8(reinterpret_cast<uint8_t *>(szDestination), nNewSize);
}


//static
bool OTPassword::randomizePassword_uint8(uint8_t * szDestination, uint32_t nNewSize)
{
    OT_ASSERT(NULL != szDestination);
    OT_ASSERT(nNewSize > 0);
	// ---------------------------------
//  const char * szFunc = "OTPassword::randomizePassword(static)";
	// ---------------------------------
    if (OTPassword::randomizeMemory_uint8(szDestination, nNewSize))
    {
        // --------------------------------------------------
        // This loop converts an array of binary bytes into the
        // same array, where each byte is translated to a byte
        // between the values of 33 and 122 (visible ASCII.)
        //
        for (uint32_t i = 0; i < nNewSize; ++i)
        {
            uint8_t temp     =  (( (szDestination[i]) % 89 ) + 33);
            szDestination[i] = temp;
        }
        // --------------------------------------------------
        // Add the NULL terminator...
        //
        szDestination[nNewSize-1] = '\0';

        return true;
    }
    return false;
}


// Returns size of memory (in case truncation is necessary.)
// Returns -1 in case of error.
//
int32_t OTPassword::randomizePassword(uint32_t nNewSize/*=DEFAULT_SIZE*/)
{
    uint32_t nSize = nNewSize;
    // ---------------------------------
	// Wipe whatever was in there before.
    //
	if (m_nPasswordSize > 0)
		zeroMemory();
	// ---------------------------------
    m_bIsBinary = false;
    m_bIsText   = true;
	// ---------------------------------
	if (0 == nSize)
		return 0;
	// ---------------------------------
	// Make sure no input size is larger than our block size
	//
	if (nSize > getBlockSize())
		nSize = getBlockSize(); // Truncated password beyond max size.
#ifndef _WIN32
    //
    // Lock the memory page, before we randomize 'size bytes' of the data.
    // (If it's not already locked, which I doubt it will be.)
    //
    if (!m_bIsPageLocked) // it won't be locked already, since we just zero'd it (above.) But I check this anyway...
    {
        if (ot_lockPage(static_cast<void *>(&(m_szPassword[0])), getBlockSize()))
        {
            m_bIsPageLocked = true;
        }
        else
            OTLog::vError("%s: Error: Failed attempting to lock memory page.\n", __FUNCTION__);
    }
#endif
	// ---------------------------------
    //
	if (!OTPassword::randomizePassword_uint8(&(m_szPassword[0]), static_cast<int32_t>(nSize+1)))
    {
        // randomizeMemory (above) already logs, so I'm not logging again twice here.
        //
        zeroMemory();
		return -1;
	}
	// --------------------------------------------------
	m_nPasswordSize = nSize;

	return m_nPasswordSize;
}


//static
bool OTPassword::randomizeMemory(void * szDestination, uint32_t nNewSize)
{
    return OTPassword::randomizeMemory_uint8(reinterpret_cast<uint8_t *>(szDestination), nNewSize);
}


//static
bool OTPassword::randomizeMemory_uint8(uint8_t * szDestination, uint32_t nNewSize)
{
    return OTCrypto::It()->RandomizeMemory(szDestination, nNewSize);
}


// Returns size of memory (in case truncation is necessary.)
// Returns -1 in case of error.
//
int32_t OTPassword::randomizeMemory(uint32_t nNewSize/*=DEFAULT_SIZE*/)
{
    uint32_t nSize = nNewSize;
    // ---------------------------------
	// Wipe whatever was in there before.
    //
	if (m_nPasswordSize > 0)
		zeroMemory();
	// ---------------------------------
    m_bIsBinary = true;
    m_bIsText   = false;
	// ---------------------------------
	if (0 == nSize)
		return 0;
	// ---------------------------------
	// Make sure no input size is larger than our block size
	//
	if (nSize > getBlockSize())
		nSize = getBlockSize(); // Truncated password beyond max size.

#ifndef _WIN32
    //
    // Lock the memory page, before we randomize 'size bytes' of the data.
    // (If it's not already locked, which I doubt it will be.)
    //
    if (!m_bIsPageLocked) // it won't be locked already, since we just zero'd it (above.) But I check this anyway...
    {
        if (ot_lockPage(static_cast<void *>(&(m_szPassword[0])), getBlockSize()))
        {
            m_bIsPageLocked = true;
        }
        else
            OTLog::vError("%s: Error: Failed attempting to lock memory page.\n", __FUNCTION__);
    }
#endif
	// ---------------------------------
    //
	if (!OTPassword::randomizeMemory_uint8(&(m_szPassword[0]), nSize))
    {
        // randomizeMemory (above) already logs, so I'm not logging again twice here.
        //
        zeroMemory();
		return -1;
	}
	// --------------------------------------------------
	m_nPasswordSize = nSize;

	return m_nPasswordSize;
}


// (FYI, truncates if nAppendSize + getPasswordSize() is larger than getBlockSize.)
// Returns number of bytes appended, or -1 for error.
//
int32_t OTPassword::addMemory(const void * vAppend, uint32_t nAppendSize)
{
    OT_ASSERT(NULL != vAppend);

//  const char * szFunc = "OTPassword::addMemory";
    // ---------------------------------
	if (0 == nAppendSize)
		return 0;
	// ---------------------------------
	// If I'm currently at a 0 size, then call setMemory instead.
    //
	if (m_nPasswordSize == 0)
		return this->setMemory(vAppend, nAppendSize);
    // ***********************************************
    //
    // By this point, I know I already have some memory allocated,
    // and I'm actually appending some other memory onto the end of it.
    //
    OT_ASSERT(m_bIsBinary); // Should already be set from the above setMemory call.
	// ---------------------------------
	// Make sure total new size isn't larger than our block size
	//
	if ((nAppendSize + m_nPasswordSize) > getBlockSize())
		nAppendSize = (getBlockSize() - m_nPasswordSize); // Truncated password beyond max size.
	// ---------------------------------
//  OT_ASSERT(nAppendSize >= 0);

    if (0 == nAppendSize)
        return 0;
    // ------------------------------------
    // By this point, I know nAppendSize is larger than 0, AND that appending it onto the
    // existing memory of this object will not exceed the total allowed block size.
    //
    // Because we use setMemory when empty, and only use addMemory when we KNOW something
    // is already there, therefore we know the page is already locked, so no need to go
    // trying to lock it again.
	// ---------------------------------
    OTPassword::safe_memcpy(static_cast<void *>(&(m_szPassword[m_nPasswordSize])),
                            static_cast<uint32_t>(nAppendSize), // dest size is based on the source size, but guaranteed to be >0 and <=getBlockSize
                            vAppend,
                            static_cast<uint32_t>(nAppendSize)); // Since dest size is known to be src size or less (and >0) we use it as src size. (We may have truncated... and we certainly don't want to copy beyond our own truncation.)
	// ---------------------------------
    m_nPasswordSize += nAppendSize;
	// ---------------------------------
	return nAppendSize;
}


// Returns size of memory (in case truncation is necessary.)
// Returns -1 in case of error.
//
int32_t OTPassword::setMemory(const void * vInput, uint32_t nInputSize)
{
    OT_ASSERT(NULL != vInput);
    // ---------------------------------
	// Wipe whatever was in there before.
    //
	if (m_nPasswordSize > 0)
		zeroMemory();
	// ---------------------------------
    m_bIsBinary = true;
    m_bIsText   = false;
	// ---------------------------------
	if (0 == nInputSize)
		return 0;
	// ---------------------------------
	// Make sure no input size is larger than our block size
	//
	if (nInputSize > getBlockSize())
		nInputSize = getBlockSize(); // Truncated password beyond max size.
	// ---------------------------------

#ifndef _WIN32
    //
    // Lock the memory page, before we copy the data over.
    // (If it's not already locked, which I doubt it will be.)
    //
    if (!m_bIsPageLocked) // it won't be locked already, since we just zero'd it (above.) But I check this anyway...
    {
        if (ot_lockPage(static_cast<void *>(&(m_szPassword[0])), getBlockSize()))
        {
            m_bIsPageLocked = true;
        }
        else
            OTLog::vError("%s: Error: Failed attempting to lock memory page.\n", __FUNCTION__);
    }
#endif

	// ---------------------------------
    OTPassword::safe_memcpy(static_cast<void *>(&(m_szPassword[0])),
                            static_cast<uint32_t>(nInputSize), // dest size is based on the source size, but guaranteed to be >0 and <=getBlockSize
                            vInput,
                            static_cast<uint32_t>(nInputSize)); // Since dest size is known to be src size or less (and >0) we use it as src size. (We may have truncated... and we certainly don't want to copy beyond our own truncation.)
	// ---------------------------------
    m_nPasswordSize = nInputSize;
	// ---------------------------------
	return m_nPasswordSize;
}

} // namespace opentxs
