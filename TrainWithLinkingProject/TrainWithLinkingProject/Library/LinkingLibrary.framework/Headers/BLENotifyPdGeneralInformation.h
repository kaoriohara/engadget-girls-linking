/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import "BLEConnecter.h"
/**
 プロファイルNotifyPdGeneralInformationのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLENotifyPdGeneralInformationDelegate <NSObject>
@optional

/*!
 *@brief     NOTIFY_PD_GENERAL_INFORMATONのdelegateメソッド
 *@note      アプリ側でこのdelegateメソッドを実装する
 *@param     peripheral      対象のペリフェラル
 *
 */
- (void)notifyPdGeneralInformationSuccess:(CBPeripheral *)peripheral receiveArray:(NSMutableArray *)receiveArray;

@end
/**
 プロファイルNotifyPdGeneralInformationのクラス
 */
@interface BLENotifyPdGeneralInformation : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLENotifyPdGeneralInformationDelegate> delegate;
@property (nonatomic, weak) id<BLENotifyPdGeneralInformationDelegate> connecterDelegate;

@property (nonatomic, readonly) NSString *package;      // M：通知元アプリ名(Package名)
@property (nonatomic, readonly) NSString *notifyApp;    // M：通知先アプリ名(Package名)
@property (nonatomic, readonly) NSString *contents1;    // O：内容1
@property (nonatomic, readonly) NSString *contents2;    // O：内容2
@property (nonatomic, readonly) NSString *contents3;    // O：内容3
@property (nonatomic, readonly) NSString *contents4;    // O：内容4
@property (nonatomic, readonly) NSString *contents5;    // O：内容5
@property (nonatomic, readonly) NSString *contents6;    // O：内容6
@property (nonatomic, readonly) NSString *contents7;    // O：内容7
@property (nonatomic, readonly) NSString *contents8;    // O：内容8
@property (nonatomic, readonly) NSString *contents9;    // O：内容9
@property (nonatomic, readonly) NSString *contents10;   // O：内容10
@property (nonatomic, readonly) NSString *mediaType;    // O：MIMEタイプ(Media向け)
@property (nonatomic, readonly) NSString *media;        // O：メディア
@property (nonatomic, readonly) NSString *imageType;    // O：MIMEタイプ(Image向け)
@property (nonatomic, readonly) NSString *image;        // O：イメージ
@property (nonatomic, readonly) short notifyId;         // O：通知先アプリ名(Package名)
@property (nonatomic, readonly) short notifyCategoryId; // O：通知先アプリ名(Package名)
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
