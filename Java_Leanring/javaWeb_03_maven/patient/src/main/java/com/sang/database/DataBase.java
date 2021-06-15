package com.sang.database;
import javax.print.Doc;
import java.io.*;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

public class DataBase implements Serializable {
    DataBase(){

    }
    private static final long serialVersionUID = 7249269246763182397L;
    private final ConcurrentHashMap<Integer, Patient> patients = new ConcurrentHashMap<>();
    public final ConcurrentHashMap<Integer, Patient> doctors = new ConcurrentHashMap<>();
    private final ConcurrentHashMap<Integer, Form> formList = new ConcurrentHashMap<>();
    IdDistributionCentre idCentre = new IdDistributionCentre();
    private Patient[] doctorList = null;
    public static String fileName = "myDataBase.db";

    /**
     *  从文件filePath中读取DataBase的实例
     * @param filePath myDataBase.db持久化的文件地址
     * @return 一个DataBase实例，读取失败返回null
     */
    public static DataBase getDataBase(String filePath){
        if(filePath == null) return null;
        File file = new File(filePath);
        if(!file.exists()
                || !file.isFile()
                || !file.canRead()
                || !file.getName().equals(fileName)
        ){
            return null;
        }
        FileInputStream fIn = null;
        BufferedInputStream buffer = null;
        ObjectInputStream oIn = null;
        try {
            fIn = new FileInputStream(file);
            buffer = new BufferedInputStream(fIn);
            oIn = new ObjectInputStream(buffer);
            DataBase ans = (DataBase)oIn.readObject();
            oIn.close();
            buffer.close();
            fIn.close();
            return ans;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return null;
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     *
     * @return 返回一个默认的DataBase实例
     */
    public static DataBase getDataBase(){
        DataBase ans = new DataBase();
        //uid = 0
        ans.registerDoctor("田泽远", "1234", "男", "1998-04-01", "骨科", "专治骨科", 12, Doctor.WORKING);
        //uid = 1
        ans.registerDoctor("桑龙龙", "1234", "男", "1998-04-01", "耳鼻喉科", "10年治疗经验", 12, Doctor.WORKING);
        //uid = 2
        ans.registerDoctor("贾语璇", "1234", "女", "1998-04-01", "儿科", "儿科名师", 12, Doctor.WORKING);
        //uid = 3
        ans.registerDoctor("周杨", "1234", "男", "1998-04-01", "眼科", "光学使者", 12, Doctor.WORKING);

        //uid = 4
        ans.registerPatient("病人1号", "1234", "男", "1990-01-01");
        //uid = 5
        ans.registerPatient("病人2号", "1234", "女", "1990-01-01");

        ans.registerPatient("病人3号", "1234", "女", "1990-01-01");

        ans.orderDoctor(4, 0);
        ans.orderDoctor(5, 0);
        ans.orderDoctor(6, 0);
        ans.orderDoctor(4, 1);
        return ans;
    }

    /**
     * 将一个DataBase实例存储（持久化）到filePath文件夹中，并将一些提示输出到out中
     * @param filePath 文件夹地址
     * @param target DataBase实例
     * @param out 输出流
     * @return 持久化成功返回true，否则返回false
     */
    public static boolean storeToDisk(String filePath, DataBase target, PrintStream out){
        if(out == null) return false;
        PrintWriter o = new PrintWriter(out);
        boolean ret = storeToDisk(filePath, target, o);
        o.flush();
        return ret;
    }

    /**
     * 将一个DataBase实例存储（持久化）到filePath文件夹中，并将一些提示输出到out中
     * @param filePath 文件夹地址
     * @param target DataBase实例
     * @param out 输出流
     * @return 持久化成功返回true，否则返回false
     */
    public static boolean storeToDisk(String filePath, DataBase target, PrintWriter out){
        if(filePath == null || target == null) throw new NullPointerException("filePath or target is null");
        filePath = filePath + "/" + fileName;
        File file = new File(filePath);
        BufferedOutputStream buffer = null;
        FileOutputStream fO = null;
        ObjectOutputStream oO = null;
        if(!file.exists()) {
            out.println("file not exist\n");
            try {
                file.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
                out.println("create failed");
                return false;
            }
        }
        out.println("create success");
        try{
            fO = new FileOutputStream(file);
            buffer = new BufferedOutputStream(fO);
            oO = new ObjectOutputStream(buffer);
            oO.writeObject(target);
            return true;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            try{
                if(oO != null) oO.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            try{
                if(buffer != null) buffer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            try{
                if(fO != null) fO.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return false;
    }


    /**
     * 注册一个病人帐号，并返回注册成功后的user Id
     * @param name 注册人设置的姓名
     * @param pass 注册人设置的密码
     * @param sex 注册人设置的性别，必须为男或女
     * @param date 注册人设置的出生日期，格式必须为"yyyy-MM-dd"
     * @return 注册成功返回User ID，失败返回-1
     */
    public int registerPatient(String name, String pass, String sex, String date){
        if(!util.checkName(name) || !util.checkPass(pass) || !util.checkDate(date) || !util.checkSex(sex)) return -1;
        try {
            int uid = idCentre.getNextUid();
            Patient p = new Patient(uid, name, pass, sex.equals("男"), date);
            patients.put(uid, p);
            return uid;
        } catch (UnFormatException e) {
            e.printStackTrace();
            return -1;
        }
    }

    /**
     * 注册一个医生账号，并返回注册成功后的user Id
     * @param name 医生的姓名
     * @param pass 医生的密码
     * @param sex 医生的性别，必须为"男"或"女"
     * @param date 医生的出生日期，格式必须为"yyyy-MM-dd"
     * @param department 医生的部门
     * @param background 医生的背景资料
     * @param restNum 医生初试的预约名额，>0
     * @param status 医生当前的状态，为Doctor.WORKING或Doctor.BUSY
     * @return
     */
    public int registerDoctor(String name, String pass, String sex, String date, String department, String background, int restNum, int status){
        if(!util.checkName(name)
                || !util.checkPass(pass)
                || !util.checkSex(sex)
                || !util.checkDate(date)
                || department == null
                || department.length() == 0
                || restNum <= 0
                || (status != Doctor.BUSY && status != Doctor.WORKING)
        ) return -1;
        if(background == null) background = "null";
        int uid;
        try{
            uid = idCentre.getNextUid();
            Doctor d = new Doctor(uid, name, pass, sex.equals("男"), date, department, background, restNum, status);
            doctors.put(uid, d);
            return uid;
        } catch (UnFormatException e) {
            e.printStackTrace();
            return -1;
        }

    }

    /**
     * 医生或者病人登录，如果登录成功，返回登陆者的实例
     * @param uid 登录人的uid
     * @param pass 登录人的密码
     * @return 登录失败返回 null， 登陆成功返回Patient实例
     */
    public Patient login(int uid, String pass){
        Patient p = patients.get(uid);
        if(p != null && p.getPass().equals(pass)){
            return p;
        }
        p = doctors.get(uid);
        if(p != null && p.getPass().equals(pass)){
            return p;
        }
        return null;
    }

    /**
     * 获得userID 为 patientUid的患者实例
     * @param patientUid 患者userID
     * @return 获得成功返回实例，失败返回null
     */
    public Patient acquirePatient(int patientUid){
        Patient p = patients.get(patientUid);
        if(p == null) p = doctors.get(patientUid);
        return p;
    }

    /**
     * 获得UserID为 doctorUid的医生实例
     * @param doctorUid 医生的userID
     * @return 获得成功返回实例，失败返回null
     */
    public Patient acquireDoctor(int doctorUid){
        return doctors.get(doctorUid);
    }

    /**
     * 修改信息
     * userID为uid的用户（医生或患者）想要修改个人信息为pass，name，sex和date
     * @param uid 用户id
     * @param pass 用户新的密码
     * @param name 用户新的名字
     * @param sex 用户新的性别
     * @param date 用户新的出生日期
     * @return 修改成功返回true， 修改失败返回false
     */
    public boolean setInfo(int uid, String pass, String name, String sex, String date){
        Patient p = patients.get(uid);
        if(p == null) p = doctors.get(uid);
        if(p == null) return false;
        if(util.checkName(name)) p.setName(name);
        if(util.checkSex(sex)) p.setMale(sex.equals("男"));
        if(util.checkPass(pass)) p.setPass(pass);
        if(util.checkPass(date)) p.setDate(date);
        return true;
    }

    /**
     * 检查userID为uid的用户今日是否已经提交过每日填报
     * @param uid 用户的uid
     * @return uid用户如果提交过今日的每日填报，则返回true
     */
    public boolean isSubmitted(int uid){
        Patient p = patients.get(uid);
        if(p == null) p = doctors.get(uid);
        if(p == null) return false;
        return p.getSubmitted();
    }

    /**
     *
     * 修改userID为uid的用户上次提交每日填报的时间为当前时间
     * @param uid
     * @return 修改成功返回true，失败返回false
     */
    public boolean setSubmitTime(int uid){
        Patient p = patients.get(uid);
        if(p == null) p = doctors.get(uid);
        if(p == null) return false;
        p.setLastSubmit(System.currentTimeMillis());
        return true;
    }

    /**
     * 更新doctorList变量
     */
    private void updateDoctorList(){
        doctorList = new Patient[doctors.size()];
        Iterator<Map.Entry<Integer, Patient>> it = doctors.entrySet().iterator();
        int cnt = 0;
        while(it.hasNext()){
            doctorList[cnt++] = it.next().getValue();
        }
    }

    /**
     *
     * @return 返回医生列表实例
     */
    public Patient[] doctorsList(){
        if(doctorList == null || doctorList.length != doctors.size()) updateDoctorList();
        return doctorList;
    }

    /**
     * 检查userID为uid的用户是否是医生
     * @param uid 用户userID
     * @return 是否为医生
     */
    public boolean isDoctor(int uid){
        return doctors.containsKey((Integer)uid);
    }

    /**
     * 检查userID为uid的用户是否为患者
     * @param uid 用户userID
     * @return 是否为患者
     */
    public boolean isPatient(int uid){
        return patients.containsKey(uid);
    }

    /**
     * 患者patientUid预约医生doctorUid，限制医生不能预约
     * @param patientUid 患者userID
     * @param doctorUid 医生的userID
     * @return 预约成功返回一个预约单（Form）实例，失败返回null
     */
    public Form orderDoctor(int patientUid, int doctorUid){
        Doctor doctor = (Doctor)doctors.get(doctorUid);
        Patient patient = patients.get(patientUid);
        int sid;
        if(patientUid == doctorUid //patientUid和doctorUid不能一样
                || patient == null || doctor == null) return null;
        synchronized (patient){
            if(patient.canBook(doctorUid, formList)){
                if(doctor.popRestNum() == false) return null;//该医生没有剩余名额可以预定,synchronized方法
                try {
                    sid = idCentre.getNextSid();//有可能出现获得不了预约号
                } catch (UnFormatException e) {
                    e.printStackTrace();
                    return null;
                }
                Form f = new Form(sid, patientUid, doctorUid, Form.WAIT);
                doctor.put(sid);
                patient.put(sid);
                formList.put(sid, f);
                return f;
            }else{
                return null;
            }
        }
    }

    /**
     * userID为patientUid的患者取消自己的预约单号为sid的预约
     * @param patientUid 患者的userID
     * @param sid 患者想要取消的预约单单号
     * @return 取消预约成功返回true，失败返回false
     */
    public boolean cancelOrder(int patientUid, int sid){
        Form f = formList.get(sid);
        Patient patient = patients.get(patientUid);
        if(patient == null) patient = doctors.get(patientUid);

        if(patient == null                          //病人不包含patientId
                || f == null                        //不包含该表单
                || f.acquirePatientUid() != patientUid  //该表单并不属于PatientUid
                || f.getStatus() == Form.CANCEL     //该表单已经被取消过
                || f.getStatus() == Form.FINISH     //该表单已经完成
        ){
            return false;
        }else{
            Doctor doctor = (Doctor)doctors.get(f.acquireDoctorUid());
            synchronized (f){
                f.setStatus(Form.CANCEL);
            }
            doctor.pushRestNum();//synchronized方法
            return true;
        }
    }

    /**
     * userID为uid的患者获得自己的所有预约单，或者userID为uid的医生获得所有预约自己的预约单
     * @param uid 患者或医生给的userID
     * @return 获得成功获得Form[]，失败返回null
     */
    public Form[] getOrderList(int uid){
        Patient a = patients.get(uid);
        if(a == null) a = doctors.get(uid);
        if(a == null) return null;
        synchronized (a){
            ArrayList<Integer> arr = a.getForms();
            Form[] ans = new Form[arr.size()];
            for(int i = 0, n = arr.size(); i < n; i++) ans[i] = formList.get(arr.get(i));
            return ans;
        }
    }

    /**
     * userId为doctorUid的医生完成对预约单单号为sid的预约单的诊断
     * @param doctorUid 医生userID
     * @param sid 预约单的单号
     * @return 诊断成功返回true，诊断失败返回false
     */
    public boolean diagnose(int doctorUid, int sid){
        Doctor doctor = (Doctor)doctors.get(doctorUid);
        Form f = formList.get(sid);
        if(doctor == null                       //该医生不存在
                || f == null                    //该表单不存在
                || f.acquireDoctorUid() != doctorUid//该表单不属于该医生
                || f.getStatus() == Form.CANCEL //该表单为取消状态
                || f.getStatus() == Form.FINISH //该表单为完成状态
        ){
            return false;
        }else{
            synchronized (f){
                f.setStatus(Form.FINISH);
            }
            doctor.pushRestNum();//synchronized方法
            return true;
        }
    }
    private void print(ConcurrentHashMap<Integer, Patient> arr, PrintWriter out){
        if(arr == null || out == null) return;
        Iterator<Map.Entry<Integer, Patient>> it = arr.entrySet().iterator();
        while(it.hasNext()){
            Patient a = it.next().getValue();
            out.println(a);
        }
    }
    private void print(ConcurrentHashMap<Integer, Form> arr, PrintWriter out ,int a){
        if(arr == null || out == null) return;
        Iterator<Map.Entry<Integer, Form>> it = arr.entrySet().iterator();
        while(it.hasNext()){
            out.println(it.next().getValue());
        }
    }
    public void printAll(PrintWriter out){
        if(out == null) return;
        out.format("病人所有信息：\n");
        print(patients, out);
        out.format("\n\n\n");
        out.format("医生所有信息\n");
        print(doctors, out);
        out.format("\n\n\n");
        out.format("预约所有信息:\n");
        print(formList, out, 1);
        out.flush();
    }
    public void printAll(OutputStream out){
        if(out == null) return;
        PrintWriter o1 = new PrintWriter(out);
        printAll(o1);
    }
    public void clearAllForms(){
        Iterator<Map.Entry<Integer, Patient>> it = patients.entrySet().iterator();
        while(it.hasNext()){
            it.next().getValue().clearForms();
        }

        Iterator<Map.Entry<Integer, Patient>> it1 = doctors.entrySet().iterator();
        while(it1.hasNext()){
            ((Doctor)it1.next().getValue()).clearForms(formList);
        }
        formList.clear();
    }
    public void clearAllPatients(){
        clearAllForms();
        patients.clear();
    }

}
