#include<stdio.h>

unsigned int arr[10000];

unsigned long long pow2(int n) {
	unsigned long long two = 1;
	for(int i=0;i<n;i++) {
		two*=2;
	}
	return two;
}


int main() {
	unsigned long long fullNum= pow2(32)-1;
	int gate, plane;
	int gateOpen=1;
	int count=0;
	int temp,arrNum,fullTemp,indexTemp = 0;
	unsigned long long arrTemp;
	scanf("%d %d",&gate,&plane);

	for(int i=0;i<plane;i++) {
		scanf("%d",&temp);
		indexTemp = 0;
		for(int i=0;i<32;i++) {
			printf("%d ",(arr[0] >> i)%2);
		}
		printf("\n");
		if(gateOpen>0) {
			if((arr[(temp-1)/32] >> ((temp-1)%32)) %2 != 1) {
				arr[(temp-1)/32]+= pow2((temp-1)%32);
				count++;
				continue;	
			} else {
				printf("check!\n");
				arrNum = (temp-1)/32;
				arrTemp = (arr[arrNum] % pow2((temp-1)%32)+1);

				fullTemp = pow2((temp-1)%32+1)-1;
				if(arrTemp != fullTemp) {
					for(int j=1;j<=((temp-1)%32+1);j++) {
						if(arrTemp%2 == 0) {
							indexTemp = j;
						}
						arrTemp/=2;
					}
					arr[arrNum]+=pow2(indexTemp-1);
					count++;
					continue;
				} else {
					if(arrNum == 0) {
						gateOpen = 0;
						continue;
					} else {
						while(arr[--arrNum] == fullNum) {
							if(arrNum == 0) break;
						}
						if(arrNum == 0 && arr[arrNum] == fullNum) {
							gateOpen = 0;
							continue;
						} else {
							arrTemp = arr[arrNum];
							for(int j=1;j<=32;j++) {
								if(arrTemp%2 == 0) {
									indexTemp = j;
								}	
								arrTemp/=2;	
							}
							arr[arrNum]+=pow2(indexTemp-1);
							count++;
							continue;
						}


					}
				}
				
			}
		}


	}


	printf("%d",count);





	return 0;
}
