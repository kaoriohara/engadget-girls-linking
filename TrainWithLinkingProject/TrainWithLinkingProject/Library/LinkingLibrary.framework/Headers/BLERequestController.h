/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "BLEConfirmNotifyCategoryResp.h"
#import "BLEGetSettingInformationResp.h"
#import "BLEGetSettingNameResp.h"
#import "BLEGetPdNotifyDetailData.h"

/**
 Linkingデバイスへの送信時に使用するクラス
 */

@interface BLERequestController : NSObject
<
BLEGetDeviceInformationRespDelegate,
BLEConfirmNotifyCategoryRespDelegate,
BLEGetSettingInformationRespDelegate,
BLEGetSettingNameRespDelegate,
BLEGetPdNotifyDetailDataDelegate
>

@property (assign,nonatomic) int uniquNumber; // NOTIFY_INFORMATION用識別ID
@property (nonatomic, readonly) unsigned short deviceId;
@property (nonatomic, readonly) NSMutableArray *deviceUId;

/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

/**
 初回シーケンス(初回接続時自動実行)
 @param peripheral 送信するデバイスのペリフェラル
 @param characteristic 送信するデバイスのキャラクタリスティック
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)connectingDevice:(CBPeripheral *)peripheral
          characteristic:(CBCharacteristic *)characteristic
              disconnect:(BOOL)disconnect;

/**
 機器情報取得シーケンス
 @param peripheral 送信するデバイスのペリフェラル
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)getDeviceInitialSetting:(CBPeripheral *)peripheral
                     disconnect:(BOOL)disconnect;

/** プロファイル単体 */

/**
 デバイス情報取得
 
 プロファイルGetDeviceInformationの送信
 @param peripheral 送信するデバイスのペリフェラル
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)getDeviceInformationMessage:(CBPeripheral *)peripheral disconnect:(BOOL)disconnect;

/**
 通知カテゴリ確認
 
 プロファイルConfirmNotifyCategoryの送信
 @param peripheral 送信するデバイスのペリフェラル
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)confirmNotifyCategoryMessage:(CBPeripheral *)peripheral disconnect:(BOOL)disconnect;

/**
 設定情報取得
 
 プロファイルGetSettingInformationの送信
 @param peripheral 送信するデバイスのペリフェラル
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)getSettingInformationMessage:(CBPeripheral *)peripheral disconnect:(BOOL)disconnect;

/**
 設定名称取得
 
 プロファイルGetSettingNameRespの送信
 @param peripheral 送信するデバイスのペリフェラル
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)getSettingNameMessage:(CBPeripheral *)peripheral settingNameType:(int)settingNameType disconnect:(BOOL)disconnect;

/** 設定名称データ */

/**
 設定名称データ返却
 
 各種設定名称のデータを返却する
 @param peripheral 取得するデバイスのペリフェラル
 @param SettingNameType 取得したい種別を選択
 @return 指定された種別の設定名称
 */
-(NSArray *)getSettingName:(CBPeripheral*)peripheral settingNameType:(NSUInteger)settingNameType;

/** センサー情報 */

/**
 センサー情報通知設定
 
 センサー情報の通知設定を行う(デリゲートはデフォルトの間隔で呼ばれる)
 @param peripheral 送信するデバイスのペリフェラル
 @param sensorType 取得したいセンサー種別を選択 Gyroscope = 0x00 Accelerometer = 0x01 Orientation = 0x02
 @param status 通知開始 = 0x01 通知停止 = 0x00
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 @warning センサーではcancelはNOに設定され,切断はされない
 */
- (void)setNotifySensorInfoMessage:(CBPeripheral *)peripheral sensorType:(char)sensorType status:(char)status disconnect:(BOOL)disconnect;

/** - + 閾値設定 */

/**
 センサー情報通知設定 + 閾値設定
 
 閾値を指定してセンサー情報の通知設定とを行う(デリゲートはデフォルトの間隔で呼ばれる)
 @param peripheral 送信するデバイスのペリフェラル
 @param sensorType 取得したいセンサー種別を選択 Gyroscope = 0x00 Accelerometer = 0x01 Orientation = 0x02
 @param status 通知開始 = 0x01 通知停止 = 0x00
 @param xThreshold xの閾値を設定
 @param yThreshold yの閾値を設定
 @param zThreshold zの閾値を設定
 @param originalData オリジナルデータがある場合は設定する
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 @warning センサーではcancelはNOに設定され,切断はされない
 */
- (void)setNotifySensorInfoMessage:(CBPeripheral *)peripheral sensorType:(char)sensorType xThreshold:(float) xThreshold yThreshold:(float) yThreshold zThreshold:(float)zThreshold originalData:(NSData *)data disconnect:(BOOL)disconnect;

