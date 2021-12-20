#include<stdio.h>

int getNumber(int a, int b) {
	if(b==0) return a;
	else {
		return getNumber(b,a%b);
	}
}


int main() {
	
	int t;
	int a,b;
	scanf("%d",&t);
	for(int i=0;i<t;i++) {
		scanf("%d %d",&a,&b);
		printf("%d\n",(a*b)/getNumber(a,b));

	}


	return 0;
}

