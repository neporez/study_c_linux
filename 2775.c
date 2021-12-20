#include<stdio.h>

long long int apart[15][15];

long long int livePeople(int i, int j) {
	long long int sum = 0;
	for(int k=1;k<=j;k++) {
		sum+=apart[i-1][k];
	}	
	return sum;
}

int main() {
	int t;
	int k,n;
	scanf("%d",&t);

	for(int i=1;i<15;i++) {
		apart[0][i]=i;
	}
	
	for(int i=1;i<15;i++) {
		for(int j=1;j<15;j++) {
			apart[i][j] = livePeople(i,j);
		}
	}

	
	for(int i=0;i<t;i++) {
		scanf("%d %d",&k,&n);
		printf("%lld",apart[k][n]);

	}



	return 0;

}
