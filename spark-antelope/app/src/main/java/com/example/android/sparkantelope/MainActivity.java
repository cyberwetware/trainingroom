package com.example.android.sparkantelope;

import android.graphics.PixelFormat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    private SurfaceHolder mSurfaceHolder;
    private SurfaceView mSurfaceView;
    private static final String TAG = "Spark Antelope";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mSurfaceView = (SurfaceView) findViewById(R.id.surface);
        mSurfaceHolder = mSurfaceView.getHolder();
        mSurfaceHolder.setFormat(PixelFormat.RGBX_8888);
        mSurfaceHolder.addCallback(new SurfaceHolder.Callback() {
            @Override
            public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
                Log.d(TAG, "Surface format: " + "\n"
                        + "width  " + width + "\n"
                        + "height " + height + "\n"
                        + "format " + format);
            }

            @Override
            public void surfaceCreated(SurfaceHolder holder) {
                SparkAntelopeNative.setVideoSurface(mSurfaceHolder.getSurface());
            }

            @Override
            public void surfaceDestroyed(SurfaceHolder holder) {
            }
        });

        // Initial button click handlers
        ((Button) findViewById(R.id.button_start)).setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                new Thread() {
                    @Override
                    public void run() {
                        SparkAntelopeNative.startSpark("Start spark", 0);
                    }
                }.start();

            }
        });

        ((Button) findViewById(R.id.button_stop)).setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                SparkAntelopeNative.stopSpark(0);
            }
        });
        Log.d(TAG, "onCreate finished");
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    protected void onDestory() {
        super.onDestroy();
    }
}
