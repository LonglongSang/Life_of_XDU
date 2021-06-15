package com.grammer.io.byteStream;

/**
 * 本文件主要测试SequenceInputStream的功能，同时也和其他类型的InputStream和OutputStream组合使用
 */

import java.io.*;
import java.util.Enumeration;
import java.util.Random;
import java.util.Vector;

public class __io07_SequenceInputStream {
    private static class Test{
        private static final int size = 1 << 20;
        private static final String str = "abcdef三";
        private static final int n = 1 << 15;
        Test(){}

        //获得DataOutputStream类型的输出的数据，将其存储在一个byte[]
        //数据类型一个int数据n表示有多少数据，每一个数据由一个int组成和一个String类型组成
        public byte preparation()[]{
            /**
             * 采用3层嵌套，由底层到高层分别为:
             * low  level: ByteArrayOutputStream
             * mid level: BufferedOutputStream
             * high level: DataOutputStream
             *
             * 最底层的ByteArrayOutputStream也可以更改为FileOutputStream
             * 中间层的BufferedOutputStream最为缓存层存在
             */
            ByteArrayOutputStream byteOut;
            BufferedOutputStream bufferedOut;
            DataOutputStream dataOut;
            byte ans[] = null;
            try{
                byteOut = new ByteArrayOutputStream(size);
                bufferedOut = new BufferedOutputStream(byteOut);
                dataOut = new DataOutputStream(bufferedOut);
                dataOut.writeInt(n);
                for(int i = 0; i < n; i++){
                    dataOut.writeInt(i);
                    dataOut.writeUTF(str);
                }
                System.out.println("-----preparation------");
                System.out.println("generate " + this.n + " elements, totally size(bytes): " + dataOut.size());
                dataOut.close();
                bufferedOut.close();
                ans = byteOut.toByteArray();
                byteOut.close();
            }catch (IOException e){
                e.printStackTrace();
            }
            return ans;
        }
        public Enumeration<InputStream> getInputStream(byte[] arr, int groupNum){
            if(arr == null) return null;
            if(arr.length < groupNum) groupNum = arr.length;
            int last = 0, len = arr.length, num;
            Vector<InputStream> tempArr = new Vector<>();
            for(int i = 0; i < groupNum; i++){
                num = len / groupNum + (i < len % groupNum ? 1 : 0);
                byte[] _ = new byte[num];
                for(int j = 0; j < num; j++) _[j] = arr[j + last];
                ByteArrayInputStream in = new ByteArrayInputStream(_);
                tempArr.add(in);
                last += num;

            }
            return tempArr.elements();
        }
        public void run(){

            /**
             * 本处同样采用4层结构，由低到高分别为
             * 1 level: ByteArrayInputStream(InputStream)
             * 2 level: SequenceInputStream
             * 3 level: BufferedInputStream
             * 4 level: DataInputStream
             *
             * 第一层最为最底层，通用也可以采用FileInputStream
             * 第二层SequenceInputStream可以整合多个第一层的InputStream作为一个序列流
             * 第三层BufferedInputStream作为缓存层
             * 第四层为读取数据的层次
             */
            byte[] charArr = preparation();
            int groupNum = 20;
            Enumeration<InputStream> inputStreamArr = getInputStream(charArr, groupNum);
            SequenceInputStream sequenceIn = new SequenceInputStream(inputStreamArr);
            BufferedInputStream bufferedInput = new BufferedInputStream(sequenceIn);
            DataInputStream dataIn = new DataInputStream(bufferedInput);
            Random r = new Random();
            try{
                System.out.println("--------run---------");
                int n = dataIn.readInt();
                System.out.println("read " + n + "elements:");
                int val;
                String str;
                for(int i = 0; i < n; i++){
                    val = dataIn.readInt();
                    str = dataIn.readUTF();
                    if(r.nextInt(100) == 20) System.out.println(val + " " + str);//保持输出1%的元素最为参考
                }
            }catch (IOException e){
                e.printStackTrace();
            }
        }
    }
    public static void main(String[] args) {

        Test t = new Test();
        t.run();

    }
}
