package com.sang.api;

import com.sang.database.DataBase;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class clearAllPatients extends HttpServlet {
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
            pW.format("数据库未启动，请启动后在执行清除");

        }else{
            util.setDatabase(DataBase.getDataBase());
            pW.format("数据初始化成功");
        }
        pW.close();

    }
}
