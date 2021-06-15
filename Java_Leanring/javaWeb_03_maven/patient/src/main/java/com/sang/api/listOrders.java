package com.sang.api;

import com.alibaba.fastjson.JSONObject;
import com.sang.database.DataBase;
import com.sang.database.Doctor;
import com.sang.database.Form;
import com.sang.database.Patient;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
//患者调用
public class listOrders extends HttpServlet {
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }
    private static class node{
        private Patient doctor;
        private int sid;
        private int status;
        private String orderDate;
        node(){

        }
        node(Patient p, Form f){
            this.doctor = p;
            this.sid = f.getSid();
            this.status = f.getStatus();
            this.orderDate = f.getOrderDate();
        }

        public void setDoctor(Patient p) {
            this.doctor = doctor;
        }

        public Patient getDoctor() {
            return doctor;
        }

        public void setOrderDate(String orderDate) {
            this.orderDate = orderDate;
        }

        public String getOrderDate() {
            return orderDate;
        }

        public void setStatus(int status) {
            this.status = status;
        }

        public int getStatus() {
            return status;
        }

        public void setSid(int sid) {
            this.sid = sid;
        }

        public int getSid() {
            return sid;
        }
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);
        DataBase db = util.getDatabase();
        PrintWriter pW = resp.getWriter();
        if(db == null){
            util.sendBadResponse(util.databaseNotInit, pW);
            return;
        }
        int uid = util.isLogin(req);
        if(uid == -1){
            util.sendBadResponse(util.notLogin, pW);
            return;
        }
        boolean isPatient = db.isPatient(uid);
        if(!isPatient){
            util.sendBadResponse(util.notIsPatient, pW);
            return;
        }
        Form[] f = db.getOrderList(uid);
        if(f == null){
            util.sendBadResponse(util.unknownFault, pW);
            return;
        }
        node[] arr = new node[f.length];
        try{
            for(int i = 0, n = arr.length; i < n; i++){
                arr[i] = new node((Doctor)db.acquireDoctor(f[i].acquireDoctorUid()), f[i]);
            }
        }catch (Exception e){
            e.printStackTrace();
            util.sendBadResponse(util.unknownFault, pW);
            return;
        }
        JSONObject j = new JSONObject();
        j.put("code", 1);
        j.put("data", arr);
        pW.format("%s", j.toJSONString());
        pW.close();
    }
}
