/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "BLESettingOperationService.h"

@protocol BLEConfirmInstallAppRespDelegate <NSObject>
@optional
/** 各サービスのレスポンスをアプリ側に返す */
- (void)confirmInstallAppRespSuccess:(CBPeripheral *)peripheral result:(char)result;
- (void)confirmInstallAppRespError:(CBPeripheral *)peripheral result:(char)result;
@end

@interface BLEConfirmInstallAppResp : NSObject

+ (id)sharedInstance;

@property (nonatomic, weak) id<BLEConfirmInstallAppRespDelegate> delegate;
@property (nonatomic, weak) id<BLEConfirmInstallAppRespDelegate> connecterDelegate;

-(void)responce:(CBPeripheral *)peripheral
         length:(Byte)length
       withData:(NSData *)data;
@end
