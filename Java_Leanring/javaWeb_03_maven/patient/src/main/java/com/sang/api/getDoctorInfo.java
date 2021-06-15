package com.sang.api;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.sang.database.DataBase;
import com.sang.database.Patient;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class getDoctorInfo extends HttpServlet {
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);
        PrintWriter pW = resp.getWriter();
        DataBase db = util.getDatabase();
        if(db == null){
            util.sendBadResponse(util.databaseNotInit, pW);
            return;
        }
        byte[] s = new byte[util.lenLimit];
        int cnt = util.read(s, req.getInputStream());
        JSONObject j = null;
        try{
            j = JSON.parseObject(s, 0, cnt, util.decoder, null);
            if(j == null) throw new NullPointerException("null pointer");
            String uidStr = (String)j.get("uid");
            if(uidStr == null) throw new NullPointerException("null");
            int uid = Integer.parseInt(uidStr);
            System.out.println("uid is " + uid);
            boolean isDoctor = db.isDoctor(uid);
            if(!isDoctor){
                util.sendBadResponse(util.checkedNotIsDoctor, pW);
                return;
            }
            Patient p = db.acquirePatient(uid);
            util.sendGoodResponse(p, pW);
        }catch (Exception e){
            e.printStackTrace();
            util.sendBadResponse(util.badJsonFormat, pW);
        }
    }
}
