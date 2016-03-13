/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
/**
 プロファイルSettingOperationの定数クラス
 */
@interface BLESettingOperationConsts : NSObject

// Message ID definition
extern const char BLESettingOperationMessageIdGetAppVersion;
extern const char BLESettingOperationMessageIdGetAppVersionResp;
extern const char BLESettingOperationMessageIdConfirmInstallApp;
extern const char BLESettingOperationMessageIdConfirmInstallAppResp;
extern const char BLESettingOperationMessageIdGetSettingInfomation;
extern const char BLESettingOperationMessageIdGetSettingInfomationResp;
extern const char BLESettingOperationMessageIdGetSettingName;
extern const char BLESettingOperationMessageIdGetSettingNameResp;
extern const char BLESettingOperationMessageIdSelectSettingInfomation;
extern const char BLESettingOperationMessageIdSelectSettingInfomationResp;

// ParameterID definition
extern const char BLESettingOperationParamIdResultCode;
extern const char BLESettingOperationParamIdCancel;
extern const char BLESettingOperationParamIdSettingNameType;
extern const char BLESettingOperationParamIdAppName;
extern const char BLESettingOperationParamIdFileVer;
extern const char BLESettingOperationParamIdFileSize;
extern const char BLESettingOperationParamIdInstallConfirmStatus;
extern const char BLESettingOperationParamIdSettingInformationRequest;
extern const char BLESettingOperationParamIdSettingInformationData;
extern const char BLESettingOperationParamIdSettingNameData;

// Result code
extern const char BLESettingOperationResultOK;
extern const char BLESettingOperationResultCancel;
extern const char BLESettingOperationResultErrorFailed;
extern const char BLESettingOperationResultErrorNoReason;
extern const char BLESettingOperationResultErrorDataNotAvailable;
extern const char BLESettingOperationResultErrorNotSupported;
extern const char BLESettingOperationResultReserved;

// Cancel
extern const char BLESettingOperationCancelUserCancel;
extern const char BLESettingOperationCancelReserved;

// SettingNameType
extern const char BLESettingOperationSettingNameTypeLedColorName;
extern const char BLESettingOperationSettingNameTypeLedPetternName;
extern const char BLESettingOperationSettingNameTypeVibrationPatternName;
extern const char BLESettingOperationSettingNameTypeNotificationDurationPatternName;
extern const char BLESettingOperationSettingNameTypeReserved;

// SensorStatus
extern const char BLESettingOperationSensorStatusOff;
extern const char BLESettingOperationSensorStatusOn;
extern const char BLESettingOperationSensorStatusReserved;

// InstallConfirmStatus
extern const char BLESettingOperationInstallOK;
extern const char BLESettingOperationInstallCancel;
extern const char BLESettingOperationInstallErrorFailed;
extern const char BLESettingOperationInstallErrorNoReason;
extern const char BLESettingOperationInstallErrorDataNotAvailable;
extern const char BLESettingOperationInstallErrorNotSupported;
extern const char BLESettingOperationInstallErrorNoSpace;
extern const char BLESettingOperationInstallErrorAllRedyInstalLed;
extern const char BLESettingOperationInstallErrorOlder;
extern const char BLESettingOperationInstallReserved;

@end
