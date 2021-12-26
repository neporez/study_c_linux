#include<stdio.h>

int timetable[400000];


typedef struct classroom {
	int s;
	int t;

}node;



void addTime(int list[], int time, int node) {
	if(list[node]== time) return;
	if(list[node] == 0){
	      list[node] = time;
	      return;
	}
	if(list[node] < time) {
		addTime(list,time,node*2+1);
	} else {
		addTime(list,time,node*2);
	}
}

int main() {
	int n,s,t;



	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d %d",&s,&t);
		addTime(timetable,s,1);
		addTime(timetable,t,1);
	}

	




	return 0;
}
