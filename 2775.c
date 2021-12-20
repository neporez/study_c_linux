#include<stdio.h>

int apart[15][15];

int livePeople(int i, int j) {
	int sum = 0;
	for(int k=0;k<=j;k++) {
		sum+=apart[i-1][k];
	}	
	return sum;
}

int main() {
	int t;
	int k,n;
	scanf("%d",&t);

	for(int i=0;i<15;i++) {
		apart[0][i]=i;
	}
	
	for(int i=1;i<15;i++) {
		for(int j=0;j<15;j++) {
			apart[i][j] = livePeople(i,j);
		}
	}

	
	for(int i=0;i<t;i++) {
		scanf("%d %d",&k,&n);
		printf("%d",apart[k][n]);

	}



	return 0;

}
