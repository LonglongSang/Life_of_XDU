package com.sang.api;

import com.sang.database.DataBase;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class loadDatabase extends HttpServlet {
    @Override
    public void destroy() {
        System.out.println("准备可持久化数据库");
        DataBase db = util.getDatabase();
        if(db != null){
            DataBase.storeToDisk(this.getServletContext().getRealPath("/WEB-INF/classes"), util.getDatabase(), System.out);
        }
    }

    @Override
    public void init() throws ServletException {

    }
    void qq(){
        System.out.println("正在载入数据库");
        ServletContext context = this.getServletContext();
        DataBase db = util.getDatabase();
        if(db == null){
            String loadPath = context.getRealPath("/WEB-INF/classes") + "/" + DataBase.fileName;
            //loadPath = "C:\\Users\\Administrator\\Desktop" + "/" + DataBase.fileName;
            db = DataBase.getDataBase(loadPath);

            if(db == null) System.out.println("从 " +  loadPath + " 中读取失败，准备初始化默认数据库");
            else System.out.println("从 " + loadPath + " 中读取成功");
            if(db == null) db = DataBase.getDataBase();
            util.setDatabase(db);
        }else{
            System.out.format("数据库已经存在，不需要创建\n");
        }
    }
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }
    @Override
    protected synchronized void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);
        PrintWriter pW = resp.getWriter();
        DataBase db = util.getDatabase();
        if(db == null){
            pW.format("数据库不存在");
            qq();
        }else{
            pW.format("数据库已经存在");
        }
        pW.close();
        /*
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        PrintWriter p = resp.getWriter();

        ServletContext context = this.getServletContext();
        DataBase db = util.getDatabase();
        if(db == null){
            p.format("数据库不存在，准备创建\n");
            String loadPath = context.getRealPath("/WEB-INF/classes") + "/" + DataBase.fileName;
            db = DataBase.getDataBase(loadPath);
            if(db == null) p.format("从 %s 中读取失败，\n准备初始化默认数据库\n", loadPath);
            else p.format("从 %s 中读取数据库成功\n");
            if(db == null) db = DataBase.getDataBase();
            util.setDatabase(db);
        }else{
            p.format("数据库已经存在，不需要创建\n");
        }
        p.close();

         */

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
