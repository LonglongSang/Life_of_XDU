#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 20 
typedef struct noode node;
struct noode{
    char name[NAME_SIZE];
    char father[NAME_SIZE];
}arr[100];
int n,m;
char line[200];
int cmp(const void* a,const void* b){
    return strcmp(((node*)a)->name,((node*)b)->name);
}
int get_index(char*name){
    int low=0,high=n-1;
    while(high>low){
        int mid=(low+high)/2;
        int a=strcmp(name,arr[mid].name);
        if(a==0){
            return mid;
        }else if(a>0){
            //high =mid-1;
            low=mid+1;
        }else{
            high =mid-1;
            //low=mid+1;
        }
    }
    return low;
}
int is_ancestor(char* name,char* ancestor){
    while(1){
        if(strcmp(name,ancestor)==0) return 1;
        int index=get_index(name);
        strcpy(name,arr[index].father);
        if(strcmp(name,"")==0) break;
    }
    return 0;
}
int main(){
    scanf("%d %d\n",&n,&m);
    char temp[100][NAME_SIZE];
    for(int i=0;i<n;i++){
        scanf("%[^\n]",line);
        getchar();
        int index=0;
        while(line[index]==' ') index++;
        if(index==0) arr[i].father[0]='\0';
        strcpy(temp[index/2],line+index);
        strcpy(arr[i].name,line+index);
        if((index/2)!=0){
            strcpy(arr[i].father,temp[(index-2)/2]);
        }
        //printf("%s\n",arr[i].name);
    }
    qsort(arr,n,sizeof(node),cmp);
    char name1[NAME_SIZE];
    char name2[NAME_SIZE];
    char a[NAME_SIZE],b[NAME_SIZE],c[NAME_SIZE],d[NAME_SIZE];
    for(int i=0;i<m;i++){
        scanf("%s %s %s %s %s %s\n",name1,a,b,c,d,name2);
        //printf("%s %s %s %s %s %s\n",name1,a,b,c,d,name2);
        //printf("%s\n",arr[get_index(name1)].name);
        if(strcmp(c,"child")==0){
            if(strcmp(arr[get_index(name1)].father,name2)==0){
                printf("True\n");
            }else{
                printf("False\n");
            }
            //printf("1");
        }else if(strcmp(c,"ancestor")==0){
            //printf("2");
            if(is_ancestor(name2,name1)){
                printf("True\n");
            }else{
                printf("False\n");
            }
        }else if(strcmp(c,"sibling")==0){
            if(strcmp(arr[get_index(name1)].father,arr[get_index(name2)].father)==0){
                printf("True\n");
            }else{
                printf("False\n");
            }
        }else if(strcmp(c,"parent")==0){
            if(strcmp(arr[get_index(name2)].father,name1)==0){
                printf("True\n");
            }else{
                printf("False\n");
            }
        }else if(strcmp(c,"descendant")==0){
            if(is_ancestor(name1,name2)){
                printf("True\n");
            }else{
                printf("False\n");
            }
        }
        //printf("1\n");
    }
    
    return 0;
}