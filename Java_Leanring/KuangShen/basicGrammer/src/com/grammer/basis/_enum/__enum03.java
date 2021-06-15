package com.grammer.basis._enum;

public class __enum03 {
    private static enum Colors{
        //当进程中有使用的Colors时，会进行初始化，分别进行下一行三个枚举类的构造，调用Colors(String name, int index)
        R("Red", 1), G("Green", 2), B("Blue", 3);
        private String name;
        private int index;
        Colors(String name, int index){
            this.name = name;
            this.index = index;
            System.out.println("private constructor running for " + name + " " + index);
        }
        public String getName(){
            return name;
        }
        public int getIndex(){
            return index;
        }
    }

    public static void main(String[] args) {
        System.out.println("Hello world");
        Colors c = Colors.B;
        System.out.println(c.getName() + " " + c.getIndex());
    }
}
