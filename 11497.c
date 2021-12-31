#include<stdio.h>
#include<string.h>
#define SWAP(x,y,temp) (temp = x, x = y, y = temp)

int arr[10001];
int arrtemp[10001];

int partition(int list[], int left, int right) {
	int pivot,low,high,temp;
	low = left;
	high = right+1;
	pivot = list[left];

	do {
		do{
			low++;

		}while(pivot > list[low] && low <= right);
		do {
			high--;
		}while(pivot < list[high] && high >= left);

		if(low<high) {
			SWAP(list[low],list[high],temp);
		}
	}while(low<high);
	SWAP(list[left],list[high],temp);

	return high;

}


void q_sort(int list[], int left, int right) {
	if(left < right) {
		int q = partition(list,left,right);

		q_sort(list, left, q-1);
		q_sort(list, q+1, right);

	}
}




int main() {
	int t,n,cnt = 0,max = 0,temp = 0;
	scanf("%d",&t);

	for(int i=0;i<t;i++) {
		scanf("%d",&n);
		cnt = 0;
		max = 0;
		memset(arr,0,sizeof(arr));
		memset(arrtemp,0,sizeof(arrtemp));
		for(int j=0;j<n;j++) {
			scanf("%d",&arrtemp[j]);
		}
		q_sort(arrtemp,0,n-1);
		if(n%2) {
			for(int j=0;j<n/2;j++) {
				arr[j] = arrtemp[cnt++];
				arr[(n-1)-j] = arrtemp[cnt++];
			}
			arr[n/2] = arrtemp[n-1];
		} else {
			for(int j=0;j<n/2;j++) {
				arr[j] = arrtemp[cnt++];
				arr[(n-1)-j] = arrtemp[cnt++];
			}
		}	
		for(int j=1;j<n;j++) {
			temp = arr[j-1] - arr[j];
			if(temp < 0) temp = (-1)*temp;
			if(temp > max) {
				max = temp;
			}
		}
		printf("%d\n",max);
	}



	return 0;
}
