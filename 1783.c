#include<stdio.h>



int main(){
	long long int n,m;

	scanf("%lld %lld",&n,&m);

	if(n==1) {
		printf("1");
	} else if(n==2) {
		if(m<3) {
			printf("1");
		} else if(m<5 && m>=3) {
			printf("2");
		} else if(m<7 && m>=5) {
			printf("3");
		} else if(m>=7) {
			printf("4");
		}
	} else if(n>=3) {
		if(m<=4) {
			printf("%lld",m);
		} else if(m>=5 && m<=6) {
			printf("4");
		} else if(m>=7) {
			printf("%lld",m-2);
		}
	}




	return 0;
}
