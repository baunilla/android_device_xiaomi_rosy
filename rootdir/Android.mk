LOCAL_PATH := $(call my-dir)

# Recovery scripts

include $(CLEAR_VARS)
LOCAL_MODULE       := init.recovery.qcom.rc
LOCAL_MODULE_TAGS  := optional
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.recovery.qcom.rc
LOCAL_MODULE_PATH  := $(TARGET_RECOVERY_ROOT_OUT)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE       := init.recovery.qcom.usb.rc
LOCAL_MODULE_TAGS  := optional
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES    := etc/init.recovery.qcom.usb.rc
LOCAL_MODULE_PATH  := $(TARGET_RECOVERY_ROOT_OUT)
include $(BUILD_PREBUILT)
