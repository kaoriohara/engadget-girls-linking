/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "BLESettingOperationService.h"
/**
 プロファイルGetSettingNameRespのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLEGetSettingNameRespDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
/**
 設定名称取得のデリゲート
 
 プロファイルGetSettingNameRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)getSettingNameRespSuccess:(CBPeripheral *)peripheral;
/**
 設定名称取得のデリゲート
 
 プロファイルGetSettingNameRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)getSettingNameRespError:(CBPeripheral *)peripheral result:(char)result;

@end
/**
 プロファイルGetSettingNameRespのクラス
 */
@interface BLEGetSettingNameResp : NSObject
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
 @param length 受信したパラメータ数
 @param data 受信したデータのパラメーター部分のデータ
 */
-(void)responce:(CBPeripheral *)peripheral
         length:(Byte)length
       withData:(NSData *)data;

@property (nonatomic, weak) id<BLEGetSettingNameRespDelegate> delegate;
@property (nonatomic, weak) id<BLEGetSettingNameRespDelegate> connecterDelegate;

@property (nonatomic) int settingNametype; // C：設定名称データ

-(void)nameTypeSetting:(int)settingNametype;

@end
