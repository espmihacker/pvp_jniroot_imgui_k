package com.liccsu.natool;

import android.graphics.Canvas;
import android.view.MotionEvent;
import android.view.Surface;

public class SuperJNI {
	
	public static native void setSurface(Surface surface);
    public static native void navateInputEvent(MotionEvent motionEvent);
    public static native float getMenuW();
    public static native float getMenuH();
    public static native float getMenuX();
    public static native float getMenuY();
    public static native void setPid(int pid);
    public static native int getPID(String packageName);
	/*
	public static native void setWidth(int width);
	public static native void setHeight(int height);
	public static native void setFilesDir(String filesDir);
	*/
}
