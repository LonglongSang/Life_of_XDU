package com.sang.api;

import com.alibaba.fastjson.JSONObject;
import com.sang.database.DataBase;
import com.sang.database.Patient;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class doctorsList extends HttpServlet {
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);
        PrintWriter pW = resp.getWriter();
        DataBase db = util.getDatabase();
        if(db == null){
            util.sendBadResponse(util.databaseNotInit, pW);
            return;
        }
        Patient[] arr = db.doctorsList();
        JSONObject j = new JSONObject();
        j.put("code", "1");
        j.put("data", arr);
        pW.format("%s", j.toJSONString());
        pW.close();
    }
}
