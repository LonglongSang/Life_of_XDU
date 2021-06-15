package com.sang.servlet04;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Arrays;

public class __01_LoginServlet extends HttpServlet {
    int cnt = 0;
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String[] hobbys = req.getParameterValues("hobbys");
        System.out.println(username);
        System.out.println(password);
        System.out.println(Arrays.toString(hobbys));
        //resp.sendRedirect(req.getContextPath() + "/success.jsp");

        switch(cnt++ % 2){
            case 0:
            {
                resp.sendRedirect(this.getServletContext().getContextPath() + "/success.jsp");
                break;
            }
            case 1:
            {
                req.getRequestDispatcher("/success.jsp").forward(req, resp);
            }
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
