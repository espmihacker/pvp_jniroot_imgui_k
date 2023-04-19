package com.liccsu.natool;

import android.annotation.NonNull;
import android.content.Intent;
import android.os.IBinder;
import android.os.Process;
import android.os.RemoteException;
import android.view.MotionEvent;
import android.view.Surface;
import com.topjohnwu.superuser.ipc.RootService;

class AIDLService extends RootService {
	static {
		if (Process.myUid() == 0)
			System.loadLibrary("IMGUI");
	}

	

	@Override
	public IBinder onBind(@NonNull Intent intent) {
		return new IMutual.Stub() {
			@Override
            public void setSurface(Surface surface) throws RemoteException {
                SuperJNI.setSurface(surface);
            }

            @Override
            public void navateInputEvent(MotionEvent motionEvent) throws RemoteException {
                SuperJNI.navateInputEvent(motionEvent);
            }

            @Override
            public float getMenuW() throws RemoteException {

                return SuperJNI.getMenuW();
            }

            @Override
            public float getMenuH() throws RemoteException {

                return SuperJNI.getMenuH();
            }

            @Override
            public float getMenuX() throws RemoteException {

                return SuperJNI.getMenuX();
            }

            @Override
            public float getMenuY() throws RemoteException {

                return SuperJNI.getMenuY();
            }
			@Override
            public void setPid(int pid) throws RemoteException {
                SuperJNI.setPid(pid);
            }

            @Override
            public int getPID(String packageName) throws RemoteException {
                return SuperJNI.getPID(packageName);
            }
			/*
			@Override
            public void setWidth(int width) throws RemoteException {
                SuperJNI.setWidth(width);
            }
			
			@Override
            public void setHeight(int height) throws RemoteException {
                SuperJNI.setHeight(height);
            }
            */
			/*
			@Override
            public void setFilesDir(String filesDir) throws RemoteException {
                SuperJNI.setFilesDir(filesDir);
            }
            */
		};
	}
}
