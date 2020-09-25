// "static void main" must be defined in a public class.
class Employee{
   String name;
   int age;
   String designation;
   double salary;
   // Employee 类的构造器
   public Employee(String name){
      this.name = name;
   }
   // 设置age的值
   public void empAge(int empAge){
      age =  empAge;
   }
   /* 设置designation的值*/
   public void empDesignation(String empDesig){
      designation = empDesig;
   }
   /* 设置salary的值*/
   public void empSalary(double empSalary){
      salary = empSalary;
   }
   /* 打印信息 */
   public void printEmployee(){
      System.out.println("名字:"+ name );
      System.out.println("年龄:" + age );
      System.out.println("职位:" + designation );
      System.out.println("薪水:" + salary);
   }
}
class Pos{
    int x;
    int y;
    public Pos(int x,int y){
        this.x=x;
        this.y=y;
    }
    public void pri(){
        System.out.println("This point's position is" + x + y);
    }
}
public class ClassExample {
    public static void main(String[] args) {
        System.out.println("Hello World!");
        Employee a=new Employee("SangLongLong");
        a.empSalary(102020);
        a.empAge(22);
        a.empDesignation("Student");
        a.printEmployee();
        
        System.out.println();
        Pos b = new Pos(1,200);
        b.pri();
    }
}

