package com.sang.serlet02;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class __00_hello extends HttpServlet {
    public int cnt = 0;
    private void setInfo(){
        if(cnt != 0) return;
        ServletContext sC = this.getServletContext();
        sC.setAttribute("hello", this);
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        setInfo();
        PrintWriter pW = resp.getWriter();
        pW.print(cnt++);
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
    void temp(){
        //ServletContext a = new ServletContext();
    }
}
