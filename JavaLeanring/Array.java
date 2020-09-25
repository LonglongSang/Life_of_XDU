// "static void main" must be defined in a public class.
//演示数组用法
public class Array{

    public static void main(String[] args) {
        //一维数组
        int []one1={1,2,3,4,5};
        int one2[]={1,2,3,4,5};
        int []one3 = new int[5];
        int one4[] = new int[5];
        int []one5 = new int[5];
        /*一位数组的C写法
        int* one1 = (int*)malloc(sizeof(int)*5);
        */
        
        //二维数组
        int [][]two1 = new int[4][2];
        int two2[][] = new int[4][2];
        int [][]two3={{1,0},{0,1},{-1,0},{0,-1}};
        int two4[][]={{1,0},{0,1},{-1,0},{0,-1}};
        
        int [][]two5 = new int[4][];//不声明大小
        for(int[] a : two5) a = new int[2];
        
        int [][]two6 = new int[4][];
        for(int i = 0; i < two6.length; i++) two6[i] = new int[2];
        /*二维数组的C写法
        int** two6 = (int**)malloc(sizeof(int*)*4);
        for(int i = 0; i < 4; i++) two6[i] = (int*)malloc(sizeof(int) * 2);
        */
        
        
        
        //三维数组
        int[][][] three1 = {{{1,2,3},{1,2,3},{1,3,2}},{{1,2,3},{1,2,3},{1,2,3}}};//一个2*3*3的三维数组
        
        int r=10,c=10,h=10;
        int [][][]three2=new int[r][][];//之后会声明一个int arr[a1][a2][a3]大小的三维数组
        for(int i=0;i<three2.length;i++){
            three2[i]=new int[c][];
            for(int j=0;j<three2[i].length;j++) three2[i][j]=new int[h];
        }
        /*C语言实现3维数组
        int r=10,c=10,h=10;
        int*** three = (int***)malloc(sizeof(int**)*r);
        for(int i=0;i<r;i++){
            three[i] = (int**)malloc(sizeof(int*)*c);
            for(int j=0;j<c;j++){
                three[i][j] = (int*)malloc(sizeof(int)*h);
            }
        }
        */
    }
}

