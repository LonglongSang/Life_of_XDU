package com.sang.database;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.concurrent.ConcurrentHashMap;

public class Patient implements Serializable {
    private int uid;            //userID
    private String name;        //姓名
    private String pass;        //密码
    private boolean isMale;     //男性则为true，女性则为false
    private String date;        //出生日期
    private boolean isDoctor;   //医生则为true，患者则为false
    private long lastSubmit;    //上一次提交每日填报的时间
    Patient(){

    }
    Patient(int uid, String name, String pass, boolean isMale, String date){
        this.uid = uid;
        this.name = name;
        this.pass = pass;
        this.isMale = isMale;
        this.date = date;
        this.isDoctor = false;
        this.lastSubmit = 10000;
    }
    private static final long serialVersionUID = 7249269246263182397L;
    private ArrayList<Integer> orders = new ArrayList<>();//存储所有属于该患者或医生的预约单单号

    /**
     * 将预约单单号sid加入到orders中
     * @param sid
     */
    public synchronized void put(int sid){
        orders.add(sid);
    }

    /**
     * 检查该患者今天是否还可以预约doctorUid的医生
     * @param doctorUid 想要预约的医生
     * @param forms 存储所有预约单信息的map
     * @return 可以预约返回true，不可以预约返回false
     */
    public synchronized boolean canBook(int doctorUid, ConcurrentHashMap<Integer, Form> forms){
        if(this.uid == doctorUid || this.isDoctor) return false;
        Form f;
        for(int n = orders.size(), i = n -1; i >= 0; i--){
            f = forms.get(orders.get(i));
            if(f != null && f.acquireDoctorUid() == doctorUid && util.sameDay(f.acquireOrderDate(), System.currentTimeMillis())) return false;
        }
        return true;
    }

    /**
     * 清空该患者或医生的所有预约信息
     */
    public void clearOrders(){
        orders.clear();
    }

    public int getAge() {
        return util.getAge(date);
        //return age;
    }
    public long acquiredLastSubmit(){
        return lastSubmit;
    }
    public void setLastSubmit(long a){
        this.lastSubmit = a;
    }

    public boolean getSubmitted() {
        return util.sameDay(System.currentTimeMillis(), this.lastSubmit);
    }

    public int acquireUid() {
        return uid;
    }
    public String getUid(){
        return String.valueOf(uid);
    }

    public String getName() {
        return name;
    }

    protected String getPass() {
        return pass;
    }

    public String getDate() {
        return date;
    }

    public String getSex() {
        return isMale ? "男" : "女";
    }
    public boolean getIsDoctor(){
        return isDoctor;
    }

    protected void setName(String name) {
        this.name = name;
    }

    protected void setPass(String pass) {
        this.pass = pass;
    }

    protected void setMale(boolean isMale) {
        this.isMale = isMale;
    }

    protected void setDate(String date) {
        this.date = date;
    }
    protected void setDoctor(boolean a){
        this.isDoctor = a;
    }
    protected ArrayList<Integer> getForms(){
        return orders;
    }
    protected synchronized void clearForms(){
        orders.clear();
    }

    @Override
    public String toString() {
        /**
         *     private int uid;
         *     private String name;
         *     private String pass;
         *     private boolean isMale;
         *     private String date;
         *     private boolean isDoctor;
         */
        return "uid: " + uid +"\tname: " + name + "\tpass: " + pass + "\tisMale: " + isMale + "\tdate: " + date + "\tisDoctor: " + isDoctor + "\tisSubmitted: " + util.sameDay(System.currentTimeMillis(), lastSubmit);
    }
}