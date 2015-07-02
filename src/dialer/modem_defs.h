/*
 * modem_defs.h
 *
 *  Created on: Jun 15, 2015
 *      Author: jcobb
 */

#ifndef MODEM_DEFS_H_
#define MODEM_DEFS_H_

#include "modem.h"

typedef void (*callback_func_t)(void);
typedef void (*callback_funcex_t)(char * token, uint8_t seconds, sys_result *result);

typedef struct
{
	uint8_t *cmd;
	char *result;
	uint32_t timeout;
	uint8_t retries;
	callback_funcex_t callback;
}at_command_t;

typedef struct
{
	uint8_t *cmd;
	char *result;
	uint32_t timeout;
	uint8_t retries;
	callback_func_t callback;
}at_command_cnx_t;


typedef struct
{
	uint8_t busy;
	uint8_t context;
	uint8_t signal;
	uint8_t creg;
	uint8_t connected;
}modem_status_t;


extern modem_status_t modem_status;


#define MODEM_RESULT_NODATA			0X00
#define MODEM_RESULT_FOUND			0X01
#define MODEM_RESULT_ERROR			0X02
#define MODEM_RESULT_NOCARRIER		0X03


// *** MODEM SPECIFIC TOKENS ***
#define MODEM_TOKEN_OK				"OK"
#define MODEM_TOKEN_ERROR			"ERROR"
#define MODEM_TOKEN_CONNECT			"CONNECT"
#define MODEM_TOKEN_NOCARRIER		"NO CARRIER"
#define MODEM_TOKEN_PROMPT			">"
#define MODEM_TOKEN_CMGS			"+CMGS:"
#define MODEM_TOKEN_CREG			"+CREG:"
#define MODEM_TOKEN_MONI			"#MONI:"
#define MODEM_TOKEN_GPRS_ACT		"+IP:"
#define MODEM_TOKEN_SGACT			"#SGACT:"
#define MODEM_TOKEN_ACK				"ACK"
#define MODEM_TOKEN_CMGL			"+CMGL:"
#define MODEM_TOKEN_CMGR			"+CMGR:"
#define MODEM_TOKEN_REMOTECMD		"$"




#define CR							'\r'
#define LF							'\n'
#define MODEM_CMD_CTRLZ				0x1a
#define MODEM_CMD_ESCAPE			0x1b
#define MODEM_CMD_AT				"AT\r"
#define MODEM_CMD_ATF				"AT&F\r"
#define MODEM_CMD_ECHOOFF			"ATE0\r"
#define MODEM_CMD_SELINT			"AT#SELINT=2\r"
#define MODEM_CMD_ATZ				"ATZ\r"

#define MODEM_CMD_MSGFMT			"AT+CMGF=1\r"
#define MODEM_CMD_MONI				"AT#MONI\r"
#define MODEM_CMD_CFUN				"AT+CFUN=1\r"
#define MODEM_CMD_CREG				"AT+CREG=1\r"
#define MODEM_CMD_GAUTH				"AT#GAUTH=0\r"
#define MODEM_CMD_QUERYNETWORK		"AT+CREG?\r"
#define MODEM_CMD_QUERYSIGNAL		"AT+CSQ?\r"
#define MODEM_CMD_SETCONTEXT		"AT+CGDCONT=1,\"IP\",\"c1.korem2m.com\"\r"
//#define MODEM_CMD_SETCONTEXT		"AT+CGDCONT=1,\"IP\",\"a10.korem2m.com\"\r"
#define MODEM_CMD_DIAL				"ATD*99***1#\r"

#define MODEM_CMD_QUERYCONTEXT		"AT#SGACT?\r"
#define MODEM_CMD_DEACTCONTEXT		"AT#SGACT=1,0\r"
#define MODEM_CMD_DEACTGPRS			"AT#GPRS=0\r" // UNUSED: FAVOR OF CMD_DEACT_CONTEXT
#define MODEM_CMD_ACTGPRS			"AT#GPRS=1\r" // UNUSED: FAVOR OF CMD_ACT_CONTEXT
#define MODEM_CMD_LISTENUDP			"AT#SLUDP=1,1,3500\r"

