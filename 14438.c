#include<stdio.h>

int min(int x, int y) {
	if(x>y) {
		return y;
	} else {
		return x;
	}
}


int segmentTreeCreate(int num[],int segmentTree[], int start ,int end, int node) {
	if(start == end) {
		segmentTree[node] = num[start];
		return segmentTree[node];
	} else {
		segmentTree[node]= min(segmentTreeCreate(num,segmentTree,start,(start+end)/2,node*2), segmentTreeCreate(num,segmentTree,(start+end)/2+1,end,node*2+1));
	}
}


int segmentInsert(int num[],int segmentTree[], int index, int value, int start, int end, int node) {
	if(start > index || end < index) return segmentTree[node];
	if(start == end) return segmentTree[node] = value;
	else return segmentTree[node]=min(segmentInsert(num,segmentTree,index,value,start,(start+end)/2,node*2),segmentInsert(num,segmentTree,index,value,(start+end)/2+1,end,node*2+1));	
}

int segmentSearch(int num[], int segmentTree[], int i, int j, int start, int end ,int node) {
	
	if(i > end || j < start) return 1000000001;

	if(i<= start && end <= j) return segmentTree[node];

	int min = 1000000001;
	
	int temp=segmentSearch(num,segmentTree,i,j,start,(start+end)/2,node*2);
	if(min > temp) {
		min = temp;
	}
	temp = segmentSearch(num,segmentTree,i,j,(start+end)/2+1,end,node*2+1);
	if(min > temp) {
		min = temp;
	}
	return min;

}


int main() {
	int n,m;
	scanf("%d",&n);
	int num[n+1];
	int segmentTree[4*(n+1)];
	for(int i = 1;i <= n;i++) {
		scanf("%d",&num[i]);
	}

	segmentTreeCreate(num,segmentTree,1,n,1);

	scanf("%d",&m);

	for(int k=0;k<m;k++) {
		int cmd;
		scanf("%d",&cmd);
		if(cmd == 1) {
			int i,v;
			scanf("%d %d",&i,&v);
			num[i]=v;
			segmentInsert(num,segmentTree,i,v,1,n,1);
		}
		if(cmd == 2) {
			int i,j;
			scanf("%d %d",&i,&j);
			printf("%d\n",segmentSearch(num,segmentTree,i,j,1,n,1));
		}

	}	


	return 0;
}
