package com.liccsu.natool;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.res.Configuration;
import android.graphics.PixelFormat;
import android.graphics.Point;
import android.os.Build;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.SystemClock;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.SurfaceView;
import android.view.View;
import android.view.WindowManager;
import android.view.WindowManager.LayoutParams;
import android.widget.ImageView;
import android.widget.TextView;
import com.liccsu.natool.MainActivity;

public class StartGame{
    public static WindowManager manager;
    public static View editPwdView;
    public static int width;
    public static int height;
    public static View view;
    public static ImageView imageView;
    public static TextView tv;
	
	static SurfaceView surfaceView;
	
	private final static String NOTIFICATION_CHANNEL_ID = "CHANNEL_ID";
    private final static String NOTIFICATION_CHANNEL_NAME = "守护进程";
	private final static int FOREGROUND_ID = 1;
	
    @SuppressLint("StaticFieldLeak")
    static WindowManager.LayoutParams params;
	static WindowManager.LayoutParams layoutParams;
	static DisplayMetrics dm = new DisplayMetrics();
	/*
	@Override
    public IBinder onBind(Intent intent) {
        throw new UnsupportedOperationException("Not yet implemented");
    }
	
	@Override
    public void onDestroy() {
        //Log.w("Liccsu-natool", "Draw is Stop!");
        super.onDestroy();
    }
	
	public int onStartCommand(Intent intent, int flags, int startId) {
        super.onStartCommand(intent, flags, startId);
        NotificationChannel notificationChannel = new NotificationChannel(
			NOTIFICATION_CHANNEL_ID,
			NOTIFICATION_CHANNEL_NAME,
			NotificationManager.IMPORTANCE_HIGH
        );
        notificationChannel.setLockscreenVisibility(Notification.VISIBILITY_PUBLIC);
        NotificationManager notificationManager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
        notificationManager.createNotificationChannel(notificationChannel);

        intent = new Intent(getApplicationContext(), MainActivity.class);  //点击通知栏后想要被打开的页面MainActivity.class
        @SuppressLint("UnspecifiedImmutableFlag") PendingIntent pendingIntent = PendingIntent.getActivity(this, 0, intent, 0);  //点击通知栏触发跳转
        Notification notification = new Notification.Builder(this, NOTIFICATION_CHANNEL_ID)
			.setSmallIcon(R.drawable.ic_launcher)
			.setContentTitle("Liccsu")
			.setContentText("进程守护中...")
			.setContentIntent(pendingIntent)
			.build();
        notification.flags |= Notification.FLAG_NO_CLEAR;
        startForeground(FOREGROUND_ID, notification);
        return Service.START_STICKY;
    }
    */
/*
    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
		
        if (params != null && surfaceView != null) {
            manager.getDefaultDisplay().getRealMetrics(dm);
            params.width = dm.widthPixels;
            params.height = dm.heightPixels;
			if(dm.widthPixels == height && dm.heightPixels == height) {
				layoutParams.x = layoutParams.x*dm.widthPixels/dm.heightPixels;
				layoutParams.y = layoutParams.y*dm.heightPixels/dm.widthPixels;
			}
			
			width = dm.widthPixels;
			height = dm.heightPixels;
            manager.updateViewLayout(surfaceView, layoutParams);
        }
		
        //SuperJNI.setWidth(dm.widthPixels);
		//SuperJNI.setHeight(dm.heightPixels);
        //GLES3JNIView.real(dm.widthPixels, dm.heightPixels);
        //Log.e("Alice-", "Width= " + dm.widthPixels + " Height= " + dm.heightPixels);
    }
	*/
	public static void showFloatWindow(final Activity Activity) {
        manager = (WindowManager) Activity.getSystemService(Context.WINDOW_SERVICE);
		Point point = new Point();
        manager.getDefaultDisplay().getRealSize(point);
        width = Math.min(point.x, point.y);
        height = Math.max(point.x, point.y);
        params = new WindowManager.LayoutParams();
        params.systemUiVisibility = View.SYSTEM_UI_FLAG_HIDE_NAVIGATION |
			View.SYSTEM_UI_FLAG_FULLSCREEN |
			View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION |
			View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY |
			View.SYSTEM_UI_FLAG_LAYOUT_STABLE |
			View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN;
        params.type = Build.VERSION.SDK_INT >= Build.VERSION_CODES.O ? WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY : WindowManager.LayoutParams.TYPE_SYSTEM_ALERT;
        params.gravity = Gravity.TOP | Gravity.LEFT;
        params.format = PixelFormat.TRANSPARENT;
        params.width = WindowManager.LayoutParams.MATCH_PARENT;
        params.height = WindowManager.LayoutParams.MATCH_PARENT;
        params.flags = //WindowManager.LayoutParams.FLAG_SECURE |//防截屏
			//WindowManager.LayoutParams.FLAG_DITHER | //抖动(过录屏)
			WindowManager.LayoutParams.FLAG_NOT_TOUCHABLE |//不接受触控
			WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE |
			WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL |
//                        WindowManager.LayoutParams.FLAG_SPLIT_TOUCH |
			WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED |//硬件加速
			WindowManager.LayoutParams.FLAG_FULLSCREEN |//隐藏状态栏导航栏以全屏(貌似没什么用)
			WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS |//忽略屏幕边界
			WindowManager.LayoutParams.FLAG_LAYOUT_ATTACHED_IN_DECOR |//显示在状态栏上方(貌似高版本无效
			WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN;//布局充满整个屏幕 忽略应用窗口限制

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            params.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;//覆盖刘海
        }

