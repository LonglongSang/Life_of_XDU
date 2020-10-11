#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace  std;
int r,c,l,t;
bool arr[60][1286][128];
char temp;
struct node{
    int x,y,z;
};
int main(){
    scanf("%d %d %d %d\n",&r,&c,&l,&t);
    //cout<<r<<c<<l<<t<<endl;
    for(int k=0;k<l;k++){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%c",&temp);
                getchar();
                cout<<temp<<" ";
                arr[l][i][j]= temp=='1' ? true:false;
            }
            cout<<endl;
        }
    }
    queue<node>Q;
    int dir[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};
    int ans=0;
    for(int k=0;k<l;k++){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!arr[k][i][j]) continue;
                arr[k][i][j]=false;
                Q.push({k,i,j});
                int cnt=1;
                while(!Q.empty()){
                    node cur=Q.front();
                    Q.pop();
                    for(int a=0;a<6;a++){
                        int x,y,z;
                        x=cur.x+dir[a][0];
                        y=cur.y+dir[a][1];
                        z=cur.z+dir[a][2];
                        if(x<0 || x>=l || y<0 || y>=r || z<0 || z>=c || !arr[x][y][z]) continue;
                        Q.push({x,y,z});
                        arr[x][y][z]=false;
                        cnt++;
                    }
                }
                cout<<cnt<<endl;
                if(cnt>=t) ans+=cnt;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}