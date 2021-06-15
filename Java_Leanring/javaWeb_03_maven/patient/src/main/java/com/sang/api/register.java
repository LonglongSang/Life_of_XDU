package com.sang.api;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.sang.database.DataBase;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;

public class register extends HttpServlet {

    private static class node
    {
        node(){

        }
        node(String name, String pass, String sex, String date){
            this.name = name;
            this.pass = pass;
            this.sex = sex;
            this.date = date;
        }
        public String name;

        public String pass;

        public String sex;

        public String date;

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
        @Override
        public String toString() {
            return name + " " + pass + " " + sex + " " + date;
        }
    }
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }
    private String getGoodResponse(int uid){
        JSONObject j = new JSONObject();
        j.put("code", 1);
        j.put("uid", String.valueOf(uid));
        return j.toString();
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);


        //从req获得输入流，从resp获得输出流
        InputStream input = req.getInputStream();
        PrintWriter pW = resp.getWriter();

        DataBase db = util.getDatabase();
        if(db == null){
            util.sendBadResponse(util.databaseNotInit, pW);
            return;
        }

        if(util.isLogin(req) != -1){
            util.sendBadResponse(util.loginCanNotRegister, pW);
            return;
        }
        //读取req中的数据，限制最多读取util.lenLimit长度
        byte[] s = new byte[util.lenLimit];
        int cnt = util.read(s, input);

        node cur = null;
        try{
            cur = JSON.parseObject(s, 0, cnt, util.decoder, node.class);
        }catch (Exception e){
            e.printStackTrace();
            pW.format("%s", JSON.toJSONString(new util.error(0, util.badJsonFormat)));
        }

        int uid = db.registerPatient(cur.name, cur.pass, cur.sex, cur.date);
        if(uid == -1){
            util.sendBadResponse(util.badJsonFormat, pW);
            return;
        }
        pW.format("%s", getGoodResponse(uid));
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
