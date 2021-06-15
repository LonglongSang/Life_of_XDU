package com.sang.api;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;

public class __02_test extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        ServletContext context = this.getServletContext();
        ServletOutputStream sOut = resp.getOutputStream();
        //PrintWriter pW = resp.getWriter();
        String name = context.getRealPath("\\WEB-INF\\classes\\a.png");
        name = name.replace("\\", "/");
        File file = new File(name);
        if(file.exists()) sOut.write("exist\n".getBytes());
        else sOut.write("not exist\n".getBytes());
        sOut.write(name.getBytes());

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
