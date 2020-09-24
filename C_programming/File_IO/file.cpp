#include <stdio.h>
int main(){
		
	//fopen有6种模式
	//选项		模式		文件不存在		写入模式
	//r			只读		报错退出		无
	//w			只写		创建			覆盖模式
	//a 		只写		创建			追加
	//r+		读写文件	报错退出		覆盖模式
	//w+ 		读写文件	创建			覆盖模式
	//a+		读写文件 	创建			追加
	FILE* file=fopen("G:\\Life_of_XDU\\C_programming\\File_IO\\ouasaast.txt","w+");
	printf("Details\n");
	if(file==NULL){
		puts("File open failed");
		return 0;
	}else{
		puts("File open success");
	}

	//下面4行演示写入
	fputs("First Line\n",file);
	fprintf(file,"Second Line:%d %d\n",12,1323);
	fputc('A',file);
	fputc('B',file);
	//下面演示读入
	/*
	char line[100];
	line[0]=fgetc(file);	
	fgets(line,3,file);
	fscanf(file,"%s",line);
	printf("Get line:%s\n",line);
	*/

	if(fclose(file)==0){//关闭成功会返回0
		puts("Close file success");
	}else{				//关闭失败返回EOF
		puts("Close file return EOF(ERROR)");
	}
	return 0;
}