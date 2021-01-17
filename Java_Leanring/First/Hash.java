import java.util.HashSet;
class Hash{
    public static void main(String []args){
        HashSet<Double> a=new HashSet<Double>();
        a.add(1.0);
        a.add(2.0);
        a.add(1.0);
        System.out.println(a);
        System.out.println(a.contains(1.0));
    }
}