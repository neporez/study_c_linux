#include<stdio.h>
#include<string.h>


unsigned int num[100000];

unsigned int numMin[1001];



int main() {
	int n,m;
	memset(numMin,255,sizeof(numMin));	
	scanf("%d",&n);
	for(int i = 1; i<=n;i++) {
		scanf("%u",&num[i]);
		if(numMin[i/100] > num[i]) {
			numMin[i/100] = num[i];
		}
	}
	scanf("%d",&m);
	for(int k=0;k<m;k++) {
		int cmd;
		scanf("%d",&cmd);
		if(cmd == 1) {
			int i;
			unsigned int v;
			scanf("%d %u",&i,&v);
		        num[i] = v;
			if(num[i] < numMin[i/100]) {
				numMin[i/100];
			}	
		}
		if(cmd == 2) {
			int i,j;
			scanf("%d %d",&i,&j);
			if(i/100 == j/100) {
				//같은 구역 소속
				unsigned int min = numMin[1000];
				for(int l=i;l<=j;l++) {
					if(num[l] < min) {
						min = num[l];
					}
				}
				printf("%d\n",min);			
			}
			if(i/100 != j/100) {
				//다른 구역 소속
				if(j-i > 100) {
					//범위가 큰 경우
					int cnt = (j/100)-(i/100);
					unsigned int min = numMin[1000];	
					for(int l = i; l< ((i/100)+1)*100; l++) {
						if(num[l] < min) {
							min = num[l];
						}
					}
					for(int l = (i/100) + 1; l<cnt;l++) {
						if(numMin[l] < min) {
							min = numMin[l];
						}
					}

					for(int l = j; l> (j/100)*100 ; l--) {
						if(num[l] < min) {
							min = num[l];
						}
					}
					printf("%d\n",min);
				} else {
					//범위가 작은 경우
					unsigned int min = numMin[1000];
					for(int l=i;l<=j;l++) {
						if(num[l] < min) {
							min = num[l];
						}
					}
					printf("%d\n",min);
				}
			}

		}
	}	



	return 0;
}
