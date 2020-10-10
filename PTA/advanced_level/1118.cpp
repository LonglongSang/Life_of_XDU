#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
void bird_v(int &count,int index,vector<int> &belong,vector<vector<int>> &image,vector<bool> &image_visited,vector<vector<int>> &bird,vector<bool> &bird_visited);
void image_v(int &count,int index,vector<int> &belong,vector<vector<int>> &image,vector<bool> &image_visited,vector<vector<int>> &bird,vector<bool> &bird_visited){
	image_visited[index]=true;
	for(auto it:image[index]) if(bird_visited[it]==false) bird_v(count,it,belong,image,image_visited,bird,bird_visited);
}
void bird_v(int &count,int index,vector<int> &belong,vector<vector<int>> &image,vector<bool> &image_visited,vector<vector<int>> &bird,vector<bool> &bird_visited){
	bird_visited[index]=true;
	belong[index]=count;
	for(auto it:bird[index]) if(image_visited[it]==false) image_v(count,it,belong,image,image_visited,bird,bird_visited);
}
int main(){
	int num,k,temp;
	scanf("%d\n",&num);
	vector<vector<int>> image(num);
	vector<vector<int>> bird(10001);
	vector<bool> image_visited(num,false);
	vector<bool> bird_visited(10001,false);
	vector<int> belong(10001,-1);
	for(int i=0;i<num;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf(" %d",&temp);
			image[i].push_back(temp);
			bird[temp].push_back(i);
		}
		scanf("\n");
	}
	int count=0;
	for(int i=0;i<image.size();i++){
		if(image_visited[i]==true) continue;
		image_v(count,i,belong,image,image_visited,bird,bird_visited);
		count++;
	}
	int max=0;
	int max_a=0;
	for(int i=1;i<10001;i++){
		if(belong[i]!=-1){
			if(belong[i]>max) max=belong[i];
			if(i>max_a) max_a=i;
		}
	}
	printf("%d %d\n",max+1,max_a);
	scanf("%d\n",&k);
	int a,b;
	for(int i=0;i<k;i++){
		scanf("%d %d\n",&a,&b);
		if(belong[a]==belong[b]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}



