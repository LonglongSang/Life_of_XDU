package com.grammer.basis._enum;

public class __enum01 {
    private static enum Colors{
        R,G,B;
        Colors(){}
    }
    private static class Cutes{
        public static final Cutes R = new Cutes();
        public static final Cutes G = new Cutes();
        public static final Cutes B = new Cutes();
    }
    private static void test1(){
        Colors c = Colors.R;
        switch(c){
            case R:
                System.out.println("Red");
                break;
            case G:
                System.out.println("Green");
                break;
            case B:
                System.out.println("Blus");
                break;
        }

        /*迭代*/
        for(Colors a: Colors.values()){
            System.out.println(a);
        }

        Colors[] arr = Colors.values();
        for(Colors a: arr){
            System.out.println(a);
        }
    }
    private static void test2(){
        Cutes c = Cutes.G;
        if(c == Cutes.R) {
            System.out.println("Red");
        }else if(c == Cutes.G) {
            System.out.println("Green");
        }else if(c == Cutes.B){
            System.out.println("Blue");
        }
    }
    public static void main(String[] args) {
        /*有没有觉得Colors和Cutes很像，test1和test2很像*/
        test1();
        if(false) test2();
    }
}
