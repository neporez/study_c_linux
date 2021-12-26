#include<stdio.h>


int main() {
	int plug=0;
	int plugCount = 0;
	int k;
	scanf("%d %d",&plug,&k);
	int plugs[100] = {0};
	int pluglist[101];
	int plugdistance[101][101];
	int plugdistanceCount[101]= {0};
	int temp, count = 0, maxDistance = 0, maxIndex=-1;
	

	for(int i=1;i<=k;i++) {
		scanf("%d",&temp);
		pluglist[i-1]= temp;
		plugdistance[temp][plugdistanceCount[temp]++] = i;
	}
	
	for(int i=1;i<=k;i++) {
		plugdistance[i][plugdistanceCount[i]] = 101;
	}

	for(int i=1;i<=k;i++) {
		plugdistanceCount[i] = 0;
	}
	int check = 0;
	for(int i=0;i<k;i++) {
		check = 0;
		for(int j=0;j<plug;j++) {
			if(plugs[j] == pluglist[i]) {
				plugdistanceCount[pluglist[i]]++;
				check = 1;		
			}
		}
		if(check > 0) {
		       	continue;
		}
		if(plug > plugCount) {
			plugs[plugCount++] = pluglist[i];
			plugdistanceCount[pluglist[i]]++;
			continue;
		}
		for(int j = 0; j<plug;j++) {
			if(maxDistance < plugdistance[plugs[j]][plugdistanceCount[plugs[j]]]) {
				maxDistance = plugdistance[plugs[j]][plugdistanceCount[plugs[j]]];
				maxIndex = j;
			}
		}
		plugs[maxIndex] = pluglist[i];
		plugdistanceCount[pluglist[i]]++;
		count++;
	}
	printf("%d",count);





	return 0;
}
