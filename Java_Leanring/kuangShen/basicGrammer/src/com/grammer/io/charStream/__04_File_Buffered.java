package com.grammer.io.charStream;
/*
某次输出：
success
Buffered' test, test 134348798 Bytes(128.12499809265137MB), write cost 2413 ms, read cost 2159ms
success
Non-buffered' test, test 134348798 Bytes(128.12499809265137MB), write cost 3077 ms, read cost 1861ms


本次测试主要使用FileReader和FileWriter，以及带缓冲的BufferedWriter和BufferedReader，
从上面输出来看，两者差距并不大，说明FileReader和FileWriter本身底层就已经使用了缓冲区。
对比之前字节流的FileOutputStream和FileInputStream和使用BufferedInputStream和BufferedOutputStream，
两者之间写入\读入相同数据，时间差距是很大的。说明FileOutputStream是不带缓冲区的，我们需要使用Buffered
*/

import java.io.*;

public class __04_File_Buffered {
    private static class Test{
        private File file;
        private int N;
        Test(File file, int N){
            this.file = file;
            try{
                if(!file.exists()) file.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }

            this.N = N;
        }
        private class node{
            public long a;
            public long b;
            public int bytes;
        }
        private node main(Writer w, Reader r){
            node timer = new node();
            timer.a = System.currentTimeMillis();
            char arr[] = {'李', '0'};
            int charCnt = 0;
            int lineSep = 1024;
            try{
                for(int i = 0; i < N; i++){
                    w.write(arr[i % 2]);
                    charCnt++;
                    if(i !=0 && i % lineSep == 0){
                        charCnt++;
                        w.write('\n');
                    }
                }
                w.close();
                timer.a = System.currentTimeMillis() - timer.a;
                timer.b = System.currentTimeMillis();
                int i = 0;
                for(i = 0; i < charCnt && r.read() != -1; i++) {

                }
                timer.bytes = charCnt * 2;
                timer.b = System.currentTimeMillis() - timer.b;
                if(i == charCnt) System.out.println("success");
                else System.out.println("failed");
            } catch (IOException e) {
                e.printStackTrace();
            }
            return timer;
        }
        public void testForNonBuffered(){

            try{
                FileWriter w = new FileWriter(file);
                FileReader r = new FileReader(file);
                node cost = main(w, r);
                System.out.println("Non-buffered' test, test " + cost.bytes + " Bytes(" + ((double)cost.bytes / 1024 / 1024) + "MB), write cost " + cost.a + " ms, read cost " + cost.b + "ms");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        public void testForBuffered(){

            try{
                FileWriter w = new FileWriter(file);
                FileReader r = new FileReader(file);
                BufferedReader bR = new BufferedReader(r, 1 << 26);
                BufferedWriter bW = new BufferedWriter(w, 1 << 26);
                node cost = main(bW, bR);
                System.out.println("Buffered' test, test " + cost.bytes + " Bytes(" + ((double)cost.bytes / 1024 / 1024) + "MB), write cost " + cost.a + " ms, read cost " + cost.b + "ms");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    public static void main(String[] args) {
        //如果路径改变，请将路径改为本文件所在文件夹下的input.txt
        File file = new File("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\io\\charStream\\input.txt");
        Test t = new Test(file, (1 << 20) * (1 << 6));
        t.testForBuffered();
        t.testForNonBuffered();
    }
}

