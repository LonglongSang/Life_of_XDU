package com.grammer.io.charStream;

import java.io.CharArrayWriter;

public class __02_CharArrayWriter {
    private static void test(){
        CharArrayWriter charW = new CharArrayWriter();
        String str = "李小龙";
        char arr[] = str.toCharArray();
        for(char i:arr){
            charW.write(i);
            //charW.append(i);也可以
        }
        arr = charW.toCharArray();
        for(char i:arr){
            System.out.print(i);
        }
    }
    public static void main(String[] args) {
        test();
    }
}
