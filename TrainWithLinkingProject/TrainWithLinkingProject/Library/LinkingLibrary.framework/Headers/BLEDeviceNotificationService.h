/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "BLEConnecter.h"

extern NSString *const BLEPdNotifyInformationParamKeyTitle;
extern NSString *const BLEPdNotifyInformationParamKeyText;
extern NSString *const BLEPdNotifyInformationParamKeyContent1;
extern NSString *const BLEPdNotifyInformationParamKeyContent2;
extern NSString *const BLEPdNotifyInformationParamKeyContent3;
extern NSString *const BLEPdNotifyInformationParamKeyContent4;
extern NSString *const BLEPdNotifyInformationParamKeyContent5;
extern NSString *const BLEPdNotifyInformationParamKeyContent6;
extern NSString *const BLEPdNotifyInformationParamKeyContent7;
extern NSString *const BLEPdNotifyInformationParamKeyContent8;
extern NSString *const BLEPdNotifyInformationParamKeyContent9;
extern NSString *const BLEPdNotifyInformationParamKeyContent10;
extern NSString *const BLEPdNotifyInformationParamKeyImage;
extern NSString *const BLEPdNotifyInformationParamKeyImageType;
extern NSString *const BLEPdNotifyInformationParamKeyMedia;
extern NSString *const BLEPdNotifyInformationParamKeyMediaType;
extern NSString *const BLEPdNotifyInformationParamKeyAppName;
extern NSString *const BLEPdNotifyInformationParamKeyAppNameLocal;
extern NSString *const BLEPdNotifyInformationParamKeyPackage;
extern NSString *const BLEPdNotifyInformationParamKeyNotifyId;
extern NSString *const BLEPdNotifyInformationParamKeyNotifyCategoryId;
extern NSString *const BLEPdNotifyInformationParamKeySender;
extern NSString *const BLEPdNotifyInformationParamKeySenderAddress;
extern NSString *const BLEPdNotifyInformationParamKeyReceiveDate;
extern NSString *const BLEPdNotifyInformationParamKeyStartDate;
extern NSString *const BLEPdNotifyInformationParamKeyEndDate;
extern NSString *const BLEPdNotifyInformationParamKeyArea;
extern NSString *const BLEPdNotifyInformationParamKeyPerson;

@interface BLEDeviceNotificationService : NSObject

typedef NS_ENUM(NSUInteger, NotificationMsgID) {
    MsgIDConfirmNotifyCategory        = 0x00,
    MsgIDConfirmNotifyCategoryResp    = 0x01,
    MsgIDNotifyInformation            = 0x02,
    MsgIDGetPdNotifyDetailData        = 0x03,
    MsgIDGetPdNotifyDetailDataResp    = 0x04,
    MsgIDNotifyPdGeneralInformation   = 0x05,
    MsgIDStartPdApplication           = 0x06,
    MsgIDStartPdApplicationResp       = 0x07,
};

