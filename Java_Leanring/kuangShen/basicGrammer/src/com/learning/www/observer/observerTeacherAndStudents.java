package com.learning.www.observer;
import java.io.*;
import java.util.*;

/**
 *  使用观察者模式模拟课堂
 *    在Java学习班中有一个老师，有许多学生。老师是观察者模式中的主题（Subject）,学生是观察者模式中的观察者（Observer）。老师为学生们讲课，传授知识；学生可以一字不差的吸收老师讲的内容（以String形式存在），并可以一字不差的复述老师在课堂上讲的内容。
 *     具体要求如下：
 * (1). 实现老师类（Teacher）、学生类（Student）、主题接口（Subject）、观察者接口（Observer）、测试类Test；
 * (2). 老师讲授的Java课程可以被学生选课(registerObserver())、被学生退课(removeObserver())、课程内容通过ontifyObservers()方法传授给所有选课的学生；
 * (3). 老师讲授的内容通过从文本文件中读取，在Test类中操作老师实例读取文本文件中的知识。老师将读取到的知识传授给选课的学生；
 * (4). 学生可以将学到的知识记下来(保存到对应学生名的文本文件中)，在需要的时候（考试、提问）进行展示；
 * (5). 在Test类中可以创建需要的参数，提供相应的操作菜单：上课(classTime())、考试(examine())、提问(classroomQuestioning)、学生选课(registerCourse())、学生退课(dropCourse());
 * (6). 考试方法中学生展学到的全部知识，可以通过传递一些知识掌握情况、考试时状态等参数，返回相应的考试成绩；
 * (7). 提问方法中选定学生，传入关键词，展示该学生学到的相关知识；
 * (8). 考试应当在程序的下一次运行时进行（在程序结束运行后，应当能够保存学生信息、学生学到的知识、学生与老师的关系；在下一次运行时能够顺利恢复上次运行时建立的对象实体，以及他们之间的关系，然后进行相应的考试操作）；
 * (9). 可以自定义异常类，并在合适的位置使用异常处理机制。
 */
//主题接口
abstract class Subject{
    public abstract void registerObserver(Observer o1);
    public abstract boolean removeObserver(Observer o1);
    public abstract int notifyObservers(String knowledge);
    public abstract int getId();
}
//观察者接口
abstract class Observer{
    public abstract int learning(String knowLedge);
    public abstract int getId();
}

//javaTeacher， java教师类，继承Subject抽象类，以及Serializable（为实现写入文件序列化）
class javaTeacher extends Subject implements Serializable{
    private int teacherId;//教师的id
    public HashSet<String> content;//掌握的知识
    public HashSet<Observer> observers;//观察者
    javaTeacher(int teacherId){
        this.teacherId = teacherId;
        this.content = new HashSet<>();
        this.observers = new HashSet<>();
    }

    //将Observer o1加入到观察者中
    @Override
    public void registerObserver(Observer o1){
        if(o1 == null) throw new NullPointerException("public void registerObserver(Object o1), o1 is null");
        else this.observers.add(o1);
    }
    //将Observer o1从观察中移除
    @Override
    public boolean removeObserver(Observer o1){
        //移除学生o1
        if(o1 == null) return false;
        if(!this.observers.contains(o1)) return false;
        else this.observers.remove(o1);
        return true;
    }
    //通知观察者们
    @Override
    public int notifyObservers(String knowledge) {
        //传授知识knowledge
        int cnt = 0;
        for(Iterator<Observer> it = this.observers.iterator(); it.hasNext();){
            cnt += it.next().learning(knowledge);//观察者反应
        }
        return cnt;
    }
    //获得观察者/学生的数量
    public int getStudentNumber(){
        return this.observers.size();
    }
    //获得教师id
    @Override
    public int getId(){
        return this.teacherId;
    }
}

