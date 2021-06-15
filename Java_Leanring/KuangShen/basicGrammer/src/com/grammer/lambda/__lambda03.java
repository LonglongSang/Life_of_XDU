package com.grammer.lambda;
interface operation <T>
{
    T op(T a, T b);
}
interface doOperation <T>
{
    T doOp(T a, T b, operation<T> op);
}
public class __lambda03 {
    public static void main(String[] args) {
        operation<Integer> add = (Integer a, Integer b)->{
            return a + b;
        };
        operation<Integer> sub = (a, b)->{
            return a - b;
        };
        operation<Integer> mul = (a, b)->{
            return a * b;
        };

        doOperation<Integer> run = (x, y, op)->{
            return op.op(x, y);
        };
        Integer x = 100;
        Integer y = 10;
        System.out.println(run.doOp(x, y, add));
        System.out.println(run.doOp(x, y, sub));
        System.out.println(run.doOp(x, y, mul));


    }
}
