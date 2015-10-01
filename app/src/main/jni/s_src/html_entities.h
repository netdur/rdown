/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf --output-file=src/html_entities.h src/html_entities.gperf  */
/* Computed positions: -k'2-7' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 8 "src/html_entities.gperf"

#include <stdlib.h>

/* Parsers tend to choke on entities with values greater than this */
const u_int32_t MAX_NUM_ENTITY_VAL = 0x10ffff;
/* Any numeric entity longer than this is obviously above MAX_NUM_ENTITY_VAL
 * used to avoid dealing with overflows. */
const size_t MAX_NUM_ENTITY_LEN = 7;

inline int is_valid_numeric_entity(uint32_t entity_val)
{
	/* Some XML parsers will choke on entities with certain
	 * values (mostly control characters.)
	 *
	 * According to lxml these are all problematic:
	 *
	 *	[xrange(0, 8),
	 *	 xrange(11, 12),
	 *	 xrange(14, 31),
	 *	 xrange(55296, 57343),
	 *	 xrange(65534, 65535)]
	 */
	return (entity_val > 8
			&& (entity_val != 11 && entity_val != 12)
			&& (entity_val < 14 || entity_val > 31)
			&& (entity_val < 55296 || entity_val > 57343)
			&& (entity_val != 65534 && entity_val != 65535)
			&& entity_val <= MAX_NUM_ENTITY_VAL);
}

