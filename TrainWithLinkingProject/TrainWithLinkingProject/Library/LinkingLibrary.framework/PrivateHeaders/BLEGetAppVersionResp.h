/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "BLESettingOperationService.h"

/**
 プロファイルGetAppVersionRespのデリゲート
 */
@protocol BLEGetAppVersionRespDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
- (void)getAppVersionRespSuccess:(CBPeripheral *)peripheral;

// 各サービスのレスポンスをアプリ側に返す
- (void)getAppVersionRespSuccess:(CBPeripheral *)peripheral result:(char)result fileVer:(NSDictionary *)fileVer;
- (void)getAppVersionRespError:(CBPeripheral *)peripheral result:(char)result;

@end
/**
 プロファイルGetAppVersionRespのクラス
 */
@interface BLEGetAppVersionResp : NSObject
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (id)sharedInstance;

@property (nonatomic, weak) id<BLEGetAppVersionRespDelegate> delegate;
@property (nonatomic, weak) id<BLEGetAppVersionRespDelegate> connecterDelegate;

-(void)responce:(CBPeripheral *)peripheral
         length:(Byte)length
       withData:(NSData *)data;

@end
