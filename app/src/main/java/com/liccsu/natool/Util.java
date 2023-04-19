package com.liccsu.natool;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.Log;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Random;

public class Util {
    
    public static Context getContext() {
        return MainActivity.getContext;
    }
	
	private static void load(Context context, File f, int a, String path) {
        for (int i = 1; i < a; i++) {
            File newFile = new File(f.getPath() + "/" + path + (i) + ".png");
            if (!newFile.exists()) {
                try {
                    InputStream in = context.getAssets().open("image/" + path + (i) + ".png");
                    FileOutputStream out = new FileOutputStream(newFile);
                    byte[] bs = new byte[1 * 1024 * 1024];
                    int count = 0;
                    while ((count = in.read(bs)) != -1) {
                        out.write(bs, 0, count);
                    }
                    out.flush();
                    in.close();
                    out.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

	public static void loadImage(Context context, String assetsPath, String savePath){
		try {
			String fileNames[] = context.getAssets().list(assetsPath);// 获取assets目录下的所有文件及目录名
			if (fileNames.length > 0) {// 如果是目录
				File file = new File(savePath);
				if (!file.exists()) {
					file.mkdirs();// 如果文件夹不存在，则递归
				}
				for (String fileName : fileNames) {
					loadImage(context, assetsPath + "/" + fileName,
							  savePath + "/" + fileName);
				}
			} else {// 如果是文件
				InputStream is = context.getAssets().open(assetsPath);
				FileOutputStream fos = new FileOutputStream(new File(savePath));
				byte[] buffer = new byte[1024];
				int byteCount = 0;
				while ((byteCount = is.read(buffer)) != -1) {// 循环从输入流读取
					// buffer字节
					fos.write(buffer, 0, byteCount);// 将读取的输入流写入到输出流
				}
				fos.flush();// 刷新缓冲区
				is.close();
				fos.close();
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


    public static String getFileMd5(File file) {
        MessageDigest digest = null;
        FileInputStream fis = null;
        byte[] buffer = new byte[1024];
        try {
            if (!file.isFile()) {
                return "";
            }
            digest = MessageDigest.getInstance("MD5");
            fis = new FileInputStream(file);
            while (true) {
                int len;
                if ((len = fis.read(buffer, 0, 1024)) == -1) {
                    fis.close();
                    break;
                }
                digest.update(buffer, 0, len);
            }
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
        BigInteger var5 = new BigInteger(1, digest.digest());
        return String.format("%1$032x", new Object[]{var5});
    }

    public static String getBinData() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 1024; i++) {
            String temp = Integer.toHexString(new Random().nextInt(255) & 0xFF);
            sb.append("\\x");
            if (temp.length() == 1) {
                sb.append("0");
            }
            sb.append(temp);
        }
        return sb.toString();
    }

    private static String getMd5(String text) throws NoSuchAlgorithmException, UnsupportedEncodingException {
        MessageDigest md5 = MessageDigest.getInstance("MD5");
        byte[] bytes = md5.digest(text.getBytes(StandardCharsets.UTF_8));
        StringBuilder builder = new StringBuilder();
        for (byte aByte : bytes) {
            builder.append(Integer.toHexString((0x000000FF & aByte) | 0xFFFFFF00).substring(6));
        }
        return builder.toString();
    }
	
	public static byte[] runShell(String command, boolean isRoot) {
        try {
            Process process = Runtime.getRuntime().exec(isRoot ? "su" : "sh");
            InputStream ins = process.getInputStream();
            InputStream es = process.getErrorStream();
            OutputStream ous = process.getOutputStream();
            ous.write("\n".getBytes());
            ous.flush();
            ous.write(command.getBytes());
            ous.flush();
            ous.write("\n".getBytes());
            ous.flush();
            ous.write("exit".getBytes());
            ous.flush();
            ous.write("\n".getBytes());
            ous.flush();
            byte[] result = readInputStream(ins, false);
            byte[] error = readInputStream(es, false);
            process.waitFor();
            ins.close();
            es.close();
            ous.close();
            if (new String(error).trim().isEmpty()) {
                return result;
            } else {
                return ("Shell Result : \n" + new String(result) + "\n" + "Shell Error : \n" + new String(error) + "\n").getBytes();
            }
        } catch (Throwable th) {
            return ("Application Error : \n" + Log.getStackTraceString(th)).getBytes();
        }
    }

    public static byte[] readInputStream(InputStream ins, boolean close) {
        try {
            ByteArrayOutputStream bos = new ByteArrayOutputStream();
            int i = -1;
            byte[] buf = new byte[1024];
            while ((i = ins.read(buf)) != -1) {
                bos.write(buf, 0, i);
            }
            if (close) {
                ins.close();
                bos.close();
            }
            return bos.toByteArray();
        } catch (Throwable th) {
            return Log.getStackTraceString(th).getBytes();
        }
    }
	
	public static void copyFileUsingFileStreams(File source, File dest)
	throws IOException {
        InputStream input = null;
        OutputStream output = null;
        try {
            input = new FileInputStream(source);
            output = new FileOutputStream(dest);
            byte[] buf = new byte[1024];
            int bytesRead;
            while ((bytesRead = input.read(buf)) !=-1){
                output.write(buf, 0, bytesRead);
            }
        } finally {
            input.close();
            output.close();
        }
    }

    public static Bitmap compressImage(Bitmap image,int size,int options) {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        // 质量压缩方法，这里100表示不压缩，把压缩后的数据存放到baos中
        image.compress(Bitmap.CompressFormat.JPEG, 80, baos);
        // 循环判断如果压缩后图片是否大于100kb,大于继续压缩
        while (baos.toByteArray().length / 1024 > size) {
            options -= 10;// 每次都减少10
            baos.reset();// 重置baos即清空baos
            // 这里压缩options%，把压缩后的数据存放到baos中
            image.compress(Bitmap.CompressFormat.JPEG, options, baos);
        }
        // 把压缩后的数据baos存放到ByteArrayInputStream中
        ByteArrayInputStream isBm = new ByteArrayInputStream(baos.toByteArray());
        // 把ByteArrayInputStream数据生成图片
        Bitmap bitmap = BitmapFactory.decodeStream(isBm, null, null);
        return bitmap;
    }
    
}
