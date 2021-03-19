package com.basicgrammer.www;
//这个文件演示如何写java的文档


/**
 * @author 作者名
 * @version 版本号
 * @since 需要最早使用的jdk版本
 * @param 参数名
 * @return 返回值情况
 * @throws 异常抛出情况
 */
public class Doc{
    /**
     *
     * @param a
     * @param b
     * @return
     * @throws Exception
     */
    int test(int a,int b)throws Exception{
        return 1;
    }

}

/**
 * 在命令行执行javadoc的命令
 * 在该文件的文件夹打开cmd
 * 执行以下命令 javadoc -encoding UTF-8 -charset UTF-8 Doc.java
 *
 * 在idea中输出javadoc（在本文件所在文件夹下有一个操作指示的图片（如何在idea中输出javadoc.png））
 * 点击上方的Tools/Generate JavaDoc
 * 在弹出的窗口中进行选择
 * Locale选项填： zh_CN
 * 表示中国地区
 * Other command line arguments 填：-encoding UTF-8 -charset UTF-8
 */
