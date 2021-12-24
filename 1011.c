#include<stdio.h>


long long int pow2(int n) {
	long long int two=1;
	for(int i=0;i<n;i++) {
		two*=2;
	}
	return two;
}

long long int teleport(long long int distance, long long int start, long long int end, long long int node) {
	if(node*node+1 <= distance && node*(node+1) >= distance) return node*2;
	if(node*(node+1)+1 <= distance && (node+1)*(node+1) >= distance) return node*2+1;
	
	long long int mid = (start+end)/2;
	if(distance > (node+1)*(node+1)) return teleport(distance, mid+1, end, (end+mid)/2);
	if(distance < node*node+1) return teleport(distance, start, mid, (start+mid)/2);




}




int main() {
	int t;
	long long int distance;
	long long int x,y;
	long long int end = pow2(16);
       	long long int count;	
	scanf("%d",&t);
	for(int i=0;i<t;i++) {
		scanf("%lld %lld",&x,&y);
		distance = y-x;
		printf("%lld\n",count = teleport(distance,0,end,end/2));
	

	}



	return 0;
}
