package com.sang.api;

import com.sang.database.DataBase;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class monitor extends HttpServlet {
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
        int uid = util.isLogin(req);
        if(uid == -1){
            pW.format("%s", util.code0);
        }else{
            if(!db.setSubmitTime(uid)){
                util.sendBadResponse(util.unknownFault, pW);
            }else{
                pW.format("%s", util.code1);
            }
        }
        pW.close();
    }
}
