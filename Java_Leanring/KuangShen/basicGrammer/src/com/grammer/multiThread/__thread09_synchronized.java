package com.grammer.multiThread;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class __thread09_synchronized {
    private static class Bank implements Runnable{
        public int arr[];
        public Account account;
        Bank(int[] arr, Account account){
            this.arr= arr;
            this.account = account;
        }
        @Override
        public void run()
        {
            if(account == null) return;
            for(int i: arr)
            {
                //System.out.println(i);

                synchronized (account){
                    account.add(i);
                }
            }
        }
    }
    private static class Account{
        public int money = 0;
        public void add(int value)
        {
            money += value;
        }
    }

    public static void main(String[] args)throws InterruptedException {
        Random r = new Random();
        final int N = 100000;
        final int dev = 100;
        int arr1[] = new int[N];
        int arr2[] = new int[N];
        int tot = 0;
        for(int i = 0; i < N; i++){
            arr1[i] = r.nextInt(dev);
            tot += arr1[i];
        }
        for(int i = 0; i < N; i++){
            arr2[i] = r.nextInt(dev);
            tot += arr2[i];
        }
        Account sang = new Account();
        Bank bank1 = new Bank(arr1, sang);
        Bank bank2 = new Bank(arr2, sang);
        Thread t1 = new Thread(bank1, "bank1");
        Thread t2 = new Thread(bank2, "bank2");
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        System.out.println(tot + " " + sang.money);

    }

}
