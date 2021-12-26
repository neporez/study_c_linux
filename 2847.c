#include<stdio.h>


int main(){
	int n,score;
	int sum[100];
	int sumdecrease = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&sum[i]);
	}


	for(int i= n-2; i>=0;i--) {
		if(sum[i+1] <= sum[i]) {
			int temp = sum[i+1]-1;
			sumdecrease += sum[i] - temp;
			sum[i] = temp;
		}
	}
	printf("%d",sumdecrease);


}
