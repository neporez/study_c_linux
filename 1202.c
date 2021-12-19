#include<stdio.h>
#include<stdlib.h>


#define SWAP(x,y,temp) ((temp) = (x), (x)=(y), (y) =(temp)) 



typedef struct bag {
	struct bag* left;
	struct bag* right;
	int value;
}node;

typedef struct jewel {

	int weight;
	int value;

}JEWEL;

JEWEL jewel[300000];
int sum=0;


int partition_jewel(JEWEL jewel[], int left , int right) {
	int pivot;
	int low,high;
	JEWEL temp;
	low = left;
	high = right+1;
	pivot = jewel[left].value;


	do {
		do{
			low++;
		}while(pivot < jewel[low].value && low<=right);
		
		do {
			high--;
		}while(pivot > jewel[high].value && left<=high);

		if(low< high) {
			SWAP(jewel[low],jewel[high],temp);
		}
	}while(low<high);

	SWAP(jewel[left],jewel[high],temp);
	
	return high;


}

void q_sort(JEWEL jewel[],int left, int right) {
	if(left < right) {
		int q = partition_jewel(jewel,left,right);

		q_sort(jewel,left,q-1);
		q_sort(jewel,q+1,right);
	}
}

node* addBag(node* root,int value) {
	node *p = root;
	node *parent = NULL;
	while(p!=NULL) {
		parent = p;
		if(p->value < value) {
			p = p->right;
		} else if(p->value >= value) {
			p = p->left;
		}
	}
	node* newNode = (node*)malloc(sizeof(node));
	newNode->left = newNode->right = NULL;
	newNode->value = value;
	if(parent!=NULL) {
		if(parent->value < value) {
			parent->right = newNode;
		} else if(parent->value >= value) {
			parent->left = newNode;
		}
	}
	return newNode;
}
void deleteBag(node*p, node*parent);
int searchBag(node* root, int weight) {
	int check = 0;
	node* temp = root;
	node* parent= NULL;
	while(1) {
		if(temp->value < weight && check == 1) {
			deleteBag(temp,parent);
			return 1;
		}
		if(temp->value >= weight) check = 1;
		if(temp->left == NULL && temp->right == NULL && check == 0) {
			return 0;
		}
		if(temp->left == NULL && temp->right == NULL && check == 1) {
			deleteBag(temp,parent);
			return 1;
		}
		if(check == 0 && temp->right!=NULL) {
			parent = temp;
			temp = temp->right;
				
		} else if(check == 1 && temp->left!=NULL) {
			parent = temp;
			temp = temp->left;
		}
		
	}

}

void deleteBag(node*p, node* parent) {
	node * temp;
	if(parent == NULL) {
		free(p);
		return;
	}

	if(p->left!=NULL && p->right==NULL) {
		temp = p->left;
		while(temp->right != NULL) {
			temp = temp->right;
		}
		if(parent->value>=p->value) {
			parent->left = temp;
		} else {
			parent->right =temp;
		}
		temp->left = p->left;
	} else if(p->right !=NULL && p->left==NULL) {
		temp = p->right;
		while(temp->left != NULL) {
			temp = temp->left;
		}
		if(parent->value>=p->value) {
			parent->left = temp;
		} else {
			parent->right = temp;
		}
		temp->right = p->right;

	} else if(p->right!=NULL && p->left!=NULL) {
		temp = p->right;
		while(temp->left != NULL) {
			temp = temp->left;
		}
		if(parent->value>=p->value) {
			parent->left = temp;
		} else {
			parent->right = temp;
		}
		temp->right = p->right;
		temp->left = p->left;
	} else {
		if(parent->value>=p->value) {
			parent->left = NULL;
		} else {
			parent->right =NULL;
		}
	}
	free(p);
}





int main() {
	int jewel_count,bag_count;
	int jewel_index = 0;
	int temp;	


	scanf("%d %d",&jewel_count,&bag_count);

	for(int i=0;i<jewel_count;i++) {
		scanf("%d %d",&jewel[i].weight,&jewel[i].value);
	}
	q_sort(jewel,0,jewel_count-1);
	scanf("%d",&temp);

	node* root = addBag(NULL, temp);

	for(int i=0;i<bag_count-1;i++) {
		scanf("%d",&temp);
		addBag(root,temp);
	}

	while(jewel_count != jewel_index && bag_count > 0) {
		int weight = jewel[jewel_index].weight;
		int value = jewel[jewel_index++].value;
		int check = 0;

		check = searchBag(root,weight);
		if(check > 0) {
			sum+=value;
			bag_count--;
		}
	}
	printf("%d",sum);


	return 0;
}
