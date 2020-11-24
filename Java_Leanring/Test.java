import java.util.ArrayList;
import java.util.Collections;//sort
import java.util.Random;
import java.util.HashSet;
public class Test {
    public static void main(String[] args) {
        Random r=new Random();
        ArrayList<Integer> arr=new ArrayList<Integer>();
        for(int i=0;i<20;i++) arr.add(r.nextInt());
        System.out.println(arr);
        //Collections.sort(arr);
        //arr.sort();
        System.out.println(arr);
        //arr.trimToSize(10);
        System.out.println(arr);

        HashSet<Integer> s1=new HashSet<Integer>();
        s1.add(1);
        s1.add(2);
        if(s1.contains(1)) System.out.println("yes");
        s1.add(2);
        System.out.println(s1.size());
    }
}