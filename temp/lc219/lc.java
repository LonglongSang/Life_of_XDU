

import java.io.*;
import java.util.Scanner;

public class lc {
    interface B{
        char get(int a);
    }
    public static void main(String[] args) throws IOException {
        String a = "1上";

        File file = new File("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\io\\input.txt");
        B getChar = (int _value)->{
            if(_value < 10) return (char)(_value + '0');
            else return (char)(_value - 10 + 'a');
        };

        char arr[] = a.toCharArray();
        byte arr1[] = {(byte)0b11111100, (byte)0b10000001, (byte)0b10000000, (byte)0b10000000, (byte)0b10000001, (byte)0b10000001};
        String k = new String(arr1, "UTF-8");
        System.out.println("#" + k + "#");
        for(int i = 0; i < arr.length; i++){
            //System.out.println(arr[i]);
            System.out.print(getChar.get((int)((arr[i] >> 12) & 0x000f)));
            System.out.print(getChar.get((int)((arr[i] >> 8) & 0x000f)));
            System.out.print(getChar.get((int)((arr[i] >> 4) & 0x000f)));
            System.out.print(getChar.get((int)((arr[i] >> 0) & 0x000f)));
            System.out.print("\n");
        }





    }
}
