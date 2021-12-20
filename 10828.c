#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int size = 0;

typedef struct stack_int {
	int value;
	struct stack_int* tail;
} STACK;

STACK* pushStack(STACK* root, int value) {
	STACK* newNode = (STACK*)malloc(sizeof(STACK));
	newNode->value = value;
	newNode->tail = root;
	return newNode;
}

STACK* popStack(STACK*root) {
	if(root == NULL) {
	 	printf("-1\n");      
		return NULL;
	}
	STACK* p=root;
	printf("%d\n",p->value);
	root = root->tail;
	free(p);
	size--;
	return root;
}



int main() {
	int n;
	STACK * root = NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		char temp[7];
		scanf("%s",temp);
		if(strcmp(temp,"push") == 0) {
			int v;
			scanf("%d",&v);
			root = pushStack(root,v);
			size++;
		}
		if(strcmp(temp,"pop") == 0) {
			root = popStack(root);
		}
		if(strcmp(temp,"empty") == 0) {
			if(size > 0) {
				printf("0\n");
			} else {
				printf("1\n");
			}
		}
		if(strcmp(temp, "top") == 0) {
			if(size > 0) {
				printf("%d\n",root->value);
			} else {
				printf("-1\n");
			}
		}
		if(strcmp(temp, "size") == 0) {
			printf("%d\n",size);
		}
	}


	return 0;
}
