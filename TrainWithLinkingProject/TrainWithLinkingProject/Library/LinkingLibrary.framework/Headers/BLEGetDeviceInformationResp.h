/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "BLEConnecter.h"
/**
 プロファイルGetDeviceInformationRespのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLEGetDeviceInformationRespDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
/**
 　デバイス情報取得のデリゲート
 
 プロファイルGetDeviceInformationRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)getDeviceInformationRespSuccess:(CBPeripheral *)peripheral;
/**
 　デバイス情報取得のデリゲート
 
 プロファイルGetDeviceInformationRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)getDeviceInformationRespError:(CBPeripheral *)peripheral result:(char)result;

@end
/**
 プロファイルGetDeviceInformationRespのクラス
 */
@interface BLEGetDeviceInformationResp : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLEGetDeviceInformationRespDelegate> deviceInfoDelegate;
@property (nonatomic, weak) id<BLEGetDeviceInformationRespDelegate> connecterDelegate;
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
