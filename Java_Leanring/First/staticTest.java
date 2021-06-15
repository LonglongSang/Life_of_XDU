public class staticTest
{
    public static void main(String[] args)
    {
        new Father();
        //先运行静态初试代码块（只运行一次）
        //非静态代码块只在实例化初始化一次
        System.out.printf("------\n");
        new Son();    
    }
}
class Father
{
    static
    {
        System.out.printf("Father static initialize\n");
    }
    {
        System.out.printf("Father Instance initialize\n");
    }
    Father()
    {
        System.out.printf("Father Constructor\n");
    }
}
class Son extends Father
{
    static
    {
        System.out.printf("Son static initialize\n");
    }
    {
        System.out.printf("Son Instance initialize\n");
    }
    Son()
    {
        System.out.printf("Son Constructor\n");
    }    
}