        surfaceView = new SurfaceView(Activity);
        surfaceView.setZOrderOnTop(true);
        surfaceView.getHolder().setFormat(PixelFormat.TRANSPARENT);
        layoutParams = new WindowManager.LayoutParams();
        layoutParams.type = Build.VERSION.SDK_INT >= Build.VERSION_CODES.O ? WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY : WindowManager.LayoutParams.TYPE_SYSTEM_ALERT;
        layoutParams.gravity = Gravity.TOP | Gravity.LEFT;
        layoutParams.format = PixelFormat.TRANSPARENT;
        layoutParams.width = 740;
        layoutParams.height = 480;
        layoutParams.x = 120;
        layoutParams.y = 120;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            layoutParams.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;//覆盖刘海
        }
        //surfaceView.setBackgroundColor(Color.RED);
        layoutParams.flags = 1024 | 8 | 256 |
			//WindowManager.LayoutParams.FLAG_SECURE |//防截屏
			 WindowManager.LayoutParams.FLAG_DITHER | //抖动(过录屏)
//                WindowManager.LayoutParams.FLAG_SPLIT_TOUCH |
			WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL |
			WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED |//硬件加速
			WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS |//忽略屏幕边界
			WindowManager.LayoutParams.FLAG_LAYOUT_ATTACHED_IN_DECOR;//显示在状态栏上方(貌似高版本无效

        surfaceView.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
					try {
						MainActivity.iTestService.navateInputEvent(event);
						int x = (int) MainActivity.iTestService.getMenuX();
						int y = (int) MainActivity.iTestService.getMenuY();
						int w = (int) MainActivity.iTestService.getMenuW();

						layoutParams.x = x;
						layoutParams.y = y;
						layoutParams.width = w;

						manager.updateViewLayout(surfaceView, layoutParams);
						new Thread(new Runnable() {
								@Override
								public void run() {
									SystemClock.sleep(200);
									Activity.runOnUiThread(new Runnable() {
											public void run() {
												int h = 0;
												try {
													h = (int) MainActivity.iTestService.getMenuH();
												} catch (RemoteException e) {
													e.printStackTrace();
												}
												layoutParams.height = h;
												manager.updateViewLayout(surfaceView, layoutParams);
											}
										});
								}
							}).start();
					} catch (RemoteException e) {
						e.printStackTrace();
					}

					return true;
				}
			});
        runWindow(Activity,params, surfaceView, layoutParams);
    }

    public static int pid = -1;

    public static void runWindow(final Activity Activity,final WindowManager.LayoutParams lp, final SurfaceView surfaceView, final WindowManager.LayoutParams layoutParams) {
        new Thread(new Runnable() {

				@Override
				public void run() {
					
						try {
							pid = MainActivity.iTestService.getPID("com.tencent.mobileqq");
						} catch (RemoteException e) {
							e.printStackTrace();
						}
						
					
					Activity.runOnUiThread(new Runnable() {
							@Override
							public void run() {
								ESPView dv = new ESPView(Activity);
								manager.addView(dv, lp);
								manager.addView(surfaceView, layoutParams);
							}
						});
				}
			}).start();
	}
}
