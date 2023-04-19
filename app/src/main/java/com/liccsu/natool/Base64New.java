package com.liccsu.natool;

public class Base64New {

    private static final int BASE = 3;
    private static final int EXPAND = 4;
    private static final int SIGN = -128;
    private static final char END = '=';
    //base64的基准字符，可以自定义，不过最好是可打印字符
    public static String str = "";

    public static void setbase(String sr){
        str=sr;
    }


    public static String encodeBase64Str(String str){
        return new String(encodeBase64(str));
    }

    public static byte[] encodeBase64(String str){
        return encodeBase64(str.getBytes());
    }

    public static byte[] encodeBase64(byte[] data){
        int len = data.length;
        int overBytes = len%BASE;
        int lenBytes = len/BASE;

        int encodeBytesLen = 0;
        if(overBytes == 0){
            encodeBytesLen = lenBytes*EXPAND;
        }else{
            encodeBytesLen = (lenBytes+1)*EXPAND;
        }

        byte[] encodeBytes = new byte[encodeBytesLen];
        int step = 0;
        int encodeIndex = 0;
        byte b1,b2,b3,m0,m1;
        for(int i=0;i<lenBytes;i++){
            step = i*3;
            //取出三个字节
            b1 = data[step];
            b2 = data[step+1];
            b3 = data[step+2];
            //获取第一个字节的最后两位
            m0 = (byte) (b1&0x03);
            //获取第二个字节的最后四位
            m1 = (byte) (b2&0x0f);
            // 字节&-128，非负数都为0，负数的话把高位11转换成00
            byte b1Index = (byte)((b1&SIGN)==0?b1>>2:b1>>2^0xc0);
            byte b2Index = (byte)((b2&SIGN)==0?b2>>4:b2>>4^0xf0);
            byte b3Index = (byte)((b3&SIGN)==0?b3>>6:b3>>6^0xfc);
            //根据字节的数值当做下标，寻找对应的字符

            
                encodeBytes[encodeIndex]= (byte) str.charAt(b1Index);
                encodeBytes[encodeIndex+1]= (byte) str.charAt(b2Index|(m0<<4));
                encodeBytes[encodeIndex+2]= (byte) str.charAt(b3Index|(m1<<2));
                encodeBytes[encodeIndex+3]= (byte) str.charAt(b3&0x3f);

                encodeIndex+=4;
           
        }
        //当剩下一个字节，或者两个字节时，需要做的处理
        if(overBytes == 1){
            b1 = data[len-1];
            byte b1Index = (byte)((b1&SIGN)==0?b1>>2:b1>>2^0xc0);
            m0 = (byte) (b1&0x03);
            encodeBytes[lenBytes*EXPAND]= (byte) str.charAt(b1Index);
            encodeBytes[lenBytes*EXPAND+1]= (byte) str.charAt((m0<<4));
            encodeBytes[lenBytes*EXPAND+2]= END;
            encodeBytes[lenBytes*EXPAND+3]= END;
        }else if(overBytes == 2){
            b1 = data[len-2];
            b2 = data[len-1];
            byte b1Index = (byte)((b1&SIGN)==0?b1>>2:b1>>2^0xc0);
            byte b2Index = (byte)((b2&SIGN)==0?b2>>4:b2>>4^0xf0);
            m0 = (byte) (b1&0x03);
            m1 = (byte) (b2&0x0f);

            encodeBytes[lenBytes*EXPAND]= (byte) str.charAt(b1Index);
            encodeBytes[lenBytes*EXPAND+1]= (byte) str.charAt(b2Index|(m0<<4));
            encodeBytes[lenBytes*EXPAND+2]= (byte) str.charAt((m1<<2));
            encodeBytes[lenBytes*EXPAND+3]= END;
        }
        return encodeBytes;
    }

    public static String decodeBase64str(String str){
        return new String(decodeBase64(str));
    }

    public static byte[] decodeBase64(String str){
        return decodeBase64(str.getBytes());
    }


