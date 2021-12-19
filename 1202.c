#include<stdio.h>
#include<stdlib.h>


#define SWAP(x,y,temp) ((temp) = (x), (x)=(y), (y) =(temp)) 



typedef struct bag {
	struct bag* left;
	struct bag* right;
	int value;
}node;

typedef struct jewel {
	
	struct jewel* left;
	struct jewel* right;

	int weight;
	int value;

}node_j;

int sum=0;
int jewel_count,bag_count;

node_j* addJewel(node_j* root,int weight,int value) {
	node_j *p = root;
	node_j *parent = NULL;
	while(p!=NULL) {
		parent = p;
		if(p->value < value) {
			p = p->left;
		} else if(p->value >= value) {
			p = p->right;
		}
	}
	node_j* newNode = (node_j*)malloc(sizeof(node_j));
	newNode->left = newNode->right = NULL;
	newNode->weight = weight;
	newNode->value = value;
	if(parent!=NULL) {
		if(parent->value < value) {
			parent->left = newNode;
		} else if(parent->value >= value) {
			parent->right = newNode;
		}
	}
	return newNode;
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

void searchingJewel(node_j* jewel, node* root);

void stealing(node_j* root_j,node* root) {
	node_j* p = root_j;
	searchingJewel(p,root);
}

void searchingJewel(node_j* jewel,node* root) {
	if(jewel == NULL) return;
	searchingJewel(jewel->left,root);
	if(bag_count == 0 || jewel_count ==0) return;
	int check = searchBag(root,jewel->weight);
	if(check > 0) {
			sum+=jewel->value;
			bag_count--;
	}
	jewel_count--;
	searchingJewel(jewel->right,root);
	if(bag_count == 0 || jewel_count ==0) return;
}





int main() {
	int temp,temp2;	


	scanf("%d %d",&jewel_count,&bag_count);
	
	scanf("%d %d", &temp, &temp2);

	node_j* root_j = addJewel(NULL, temp, temp2);

	for(int i=0;i<jewel_count-1;i++) {
		scanf("%d %d",&temp,&temp2);
		addJewel(root_j,temp,temp2);
	}
	scanf("%d",&temp);

	node* root = addBag(NULL, temp);

	for(int i=0;i<bag_count-1;i++) {
		scanf("%d",&temp);
		addBag(root,temp);
	}
	stealing(root_j,root);
	printf("%d",sum);


	return 0;
}
