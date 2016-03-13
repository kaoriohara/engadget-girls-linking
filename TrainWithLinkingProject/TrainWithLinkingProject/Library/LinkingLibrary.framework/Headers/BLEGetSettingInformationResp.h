/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <CoreBluetooth/CoreBluetooth.h>
#import "BLESettingOperationService.h"
/**
 プロファイルGetSettingInformationRespのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLEGetSettingInformationRespDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
/**
 設定情報取得のデリゲート
 
 プロファイルGetSettingInformationRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)getSettingInformationRespSuccess:(CBPeripheral *)peripheral;
/**
 設定情報取得のデリゲート
 
 プロファイルGetSettingInformationRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)getSettingInformationRespError:(CBPeripheral *)peripheral result:(char)result;

@end
/**
 プロファイルGetAppVersionRespのクラス
 */
@interface BLEGetSettingInformationResp : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLEGetSettingInformationRespDelegate> delegate;
@property (nonatomic, weak) id<BLEGetSettingInformationRespDelegate> connecterDelegate;
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
