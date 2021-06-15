package com.grammer.io.byteStream;

/*演示如何使用DataInputStream和DataOutputStream和PipeInputStream和PipeOutputSream*/
import java.io.*;

public class __io05_DataInputStream_DataOutputStream {
    private static class Student{
        public String name;
        public float gpa;
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
        PipedOutputStream pOutput = null;
        PipedInputStream pInput = null;
        final int _size = 1 << 14;
        DataInputStream dInput = null;
        DataOutputStream dOutput = null;
        Student arr[] = {
                new Student("Li bai", 1.3f),
                new Student("Sang bai", 123.123f)
        };
        try{
            pInput = new PipedInputStream(_size);
            pOutput = new PipedOutputStream();
            pOutput.connect(pInput);

            dInput = new DataInputStream(pInput);
            dOutput = new DataOutputStream(pOutput);

            {
                int num = arr.length;
                dOutput.writeInt(num);
                for(int i = 0; i < num; i++){
                    dOutput.writeUTF(arr[i].name);
                    dOutput.writeFloat(arr[i].gpa);
                }
                dOutput.flush();
            }

            {
                int num = 0;
                num  = dInput.readInt();
                Student arr1[] = new Student[num];
                for(int i = 0; i < num; i++){
                    arr1[i] = new Student(dInput.readUTF(), dInput.readFloat());
                }
                for(int i = 0; i< num; i++){
                    System.out.println(arr1[i]);
                }
            }



        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            try{
                pInput.close();
                pOutput.close();
                dInput.close();
                dOutput.close();
            }catch(IOException e){
                e.printStackTrace();
            }
        }
    }
}