typedef NS_ENUM(NSUInteger, NotificationServiceParamID) {
    NotificationServiceParamIDResultCode            = 0x00,
    NotificationServiceParamIDCancel                = 0x01,
    NotificationServiceParamIDGetStatus             = 0x02,
    NotificationServiceParamIDNotifyCategory        = 0x03,
    NotificationServiceParamIDNotifyCategoryID      = 0x04,
    NotificationServiceParamIDGetParameterID        = 0x05,
    NotificationServiceParamIDGetParameterLength    = 0x06,
    NotificationServiceParamIDParameterIdList       = 0x07,
    NotificationServiceParamIDUniqueId              = 0x08,
    NotificationServiceParamIDNotifyId              = 0x09,
    NotificationServiceParamIDNotificationOperation = 0x0A,
    NotificationServiceParamIDTitle                 = 0x0B,
    NotificationServiceParamIDText                  = 0x0C,
    NotificationServiceParamIDAppName               = 0x0D,
    NotificationServiceParamIDAppNameLocal          = 0x0E,
    NotificationServiceParamIDNotifyApp             = 0x0F,
    NotificationServiceParamIDRumblingSetting       = 0x10,
    NotificationServiceParamIDVibrationPattern      = 0x11,
    NotificationServiceParamIDLedPattern            = 0x12,
    NotificationServiceParamIDSender                = 0x13,
    NotificationServiceParamIDSenderAddress         = 0x14,
    NotificationServiceParamIDReceiveDate           = 0x15,
    NotificationServiceParamIDStartDate             = 0x16,
    NotificationServiceParamIDEndDate               = 0x17,
    NotificationServiceParamIDArea                  = 0x18,
    NotificationServiceParamIDPerson                = 0x19,
    NotificationServiceParamIDMimeTypeForImage      = 0x1A,
    NotificationServiceParamIDMimeTypeForMedia      = 0x1B,
    NotificationServiceParamIDImage                 = 0x1C,
    NotificationServiceParamIDContents1             = 0x1D,
    NotificationServiceParamIDContents2             = 0x1E,
    NotificationServiceParamIDContents3             = 0x1F,
    NotificationServiceParamIDContents4             = 0x20,
    NotificationServiceParamIDContents5             = 0x21,
    NotificationServiceParamIDContents6             = 0x22,
    NotificationServiceParamIDContents7             = 0x23,
    NotificationServiceParamIDContents8             = 0x24,
    NotificationServiceParamIDContents9             = 0x25,
    NotificationServiceParamIDContents10            = 0x26,
    NotificationServiceParamIDMedia                 = 0x27,
    NotificationServiceParamIDPackage               = 0x28,
    NotificationServiceParamIDClass                 = 0x29,
    NotificationServiceParamIDSharingInformation    = 0x2A,
};

- (id)init;

/**
 通知カテゴリ確認
 
 プロファイルconfirmNotifyCategoryのデータ作成
 
 @param peripheral 送信するデバイスのペリフェラル
 @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 
 @return 送信するデータ
 */
- (NSData *)confirmNotifyCategory:(CBPeripheral *)peripheral disconnect:(BOOL)disconnect;

/**
 情報通知
 
 通知カテゴリ - General
 
 プロファイルnotifyInformationのデータ作成
 
 @param title            タイトル
 @param text             本文
 @param appName          通知元アプリ名
 @param appNameLocal     通知元アプリ名(ローカル)
 @param package          通知元アプリ名(Package名)
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値
 @param vibration        バイブレーションの設定値
 @param uniqueId         識別ID
 
 @return 送信するデータ
 */
- (NSData *)sendGeneralInformation:(NSString *)title
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
                          uniqueId:(int)uniqueId;

/**
 情報通知
 
 通知カテゴリ - Etc
 
 プロファイルnotifyInformationのデータ作成
 
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
 @param appName          通知元アプリ名
 @param appNameLocal     通知元アプリ名(ローカル)
 @param package          通知元アプリ名(Package名)
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値
 @param vibration        バイブレーションの設定値
 @param uniqueId         識別ID
 
 @return 送信するデータ
 */
- (NSData *)sendEtcInformation:(NSData *)content1
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
                      uniqueId:(int)uniqueId;

/**
 情報通知
 
 通知カテゴリ - PhoneIncomingCall
 
 プロファイルnotifyInformationのデータ作成
 
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値
 @param vibration        バイブレーションの設定値
 @param uniqueId         識別ID
 
 @return 送信するデータ
 */
- (NSData *)sendPhoneIncomingCallInformation:(short)notifyId
                            notifyCategoryId:(short)notifyCategoryId
                                  ledSetting:(BOOL)ledSetting
                            vibrationSetting:(BOOL)vibrationSetting
                                         led:(NSMutableDictionary *)led
                                   vibration:(NSMutableDictionary *)vibration
                                    uniqueId:(int)uniqueId;

