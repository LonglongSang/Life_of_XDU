package com.grammer.io.byteStream;

/*实现一个简单的文件拷贝*/
import java.io.*;

public class __io03_copyFile {
    public static void main(String[] args) {
        //oriFile为要拷贝的文件，copyFile为要拷贝到的文件
        File oriFile = new File("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\io\\byteStream\\__io03_ori.txt");
        File copyFile = new File("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\io\\byteStream\\__io03_copy.txt");
        InputStream input = null;
        OutputStream output = null;
        if(!oriFile.exists()){
            System.err.println(oriFile.getAbsolutePath() + " is not exists");
            return;
        }
        if(!copyFile.exists()){
            try{
                copyFile.createNewFile();
                System.out.println(copyFile.getAbsolutePath() + " not exists, create it");
            }catch(IOException e){
                e.printStackTrace();
            }finally{

            }
        }
        try{
            input = new FileInputStream(oriFile);
            output = new FileOutputStream(copyFile);
            byte[] arr = new byte[1 << 10];
            int limit = arr.length;
            int len = 0;
            while((len = input.read(arr, 0, limit)) != -1){
                System.out.println("copied " + len + " bytes");
                output.write(arr, 0, len);
            }
            input.close();
            output.close();
            System.out.println("copy from " + oriFile.getName() + " to " + copyFile.getName() + " success");
        }catch(IOException e){
            e.printStackTrace();
        }finally{

        }
    }
}
