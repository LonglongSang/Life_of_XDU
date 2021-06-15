package com.grammer.lintCode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.TreeSet;

public class BankSystem {

    private class Node{
        long timeStamp;
        int money;
        Node(long t, int m){
            timeStamp = t;
            money = m;
        }
    }
    public HashMap<Integer, ArrayList<Node>> dp = new HashMap<>();
    public BankSystem(){
        // Write your code here

    }
    /**
     * @param id: user account id
     * @param amount: the number of bank deposits
     * @param timestamp: the data of bank transaction
     * @return: nothing
     */
    public void deposite(int id, int amount, long timestamp) {
        // Write your code here
        ArrayList<Node> arr = dp.get(id);
        if(arr == null){
            arr = new ArrayList<>();
            dp.put(id, arr);
        }
        Node last = arr.size() > 0 ? arr.get(arr.size() - 1) : null;
        if(last != null){
            arr.add(new Node(timestamp, last.money + amount));
        }else{
            arr.add(new Node(timestamp, amount));
        }
    }

    /**
     * @param id: user account id
     * @param amount : the number of bank withdraw
     * @param timestamp: the data of bank transaction
     * @return: if user account can not withdraw the number of amount,return false. else return true
     */
    public boolean withdraw(int id, int amount , long timestamp) {
        //
        ArrayList<Node> arr = dp.get(id);
        Node last = null;
        if(arr != null && arr.size() != 0) last = arr.get(arr.size() - 1);
        if(last != null && last.money >= amount){
            arr.add(new Node(timestamp, last.money - amount));
            return true;
        }
        return false;

    }

    /**
     * @param id: user account id
     * @param startTime: start time
     * @param endTime: end time
     * @return: need return two numbers,the first one is start time account balance,the second is end time account balance
     */
    public int getAns(ArrayList<Node> arr, long stamp){
        int low = 0, high = arr.size() - 1;
        int mid, ans = -1;
        while(high >= low){
            mid = (low + high) / 2;
            if(arr.get(mid).timeStamp >stamp){
                high = mid - 1;
            }else{
                low = mid + 1;
                ans = mid;
            }
        }
        return ans == -1 ? 0 : arr.get(ans).money;
    }
    public int[] check(int id, long startTime, long endTime) {
        //
        ArrayList<Node> arr = dp.get(id);
        if(arr == null) return new int[0];
        int ans[] = new int[2];
        ans[0] = getAns(arr, startTime);
        ans[1] = getAns(arr, endTime);
        return ans;
    }
}