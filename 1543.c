#include<stdio.h>


int strcompare(char *word, char *list) {
	char *dst = word;
	char *dst_list = list;
	int check = 1;
	do {
		if(*dst != *dst_list) {
			check = 0;
			break;
		}
		dst++;
		dst_list++;
	}while(*dst!='\0' && *dst_list!='\0');
	if(check > 0) return 1;
	else return 0;
}


int main() {
	char word[51];
	char list[2501];
	int count = 0;
	int wordlength;
	int check;

	scanf("%[^\n]s",word);
	scanf("%[^\n]s",list);

	for(wordlength=0;word[wordlength]!='\0';wordlength++);
	
	printf("leng: %d\n",wordlength);

	for(int i=0;list[i]!='\0';i++) {
		if(list[i] == word[0]) {
			check=strcompare(word,&list[i]);
			if(check > 0) {
				check = 0;
				printf("index: %d\n",i);
				i+=wordlength-1;
				count++;
				
			}
		}
	}
	printf("%d",count);

}
