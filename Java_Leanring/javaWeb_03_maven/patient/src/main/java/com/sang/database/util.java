package com.sang.database;

import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class util {


    private static final int[] monthNum = new int[]{0,31,28,31,30,31,30,31,31,30,31,30,31};
    private static final String male = "男";
    private static final String female = "女";

    /**
     *
     * @param name 姓名内容
     * @return 检查名字是否符合规范
     */
    public static boolean checkName(String name){
        return name != null && name.length() > 0 && name.length() <= 16;
    }
    /**
     *
     * @param pass 密码内容
     * @return 检查密码是否符合规范
     */
    public static boolean checkPass(String pass){
        return checkName(pass);
    }
    /**
     * @param year 年份
     * @return 检查year是否为闰年
     *
     */
    public static boolean isLeapYear(int year){
        return year >= 0 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    }
    /*
    public static boolean checkDate(String Date){
        //格式必须为1998-02-12
        if(Date == null || Date.length() != 10) return false;
        int year = 0, month = 0, day = 0;
        for(int i = 0; i < 4; i++){
            if(!Character.isDigit(Date.charAt(i))) return false;
            year = year * 10 + (int)(Date.charAt(i) - '0');
        }
        if(year < 1900 || year > 2021) return false;
        for(int i = 5; i < 7; i++){
            if(!Character.isDigit(Date.charAt(i))) return false;
            month = month * 10 + (int)(Date.charAt(i) - '0');
        }
        if(month < 1 || month > 12) return false;
        for(int i = 8; i < 10; i++){
            if(!Character.isDigit(Date.charAt(i))) return false;
            day = day * 10 + (int)(Date.charAt(i) - '0');
        }
        if(month == 2){
            return 1 <= day && day <= (monthNum[2] + (isLeapYear(year) ? 1 : 0));
        }else{
            return 1 <= day && day <= monthNum[month];
        }
    }
     */

    /**
     *
     * @param sex 性别
     * @return 检查sex内容是否为"男" 或 "女"其中之一
     */
    public static boolean checkSex(String sex){
        return sex != null && sex.length() == 1 && (sex.equals(male) || sex.equals(female));
    }

    /**
     *
     * @param a a和b均为System.currentTimeMillis()的返回值
     * @param b a和b均为System.currentTimeMillis()的返回值
     * @return 检查a和b两个时间点是否属于同一天
     */
    public static boolean sameDay(long a, long b){

        SimpleDateFormat s = new SimpleDateFormat("yyyy-MM-dd");
        String x1 = s.format(new Date(a));
        String y1 = s.format(new Date(b));
        return x1.equals(y1);
    }

    private static List<Integer> Today(){
        List<Integer> now_Date = new ArrayList<Integer>(5);

        LocalDate today = LocalDate.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        String nowDate = today.format(formatter);

        int years,months,days;
        years = Integer.parseInt(nowDate.substring(0, 4));
        months = Integer.parseInt(nowDate.substring(5, 7));
        days = Integer.parseInt(nowDate.substring(8,10));

        now_Date.add(years);
        now_Date.add(months);
        now_Date.add(days);

        return now_Date;
    }

    /**
     *
     * @param Date 日期
     * @return 检查Date是否符合格式"yyyy-MM-dd"，符合返回true，不符合返回false
     */
    public static boolean checkDate(String Date) {
        //初始化
        int year = 0, month = 0, day = 0;
        //int[] monthNum = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        //当前时间
        List<Integer> now_Date = new ArrayList<Integer>(5);
        now_Date = Today();

        int years,months,days;
        years = now_Date.get(0);
        months = now_Date.get(1);;
        days = now_Date.get(2);;

        //格式
        if(Date.isEmpty())return false;
        int len = Date.length();
        if (len != 10) return false;
        for (int i = 0; i < len; ) {
            if ((i == 4 || i == 7) & Date.charAt(i) == '-') {
                i++;
            } else if (Date.charAt(i) >= '0' && Date.charAt(i) <= '9') {
                i++;
            } else {
                return false;
            }
        }
        //数值
        year = Integer.parseInt(Date.substring(0, 4));
        month = Integer.parseInt(Date.substring(5, 7));
        day = Integer.parseInt(Date.substring(8,10));


        if (year < 1900 || year >= years+1) {
            return false;
        }else if(year == years){
            if (month >= 1 & month < months){
                if (month == 2) {
                    if (year % 4 == 0 || year % 100 == 0) {
                        return day >= 1 & day <= 29;
                    }else{
                        return day >= 1 & day <= 28;
                    }
                } else {
                    return day >= 1 & day <= monthNum[month];
                }
            }else if(month == months){
                return day >= 1 & day <= days;
            }else {
                return false;
            }
        } else {
            if (month >= 1 & month <= 12) {
                if (month == 2) {
                    if (year % 4 == 0 || year % 100 == 0) {
                        return day >= 1 & day <= 29;
                    }else{
                        return day >= 1 & day <= 28;
                    }
                } else {
                    return day >= 1 & day <= monthNum[month];
                }
            } else {
                return false;
            }
        }

    }


    /**
     *
     * @param Date 格式为"yyyy-MM-dd"
     * @return 返回出生日期为Date的年龄
     */
    public static int getAge(String Date){
        List<Integer> now_Date = new ArrayList<Integer>(5);
        now_Date = Today();

        if(Date.isEmpty())return 0;
        int age=0,year=0,month=0,day=0;

        if(!checkDate(Date)){
            return 0;
        }else{
            year = Integer.parseInt(Date.substring(0, 4));
            month = Integer.parseInt(Date.substring(5, 7));
            day = Integer.parseInt(Date.substring(8,10));

            age = now_Date.get(0) - year;
            if(month >= now_Date.get(1) & day > now_Date.get(2)){
                age-=1;
            }
            return age;
        }
    }
}
