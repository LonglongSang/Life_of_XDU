package com.grammer.io.byteStream;

/*如何使用ObjectInputStream和ObjectOutputStream*/

import java.io.*;

public class __io04_serializable {

    //需要序列化的类，需要继承Serializable接口
    private static class Student implements Serializable {
        public float gpa;
        public String name;
        Student(String name, float gpa){
            this.name = name;
            this.gpa = gpa;
        }
        @Override
        public String toString(){
            return name + " " + gpa;
        }
    }
    public static void main(String[] args) {
        Student s1 = new Student("LiHua", 3.5f);
        Student s2 = new Student("Xiao Ming", 1.8f);
        File file = new File("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\io\\byteStream\\__io04_serializable.txt");
        if(!file.exists()){
            try{
                file.createNewFile();
            }catch(IOException e){
                e.printStackTrace();
                return;
            }
        }
        ObjectOutputStream oOutput = null;
        ObjectInputStream oInput = null;
        FileOutputStream fOutput = null;
        FileInputStream fInput = null;
        try{
            fOutput = new FileOutputStream(file);
            oOutput = new ObjectOutputStream(fOutput);//ObjectOutputStream(OutputStream o);

            fInput = new FileInputStream(file);
            oInput = new ObjectInputStream(fInput);//ObjectInputStream(InputStream o);

            oOutput.writeObject(s1);//将一个实例写出
            oOutput.writeObject(s2);//将一个实例写出

            Student s3 = null;
            Student s4 = null;

            s3 = (Student)oInput.readObject();//从ObjectInputStream重新读入一个实例
            s4 = (Student)oInput.readObject();//从ObjectInputStream重新读入一个实例
            System.out.println(s3);
            System.out.println(s4);
        }catch(IOException e){
            e.printStackTrace();
        }catch(ClassNotFoundException e){
            e.printStackTrace();
        }finally {


            try{

                oOutput.close();
                fOutput.close();

                oInput.close();
                fInput.close();

            }catch(IOException e){
                e.printStackTrace();
            }
        }
    }
}
