#include<stdio.h>


char board[50][50];

int checkFlip(int h, int w) {
	int min= 2500;
	int cnt = 0;
	for(int i=h;i<h+8;i++) {
		for(int j=w;j<w+8;j++) {
			if((i+j)%2 == 0 && board[i][j] == 'B') {
				cnt++;		
			}
			if((i+j)%2==1 && board[i][j] == 'W') {
				cnt++;
			}
		}
	}
	if(min > cnt) {
		min = cnt;
	}
	cnt = 0;
	for(int i=h;i<h+8;i++) {
		for(int j=w;j<w+8;j++) {
			if((i+j)%2 == 1 && board[i][j] == 'B') {
				cnt++;		
			}
			if((i+j)%2==0 && board[i][j] == 'W') {
				cnt++;
			}
		}
	}
	if(min > cnt) {
		min = cnt;
	}
	return min;

}


int main() {
	
	int h,w;
	int min = 2500;
	scanf("%d %d",&h,&w);
	int temp;
	for(int i=0;i<h;i++) {
		scanf("%s",board[i]);
	}
	
	for(int i=0;i<=h-8;i++) {
		for(int j =0; j<=w-8;j++) {
			temp = checkFlip(i,j);
			if(min > temp) {
				min = temp; 
			}
		}
	}

	printf("%d",min);


	return 0;
}
