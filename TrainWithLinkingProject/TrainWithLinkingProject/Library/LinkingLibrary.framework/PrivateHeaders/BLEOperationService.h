/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "BLEConnecter.h"

@interface BLEOperationService : NSObject

/*
 * メッセージID
 * OperationサービスでサポートしているメッセージIDを定義
 */
typedef NS_ENUM(NSUInteger, OperationMsgID) {
    MsgIDNotifyPdOperation      = 0x00
};

typedef NS_ENUM(NSUInteger, OperationParamID) {
    OperationParamIDResult      = 0x00,
    OperationParamIDCancel      = 0x01,
    OperationParamIDButtonID    = 0x02,
};

typedef NS_ENUM(NSUInteger, ButtonID) {
    ButtonIDPower           = 0x00,
    ButtonIDReturn          = 0x01,
    ButtonIDEnter           = 0x02,
    ButtonIDHome            = 0x03,
    ButtonIDMenu            = 0x04,
    ButtonIDVolumeUp        = 0x05,
    ButtonIDVolumeDown      = 0x06,
    ButtonIDPlay            = 0x07,
    ButtonIDPause           = 0x08,
    ButtonIDStop            = 0x09,
    ButtonIDFastForward     = 0x0A,
    ButtonIDReWind          = 0x0B,
    ButtonIDShutter         = 0x0C,
    ButtonIDUp              = 0x0D,
    ButtonIDDown            = 0x0E,
    ButtonIDLeft            = 0x0F,
    ButtonIDRight           = 0x10,
};

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

/**
 デバイス操作通知受信データクラスを呼び出すメソッド
 
 @param peripheral  受信したデバイスのペリフェラル
 @param length      データ長
 @param data        受信データ
 */
- (void)operationNotification:(CBPeripheral *)peripheral
                       length:(Byte)length
                     withData:(NSData *)data;

@end
