package com.sang.api;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.sang.database.DataBase;
import com.sang.database.Form;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class orderDoctor extends HttpServlet {
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
        util.Ref<Integer> patientUid = new util.Ref<>();
        util.Ref<Integer> cnt = new util.Ref<>();
        util.commonInit(req, db, patientUid, s, cnt, pW);
        try{
            JSONObject j = JSON.parseObject(s.value, 0, cnt.value, util.decoder, null);
            String doctorUidStr = (String)j.get("uid");
            if(doctorUidStr == null) throw new NullPointerException("null");
            int doctorUid = Integer.parseInt(doctorUidStr);
            Form f = db.value.orderDoctor(patientUid.value, doctorUid);
            if(f == null){
                util.sendBadResponse(util.orderFailed, pW);
                return;
            }
            j.clear();
            j.put("code", 1);
            j.put("data", f);
            pW.format("%s", j.toJSONString());
            pW.close();
        }catch (Exception e){
            e.printStackTrace();
            util.sendBadResponse(util.badJsonFormat, pW);
            return;
        }
    }
}
