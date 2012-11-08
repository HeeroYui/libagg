LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# name of the librairy
LOCAL_MODULE := agg

# name of the dependency
LOCAL_LIBRARIES := freetype etk

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/agg/ \
                    $(LOCAL_PATH)/agg/util/

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

# load the common sources file of the platform
include $(LOCAL_PATH)/file.mk

LOCAL_SRC_FILES := $(FILE_LIST)

include $(BUILD_STATIC_LIBRARY)
