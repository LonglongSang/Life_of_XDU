package com.learning.www;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class io {
    private static class Counter{
        public class Node{
            public String value;
            public int cnt;
            Node(String value){
                this.value = value;
                cnt = 0;
            }
        }
        public File file;
        private HashMap<String, Node> cnt;
        Counter(File file){
            this.file = file;
            cnt = new HashMap<>();
        }
        Counter(){
            this(null);
        }
        private void clear(){
            cnt.clear();
        }
        public void setFile(File file){
            //重设需要统计的文件
            this.file = file;
            clear();
        }
        private void add(String s){
            //将字符串s加入到this.cnt中
            Node value = cnt.get(s);
            if(value == null){
                value = new Node(s);
                cnt.put(s, value);
            }
            value.cnt++;
        }
        private interface Lam{
            boolean ok(String s, char[] sign, boolean [] have);
        }
        private void process(String s){
            add(s);
            //static char sign[] = {',', '.'};
            //static boolean have[] = new boolean[sign.length];
            //static Lam haveComma =
        }
        public void run() throws FileNotFoundException {
            if(file == null) return;
            Scanner sc = new Scanner(file);
            char arr[] = new char[1000];
            while(sc.hasNext()){
                String cur = sc.next();
                process(cur);
            }
        }

        public Node[] getResult(){
            //获取结果
            System.out.println(cnt.size());
            Node[] result = new Node[cnt.size()];
            Map.Entry<String, Node> cur;
            int index = 0;
            for(Iterator<Map.Entry<String, Node>> it = cnt.entrySet().iterator(); it.hasNext();){
                cur = it.next();
                result[index++] = cur.getValue();
            }
            return result;
        }





    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("please input file, 1 for leave");
            String filePath = sc.nextLine();
            if(filePath.equals("1")) break;
            filePath = "G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\learning\\www\\input.txt";
            File file = new File(filePath);
            Counter c = new Counter(file);
            System.out.println("hello world");
            c.run();
            Counter.Node [] result = c.getResult();
            for(Counter.Node cur: result){
                System.out.println(cur.value + " " + cur.cnt);
            }
        }


    }
}
