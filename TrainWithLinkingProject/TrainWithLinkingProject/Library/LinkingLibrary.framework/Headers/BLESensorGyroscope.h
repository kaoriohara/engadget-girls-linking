/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
/**
 ジャイロセンサーのモデルクラス
 */
@interface BLESensorGyroscope : NSObject

@property (nonatomic) float xValue;
@property (nonatomic) float yValue;
@property (nonatomic) float zValue;
@property (nonatomic) NSData * originalData;

@end
