package com.grammer.io.byteStream;
/*System.in.read*/
import java.io.IOException;

public class __io01 {
    public static void main(String[] args) {
        char arr[] = new char[1 << 32];
        int cnt = 0;
        do{
            try{
                arr[cnt] = (char) System.in.read();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }while(arr[cnt++] != -1);
        cnt--;
        arr[cnt] = 0;
        for(int i = 0; i < cnt; i++) System.out.printf("%s\n", arr);
        //Integer.Ma
    }
}

