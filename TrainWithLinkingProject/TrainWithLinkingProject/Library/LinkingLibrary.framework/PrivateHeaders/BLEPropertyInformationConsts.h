/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
/**
 プロファイルPropertyInformationの定数クラス
 */
@interface BLEPropertyInformationConsts : NSObject

// Message ID definition
extern const char BLEPropertyInfomationMessageIdGetDeviceInformation;
extern const char BLEPropertyInfomationMessageIdGetDeviceInformationResp;

// ParameterID definition
extern const char BLEPropertyInfomationParamIdResultCode;
extern const char BLEPropertyInfomationParamIdCancel;
extern const char BLEPropertyInfomationParamIdServiceList;
extern const char BLEPropertyInfomationParamIdDeviceId;
extern const char BLEPropertyInfomationParamIdDeviceUId;
extern const char BLEPropertyInfomationParamIdDeviceCapability;
extern const char BLEPropertyInfomationParamIdOriginalInformation;
extern const char BLEPropertyInfomationParamIdExSensorType;

// Result code
extern const char BLEPropertyInfomationResultOk;
extern const char BLEPropertyInfomationResultCancel;
extern const char BLEPropertyInfomationResultErrorFailed;
extern const char BLEPropertyInfomationResultErrorNoReason;
extern const char BLEPropertyInfomationResultErrorDataNotAvailable;
extern const char BLEPropertyInfomationResultErrorNotSupported;
extern const char BLEPropertyInfomationResultReserved;

// Cancel
extern const char BLEPropertyInfomationCancelUserCancel;
extern const char BLEPropertyInfomationCancelReserved;

// ServiceList
extern const char BLEPropertyInfomationServiceListPropertyInformation;
extern const char BLEPropertyInfomationServiceListNotifycation;
extern const char BLEPropertyInfomationServiceListOperation;
extern const char BLEPropertyInfomationServiceListSensorInformation;
extern const char BLEPropertyInfomationServiceListSettingOperation;
extern const char BLEPropertyInfomationServiceListReserved;

// DeviceCapability
extern const char BLEPropertyInfomationDeviceCapabilityHasLed;
extern const char BLEPropertyInfomationDeviceCapabilityGyroscope;
extern const char BLEPropertyInfomationDeviceCapabilityAccelerometer;
extern const char BLEPropertyInfomationDeviceCapabilityOrientation;
extern const char BLEPropertyInfomationDeviceCapabilityReserved;  // greater than or equal to

// OriginalInformation
extern const char BLEPropertyInfomationOriginalInfoLbAppName;
extern const char BLEPropertyInfomationOriginalInfoLbAppNameLocal;
extern const char BLEPropertyInfomationOriginalInfoLbAppDlUrl1;
extern const char BLEPropertyInfomationOriginalInfoLbAppDlUrl2;
extern const char BLEPropertyInfomationOriginalInfoLbAppDlUrl3;
extern const char BLEPropertyInfomationOriginalInfoLbAppexecInfo1;
extern const char BLEPropertyInfomationOriginalInfoLbAppexecInfo2;
extern const char BLEPropertyInfomationOriginalInfoLbAppexecInfo3;
extern const char BLEPropertyInfomationOriginalInfoHbAppPackage;
extern const char BLEPropertyInfomationOriginalInfoHbReserved;  // greater than or equal to

@end
