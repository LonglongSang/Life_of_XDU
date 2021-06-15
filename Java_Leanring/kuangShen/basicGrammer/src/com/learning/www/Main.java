package com.learning.www;

import java.io.*;
import java.util.*;

public class Main {

    private static class R{
        BufferedInputStream buffered;
        PushbackInputStream pushBack;
        static int defaultBufferSize = 1 << 12;
        R(InputStream i){
            this(i, defaultBufferSize);
        }
        R(InputStream i, int _size){
            buffered = new BufferedInputStream(i, _size);
            pushBack = new PushbackInputStream(buffered, 1 << 10);
        }
        byte[] arr = new byte[1 << 10];
        int cnt;
        String readLine(){
            int val;
            cnt = 0;
            try{
                while((val = pushBack.read()) != -1){
                    if(val == '\n'){
                        pushBack.unread(val);
                        break;
                    }
                    arr[cnt++] = (byte)val;
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return new String(arr, 0, cnt);
        }
        private void forward(){
            cnt = 0;
            int val;
            try{
                while((val = pushBack.read()) != -1){
                    if(val == ' ' || val == '\n' || val == 'r' || val == '\t'){
                        pushBack.unread(val);
                        break;
                    }
                    arr[cnt++] = (byte)val;
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        long readLong(){
            forward();
            long ans = 0;
            for(int i = 0; i < cnt; i++) ans = ans * 10 + arr[i] - '0';
            return ans;
        }
        int readInt(){
            forward();
            int ans = 0;
            for(int i = 0; i < cnt; i++) ans = ans * 10 + arr[i] - '0';
            return ans;
        }
        float readFloat(){
            forward();
            return Float.valueOf(new String(arr, 0, cnt));
        }
        double readDouble(){
            forward();
            return Double.valueOf(new String(arr, 0, cnt));
        }
        String readString(){
            forward();
            return new String(arr, 0, cnt);
        }
        Byte readByte(){
            try{
                return (byte)pushBack.read();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return -1;
        }
    }


    private static class Solution{
        private class node{
            node(String name){
                for(int i = 0; i < 3; i++) arr[i] = -100;
                this.name = name;
            }
            public String name;
            public int[] arr = new int[3];
            int g;
        }
        static int p, m, n, cnt;
        static node ans[] = new node[100005];
        int getGrade(node cur){
            if(cur == null) return 0;
            return cur.arr[2] > cur.arr[1] ? cur.arr[2] :(int)( 0.4 * cur.arr[1] + 0.6 * cur.arr[2]);
        }
        boolean check(node cur){
            return cur != null && cur.arr[0] >= 200 && getGrade(cur) >= 60;
        }
        void run(HashMap<String, node> mp, R r, int t, int index){
            node cur = null;

            String name;
            int g;
            for(int i = 0; i < t; i++){
                name = r.readString();
                r.readByte();
                g = r.readInt();
                r.readByte();
                cur = mp.get(name);
                if(cur == null){
                    cur = new node(name);
                }
                cur.arr[index] = g;
                if(check(cur)){
                    ans[cnt++] = cur;
                    cur.g = getGrade(cur);
                }
            }
        }
        public void main(){
            cnt = 0;
            R r = new R(System.in, 1 << 20);
            p = r.readInt();
            r.readByte();
            m = r.readInt();
            r.readByte();
            n = r.readInt();
            r.readByte();
            System.out.println(p + " " + m + " " + n);
            HashMap<String, node> mp = new HashMap<>();
            run(mp, r, p, 0);
            run(mp, r, m, 1);
            run(mp, r, n, 2);
            if(true) return;
            Arrays.sort(ans, 0, cnt, (o1, o2)->{
               if(o1.g != o2.g) return o2.g - o1.g;
               else return o1.name.compareTo(o2.name);
            });
            for(int i = 0; i < cnt; i++){
                //System.out.format("%s %d %d %d %d\n", ans[i].name, ans[i].arr[0], ans[i].arr[1] == -100 ? -1: ans[i].arr[1], ans[i].arr[2], ans[i].g);
            }
        }
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        s.main();
    }
}
