package com.sang.api;

import com.alibaba.fastjson.JSONObject;

public class __04_testJson {

    public static void main(String[] args) {
        JSONObject ob = new JSONObject();
        ob.put("x", 10);
        ob.put("y", 12);
        ob.put("z", 13);
        ob.put("hello", "\"hello ");
        System.out.println(ob);
        System.out.println(ob.toJSONString());
        System.out.println(ob.toString());
        JSONObject ob1 = new JSONObject();
        ob1.put("name", "hello");
        ob1.put("pass", "good");
        ob.put("data", ob1);
        System.out.println(ob);
    }
}
