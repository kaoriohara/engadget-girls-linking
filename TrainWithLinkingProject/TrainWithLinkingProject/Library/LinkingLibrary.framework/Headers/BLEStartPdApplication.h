/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "BLEConnecter.h"
/**
 プロファイルStartPdApplicationのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLEStartPdApplicationDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
/**
 周辺機器からのアプリケーション起動のデリゲート
 
 プロファイルStartPdApplicationRespの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 */
- (void)startPdApplication:(CBPeripheral *)peripheral;

@end
/**
 プロファイルStartPdApplicationのクラス
 */
@interface BLEStartPdApplication : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLEStartPdApplicationDelegate> delegate;
@property (nonatomic, weak) id<BLEStartPdApplicationDelegate> connecterDelegate;

@property (nonatomic, readonly) NSMutableDictionary* package;   // M：通知元アプリ名（パッケージ名）
@property (nonatomic, readonly) NSMutableDictionary* notifyApp; // M：通知先アプリ名（パッケージ名）
@property (nonatomic, readonly) NSMutableDictionary* className; // M：クラス名
@property (nonatomic, readonly) NSMutableDictionary* sharingInformation;   // O：連携情報
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
