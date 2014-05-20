#ifndef ECWMBUS_H
#define ECWMBUS_H

#include <windows.h>
#include <stdint.h>
#include <stdio.h>

//multiplatform
#ifndef max
  #define max(x,y) ((x>y) ? x:y)
  #define min(x,y) ((x>y) ? y:x)
#endif

#ifndef TRUE
    #define TRUE  (1==1)
    #define FALSE (1==2)
#endif

#define XSIZE     320
#define YSIZE      80

//Logging modes
#define LOGTOCSV 0
#define LOGTOVZ  1
#define LOGTOXML 2
#define LOGTODAT 3


//show Information
#define SILENTMODE 0
#define SHOWDETAILS 1
#define SHOWALLDETAILS 2


//wMBUS Sticks
#define WMBUSSTICK1 1
#define WMBUSSTICK2 2




//App defines
#define MAXMETER 16 

#define FASTFORWARD             0x18C4
#define AES_KEYLENGHT_IN_BYTES  16

#pragma pack(push,1)
typedef struct _WMBUS_METER {
    uint16_t  manufacturerID;
    uint32_t  ident;
    uint8_t   version;
    uint8_t   type;
    uint8_t   key[AES_KEYLENGHT_IN_BYTES];
} ecwMBUSMeter, *pecwMBUSMeter;
#pragma pack(pop)

#define RFDATA_ENCRYPTED 0x01
#define RFDATA_NOT_ENCRYPTED 0x02

typedef struct _RF_DATA {
    uint32_t time;      // UNIX epoch time
    uint32_t value;     // OCR value in integer
    int8_t   exp;       // OCR value exponent
    uint8_t  accNo;     // RF packet access number, should be ascending and wraps
    int8_t   rssiDBm;   // rssi in dbm
    uint8_t  pktInfo;   // EC packet info
    uint8_t  utcnt_pic;   // Unique transmission counter (OCR picture count)
    uint8_t  utcnt_tx;    // Unique transmission counter (tx count)
    uint8_t  status;      // wMbus Status
    uint16_t configWord;  // wMbus ConfigWord
    uint32_t mbusID;      // MBus ID (8 BCD)
    bool valDuringErrState; // valDuringErrState: True when OCR could not be done, e.g. when SA is de-mounted, and ocr is repeated by last valid value (See "Value during error state" in M-Bus spec, coded in DIF[5:4])
} ecMBUSData, *psecMBUSData;


void ErrorAndExit(const char *info);

#endif
