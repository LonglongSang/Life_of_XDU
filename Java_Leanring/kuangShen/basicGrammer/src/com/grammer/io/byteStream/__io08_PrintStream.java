package com.grammer.io.byteStream;

/**
 * 本文件用来测试PrintStream
 */

import java.io.*;

public class __io08_PrintStream {
    private static class Test{
        public void testFor(){
            //PrintStream,底层有一个BufferedWriter a和一个OutputStreamWriter b，PrintStream利用a作为缓存层，利用b作为最终输出的层
            OutputStream stdout = new FileOutputStream(FileDescriptor.out);//FileDescriptor.out是stdout的文件描述符，创建一个文件输出流
            PrintStream p = new PrintStream(stdout, true);
            p.println("12 " + 12);
            String str = "李小龙";
            p.format("%s %d\n", str, 12129);
            //System.out就是一个PrintStream，所以p的用法和System.out一致
        }
    }
    public static void main(String[] args) {
        Test t = new Test();
        t.testFor();
    }
}
