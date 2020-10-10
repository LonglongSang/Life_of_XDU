#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
int IsTheNumber ( const int N ){
    int low=1;
    int high=N;
    int mid;
    int flag=0;
    while(high>=low){
        mid=(low+high)/2;
        if(mid*mid==N){
            flag=1;
			break;
        }else if(mid*mid>N){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(flag==0) return 0;
    int key[10];
    for(int i=0;i<10;i++) key[i]=0;
	int n=N;
    while(n!=0){
		key[n%10]++;
		n/=10;
	}
	for(int i=0;i<10;i++){
		if(key[i]>1) return 1;
	}
	return 0;
}