/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */
#import "BLEConnecter.h"
/**
 プロファイルConfirmNotifyCategoryRespのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLEConfirmNotifyCategoryRespDelegate <NSObject>
@optional
/** 各サービスのレスポンスをアプリ側に返す */
/**
 通知カテゴリ確認のデリゲート
 
 プロファイルConfirmNotifyCategoryRespの受信成功を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)confirmNotifyCategoryRespSuccess:(CBPeripheral *)peripheral;
/**
 通知カテゴリ確認のデリゲート
 
 プロファイルGetDeviceInformationRespのエラーを通知
 @param peripheral 受信したデバイスのペリフェラル
 @param result 受信したResultCode
 */
- (void)confirmNotifyCategoryRespError:(CBPeripheral *)peripheral result:(char)result;

@end
/**
 プロファイルConfirmNotifyCategoryRespのクラス
 */
@interface BLEConfirmNotifyCategoryResp : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLEConfirmNotifyCategoryRespDelegate> delegate;
@property (nonatomic, weak) id<BLEConfirmNotifyCategoryRespDelegate> connecterDelegate;
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
