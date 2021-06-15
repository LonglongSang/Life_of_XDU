package com.sang.database;

import javax.print.Doc;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.concurrent.ConcurrentHashMap;

public class Doctor extends Patient implements Serializable{
    public static int BUSY = 0;
    public static int WORKING = 1;
    private String department;//该医生所属部门
    private String background;//该医生的背景资料介绍
    private int restNum;//该医生剩余可预约名额
    private int status;//该医生的状态，Doctor.BUSY或Doctor.WORKING
    private static final long serialVersionUID = 7243261246761132397L;
    Doctor(){

    }
    Doctor(int uid, String name, String pass, boolean isMale, String date, String department, String background, int restNum,int status){
        super(uid, name, pass, isMale, date);
        this.department = department;
        this.background = background;
        this.restNum = restNum;
        this.status = status;
        setDoctor(true);
    }

    public String getBackground() {
        return background;
    }
    public String getDepartment(){
        return department;
    }
    public int getRestNum(){
        return restNum;
    }
    public int getStatus(){
        return status;
    }
    protected void setBackground(String background) {
        this.background = background;
    }
    protected void setDepartment(String department){
        this.department = department;
    }
    protected void setStatus(int status){
        this.status = status;
    }

    /**
     * 进行预约该医生的尝试，预约成功返回true，预约失败返回false
     * @return
     */
    protected synchronized boolean popRestNum(){
        if(restNum == 0) return false;
        restNum--;
        return true;
    }

    /**
     *
     * @return 完成预约单后的操作，将该医生的预约名额加1，如果成功返回true，失败返回false
     */
    protected synchronized boolean pushRestNum(){
        if(restNum == Integer.MAX_VALUE) return false;
        restNum++;
        return true;
    }

    protected synchronized void clearForms(ConcurrentHashMap<Integer, Form> formList) {
        if(formList == null) return;
        ArrayList<Integer> arr = getForms();
        Form f;
        for(int i = 0, n = arr.size(); i < n; i++){
            f = formList.get(arr.get(i));
            if(f != null && (f.getStatus() == Form.RUNNING || f.getStatus() == Form.WAIT)) pushRestNum();
        }
        super.clearForms();
    }

    @Override
    public String toString() {
        return super.toString()
                + "\tdepartment: " + department
                + "\tbackground: " + background
                + "\trestNum: " + restNum
                + "\tstatus: status";
    }
}
