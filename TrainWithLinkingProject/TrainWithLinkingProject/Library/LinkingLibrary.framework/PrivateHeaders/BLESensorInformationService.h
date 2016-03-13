/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "BLEConnecter.h"

@interface BLESensorInformationService : NSObject

/*
 * メッセージID
 * SensorInformationサービスでサポートしているメッセージIDを定義
 */
typedef NS_ENUM(NSUInteger, SensorInformationMsgID) {
    MsgIDGetSensorInfo           = 0x00,
    MsgIDGetSensorInfoResp       = 0x01,
    MsgIDSetNotifySensorInfo     = 0x02,
    MsgIDSetNotifySensorInfoResp = 0x03,
    MsgIDNotifyPdSensorInfo      = 0x04
};

typedef NS_ENUM(NSUInteger, NotifyPdSensorInfoParamID) {
    NotifyPdSensorInfoParamIDResultCode           = 0x00,
    NotifyPdSensorInfoParamIDCancel               = 0x01,
    NotifyPdSensorInfoParamIDSensorType           = 0x02,
    NotifyPdSensorInfoParamIDStatus               = 0x03,
    NotifyPdSensorInfoParamIDX_value              = 0x04,
    NotifyPdSensorInfoParamIDY_value              = 0x05,
    NotifyPdSensorInfoParamIDZ_value              = 0x06,
    NotifyPdSensorInfoParamIDX_threshold          = 0x07,
    NotifyPdSensorInfoParamIDY_threshold          = 0x08,
    NotifyPdSensorInfoParamIDZ_threshold          = 0x09,
    NotifyPdSensorInfoParamIDOriginalData         = 0x0A
};

typedef NS_ENUM(NSUInteger, SensorInformationSensorType) {
    SensorInformationSensorTypeGyroscope     = 0x00,
    SensorInformationSensorTypeAccelerometer = 0x01,
    SensorInformationSensorTypeOrientation   = 0x02,
};

/**
 センサー情報取得
 
 プロファイルgetSensorInfoのデータ作成
 
 @param peripheral 送信するデバイスのペリフェラル
 @param sensorType センサー種別
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 送信するデータ
 */
- (NSData *)getSensorInformation:(CBPeripheral *)peripheral sensorType:(char)sensorType disconnect:(BOOL)disconnect;

/**
 センサー情報通知設定
 
 プロファイルsetNotifySensorInfoのデータ作成
 
 @param peripheral 送信するデバイスのペリフェラル
 @param sensorType センサー種別
 @param status     ステータス
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 送信するデータ
 */
- (NSData *)setNotifySensorInfo:(CBPeripheral *)peripheral sensorType:(char)sensorType status:(char)Status disconnect:(BOOL)disconnect;

/**
 センサー情報取得の応答
 
 プロファイルgetSensorInfoRespのデータ作成
 
 @param peripheral 送信するデバイスのペリフェラル
 @param sensorType センサー種別
 @param xThreshold X軸値
 @param yThreshold Y軸値
 @param zThreshold Z軸値
 @param data       独自データ
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 送信するデータ
 */
- (NSData *)setNotifySensorInfo:(CBPeripheral *)peripheral
                     sensorType:(char)sensorType
                     xThreshold:(float)xThreshold
                     yThreshold:(float)yThreshold
                     zThreshold:(float)zThreshold
                   originalData:(NSData*)data
                     disconnect:(BOOL)disconnect;

/**
 Linkingデバイス側からの受信データをメッセージID毎に振り分けるメソッド
 
 @param peripheral  受信したデバイスのペリフェラル
 @param messageID   メッセージID
 @param length      データ長
 @param data        受信データ
 */
- (void)responce:(CBPeripheral *)peripheral
  selectmessasge:(Byte)messageID
          length:(Byte)length
        withData:(NSData *)data;

@end
