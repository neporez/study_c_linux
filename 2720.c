#include<stdio.h>

int main() {
	int q = 25, d = 10, n = 5, p = 1;
	int q_n = 0, d_n =0, n_n=0,p_n=0;
	int t;
	int temp;
	scanf("%d",&t);
	for(int i=0;i<t;i++) {
		scanf("%d",&temp);
		while(temp-q >= 0) {
			temp = temp-q;
			q_n++;
		}
		while(temp-d >= 0) {
			temp = temp-d;
			d_n++;
		}
		while(temp-n >= 0) {
			temp = temp-n;
			n_n++;
		}
		while(temp-p >=0) {
			temp = temp-p;
			p_n++;
		}
		printf("%d %d %d %d\n",q_n,d_n,n_n,p_n);
		q_n = d_n =n_n =p_n =0;

	}
	

	



	return 0;
}
