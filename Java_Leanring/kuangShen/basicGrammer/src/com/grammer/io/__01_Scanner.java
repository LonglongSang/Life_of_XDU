package com.grammer.io;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class __01_Scanner {


    private static void test(){
        File file = new File("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\io\\input.txt");
        InputStream input;
        Scanner sc = null;
        try{
             input = new FileInputStream(file);
             sc = new Scanner(input);
            while(sc.hasNextByte()){
                System.out.println(sc.nextByte());
            }
            if(sc.hasNextBigInteger()) System.out.println("true");
        }catch (IOException e){
            e.printStackTrace();
        }


        if(true) return;
        try{
            int a = sc.nextInt();
            byte q;
            if(sc.hasNextByte()){
                System.out.println("true");
            }
            if(true) return;
            float b = sc.nextFloat();
            sc.nextByte();
            //System.in.read();
            String s1 = sc.next();
            sc.nextByte();
            String s2 = sc.next();
            //System.in.read();
            sc.nextByte();
            String s3 = sc.nextLine();
            System.out.println(a + " " + b);
            System.out.println(s1 + " " + s2);
            System.out.println(s3);
        }finally {

        }

    }
    public static void main(String[] args) {
        test();

    }
}
