#include<stdio.h>

int bag[300001];

typedef struct jewel {
	int value;
	int weight;
}JEWEL;

JEWEL jewel[300001];
JEWEL jewel_heap[300001];


void addJewel(int weight, int value, int index) {
	JEWEL temp;
	temp.weight = weight;
	temp.value = value;
	jewel[index] = temp;
	
	while((jewel[index/2].weight > jewel[index].weight) && index != 1) {
		temp = jewel[index/2];
		jewel[index/2] = jewel[index];
		jewel[index] = temp;
		index/=2;
	}
	
}
void addBag(int weight, int index) {
	int temp;
	temp = weight;
	bag[index] = temp;

	while((bag[index/2] > bag[index]) && index!=1) {
		temp = bag[index/2];
		bag[index/2] = bag[index];
		bag[index] = temp;
		index/=2;
	}
}
int popBag(int index) {
	int temp;
	int returnTemp = bag[1];
	int index_p = 1;
	bag[1] = bag[index];
	bag[index] = 0;

	while(index_p*2 < index && (bag[index_p] > bag[index_p*2] || bag[index_p] > bag[index_p*2+1])) {
		if(bag[index_p*2] !=0 && bag[index_p*2+1] !=0) {	
			if(bag[index_p*2] < bag[index_p*2+1]) {
				temp = bag[index_p*2];
			       	bag[index_p*2] = bag[index_p];
				bag[index_p] = temp;
				index_p *=2;	
			} else {
				temp = bag[index_p*2+1];
				bag[index_p*2+1] = bag[index_p];
				bag[index_p] = temp;
				index_p = index_p*2+1;
			}
		} else if(bag[index_p*2+1] == 0 && bag[index_p*2] < bag[index_p]) {
				temp = bag[index_p*2];
			       	bag[index_p*2] = bag[index_p];
				bag[index_p] = temp;
				index_p *=2;	
		} else {
			break;
		}
	}
	return returnTemp;
}

void addHeap(int weight, int value, int index) {
	JEWEL temp;
	temp.weight = weight;
	temp.value = value;
	jewel_heap[index] = temp;

	while(index!=1 &&(jewel_heap[index/2].value < jewel_heap[index].value)) {
		temp = jewel_heap[index/2];
		jewel_heap[index/2] = jewel_heap[index];
		jewel_heap[index] = temp;
		index/=2;
	}
}

JEWEL popJewel(int index) {
	JEWEL temp;
	JEWEL returnTemp = jewel[1];
	int index_p = 1;
	jewel[1] = jewel[index];
	jewel[index].weight = 0;
	jewel[index].value = 0;
	
	while(index_p*2<index && (jewel[index_p].weight > jewel[index_p*2].weight || jewel[index_p].weight > jewel[index_p*2+1].weight)) {
		if(jewel[index_p*2].weight != 0 && jewel[index_p*2+1].weight != 0) {
			if(jewel[index_p*2].weight < jewel[index_p*2+1].weight) {
				temp = jewel[index_p*2];
				jewel[index_p*2] = jewel[index_p];
				jewel[index_p] = temp;
				index_p*=2;
			} else {
				temp = jewel[index_p*2+1];
				jewel[index_p*2+1] = jewel[index_p];
				jewel[index_p] = temp;
				index_p = index_p*2+1;
			}
	       	} else if(jewel[index_p*2+1].weight == 0 && jewel[index_p*2].weight < jewel[index_p].weight) {
			temp = jewel[index_p*2];
			jewel[index_p*2] = jewel[index_p];
			jewel[index_p] = temp;
			index_p*=2;
		} else {
			break;
		}

	}


	return returnTemp;
}

JEWEL popHeap(int index) {
	JEWEL temp;
	JEWEL returnTemp = jewel_heap[1];
	int index_p = 1;
	jewel_heap[1] = jewel_heap[index];
	jewel_heap[index].weight = 0;
	jewel_heap[index].value = 0;

	while(index_p*2<index && (jewel_heap[index_p].value < jewel_heap[index_p*2].value || jewel_heap[index_p].value < jewel_heap[index_p*2+1].value)) {
		if(jewel_heap[index_p*2].value != 0 && jewel_heap[index_p*2+1].value !=0) {	
			if(jewel_heap[index_p*2].value > jewel_heap[index_p*2+1].value) {
				temp = jewel_heap[index_p*2];
				jewel_heap[index_p*2] = jewel_heap[index_p];
				jewel_heap[index_p] = temp;
				index_p*=2;
			} else {
				temp = jewel_heap[index_p*2+1];
				jewel_heap[index_p*2+1] = jewel_heap[index_p];
				jewel_heap[index_p] = temp;
				index_p = index_p*2+1;
			}
		} else if(jewel_heap[index_p*2+1].value == 0 && jewel_heap[index_p*2].value > jewel_heap[index_p].value) {
			temp = jewel_heap[index_p*2];
			jewel_heap[index_p*2] = jewel_heap[index_p];
			jewel_heap[index_p] = temp;
			index_p*=2;
		} else {
			break;
		}
	}


	return returnTemp;

}

int main() {
	int n,k,temp1,temp2,index_jewel = 1, index_bag=1, index_heap = 1;
	int bagWeight,sum=0;
	JEWEL tempJewel;
	scanf("%d %d",&n,&k);
	
	for(int i=0;i<n;i++) {
		scanf("%d %d",&temp1,&temp2);
		addJewel(temp1,temp2,index_jewel++);
	}
	for(int i=0;i<k;i++) {
		scanf("%d",&temp1);
		addBag(temp1,index_bag++);
	}
	while(bag[1] > 0 && jewel[1].weight > 0) {
		bagWeight = popBag(--index_bag);
		while(bagWeight >= jewel[1].weight && index_jewel > 1) {
			tempJewel = popJewel(--index_jewel);
			addHeap(tempJewel.weight, tempJewel.value, index_heap++);
			
		}
		if(jewel_heap[1].weight != 0) {
			sum+=popHeap(--index_heap).value;
		}
		while(jewel_heap[1].weight != 0) {
			tempJewel= popHeap(--index_heap);
			addJewel(tempJewel.weight,tempJewel.value,index_jewel++);
		}
	}	

	printf("%d",sum);

	return 0;
}
