#include "node.h"

typedef struct thire {
	char param;
	node* head;
	int level;

} thire;

thire* newThire(char param);
void addWord(thire* t,char c[],int size);
void printWords(node* t,int level,char pre[]);
void freeT(thire* t);
