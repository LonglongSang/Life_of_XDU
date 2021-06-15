package com.grammer.lambda;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;

public class __lambda02 {
    public static void main(String[] args) {
        final int N = 10;
        final int dev = 100;
        Random r = new Random();
        Integer arr[] = new Integer[N];
        for(int i = 0; i < N; i++)
        {
            arr[i] = r.nextInt(dev);
        }
        Comparator<Integer> cmp = new Comparator<Integer>(){
            @Override
            public int compare(Integer a, Integer b){
                return a.compareTo(b);
            }
        };
        Arrays.sort(arr, 0, 10, new Comparator<Integer>(){
            @Override
            public int compare(Integer a, Integer b){
                return a.compareTo(b);
            }
        });
        Arrays.sort(arr, (x, y)->{
            return x.compareTo(y);
        });
    }
}
