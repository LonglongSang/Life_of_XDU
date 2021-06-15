package com.sang.api;

import com.sang.database.DataBase;
import com.sang.database.Patient;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class getPatientInfo extends HttpServlet {
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
        int uid;
        if((uid = util.isLogin(req)) == -1){
            util.sendBadResponse(util.notLogin, pW);
            return;
        }
        Patient patient = db.acquirePatient(uid);
        if(patient == null){
            util.sendBadResponse(util.badUser, pW);
        }else{
            util.sendGoodResponse(patient, pW);
        }

    }
}
