package com.sang.api;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.sang.database.DataBase;
import com.sang.database.Patient;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.nio.charset.CharsetDecoder;
import java.nio.charset.StandardCharsets;
import java.util.Date;
import java.util.Enumeration;

public class util {

    public static final Charset charset = StandardCharsets.UTF_8;
    //public static final Charset charset = Charset.forName("utf-8");
    public static final CharsetDecoder decoder = charset.newDecoder();
    public static final int lenLimit = 1 << 7;
    public static final String badJsonFormat = "JSON 格式有误";
    public static final String haveLogin = "你已经登录，如果想登陆，请退出再登录";
    public static final String databaseNotInit = "数据库尚未初始化，请联系管理员";
    public static final String passOrNameFault = "用户不存在或密码错误";
    public static final String notLogin = "您现在还未登陆";
    public static final String badUser = "您使用了假的cookie来伪造登录";
    public static final String checkedNotIsDoctor = "你查询的人不是医生";
    public static final String orderFailed = "请检查您是否预定的是医生，或请检查该医生是否还有预约名额";
    public static final String cancelFailed = "你已经完成该预约或者已经取消";
    public static final String diagnoseFailed = "你不是医生，或者该预约已经取消或者已经诊断过";
    public static final String unknownFault = "未知错误";
    public static final String notIsDoctor = "当前登录的人不是医生";
    public static final String notIsPatient = "当前登录的人不是患者";
    public static final String loginCanNotRegister = "您当前已登录，请退出后，再注册";

    public static final String code0 = "{\"code\":0}";
    public static final String code1 = "{\"code\":1}";
    private static DataBase db = null;
    public static synchronized void setDatabase(DataBase _db){
        db = _db;
    }
    public static synchronized DataBase getDatabase(){
        return db;
    }
    public static class Ref<T>{
        Ref(T value){
            this.value = value;
        }
        Ref(){

        }
        public T value = null;
    }
    public static class error{
        error(int code, String msg){
            this.code = code;
            this.msg = msg;
        }
        public final int code;
        public final String msg;
    }

    public static final String header1 = "Access-Control-Allow-Origin";
    public static final String header2 = "Access-Control-Allow-Credentials";
    public static final String header3_1 = "Access-Control-Request-Headers";
    public static final String header3_2 = "access-control-request-headers";
    public static final String header5 = "Access-Control-Allow-Headers";
    public static final String header4 = "Access-Control-Allow--Methods";
    public static boolean commonInit(HttpServletRequest req, util.Ref<DataBase> db, util.Ref<Integer> uid, util.Ref<byte[]> s, util.Ref<Integer> cnt, PrintWriter pW){
        db.value = getDatabase();
        if(db.value == null){
            sendBadResponse(util.databaseNotInit, pW);
            return false;
        }
        uid.value = isLogin(req);
        if(uid.value == -1){
            sendBadResponse(util.notLogin, pW);
            return false;
        }
        s.value = new byte[util.lenLimit];
        try{
            cnt.value = read(s.value, req.getInputStream());
            return true;
        }catch (IOException e){
            e.printStackTrace();
            util.sendBadResponse(util.unknownFault, pW);
            return false;
        }
    }
    /**
     * 对req报文和resp报文进行一些处理
     * @param req http请求报文
     * @param resp http回应报文
     * @throws UnsupportedEncodingException
     */
    public static void initResponseSetOptions(HttpServletRequest req, HttpServletResponse resp) throws UnsupportedEncodingException {
        if(resp == null || req == null) return;
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        resp.setHeader(header1, req.getHeader("origin"));
        resp.setHeader(header2, "true");
        String z = req.getHeader(header3_1);
        if(z == null) z = req.getHeader(header3_2);
        resp.setHeader(header5, z);
        resp.setHeader(header4, "GET,POST,DELETE,OPTIONS");
        printInfo(req);
    }

    /**
     * 输出http请求里的信息
     * @param req http请求报文
     */
    public static void printInfo(HttpServletRequest req){
        System.out.println((new Date(System.currentTimeMillis())).toLocaleString());
        System.out.println(req.getMethod());
        System.out.println(req.getRequestURL());
        System.out.println("JSESSIONID: " + req.getRequestedSessionId());
        System.out.println("remote Host: "  + req.getRemoteHost());
        System.out.println("remote Addr: " + req.getRemoteAddr());
        System.out.println("Header信息");
        Enumeration<String> hArr = req.getHeaderNames();
        while(hArr.hasMoreElements()){
            String a = hArr.nextElement();
            System.out.println(a + " : " + req.getHeader(a));
        }
        System.out.println("Cookie信息");
        Cookie[] cArr = req.getCookies();
        if(cArr == null){
            System.out.println("no cookie");
        }else{
            for(Cookie c: cArr){
                System.out.println(c.getName() + ":" + c.getValue());
            }
        }
        System.out.println("\n\n\n\n");

    }
    public static void initResponseSet(HttpServletRequest req, HttpServletResponse resp) throws UnsupportedEncodingException {
        if(resp == null || req == null) return;
        initResponseSetOptions(req, resp);
    }

    /**
     * 是否已经登录
     * @param req
     * @return
     */
    public static int isLogin(HttpServletRequest req){
        HttpSession session = req.getSession();
        Integer uid = (Integer)session.getAttribute("uid");
        if(uid == null) return -1;
        else return uid;
    }

    /**
     * 向流中写入JSON格式的error信息，并关闭输出流
     * @param info 错误信息
     * @param pW 流
     */
    public static void sendBadResponse(String info, PrintWriter pW){
        pW.format("%s", JSON.toJSONString(new error(0, info)));
        pW.close();
    }
    public static void sendGoodResponse(Patient patient, PrintWriter pW){
        JSONObject j = new JSONObject();
        j.put("code", 1);
        j.put("data", patient);
        pW.format("%s", j.toJSONString());
        pW.close();
    }

    /**
     * 从输入流中读入数据到s中，读取的字节最大限制为util.lenLimit
     * @param s 目标数据存储
     * @param input 输入流
     * @return 从输入流中读取的字节数
     * @throws IOException
     */
    public static int read(byte[] s, InputStream input) throws IOException {
        if(s == null || s.length < lenLimit || input == null) return 0;
        int cnt = 0, len;
        while(cnt < lenLimit && (len = input.read(s, cnt, s.length - cnt)) != -1){
            cnt += len;
        }
        return cnt;
    }
}