#include <string.h>
/* maximum key range = 757, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash_html_entity (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771,   0,
       95,  90,   0, 771, 771, 771, 771, 771, 771,   0,
      771, 771, 771, 771, 771, 115,  94,  55,   0, 150,
       25,   0,  30, 195, 771,  30,  30,   5,  35,  45,
       45, 771,  10,   0,  50, 125, 771, 771,   5,  85,
       75, 771, 771, 771, 771, 771, 771,  40,  65,  20,
       25,  60, 240, 240, 223,  10, 102,  20,  35, 135,
        0,   5,  10, 183,  20,   5,   0,  50,  75,  10,
       75, 175,  85,  15, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 771, 771, 771, 771, 771, 771
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[6]];
      /*FALLTHROUGH*/
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]+1];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
        break;
    }
  return hval;
}

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const char *
is_allowed_named_entity (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 253,
      MIN_WORD_LENGTH = 4,
      MAX_WORD_LENGTH = 10,
      MIN_HASH_VALUE = 14,
      MAX_HASH_VALUE = 770
    };

  static const char * const wordlist[] =
    {
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "",
      "&or;",
      "&not;",
      "", "", "", "",
      "&int;",
      "", "", "", "",
      "&psi;",
      "&isin;",
      "&notin;",
      "", "",
      "&Rho;",
      "", "", "", "",
      "&phi;",
      "&prop;",
      "", "", "",
      "&rho;",
      "&nbsp;",
      "&thorn;",
      "&thinsp;",
      "",
      "&chi;",
      "", "", "", "", "",
      "&prod;",
      "", "", "",
      "&amp;",
      "", "", "", "",
      "&Psi;",
      "", "", "", "", "",
      "&iota;",
      "", "",
      "&omicron;",
      "&Phi;",
      "", "", "", "",
      "&and;",
      "&sdot;",
      "", "",
      "&nu;",
      "&Chi;",
      "&emsp;",
      "", "",
      "&Mu;",
      "",
      "&ensp;",
      "&ocirc;",
      "",
      "&lt;",
      "&uml;",
      "",
      "&icirc;",
      "", "",
      "&sup;",
      "&sup1;",
      "",
      "&Scaron;",
      "",
      "&cap;",
      "&part;",
      "&pound;",
      "&scaron;",
      "", "",
      "&ni;",
      "",
      "&lowast;",
      "&Omicron;",
      "&cup;",
      "&Xi;",
      "&crarr;",
      "",
      "&Nu;",
      "",
      "&pi;",
      "&theta;",
      "", "",
      "&tau;",
      "&nsub;",
      "&acirc;",
      "", "",
      "&thetasym;",
      "",
      "&Ocirc;",
      "", "", "",
      "&rarr;",
      "&ucirc;",
      "", "",
      "&loz;",
      "&darr;",
      "&trade;",
      "", "", "",
      "&para;",
      "&ecirc;",
      "", "", "",
      "&larr;",
      "&radic;",
      "", "",
      "&sub;",
      "&Pi;",
      "&kappa;",
      "&iquest;",
      "",
      "&eta;",
      "&supe;",
      "&rceil;",
      "&there4;",
      "",
      "&rArr;",
      "&uarr;",
      "&Kappa;",
      "", "",
      "&dArr;",
      "&euro;",
      "&Theta;",
      "&circ;",
      "",
      "&Tau;",
      "",
      "&lceil;",
      "", "",
      "&lArr;",
      "&ordm;",
      "", "", "",
      "&lrm;",
      "&xi;",
      "&acute;",
      "&ccedil;",
      "", "",
      "&sup3;",
      "",
      "&ntilde;",
      "",
      "&uArr;",
      "&sup2;",
      "&piv;",
      "&otilde;",
      "",
      "&shy;",
      "",
      "&Acirc;",
      "", "", "", "", "",
      "&curren;",
      "", "", "",
      "&Ucirc;",
      "&oacute;",
      "", "",
      "&sube;",
      "&nabla;",
      "&iacute;",
      "&mu;",
      "",
      "&bull;",
      "&oline;",
      "&Ccedil;",
      "",
      "&sum;",
      "&copy;",
      "&equiv;",
      "&Ntilde;",
      "", "", "",
      "&prime;",
      "&atilde;",
      "&tilde;",
      "", "",
      "&Ecirc;",
      "&Otilde;",
      "", "", "", "", "",
      "&apos;",
      "", "", "",
      "&aacute;",
      "&ne;",
      "&Eta;",
      "&macr;",
      "&sim;",
      "&Oacute;",
      "", "",
      "&Iota;",
      "&empty;",
      "&uacute;",
      "", "",
      "&ouml;",
      "&exist;",
      "", "", "",
      "&iuml;",
      "&Prime;",
      "&eacute;",
      "",
      "&rsquo;",
      "&cent;",
      "&zwj;",
      "&zwnj;",
      "&quot;",
      "&sbquo;",
      "&sect;",
      "&infin;",
      "&otimes;",
      "", "",
      "&cong;",
      "&Icirc;",
      "&brvbar;",
      "&le;",
      "&lsquo;",
      "&ordf;",
      "&clubs;",
      "", "",
      "&oplus;",
      "&perp;",
      "",
      "&Yacute;",
      "&micro;",
      "&ang;",
      "&auml;",
      "", "",
      "&gt;",
      "&rlm;",
      "&Ouml;",
      "&upsilon;",
      "",
      "&minus;",
      "&middot;",
      "&uuml;",
      "&aring;",
      "&Atilde;",
      "",
      "&divide;",
      "&rsaquo;",
      "&epsilon;",
      "",
      "&times;",
      "&ETH;",
      "&euml;",
      "&szlig;",
      "&frac14;",
      "&diams;",
      "",
      "&oslash;",
      "",
      "&Aacute;",
      "", "",
      "&lsaquo;",
      "&Delta;",
      "", "",
      "&rdquo;",
      "&spades;",
      "",
      "&Uacute;",
      "",
      "&raquo;",
      "&rang;",
      "&frasl;",
      "&rfloor;",
      "&harr;",
      "&ndash;",
      "&Yuml;",
      "&cedil;",
      "&eth;",
      "",
      "&ldquo;",
      "&real;",
      "&THORN;",
      "&plusmn;",
      "",
      "&laquo;",
      "&lang;",
      "&delta;",
      "&lfloor;",
      "", "",
      "&beta;",
      "&omega;",
      "&Eacute;",
      "", "",
      "&Oslash;",
      "&image;",
      "&weierp;",
      "", "",
      "&Zeta;",
      "&OElig;",
      "&hArr;",
      "", "",
      "&Auml;",
      "&asymp;",
      "&Lambda;",
      "",
      "&bdquo;",
      "&zeta;",
      "&Upsilon;",
      "&lambda;",
      "", "",
      "&Uuml;",
      "&Aring;",
      "&yacute;",
      "",
      "&Beta;",
      "",
      "&Gamma;",
      "", "", "", "",
      "&iexcl;",
      "&forall;",
      "", "", "",
      "&Omega;",
      "", "", "", "",
      "&Epsilon;",
      "&Iacute;",
      "", "",
      "&Euml;",
      "",
      "&frac34;",
      "", "", "", "",
      "&frac12;",
      "", "", "", "", "", "", "", "", "",
      "", "",
      "&yen;",
      "", "", "", "", "",
      "&yuml;",
      "", "", "", "",
      "&ograve;",
      "&AElig;",
      "", "", "",
      "&igrave;",
      "", "", "", "", "", "", "", "", "",
      "&Iuml;",
      "", "", "", "", "", "", "", "",
      "&alpha;",
      "", "",
      "&permil;",
      "", "", "", "", "", "", "",
      "&agrave;",
      "", "", "",
      "&mdash;",
      "&Ograve;",
      "", "", "", "",
      "&ugrave;",
      "",
      "&upsih;",
      "", "", "", "", "",
      "&ge;",
      "",
      "&egrave;",
      "", "", "", "", "", "", "", "", "",
      "&fnof;",
      "", "", "", "", "", "", "", "",
      "&reg;",
      "", "", "", "",
      "&deg;",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "",
      "&Sigma;",
      "", "", "", "",
      "&sigma;",
      "&Alpha;",
      "", "", "", "", "",
      "&hearts;",
      "&oelig;",
      "", "", "",
      "&Agrave;",
      "", "", "", "", "", "", "", "", "",
      "&Ugrave;",
      "", "", "", "", "", "", "", "", "",
      "&hellip;",
      "", "", "", "", "", "", "", "", "",
      "",
      "&aelig;",
      "", "", "",
      "&Egrave;",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "",
      "&Igrave;",
      "&gamma;",
      "", "", "", "", "", "", "", "", "",
      "",
      "&Dagger;",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "",
      "&dagger;",
      "", "", "", "", "",
      "&alefsym;",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "", "", "", "",
      "", "", "", "", "", "",
      "&sigmaf;"
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash_html_entity (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key];

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return s;
        }
    }
  return 0;
}
