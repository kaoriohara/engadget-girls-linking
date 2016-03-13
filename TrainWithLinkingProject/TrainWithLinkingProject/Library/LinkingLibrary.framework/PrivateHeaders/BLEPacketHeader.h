/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>

@interface BLEPacketHeader : NSObject

@property (nonatomic) Byte hdr;
@property (nonatomic) BOOL isClient;
@property (nonatomic) BOOL isCancel;
@property (nonatomic) BOOL isEnd;
@property (nonatomic) int seq;

/**
 初期化メソッド
 
 */
- (id)init;

/**
 Header解析メソッド
 
 @param header 1パケット内のHeader
 */
- (id)initWithHeaderByte:(Byte)header;

/**
 各パラメータをプロパティにセットするメソッド
 
 @param isClientFlag 要求起点を示すフラグ（Source）
 @param isCancelFlag キャンセルを示すフラグ（Cancel）
 @param isEndFlag    パケットの終端を意味するフラグ（Execute）
 @param sequence     シーケンス番号
 */
- (id)initWithFlagsClient:(BOOL)isClientFlag cancel:(BOOL)isCancelFlag end:(BOOL)isEndFlag sequence:(int)sequence;

/**
 Headerを解析してプロパティにセットするメソッド
 
 @param header 1パケット内のHeader
 */
- (void)setHeader:(Byte)header;

/**
 要求起点を示すフラグをプロパティにセットするメソッド
 
 @param isClientFlag 要求起点を示すフラグ（Source）
 */
- (void)setIsClient:(BOOL)isClientFlag;

/**
 キャンセルを示すフラグをプロパティにセットするメソッド
 
 @param isCancelFlag キャンセルを示すフラグ（Cancel）
 */
- (void)setIsCancel:(BOOL)isCancelFlag;

/**
 パケットの終端を意味するフラグをプロパティにセットするメソッド
 
 @param isEndFlag パケットの終端を意味するフラグ（Execute）
 */
- (void)setIsEnd:(BOOL)isEndFlag;

/**
 シーケンス番号をプロパティにセットするメソッド
 
 @param sequence シーケンス番号
 */
- (void)setSequence:(int)sequence;

@end
