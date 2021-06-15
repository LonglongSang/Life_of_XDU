package com.sang.api;

import com.alibaba.fastjson.JSON;
import com.sang.database.DataBase;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class setInfo extends HttpServlet {
    public static class node
    {
        node(){

        }
        public String uid;
        public String name;
        public String pass;
        public String sex;
        public String date;
        public void setUid(String uid){
            this.uid = uid;
        }
        public String getUid(){
            return this.uid;
        }
        public void setName(String name){
            this.name = name;
        }
        public String getName(){
            return this.name;
        }
        public void setPass(String pass){
            this.pass = pass;
        }
        public String getPass(){
            return this.pass;
        }
        public void setSex(String sex){
            this.sex = sex;
        }
        public String getSex(){
            return this.sex;
        }
        public void setDate(String date){
            this.date = date;
        }
        public String getDate(){
            return this.date;
        }
    }
    private static String msg = "{\"code\":1,\"msg\":\"success\"}";
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);
        PrintWriter pW = resp.getWriter();
        util.Ref<DataBase> db = new util.Ref<>();
        util.Ref<byte[]> s = new util.Ref<>(new byte[util.lenLimit]);
        util.Ref<Integer> uid = new util.Ref<>();
        util.Ref<Integer> cnt = new util.Ref<>();
        util.commonInit(req, db, uid, s, cnt, pW);
        try{
            node cur = JSON.parseObject(s.value, 0, cnt.value, util.decoder, node.class);
            db.value.setInfo(uid.value, cur.pass, cur.name, cur.sex, cur.date);
            pW.format("%s", msg);
            pW.close();
        }catch (Exception e){
            e.printStackTrace();
            util.sendBadResponse(util.badJsonFormat, pW);
        }
    }
}
