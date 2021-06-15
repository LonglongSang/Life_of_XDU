package com.sang.cookieSeesion;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;

public class __01_cookie_hello extends HttpServlet {
    private int check(PrintWriter pW, Cookie[] arr, int startPos, boolean check, String name){
        if(name == null || arr == null || pW == null) return 0x7fffffff;
        for(; startPos < arr.length; startPos++){
            if(arr[startPos] != null && arr[startPos].getName().equals(name)){
                if(check) return startPos;
                pW.write((new Date(Long.parseLong(arr[startPos].getValue()))).toLocaleString() + "\n");
            }
        }
        return 0x7fffffff;
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        PrintWriter pW = resp.getWriter();
        Cookie[] cookiesArr = req.getCookies();
        String name = "lastLoginTime";
        int expireTime = 20;//3秒后cookie过期
        int startPos = 0;
        pW.write("你本次访问的时间为: " + (new Date(System.currentTimeMillis())).toLocaleString() + "\n");
        pW.write("本次cookie " + expireTime + " 秒后过期\n");
        if(cookiesArr != null && (startPos = check(pW, cookiesArr, 0, true, name)) != 0x7fffffff){
            pW.write("你上一次登录时间为\n");
            check(pW, cookiesArr, startPos, false, name);
        }else{
            pW.write("这是你第一次访问本网站" + new Date(System.currentTimeMillis()).toLocaleString());
        }
        Cookie temp = new Cookie(name, String.valueOf(System.currentTimeMillis()));
        temp.setMaxAge(expireTime);//expireTime秒后过期
        resp.addCookie(temp);//将cookie添加到响应报文里
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
