LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# load the common sources file of the platform
include $(LOCAL_PATH)/Generic.mk

LOCAL_CFLAGS += -D__PLATFORM__Android

include $(BUILD_STATIC_LIBRARY)
