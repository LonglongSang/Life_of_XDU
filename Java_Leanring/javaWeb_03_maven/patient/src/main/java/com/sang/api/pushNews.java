package com.sang.api;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class pushNews extends HttpServlet {
    static String news = "  {\n" +
            "    \"code\": 1,\n" +
            "    \"data\": [\n" +
            "      {\n" +
            "        \"title\": \"最近广州疫情反复\",\n" +
            "        \"date\": \"2021-6-1\",\n" +
            "        \"content\": \"最近广州疫情反复，请注意！！！！！！！！！！！！！\",\n" +
            "        \"from\": \"中国xx网\"\n" +
            "      },\n" +
            "      {\n" +
            "        \"title\": \"接种疫苗\",\n" +
            "        \"date\": \"2021-6-2\",\n" +
            "        \"content\": \"最近大部分人群开始接种疫苗第一针或接种第二针，未接种的抓紧时间\",\n" +
            "        \"from\": \"中国xx网\"\n" +
            "      }\n" +
            "    ]\n" +
            "  }";
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSetOptions(req, resp);
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        util.initResponseSet(req, resp);
        PrintWriter pW = resp.getWriter();
        pW.format("%s", news);
        pW.close();
    }
}
