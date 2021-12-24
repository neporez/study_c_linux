#include<stdio.h>
#include<stdlib.h>

typedef struct human {
	int friendlist[2000];
	int count;
}node;




int main() {
	int n,m;
	int me,friend;
	scanf("%d %d",&n,&m);

	node*p = (node*)malloc(sizeof(node)*2000); 
	

	for(int i=0;i<m;i++) {
		scanf("%d %d",&me,&friend);

	}




	return 0;
}
