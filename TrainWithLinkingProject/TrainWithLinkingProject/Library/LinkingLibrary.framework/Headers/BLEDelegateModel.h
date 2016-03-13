/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BLESensorGyroscope.h"
#import "BLESensorAccelerometer.h"
#import "BLESensorOrientation.h"
#import "BLEDeviceSetting.h"
@protocol BLEConnecterDelegate <NSObject>

@optional
/**
　デバイスが発見された際に呼ばれるデリゲート
 
 @param peripheral 発見したデバイスのペリフェラル
 @param advertisementData 発見したデバイスのアドバタイズデータ
 @param RSSI 発見したデバイスのRSSI値
 */
- (void)didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary *)advertisementData RSSI:(NSNumber *)RSSI;
/**
 　デバイスに接続した際に呼ばれるデリゲート
 @param peripheral 接続したデバイスのペリフェラル
 */
- (void)didConnectPeripheral:(CBPeripheral *)peripheral;
/**
 　デバイスに接続した際に呼ばれるデリゲート
 @param setting 接続したデバイスの設定情報
 */
- (void)didConnectDevice:(BLEDeviceSetting *)setting;
/**
 　デバイスが切断された際に呼ばれるデリゲート
 @param peripheral 切断されたデバイスのペリフェラル
 */
- (void)didDisconnectPeripheral:(CBPeripheral *)peripheral;
/**
 　デバイスが切断された際に呼ばれるデリゲート
 @param setting 切断されたデバイスの設定情報
 */
- (void)didDisconnectDevice:(BLEDeviceSetting *)setting;
/**
 　デバイス接続に失敗した際に呼ばれるデリゲート
 @param peripheral 接続に失敗したデバイスのペリフェラル
 @param error エラー内容
 */
- (void)didFailToConnectPeripheral:(CBPeripheral *)peripheral error:(NSError *)error;
/**
 　RSSI値変更の通知
 @param peripheral 変更されたデバイスのペリフェラル
 @param RSSI 変更されたデバイスのRSSI値
 @param isInRSSIThreshold YESの場合は閾値内へ,NOの場合は閾値外へ遷移したことを示す。
 */
- (void)didDeviceChangeRSSIValue:(CBPeripheral *)peripheral RSSI:(NSNumber *)RSSI inThreshold:(BOOL)isInRSSIThreshold;
/**
 　RSSIの取得値が閾値を下回った場合の通知
 @param peripheral 閾値を下回ったデバイスのペリフェラル
 @param RSSI 閾値を下回ったデバイスのRSSI値
 */
- (void)isBelowTheThreshold:(CBPeripheral *)peripheral RSSI:(NSNumber *)RSSI;
/**
 　受信したアドバタイズ情報の通知
 @param peripheral 受信したデバイスのペリフェラル
 @param data 受信したアドバタイズ情報
 */
- (void)receivedAdvertisement:(CBPeripheral *)peripheral
                advertisement:(NSDictionary *)data;
/**
 　接続がタイムアウトした場合の通知
 @param peripheral タイムアウトしたデバイスのペリフェラル
 */
- (void)didTimeOutPeripheral:(CBPeripheral *)peripheral;
/**
 　書き込み処理成功の通知
 @param peripheral 書き込み処理が成功したデバイスのペリフェラル
 */
- (void)didSuccessToWrite:(CBPeripheral *)peripheral;
/**
 　書き込み処理失敗の通知
 @param peripheral 書き込み処理が失敗したデバイスのペリフェラル
 @param error エラー内容
 */
- (void)didFailToWrite:(CBPeripheral *)peripheral error:(NSError *)error;
/**
 デバイス情報取得シーケンス完了のデリゲート
 
 デバイス情報取得シーケンスを実行し、デバイス情報の更新完了を通知
 @param peripheral 情報を更新したデバイスのペリフェラル
 */
- (void)didDeviceInitialFinished:(CBPeripheral *)peripheral;
/**
 　デバイス情報取得のデリゲート
 
   プロファイルGetDeviceInformationRespの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param data 受信したデータ
 */
- (void)sendGetDeviceInformationRespData:(CBPeripheral *)peripheral data:(NSData *)data;
/**
 　デバイス情報取得のデリゲート
 
 プロファイルGetDeviceInformationRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)getDeviceInformationRespSuccessDelegate:(CBPeripheral *)peripheral;
/**
 　デバイス情報取得のデリゲート
 
 プロファイルGetDeviceInformationRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)getDeviceInformationRespError:(CBPeripheral *)peripheral result:(char)result;
/**
 通知カテゴリ確認のデリゲート
 
 プロファイルConfirmNotifyCategoryRespの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param data 受信したデータ
 */
