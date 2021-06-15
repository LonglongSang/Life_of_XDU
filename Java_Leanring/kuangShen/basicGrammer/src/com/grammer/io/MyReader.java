package com.grammer.io;

import java.io.*;

public class MyReader {
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
    public static void main(String[] args) throws IOException {
        byte[] arr = "3\n123 adakl\n12312 ----_\n121 ----\n".getBytes();
        ByteArrayInputStream b = new ByteArrayInputStream(arr);
        R r = new R(b);
        int n = r.readInt();
        r.readByte();
        for(int i = 0; i < n; i++){
            String str = r.readLine();
            r.readByte();
            System.out.println(str);
        }

    }
}
