package com.sang.serlet02;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class __02_dispatcher extends HttpServlet {
    private int cnt = 0;
    static String codeContent = "import javax.servlet.ServletContext;\n" +
            "import javax.servlet.ServletException;\n" +
            "import javax.servlet.http.HttpServlet;\n" +
            "import javax.servlet.http.HttpServletRequest;\n" +
            "import javax.servlet.http.HttpServletResponse;\n" +
            "import java.io.IOException;\n" +
            "import java.io.PrintWriter;\n" +
            "\n" +
            "public class __02_dispatcher extends HttpServlet {\n" +
            "    private int cnt = 0;\n" +
            "    @Override\n" +
            "    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {\n" +
            "        ServletContext context = this.getServletContext();\n" +
            "        PrintWriter pW = resp.getWriter();\n" +
            "        switch (cnt++ % 2){\n" +
            "            case 0:\n" +
            "            {\n" +
            "                pW.write(\"这个页面用于测试RequestDispatcher，这次访问并不会进行转发，下次访问将会进行转发，转发到网页/contextParam\");\n" +
            "                pW.write(\"\\n\\n\\n代码如下:\\n\");\n" +
            "\n" +
            "\n" +
            "                break;\n" +
            "            }\n" +
            "            case 1:\n" +
            "            {\n" +
            "                RequestDispatcher rD = context.getRequestDispatcher(\"/contextParam\");\n" +
            "                rD.forward(req, resp);\n" +
            "                /*\n" +
            "                context.getRequestDispatcher(\"/contextParam\").forward(req, resp);\n" +
            "                 */\n" +
            "            }\n" +
            "        }\n" +
            "        if(cnt == 0x7fffffff) cnt = 1;\n" +
            "    }\n" +
            "    @Override\n" +
            "    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {\n" +
            "        doGet(req, resp);\n" +
            "    }\n" +
            "}\n";
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        ServletContext context = this.getServletContext();
        resp.setCharacterEncoding("utf-8");
        //resp.setContentType("text/html;charset=UTF-8");
        PrintWriter pW = resp.getWriter();
        switch (cnt++ % 2){
            case 0:
            {
                pW.write("这个页面用于测试RequestDispatcher，这次访问并不会进行转发，下次访问将会进行转发，转发到网页/contextParam");
                pW.write("\n\n\n代码如下:\n");
                pW.write(codeContent);
                break;
            }
            case 1:
            {
                RequestDispatcher rD = context.getRequestDispatcher("/contextParam");
                rD.forward(req, resp);
                /*
                context.getRequestDispatcher("/contextParam").forward(req, resp);
                 */
            }
        }
        if(cnt == 0x7fffffff) cnt = 1;
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
