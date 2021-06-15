package com.sang.api;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class __05_redirect extends HttpServlet {
    private int cnt = 0;
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String newPath = this.getServletContext().getContextPath() + "/download/a.png";
        System.out.println(this.getServletContext().getContextPath());
        //sendRedirect做的就是以下两步
        switch (cnt++ % 2){
            case 0:
            {
                resp.sendRedirect(newPath);
                break;
            }
            case 1:
            {
                resp.setHeader("Location", newPath);
                resp.setStatus(302);
                resp.getWriter().write("");
            }
        }
    }
}
