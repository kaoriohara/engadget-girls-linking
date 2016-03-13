/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
/**
 プロファイルSensorInformationの定数クラス
 */
@interface BLESensorInformationConsts : NSObject

// Message ID definition
extern const char BLESensorInformationMessageIdGetSensorInfo;
extern const char BLESensorInformationMessageIdGetSensorInfoResp;
extern const char BLESensorInformationMessageIdSetNotifySensorInfo;
extern const char BLESensorInformationMessageIdSetNotifySensorInfoResp;
extern const char BLESensorInformationMessageIdNotifyPdSensorInfo;

// ParameterID definition
extern const char BLESensorInformationParamIdResultCode;
extern const char BLESensorInformationParamIdCancel;
extern const char BLESensorInformationParamIdSensorType;
extern const char BLESensorInformationParamIdStatus;
extern const char BLESensorInformationParamIdXValue;
extern const char BLESensorInformationParamIdYValue;
extern const char BLESensorInformationParamIdZValue;
extern const char BLESensorInformationParamIdXThreshold;
extern const char BLESensorInformationParamIdYThreshold;
extern const char BLESensorInformationParamIdZThreshold;
extern const char BLESensorInformationParamIdOriginalData;

// Result code
extern const char BLESensorInformationResultOK;
extern const char BLESensorInformationResultCancel;
extern const char BLESensorInformationResultErrorFailed;
extern const char BLESensorInformationResultErrorNoReason;
extern const char BLESensorInformationResultErrorDataNotAvailable;
extern const char BLESensorInformationResultErrorNotSupported;
extern const char BLESensorInformationResultReserved;

// Cancel
extern const char BLESensorInformationCancelUserCancel;
extern const char BLESensorInformationCancelReserved;

// SensorType
extern const char BLESensorInformationSensorTypeGyroscope;
extern const char BLESensorInformationSensorTypeAccelerometer;
extern const char BLESensorInformationSensorTypeOrientation;
extern const char BLESensorInformationSensorTypeReserved;

// SensorStatus
extern const char BLESensorInformationSensorStatusOff;
extern const char BLESensorInformationSensorStatusOn;
extern const char BLESensorInformationSensorStatusReserved;

@end
