/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "BLEConnecter.h"
/**
 プロファイルNotifyPdOperationのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLENotifyPdOperationDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
/**
 デバイス操作通知のデリゲート
 
 プロファイルNotifyPdOperationの受信を通知
 @param peripheral 受信したデバイスのペリフェラル
 @param buttonID 受信したbuttonID
 */
- (void)notifyPdOperationSuccess:(CBPeripheral *)peripheral buttonID:(char)buttonID;

@end
/**
 プロファイルNotifyPdOperationのクラス
 */
@interface BLENotifyPdOperation : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLENotifyPdOperationDelegate> delegate;
@property (nonatomic, weak) id<BLENotifyPdOperationDelegate> connecterDelegate;
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
