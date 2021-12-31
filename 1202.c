#include<stdio.h>

#define SWAP(x,y,temp) (temp=x,x=y,y=temp)


typedef struct jewel {
	int value;
	int weight;
}JEWEL;

int bag[300000];

JEWEL jewel[300000];
JEWEL pq[300000];

int partitionJ(JEWEL list[],int left, int right) {
	int low,high,pivot,temp;




}


void qj_sort(JEWEL list[], int left, int right) {
	if(left < right) {
		int q = partitionJ(list,left,right);

		qj_sort(list,left,q-1);
		qj_sort(list,q+1,right);
	}
}

int partition(int list[], int left, int right) {
	int low,high,pivot,temp;
	low = left;
	high = right+1;
	pivot = list[left];
	
	do {
		do {

			low++;
		}while(pivot > list[low] && low<right);

		do {
			high--;
		}while(pivot < list[high] && high > left);
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

		q_sort(list,0,q-1);
		q_sort(list,q+1,right);

	}

}


int main() {
	int n,k,temp,temp2;
	scanf("%d %d",&n,&k);

	for(int i=0;i<n;i++) {
		scanf("%d %d",);
	}

	for(int i=0;i<k;i++) {
		scanf("%d",&bag[i]);
	}

	q_sort(bag,0,k-1);






	return 0;
}
