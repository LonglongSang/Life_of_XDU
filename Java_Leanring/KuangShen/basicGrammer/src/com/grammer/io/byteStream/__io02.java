package com.grammer.io.byteStream;

import java.io.*;

public class __io02 {
    public static void main(String[] args) {
        File file = new File("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\io\\byteStream\\input.txt");
        InputStream input = null;
        try{
            input = new FileInputStream(file);
        }catch(FileNotFoundException e){
            e.printStackTrace();
        }
        int a = 0;
        do{

            try{
                assert input != null;
                a = input.read();
                if(a != -1) System.out.print((char)a);
            }catch (IOException e) {
                e.printStackTrace();
            }
        }while(a != -1);
        try{
            input.close();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
