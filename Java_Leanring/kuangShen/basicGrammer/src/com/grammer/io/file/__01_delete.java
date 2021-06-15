package com.grammer.io.file;

import java.io.File;

public class __01_delete {
    private static class Test{
        private boolean really;//是否真的删除
        Test(boolean really){
            this.really = really;
        }

        //递归删除一个文件夹/文件中所有，包括其自身，利用递归删除
        public void delete(File file){
            if(file == null || !file.exists()) return;
            if(file.isFile()){
                if(really) file.delete();
                System.out.println("delete a file: " + file.getAbsolutePath());
                return;
            }
            File[] son = file.listFiles();
            for(int i = 0, n = son.length; i < n; i++){
                delete(son[i]);
            }
            if(really) file.delete();
            System.out.println("delete a directory: " + file.getAbsolutePath());
        }
        public void delete(String filePath){
            delete(new File((filePath)));
        }
    }
    public static void main(String[] args) {
        Test t = new Test(false);
        t.delete("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\io\\file\\testDelete");

    }
}
