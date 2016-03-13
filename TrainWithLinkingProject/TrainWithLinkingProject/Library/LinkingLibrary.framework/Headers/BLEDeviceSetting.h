/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <UIKit/UIKit.h>
#import "BLETimer.h"

#define DEV_STAT_CONNECTED    @"CONNECTED"
#define DEV_STAT_DISCONNECTED @"DISCONNECTED"
/**
 デバイス情報を管理するクラス
 @warninng 使用されないメソッドも記載
 */
extern NSTimeInterval const kReadRSSIInBackgroundStateInterval;
extern NSTimeInterval const kReadRSSIInForegroundStateInterval;
extern NSTimeInterval const kReconnectInBackgroundStateInterval;
extern NSTimeInterval const kReconnectInForegroundStateInterval;

extern NSUInteger const kNumberOfRSSIsForMeasuring;
extern float const kRSSIPerMeter;
extern float const kAttenuationRate;

@interface BLEDeviceSetting : NSObject

// デバイス情報
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *connectionStatus;
@property (nonatomic, strong) CBCharacteristic *gCharacteristicWrite;
@property (nonatomic, strong) CBCharacteristic *gCharacteristicNotify;
@property (nonatomic) UIBackgroundTaskIdentifier backgroundTaskIdentifier;
@property (nonatomic, strong, readonly) NSNumber *estimatedDistance;
@property (nonatomic, strong) NSTimer *readingRSSITimer;
@property (nonatomic) BOOL userSettingOFF;
@property (nonatomic, strong) NSTimer *reconnectTimer;
@property (nonatomic) float latestDistance;
@property (nonatomic) float distanceThreshold;
@property (nonatomic) BOOL isInDistanceThreshold; // 現在値（current value）<= 閾値（threshold） ? YES : NO

// 初回シーケンス中
@property (nonatomic) BOOL notifyDeviceInitial;

// 初回シーケンス完了
@property (nonatomic) BOOL initialDeviceSettingFinished;

//データ更新フラグ
@property (nonatomic) BOOL saved;

// PeripheralDevicePropertyInformationService
// ServiceList : サービス
@property (nonatomic) BOOL hasPeripheralDevicePropertyInformation;
@property (nonatomic) BOOL hasPeripheralDeviceNotification;
@property (nonatomic) BOOL hasPeripheralDeviceOperation;
@property (nonatomic) BOOL hasPeripheralDeviceSensorInformation;
@property (nonatomic) BOOL hasPeripheralDeviceSettingOperation;
@property (nonatomic) BOOL hasPeripheralDeviceServiceListReserved;

// DeviceId : デバイスID(周辺機器の商品毎に固有)
// DeviceUid : デバイス固有ID(個々の機器に固有のID)
@property (nonatomic) unsigned short deviceId;
@property (nonatomic) unsigned int deviceUid;

// DeviceCapability : 機能
@property (nonatomic) BOOL hasLED;
@property (nonatomic) BOOL hasGyroscope;
@property (nonatomic) BOOL hasAccelerometer;
@property (nonatomic) BOOL hasOrientation;
@property (nonatomic) BOOL hasPeripheralDeviceCapabilityReserved;

// OriginalInformation : デバイス独自情報
@property (nonatomic) NSMutableArray *originalInformation;

// ExSensorType : 拡張センサータイプ情報
@property (nonatomic) NSData *exSensorType;

//PeripheralDeviceNotification Service
@property (nonatomic) BOOL notifyCategoryNotNotify;
@property (nonatomic) BOOL notifyCategoryAll;
@property (nonatomic) BOOL notifyCategoryPhoneIncomingCall;
@property (nonatomic) BOOL notifyCategoryPhoneInCall;
@property (nonatomic) BOOL notifyCategoryPhoneIdle;
@property (nonatomic) BOOL notifyCategoryMail;
@property (nonatomic) BOOL notifyCategorySchedule;
@property (nonatomic) BOOL notifyCategoryGeneral;
@property (nonatomic) BOOL notifyCategoryEtc;

// PeripheralDeviceSensorInformationService

// PeripheralDeviceSettingOperationService

// GetAppVersion
@property (nonatomic) NSDictionary *fileversion;

// SettingInformationData : 設定情報データ
@property (nonatomic) NSMutableArray *settingInformationData;
@property (nonatomic) NSMutableDictionary *settingInformationDataLED;
@property (nonatomic) NSMutableDictionary *settingInformationDataVibration;
@property (nonatomic) NSMutableDictionary *settingInformationDataNotificationDuration;

// SettingNameData : 設定名称データ
@property (nonatomic) NSMutableArray *settingNameData;
@property (nonatomic) NSMutableDictionary *lEDColorName;
@property (nonatomic) NSMutableArray *lEDColorNameArray;
@property (nonatomic) NSMutableDictionary *lEDPatternName;
@property (nonatomic) NSMutableArray *lEDPatternArray;
@property (nonatomic) NSMutableDictionary *vibrationPatternName;
@property (nonatomic) NSMutableArray *vibrationPatternArray;

@property (nonatomic) NSMutableDictionary *notificationDurationName;
@property (nonatomic) NSMutableArray *notificationDurationArray;
@property (nonatomic) NSMutableDictionary *settingNameDataReserved;

typedef NS_ENUM(NSUInteger, SettingNameType) {
    LEDColorName         = 0x00,
    LEDPatternName       = 0x01,
    VibrationPatternName = 0x02,
};

@property (nonatomic) SettingNameType settingNameType;

// センサー情報
@property (nonatomic) BLESensorGyroscope *gyroscope;
@property (nonatomic) BLESensorAccelerometer *accelerometer;
@property (nonatomic) BLESensorOrientation *orientation;

// タイマー
@property (nonatomic) BLETimer *sensorTimer;
@property (nonatomic) BLETimer *disconnectTimer;
@property (nonatomic) BLETimer *timeOutTimer;

@property (nonatomic) BOOL isNotDisconnect;
/**
 RSSIより概算距離を算出するメソッド
 
 プロファイルSelectSettingInformationRespのエラーを通知
 @param RSSI 受信したRSSiの値
 */
- (void)updateEstimatedDistanceWithRSSIValue:(NSNumber *)RSSI;
/**
 概算距離をリセットするメソッド
 */
- (void)resetEstimatedDistance;

@end
