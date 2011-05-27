#ifndef INC_PFCfgParserTokenTypes_hpp_
#define INC_PFCfgParserTokenTypes_hpp_

/* $ANTLR 2.7.7 (20090306): "pf.g" -> "PFCfgParserTokenTypes.hpp"$ */

#ifndef CUSTOM_API
# define CUSTOM_API
#endif

#ifdef __cplusplus
struct CUSTOM_API PFCfgParserTokenTypes {
#endif
	enum {
		EOF_ = 1,
		NEWLINE = 4,
		LINE_COMMENT = 5,
		WORD = 6,
		EQUAL = 7,
		ANTISPOOF = 8,
		ALTQ = 9,
		QUEUE = 10,
		SET = 11,
		SCRUB = 12,
		TABLE = 13,
		LESS_THAN = 14,
		GREATER_THAN = 15,
		PERSIST = 16,
		CONST = 17,
		COUNTERS = 18,
		FILE = 19,
		STRING = 20,
		OPENING_BRACE = 21,
		COMMA = 22,
		CLOSING_BRACE = 23,
		EXLAMATION = 24,
		COLON = 25,
		NETWORK = 26,
		BROADCAST = 27,
		PEER = 28,
		INT_CONST = 29,
		SELF = 30,
		IPV4 = 31,
		SLASH = 32,
		NAT = 33,
		BINAT = 34,
		RDR = 35,
		TIMEOUT = 36,
		PASS = 37,
		BLOCK = 38,
		IN = 39,
		OUT = 40,
		LOG = 41,
		OPENING_PAREN = 42,
		CLOSING_PAREN = 43,
		ALL = 44,
		USER = 45,
		TO = 46,
		QUICK = 47,
		ON = 48,
		INET = 49,
		INET6 = 50,
		PROTO = 51,
		IP = 52,
		ICMP = 53,
		IGMP = 54,
		TCP = 55,
		UDP = 56,
		RDP = 57,
		RSVP = 58,
		GRE = 59,
		ESP = 60,
		AH = 61,
		EIGRP = 62,
		OSPF = 63,
		IPIP = 64,
		VRRP = 65,
		L2TP = 66,
		ISIS = 67,
		FROM = 68,
		URPF_FAILED = 69,
		ANY = 70,
		NO_ROUTE = 71,
		IPV6 = 72,
		ROUTE_TO = 73,
		REPLY_TO = 74,
		FLAGS = 75,
		ICMP_TYPE = 76,
		ICMP_CODE = 77,
		ICMP6_TYPE = 78,
		TAGGED = 79,
		TAG = 80,
		NO = 81,
		KEEP = 82,
		MODULATE = 83,
		SYNPROXY = 84,
		STATE = 85,
		LABEL = 86,
		PORT = 87,
		EXIT = 88,
		QUIT = 89,
		INTRFACE = 90,
		ICMP6 = 91,
		IGRP = 92,
		IPSEC = 93,
		NOS = 94,
		PCP = 95,
		PIM = 96,
		PPTP = 97,
		RIP = 98,
		SNP = 99,
		HOST = 100,
		RANGE = 101,
		LOG_LEVEL_ALERTS = 102,
		LOG_LEVEL_CRITICAL = 103,
		LOG_LEVEL_DEBUGGING = 104,
		LOG_LEVEL_EMERGENCIES = 105,
		LOG_LEVEL_ERRORS = 106,
		LOG_LEVEL_INFORMATIONAL = 107,
		LOG_LEVEL_NOTIFICATIONS = 108,
		LOG_LEVEL_WARNINGS = 109,
		LOG_LEVEL_DISABLE = 110,
		LOG_LEVEL_INACTIVE = 111,
		TRANSLATE_TO = 112,
		Whitespace = 113,
		HEX_CONST = 114,
		NUMBER = 115,
		NEG_INT_CONST = 116,
		HEX_DIGIT = 117,
		DIGIT = 118,
		NUM_3DIGIT = 119,
		NUM_HEX_4DIGIT = 120,
		NUMBER_ADDRESS_OR_WORD = 121,
		PIPE_CHAR = 122,
		NUMBER_SIGN = 123,
		PERCENT = 124,
		AMPERSAND = 125,
		APOSTROPHE = 126,
		STAR = 127,
		PLUS = 128,
		MINUS = 129,
		DOT = 130,
		SEMICOLON = 131,
		QUESTION = 132,
		COMMERCIAL_AT = 133,
		OPENING_SQUARE = 134,
		CLOSING_SQUARE = 135,
		CARET = 136,
		UNDERLINE = 137,
		TILDE = 138,
		DOUBLE_QUOTE = 139,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
#endif /*INC_PFCfgParserTokenTypes_hpp_*/