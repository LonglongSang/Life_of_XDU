#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct nod{
	int val;
	int next;
}node;
#define MAXN 100000
int cnt[10001];
node arr[MAXN];
void pri(int now){
	while(now!=-1){
		if(arr[now].next!=-1) printf("%.5d %d %.5d\n",now,arr[now].val,arr[now].next);
		else printf("%.5d %d -1\n",now,arr[now].val);
		now=arr[now].next;
	}	
}
int main(){
	int root,n;
	scanf("%d %d\n",&root,&n);
	int index,val,next;
	for(int i=0;i<n;i++){
		scanf("%d %d %d\n",&index,&val,&next);
		arr[index].val=val;
		arr[index].next=next;
	}
	int now=root;
	int del_root=-1;
	int del_last=-1;
	int last=root;
	int temp;
	while(now!=-1){
		cnt[abs(arr[now].val)]++;
		temp=arr[now].next;
		arr[now].next=-1;
		if(cnt[abs(arr[now].val)]>1){
			if(del_root!=-1){
				arr[del_last].next=now;
				del_last=now;
			}else{
				del_root=now;
				del_last=now;
			}
			
		}else{
			if(now!=root){
				arr[last].next=now;
				last=now;
			}
		}
		now=temp;
	}
	pri(root);
	pri(del_root);
	
    return 0;
}