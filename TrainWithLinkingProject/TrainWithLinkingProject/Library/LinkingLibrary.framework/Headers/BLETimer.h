/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BLESensorGyroscope.h"
#import "BLESensorAccelerometer.h"
#import "BLESensorOrientation.h"
/**
 タイマーのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLETimerDelegate <NSObject>

// 各サービスのレスポンスをアプリ側に返す
/**
 設定された間隔でのジャイロセンサーの取得を通知
 
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)gyroscopeDidUpDateWithInterval:(CBPeripheral *)peripheral gyroscope:(BLESensorGyroscope *)gyroscope;
/**
 設定された間隔での加速センサーの取得を通知
 
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)accelerometerDidUpDateWithInterval:(CBPeripheral *)peripheral accelerometer:(BLESensorAccelerometer *)accelerometer;
/**
 設定された間隔での方位センサーの取得を通知
 
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)orientationDidUpDateWithInterval:(CBPeripheral *)peripheral orientation:(BLESensorOrientation *)orientation;
/**
 設定時間超過の為,ジャイロセンサーの取得終了を通知
 @param peripheral 終了したデバイスのペリフェラル
 */
- (void)gyroscopeObservationEnded:(CBPeripheral *)peripheral;
/**
 設定時間超過の為,方位センサーの取得終了を通知
 @param peripheral 終了したデバイスのペリフェラル
 */
- (void)accelerometerObservationEnded:(CBPeripheral *)peripheral;
/**
 ジャイロセンサーの取得を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 @param sensor 取得したデバイスのセンサーデータ
 */
- (void)orientationObservationEnded:(CBPeripheral *)peripheral;
/**
 　接続がタイムアウトした場合の通知
 @param peripheral タイムアウトしたデバイスのペリフェラル
 */
- (void)didTimeout:(CBPeripheral *)peripheral;

@end
/**
 タイマーを管理しているクラス
 */
@interface BLETimer : NSObject

@property (nonatomic)NSTimer *gyroscopeIntervalTimer;
@property (nonatomic)NSTimer *gyroscopeAutoStopTimer;
@property (nonatomic)NSTimer *accelerometerIntervalTimer;
@property (nonatomic)NSTimer *accelerometerAutoStopTimer;
@property (nonatomic)NSTimer *orientationIntervalTimer;
@property (nonatomic)NSTimer *orientationAutoStopTimer;
@property (nonatomic)NSTimer *disconnectTimer;

@property (nonatomic)NSTimer *timeOutTimer;

@property (nonatomic)CBPeripheral *gyroscopePeripheral;
@property (nonatomic)CBPeripheral *accelerometerPeripheral;
@property (nonatomic)CBPeripheral *orientationPeripheral;
@property (nonatomic)CBPeripheral *disconnectPeripheral;
@property (nonatomic)CBPeripheral *timeOutPeripheral;

@property (nonatomic)float gyroscopeInterval;
@property (nonatomic)float gyroscopeStopTime;

@property (nonatomic)float accelerometerInterval;
@property (nonatomic)float accelerometerStopTime;

@property (nonatomic)float orientationInterval;
@property (nonatomic)float orientationStopTime;

@property (nonatomic)float disconnectTime;

@property (nonatomic)float timeOutTime;

@property (nonatomic, weak) id<BLETimerDelegate> delegate;
@property (nonatomic, weak) id<BLETimerDelegate> connecterDelegate;

// ジャイロ
/**
 ジャイロセンサーの開始
 @param peripheral 開始するデバイスのペリフェラル
 */
-(void)startGyroscopeIntervalTimer:(CBPeripheral *)peripheral;
/**
 ジャイロセンサーの停止
 @param peripheral 停止するデバイスのペリフェラル
 */
-(void)stopGyroscopeIntervalTimer:(CBPeripheral *)peripheral;
/**
 ジャイロセンサーの停止時間を設定
 @param peripheral 設定するデバイスのペリフェラル
 */
-(void)startGyroscopeAutoStopTimer:(CBPeripheral *)peripheral;
/**
 設定時間超過によるジャイロセンサーの停止
 @param peripheral 停止するデバイスのペリフェラル
 */
-(void)stopGyroscopeAutoStopTimer:(CBPeripheral *)peripheral;

// 加速
/**
 加速センサーの開始
 @param peripheral 開始するデバイスのペリフェラル
 */
-(void)startAccelerometerIntervalTimer:(CBPeripheral *)peripheral;
/**
 加速センサーの停止
 @param peripheral 停止するデバイスのペリフェラル
 */
-(void)stopAccelerometerIntervalTimer:(CBPeripheral *)peripheral;
/**
 加速センサーの停止時間を設定
 @param peripheral 設定するデバイスのペリフェラル
 */
-(void)startAccelerometerAutoStopTimer:(CBPeripheral *)peripheral;
/**
 設定時間超過による加速センサーの停止
 @param peripheral 停止するデバイスのペリフェラル
 */
-(void)stopAccelerometerAutoStopTimer:(CBPeripheral *)peripheral;

// 方位
/**
 方位センサーの開始
 @param peripheral 開始するデバイスのペリフェラル
 */
-(void)startOrientationIntervalTimer:(CBPeripheral *)peripheral;
/**
 方位センサーの停止
 @param peripheral 停止するデバイスのペリフェラル
 */
-(void)stopOrientationIntervalTimer:(CBPeripheral *)peripheral;
/**
 方位センサーの停止時間を設定
 @param peripheral 設定するデバイスのペリフェラル
 */
-(void)startOrientationAutoStopTimer:(CBPeripheral *)peripheral;
/**
 設定時間超過による方位センサーの停止
 @param peripheral 停止するデバイスのペリフェラル
 */
-(void)stopOrientationAutoStopTimer:(CBPeripheral *)peripheral;
/**
 接続を切断するタイマーの開始
 @param peripheral 開始するデバイスのペリフェラル
 */
-(void)startDisconnectTimer:(CBPeripheral *)peripheral;
/**
 接続を切断するタイマーの停止
 @param peripheral 停止するデバイスのペリフェラル
 */
-(void)stopDisconnectTimer:(CBPeripheral *)peripheral;
/**
 タイムアウトを設定するタイマーの開始
 @param peripheral 開始するデバイスのペリフェラル
 */
-(void)startTimeOutTimer:(CBPeripheral *)peripheral;
/**
 タイムアウトを設定するタイマーの停止
 @param peripheral 停止するデバイスのペリフェラル
 */
-(void)stopTimeOutTimer:(CBPeripheral *)peripheral;

@end
