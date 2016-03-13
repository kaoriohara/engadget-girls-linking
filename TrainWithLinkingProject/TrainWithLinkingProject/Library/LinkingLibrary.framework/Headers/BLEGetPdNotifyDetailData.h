/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "BLEConnecter.h"
/**
 プロファイルGetPdNotifyDetailDataのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLEGetPdNotifyDetailDataDelegate <NSObject>
@optional

/**
 通知詳細情報の取得の通知
 
 プロファイルGetPdNotifyDetailDataの受信を通知
 @param peripheral 取得したデバイスのペリフェラル
 @param paramKey   取得したいパラメータID識別キー
 */
- (void)getPdNotifyDetailDataSuccess:(CBPeripheral *)peripheral paramKey:(NSString *)paramKey;

@end

/**
 プロファイルGetPdNotifyDetailDataのクラス
 */
@interface BLEGetPdNotifyDetailData : NSObject

/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLEGetPdNotifyDetailDataDelegate> delegate;
@property (nonatomic, weak) id<BLEGetPdNotifyDetailDataDelegate> connecterDelegate;

@property (nonatomic, readonly) NSMutableDictionary* uniqueId;           // M：識別ID
@property (nonatomic, readonly) NSMutableDictionary* getParameterID;     // M：取得したいパラメータID
@property (nonatomic, readonly) NSMutableDictionary* getParameterLength; // M：取得したいパラメータデータ長
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
