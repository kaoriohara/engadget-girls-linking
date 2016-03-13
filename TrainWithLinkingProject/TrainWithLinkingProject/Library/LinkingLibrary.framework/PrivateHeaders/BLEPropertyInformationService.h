/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */
#import <Foundation/Foundation.h>
#import "BLEConnecter.h"

@interface BLEPropertyInformationService : NSObject

/*
 * メッセージID
 * PropertyInformationサービスでサポートしているメッセージIDを定義
 */
typedef NS_ENUM(NSUInteger, PropertyInformationMsgID) {
    MsgIDGetDeviceInformation     = 0x00,
    MsgIDGetDeviceInformationResp = 0x01,
};

typedef NS_ENUM(NSUInteger, PropertyInformationServiceParamID) {
    PropertyInformationServiceParamIDResultCode							= 0x00,
    PropertyInformationServiceParamIDCancel								= 0x01,
    PropertyInformationServiceParamIDServiceList						= 0x02,
    PropertyInformationServiceParamIDDeviceId							= 0x03,
    PropertyInformationServiceParamIDDeviceUid							= 0x04,
    PropertyInformationServiceParamIDDeviceCapability					= 0x05,
    PropertyInformationServiceParamIDOriginalInformation	         = 0x06,
    PropertyInformationServiceParamIDExSensorType			         = 0x07,
};

typedef NS_ENUM(NSUInteger, PropertyInformationServiceOriginalInfo) {
    PropertyInformationServiceOriginalInfoAppname         = 0x00,
    PropertyInformationServiceOriginalInfoAppnameLocal    = 0x01,
    PropertyInformationServiceOriginalInfoAppdlUrl1       = 0x02,
    PropertyInformationServiceOriginalInfoAppdlUrl2       = 0x03,
    PropertyInformationServiceOriginalInfoAppdlUrl3       = 0x04,
    PropertyInformationServiceOriginalInfoAppExecInfO1    = 0x05,
    PropertyInformationServiceOriginalInfoAPPExecInfO2    = 0x06,
    PropertyInformationServiceOriginalInfoAPPExecInfO3    = 0x07,
    PropertyInformationServiceOriginalInfoAppPackage      = 0x08,
    PropertyInformationServiceOriginalInfoReserved        = 0x09,
};

/**
 デバイス情報取得
 
 プロファイルgetDeviceInformationのデータ作成
 
 @param peripheral 送信するデバイスのペリフェラル
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 送信するデータ
 */
- (NSData *)getDeviceInformation:(CBPeripheral *)peripheral disconnect:(BOOL)disconnect;

/**
 Linkingデバイス側からの受信データをメッセージID毎に振り分けるメソッド
 
 @param peripheral  受信したデバイスのペリフェラル
 @param messageID   メッセージID
 @param length      データ長
 @param data        受信データ
 */
-(void)responce:(CBPeripheral *)peripheral
 selectmessasge:(Byte)messageID
         length:(Byte)length
       withData:(NSData *)data;

@end
