LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := IMGUI
LOCAL_ARM_MODE := arm

LOCAL_CFLAGS := -Wno-error=format-security -w
LOCAL_CFLAGS += -fno-exceptions -fpermissive -fvisibility=hidden
LOCAL_CPPFLAGS := -Wno-error=format-security -fpermissive -w -Werror -s -std=c++14
LOCAL_CPPFLAGS += -fno-exceptions -fms-extensions -Wno-error=c++11-narrowing -fvisibility=hidden
LOCAL_CPPFLAGS += -frtti
LOCAL_CPPFLAGS += -fexceptions

LOCAL_C_INCLUDES += $(LOCAL_PATH)/imgui
LOCAL_C_INCLUDES += $(LOCAL_PATH)/UE4
LOCAL_C_INCLUDES += $(LOCAL_C_INCLUDES:$(LOCAL_PATH)/%:=%)


FILE_LIST += $(wildcard $(LOCAL_PATH)/UE4/*.c*)
FILE_LIST += $(wildcard $(LOCAL_PATH)/*.c*)
FILE_LIST += $(wildcard $(LOCAL_PATH)/imgui/*.c*)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%) 

LOCAL_LDFLAGS += -llog -lEGL -lGLESv3 -landroid

LOCAL_CFLAGS += -std=c++14
include $(BUILD_SHARED_LIBRARY)
