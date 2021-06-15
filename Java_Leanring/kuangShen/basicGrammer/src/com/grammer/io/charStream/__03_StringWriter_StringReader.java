package com.grammer.io.charStream;
/**
 * 测试StringBuffer和StringReader
 */

import java.io.*;

public class __03_StringWriter_StringReader {
    private static final String  str = "李小龙2";
    private static void test() throws IOException {
        Reader a = new StringReader(str);
        char[] arr = new char[1 << 10];
        int val, tot = 0;
        while((val = a.read()) != -1){
            arr[tot++] = (char)val;
            a.reset();//可以看看reset函数和mark函数
            arr[tot++] = (char)a.read();
            a.mark(Integer.MAX_VALUE);
        }
        for(int i = 0; i < tot; i++) System.out.print(arr[i]);
        System.out.println();
        StringWriter w = new StringWriter(1 << 10);
        for(int i = 0; i < tot; i++) w.write(arr[i]);
        String p1 = w.toString();
        StringBuffer p2 = w.getBuffer();
        System.out.println(p1);
        System.out.println(p2);
    }
    public static void main(String[] args) throws IOException {

        test();
    }
}
