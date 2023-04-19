package com.liccsu.natool;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Align;
import android.graphics.Paint.Style;
import android.graphics.PixelFormat;
import android.graphics.PorterDuff;
import android.os.RemoteException;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.annotation.NonNull;
import android.content.Context;
import android.os.RemoteException;
import android.util.AttributeSet;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.WindowManager;
import android.graphics.PixelFormat;

public class ESPView extends SurfaceView implements SurfaceHolder.Callback {
	
    	public static byte fontData[];
		int action;

	public ESPView(Context context) {
			this(context, null);
		}

	public ESPView(Context context, AttributeSet attrs) {
			this(context, attrs, 0);
		}

	public ESPView(Context context, AttributeSet attrs, int defStyleAttr) {
			super(context, attrs, defStyleAttr);
			getHolder().addCallback(this);
			setZOrderOnTop(true);
			getHolder().setFormat(PixelFormat.TRANSPARENT);
		}
		
    @Override
    public void surfaceCreated(final SurfaceHolder holder) {
        Log.e("ESPView","surfaceCreated");
        try {
            MainActivity.iTestService.setSurface(holder.getSurface());
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
		
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {}
	

}

