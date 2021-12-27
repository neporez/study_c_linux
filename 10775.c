#include<stdio.h>
#include<stdlib.h>

typedef struct GATE {
	int value;
	struct GATE* next;
	struct GATE* pref;
}G;

G* addGate(int gate) {
	int index = 1;
	G* root = (G*)malloc(sizeof(G));
	root->value = index;
	root->next = NULL;
	root->pref = NULL;
	G* parent = root;
	while(index<gate) {
		index++;
		G* newNode = (G*)malloc(sizeof(G));
		newNode->value = index;
		newNode->pref = parent;
		parent->next = newNode;
		parent = parent->next;
	}

	return root;
}

int main() {
	G* root;
	G *p;
	G* _pref;
	G* _next;
	int gate,plane;
	int openGate = 1;
	int temp=0;
	int cnt = 0;
	scanf("%d",&gate);
	scanf("%d",&plane);

	root = addGate(gate+1);
	p = root;
	for(int i=0;i<plane;i++) {
		p =root;
		scanf("%d",&temp);
		if(openGate > 0) {
			if(p->value > temp || p->value== gate+1) {
				openGate = 0;
				continue;
			}
			while(p->value <= temp) {
				p = p->next;
			}
			
			p = p->pref;
			if(p->pref!=NULL) {
				_pref = p->pref;
			} else {
				_pref = NULL;
			}
			if(p->next!=NULL) {
				_next = p->next;
			} else {
				_next = NULL;
			}
			if(p->pref!=NULL) {
				_pref->next = _next;
			} else {
				root = _next;
				_next->pref = NULL;
			}
			if(p->next!=NULL) { 
				_next->pref = _pref;
			} else {
				_pref->next = NULL;
			}
			free(p);
			cnt++;
		}
	}
	printf("%d",cnt);
	





	return 0;
}
