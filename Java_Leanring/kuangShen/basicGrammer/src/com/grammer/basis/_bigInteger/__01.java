package com.grammer.basis._bigInteger;

import java.math.BigInteger;
import java.util.Random;

public class __01 {
    private static class Test{
        public void main(){
            int n = 10;
            int[] arr = new int[n];
            Random r = new Random();
            for(int i = 0; i < n; i++){
                arr[i] = r.nextInt(10);
                System.out.print(arr[i]);
            }
            System.out.println();
            BigInteger a = new BigInteger("13123123");
            System.out.println(a);
        }
    }
    public static void main(String[] args) {
        (new Test()).main();
    }
}
