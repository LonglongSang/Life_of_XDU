package com.grammer.io.file;
/*
  这个类可以统计一个文件夹/文件中目标后缀名的行数
  如何使用: 将本文件命名为__02.java，并调整第165,167,169行数据即可
  编译命令：javac -encoding utf-8 __02.java && java __02
 */
import java.io.*;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

class CountLine{
    private static class node{
        node(String sub){
            this.sub = sub;
            totLine = 0;
            maxCnt = 0;
            minCnt = 0x7fffffff;
            fileCnt = 0;
        }
        public String sub;//后缀名
        public int totLine;//统计后缀为sub的文件总共有多少行
        public int maxCnt;//后缀为sub的文件中，最多的行数
        public int minCnt;//后缀为sub的文件，最少的行数
        public int fileCnt;//后缀为sub的文件的数目
    }
    private interface Lambda{
        void func(PrintStream out);
    }
    CountLine(){
        this.mp = null;
        this.out = null;
    }
    private HashMap<String, node> mp;
    private PrintStream out;
    private File targetFile;
    private File outputFile;
    private void init(String[] sub){
        //利用sub初始化HashMap(this.mp)
        this.mp = new HashMap<>();
        for(String q:sub){
            this.mp.put(q, new node(q));
        }
    }
    public int main(String filePath, String outputFilePath, String[] sub){
        //统计filePath目录/文件中后缀为sub[i]的所有文件的函数，并将结果输出到outPutFilePath
        File outputFile = new File(outputFilePath);
        return main(new File(filePath), outputFile, sub);
    }
    private void printReport(int tot){
        Lambda func = (out)->{
            out.format("\n\n\n\n--------Report for dir/file: %s-------\n\n", this.targetFile.getAbsoluteFile());
            out.format("\t\tReport write into: %s\n\n", this.outputFile.getAbsoluteFile());
            out.format("\t\ttotal Line for suffix:");
            Iterator<Map.Entry<String, node>> it;
            node cur;
            for(it = this.mp.entrySet().iterator(); it.hasNext();){
                out.format(" %s", it.next().getKey());
            }
            out.format(" is %d\n\n\n\n", tot);
            for(it = this.mp.entrySet().iterator(); it.hasNext();){
                cur = it.next().getValue();
                out.format("---------*.%s---------\n", cur.sub);
                out.format("\t*.%s's file number: %d\n", cur.sub, cur.fileCnt);
                out.format("\t*.%s's file total line: %d\n", cur.sub, cur.totLine);
                out.format("\t*.%s's max Line in file: %d line\n", cur.sub, cur.maxCnt);
                out.format("\t*.%s's min Line in file: %d line\n\n", cur.sub, cur.minCnt == 0x7fffffff ? 0 : cur.minCnt);
            }
        };
        func.func(this.out);
        func.func(System.out);
    }
    public int main(File file, File outputFile, String[] sub){
        this.targetFile = file;
        this.outputFile = outputFile;
        int ans = 0;
        try{
            init(sub);
            if(!outputFile.exists()){
                if(!outputFile.createNewFile()) throw new Exception("create output file failed");
            }
            if(!outputFile.canWrite()) throw new Exception("outPut file: " + outputFile.getAbsolutePath() + " can not write");
            FileOutputStream fOut = new FileOutputStream(outputFile, true);
            BufferedOutputStream buffered = new BufferedOutputStream(fOut, 1 << 20);
            this.out = new PrintStream(buffered);
            ans = help(file);
            printReport(ans);
            this.out.close();
            buffered.close();
            fOut.close();
        } catch(Exception e){
            e.printStackTrace();
        } finally {
            this.mp = null;
            this.out = null;
        }
        return ans;
    }
    private node existInSuffix(File file){
        //判断文件file的后缀名是否存在于this.sub中,如果不存在返回null，如果是返回非null
        if(file == null || file.isDirectory()) return null;
        String name = file.getName();
        int lastDot = name.lastIndexOf('.');
        if(lastDot == -1) return null;
        String subFIX = name.substring(lastDot + 1);
        return this.mp.get(subFIX);
    }
    private int help(File file){
        //递归计算file有多少行
        if(file == null) return 0;
        if(file.isFile()){
            //文件
            node cur;
            if((cur = existInSuffix(file)) != null){
                int temp = countLine(file);
                cur.totLine += temp;
                cur.minCnt = Math.min(cur.minCnt, temp);
                cur.maxCnt = Math.max(cur.maxCnt, temp);
                cur.fileCnt++;
                return temp;
            }else{
                return 0;
            }
        }else{
            //文件夹
            File[] arr = file.listFiles();
            int tot = 0;
            if(arr != null){
                for(File i: arr){
                    tot +=help(i);
                }
            }

            this.out.println("Dir " + file.getAbsolutePath() + " line: " + tot);
            return tot;
        }
    }
    private int countLine(File file){
        //计算文件file有多少行
        if(file == null || !file.exists() || !file.isFile() || !file.canRead()) return 0;
        int val;
        int cnt = 0;
        try{
            FileInputStream fInput = new FileInputStream(file);
            BufferedInputStream buffered = new BufferedInputStream(fInput, 1 << 20);
            while((val = buffered.read()) != -1){
                if(val == '\n') cnt++;
            }
            buffered.close();
            fInput.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        this.out.println("File: " + file.getAbsolutePath() + " line: " + cnt);
        return cnt;
    }
}
public class __02 {
    public static void main(String[] args) {
        CountLine c = new CountLine();



        //你想统计的文件的后缀名，该实例会统计以下四种后缀名
        String[] arr = {"cpp", "c", "java", "py"};
        //你想统计的文件夹或者文件的绝对地址，示例的文件夹地址为G:\Life_of_XDU
        File file = new File("G:\\Life_of_XDU");
        //存放输出结果的文件的绝对地址，示例的输出文件为G:\outPut.txt
        File outPut = new File("G:\\outPut.txt");




        c.main(file, outPut, arr);
    }
}
