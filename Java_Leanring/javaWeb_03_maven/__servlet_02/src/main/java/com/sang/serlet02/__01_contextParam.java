package com.sang.serlet02;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

/**
 * 测试ServletContext的getInitParameter函数
 */
public class __01_contextParam extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        PrintWriter pW = resp.getWriter();
        ServletContext sC = this.getServletContext();
        resp.setCharacterEncoding("utf-8");
        pW.write("__01_contextParam\n");
        Random r = new Random();
        //随机设置template_para的内容，good是不存在与web.xml中的，但是template_para是存在于web.xml中的，表现如下
        /**
         *   <context-param>
         *     <param-name>template_para</param-name>
         *     <param-value>this is a template_para content</param-value>
         *   </context-param>
         */
        String template_para = r.nextInt(2) == 0 ? "good" : "template_para";
        template_para = sC.getInitParameter(template_para);//获得template_para的内容，如果不存在，返回null
        pW.write(template_para == null ? "null" : template_para);
        pW.write("\n");
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
