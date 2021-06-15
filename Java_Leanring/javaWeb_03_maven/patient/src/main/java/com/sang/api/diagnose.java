package com.sang.api;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.sang.database.DataBase;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class diagnose extends HttpServlet {
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
            JSONObject j = JSON.parseObject(s.value, 0, cnt.value, util.decoder, null);
            String sidStr = (String)j.get("sid");
            int sid = Integer.valueOf(sidStr);
            boolean ok = db.value.diagnose(uid.value, sid);
            if(ok){
                pW.format("{\"code\": 1}");
                pW.close();
            }else{
                util.sendBadResponse(util.diagnoseFailed, pW);
            }
        }catch (Exception e){
            e.printStackTrace();
            util.sendBadResponse(util.badJsonFormat, pW);
            return;
        }
    }
}
