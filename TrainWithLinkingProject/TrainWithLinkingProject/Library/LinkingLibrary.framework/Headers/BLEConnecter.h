/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBCentralManager.h>
#import <CoreBluetooth/CBPeripheral.h>
#import "BLEDeviceNotificationService.h"
#import "BLEDelegateModel.h"
#import "BLEGetDeviceInformationResp.h"
#import "BLENotifyPdGeneralInformation.h"
#import "BLECommonConsts.h"
#import "BLEStartPdApplication.h"
/**
 CoreBluetooth機能を管理するクラス
 */
@interface BLEConnecter : NSObject
<
CBCentralManagerDelegate
,CBPeripheralDelegate
//,BLEDeviceNotificationServiceDelegate
>

@property (nonatomic, weak) id<BLEConnecterDelegate> delegate;
@property (nonatomic, weak) id<BLEConnecterDelegate> timerDelegate;
@property (strong,nonatomic)CBPeripheral *targetPeripheral;

@property (nonatomic ,setter=setDisconnectTime:) float disconnectTime;
@property (nonatomic ,setter=setTimeOut:) float timeOutTime;
@property (nonatomic, readonly, getter=isSetLED) BOOL setLED;
@property (nonatomic ,setter=setThreshold:) float threshold;

@property (nonatomic) BOOL sendCancelFlg;

@property (nonatomic, readonly) BOOL canDiscovery
;
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (BLEConnecter *)sharedInstance;
/**
 BLEDeviceSettingを返却する
 @param peripherals 返却するBLEDeviceSettingのperipheral
 @return BLEDeviceSetting
 */
-(BLEDeviceSetting *)getDeviceByPeripheral:(CBPeripheral *)pPeripheral;

/**
 *
 * デバイス検索を行う
 */
- (void)scanDevice;
/**
 *
 * アドバタイズの検出を開始する
 */
- (void)startPartialScanDevice;
/**
 *
 * デバイス検索を行う
 *
 * @param serviceUUIDs  サービスのUUID
 * @param writeUUIDs    キャラクタリスティクスWriteのUUID
 * @param indicateUUIDs キャラクタリスティクスIndicateのUUID
 *
 */
- (void)scanDevice:(NSString *)serviceUUIDs writeUUIDs:(NSString *)writeUUIDs indicateUUIDs:(NSString *)indicateUUIDs;
/**
 *
 * デバイス検索を停止する
 */
- (void)stopScan;
/**
 *
 * アドバタイズの検出を停止する
 */
- (void)stopPartialScanDevice;
/**
 スキャン状況を返却する
 @return YES = 検索中 NO = 検索を行っていない
 */
- (BOOL)isScanning;


/**
 *
 * デバイス接続
 *
 * @param index 接続するデバイスのインデックス
 *
 */
- (void)connectDevice:(CBPeripheral *)peripheral;
//- (void)connectDevice;

// デバイスを切断する
-(void)disconnectByDeviceUUID:(NSString *)uuidOfPeripheral;
// すべてのデバイスを切断する
-(void)disconnectAll;

/**
 *
 * Linkingデバイスへメッセージ送信を行う
 *
 * @param data 送信するデータ
 * @param peripheral 送信するデバイスのperipheral
 * @param characteristic キャラクタリスティック
 * @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
-(void)sendRequestWithData:(NSData *)data
                peripheral:(CBPeripheral *)peripheral
            characteristic:(CBCharacteristic *)characteristic
                disconnect:(BOOL)disconnect;

/**
 *
 * Linkingデバイスへ分割メッセージ送信を行う
 *
 * @param data 送信するデータ
 * @param deviceId 送信するデバイスのdeviceId
 * @param deviceUId 送信するデバイスのdeviceUId
 * @param peripheral 送信するデバイスのperipheral
 * @param disconnect YESの場合は即時切断、NOの場合は一定間隔をおいて切断する(disconnectTimeが0の場合は切断されない)
 */
- (void)sendRequestWithMultiData:(NSMutableArray *)multiData
                        deviceId:(unsigned short)deviceId
                       deviceUId:(NSMutableArray *)deviceUId
                      peripheral:(CBPeripheral *)peripheral
                      disconnect:(BOOL)disconnect;

/**
 *
 * デリゲートの登録を行う
 *
 * @param delegate デリゲートを登録
 * @param deviceUUID デリゲートを登録するデバイスのUUID
 */
-(void)addListener:(id<BLEConnecterDelegate>)delegate deviceUUID:(NSString *)deviceUUID;
/**
 *
 * デリゲートの削除を行う
 *
 * @param delegate デリゲートを削除
 * @param deviceUUID デリゲートを削除するデバイスのUUID
 */
-(void)removeListener:(id<BLEConnecterDelegate>)delegate deviceUUID:(NSString *)deviceUUID;
/**
 *
 * タイマーのデリゲートの削除を行う
 *
 * @param delegate デリゲートを登録
 * @param deviceUUID デリゲートを登録するデバイスのUUID
 */
-(void)addTimerListener:(id<BLEConnecterDelegate>)delegate deviceUUID:(NSString *)deviceUUID;
/**
 デバイス情報取得シーケンス完了メソッド

 @param peripheral 情報を更新したデバイスのペリフェラル
 @param isFirst YES = 初回シーケンス　NO = 初回ではない
 */
-(void)notifyDeviceInitialFinish:(CBPeripheral *)peripheral firstInitial:(BOOL)isFirst;

@end