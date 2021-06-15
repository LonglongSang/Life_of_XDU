package com.sang.serlet02;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class __04_temp extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        PrintWriter pW = resp.getWriter();
        this.getServletContext();
        pW.format("getContextPath(): %s\n", req.getContextPath());
        pW.format("getMethod(): %s\n", req.getMethod());
        pW.format("getPathInfo(): %s\n", req.getPathInfo());
        pW.format("getRequestURI(): %s\n", req.getRequestURI());
        pW.format("getRequestURL(): %s\n", req.getRequestURL());
        pW.format("getRemoteUser(): %s\n", req.getRemoteUser());
        pW.format("getRemoteAddr(): %s\n", req.getRemoteAddr());
        pW.format("getRemotePort(): %s\n", req.getRemotePort());
        pW.format("getRemoteHost(): %s\n", req.getRemoteHost());
        //pW.format("%s\n", req.g);

    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
