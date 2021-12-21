#include<stdio.h>
#include<stdlib.h>

typedef struct price {
	int value;
	char color;


}Price;


typedef struct home {
	
	Price price[3];

	struct home* left;
	struct home* right;
	int index;

	


}node;

int homeIndex[1000];
int sum=0;
int n;


void sortPrice(Price price[]) {
	int temp;
	char tempC;
	for(int i=0;i<3;i++) {
		for(int j=i;j<3;j++) {
			if(price[i].value > price[j].value) {
				temp = price[i].value;
				tempC = price[i].color;

				price[i].value = price[j].value;
				price[i].color = price[j].color;
			
				price[j].value = temp;
				price[j].color = tempC;
			}
		}	

	}
}

int checkDirection(Price price1[], Price price2[],int index) {
	if(index == 1 && (price1[index].value == price2[index].value)) {
		return 0;
	} else if(index == 1 && (price1[index].value > price2[index].value)) {
		return -1;
	} else if(index == 1 && (price1[index].value < price2[index].value)) {
		return 1;
	}
	if(index == 2 && (price1[index].value == price2[index].value) && (price1[index].color == price2[index].color)) {
		checkDirection(price1,price2,index-1);
	} else if(index == 2 && (price1[index].value > price2[index].value)) {
		return -1;
	} else if(index == 2 && (price1[index].value < price2[index].value)) {
		return 1;
	} else if(index == 2) {
		return -1;
	}
}

node* addHome(node*root, Price price[],int index) {
	node*p = root;
	node*parent = NULL;
	int check;
	while(p!= NULL) {
		parent = p;
		
		if(price[0].value == p->price[0].value) {
			if(price[0].color == p->price[0].color) {
				check = checkDirection(price,p->price,2);
				if(check > 0) {
					p = p->right;
				} else {
					p = p->left;
				}
			} else {
				p = p->left;
				check = -1;
			}
		} else if(price[0].value < p->price[0].value) {
			p = p->left;
			check = -1;
		} else if (price[0].value > p->price[0].value) {
			p = p->right;
			check = 1;
		}

	}

	node* newNode = (node*)malloc(sizeof(node));

	newNode->price[0].value = price[0].value;
	newNode->price[1].value = price[1].value;
	newNode->price[2].value = price[2].value;
	newNode->price[0].color = price[0].color;
	newNode->price[1].color = price[1].color;
	newNode->price[2].color = price[2].color;

	newNode->index = index;
	if(parent != NULL) {
		//루트 아니면 알아서 처리
		if(check > 0) {
			parent->right = newNode;
		} else {
			parent->left = newNode;
		}
	}
	return newNode;
}

void checkColor(Price price[], int checkIndex[], int check) {
	int index = 0;
	if(check%2 == 0) {
		int i =0;
		for(i=0;price[i].color != 'r';i++);
		checkIndex[index++] = i;
	}
	check/=2;
	if(check%2 == 0) {
		int i =0;
		for(i=0;price[i].color != 'g';i++);
		checkIndex[index++] = i;
	
	}
	check/=2;
	if(check%2 == 0) {
		int i =0;
		for(i=0;price[i].color != 'b';i++);
		checkIndex[index++] = i;
	
	}

}


void paintNode(node* root) {
	node*p = root;
	int check = 0;
	if(p == NULL) return;
	paintNode(p->left);
	if(p->index == 0) {
	        check = homeIndex[p->index+1];
	} else	if(p->index == n-1) {
		check = homeIndex[p->index-1];
	} else {
		check = homeIndex[p->index+1] | homeIndex[p->index-1];
	}
	int checkIndex[3] = {-1,-1,-1};
	int min = 1001;
	checkColor(p->price,checkIndex,check);

	for(int i=0;(checkIndex[i] != -1 && i < 3);i++) {
		if(min > p->price[checkIndex[i]].value) {
			min = p->price[checkIndex[i]].value;
			if(p->price[checkIndex[i]].color == 'r') {
				check = 1;
			} else if(p->price[checkIndex[i]].color == 'g') {
				check = 2;
			} else {
				check = 4;
			}
		}
	}
	sum+=min;
	homeIndex[p->index] = check; 

	paintNode(p->right);
}


int main() {
	Price price[3];

	scanf("%d",&n);
	scanf("%d %d %d",&price[0].value,&price[1].value,&price[2].value);
	price[0].color = 'r';
	price[1].color = 'g';
	price[2].color = 'b';
	sortPrice(price);
	node*root = addHome(NULL,price,0);
	for(int i=1;i<n;i++) {	
		scanf("%d %d %d",&price[0].value,&price[1].value,&price[2].value);
		price[0].color = 'r';
		price[1].color = 'g';
		price[2].color = 'b';
		sortPrice(price);
		addHome(root,price,i);
	}
	
	paintNode(root);

	//여기까지 집을 모두 이진 탐색트리로 저장함
	printf("%d",sum);



	return 0;
}
