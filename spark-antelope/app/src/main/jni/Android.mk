LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := native-spark
LOCAL_SRC_FILES := native-spark.cpp

include $(BUILD_SHARED_LIBRARY)

