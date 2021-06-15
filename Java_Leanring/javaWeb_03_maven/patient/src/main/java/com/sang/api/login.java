package com.sang.api;

import com.alibaba.fastjson.JSON;
import com.sang.database.DataBase;
import com.sang.database.Patient;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;

public class login extends HttpServlet {
    private static class node{
        node(){

        }
        public String uid;
        public String pass;
        public void setPass(String pass) {
            this.pass = pass;
        }
        public String getPass() {
            return pass;
        }
        public void setUid(String uid) {
            this.uid = uid;
        }
        public String getUid() {
            return uid;
        }

        @Override
        public String toString() {
            return uid + " " + pass;
        }
    }
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);
        PrintWriter pW = resp.getWriter();
        if(util.isLogin(req) != -1){
            util.sendBadResponse(util.haveLogin, pW);
            return;
        }
        DataBase db = util.getDatabase();
        if(db == null){
            util.sendBadResponse(util.databaseNotInit, pW);
            return;
        }
        byte[] s = new byte[util.lenLimit];
        int cnt = util.read(s, req.getInputStream());
        node cur = null;
        try{
            cur = JSON.parseObject(s, 0, cnt, util.decoder, node.class);
        }catch (Exception e){
            e.printStackTrace();
            util.sendBadResponse(util.badJsonFormat, pW);
            return;
        }
        int uid;
        try{
            uid = Integer.valueOf(cur.uid);
        }catch (Exception e){
            e.printStackTrace();
            util.sendBadResponse(util.badJsonFormat, pW);
            return;
        }
        Patient patient = db.login(uid, cur.pass);
        if(patient == null){
            util.sendBadResponse(util.passOrNameFault, pW);
            return;
        }
        util.sendGoodResponse(patient, pW);
        req.getSession().setAttribute("uid", patient.acquireUid());
    }
}
