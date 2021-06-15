package com.sang.cookieSeesion;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;

/**
 * 这个文件用于测试session
 * 当你打开一个浏览器时，用户第一次访问本网址下的一个有效地址，用户的请求报文是不携带任何cookie信息的
 * 当服务端检测到这是该浏览器第一次访问本服务器，就会在回应报文里加入一个cookie，名字为JSESSIONID
 * 所以本质上session还是一个cookie
 *
 * 可以去web.xml里被子session的过期时间
 *  <session-config>
 *     <session-timeout>1</session-timeout><!--设置session 1 分钟不访问即过期-->
 *   </session-config>
 *
 * http://localhost:8080/__servlet_05_cookie_session_war/helloSession
 * http://localhost:8080/__servlet_05_cookie_session_war/test
 * 通过这两个网址，可以交替测试
 */
public class __02_session_hello extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        HttpSession session = req.getSession();
        PrintWriter pW = resp.getWriter();
        if(session.getAttribute("times") == null){
            session.setAttribute("times", 0);
        }
        if (session.isNew()) {
            pW.write("新 session, session ID: " + session.getId() + "\n");
        }else{
            pW.write("旧 session, session ID: " + session.getId() + "\n");
        }
        Date d = new Date();
        d.setTime(System.currentTimeMillis());
        pW.format("本次访问时间 %s\n", d.toLocaleString());
        d.setTime(session.getCreationTime());
        pW.format("Session 的创建时间 %s\n", d.toLocaleString());
        d.setTime(session.getLastAccessedTime());
        pW.format("上一次访问本网站的时间: %s\n", d.toLocaleString());
        pW.format("这是你第%d次访问本网页\n", (Integer)session.getAttribute("times") + 1);
        pW.format("\n\n访问：http://localhost:8080/__servlet_05_cookie_session_war/invalidate 去失效session\n");
        pW.close();
        session.setAttribute("times", (Integer)session.getAttribute("times") + 1);
        /**
         *如果你打开网页http://localhost:8080/__servlet_05_cookie_session_war/helloSession
         * 他一般总是显示这不是一个新session
         * 因为在一个浏览器，你第一次访问这个网页session就已经存在(idea测试该项目时，会先打开主页，那时就注册了)
         * 所以当你访问本网页，一定不是一个新session，但是你可以关闭该浏览器，再打开然后再访问本网址即可，就会显示
         * 这是一个新session
         */

    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
