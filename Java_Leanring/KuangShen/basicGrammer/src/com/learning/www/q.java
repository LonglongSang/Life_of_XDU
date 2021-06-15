package com.learning.www;
import java.util.*;
import java.lang.*;
class Note<T>
{
    public T value;
    private Map<Integer,T> dp = new TreeMap<>();
    private int cnt;
    private int valid;
    private final int N = 10000;
    private int mapping[] = new int[N];

    Note()
    {
        this.cnt = 0;
        this.valid = 0;
    }
    void add(T value)
    {
        this.valid++;
        dp.put(this.cnt++, value);
    }
    T remove(int key)
    {
        System.out.println("This ---" + mapping[key]);
        T ret = dp.get(mapping[key]);
        dp.remove(mapping[key]);
        if(ret != null) this.valid--;
        return ret;
    }
    void print()
    {
        System.out.println("--------------Note Infor--------------");
        System.out.println("Total quantity:" + this.valid);
        System.out.println("---------------Content Begin---------------");
        Iterator<Map.Entry<Integer,T>> it = dp.entrySet().iterator();
        Map.Entry<Integer, T> cur;
        int nowCnt = 0;
        for(; it.hasNext();)
        {
            cur = it.next();
            System.out.print("Line " + nowCnt+ " [");
            this.mapping[nowCnt++] = cur.getKey();
            System.out.println(cur.getValue() + "]");
        }
        System.out.println("---------------Content End---------------");
    }
    void clear()
    {
        this.cnt = 0;
        this.valid = 0;
        dp.clear();
    }
    void input()
    {

    }
}
public class q {
    public static void run()
    {
        Note<String> myNote = new Note<>();
        Scanner sc = new Scanner(System.in);
        int typ;
        while(true)
        {
            //清屏命令

            myNote.print();
            System.out.println("1 for add");
            System.out.println("2 for remove");
            System.out.println("3 for remove all");
            System.out.println("4 for quit");
            typ = sc.nextInt();
            if(typ == 1)
            {
                System.out.println("add");
                sc.nextLine();
                String a = sc.nextLine();
                myNote.add(a);
            }else if(typ == 2)
            {
                System.out.println("remove");
                myNote.remove(sc.nextInt());
            }else if(typ == 3)
            {
                myNote.clear();
            }else if(typ == 4)
            {
                System.out.println("break");
                break;
            }else
            {
                System.out.println(" not good");
            }
        }

    }
    public static void main(String[] args) {

        run();
    }
}
