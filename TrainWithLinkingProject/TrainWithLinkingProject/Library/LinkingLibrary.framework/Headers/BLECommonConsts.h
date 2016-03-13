/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */
/* !!COMMON_MODULE_VERSION_INFO */


#ifndef COMMON_MODULE_VERSION_INFO
#define COMMON_MODULE_VERSION_INFO @"1.0.0"
#endif


#import <Foundation/Foundation.h>

static NSString * const kUUIDDeviceLinkService = @"b3b36901-50d3-4044-808d-50835b13a6cd";
static NSString * const kUUIDCharacteristicWriteMessage = @"b3b39101-50d3-4044-808d-50835b13a6cd";
static NSString * const kUUIDCharacteristicIndicateMessage = @"b3b39102-50d3-4044-808d-50835b13a6cd";
/**
 定数クラス
 */
@interface BLECommonConsts : NSObject

/**
 Packet structure[20byte]
 */
// length of packet
extern int const BLEPacketLength;

// length of packet header
extern int const BLEPacketHeaderLength;

// length of packet payload
extern int const BLEPacketPayloadLength;

/**
 Packet header structure[1byte]
 */
// source flag.
extern const char BLEPacketHeaderSourceClient;
extern const char BLEPacketHeaderSourceServer;

// cancel flag.
extern const char BLEPacketHeaderCancelOff;
extern const char BLEPacketHeaderCancelOn;

// default sequnece number.
extern const char BLEPacketHeaderDefaultSeqNum;

// terminal flag.
extern const char BLEPacketHeaderExecuteOff;
extern const char BLEPacketHeaderExecuteOn;

// bit mask of source flag.
extern const char BLEBitMaskOfPacketHeaderSource;

// bit mask of cancel flag.
extern const char BLEBitMaskOfPacketHeaderCancel;

// bit mask of sequence number.
extern const char BLEBitMaskOfPacketHeaderSequence;

// bit mask of terminal flag.
extern const char BLEBitMaskOfPacketExecute;

/**
 Packet payload structure[4byte + nbyte]
 */
// length of payload header
extern int const BLEPayloadHeaderLength;

// length of service id
extern int const BLEPayloadHeaderServiceIdLength;

// length of message id
extern int const BLEPayloadHeaderMessageIdLength;

// length of parameters number
extern int const BLEPayloadHeaderParametersLength;

/**
 data parameter structure[1byte + 3byte + nbyte]
 */
// length of parameter id
extern int const BLEPayloadParameterIdLength;

// length of parameter length
extern int const BLEPayloadParameterlenLength;

/**
 service id, category id definition
 */
// Service ID definition
extern const char BLEServiceIdPropertyInformation;
extern const char BLEServiceIdNotification;
extern const char BLEServiceIdOperation;
extern const char BLEServiceIdSensorInformation;
extern const char BLEServiceIdSettingOperation;

// general
extern const char BLEZeroPadding;
extern int const BLEWorkBufferSize;
extern int const BLEParameterLength;
extern int const BLEPayloadSize;

extern const char BLEChar0x00;
extern const char BLEChar0x01;
extern const char BLEChar0x02;
extern const char BLEChar0x03;
extern const char BLEChar0x04;
extern const char BLEChar0x05;
extern const char BLEChar0x06;
extern const char BLEChar0x07;
extern const char BLEChar0x08;
extern const char BLEChar0x09;
extern const char BLEChar0x10;
extern const char BLEChar0x20;

extern const char BLEBit0x01;
extern const char BLEBit0x02;
extern const char BLEBit0x04;
extern const char BLEBit0x08;
extern const char BLEBit0x10;
extern const char BLEBit0x20;
extern const char BLEBit0x40;
extern const char BLEBit0x80;
extern const char BLEBit0x3E;
extern const char BLEBit0x7F;
extern const char BLEBit0xBF;
extern const char BLEBit0xFE;

+ (NSString*)versionInfo;

@end
