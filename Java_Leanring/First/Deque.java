//https://www.hackerrank.com/challenges/java-dequeue/problem
import java.util.*;
class node{
    public int index;
    public int value;
    public node(int i,int v)
    {
        index = i;
        value = v;
    }
}
    public class test {
        static int N = 10000005;
        static int[] vis = new int[N];
        public static void main(String[] args) {
            for(int i = 0;i< N ;i++) vis[i] = -1;
            Scanner in = new Scanner(System.in);
            Deque<node> Q = new ArrayDeque<node>();
            //Deque<node> Q = new LinkedList<node>();
            int n = in.nextInt();
            int m = in.nextInt();
            int cnt = 0;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                node temp = new node(i, in.nextInt());
                //System.out.println(Q.size());
                while( !Q.isEmpty() && Q.peekFirst().index <= i - m)
                {
                    if(vis[Q.peekFirst().value] == Q.peekFirst().index)
                    {
                        vis[Q.peekFirst().value] = -1;
                        cnt--;
                    }
                    Q.removeFirst();
                }
                while( !Q.isEmpty() && vis[Q.peekFirst().value] != Q.peekFirst().index)
                {
                    if(vis[Q.peekFirst().value] == Q.peekFirst().index)
                    {
                        vis[Q.peekFirst().value] = -1;
                        cnt--;
                    }
                    Q.removeFirst();
                }
                if(vis[temp.value] == -1) cnt++;
                vis[temp.value] = i;
                Q.addLast(temp);
                if(cnt > ans) ans = cnt;
            }
            System.out.println(ans);
        }
    }



