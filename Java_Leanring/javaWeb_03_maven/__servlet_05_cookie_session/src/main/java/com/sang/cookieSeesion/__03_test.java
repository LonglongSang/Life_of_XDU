package com.sang.cookieSeesion;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

public class __03_test extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        PrintWriter pW = resp.getWriter();
        HttpSession session = req.getSession();
        Integer val = (Integer)session.getAttribute("times");
        pW.format("获得了session中存储的key的值，值为\n");
        String url = "http://localhost:8080/__servlet_05_cookie_session_war/helloSession";
        pW.write(val == null ? "你还没有访问过" + url : "这是你第" + val + "次访问" + url);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
