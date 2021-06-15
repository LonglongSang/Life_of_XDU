package com.grammer.multiThread;


import java.util.Random;
import java.util.concurrent.*;

/*实现线程方法3，Callable*/
public class __thread03 implements Callable<Integer> {


    public int N;
    __thread03(int N)
    {
        this.N = N;
    }
    public static void main(String[] args) throws ExecutionException, InterruptedException {


        __thread03 t1 = new __thread03(10000);
        __thread03 t2 = new __thread03(12);

        //创建执行服务
        ExecutorService service = Executors.newFixedThreadPool(3);

        //提交执行
        Future<Integer> r1 = service.submit(t1);
        Future<Integer> r2 = service.submit(t2);

        //获取结果
        Integer ans1 = r1.get();
        Integer ans2 = r2.get();
        System.out.println(ans1 + " " + ans2);

        //关闭服务
        service.shutdownNow();

    }

    @Override
    public Integer call()
    {
        Random r = new Random();
        return r.nextInt(N);
    }

}
