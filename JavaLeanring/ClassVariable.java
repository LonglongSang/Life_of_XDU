// "static void main" must be defined in a public class.
//本文件讲述了类变量，即，class Node里的cnt，由static修饰
class Node{
    static int cnt=0;
    int val;
    public Node(int val){
        this.val = val;
        cnt++;
    }
    /*输出有多少个已经实例化的对象*/
    public void pri(){
        System.out.println("Node类已经有 " + cnt + " 个对象已经实例化");
    }
}
//类变量
public class ClassVariable{
    public static void main(String[] args) {
        Node a = new Node(100);
        a.pri();
        Node b = new Node(1000);
        a.pri();
        System.out.println(a.cnt);
    }
}

