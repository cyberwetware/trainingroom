/*
 * Copyright 2012, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "Spark Native"

#include <jni.h>
#include <unistd.h>
#include <android/log.h>
#include <android/native_window_jni.h>
#include "graphic-source.h"

#define TAG "Spark Native"

#ifndef LOGD
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#endif

#ifndef LOGE
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#endif

#ifndef LOGW
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#endif

#ifndef LOGI
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#endif

#ifndef LOGV
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#endif

static ANativeWindow* mNativeWindow;

typedef enum {
	SPARK_IDLE,
	SPARK_RUNNING,
	SPRAK_STOPPING,
} spark_state;
spark_state mState = SPARK_IDLE;

static void setVideoSurface(JNIEnv *env, jobject thiz, jobject jsurface) {
	LOGD("Set video surface");
	mNativeWindow = ANativeWindow_fromSurface(env, jsurface);
	if(mNativeWindow == NULL) {
		LOGE("Set video surface failed");
		return;
	}
}

static int startSpark(JNIEnv *env, jobject clazz, jstring jcomment, int jcode) {
	LOGD("Start spark antelope");
	if(mNativeWindow == NULL) {
		LOGE("Invalid ANativeWindow instance");
		return 0;
	}

	int32_t w = ANativeWindow_getWidth(mNativeWindow);
	int32_t h = ANativeWindow_getHeight(mNativeWindow);
	LOGD("Native window region width[%d] height[%d]", w, h);

	unsigned char *img = (unsigned char *)malloc(w * h * 4);
	if (img == NULL) {
		LOGE("Allocated graphic buffer faield: %d", errno);
		return 0;
	}

	ANativeWindow_setBuffersGeometry(mNativeWindow, w, h, WINDOW_FORMAT_RGBA_8888);
	ANativeWindow_Buffer buffer;
	int lockResult = -1;
	mState = SPARK_RUNNING;

	fill_truecolor_rgba_buffer(w, h, (void *)img);
	while (mState == SPARK_RUNNING) {
		lockResult = ANativeWindow_lock(mNativeWindow, &buffer, NULL);
		if (lockResult == 0) {
			memcpy(buffer.bits, img, w * h * 4);
			ANativeWindow_unlockAndPost(mNativeWindow);
		}
		sleep(1);
	}
	mState = SPARK_IDLE;
	free(mNativeWindow);

	return 1;
}

static int stopSpark(JNIEnv *env, jobject clazz, int jcode) {
	LOGD("Stop spark...");
	mState = SPRAK_STOPPING;
	while (mState == SPRAK_STOPPING) {
		sleep(1);
		if(mState == SPARK_IDLE) {
			LOGI("Stop spark antelope done");
			break;
		}
	}

	if (mNativeWindow != NULL) {
		ANativeWindow_release(mNativeWindow);
		mNativeWindow = NULL;
	}

	return 1;
}


extern "C" {

// Implementation with JNI interfaces
JNIEXPORT jint JNICALL Java_com_example_android_sparkantelope_SparkAntelopeNative_startSpark
		(JNIEnv *env, jclass thiz, jstring jcomment, jint code) {
	return startSpark(env, thiz, jcomment, code);
}

JNIEXPORT jint JNICALL Java_com_example_android_sparkantelope_SparkAntelopeNative_stopSpark
		(JNIEnv *env, jclass thiz, jint code) {
	return stopSpark(env, thiz, code);
}

JNIEXPORT void JNICALL Java_com_example_android_sparkantelope_SparkAntelopeNative_setVideoSurface
		(JNIEnv *env, jclass thiz, jobject jsurface) {
	setVideoSurface(env, thiz, jsurface);
}

};

