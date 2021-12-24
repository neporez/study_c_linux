#include<stdio.h>
#define SWAP(x,y,temp) (temp = x, x= y , y= temp)

int partition(int list[],int left, int right) {
	int low,high,pivot;
	int temp;
	low = left;
	high = right+1;
	pivot = list[left];
	do{
		do{
			low++;
		}while(pivot > list[low] && right >= low);
		do{
			high--;
		}while(pivot < list[high] && left <= high);
		if(low<high) {
			SWAP(list[low],list[high],temp);
		}
	}while(low < high);

	SWAP(list[left],list[high],temp);
	return high;


}


void q_sort(int list[],int left,int right) {
	if(left < right) {
		int q = partition(list,left,right);

		q_sort(list,left,q-1);
		q_sort(list,q+1,right);
	}
	
}



int main() {
	int n,l;
	int arr[1000];
	int distance[1000];
	int sum=0;
	int count = 1;
	scanf("%d %d",&n,&l);
	for(int i =0;i<n;i++) {
		scanf("%d",&arr[i]);
	}

	q_sort(arr,0,n-1);

	for(int i=0;i<n-1;i++) {
		distance[i] = arr[i+1]- arr[i];
	}
	for(int i=0;i<n-1;i++) {
		sum+=distance[i];
		if(sum+1 > l)  {
			count++;
			sum = 0;
		}
		 
	}
	printf("%d",count);



	return 0;
}
