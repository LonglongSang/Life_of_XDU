public class quickPow{
    static long myQuickPow(long a,long b,long dev){
        //(a**p)%dev
        long ans=1;
        while(b!=0){
            if(b%2==1) ans=ans*a%dev;
            a=a*a%dev;
            b/=2;
        }
        return ans;
    }
    public static void main(String[] args){
        long dev=1000000007L;
        System.out.println(myQuickPow(2,100,dev));
    }
}