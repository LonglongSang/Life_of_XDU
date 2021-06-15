package com.sang.api;

import com.sang.database.DataBase;
import com.sang.database.Doctor;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class printDatabaseInfo extends HttpServlet {
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);
        DataBase db = util.getDatabase();
        PrintWriter pW = resp.getWriter();
        if(db == null){
            pW.format("数据库还未启动\n");
        }else{
            db.printAll(pW);
        }
        pW.close();
        Doctor d = (Doctor) db.acquireDoctor(0);
    }
}
