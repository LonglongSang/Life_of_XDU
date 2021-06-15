package com.grammer.io.charStream;
/**
 * 测试字节流和字符流的区别
 * 利用CharArrayReader来测试
 *
 */

/**
 * String str = "立白001"
 *
 * 输出：
 * -------Char Stream------
 * Char array length: 5
 * 立
 * 白
 * 0
 * 0
 * 1
 * -------Byte Stream------
 * Byte array length: 9
 * -25
 * -85
 * -117
 * -25
 * -103
 * -67
 * 48
 * 48
 * 49
 *
 *
 * 解释：Char Stream输出5个字符，和String str的长度一样
 * Byte Stream输出9个字符，前两个中文字符转化为utf-8字符占用3个字节，001各占用一个字符
 */

import java.io.ByteArrayInputStream;
import java.io.CharArrayReader;
import java.io.IOException;

public class __01_CharArrayReader {
    static String str = new String("立白001");

    private static void testForCharStream(){
        System.out.println("-------Char Stream------");
        char arr[] = str.toCharArray();
        System.out.println("Char array length: " + arr.length);
        CharArrayReader charR = new CharArrayReader(arr);
        int val;
        try{
            while((val = charR.read()) != -1){
                System.out.println((char)val);
            }
            charR.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    private static void testForByteStream(){
        System.out.println("-------Byte Stream------");
        byte arr[] = str.getBytes();
        ByteArrayInputStream byteIn = new ByteArrayInputStream(arr);
        System.out.println("Byte array length: " + arr.length);
        try{
            int val;
            while((val = byteIn.read()) != -1){
                System.out.println((byte)val);
            }
            byteIn.close();
        }catch (IOException e){
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        testForCharStream();
        testForByteStream();

    }
}
