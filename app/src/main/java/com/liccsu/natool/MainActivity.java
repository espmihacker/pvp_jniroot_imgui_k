package com.liccsu.natool;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Point;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager;
import android.widget.Toast;
import com.liccsu.natool.MainActivity;
import com.topjohnwu.superuser.ipc.RootService;
import android.widget.EditText;
import android.widget.TextView;
import java.io.FileWriter;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.net.URL;
import java.net.HttpURLConnection;
import java.io.OutputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.math.BigInteger;
import android.content.SharedPreferences;
import android.provider.Settings;
import org.json.JSONObject;
import org.json.JSONException;
import android.util.Log;
import java.io.InputStream;
import java.io.FileOutputStream;

public class MainActivity extends Activity {
	public static int 真实宽;//分辨率x
    public static int 真实高;//分辨率y
	public static Context getContext;
	public static IMutual iTestService;
	public static native void Resolution(float px, float py);
    public static native void Close();
    public static native void getReady();
    
    static String 卡密,机器码;

    public static String appkey="9afa93a1a780126b942d3db0b04338de";
    public static String basekey="j3lWE6gfkDQq1X5x0aOcGoiRSV9BIhTtJb+w/FCsLYuPMvrU2K4dpA7neHZ8mzyN";
    public static String webapi="http://w.t3yanzheng.com/68EBAAAC3D6FC119";
    public static final String api3 = "http://w.t3yanzheng.com/74FE1607522BED20";
    
    public static boolean 登录=false;
    
    public static EditText input;

    public static TextView textView1;
    
	private Point point;
    private static MainActivity Instance;
	private WindowManager manager;

	private WindowManager.LayoutParams vParams;

    private String MyCamilo, Mytime, MyMachineCode, MyTheAnnouncement, MyUpdate, MyStamp, MyTheSignature, MyReturn;
    
	private View vTouch;
    public WindowManager windowManager,xfqManager;
	public void 储存权限() {
        boolean isGranted = true;
        if (android.os.Build.VERSION.SDK_INT >= 23) {
            if (this.checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
                isGranted = false;
            }
            if (this.checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
                isGranted = false;
            }
            if (!isGranted) {
                this.requestPermissions(
                    new String[]{Manifest.permission.ACCESS_COARSE_LOCATION, Manifest.permission
                        .ACCESS_FINE_LOCATION,
                        Manifest.permission.READ_EXTERNAL_STORAGE,
                        Manifest.permission.WRITE_EXTERNAL_STORAGE},
                    102);
            }
        }
    }
    
    private boolean 写出资源文件(String outPath, String fileName) throws IOException
    {
        File file = new File(outPath);
        if (!file.exists())
        {
            if (!file.mkdirs())
            {
                Log.e("--Method--", "copyAssetsSingleFile: cannot create directory.");
                return false;
            }
        }
        try
        {
            InputStream inputStream = getAssets().open(fileName);
            File outFile = new File(file, fileName);
            FileOutputStream fileOutputStream = new FileOutputStream(outFile);
            // Transfer bytes from inputStream to fileOutputStream
            byte[] buffer = new byte[1024];
            int byteRead;
            while (-1 != (byteRead = inputStream.read(buffer)))
            {
                fileOutputStream.write(buffer, 0, byteRead);
            }
            inputStream.close();
            fileOutputStream.flush();
            fileOutputStream.close();
            return true;
        }
        catch (IOException e)
        {
            e.printStackTrace();
            return false;
        }
    }