- (void)sendConfirmNotifyCategoryRespData:(CBPeripheral *)peripheral data:(NSData *)data;
/**
 通知カテゴリ確認のデリゲート
 
 プロファイルConfirmNotifyCategoryRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)confirmNotifyCategoryRespSuccessDelegate:(CBPeripheral *)peripheral;
/**
 通知カテゴリ確認のデリゲート
 
 プロファイルGetDeviceInformationRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)confirmNotifyCategoryRespError:(CBPeripheral *)peripheral result:(char)result;
/**
 設定情報取得のデリゲート
 
 プロファイルGetSettingInformationRespの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param data 受信したデータ
 */
- (void)sendGetSettingInformationRespData:(CBPeripheral *)peripheral data:(NSData *)data;
/**
 設定情報取得のデリゲート
 
 プロファイルGetSettingInformationRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)getSettingInformationRespSuccessDelegate:(CBPeripheral *)peripheral;
/**
 設定情報取得のデリゲート
 
 プロファイルGetSettingInformationRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)getSettingInformationRespError:(CBPeripheral *)peripheral result:(char)result;
/**
 設定名称取得のデリゲート
 
 プロファイルGetSettingNameRespの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param data 受信したデータ
 */
- (void)sendGetSettingNameRespData:(CBPeripheral *)peripheral data:(NSData *)data;
/**
 設定名称取得のデリゲート
 
 プロファイルGetSettingNameRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)getSettingNameRespSuccessDelegate:(CBPeripheral *)peripheral;
/**
 設定名称取得のデリゲート
 
 プロファイルGetSettingNameRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)getSettingNameRespError:(CBPeripheral *)peripheral result:(char)result;
/**
 設定情報選択のデリゲート
 
 プロファイルSelectSettingInformationRespの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param data 受信したデータ
 */
- (void)sendSelectSettingInformationRespData:(CBPeripheral *)peripheral data:(NSData *)data;
/**
 設定情報選択のデリゲート
 
 プロファイルSelectSettingInformationRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)sendSelectSettingInformationRespSuccessDelegate:(CBPeripheral *)peripheral;
/**
 設定情報選択のデリゲート
 
 プロファイルSelectSettingInformationRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)selectSettingInformationRespError:(CBPeripheral *)peripheral result:(char)result;
/**
 通知詳細情報の取得応答のデリゲート
 
 プロファイルGetPdNotifyDetailDataRespの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param data 受信したデータ
 */
- (void)sendGetPdNotifyDetailDataRespData:(CBPeripheral *)peripheral data:(NSData *)data;

/**
 通知詳細情報の取得のデリゲート
 
 プロファイルGetPdNotifyDetailDataの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 @param paramKey   取得したいパラメータID識別キー
 */
- (void)sendGetPdNotifyDetailDataSuccessDelegate:(CBPeripheral *)peripheral paramKey:(NSString *)paramKey;

/**
 周辺機器からの汎用情報通知のデリゲート
 
 プロファイルNotifyPdGeneralInformationの受信を通知
 @param peripheral   受信したデバイスのペリフェラル
 @param receiveArray 受信したデータ
 */
- (void)sendNotifyPdGeneralInformationSuccessDelegate:(CBPeripheral *)peripheral receiveArray:(NSMutableArray *)receiveArray;

/**
 周辺機器からのアプリケーション起動のデリゲート
 
 プロファイルStartPdApplicationの受信を通知
 @param peripheral   受信したデバイスのペリフェラル
 */
- (void)sendStartPdApplicationSuccessDelegate:(CBPeripheral *)peripheral result:(Byte)result;

/**
 周辺機器からのアプリケーション起動のデリゲート
 
 プロファイルStartPdApplicationRespの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param data 受信したデータ
 */
- (void)sendStartPdApplicationRespData:(CBPeripheral *)peripheral data:(NSData *)data;
/**
 センサー情報通知設定のデリゲート
 
 プロファイルSetNotifySensorInfoRespの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param data 受信したデータ
 */
- (void)sendSetNotifySensorInfoRespData:(CBPeripheral *)peripheral data:(NSData *)data;
/**
 センサー情報通知設定のデリゲート
 
 プロファイルSetNotifySensorInfoRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)setNotifySensorInfoRespSuccessDelegate:(CBPeripheral *)peripheral;
/**
 センサー情報通知設定のデリゲート
 
 プロファイルSetNotifySensorInfoRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)setNotifySensorInfoRespError:(CBPeripheral *)peripheral result:(char)result;
/**
 デバイス操作通知のデリゲート
 
 プロファイルNotifyPdOperationの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param buttonID 受信したbuttonID
 */
