//package com.grammer.io.file;
import java.io.*;
import java.util.HashSet;
class CountLine{
    CountLine(){
        this.sub = null;
        this.out = null;
    }
    private HashSet<String> sub;
    private PrintStream out;
    private void init(String[] sub){
        //利用sub初始化HashSet
        this.sub = new HashSet<>();
        for(String q:sub){
            this.sub.add(q);
        }
    }
    public long main(String filePath, String outputFilePath, String[] sub){
        //统计filePath目录/文件中后缀为sub[i]的所有文件的函数，并将结果输出到outPutFilePath
        File outputFile = new File(outputFilePath);
        long ans = main(new File(filePath), outputFile, sub);
        return ans;
    }
    public long main(File file, File outputFile, String[] sub){
        long ans = 0;
        try{
            init(sub);
            if(!outputFile.exists()){
                outputFile.createNewFile();
            }
            if(!outputFile.canWrite()) throw new Exception("outPut file: " + outputFile.getAbsolutePath() + " can not write");
            FileOutputStream fOut = new FileOutputStream(outputFile, true);
            BufferedOutputStream buffered = new BufferedOutputStream(fOut, 1 << 20);
            this.out = new PrintStream(buffered);
            ans = help(file);
            this.out.close();
            buffered.close();
            fOut.close();
        }catch(IOException e){
            e.printStackTrace();
        }catch (Exception e1){
            e1.printStackTrace();
        }finally {
            this.sub = null;
            this.out = null;
        }
        return ans;
    }
    private boolean existInSubfix(File file){
        //判断文件file的后缀名是否存在于this.sub中
        if(file == null || file.isDirectory()) return false;
        String name = file.getName();
        int lastDot = name.lastIndexOf('.');
        if(lastDot == -1) return false;
        String subFIX = name.substring(lastDot + 1);
        return this.sub.contains(subFIX);
    }
    private int help(File file){
        //递归计算file有多少行
        if(file == null) return 0;
        if(file.isFile()){
            //文件
            if(existInSubfix(file)) return countLine(file);
            else return 0;
        }else{
            //文件夹
            File[] arr = file.listFiles();
            int tot = 0;
            for(File i: arr){
                tot +=help(i);
            }
            this.out.println("Dir " + file.getAbsolutePath() + " line: " + tot);
            return tot;
        }
    }
    private int countLine(File file){
        //计算文件file有多少行
        if(file == null || !file.exists() || !file.isFile() || !file.canRead()) return 0;
        int val = 0;
        int cnt = 0;
        try{
            FileInputStream fInput = new FileInputStream(file);
            BufferedInputStream buffered = new BufferedInputStream(fInput, 1 << 20);
            while((val = buffered.read()) != -1){
                if(val == '\n') cnt++;
            }
            buffered.close();
            fInput.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
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



        //你想统计的文件的后缀名
        String[] arr = {"cpp", "c", "java"};
        //你想统计的文件夹或者文件的绝对地址
        File file = new File("G:\\Life_of_XDU");
        //存放输出结果的文件的绝对地址
        File outPut = new File("G:\\outPut.txt");




        long ans = c.main(file, outPut, arr);
    }
}
