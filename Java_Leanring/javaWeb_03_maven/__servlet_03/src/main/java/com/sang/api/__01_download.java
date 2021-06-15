package com.sang.api;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.net.URLDecoder;

public class __01_download extends HttpServlet {
    protected String getUrlName(String Url){
        /**
         * http://localhost:8080/__servlet_03_war/download/a.png
         * 如果请求地址如上，我们将提取出a.png并返回
         */
        if(Url == null) return "";
        int index = Url.lastIndexOf("/");
        if(index == -1) return "";
        return Url.substring(index + 1);
    }
    static byte[] buffer = new byte[1 << 10];
    int cnt = 0;
    //将File中内容写入到out中
    private boolean copy(File file, OutputStream out, boolean tested){
        if(file == null || out == null || !file.exists() || file.isDirectory() || !file.canRead()) return false;
        if(tested) return true;
        int len = 0;
        FileInputStream fIn;
        BufferedInputStream bIn;
        try {
            fIn = new FileInputStream(file);
            bIn = new BufferedInputStream(fIn);
            while((len = bIn.read(buffer, 0, buffer.length)) != -1){
                out.write(buffer, 0, len);
            }
            bIn.close();
            fIn.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return true;
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        /**
         * 如果我们在浏览器中输入：http://localhost:8080/__servlet_03_war/download/QQ音乐.png
         * 实际传输过来的是：http://localhost:8080/__servlet_03_war/download/QQ%E9%9F%B3%E4%B9%90.png
         * 因此需要URLDecoder将url转化为UTF-8的格式
         */
        String decodedUrl = URLDecoder.decode(new String(req.getRequestURL()), "UTF-8");
        String fileName = getUrlName(decodedUrl);
        ServletContext context = this.getServletContext();
        String filePath = context.getRealPath("/WEB-INF/classes/" + fileName);
        filePath = filePath.replace("\\", "/");
        File file = new File(filePath);
        switch(cnt++ % 3){
            case 0:
            {
                System.out.println("----------------0");
                resp.setContentType("text/html;charset=UTF-8");
                PrintWriter pW = resp.getWriter();
                pW.format("你请求的地址为:%s<br>\n</br>", decodedUrl);
                pW.format("编码后的地址为:%s<br>\n</br>", req.getRequestURL());
                pW.format("你想要下载的文件名为: %s<br>\n</br>", fileName);
                break;
            }
            case 1:
            {
                System.out.println("----------------1");
                ServletOutputStream sOut = resp.getOutputStream();
                if(!copy(file, sOut, true)){
                    sOut.write(("you want download " + fileName + ", but not exist").getBytes());
                }else{
                    resp.setHeader("Content-Disposition", "attachment:filename=" + "\"" + fileName + "\"");//把s1中的;改成:，就不会自动下载
                    copy(file, sOut, false);
                }
                sOut.close();
                break;
            }
            case 2:
            {
                System.out.println("----------------2");
                ServletOutputStream sOut = resp.getOutputStream();
                if(!copy(file, sOut, true)){
                    sOut.write(("you want download " + fileName + ", but not exist").getBytes());
                }else{
                    resp.setHeader("Content-Disposition", "attachment;filename=" + "\"" + fileName + "\"");//把s1中的;改成:，就不会自动下载
                    copy(file, sOut, false);
                }
                sOut.close();
            }
        }
        if(cnt == 0x7fffffff) cnt = 1;
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
