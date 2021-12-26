#include<stdio.h>


int sum = 0;
int rgb[1001][3];


// 가장 작은 값과 두번째로 작은 값을 찾는다.
// 가장 작은 값의 인덱스를 저장, 두번째도
// 다음 번지의 가장 작은 값을 찾는다. 이전 작은 값과 인덱스가 겹치지 않으면 가장 작은 값으로 저장하고 나머지
// 인덱스와 겹치지 않는 값을 두번째 작은 값으로 인덱스와 값으로 저장
// 만약 가장 작은 값이 겹친다면 이전 번지에서 두번째 값과 가장 작은 값의 합이 현재번지의 가장 작은값과 이전번지의 두번째로 작은
// 값의 합을 비교하여 저장

int minIndex(int colors[]) {
	int min = 1001;
	int _minIndex = -1;
	for(int i=0;i<3;i++) {
		if(colors[i] < min) {
			min = colors[i];
			_minIndex = i;
		}
	}
	return _minIndex;
}

int secondIndex(int colors[]) {
	int _minIndex = minIndex(colors);
	int maxIndex = -1;
	int max = 0;
	
	int secondIndex = -1;
	for(int i=0;i<3;i++) {
		if(max < colors[i]) {
			max = colors[i];
			maxIndex = i;
		}
	}

	for(int i =0;i<3;i++) {
		if(maxIndex != i && _minIndex != i) {
			secondIndex = i;
		}
	}

	return secondIndex;
}


int main() {
	int n;
	int beforeMin;
	int beforeSecond;
	int nowMin;
	int nowSecond;
	int tempMin = 1001;
	scanf("%d",&n);
	scanf("%d %d %d",&rgb[0][0],&rgb[0][1],&rgb[0][2]);

	beforeMin = minIndex(rgb[0]);
	beforeSecond = secondIndex(rgb[0]);
	sum+= rgb[0][beforeMin];
	

	for(int i=1;i<n;i++) {
		scanf("%d %d %d",&rgb[i][0],&rgb[i][1],&rgb[i][2]);
		nowMin = minIndex(rgb[i]);
		if(nowMin != beforeMin) {
			sum+=rgb[i][nowMin];
			for(int j = 0; j<3; j++) {
				if(beforeMin != j && nowMin != j) {
					beforeSecond = j;
				}
			}
			beforeMin = nowMin;
		} else {
			tempMin = 1001;
			for(int j = 0; j<3;j++) {
				if(nowMin != j && tempMin > rgb[i][j]) {
					tempMin = rgb[i][j];
					nowSecond = j;
				}
			}
			if((rgb[i][nowMin] + rgb[i-1][beforeSecond]) > (rgb[i][nowSecond] + rgb[i-1][beforeMin])) {
					sum+= rgb[i][nowSecond];
					for(int j=0;j<3;j++) {
						if(nowSecond != j && nowMin != j) {
							beforeSecond = j;
							break;
						}
					}
					beforeMin = nowSecond;
			} else {
					sum-= rgb[i-1][beforeMin];
					sum+= rgb[i-1][beforeSecond];
					sum+= rgb[i][nowMin];
					beforeMin = nowMin;
					for(int j=0;j<3;j++) {
						if(nowMin != j && beforeSecond != j) {
							beforeSecond = j;
							break;
						}
					}
			}

		}



	}


	printf("%d",sum);





	return 0;
}
