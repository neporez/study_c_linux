#include<stdio.h>


int min(int x, int y) {
	if(x> y) {
		return y;
	}
	return x;
}


int main() {
	int n;
	int a[1001][3];
	int d[1001][3];
	int minSum = 1000*1000+1;
	a[0][0] = a[0][1] = a[0][2] =d[0][0] = d[0][1] = d[0][2] = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d %d %d",&a[i][0], &a[i][1],&a[i][2]);
		d[i][0] = min(d[i-1][1],d[i-1][2]) + a[i][0];
		d[i][1] = min(d[i-1][0],d[i-1][2]) + a[i][1];
		d[i][2] = min(d[i-1][0],d[i-1][1]) + a[i][2];
	}
	
	for(int i = 0;i<3;i++) {
		if(minSum > d[n][i]) {
			minSum= d[n][i];
		}
	}
	
	printf("%d",minSum);





	return 0;
}
