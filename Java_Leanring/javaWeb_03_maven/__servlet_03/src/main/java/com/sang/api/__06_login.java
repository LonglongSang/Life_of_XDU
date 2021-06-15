package com.sang.api;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.net.URLDecoder;

public class __06_login extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        System.out.println(URLDecoder.decode(String.valueOf(req.getRequestURL()), "UTF-8"));
        System.out.println("name is " + req.getParameter("username"));
        System.out.println("password is " + req.getParameter("password"));
        resp.sendRedirect(this.getServletContext().getContextPath() + "/success.jsp");
    }
}
