package com.example.android.sparkantelope;

import android.view.Surface;

public class SparkAntelopeNative {
    public static final String TAG = "Spark Native";

    static {
        System.loadLibrary("native-spark");
    }

    public static native int startSpark(String comment, int code);

    public static native int stopSpark(int code);

    public static native void setVideoSurface(Surface surface);

}