//Student类，继承Observer和Serializable接口
class Student extends Observer implements Serializable{
    private javaTeacher myJavaTeacher;//观察者观察的东西
    private int studentId;//学生ID
    //private javaTeacher myJavaTeacher;
    private HashSet<String> learnedKnowledge;
    private int intelligence;
    Student(int studentId, int intelligence){
        this.studentId = studentId;
        this.myJavaTeacher = null;
        this.learnedKnowledge = new HashSet<>();
        if(intelligence > 100) intelligence = 100;
        if(intelligence < 0) intelligence = 10;
        this.intelligence = intelligence;
    }
    @Override
    public int learning(String knowledge) {
        //该学生，学习知识knowledge
        int flo = 30;
        int limit = 70;
        if(knowledge != null){
            /**
             * 假设学生的智力为intelligence，则他们的智力表现浮动为x = [intelligence - flo + intelligence + flo]
             * 该学生学习该知识时，当 x >= limit，他会学习会该知识，否则学习该知识失败
             */
            if(this.learnedKnowledge.contains(knowledge)) return 1;//已经学过这个知识了
            Random r = new Random();
            int error = r.nextInt(flo * 2 + 1) - flo;
            error += this.intelligence;
            if(error >= limit){
                this.learnedKnowledge.add(knowledge);
                return 1;
            }else{
                return 0;
            }
        }
        return 0;
    }
    //退课dropOut
    public void dropCourse(){
        if(myJavaTeacher != null){
            try{
                myJavaTeacher.removeObserver(this);
                learnedKnowledge.clear();//既然退课，该学生就把所有学到的东西都删除
                myJavaTeacher = null;
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }
    //选课
    public boolean registerCourse(javaTeacher teacher){
        if(this.myJavaTeacher != null) return false;
        else if(teacher == null) throw new NullPointerException("your want choose a java teacher who is not exist");
        else{
            this.myJavaTeacher = teacher;
            teacher.registerObserver(this);
            return true;
        }
    }
    //获得学生id
    @Override
    public int getId(){
        return this.studentId;
    }
    //获得教授该学生老师的id，如果该学生未选课，则返回-1
    public int getTeacherId(){
        return myJavaTeacher == null ? -1 : myJavaTeacher.getId();
    }
    //计算该学生java分数，通过其学习到的知识，占教授其课程老师的所有知识的百分比进行计算得分
    public int getGrade(){
        if(this.myJavaTeacher == null) return 0;
        HashSet<String> content = this.myJavaTeacher.content;
        int cnt = 0;
        for(Iterator<String> it = this.learnedKnowledge.iterator(); it.hasNext();){
            if(content.contains(it.next())) cnt++;
        }
        return (int)((double)cnt / content.size() * 100);
    }
    //返回该学生是否学会了knowledge这个知识
    public boolean isLearned(String knowledge){
        return learnedKnowledge.contains(knowledge);
    }

}


/**
 * 测试类:
 * 数据产生：
 * 测试类可以有两种方式产生测试用的Student和javaTeacher实例
 *  1、随机产生
 *  2、输入一个文件件，从该文件夹中读入Student（后缀名.student）和javaTeacher（后缀名.teacher）的Object文件
 *
 * 之后运行规定的功能
 *
 * 数据输出：
 * 可选项，如果选则将当前数据输出，请输入一个不包含后缀名为.student和.teacher文件的文件夹，
 * 将会通过ObjectOutputStream进行输出，下次可再进行读入
 */
class Test{
    public List<Object> teacherList;//拥有的老师javaTeacher
    public List<Object> studentsList;//拥有的学生
    public static String teacherFileSuffix = "teacher";
    public static String studentFileSuffix = "student";
    private PrintStream out;//输出流
    Test(){
        teacherList = new ArrayList<>();
        studentsList = new ArrayList<>();
        out = System.out;
    }


    //选课
    private void registerCourse(){
        out.format("----------------registerCourse----------------\n");
        Student s;
        Random r = new Random();
        int teacherSize = teacherList.size();
        boolean success;
        javaTeacher t;
        for(Object o1: studentsList){
            s = (Student)o1;
            try{
                t = (javaTeacher)teacherList.get(r.nextInt(teacherSize));
                success = s.registerCourse(t);
                out.format("student %d register to teacher %d", s.getId(), t.getId());
                if(success) out.format(" success\n");
                else out.format(" failed\n");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        out.format("----------------registerCourse End----------------\n\n\n\n");
    }

    //--------------------功能区域-----------------------

    //上课
    private void classTime(javaTeacher teacher){
        if(teacher == null) return;
        out.format("----------------classTime----------------\nteacher is %d, he/she have %d student\n", teacher.getId(),teacher.getStudentNumber());
        if(teacher.getStudentNumber() == 0) {
            out.format("classTime end\n");
            return;
        }
        int cnt;
        String knowledge;
        for(Iterator<String> it = teacher.content.iterator(); it.hasNext();){
            knowledge = it.next();
            cnt = teacher.notifyObservers(knowledge);//传授知识
            out.format("teacher %d teacher %s, %d / %d learned\n", teacher.getId(), knowledge, cnt, teacher.getStudentNumber());
        }
        out.format("----------------classTime End----------------\n\n\n\n");
    }

    //老师teacher向他的学生们进行提问，提问次数限制为questionLimit次
    private void classroomQuestioning(javaTeacher teacher, int questionLimit){
        out.format("----------------classroomQuestioning----------------\nteacher is %d, he/she have %d student\n", teacher.getId(),teacher.getStudentNumber());
        if(teacher.getStudentNumber() == 0){
            out.format("----------------classroomQuestioning End----------------\n\n\n\n");
            return;
        }
        int questioned = 0;
        Random r = new Random();
        int i = 0, size = teacher.observers.size();
        Student s;
        String knowledge;
        Student[] studentsArr = new Student[size];
        for(Iterator<Observer> it = teacher.observers.iterator(); it.hasNext();){
            studentsArr[i++] = (Student)it.next();
        }
        for(Iterator<String> it = teacher.content.iterator(); it.hasNext() && questioned < questionLimit;){
            knowledge = it.next();
            if(r.nextInt(3) <= 1){
                s = studentsArr[r.nextInt(size)];
                out.format("teacher %d question student %d knowledge:[ %s ]", teacher.getId(), s.getId(), knowledge);
                if(s.isLearned(knowledge)) out.format(", and he/she answer is right\n");
                else out.format(", but he/she answer is bad\n");
                questioned++;
            }
        }
        out.format("----------------classroomQuestioning End----------------\n\n\n\n");

    }
    //对teacher的学生进行考试
    private void examine(javaTeacher teacher){
        if(teacher == null) return;
        out.format("----------------examine----------------\nteacher is %d, he/she have %d student\n", teacher.getId(),teacher.getStudentNumber());
        if(teacher.getStudentNumber() == 0) {
            out.format("examine end\n");
            return;
        }
        Student s;
        for(Iterator<Observer> it = teacher.observers.iterator(); it.hasNext();){
            s = (Student)it.next();
            out.format("student %d get grade: %d\n", s.getId(), s.getGrade());
        }
        out.format("----------------examine End----------------\n\n\n\n");
    }
    //退课
    private void dropCourse(){
        out.format("----------------dropCourse----------------\n");
        Student s;
        Random r = new Random();
        int dropped = 0;
        int dropLimit = 2;
        for(Iterator<Object> it = studentsList.iterator(); it.hasNext() && dropped < dropLimit;){
            s = (Student)it.next();
            if(r.nextInt(5) <= 1){
                s.dropCourse();
                out.format("student %d dropCourse\n", s.getId());
                dropped++;
            }
        }
        out.format("----------------dropCourse End----------------\n\n\n\n");
    }

    //模拟控制
    private void simulation(){
        Random r = new Random();
        registerCourse();//学生注册
        javaTeacher t;
        for(int i = 0, n= 2 + r.nextInt(3); i < n; i++){
            for(Object o1: teacherList){
                t = (javaTeacher)o1;
                classTime(t);//教师上课
                if(r.nextInt(2) == 0) classroomQuestioning(t, 2);//教师提问
            }
        }
        for(Object o1:teacherList){
            t = (javaTeacher)o1;
            examine(t);//考试
        }
        dropCourse();//学生退课
    }
    //--------------------功能区域 结束-----------------------


    //--------------------测试类主控台---------------------
    public void run(){
        Scanner sc = new Scanner(System.in);

        String typ;
        boolean good = false;
        boolean leave = false;
        while(!good && !leave){
            System.out.println("Do you want load data from dist(input for 1), or generate test data(input 2), and 3 for leave");
            typ = sc.nextLine();
            good = true;
            try{
                if(Integer.parseInt(typ) == 1){
                    System.out.println("please input your absolute path");
                    String dir = sc.nextLine();
                    loadFromDist(dir);
                }else if(Integer.parseInt(typ) == 2){
                    generateData(3, 20);
                }else if(Integer.parseInt(typ) == 3){
                     leave = true;
                }else{
                    throw new Exception("bad input");
                }
            }catch (Exception e){
                e.printStackTrace();
                good = false;
            }
        }
        if(leave) return;
        simulation();//进行模拟
        good = false;
        while(!good && !leave){
            System.out.format("do you want save data to dist, 1 for yes, 2 for leave\n");
            good = true;
            typ = sc.nextLine();
            try{
                if(Integer.parseInt(typ) == 1){
                    System.out.println("please input your path");
                    String path = sc.nextLine();
                    writeIntoDist(path);
                }else if(Integer.parseInt(typ) == 2){
                    leave = true;
                }else{
                    throw new Exception("bad input\n");
                }
            }catch (Exception e){
                e.printStackTrace();
                good = false;
            }
        }
    }
    //--------------------测试类主控台 结束---------------------





    //-------------------输入区域--------------------

    //随机产生n个javaTeacher对象和m个Student对象
    private void generateData(int n, int m){
        javaTeacher t;
        Random r = new Random();
        int q;
        for(int i = 0; i < n; i++){
            t = new javaTeacher(i);
            q =r.nextInt(10);
            for(int j = 0; j < q; j++) t.content.add("Knowledge-" + j);
            teacherList.add(t);
        }
        for(int i = 0; i < m; i++){
            studentsList.add(new Student(i, 50 + r.nextInt(60)));
        }
    }
    private interface Lambda{
        void func(String suffix, List<Object> tar) throws IOException, ClassNotFoundException;
    }
    private interface Lambda1{
        Object getObject(File file) throws IOException, ClassNotFoundException;
    }
    //从directory表示的路径中的.student和.teacher数据
    private void loadFromDist(String directory) throws Exception {
        File dir = new File(directory);
        if(!dir.exists()) throw new Exception("load from " + dir.getAbsolutePath() + " but not exist");
        Lambda1 func0 = (file)->{
            if(!file.exists() || file.isDirectory() || !file.canRead()) return null;
            FileInputStream fInput = new FileInputStream(file);
            BufferedInputStream buffered = new BufferedInputStream(fInput);
            ObjectInputStream oInput = new ObjectInputStream(fInput);
            Object ret = oInput.readObject();
            oInput.close();
            buffered.close();
            fInput.close();
            return ret;
        };
        Lambda func1 = (suffix, tar)->{
            File[] arr = dir.listFiles();
            if(arr == null) return;
            for(File i: arr){
                String name = i.getName();
                int last = name.lastIndexOf('.');
                if(last == -1) continue;
                if(name.substring(last + 1).compareTo(suffix) == 0){
                    tar.add(func0.getObject(i));
                }
            }
        };
        func1.func(teacherFileSuffix, teacherList);
        func1.func(studentFileSuffix, studentsList);
    }
    //-------------------输入区域 结束--------------------





    //---------------------输出区域------------------------

    //检查文件夹下是否有后缀名为suffix的文件
    private boolean haveSuffixInDir(File dir, String suffix){
        if(dir == null) return false;
        File[] arr = dir.listFiles();
        if(arr == null) return false;
        String name;
        int index;
        for(File i: arr){
            if(i.isFile()){
                name = i.getName();
                index = name.lastIndexOf('.');
                if(index != -1 && name.substring(index + 1).compareTo(suffix) == 0) return true;
            }
        }
        return false;
    }
    //将对象o1通过ObjectOutputStream输出到文件夹dir中
    private void write(Object o1, File dir) throws Exception {
        String suffix;
        String id;
        if(o1 instanceof Student){
            suffix = studentFileSuffix;
            id = String.valueOf(((Student)o1).getId());
        }else if(o1 instanceof javaTeacher){
            suffix = teacherFileSuffix;
            id = String.valueOf(((javaTeacher)o1).getId());
        }else{
            throw new Exception("bad");
        }
        String path = dir.getAbsolutePath() + "/" + id + "." + suffix;
        File file = new File(path);
        FileOutputStream fOut;
        BufferedOutputStream bufferedOut;
        ObjectOutputStream oOut;
        if(!file.exists()) file.createNewFile();
        fOut = new FileOutputStream(file);
        bufferedOut = new BufferedOutputStream(fOut);
        oOut = new ObjectOutputStream(bufferedOut);
        if(o1 instanceof Student) oOut.writeObject((Student)o1);
        else if(o1 instanceof javaTeacher) oOut.writeObject((javaTeacher)o1);
        oOut.close();
        bufferedOut.close();
        fOut.close();
    }
    private void writeIntoDist(String path) throws Exception {
        File dir = new File(path);
        if(!dir.exists()) throw new FileNotFoundException("Can not found path: " + dir.getAbsolutePath());
        else if(dir.isFile()) throw new Exception("your input path is a file, not is directory");
        else if(haveSuffixInDir(dir, teacherFileSuffix)) throw new Exception("In path " + dir.getAbsolutePath() + " have file with suffix ." + teacherFileSuffix);
        else if(haveSuffixInDir(dir, studentFileSuffix)) throw new Exception("In path " + dir.getAbsolutePath() + " have file with suffix ." + studentFileSuffix);
        for(Object o1: studentsList){
            write(o1, dir);
        }
        for(Object o1: teacherList){
            write(o1, dir);
        }
    }
    //---------------------输出区域 结束------------------------
}
public class observerTeacherAndStudents {
    public static void main(String[] args) {
        Test t = new Test();
        t.run();
    }
}