/** - + 閾値設定 + タイマー設定 */

/**
 センサー情報通知設定 + 閾値設定 + タイマー設定
 
 閾値と通知時間を指定してセンサー情報の通知設定とを行う
 @param peripheral 送信するデバイスのペリフェラル
 @param sensorType 取得したいセンサー種別を選択 Gyroscope = 0x00 Accelerometer = 0x01 Orientation = 0x02
 @param status 通知開始 = 0x01 通知停止 = 0x00
 @param xThreshold xの閾値を設定
 @param yThreshold yの閾値を設定
 @param zThreshold zの閾値を設定
 @param setInterval 通知間隔を設定する
 @param setAutoStopTime 通知終了時間を設定する
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 @warning センサーではcancelはNOに設定され,切断はされない
 */
- (void)setNotifySensorInfoMessage:(CBPeripheral *)peripheral sensorType:(char)sensorType xThreshold:(float) xThreshold yThreshold:(float) yThreshold zThreshold:(float)zThreshold  originalData:(NSData *)data setInterval:(float)setInterval setAutoStopTime:(float)setAutoStopTime disconnect:(BOOL)disconnect;

/**
 設定情報選択
 
 Linkingデバイスの設定を変更する
 @param peripheral 送信するデバイスのペリフェラル
 @param ledSettingDict settingInformationDataの値を設定値に変更して送信
 @param vibrationSettingDict settingInformationDataの値を設定値に変更して送信
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)setSelectSettingInformationWithLED:(NSDictionary *)ledSettingDict
                                 vibration:(NSDictionary *)vibrationSettingDict
                                peripheral:(CBPeripheral *)peripheral
                                disconnect:(BOOL)disconnect;

/**
 設定情報選択
 
 Linkingデバイスのデモを行う
 @param peripheral 送信するデバイスのペリフェラル
 @param ledSettingDict settingInformationDataの値を設定値に変更して送信
 @param vibrationSettingDict settingInformationDataの値を設定値に変更して送信
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)startDemoSelectSettingInformationWithLED:(NSDictionary *)ledSettingDict
                                       vibration:(NSDictionary *)vibrationSettingDict
                                      peripheral:(CBPeripheral *)peripheral
                                      disconnect:(BOOL)disconnect;

/**
 設定情報選択
 
 Linkingデバイスのデモを停止する
 @param peripheral 送信するデバイスのペリフェラル
 @param ledSettingDict settingInformationDataの値を設定値に変更して送信
 @param vibrationSettingDict settingInformationDataの値を設定値に変更して送信
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)stopDemoSelectSettingInformationWithLED:(NSDictionary *)ledSettingDict
                                      vibration:(NSDictionary *)vibrationSettingDict
                                     peripheral:(CBPeripheral *)peripheral
                                     disconnect:(BOOL)disconnect;

/** 端末情報削除 */

/**
 端末情報削除
 
 保存されている端末情報を削除する
 */
- (void)deleteDevices;

/** 情報通知 */

/**
 一般的な情報通知
 
 @param title            タイトル
 @param text             本文
 @param appName          通知元アプリ名
 @param appNameLocal     通知元アプリ名(ローカル)
 @param package          通知元アプリ名(Package名)
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param vibration        バイブレーションの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param deviceId         デバイスID
 @param deviceUId        デバイス固有ID
 @param peripheral       送信するデバイスのペリフェラル
 @param disconnect       YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 識別ID 戻り値の識別IDが-1の場合はパラメータの設定に不備があります。
 */
- (int)sendGeneralInformation:(NSString *)title
                         text:(NSString *)text
                      appName:(NSString *)appName
                 appNameLocal:(NSString *)appNameLocal
                      package:(NSString *)package
                     notifyId:(short)notifyId
             notifyCategoryId:(short)notifyCategoryId
                   ledSetting:(BOOL)ledSetting
             vibrationSetting:(BOOL)vibrationSetting
                          led:(NSMutableDictionary *)led
                    vibration:(NSMutableDictionary *)vibration
                     deviceId:(unsigned short)deviceId
                    deviceUId:(NSMutableArray *)deviceUId
                   peripheral:(CBPeripheral *)peripheral
                   disconnect:(BOOL)disconnect;

