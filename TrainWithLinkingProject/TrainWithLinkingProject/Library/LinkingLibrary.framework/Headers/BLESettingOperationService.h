/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "BLEConnecter.h"

@interface BLESettingOperationService : NSObject

/*
 * メッセージID
 * SettingOperationサービスでサポートしているメッセージIDを定義
 */
typedef NS_ENUM(NSUInteger, SettingOperationMsgID) {
    MsgIDGetAppVersion                = 0x00,
    MsgIDGetAppVersionResp            = 0x01,
    MsgIDConfirmInstallApp            = 0x02,
    MsgIDConfirmInstallAppResp        = 0x03,
    MsgIDGetSettingInformation        = 0x04,
    MsgIDGetSettingInformationResp    = 0x05,
    MsgIDGetSettingName               = 0x06,
    MsgIDGetSettingNameResp           = 0x07,
    MsgIDSelectSettingInformation     = 0x08,
    MsgIDSelectSettingInformationResp = 0x09,
};

typedef NS_ENUM(NSUInteger, SettingOperationParamID) {
    SettingoperationParamIDResultCode							= 0x00,
    SettingoperationParamIDCancel								= 0x01,
    SettingoperationParamIDSettingType							= 0x02,
    SettingoperationParamIDAppName								= 0x03,
    SettingoperationParamIDFilever								= 0x04,
    SettingoperationParamIDFileSize							   = 0x05,
    SettingoperationParamIDInstallConfirmStatus          = 0x06,
    SettingoperationParamIDSettingInformationRequest     = 0x07,
    SettingoperationParamIDSettingInformationData			= 0x08,
    SettingoperationParamIDSettingNameData					= 0x09,
};

typedef NS_ENUM(NSUInteger, SettingOperationNameType) {
    SettingOperationNameTypeLEDColorName							= 1,
    SettingOperationNameTypeLEDPatten								= 2,
    SettingOperationNameTypeVibrationPatternName				= 3,
    SettingOperationNameTypeNotificationDurationPatternName = 4,
    SettingOperationNameTypeReserved								= 5,

};

typedef NS_ENUM(NSUInteger, SettingOperationSettingInformationDataIdentifier) {
    SettingOperationSettingInformationDataIdentifierLED       = 0x00,
    SettingOperationSettingInformationDataIdentifierVibration = 0x01,
    SettingOperationSettingInformationDataIdentifierTime      = 0x02,
};

typedef NS_ENUM(NSUInteger, SettingOperationSelectSetting) {
    SettingOperationSelectSettingSetting       = 0x00,
    SettingOperationSelectSettingStart         = 0x01,
    SettingOperationSelectSettingStop          = 0x02,
};

/**
 設定情報取得
 
 プロファイルgetSettingInformationのデータ作成
 
 @param peripheral 送信するデバイスのペリフェラル
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 送信するデータ
 */
- (NSData *)getSettingInformation:(CBPeripheral *)peripheral disconnect:(BOOL)disconnect;

/**
 設定情報取得
 
 プロファイルgetSettingInformationのデータ作成
 
 @param peripheral 送信するデバイスのペリフェラル
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 送信するデータ
 */
- (NSData *)getAppVersionData:(CBPeripheral *)peripheral setData:(NSData *)setData disconnect:(BOOL)disconnect;

/**
 アプリインストール確認要求
 
 プロファイルconfirmInstallAppのデータ作成
 
 @param peripheral 送信するデバイスのペリフェラル
 @param appName    アプリ名(Package名)
 @param fileVer    ファイルバージョン/アプリバージョン
 @param fileSize   ファイルサイズ
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 送信するデータ
 */
- (NSData *)confirmInstallApp:(CBPeripheral *)peripheral appName:(NSData *)appName fileVer:(NSData *)fileVer fileSize:(int)fileSize disconnect:(BOOL)disconnect;

/**
 設定名称取得
 
 プロファイルgetSettingNameのデータ作成
 
 @param peripheral    送信するデバイスのペリフェラル
 @param getValueType  設定種別
 @param disconnect    YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 送信するデータ
 */
- (NSData *)getSettingName:(CBPeripheral *)peripheral getValueType:(int)getValueType disconnect:(BOOL)disconnect;

/**
 設定情報選択
 
 プロファイルselectSettingInformationのデータ作成
 
 @param ledSetting        settingInformationDataの値を設定値に変更
 @param vibrationSetting  settingInformationDataの値を設定値に変更
 @param settingType       設定値識別子 0x00=設定要求 0x01=設定デモ要求 0x02=設定デモ停止要求
 
 @return 送信するデータ
 */
- (NSData *)makeSelectSettingInformationMessageWithLED:(NSDictionary *)ledSetting vibration:(NSDictionary *)vibrationSetting settingType:(Byte)settingType;

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
