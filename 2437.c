#include<stdio.h>

#define SWAP(x,y,temp) (temp = x, x= y, y= temp)

int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left;
	int high = right+1;
	int temp;
	do {
		do {

			low++;

		}while(pivot > arr[low] && low <= right);

		do {
			high--;
		}while(pivot<arr[high] && high >= left);
		if(low<high)
			SWAP(arr[low],arr[high],temp);
	}while(low<high);
	SWAP(arr[left],arr[high],temp);

	return high;
}


void q_sort(int arr[],int left, int right) {
	
	if(left < right) {
		int p = partition(arr,left,right);
		
		q_sort(arr,left,p-1);
		q_sort(arr,p+1,right);

	}

}




int main() {
	int n,sum=0;
	
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	
	q_sort(arr,0,n-1);
	


	for(int i=0;i<n;i++) {
		sum+=arr[i];
		if(arr[i+1] - 1 > sum && i<n-1) {
			printf("%d",sum+1);
			return 0;
		}	
	}
	printf("%d",sum+1);


}