    public static byte[] decodeBase64(byte[] data){
        if(data.length == 0){
            return new byte[0];
        }
        int len = 0;
        if((len = data.length%EXPAND)!=0){
            throw new IllegalArgumentException("data is not base 64 bytes");
        }
        len = data.length/EXPAND;
        byte[] decodeBytes = new byte[len*BASE];
        int byteLen = 0;
        int decodeIndex = 0;
        byte b1,b2,b3,b4;
        for(int i=0;i<len;i++){
            decodeIndex = i*4;
            b1 = data[decodeIndex];
            b2 = data[decodeIndex+1];
            b3 = data[decodeIndex+2];
            b4 = data[decodeIndex+3];
            if(b3!=END&&b4!=END){
                //无补充符号
                b1 = (byte) str.indexOf(b1);
                b2 = (byte) str.indexOf(b2);
                b3 = (byte) str.indexOf(b3);
                b4 = (byte) str.indexOf(b4);
                decodeBytes[byteLen++] = (byte) (b1<<2|b2>>4);
                decodeBytes[byteLen++] = (byte) (((b2&0xf)<<4)|((b3>>2)&0xf));
                decodeBytes[byteLen++] = (byte) (b3<<6|b4);
            }else if(b3==END){
                b1 = (byte) str.indexOf(b1);
                b2 = (byte) str.indexOf(b2);
                decodeBytes[byteLen++] = (byte) (b1<<2|b2>>4);
            }else if(b4==END){
                b1 = (byte) str.indexOf(b1);
                b2 = (byte) str.indexOf(b2);
                b3 = (byte) str.indexOf(b3);
                decodeBytes[byteLen++] = (byte) (b1<<2|b2>>4);
                decodeBytes[byteLen++] = (byte) (((b2&0xf)<<4)|((b3>>2)&0xf));
            }
        }
        byte[] retBytes = new byte[byteLen];
        System.arraycopy(decodeBytes, 0, retBytes, 0, byteLen);
        return retBytes;
    }

    public static byte[] headAndTailEncodeBase64(String str){
        return headAndTailEncodeBase64(str.getBytes());
    }
    //头尾字节交叉后的编码处理
    public static byte[] headAndTailEncodeBase64(byte[] data){
        int len = data.length;
        if(len==0){
            return new byte[0];
        }
        int half = data.length/2;
        int over = data.length%2;
        byte[] newByte = new byte[len];
        for(int i=0;i<half;){
            newByte[i*2] = data[i];
            newByte[((++i)*2-1)] = data[len-i];
        }
        if(over!=0){
            newByte[len-1] = data[half];
        }
        return encodeBase64(newByte);
    }

    public static byte[] headAndTailDecodeBase64(byte[] data){
        byte[] ret = decodeBase64(data);
        if(ret.length==0){
            return new byte[0];
        }
        int len = ret.length;
        int half = ret.length/2;
        int over = ret.length%2;
        byte[] newByte = new byte[len];
        for(int i=0;i<half;){
            newByte[i] = ret[i*2];
            newByte[len-(++i)] = ret[(i*2-1)];
        }
        if(over!=0){
            newByte[half] = data[len-1];
        }
        return newByte;
    }



    public static String strTo16(String s) {
        String str = "";
        for (int i = 0; i < s.length(); i++) {
            int ch = (int) s.charAt(i);
            String s4 = Integer.toHexString(ch);
            str = str + s4;
        }
        return str;
    }


    public static String str2HexStr(String str) {
        char[] chars = "0123456789abcdef".toCharArray();
        StringBuilder sb = new StringBuilder("");
        byte[] bs = str.getBytes();
        int bit;
        for (int i = 0; i < bs.length; i++) {
            bit = (bs[i] & 0x0f0) >> 4;
            sb.append(chars[bit]);
            bit = bs[i] & 0x0f;
            sb.append(chars[bit]);
            // sb.append(' ');
        }
        return sb.toString();
    }



}

