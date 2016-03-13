/**
 * Copyright © 2015-2016 NTT DOCOMO, INC. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
/**
 プロファイルOperationServiceの定数クラス
 */
@interface BLEOperationServiceConsts : NSObject

// Message ID definition
extern const char BLEPdOperationMessageIdNotifyPdOperation;

// ParameterID definition
extern const char BLEPdOperationParamIdResultCode;
extern const char BLEPdOperationParamIdCancel;
extern const char BLEPdOperationParamIdButtonId;

// Result code
extern const char BLEPdOperationResultOK;
extern const char BLEPdOperationResultCancel;
extern const char BLEPdOperationResultErrorFailed;
extern const char BLEPdOperationResultErrorNoReason;
extern const char BLEPdOperationResultErrorDataNotAvailable;
extern const char BLEPdOperationResultErrorNotSupported;
extern const char BLEPdOperationResultReserved;

// Cancel
extern const char BLEPdOperationCancelUserCancel;
extern const char BLEPdOperationCancelReserved;

// GetStatus
extern const char BLEPdOperationButtonIdPower;
extern const char BLEPdOperationButtonIdReturn;
extern const char BLEPdOperationButtonIdEnter;
extern const char BLEPdOperationButtonIdHome;
extern const char BLEPdOperationButtonIdMenu;
extern const char BLEPdOperationButtonIdVolumeUp;
extern const char BLEPdOperationButtonIdVolumeDown;
extern const char BLEPdOperationButtonIdPlay;
extern const char BLEPdOperationButtonIdPause;
extern const char BLEPdOperationButtonIdStop;
extern const char BLEPdOperationButtonIdFastFoward;
extern const char BLEPdOperationButtonIdReWind;
extern const char BLEPdOperationButtonIdShutter;
extern const char BLEPdOperationButtonIdUp;
extern const char BLEPdOperationButtonIdDown;
extern const char BLEPdOperationButtonIdLeft;
extern const char BLEPdOperationButtonIdRight;
extern const char BLEPdOperationButtonIdReserved;

@end
