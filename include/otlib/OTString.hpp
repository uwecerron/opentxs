/************************************************************
 *
 *  OTString.hpp
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

#ifndef  __OT_STRING_HPP__
#define  __OT_STRING_HPP__

#include "OTCommon.hpp"

#ifdef _WIN32
#include "win32_utf8conv.hpp"  // support for changing between std::string and std::wstring
#endif

#include <cstdarg>
#include <list>
#include <map>
#include <sstream>

#include <string.h>

// All of the below PRI values are defined in inttypes.h
// Therefore if it's NOT defined, then we must probably be
// on Windows, since Windows doesn't have inttypes.h yet,
// only stdint.h
#if !defined( PRId8 )
#define PRId8 "d"
#endif

#if !defined( PRId16 )
#define PRId16 "d"
#endif

#if !defined( PRId32 )
#if defined( WINAPI )
#define PRId32 "I32d"

#else
#define PRId32 "d"

#endif
#endif

#if !defined( PRId64 )
#if defined( WINAPI )
#define PRId64 "I64d"

#elif __WORDSIZE == 64
#define PRId64 "ld"

#else
#define PRId64 "lld"

#endif
#endif

//#ifdef _WIN32
//#define MAX_STRING_LENGTH   631072
//#else
#define MAX_STRING_LENGTH   0x800000   // this is about 8 megs.
//#define MAX_STRING_LENGTH   1262144
//#endif // _WIN32
// TODO: consider how MAX_SIZE affects the above hard-coded number...

namespace opentxs {

class OTASCIIArmor;
class OTContract;
class OTIdentifier;
class OTPseudonym;
class OTSignature;

typedef std::list   <std::string>                   listOfStrings;
typedef std::map	<std::string, std::string>		mapOfStrings;


// If you've already strlen'd the string,
// you can pass the length to str_hsh or str_dup
// and save it the trouble.
//
char *str_dup1(const char *str);
char *str_dup2(const char *str, uint32_t length);
int32_t   len_cmp(char *s1, char *s2);


template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}


/*
 * strlcpy and strlcat
 *
 * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
inline size_t strlcpy(char *dst, const char *src, size_t siz)
{
    char *d = dst;
    const char *s = src;
    size_t n = siz;

    /* Copy as many bytes as will fit */
    if (n != 0)
    {
        while (--n != 0)
        {
            if ((*d++ = *s++) == '\0')
                break;
        }
    }

    /* Not enough room in dst, add NUL and traverse rest of src */
    if (n == 0)
    {
        if (siz != 0)
            *d = '\0';  /* NUL-terminate dst */
        while (*s++)
            ;
    }

    return(s - src - 1); /* count does not include NUL */
}
/*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz <= strlen(dst)).
 * Returns strlen(src) + MIN(siz, strlen(initial dst)).
 * If retval >= siz, truncation occurred.
 */
inline size_t strlcat(char *dst, const char *src, size_t siz)
{
    char *d = dst;
    const char *s = src;
    size_t n = siz;
    size_t dlen;

    /* Find the end of dst and adjust bytes left but don't go past end */
    while (n-- != 0 && *d != '\0')
        d++;
    dlen = d - dst;
    n = siz - dlen;

    if (n == 0)
        return(dlen + strlen(s));
    while (*s != '\0')
    {
        if (n != 1)
        {
            *d++ = *s;
            n--;
        }
        s++;
    }
    *d = '\0';

    return(dlen + (s - src)); /* count does not include NUL */
}
// (End of the Todd Miller code.)


class OTString
{
   // Construction -- Destruction
public:
EXPORT	OTString();
EXPORT	OTString(const OTString & strValue);
EXPORT	OTString(const OTASCIIArmor & strValue);
        OTString(const OTSignature & strValue);
EXPORT	OTString(const OTContract & theValue);
EXPORT	OTString(const OTIdentifier & theValue);
        OTString(OTPseudonym & theValue);
EXPORT	OTString(const char * new_string);
        OTString(const char * new_string, size_t sizeLength);
EXPORT	OTString(const std::string & new_string);
EXPORT	virtual ~OTString();

   void Initialize();

EXPORT	OTString& operator=(OTString rhs);
//	OTString& operator=(const char * new_string);       // Many unexpected side-effects if you mess with this.  }:-)
//	OTString& operator=(const std::string & strValue);

	// ----------------------------------------------
static   bool vformat(const char * fmt, std::va_list * pvl, std::string & str_output);

         void swap(OTString & rhs);
	// ----------------------------------------------
         bool operator >(const OTString &s2) const;
         bool operator <(const OTString &s2) const;
         bool operator <=(const OTString &s2) const;
         bool operator >=(const OTString &s2) const;
EXPORT   bool operator ==(const OTString &s2) const;
	// ----------------------------------------------
EXPORT	static       std::string & trim(std::string& str);
	// ----------------------------------------------
EXPORT  static const std::string   replace_chars
                                    (const std::string & str,
                                     const std::string & charsFrom,
                                     const char & charTo);
// ----------------------------------------------
#ifdef _WIN32
EXPORT static std::wstring s2ws(const std::string  & s);
EXPORT static std::string  ws2s(const std::wstring & s);
#endif
// ----------------------------------------------

