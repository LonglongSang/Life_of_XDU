package com.grammer.io.byteStream;
import java.io.*;

/*
测试BufferedInputStream和BufferOutputStream向文件输出的效果
与之对比的是FileInputStream和FileOutputStream的效果
 */

/*
某一次的输出如下：
1621942213537 1621942213890
1621942213890 1621942214286
Total test: 16777216Bytes write and read
write: 353ms
read: 396ms
1621942214289 1621942253398
1621942253398 1621942282506
Total test: 16777216Bytes write and read
write: 39109ms
read: 29108ms
 */


public class __io06_BufferedInputStream {
    private static class Test{
        public InputStream in;
        public OutputStream out;
        public static final int N = (1 << 20) * (1 << 7);//128MB
        Test(InputStream in, OutputStream out){
            this.in = in;
            this.out = out;
        }
        public void reset(InputStream in, OutputStream out){
            this.in = in;
            this.out = out;
        }
        public long write(){
            long beginTime = System.currentTimeMillis();
            try{
                for(int i = 0; i < N; i++){
                    out.write('a');
                }
                out.flush();
            }catch(IOException e){
                e.printStackTrace();
            }
            long endTime = System.currentTimeMillis();
            //System.out.println(beginTime + " " + endTime);
            return endTime - beginTime;
        }
        public long read() {
            long beginTime = System.currentTimeMillis();
            int val;
            try {
                for (int i = 0; i < N; i++) {
                    val = in.read();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            long endTime = System.currentTimeMillis();
            //System.out.println(beginTime + " " + endTime);
            return endTime - beginTime;
        }
        public long run(){
            if(in == null || out == null){
                return 0L;
            }

            long _a = write();
            long _b = read();
            System.out.println("Total test: " + N + " Bytes, " + (N >> 20) + " MB write and read");
            System.out.println("write: " + _a + " ms");
            System.out.println("read: " + _b + " ms");
            System.out.println();
            return _a + _b;
        }
    }
    private static void testForBuffered(String filePath, int bufferSize){
        FileOutputStream fOut = null;
        FileInputStream fIn = null;

        BufferedOutputStream bOut = null;
        BufferedInputStream bIn = null;
        try{
            fOut = new FileOutputStream(filePath);
            fIn = new FileInputStream(filePath);

            bOut = new BufferedOutputStream(fOut, bufferSize);
            bIn = new BufferedInputStream(fIn, bufferSize);

            Test t = new Test(bIn, bOut);
            t.run();

        }catch(IOException e){
            e.printStackTrace();
        }finally {
            try{
                fIn.close();
                fOut.close();
                bIn.close();
                bOut.close();
            }catch (IOException e){
                e.printStackTrace();
            }
        }

    }
    private static void testForNonBuffered(String filePath){
        FileOutputStream fOut = null;
        FileInputStream fIn = null;
        try{
            fOut = new FileOutputStream(filePath);
            fIn = new FileInputStream(filePath);

            Test t = new Test(fIn, fOut);
            t.run();

        }catch(IOException e){
            e.printStackTrace();
        }finally {
            try{
                fIn.close();
                fOut.close();
            }catch (IOException e){
                e.printStackTrace();
            }
        }

    }
    public static void main(String[] args) throws IOException {
        int bufferSize = 1 << 20;
        String filePath = "G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\io\\input.txt";
        testForBuffered(filePath, bufferSize);
        //testForNonBuffered(filePath);

    }
}
