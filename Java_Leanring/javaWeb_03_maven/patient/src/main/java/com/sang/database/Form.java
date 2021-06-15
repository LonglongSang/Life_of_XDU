package com.sang.database;

import java.io.Serializable;
import java.util.Date;

public class Form implements Serializable {
    private static final long serialVersionUID = 3249261246761182397L;
    public static int WAIT = 0;
    public static int RUNNING = 1;
    public static int FINISH = 2;
    public static int CANCEL = 3;
    private int sid;//该预约单的单号
    private int patientUid;//进行预约的患者的userID
    private int doctorUid;//预约的医生的userID
    private int status;//0等待中，1进行中，2完成，3取消，可能的值为Form.WAIT,Form.RUNNING，Form.FINISH，Form.CANCEL
    private long orderDate;//预约时间
    Form(int sid, int patientUid, int doctorUid, int status){
        this.sid = sid;
        this.patientUid = patientUid;
        this.doctorUid = doctorUid;
        this.status = status;
        this.orderDate = System.currentTimeMillis();
    }
    public int getSid(){
        return sid;
    }
    public int acquirePatientUid(){
        return patientUid;
    }
    public int acquireDoctorUid(){
        return doctorUid;
    }
    public String getPatientUid(){
        return String.valueOf(patientUid);
    }
    public String getDoctorUid(){
        return String.valueOf(doctorUid);
    }
    public int getStatus(){
        return status;
    }
    public long acquireOrderDate(){
        return orderDate;
    }
    public String getOrderDate(){
        return (new Date(acquireOrderDate())).toLocaleString();
    }
    public synchronized void setStatus(int status){
        this.status = status;
    }
    @Override
    public String toString() {
        return "sid: " + sid + "\tpatientUid:  " + patientUid + "\tdoctorUid: " + doctorUid + "\tstatus: " + status + "\torderDate: " + (new Date(orderDate).toLocaleString());
    }
}