	// ----------------------------------------------
    // from: http://www.cplusplus.com/faq/sequences/strings/split/
    //
    struct split
    {
        enum empties_t { empties_ok, no_empties };
    };

    template <typename Container>
    static Container& split_byChar(
        Container&                            result,
        const typename Container::value_type& s,
        const typename Container::value_type& delimiters,
        split::empties_t               empties)
    {
        result.clear();
        size_t current;
        int64_t next = -1;
        do
        {
            if (empties == split::no_empties)
            {
                next = s.find_first_not_of(delimiters, static_cast<uint32_t>(next)+1);
                if (next == Container::value_type::npos) break;
                next -= 1;
            }
            current = static_cast<size_t>(next + 1);
            next = s.find_first_of( delimiters, current );
            result.push_back(s.substr(current, static_cast<uint32_t>(next) - current));
        }
        while (next != Container::value_type::npos);
        return result;
    }
	// ----------------------------------------------

private: 	// Implementation
	// You better have called Initialize() or Release() before you dare call this.
	void LowLevelSetStr(const OTString & strBuf);

	// Only call this right after calling Initialize() or Release().
	// Also, this function ASSUMES the new_string pointer is good.
	void LowLevelSet(const char * new_string, uint32_t nEnforcedMaxLength);
	// ----------------------------------------------
	// Operations
public:
EXPORT    static bool safe_strcpy(char * dest,
                                  const
                                  char * src,
                                  // -----------------
                                  size_t dest_size, // max size of destination must be passed here.
                                  bool   bZeroSource=false); // if true, sets the source buffer to zero after copying is done.
    // ----------------------------------------------
    static size_t safe_strlen(const char * s, size_t max);
	// ----------------------------

EXPORT  static int64_t StringToLong(const std::string & strNumber);

EXPORT  int64_t ToLong() const;


EXPORT  static uint64_t StringToUlong(const std::string & strNumber);

EXPORT  uint64_t ToUlong() const;

    // ----------------------------

EXPORT	bool At    (uint32_t lIndex, char &c) const;
    // ----------------------------------------------
EXPORT	bool Exists() const;
   	// ----------------------------------------------
EXPORT  bool DecodeIfArmored(bool bEscapedIsAllowed=true);
   	// ----------------------------------------------
EXPORT uint32_t GetLength(void) const;
	// ----------------------------------------------
EXPORT        bool   Compare(const char     * strCompare) const;
EXPORT        bool   Compare(const OTString & strCompare) const;

EXPORT	      bool   Contains(const char     * strCompare) const;
              bool   Contains(const OTString & strCompare) const;

EXPORT	const char * Get(void) const;
	// ----------------------------
	// new_string MUST be at least nEnforcedMaxLength in size if
    // nEnforcedMaxLength is passed in at all.
    //
	// That's because this function forces the null terminator at
    // that length, minus 1. For example, if the max is set to 10, then
    // the valid range is 0..9. Therefore 9 (10 minus 1) is where the
    // NULL terminator goes.
    //
EXPORT	void   Set         (const char     * new_string, uint32_t nEnforcedMaxLength=0);
EXPORT	void   Set         (const OTString & strBuf);
	// ----------------------------
    // For a straight-across, exact-size copy of bytes.
    // Source not expected to be null-terminated.
EXPORT	bool   MemSet      (const char     * pMem, uint32_t theSize);
	// ----------------------------
EXPORT	void   Concatenate (const char     * arg, ...);
        void   Concatenate (const OTString & strBuf);
	// ----------------------------
        void   Truncate    (      uint32_t   lAt);
	// ----------------------------
EXPORT	void   Format      (const char     * fmt, ...);
   	// ----------------------------------------------
        void ConvertToLowerCase();
        void ConvertToUpperCase();
    // ----------------------------------------------
EXPORT	bool TokenizeIntoKeyValuePairs(mapOfStrings & mapOutput) const;
	// ----------------------------------------------
EXPORT	void OTfgets(std::istream & ofs);
	// ----------------------------------------------
	// true  == there are more lines to read.
	// false == this is the last line. Like EOF.
	bool sgets(char * szBuffer, uint32_t nBufSize);

    char sgetc(void);
    void sungetc(void);
    void reset(void);

	void WriteToFile(std::ostream & ofs) const;
	// ----------------------------------------------
    EXPORT   virtual void Release(void);
    void Release_String(void);
	// ----------------------------------------------
	EXPORT   void zeroMemory();
    // ----------------------------------------------
   // Internal properties
protected:
   uint32_t  m_lLength;
   uint32_t  m_lPosition;
   char    * m_strBuffer;
    // ----------------------------------------------
};


//bool operator >(const OTString& s1, const OTString& s2);
//bool operator <(const OTString& s1, const OTString& s2);
//bool operator >=(const OTString &s1, const OTString& s2);
//bool operator <=(const OTString &s1, const OTString& s2);



} // namespace opentxs

#endif // __OT_STRING_HPP__
