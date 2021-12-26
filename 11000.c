#include<stdio.h>

typedef struct timeTable {
	int start;
	int end;	
}T;

T startHeap[200001];
T endHeap[200001];

void addStartHeap(int start, int end, int index) {
	T temp;
	startHeap[index].start= start;
	startHeap[index].end = end;
	if(index == 1) return;
	while(startHeap[index/2].start > startHeap[index].start && index != 1) {
		temp = startHeap[index/2];
		startHeap[index/2]= startHeap[index];
		startHeap[index]= temp;
		index /= 2;
	}
	
}

void addEndHeap(int start, int end, int index) {
	T temp;
	endHeap[index].start = start;
	endHeap[index].end = end;
	if(index == 1) return;
	while(endHeap[index/2].end > endHeap[index].end && index!=1) {
		temp = endHeap[index/2];
		endHeap[index/2] = endHeap[index];
		endHeap[index]= temp;
		index /= 2;
	}
}


void popStartHeap(int endIndex) {
	T temp;
	startHeap[1]=startHeap[endIndex];
	startHeap[endIndex].start = -1;
	startHeap[endIndex].end = -1;
	if(endIndex == 1) return;
	int index =1;
	while(1) {
		if(startHeap[index*2].start != -1 && startHeap[index*2+1].start != -1) {
			if(startHeap[index*2].start < startHeap[index*2+1].start) {
				if(startHeap[index].start > startHeap[index*2].start && index*2 < endIndex) {
					temp = startHeap[index];
					startHeap[index] = startHeap[index*2];
					startHeap[index*2] = temp;
					index*=2;
					continue;		
				}
				if(startHeap[index].start > startHeap[index*2+1].start && index*2+1 < endIndex) {
					temp = startHeap[index];
					startHeap[index] =startHeap[index*2+1];
					startHeap[index*2+1]= temp;
					index = index*2+1;
					continue;
				}
			} else {
				if(startHeap[index].start > startHeap[index*2+1].start && index*2+1 < endIndex) {
					temp = startHeap[index];
					startHeap[index] =startHeap[index*2+1];
					startHeap[index*2+1]= temp;
					index = index*2+1;
					continue;
				}
				if(startHeap[index].start > startHeap[index*2].start && index*2 < endIndex) {
					temp = startHeap[index];
					startHeap[index] = startHeap[index*2];
					startHeap[index*2] = temp;
					index*=2;
					continue;		
				}
			
			}
		} else if(startHeap[index*2].start != -1 && startHeap[index*2+1].start == -1) {
				if(startHeap[index].start > startHeap[index*2].start && index*2 < endIndex) {
					temp = startHeap[index];
					startHeap[index] = startHeap[index*2];
					startHeap[index*2] = temp;
					index*=2;
					continue;		
				}
		} else if(startHeap[index*2+1].start != -1 && startHeap[index*2].start == -1) {
				if(startHeap[index].start > startHeap[index*2+1].start && index*2+1 < endIndex) {
					temp = startHeap[index];
					startHeap[index] =startHeap[index*2+1];
					startHeap[index*2+1]= temp;
					index = index*2+1;
					continue;
				}	
		}
		break;
	}
}

void popEndHeap(int endIndex) {
	T temp;
	endHeap[1] = endHeap[endIndex];
	endHeap[endIndex].start =-1;
	endHeap[endIndex].end = -1;
	if(endIndex == 1) return;
	int index = 1;
	while(1) {
		if(endHeap[index*2].end != -1 && endHeap[index*2+1].end != -1) {
			if(endHeap[index*2].end < endHeap[index*2+1].end) {
				if(endHeap[index].end > endHeap[index*2].end && index*2 < endIndex) {
					temp = endHeap[index];
					endHeap[index] = endHeap[index*2];
					endHeap[index*2] = temp;
					index*=2;
					continue;		
				}
				if(endHeap[index].end > endHeap[index*2+1].end && index*2+1 < endIndex) {
					temp = endHeap[index];
					endHeap[index] =endHeap[index*2+1];
					endHeap[index*2+1]= temp;
					index = index*2+1;
					continue;
				}
			} else {
				if(endHeap[index].end > endHeap[index*2+1].end && index*2+1 < endIndex) {
					temp = endHeap[index];
					endHeap[index] =endHeap[index*2+1];
					endHeap[index*2+1]= temp;
					index = index*2+1;
					continue;
				}
				if(endHeap[index].end > endHeap[index*2].end && index*2 < endIndex) {
					temp = endHeap[index];
					endHeap[index] = endHeap[index*2];
					endHeap[index*2] = temp;
					index*=2;
					continue;		
				}
			
			}
		} else if(endHeap[index*2].end != -1 && endHeap[index*2+1].end == -1) {
				if(endHeap[index].end > endHeap[index*2].end && index*2 < endIndex) {
					temp = endHeap[index];
					endHeap[index] = endHeap[index*2];
					endHeap[index*2] = temp;
					index*=2;
					continue;		
				}
		} else if(endHeap[index*2+1].end != -1 && endHeap[index*2].end == -1) {
				if(endHeap[index].end > endHeap[index*2+1].end && index*2+1 < endIndex) {
					temp = endHeap[index];
					endHeap[index] =endHeap[index*2+1];
					endHeap[index*2+1]= temp;
					index = index*2+1;
					continue;
				}	
		}
		break;

	}
}






int main() {
	int n;
	int startTemp, endTemp;
	int classroom = 1;
	int maxClassroom = 0;
	int popCount=0;
	scanf("%d",&n);

	for(int i=1;i<=n;i++) {
		startHeap[i].start = -1;
		startHeap[i].end = -1;
		endHeap[i].start = -1;
		endHeap[i].end = -1;
	}

	for(int i=1;i<=n;i++) {
		scanf("%d %d",&startTemp,&endTemp);
		addStartHeap(startTemp, endTemp, i);
	}

	while(1) {
		if((startHeap[1].start < endHeap[1].end && startHeap[1].start != -1) || (startHeap[1].start!= -1 && endHeap[1].end==-1)) {
			addEndHeap(startHeap[1].start,startHeap[1].end,classroom++);
			if(maxClassroom < classroom) {
				maxClassroom = classroom;
			}
			popStartHeap(n-popCount);
			popCount++;	


		} else if((startHeap[1].start >= endHeap[1].end && endHeap[1].end != -1) || (startHeap[1].start ==-1 && endHeap[1].end != -1)){
			popEndHeap(--classroom);
				


		}
		if(startHeap[1].start == -1 && endHeap[1].end == -1) {
			break;
		}
	}	

	printf("%d",maxClassroom-1);

	return 0;
}

