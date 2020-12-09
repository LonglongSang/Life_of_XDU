#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int t,r,c,cnt[2],v,typ,add,now[2],sum;
#define N 10005
int arr[2][N];
pair<int,int> getsum(int &sum,int i,int j){
    int x=0;
    sum=0;
    while(x<c && i<cnt[0] && j<cnt[1]){
        if(arr[0][i+1]-arr[0][i]>arr[1][j]){
            sum+=arr[0][i+1]-arr[0][i++];
        }else{
            sum+=arr[1][j++];
        }
        x++;
    }
    while(x<c && i<cnt[0]) sum+=arr[0][i+1]-arr[0][i++],x++;
    while(x<c && j<cnt[1]) sum+=arr[1][j++];
    return {i,j};
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    scanf("%d",&t);
    getchar();
    while(t--){
        scanf("%d %d %d",&r,&c,&add);
        getchar();
        cnt[0]=0,cnt[1]=0,now[0]=0,now[1]=0;
        for(int i=0,n=r*c;i<n;i++){
            scanf("%d %d",&v,&typ);
            getchar();
            if(typ) arr[1][cnt[1]++]=v;
            else arr[0][++cnt[0]]=v;
            
        }
        sort(arr[0]+1,arr[0]+1+cnt[0],cmp);
        sort(arr[1],arr[1]+cnt[1],cmp);
        arr[0][0]=0;
        int index=0;
        for(int i=1;i<=cnt[0];i++) arr[0][i]+=arr[0][i-1];
        pair<int,int> temp;
        int sum;
        while(now[0]<cnt[0] && now[1]<cnt[1]){
            temp=getsum(sum,now[0],now[1]);
            //printf("#%d\n",sum);
            if(now[0]+c<=cnt[0]){
                int sum1=arr[0][now[0]+c]-arr[0][now[0]]+add;
                //cout<<"in "<<sum1<<endl;
                if(sum1>=sum){
                    sum=sum1;
                    //cout<<"##"<<endl;
                    now[0]=now[0]+c;
                    //printf("add\n");
                }else{
                    now[0]=temp.first;
                    now[1]=temp.second;
                    //printf("noadd\n");
                }
            }else{
                now[0]=temp.first;
                now[1]=temp.second;
                //printf("noadd\n");
            }
            if(index++) printf(" ");
            printf("%d",sum);
        }

        for(int i=0;i<2;i++){
            while(now[i]<cnt[i]){
                sum=0;
                temp=getsum(sum,now[0],now[1]);
                now[0]=temp.first,now[1]=temp.second;
                if(index++) printf(" ");
                printf("%d",sum+(i?0:add));
            }
        }
        putchar('\n');
    }
}