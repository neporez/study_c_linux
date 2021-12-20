#include<stdio.h>


int sum[1024*1024*2+1];
int bu[21];
int pow2(int n) {
	int two = 1;
	for(int i= 0; i<n;i++) {
		two*=2;
	}
	return two;

}

int main() {
	int c,b,k;
	int max;
	int a=2;
	int index = 1;
	scanf("%d %d",&c,&b);
	max = 0;
	
	
	for(int i=1;i<b+1;i++) {
		scanf("%d",&bu[i]);
	}

	for(int i=0,j=0;index<=b;i++,j+=2) {
		if(j==a) {
			a*=2;
			j=0;
			index++;
		}
		sum[i*2 + 1] += sum[i];
		sum[i*2 + 2] += sum[i]+bu[index];
		if(index == b) {
			if(max < sum[i*2 +1] && c>= sum[i*2+1]) {
				max = sum[i*2 +1];
			}
			if(max < sum[i*2 +2] && c>= sum[i*2+2]) {
				max = sum[i*2+2];
			}
		}
	}

	printf("%d\n",max);

	return 0;
}
