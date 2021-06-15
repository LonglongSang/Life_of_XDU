package com.sang.serlet02;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Properties;

public class __03_properities extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html;charset=UTF-8");
        PrintWriter pW = resp.getWriter();
        ServletContext context = this.getServletContext();
        Properties prop = new Properties();
        InputStream input = context.getResourceAsStream("/WEB-INF/classes/db.properities");
        prop.load(input);
        pW.format("%s<br>\n<br/>", prop.getProperty("name", "null"));
        pW.format("%s<br>\n<br/>", prop.getProperty("password", "null"));
        pW.format("%s<br>\n<br/>", prop.getProperty("non-existed", "null"));
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
