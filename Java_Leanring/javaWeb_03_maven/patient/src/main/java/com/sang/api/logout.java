package com.sang.api;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class logout extends HttpServlet {
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);
        PrintWriter pW = resp.getWriter();
        if(util.isLogin(req) == -1){
            //未登陆
            pW.format("{\"code\": 0}");
        }else{
            //登录了
            req.getSession().invalidate();
            pW.format("{\"code\": 1}");
        }
        pW.close();
    }
}
