package com.liccsu.natool;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;

//Spiritleve 屏幕旋转监听
public abstract class Spiritleve implements SensorEventListener {
	/**
	 * 用法如下：
	 * //屏幕旋转监听 内部类
	 * public class SV extends GT.DeviceListening.Spiritleve {
	 * <p>
	 * private OnClickAdapterListener<String> onClickAdapterListener;
	 * <p>
	 * public SV(Context context,OnClickAdapterListener<String> onClickAdapterListener) {
	 * super(context);
	 * this.onClickAdapterListener = onClickAdapterListener;
	 * }
	 *
	 * @Override protected void getPosition(float xAngle, float yAngle) {
	 * super.getPosition(xAngle, yAngle);
	 * int mobilePosition = getMobilePosition(xAngle, yAngle);
	 * GT.logt("mobilePosition:" + mobilePosition);
	 * if(mobilePosition == 3){
	 * onClickAdapterListener.onClickAdapter("横屏");
	 * }else{
	 * onClickAdapterListener.onClickAdapter("其他");
	 * }
	 * }
	 * <p>
	 * <p>
	 * }
	 * *
	 * 最后再在方法中初始化
	 * new SV(activity);
	 * *
	 */
	float[] acceleromterValues = new float[3];//加速度传感器的值
	float[] magneticValues = new float[3];//磁场传感器的值

	//动作定义 常量
	public static final int LIE_LOW = 0;         //平躺
	public static final int SLEEPER = 1;         //卧铺
	public static final int STAND_RIGHT = 2;     //右立;
	public static final int LEFT_STANDING = 3;   //左立
	public static final int STAND = 4;           //站立
	public static final int HANDSTAND = 5;       //倒立

	public static final int ZHP = 1;            //正横屏
	public static final int FHP = -1;           //反横屏
	public static final int ZSP = 2;            //正竖屏
	public static final int FSP = -2;           //反竖屏

	private SensorManager sensorManager;       //定义取消屏幕监听

	public Spiritleve(Context context) {
		sensorManager = (SensorManager) context.getSystemService(Context.SENSOR_SERVICE);//获取传感器管理器
		//为磁场传感器注册监听器
		sensorManager.registerListener(this, sensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD), SensorManager.SENSOR_DELAY_GAME);
		//为加速度传感器注册监听器
		sensorManager.registerListener(this, sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER), SensorManager.SENSOR_DELAY_GAME);
	}

	@Override
	public void onSensorChanged(SensorEvent event) {    //值改变触发

		if (event.sensor.getType() == Sensor.TYPE_ACCELEROMETER) {
			acceleromterValues = event.values.clone();//获取加速度传感器的值
		} else if (event.sensor.getType() == Sensor.TYPE_MAGNETIC_FIELD) {
			magneticValues = event.values.clone();//获取磁场传感器的值
		}

		float[] Rarry = new float[9];//保存旋转数据的数组
		float[] values = new float[3];//保存方向数据的数组

		SensorManager.getRotationMatrix(Rarry, null, acceleromterValues, magneticValues);//获得一个包含旋转矩阵的数组
		SensorManager.getOrientation(Rarry, values);//获取方向值

		float xAngle = (float) Math.toDegrees(values[1]);//x轴旋转角度
		float yAngle = (float) Math.toDegrees(values[2]);//y轴旋转角度

		getPosition(xAngle, yAngle);//获取小球的位置坐标

	}

	//根据X轴和Y轴的旋转角度确定小篮球的位置
	protected void getPosition(float xAngle, float yAngle) {
		/*
		 这里会返回具体的手机位置信息
		 使用 getMobilePosition 或 getScreenPosition 方法判定 当前手机的位置
		 */
	}

	@Override
	public void onAccuracyChanged(Sensor sensor, int accuracy) {
		//精度改变触发
	}

	/**
	 * 获取当前手机位置
	 * 手机仰天躺(LIE_LOW)、手机卧铺躺(SLEEPER)、手机右立(STAND_RIGHT)、
	 * 手机左立(LEFT_STANDING)、手机站起(STAND)、手机倒立(HANDSTAND)
	 */
	public int getMobilePosition(float xAngle, float yAngle) {
		int X = (int) xAngle;
		int Y = (int) yAngle;
		if ((X >= -10 && X <= 10) && (Y >= -10 && Y <= 10)) {//手机仰天躺
			return LIE_LOW;
		} else if ((X >= -10 && X <= 10) && (Y >= 170 && Y <= 179)) {//手机卧铺躺
			return SLEEPER;
		} else if ((X >= 0 && X <= 2) && (Y >= 11 && Y <= 90)) {//手机右立
			return STAND_RIGHT;
		} else if ((X >= 0 && X <= 2) && (Y <= -1 && Y >= -90)) {//手机左立
			return LEFT_STANDING;
		} else if (X <= -50 && X >= -90) {//手机站起
			return STAND;
		} else if ((X >= 50 && X <= 90)) {//手机倒立
			return HANDSTAND;
		}
		return SLEEPER;//默认仰天躺
	}

	/**
	 * 获取当前手机屏幕位置
	 * 正横屏(ZHP.1)、反横屏(FHP.-1)、竖屏(SP.0)
	 */
	public int getScreenPosition(float xAngle, float yAngle) {
		int X = (int) xAngle;
		int Y = (int) yAngle;

		if ((X >= -30 && X <= 0) && (Y <= -40 && Y >= -179)) {
			return ZHP;
		} else if ((X >= -30 && X <= 0) && (Y >= 40 && Y <= 179)) {
			return FHP;
		} else if ((X >= -90 && X <= -10) && (Y >= -39 && Y <= 179)) {
			return ZSP;
		} else if ((X <= 90 && X >= 10) && (Y <= 39 && Y >= -179)) {
			return FSP;
		}
		return -181;//默认正横屏
	}

	public void close() {
		sensorManager.unregisterListener(this);//取消注册的屏幕监听
	}

}
