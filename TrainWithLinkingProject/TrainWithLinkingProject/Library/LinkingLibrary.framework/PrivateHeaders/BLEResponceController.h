/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */
#import <Foundation/Foundation.h>
#import "BLEConnecter.h"
/**
 Linkingデバイスからの受信時に使用するクラス
 */
@interface BLEResponceController : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;
/**
 受信データパースメソッド
 
 @param peripheral 受信したデバイスのペリフェラル
 @param serviceID 受信したデータのサービスID
 @param messageID 受信したデータのメッセージID
 @param data 受信したデータ
 */
-(void)selectService:(CBPeripheral *)peripheral serviceID:(Byte)serviceID selectmessasge:(Byte)messageID withData:(NSData *)data;

typedef NS_ENUM(NSUInteger, ProfileServiceID) {
	ServiceIDPropertyInformation = 0x00, /*!< PropertyInformation */
	ServiceIDNotification        = 0x01, /*!< Notification */
	ServiceIDOperation           = 0x02, /*!< Operation */
	ServiceIDSensorInformation   = 0x03, /*!< SensorInformation */
	ServiceIDSettingOperation    = 0x04, /*!< SettingOperation */
};

@end
