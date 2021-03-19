import java.util.Date;

public class hello {
    //java高类型不会自动向低类型转换，也不会向同类型转换
    static long quickPow(long a,long b){
        long ans=1;
        long dev=1000000007L;
        while(b!=0){
            if(b%2==1) ans=ans*a%dev;
            a=a*a%dev;
            b/=2;
        }
        return ans;
    }
    public static void main(String[] args){
        System.out.println(quickPow(12312,123123123));
        Date a;
        //https://space.bilibili.com/95256449/channel/detail?cid=146244
    }

}


