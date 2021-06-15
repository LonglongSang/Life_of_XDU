package com.grammer.multiThread;

/**
 * 从静态代理模式来理解Thread和Runnable
 */

public class __thread04_staticProxy {
    private static class node implements Runnable
    {
        node(){}
        @Override
        public void run()
        {
            System.out.println("run");
        }
    }
    public static void test1()
    {
        //自己准备自己的婚礼
        Person person = new Person("Li XiaoLong");
        person.marry();

        //让婚庆公司来帮我准备婚礼，MarryCompany和Person都继承了Marry接口，由MarryCompany来替我代理结婚
        MarryCompany mc = new MarryCompany(person);
        mc.marry();
    }
    public static void test2()throws InterruptedException
    {
        node a = new node();

        //Thread和node类都继承了Runnable接口，由Thread类来替我代理
        Thread t = new Thread(a, "thread01");
        t.start();
        t.join();
    }
    public static void main(String[] args)throws InterruptedException {
        System.out.println("--------test1--------");
        test1();

        System.out.println("--------test2--------");
        test2();
    }
}


/*Marry接口*/
interface Marry
{
    void marry();
}

class Person implements Marry
{
    private String name;
    Person(String _name)
    {
        this.name = _name;
    }
    @Override
    public void marry()
    {
        System.out.println(this.name + " now get married, he/she is happy");
    }
    public String getName()
    {
        return this.name;
    }
}


/*婚庆公司*/
class MarryCompany implements Marry
{
    private Person person;//要结婚的人


    MarryCompany(Person _person)
    {
        this.person = _person;
    }

    @Override
    public void marry()
    {
        System.out.println("Marry Company now help " + person.getName() + " to prepare wedding");
        person.marry();//帮Person结婚
        System.out.println("Marry Company have already helped " + person.getName() + " now need to get money");
    }
}