/**
 その他の情報通知
 
 @param content1         内容1
 @param content2         内容2
 @param content3         内容3
 @param content4         内容4
 @param content5         内容5
 @param content6         内容6
 @param content7         内容7
 @param imageData        画像データ
 @param imageType        画像データのMIMEタイプ
 @param mediaData        メディアデータ
 @param mediaType        メディアデータのMIMEタイプ
 @param appName          通知元アプリ名
 @param appNameLocal     通知元アプリ名(ローカル)
 @param package          通知元アプリ名(Package名)
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param vibration        バイブレーションの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param deviceId         デバイスID
 @param deviceUId        デバイス固有ID
 @param peripheral       送信するデバイスのペリフェラル
 @param disconnect       YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 識別ID 戻り値の識別IDが-1の場合はパラメータの設定に不備があります。
 */
- (int)sendEtcInformation:(NSData *)content1
                 content2:(NSData *)content2
                 content3:(NSData *)content3
                 content4:(NSData *)content4
                 content5:(NSData *)content5
                 content6:(NSData *)content6
                 content7:(NSData *)content7
                imageData:(NSData *)imageData
                imageType:(NSString *)imageType
                mediaData:(NSData *)mediaData
                mediaType:(NSString *)mediaType
                  appName:(NSString *)appName
             appNameLocal:(NSString *)appNameLocal
                  package:(NSString *)package
                 notifyId:(short)notifyId
         notifyCategoryId:(short)notifyCategoryId
               ledSetting:(BOOL)ledSetting
         vibrationSetting:(BOOL)vibrationSetting
                      led:(NSMutableDictionary *)led
                vibration:(NSMutableDictionary *)vibration
                 deviceId:(unsigned short)deviceId
                deviceUId:(NSMutableArray *)deviceUId
               peripheral:(CBPeripheral *)peripheral
               disconnect:(BOOL)disconnect;

/**
 通知詳細情報の取得応答
 
 プロファイルgetPdNotifyDetailDataRespの呼び出しメソッド
 
 @param uniqueId    識別ID
 @param resultCode  処理結果
 @param paramValue  GET_PD_NOTIFY_DETAIL_DATAで指定されたパラメータIDに紐付くデータ
 @param paramId     GET_PD_NOTIFY_DETAIL_DATAで指定されたパラメータID
 @param peripheral  送信するデバイスのペリフェラル
 @param disconnect  YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)sendGetPdNotifyDetailDataResp:(int)uniqueId resultCode:(Byte)resultCode paramValue:(NSString *)paramValue paramId:(NSString *)paramId peripheral:(CBPeripheral *)peripheral disconnect:(BOOL)disconnect;

/**
 周辺機器からのアプリケーション起動の応答
 
 プロファイルstartPdApplicationRespの呼び出しメソッド
 
 @param result      処理結果
 @param peripheral  送信するデバイスのペリフェラル
 @param disconnect  YESの場合は即時切断、NOの場合は一定間隔をおいて切断す
 */
- (void)sendStartPdApplicationResp:(Byte)result peripheral:(CBPeripheral *)peripheral disconnect:(BOOL)disconnect;

/**
 PhoneIncomingCallの情報通知
 
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param vibration        バイブレーションの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param deviceId         デバイスID
 @param deviceUId        デバイス固有ID
 @param peripheral       送信するデバイスのペリフェラル
 @param disconnect       YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 識別ID 戻り値の識別IDが-1の場合はパラメータの設定に不備があります。
 */
- (int)sendPhoneIncomingCallInformation:(short)notifyId
                       notifyCategoryId:(short)notifyCategoryId
                             ledSetting:(BOOL)ledSetting
                       vibrationSetting:(BOOL)vibrationSetting
                                    led:(NSMutableDictionary *)led
                              vibration:(NSMutableDictionary *)vibration
                               deviceId:(unsigned short)deviceId
                              deviceUId:(NSMutableArray *)deviceUId
                             peripheral:(CBPeripheral *)peripheral
                             disconnect:(BOOL)disconnect;

/**
 PhoneInCallの情報通知
 
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param vibration        バイブレーションの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param deviceId         デバイスID
 @param deviceUId        デバイス固有ID
 @param peripheral       送信するデバイスのペリフェラル
 @param disconnect       YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 識別ID 戻り値の識別IDが-1の場合はパラメータの設定に不備があります。
 */
- (int)sendPhoneInCallInformation:(short)notifyId
                 notifyCategoryId:(short)notifyCategoryId
                       ledSetting:(BOOL)ledSetting
                 vibrationSetting:(BOOL)vibrationSetting
                              led:(NSMutableDictionary *)led
                        vibration:(NSMutableDictionary *)vibration
                         deviceId:(unsigned short)deviceId
                        deviceUId:(NSMutableArray *)deviceUId
                       peripheral:(CBPeripheral *)peripheral
                       disconnect:(BOOL)disconnect;