    private void 执行(String shell) {
        String s=shell;
        try {
            Runtime.getRuntime().exec(s, null, null);//执行
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static boolean deleteFile(String filename) {
        return new File(filename).delete();
    }
    
    public static boolean 删除文件(String folder) {
        if (folder == null || folder.length() == 0 || folder.trim().length() == 0) {
            return true;
        }
        File file = new File(folder);
        if (!file.exists()) {
            return true;
        }
        if (file.isFile()) {
            return file.delete();
        }
        if (!file.isDirectory()) {
            return false;
        }
        for (File f : file.listFiles()) {
            if (f.isFile()) {
                f.delete();
            } else if (f.isDirectory()) {
                deleteFile(f.getAbsolutePath());
            }
        }
        return file.delete();
    }
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
        input = findViewById(R.id.activityLoginMainEditText1);
        input.setText(读取文件("/sdcard/kmm"));
        创建文件("/storage/emulated/0/stop");
        //GetMyUpdate();
		getContext = this;
		//MainActivity.this.requestWindowFeature(Window.FEATURE_NO_TITLE);
		//MainActivity.this.getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
		RootService.bind(new Intent(this, AIDLService.class), new AIDLConnection(false));
		//new SV(MainActivity.this);
		Util.loadImage(this, "image", this.getFilesDir().getAbsolutePath());
		//SuperJNI.setFilesDir(this.getFilesDir().getAbsolutePath());
        findViewById(R.id.go_app).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    new Thread(new Runnable(){
                            @Override
                            public void run() {
                                // Base64New.setbase(basekey);
                                String kami=input.getText().toString();
                                // kami=Base64New.str2HexStr(Base64New.encodeBase64Str(kami));
                                String imei=Settings.System.getString(getContentResolver(), Settings.Secure.ANDROID_ID);
                                // imei=Base64New.str2HexStr(Base64New.encodeBase64Str(imei));
                                // kami = "HWNDY489221116BE42F10DC0D9EEBE54";
                                String fh=Post(webapi,"kami="+kami+"&imei="+imei+"&print=json");
                                final String jfh=fh;// Base64New.decodeBase64str(fh);
                                runOnUiThread(new Runnable(){
                                        @Override
                                        public void run() {
                                            try {
                                                JSONObject jsonObject = new JSONObject(jfh);
                                                String code=jsonObject.getString("code");//是否登录成功
                                                String id=jsonObject.optString("id");//卡密ID
                                                String endtime=jsonObject.optString("end_time");//到期时间
                                                String token=jsonObject.optString("token");//校验密钥
                                                String date=jsonObject.optString("date");//服务器时间
                                                Long timee=jsonObject.optLong("time");//服务器时间戳
                                                if(code.equals("200")){//登录成功
                                                    String jmcs=id+appkey+endtime+date;
                                                    if(token.equals(stringToMD5(jmcs))){
                                                        Long starts  = System.currentTimeMillis();
                                                        starts=starts/10000;
                                                        timee=timee/10;
                                                        if(String.valueOf(starts).equals(String.valueOf(timee))){
                                                            StartGame.showFloatWindow(MainActivity.this);
                                                            // Toast.makeText(MainActivity.this, "Start", Toast.LENGTH_SHORT).show();
                                                            删除文件("/storage/emulated/0/stop");
                                                            执行("chmod 777 " + getCacheDir() + "/assets/hz");
                                                            执行("chmod 777 " + getCacheDir() + "/assets/gb");
                                                            try {
                                                                写出资源文件(getCacheDir() + "/assets", "hz");
                                                                写出资源文件(getCacheDir() + "/assets", "gb");
                                                            } catch (IOException e) {}
                                                            
                                                            写入("/sdcard/kmm",input.getText().toString());  
                                                            机器码 = Settings.System.getString(getContentResolver(), Settings.Secure.ANDROID_ID);
                                                            写入("/sdcard/sbm", 机器码);
                                                            Toast.makeText(getApplicationContext(),"登录成功\n到期时间："+endtime,Toast.LENGTH_LONG).show();
                                                        }
                                                        else{
                                                            Toast.makeText(getApplicationContext(),"数据过期",Toast.LENGTH_LONG).show();
                                                        }
                                                    }
                                                    else{
                                                        Toast.makeText(getApplicationContext(),"校验失败，数据异常",Toast.LENGTH_LONG).show();
                                                    }
                                                }
                                                else{
                                                    String ms=jsonObject.getString("msg");
                                                    Toast.makeText(getApplicationContext(),ms,Toast.LENGTH_LONG).show();
                                                }
                                            } catch (JSONException e) {
                                                Toast.makeText(getApplicationContext(),jfh,Toast.LENGTH_LONG).show();
                                            }
                                        }
                                    });
                            }
                        }).start();

                }

            });
		
	}
    
    public static void 写入(String 路径,String 内容){
        try {
            FileWriter fw = new FileWriter(路径);
            fw.write(内容);
            fw.close();
        } catch (IOException e) {}
    }

    public static String 读取文件(String path) {
        String str = "";
        try {
            File urlFile = new File(path);
            InputStreamReader isr = new InputStreamReader(new FileInputStream(urlFile), "UTF-8");
            BufferedReader br = new BufferedReader(isr);

            String mimeTypeLine = null;
            while ((mimeTypeLine = br.readLine()) != null) {
                str = str + mimeTypeLine;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return str;
    }

    public static void 创建文件(String path) {
        //新建一个File类型的成员变量,传入文件名路径
        File mFile=new File(path);
        //判断文件是否存在,存在就删除
        if (mFile.exists()) {
            mFile.delete();
        }
        try {
            //创建文件
            mFile.createNewFile();
            //给一个吐司提示,显示创建成功
        } catch (IOException e) {
            e.printStackTrace();
        }
	}
    
    public static String Post(String ur,String byteString){
        String fh="";
        try {
            URL url=new URL(ur);
            HttpURLConnection HttpURLConnection=(HttpURLConnection) url.openConnection();
            HttpURLConnection.setReadTimeout(9000);
            HttpURLConnection.setRequestMethod("POST");
            OutputStream outputStream = HttpURLConnection.getOutputStream();

            outputStream.write(byteString.getBytes());
            BufferedReader BufferedReader=new BufferedReader(new InputStreamReader(HttpURLConnection.getInputStream()));
            String String="";
            StringBuffer StringBuffer=new StringBuffer();
            while ((String = BufferedReader.readLine()) != null) {
                StringBuffer.append(String);
            }
            fh=StringBuffer.toString();
        }
        catch (IOException e){}
        return fh;
    }

    public static String stringToMD5(String plainText) {
        byte[] secretBytes = null;
        try {
            secretBytes = MessageDigest.getInstance("md5").digest(
                plainText.getBytes());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException("没有这个md5算法！");
        }
        String md5code = new BigInteger(1, secretBytes).toString(16);
        for (int i = 0; i < 32 - md5code.length(); i++) {
            md5code = "0" + md5code;
        }
        return md5code;
    }
    
    private void GetMyUpdate() {
        new Thread() {
            @Override
            public void run() {
                MyUpdate = Post(api3, "&t=" + Mytime);
                MyUpdate = Base64New.decodeBase64str(MyUpdate);
                runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            if (MyUpdate.equals("1000")) {
                                Toast.makeText(getApplication(), "最新版", Toast.LENGTH_SHORT).show();

                            } else {
                                Toast.makeText(getApplication(), "有新版本", Toast.LENGTH_SHORT).show();

                            }
                        }
                    });
            }
        }.start();
    }
    
}
