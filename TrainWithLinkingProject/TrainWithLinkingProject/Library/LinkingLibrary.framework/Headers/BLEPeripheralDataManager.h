/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <CoreBluetooth/CBPeripheral.h>

@class BLEDeviceSetting;
/**
 ペリフェラル情報のデータクラス
 */
@interface BLEPeripheralDataManager : NSObject

@property (nonatomic, strong) NSMutableArray *deviceArray;

@property (nonatomic, strong) NSString *serviceUUID;
@property (nonatomic, strong) NSString *characteristicWriteUUID;
@property (nonatomic, strong) NSString *characteristicIndicateUUID;
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSDictionary *advertisementData;
@property (nonatomic, strong) NSNumber *RSSI;
@property (nonatomic, strong) NSMutableArray *scanResultArray;
/**
deviceArrayの情報を更新する
 */
- (void)updateDevice;
/**
 serviceUUIDをセットする
 @param serviceUUIDs セットするserviceUUID
 */
- (void) setServiceUUID:(NSString *)serviceUUIDs;
/**
 serviceUUIDを返却する
 @return serviceUUID
 */
- (NSString *)getServiceUUID;
/**
 characteristicWriteUUIDをセットする
 @param characteristicWriteUUIDs セットするcharacteristicWriteUUID
 */
- (void) setCharacteristicWriteUUID:(NSString *)characteristicWriteUUIDs;
/**
 characteristicWriteUUIDを返却する
 @return characteristicWriteUUID
 */
- (NSString *)getCharacteristicWriteUUID;
/**
 characteristicIndicateUUIDをセットする
 @param characteristicIndicateUUIDs セットするcharacteristicIndicateUUID
 */
- (void) setCharacteristicIndicateUUID:(NSString *)characteristicIndicateUUIDs;
/**
 characteristicIndicateUUIDを返却する
 @return characteristicIndicateUUID
 */
- (NSString *)getCharacteristicIndicateUUID;

/*!
 * 
 * 
 *
 */
/**
 peripheralをセットする
 @param peripherals セットするperipheral
 */
- (void) setPeripheral:(CBPeripheral *)peripherals;
/**
 peripheralを返却する
 @return peripheral
 */
- (CBPeripheral *)getPeripheral;
/**
 BLEDeviceSettingを返却する
 @param peripherals 返却するBLEDeviceSettingのperipheral
 @return BLEDeviceSetting
 */
- (BLEDeviceSetting *)getDeviceWithPeripheral:(CBPeripheral *)peripherals;

/*!
 *
 *
 *
 */
/**
 advertisementDataをセットする
 @param advertisementDatas セットするadvertisementData
 */
- (void) setAdvertisementData:(NSDictionary *)advertisementDatas;
/**
 advertisementDataを返却する
 @return advertisementData
 */
- (NSDictionary *)getAdvertisementData;

/*!
 *
 *
 *
 */
/**
 RSSIをセットする
 @param RSSIs セットするRSSI
 */
- (void) setRSSI:(NSNumber *)RSSIs;
/**
 RSSIを返却する
 @return RSSI
 */
- (NSNumber *)getRSSI;

/*!
 *
 *
 *
 */
/**
 scanResultArrayをセットする
 @param scanResultArrays セットするscanResultArray
 */
- (void) setScanResultArray:(NSMutableArray *)scanResultArrays;
/**
 scanResultArrayを返却する
 @return scanResultArray
 */
- (NSMutableArray *)getScanResultArray;
/**
 保存されていたdeviceArrayの情報を読み込む
 */
-(void)loadDevices;
/**
 インスタンス取得、生成
 
 シングルトンデザインパターン。
 @param     なし
 @return    シングルトンのインスタンス
 */
+ (BLEPeripheralDataManager *)sharedManager;

@end