/**
 PhoneIdleの情報通知
 
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param vibration        バイブレーションの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param deviceId         デバイスID
 @param deviceUId        デバイス固有ID
 @param peripheral       送信するデバイスのペリフェラル
 @param disconnect       YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 識別ID 戻り値の識別IDが-1の場合はパラメータの設定に不備があります。
 */
- (int)sendPhoneIdleInformation:(short)notifyId
               notifyCategoryId:(short)notifyCategoryId
                     ledSetting:(BOOL)ledSetting
               vibrationSetting:(BOOL)vibrationSetting
                            led:(NSMutableDictionary *)led
                      vibration:(NSMutableDictionary *)vibration
                       deviceId:(unsigned short)deviceId
                      deviceUId:(NSMutableArray *)deviceUId
                     peripheral:(CBPeripheral *)peripheral
                     disconnect:(BOOL)disconnect;

/**
 Mailの情報通知
 
 @param title            タイトル
 @param text             本文
 @param appName          通知元アプリ名
 @param appNameLocal     通知元アプリ名(ローカル)
 @param package          通知元アプリ名(Package名)
 @param sender           送信者
 @param senderAddress    送信アドレス
 @param receiveDate      受信日時
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param vibration        バイブレーションの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param deviceId         デバイスID
 @param deviceUId        デバイス固有ID
 @param peripheral       送信するデバイスのペリフェラル
 @param disconnect       YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 識別ID 戻り値の識別IDが-1の場合はパラメータの設定に不備があります。
 */
- (int)sendMailInformation:(NSString *)title
                      text:(NSString *)text
                   appName:(NSString *)appName
              appNameLocal:(NSString *)appNameLocal
                   package:(NSString *)package
                    sender:(NSString *)sender
             senderAddress:(NSString *)senderAddress
               receiveDate:(NSDate *)receiveDate
                  notifyId:(short)notifyId
          notifyCategoryId:(short)notifyCategoryId
                ledSetting:(BOOL)ledSetting
          vibrationSetting:(BOOL)vibrationSetting
                       led:(NSMutableDictionary *)led
                 vibration:(NSMutableDictionary *)vibration
                  deviceId:(unsigned short)deviceId
                 deviceUId:(NSMutableArray *)deviceUId
                peripheral:(CBPeripheral *)peripheral
                disconnect:(BOOL)disconnect;

/**
 Scheduleの情報通知
 
 @param title            タイトル
 @param text             テキスト(詳細)
 @param appName          通知元アプリ名
 @param appNameLocal     通知元アプリ名(ローカル)
 @param package          通知元アプリ名(Package名)
 @param startDate        開始日時
 @param endDate          終了日時
 @param area             エリア
 @param person           パーソン
 @param Contents1        内容1
 @param Contents2        内容2
 @param Contents3        内容3
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param vibration        バイブレーションの設定値（settingInformationDataの値をNSMutableDictionary型に格納）
 @param deviceId         デバイスID
 @param deviceUId        デバイス固有ID
 @param peripheral       送信するデバイスのペリフェラル
 @param disconnect       YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 識別ID 戻り値の識別IDが-1の場合はパラメータの設定に不備があります。
 */
- (int)sendScheduleInformation:(NSString *)title
                          text:(NSString *)text
                       appName:(NSString *)appName
                  appNameLocal:(NSString *)appNameLocal
                       package:(NSString *)package
                     startDate:(NSDate *)startDate
                       endDate:(NSDate *)endDate
                          area:(NSString *)area
                        person:(NSString *)person
                      content1:(NSData *)content1
                      content2:(NSData *)content2
                      content3:(NSData *)content3
                      notifyId:(short)notifyId
              notifyCategoryId:(short)notifyCategoryId
                    ledSetting:(BOOL)ledSetting
              vibrationSetting:(BOOL)vibrationSetting
                           led:(NSMutableDictionary *)led
                     vibration:(NSMutableDictionary *)vibration
                      deviceId:(unsigned short)deviceId
                     deviceUId:(NSMutableArray *)deviceUId
                    peripheral:(CBPeripheral *)peripheral
                    disconnect:(BOOL)disconnect;


/**　端末設定 */

/**　getAppVersionMessage:非対応
 confirmInstallAppMessage:非対応
 */
//- (void)getAppVersionMessage:(CBPeripheral *)peripheral setData:(NSData *)setData disconnect:(BOOL)disconnect;
//- (void)confirmInstallAppMessage:(CBPeripheral *)peripheral appName:(NSData *)appName fileVer:(NSData *)fileVer     fileSize:(int)fileSize disconnect:(BOOL)disconnect;

@end
