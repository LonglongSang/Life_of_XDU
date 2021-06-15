package com.sang.api;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class __03_post extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("get");
        //super.doGet(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("post");
        InputStream in = req.getInputStream();
        InputStreamReader isR = new InputStreamReader(in);
        int a;
        while((a = isR.read()) != -1){
            System.out.format("%c", (char)a);
        }
        isR.close();
        in.close();
    }
}
