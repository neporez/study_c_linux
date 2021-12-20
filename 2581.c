#include<stdio.h>



int num[10001];

void settingNum() {
	int i = 3;
	for(;i<=10000;i+=2) {
		for(int j=2*i;j<=10000;j+=i) {
			num[j]++;
		}
	}

}


int main() {
	int m,n;
	scanf("%d %d",&m,&n);
	int sum=0,min=10001;
	
	int i = (m%2 == 0)? m+1:m;

	settingNum();
	
	for(;i<=n;i+=2) {
		if(num[i] == 0) {
			sum+=i;
			if(min > i) {
				min = i;
			}
		}	
	}
	printf("%d\n%d\n",sum,min);

	return 0;


}