- (void)deviceButtonPushed:(CBPeripheral *)peripheral buttonID:(char)buttonID;
/**
 設定時間超過の為,ジャイロセンサーの取得終了を通知
 @param peripheral 終了したデバイスのペリフェラル
 */
- (void)gyroscopeObservationEnded:(CBPeripheral *)peripheral;
/**
 設定時間超過の為,加速センサーの取得終了を通知
 @param peripheral 終了したデバイスのペリフェラル
 */
- (void)accelerometerObservationEnded:(CBPeripheral *)peripheral;
/**
 設定時間超過の為,方位センサーの取得終了を通知
 @param peripheral 終了したデバイスのペリフェラル
 */
- (void)orientationObservationEnded:(CBPeripheral *)peripheral;
/**
 ジャイロセンサーの取得を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)gyroscopeDidUpDateDelegate:(CBPeripheral *)peripheral sensor:(BLESensorGyroscope *)sensor;
/**
 設定された間隔でのジャイロセンサーの取得を通知
 
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)gyroscopeDidUpDateWithIntervalDelegate:(CBPeripheral *)peripheral sensor:(BLESensorGyroscope *)sensor;
/**
 ジャイロセンサーの取得を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 */
- (void)gyroscopeDidUpDateDelegate:(CBPeripheral *)peripheral;
/**
 加速センサーの取得を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)accelerometerDidUpDateDelegate:(CBPeripheral *)peripheral sensor:(BLESensorAccelerometer *)sensor;
/**
 設定された間隔での加速センサーの取得を通知
 
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)accelerometerDidUpDateWithIntervalDelegate:(CBPeripheral *)peripheral sensor:(BLESensorAccelerometer *)sensor;
/**
 加速センサーの取得を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 */
- (void)accelerometerDidUpDateDelegate:(CBPeripheral *)peripheral;
/**
 方位センサーの取得を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)orientationDidUpDateDelegate:(CBPeripheral *)peripheral sensor:(BLESensorOrientation *)sensor;
/**
 設定された間隔での方位センサーの取得を通知
 
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)orientationDidUpDateWithIntervalDelegate:(CBPeripheral *)peripheral sensor:(BLESensorOrientation *)sensor;
/**
 方位センサーの取得を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 */
- (void)orientationDidUpDateDelegate:(CBPeripheral *)peripheral;

/*
 *　getSensorInformationMessage:非対応
 */
//- (void)sendGetSensorInfoRespData:(CBPeripheral *)peripheral data:(NSData *)data;

/**　getAppVersionMessage:非対応
 confirmInstallAppMessage:非対応
 */
//- (void)sendGetAppVersionRespData:(CBPeripheral *)peripheral data:(NSData *)data;
//- (void)sendConfirmInstallAppRespData:(CBPeripheral *)peripheral data:(NSData *)data;
/** - アプリバージョン取得 */
/**　getAppVersionMessage:非対応
 confirmInstallAppMessage:非対応
 */
//- (void)getAppVersionRespSuccessDelegate:(CBPeripheral *)peripheral result:(char)result fileVer:(NSDictionary *)fileVer;
//
//-(void)confirmInstallAppRespSuccessDelegate:(CBPeripheral *)peripheral result:(char)result;
/**  エラーレスポンス */
/**　getAppVersionMessage:非対応
 confirmInstallAppMessage:非対応
 */
//- (void)getAppVersionRespError:(CBPeripheral *)peripheral result:(char)result;
//- (void)confirmInstallAppRespError:(CBPeripheral *)peripheral result:(char)result;
/**　getSensorInformationMessage:非対応
 */
//- (void)getSensorInfoRespError:(CBPeripheral *)peripheral result:(char)result;
/**  センサー情報取得時 */
/**　getSensorInformationMessage:非対応
 */
//- (void)getSensorInfoRespSuccess:(CBPeripheral *)peripheral
//                      resultCode:(char)resultCode
//                          xValue:(float)xValue
//                          yValue:(float)yValue
//                          zValue:(float)zValue
//                    originalData:(NSData * )data;



@end
/*
 *デリゲートを管理するクラス
 @warninng 使用されないデリゲートも記載
 */
@interface BLEDelegateModel : NSObject

@property (nonatomic, strong) NSString *deviceUUID;
@property (nonatomic, weak) id<BLEConnecterDelegate> bluetoothDelegate;
@property (nonatomic, weak) id<BLEConnecterDelegate> bluetoothTimerDelegate;

@end
