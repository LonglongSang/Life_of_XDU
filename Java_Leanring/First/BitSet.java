//https://www.hackerrank.com/challenges/java-bitset/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BitSet [] b = new BitSet[2];

        Scanner sc = new Scanner(System.in);
        int n, q;
        n = sc.nextInt();
        q = sc.nextInt();
        b[0] = new BitSet(n);
        b[1] = new BitSet(n);
        int x, y;
        while(q-- > 0)
        {
            String typ = sc.next();
            x = sc.nextInt();
            y = sc.nextInt();
            if(typ.compareTo("XOR") == 0)
            {
                b[--x].xor(b[--y]);
            }else if(typ.compareTo("AND") == 0)
            {
                b[--x].and(b[--y]);
            }else if(typ.compareTo("OR") == 0)
            {
                b[--x].or(b[--y]);
            }else if(typ.compareTo("SET") == 0)
            {
                b[--x].set(y);
            }else
            {
                b[--x].flip(y);
            }
            System.out.println(b[0].cardinality() + " " + b[1].cardinality());
        }        
    }
}