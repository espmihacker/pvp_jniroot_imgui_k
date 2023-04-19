package com.liccsu.natool;

import android.content.ComponentName;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.util.Log;

public class AIDLConnection implements ServiceConnection {
   
        private final boolean isDaemon;

        AIDLConnection(boolean b) {
            isDaemon = b;
        }

        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            MainActivity.iTestService= IMutual.Stub.asInterface(service);
            Log.d("Shocker","Connected");
        }

        @Override
        public void onServiceDisconnected(ComponentName componentName) {
            Log.d("Shocker","Disconnected");

        }
  
	
}
