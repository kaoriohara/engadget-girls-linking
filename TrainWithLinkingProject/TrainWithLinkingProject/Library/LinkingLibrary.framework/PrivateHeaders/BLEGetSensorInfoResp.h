/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "BLEConnecter.h"
/**
 プロファイルGetSettingInformationRespのデリゲート
 @warninng 使用されないデリゲートも記載
 */
@protocol BLEGetSensorInfoRespDelegate <NSObject>
@optional
// 各サービスのレスポンスをアプリ側に返す
- (void)getSensorInfoRespSuccess:(CBPeripheral *)peripheral;

- (void)getSensorInfoRespSuccess:(CBPeripheral *)peripheral
                      resultCode:(char)resultCode
                          xValue:(float)xValue
                          yValue:(float)yValue
                          zValue:(float)zValue
                    originalData:(NSData *)data;

- (void)getSensorInfoRespError:(CBPeripheral *)peripheral result:(char)result;

@end

@interface BLEGetSensorInfoResp : NSObject

+ (id)sharedInstance;

@property (nonatomic, weak) id<BLEGetSensorInfoRespDelegate> deviceInfoDelegate;
@property (nonatomic, weak) id<BLEGetSensorInfoRespDelegate> connecterDelegate;

-(void)responce:(CBPeripheral *)peripheral
         length:(Byte)length
       withData:(NSData *)data;

@end