/**
 情報通知
 
 通知カテゴリ - PhoneInCall
 
 プロファイルnotifyInformationのデータ作成
 
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値
 @param vibration        バイブレーションの設定値
 @param uniqueId         識別ID
 
 @return 送信するデータ
 */
- (NSData *)sendPhoneInCallInformation:(short)notifyId
                      notifyCategoryId:(short)notifyCategoryId
                            ledSetting:(BOOL)ledSetting
                      vibrationSetting:(BOOL)vibrationSetting
                                   led:(NSMutableDictionary *)led
                             vibration:(NSMutableDictionary *)vibration
                              uniqueId:(int)uniqueId;

/**
 情報通知
 
 通知カテゴリ - PhoneIdle
 
 プロファイルnotifyInformationのデータ作成
 
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値
 @param vibration        バイブレーションの設定値
 @param uniqueId         識別ID
 
 @return 送信するデータ
 */
- (NSData *)sendPhoneIdleInformation:(short)notifyId
                    notifyCategoryId:(short)notifyCategoryId
                          ledSetting:(BOOL)ledSetting
                    vibrationSetting:(BOOL)vibrationSetting
                                 led:(NSMutableDictionary *)led
                           vibration:(NSMutableDictionary *)vibration
                            uniqueId:(int)uniqueId;

/**
 情報通知
 
 通知カテゴリ - Mail
 
 プロファイルnotifyInformationのデータ作成
 
 @param title            タイトル
 @param text             本文
 @param appName          通知元アプリ名
 @param appNameLocal     通知元アプリ名(ローカル)
 @param package          通知元アプリ名(Package名)
 @param sender           送信者
 @param senderAddress    送信アドレス
 @param receiveDate      受信日時
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値
 @param vibration        バイブレーションの設定値
 @param uniqueId         識別ID
 
 @return 送信するデータ
 */
- (NSData *)sendMailInformation:(NSString *)title
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
                       uniqueId:(int)uniqueId;

/**
 情報通知
 
 通知カテゴリ - Schedule
 
 プロファイルnotifyInformationのデータ作成
 
 @param title            タイトル
 @param text             本文
 @param appName          通知元アプリ名
 @param appNameLocal     通知元アプリ名(ローカル)
 @param package          通知元アプリ名(Package名)
 @param startDate        開始日時
 @param endDate          終了日時
 @param area             エリア
 @param person           パーソン
 @param content1         内容1
 @param content2         内容2
 @param content3         内容3
 @param notifyId         通知ID
 @param notifyCategoryId 通知カテゴリID
 @param ledSetting       LED設定フラグ
 @param vibrationSetting バイブレーション設定フラグ
 @param led              LEDの設定値
 @param vibration        バイブレーションの設定値
 @param uniqueId         識別ID
 
 @return 送信するデータ
 */
- (NSData *)sendScheduleInformation:(NSString *)title
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
                           uniqueId:(int)uniqueId;

/**
 通知詳細情報の取得応答
 
 プロファイルgetPdNotifyDetailDataRespのデータ作成
 
 @param uniqueId    識別ID
 @param resultCode  処理結果
 @param paramValue  GET_PD_NOTIFY_DETAIL_DATAで指定されたパラメータIDに紐付くデータ
 @param paramId     GET_PD_NOTIFY_DETAIL_DATAで指定されたパラメータID
 
 @return 送信するデータ
 */
- (NSData *)sendGetPdNotifyDetailDataResp:(int)uniqueId resultCode:(Byte)resultCode paramValue:(NSString *)paramValue paramId:(char)paramId;

/**
 周辺機器からのアプリケーション起動の応答
 
 プロファイルstartPdApplicationRespのデータ作成
 
 @param result  処理結果
 
 @return 送信するデータ
 */
- (NSData *)sendStartPdApplicationResp:(Byte)result;

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