#define MODEM_CMD_SENDSMS			"AT+CMGS=\"8126290240\"\r\nHello World\r\n\032"




#define MODEM_CMD_SETBAND		"AT#BND=1\r"	// 850/1900 default
//#define MODEM_CMD_SETCONTEXT	"AT+CGDCONT=1,\"IP\",\"%s\"\r"
//#define CMD_USERID			"AT#USERID=\"\"\r"
//#define CMD_PASSWORD			"AT#PASSW=\"\"\r"
//#define MODEM_CMD_USERID2		"AT#USERID=\"%s\"\r"
//#define MODEM_CMD_PASSWORD2		"AT#PASSW=\"%s\"\r"




#ifdef MODEM_TYPE_CDMA
	#define MODEM_CMD_CDMA_QUERY_PROV	"AT$QCMIPGETP\r"
	#define MODEM_TOKEN_CDMA_PROV0		"Profile:"
	#define MODEM_TOKEN_CDMA_PROV1		"NAI:"
	#define MODEM_TOKEN_CDMA_PROV2		"Home:"
	#define MODEM_TOKEN_CDMA_PROV3		"Primary:"
	#define MODEM_TOKEN_CDMA_PROV4		"Secondary:"
	#define MODEM_TOKEN_CDMA_PROV5		"MN-AAA SPI:"
	#define MODEM_TOKEN_CDMA_PROV6		"MN-HA SPI:"
	#define MODEM_TOKEN_CDMA_PROV7		"Rev Tun:"
	#define MODEM_TOKEN_CDMA_PROV8		"MN-AAA SET:"
	#define MODEM_TOKEN_CDMA_PROV9		"MN-HA SET:"

	#define MODEM_CMD_CDMA_QUERY_MEID			"AT#MEID?\r"
	#define MODEM_TOKEN_CDMA_MEID				"#MEID:"
	#define MODEM_CMD_CDMA_QUERY_MODEMVER		"AT+CGMR\r"
	#define MODEM_TOKEN_CDMA_MODEMVER			"09.01"	//"09.01.020"

	#define MODEM_CMD_CDMA_ATD_OTA				"ATD*22899;\r"
	#define MODEM_TOKEN_CDMA_OTA				"#OTASP:"
	#define MODEM_TOKEN_CDMA_OTA0				"#OTASP:0"
	#define MODEM_TOKEN_CDMA_OTA1				"#OTASP:1"
	#define MODEM_TOKEN_CDMA_OTA2				"#OTASP:2"
	#define MODEM_TOKEN_CDMA_OTA5				"#OTASP:5"


	#define MODEM_CMD_CDMA_QUERY_PROFILENAI				"AT$QCMIPP?\r"
	#define MODEM_TOKEN_CDMA_RSP_PROFILENAI				"$QCMIPP:"
	#define MODEM_CMD_CDMA_SET_SELECTPROFILENAI_0		"AT$QCMIPP=0\r"
	#define MODEM_CMD_CDMA_SET_SELECTPROFILENAI_1		"AT$QCMIPP=1\r"
	//2. Ensure that NAI Profile 1 is enabled.
	#define MODEM_CMD_CDMA_QRY_PROFILENAIENABLED		"AT$QCMIPEP?\r"
	#define MODEM_TOKEN_CDMA_PROFILENAIENABLED			"$QCMIPEP:"
	#define MODEM_CMD_CDMA_SET_ENABLEPROFILENAI			"AT$QCMIPEP=1\r"
	#define MODEM_CMD_CDMA_SET_DISABLEPROFILENAI		"AT$QCMIPEP=0\r"

	//3. Enable Mobile IP
	#define MODEM_CMD_CDMA_QUERY_MOBILEIPENABLED		"AT$QCMIP?\r"
	#define MODEM_TOKEN_CDMA_RSP_MOBILEIPENABLED		"$QCMIP:"
	#define MODEM_CMD_CDMA_SET_ENABLEMOBILEIP			"AT$QCMIP=2\r"
#endif






#endif /* MODEM_DEFS_H_ */
