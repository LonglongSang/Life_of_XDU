# 如何安装JAVA

1. 下载并安装java

2. 在系统变量里添加一个JAVA_HOME的系统变量
    内容填安装java的目录，如C:\Program Files\Java\jdk1.8.0_271

3. 在环境变量里添加java的地址bin和jre
---
    方法1: %JAVA_HOME%\bin
    方法2: C:\Program Files\Java\jdk1.7.0_21\bin
    我用方法1，添加以下两个路径即可：
    %JAVA_HOME%\bin
    %JAVA_HOME%\jre\bin

---

    实际上在安装JAVA时，它自动帮你配置了一个path变量：
    C:\Program Files (x86)\Common Files\Oracle\Java\javapath;
    里面已经包括

---

    在安装java里在JAVA_HOME这个文件下安装了一个jre（不是jdk目录下的jre），也不知道这个jre是干嘛的

4. 查看是否安装成功
    在cmd里使用java -version