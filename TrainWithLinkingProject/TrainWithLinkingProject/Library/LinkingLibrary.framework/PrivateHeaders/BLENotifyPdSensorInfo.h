/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "BLEConnecter.h"
/**
 プロファイルotifyPdSensorInfoのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLENotifyPdSensorInfoDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
/**
 センサーの取得を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 */
- (void)notifyPdSensorInfoSuccess:(CBPeripheral *)peripheral;
/**
 ジャイロセンサーの情報更新を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 */
- (void)gyroscopeDidUpDate:(CBPeripheral *)peripheral;
/**
 ジャイロセンサーの情報更新を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 @param gyroscope 取得したデバイスのセンサーデータ
 */
- (void)gyroscopeDidUpDate:(CBPeripheral *)peripheral gyroscope:(BLESensorGyroscope *)gyroscope;
/**
 加速センサーの情報更新を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 */
- (void)accelerometeDidUpDate:(CBPeripheral *)peripheral;
/**
 加速センサーの情報更新を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 @param accelerometer 取得したデバイスのセンサーデータ
 */
- (void)accelerometerDidUpDate:(CBPeripheral *)peripheral accelerometer:(BLESensorAccelerometer *)accelerometer;
/**
 方位センサーの情報更新を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 */
- (void)orientationDidUpDate:(CBPeripheral *)peripheral;
/**
 方位センサーの情報更新を通知
 
 プロファイルNotifyPdSensorInfoの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 @param orientation 取得したデバイスのセンサーデータ
 */
- (void)orientationDidUpDate:(CBPeripheral *)peripheral orientation:(BLESensorOrientation *)orientation;

@end
/**
 プロファイルNotifyPdSensorInfoのクラス
 */
@interface BLENotifyPdSensorInfo : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLENotifyPdSensorInfoDelegate> delegate;
@property (nonatomic, weak) id<BLENotifyPdSensorInfoDelegate> connecterDelegate;
/**
 受信データパースメソッド
 
 @param peripheral 受信したデバイスのペリフェラル
 @param length 受信したパラメータ数
 @param data 受信したデータのパラメーター部分のデータ
 */
- (void)responce:(CBPeripheral *)peripheral
          length:(Byte)length
        withData:(NSData *)data;

@end
