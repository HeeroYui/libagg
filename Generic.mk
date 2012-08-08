
# name of the librairy
LOCAL_MODULE := agg

# get the tag of the current project : 
LOCAL_VERSION_TAG=$(shell cd $(LOCAL_PATH) ; git describe --tags)
LOCAL_VERSION_TAG_SHORT=$(shell cd $(LOCAL_PATH) ; git describe --tags --abbrev=0)
$(info $(LOCAL_MODULE) version TAG : $(LOCAL_VERSION_TAG))


# name of the dependency
LOCAL_STATIC_LIBRARIES := freetype

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/agg/ \
                    $(LOCAL_PATH)/agg/util/

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

ifeq ($(DEBUG),1)
LOCAL_CFLAGS := -DAGG_DEBUG_LEVEL=3 \
                -DAGG_VERSION_TAG_NAME="\"$(LOCAL_VERSION_TAG_SHORT)-debug\""
else
LOCAL_CFLAGS := -DAGG_DEBUG_LEVEL=3 \
                -DAGG_VERSION_TAG_NAME="\"$(LOCAL_VERSION_TAG_SHORT)-release\""
endif

# load the common sources file of the platform
include $(LOCAL_PATH)/file.mk

LOCAL_SRC_FILES := $(FILE_LIST)

