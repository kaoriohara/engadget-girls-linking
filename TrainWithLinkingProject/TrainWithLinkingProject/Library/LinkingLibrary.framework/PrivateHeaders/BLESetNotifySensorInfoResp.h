/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "BLEConnecter.h"
/**
 プロファイルSetNotifySensorInfoRespのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLESetNotifySensorInfoRespDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
/**
 センサー情報通知設定のデリゲート
 
 プロファイルSetNotifySensorInfoRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)setNotifySensorInfoRespSuccess:(CBPeripheral *)peripheral;
/**
 センサー情報通知設定のデリゲート
 
 プロファイルSetNotifySensorInfoRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)setNotifySensorInfoRespError:(CBPeripheral *)peripheral result:(char)result;

@end

/**
 プロファイルSetNotifySensorInfoRespのクラス
 */
@interface BLESetNotifySensorInfoResp : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLESetNotifySensorInfoRespDelegate> deviceInfoDelegate;
@property (nonatomic, weak) id<BLESetNotifySensorInfoRespDelegate> connecterDelegate;
/**
 受信データパースメソッド
 
 @param peripheral 受信したデバイスのペリフェラル
 @param length 受信したパラメータ数
 @param data 受信したデータのパラメーター部分のデータ
 */
-(void)responce:(CBPeripheral *)peripheral
         length:(Byte)length
       withData:(NSData *)data;
@end
