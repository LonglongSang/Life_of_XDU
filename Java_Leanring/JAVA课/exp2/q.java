//import java.util.ArrayList;
import java.util.*;
class Myinterger
{
    public static final int len = 256;
    private static void opposite(Myinterger a)
    {
        boolean add = true;
        boolean cur = false;
        for(int i = 0; i < len; i++)
        {
            cur = !a.value[i];
            if(cur && add)
            {
                a.value[i] = false;
                add = true;
            }else if(!cur && !add)
            {
                a.value[i] = false;
                add = false;
            }else
            {
                a.value[i] = true;
                add = false;
            }
        }
    }
    private void init(long val)
    {
        int cnt = 0;
        boolean neg = false;
        if(val < 0) neg = true;
        while(val != 0)
        {
            if(val % 2 != 0) value[cnt] = true;
            val /= 2;
            cnt++;
        }
        if(neg) opposite(this);//负数就取相反数
    }
    private static void init(Myinterger th, String a)
    {
        if(a.length() == 0) return;
        StringBuilder aOri = new StringBuilder(a);
        boolean neg = aOri.charAt(0) == '-';
        StringBuilder aRel = new StringBuilder();
        boolean zero = true;
        for(int i = 0; i < aOri.length(); i++)
        {
            if(aOri.charAt(i) >= '0' && aOri.charAt(i) <= '9' && (aOri.charAt(i) != '0' || !zero))
            {
                aRel.append(aOri.charAt(i));
                zero = false;
            }
            else if(aOri.charAt(i) != ',' && aOri.charAt(i) != '-')
            {
                System.exit(1);
            }
        }
        //strReverse(aRel);
        //System.out.println(a);
        
        int cnt = 0, last = 0, tot;
        
        while(aRel.length() != 0 && aRel.charAt(0) != '0')
        {
            last = 0;
            //System.out.println("aRel "+aRel);
            StringBuilder cur = new StringBuilder();
            if((aRel.charAt(aRel.length() - 1) - '0') % 2 == 1){
                th.value[cnt++] = true;
            }
            else
            {
                th.value[cnt++] = false;
            }
            if(aRel.length() == 1 && aRel.charAt(0) == '1') break;
            for(int i = 0; i < aRel.length(); i++)
            {
                tot = last * 10 + aRel.charAt(i) - '0';
                if(tot / 2 != 0 || cur.length() != 0)cur.append((char)(tot / 2 + '0'));
                last = tot % 2;
            }
            //System.out.println("cur "+cur);
            aRel = cur;
        }
        if(neg) opposite(th);
        //th.print();
    }
    public void print()
    {
        for(int i = 0; i < len; i++) System.out.print(value[i] ? 1 : 0);
        System.out.println();
    }
    Myinterger(int val)
    {
        init((long)val);
    }
    Myinterger(long val)
    {
        init(val);
    }
    Myinterger()
    {

    }
    Myinterger(String val)
    {
        init(this, val);
        //return ans;
    }
    private static void strMultiple(StringBuilder a, int mul)
    {
    	int length = a.length();
    	int add = 0;
    	int tot = 0;
    	for(int i = 0; i < length; i++)
    	{
    		tot = (a.charAt(i) - '0') * mul + add;
            //System.out.println(tot);
    		a.setCharAt(i,  (char)('0' + (int)(tot % 10)));
    		add = tot / 10;
    	}
        while(add != 0)
        {
            a.append((char)(add % 10 + '0'));
            add /= 10;
        }
    }
    private static void strAdd(StringBuilder a, int add)
    {
    	int length = a.length();
    	int tot;
    	for(int i = 0; i < length && add != 0; i++)
    	{
    		tot = (a.charAt(i) - '0')  + add;
            //System.out.println(tot);
    		a.setCharAt(i,  (char)('0' + (int)(tot % 10)));
    		add = tot / 10;
    	}
        while(add != 0)
        {
            a.append((char)(add % 10 + '0'));
            add /= 10;
        }
    }
    private static void strReverse(StringBuilder a)
    {
    	int low = 0, high = a.length() - 1;
    	char temp;
    	while(high > low)
    	{
    		temp = a.charAt(low);
    		a.setCharAt(low, a.charAt(high));
    		a.setCharAt(high, temp);
            low++;
            high--;
    	}
    }
    public static StringBuilder toString(Myinterger a)
    {
    	Myinterger aRel = a;
    	StringBuilder ans = new StringBuilder();
    	ans.append("0");
    	if(a.value[len - 1])
    	{
    		aRel = new Myinterger(a);
    		opposite(aRel);
    	}
    	for(int i = len - 1; i >= 0; i--)
    	{
    		strMultiple(ans, 2);
    		strAdd(ans, aRel.value[i] ? 1 : 0);
            //System.out.println(ans);
    	}
    	if(a.value[len - 1]) ans.append("-");
    	strReverse(ans);
    	return ans;
    }
    Myinterger(Myinterger a)
    {
    	for(int i = 0; i < len; i++) this.value[i] = a.value[i];
    }
    private void add(Myinterger a, int offset, Myinterger ans)
    {
        boolean add = false;
        int cnt;
        for(int i = 0; i < len && i + offset < len; i++)
        {
            cnt = 0;
            if(a.value[i]) cnt++;
            if(ans.value[i + offset]) cnt++;
            if(add) cnt++;
            switch(cnt)
            {
                case 0:
                    add = false;
                    ans.value[i + offset] = false;
                    break;
                case 1:
                    ans.value[i + offset] = true;
                    add = false;
                    break;
                case 2:
                    ans.value[i + offset] = false;
                    add = true;
                    break;
                case 3:
                    ans.value[i + offset] = true;
                    add = true;
                    break;
            }
        }
    }
    Myinterger add(Myinterger a)
    {
        Myinterger ans = new Myinterger();
        boolean op1 = a.value[len - 1];
        boolean op2 = this.value[len - 1];
        add(this, 0, ans);
        add(a, 0, ans);
        if(op1 == op2 && ans.value[len - 1] != op1)
        {
            
        }
        return ans;
    }
    Myinterger minus(Myinterger a)
    {
        Myinterger ans = new Myinterger();
        Myinterger aOpp = new Myinterger(a);
        opposite(aOpp);
        add(this, 0, ans);
        add(aOpp, 0, ans);
        return ans;
    }

    public boolean equals(Myinterger a)
    {
    	for(int i = 0; i < len; i++) if(this.value[i] != a.value[i]) return false;
    	return true;
    }
    boolean[] value = new boolean[len];
}
class MyNatural extends Myinterger
{
    public static Myinterger toMyInterger(MyNatural a)
    {
        Myinterger ans = new Myinterger();
        for(int i = 0; i < Myinterger.len; i++)
        {
            ans.value[i] = a.value[i];
        }
        return ans;
    }
}
public class q
{
    public static void main(String[] args)
    {
        //Myinterger a = new Myinterger("20000031232131222222222222222222222222222222220000000000000000000000");
        //Myinterger b = new Myinterger("100000000000333333333333330000000000000000");
        //Myinterger c = a.add(b);
        //Myinterger d = a.minus(b);
        int typ;
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            System.out.println("Function: 1 for add, 2 for minus,3 for quit");
            typ = sc.nextInt();
            if(typ == 3) break;
            String x = sc.next();
            String y = sc.next();
            Myinterger a = new Myinterger(x);
            Myinterger b = new Myinterger(y);
            Myinterger c;
            if(typ == 1)
            {
                c = a.add(b);
            }else{
                c = a.minus(b);
            }
            System.out.println(Myinterger.toString(c));
            //break;
        }
    }
}