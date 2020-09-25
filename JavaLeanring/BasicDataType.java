// "static void main" must be defined in a public class.

public class BasicDataType{
    public static void main(String[] args) {
        System.out.println("Byte Size "+Byte.SIZE);
        System.out.println("Short Size "+Short.SIZE);
        System.out.println("Double Size "+Double.SIZE);
        System.out.println("Double MAX_VALUE "+Double.MAX_VALUE);
        System.out.println("Int MAX_VALUE "+Integer.MAX_VALUE);
        byte b = 100;
        short s = 20202;
        int i = 120112010;
        long l = 191293123129312L;//整数默认是int,需要显式加L转为long
        float f = 123.20F;//浮点数默认是double,需要显式加F转为float
        double d = 1290219.02;
        char c = 210;
        boolean bl = true;
        
        i = 1000;
        final int i2 = 100;
        
        String str = "I am string";
        str += i2;//字符串可以和非字符串拼接
        System.out.println(str);
        //i2 = 300; i2不能被修改，因为i2被final修饰了，是常量
        /*Java 的8种内置基础数据类型
        byte 8位，C语言里的char
        short 16位
        int 32位
        long 64位
        float 32位
        double 64位
        char 字符型，16位，表示字符
        boolean 布尔型
        */
    }
}

