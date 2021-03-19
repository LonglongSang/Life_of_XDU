package java.com.hackerrank.www;
/**
 * https://www.hackerrank.com/challenges/java-datatypes/problem
 */

import java.util.*;
import java.io.*;



class javaDatatypes{
    public static void main(String []argh)
    {



        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        long a=(long)0x7fff;
        long b=(long)0x7fffffff;
        long c=0x7fffffffffffffffL;
        for(int i=0;i<t;i++)
        {

            try
            {
                long x=sc.nextLong();
                System.out.println(x+" can be fitted in:");
                if(x>=-128 && x<=127)System.out.println("* byte");
                if(x>=-a-1 && x<=a) System.out.println("* short");
                if(x>=-b-1 && x<=b) System.out.println("* int");
                if(x>=-c-1 && x<=c) System.out.println("* long");
                //Complete the code
            }
            catch(Exception e)
            {
                System.out.println(sc.next()+" can't be fitted anywhere.");
            }

        }
    }
}



