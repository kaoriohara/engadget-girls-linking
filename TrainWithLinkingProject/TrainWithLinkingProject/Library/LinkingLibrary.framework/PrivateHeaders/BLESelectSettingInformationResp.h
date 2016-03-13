/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <CoreBluetooth/CoreBluetooth.h>
#import "BLESettingOperationService.h"
/**
 プロファイルSelectSettingInformationRespのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLESelectSettingInformationRespDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
/**
 設定情報選択のデリゲート
 
 プロファイルSelectSettingInformationRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)selectSettingInformationRespSuccess:(CBPeripheral *)peripheral;
/**
 設定情報選択のデリゲート
 
 プロファイルSelectSettingInformationRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)selectSettingInformationRespError:(CBPeripheral *)peripheral result:(char)result;

@end
/**
 プロファイルSelectSettingInformationRespのクラス
 */
@interface BLESelectSettingInformationResp : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLESelectSettingInformationRespDelegate> delegate;
@property (nonatomic, weak) id<BLESelectSettingInformationRespDelegate> connecterDelegate;
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
