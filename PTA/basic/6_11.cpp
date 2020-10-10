#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
int partition(float *nums,int low,int high){
    float pivot=nums[low];
    while(low<high){
        while(nums[high]>=pivot && low<high) high--;
        nums[low]=nums[high];
        while(nums[low]<=pivot && low<high) low++;
        nums[high]=nums[low];
    }
    nums[low]=pivot;
    return low;
}
void quicksort(float *nums,int low,int high){
    if(high>low){
        int pivot=partition(nums,low,high);
        quicksort(nums,low,pivot-1);
        quicksort(nums,pivot+1,high);
    }
}

ElementType Median( ElementType A[], int N ){
	quicksort(A,0,N-1);
	if(N%2==1){
		return A[(N+1)/2-1];
	}else{
		return (A[(N+1)/2-1]+A[(N+1)/2])/2;
	}
}