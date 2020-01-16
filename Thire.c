#include "Thire.h"
#define ENDWORD '`'


void print(char arr[], int level,node* leaf)
{
	for (int i = 0; i < level; i++)
	{
		printf("%c",arr[i]);
	}
	printf("\t");
	printf("%d", leaf->count);
	printf("\n");
}

thire* newThire(char param)
{
	thire* p = (thire*)malloc(sizeof(thire));
	if (p == 0)
	{
		printf("Eror to alloc");
		return;
	}
	else
	{
		p->param = param;
		p->head = newNode(' ');
		p->level = 0;
	}
	return p;
}
void addWord(thire* t,char c[], int size)
{
	if (t == 0)
		return;
	node* head = t->head;
	for (int i = 0; i < size; i++)
	{
		char cur = c[i];
		if (contains(head, cur) == 0)
		{
			addChildrenByPar(&head, t->param, cur);
		}
		head = getNode(head, cur);
	}
	addChildrenByPar(&head, t->param, ENDWORD);
	if (t->level < size)
		t->level = size;
}

void printWords(node* t,int level,char pre[])
{
	if (t == 0)
		return;

	for (int i = 0; i < NUM_LETTERS; i++)
	{
		if (t->children[i] == 0)
			return;
		char c = t->children[i]->letter;
		if (c == ENDWORD)
		{
			print(pre,level,t->children[i]);
		}
		else
		{
			pre[level] = c;
		}
		printWords(t->children[i],level+1,pre);
	}
}
void freeChildrens(node* n)
{
	if (n == 0)
	{
		return;
	}
	freeNode(n);
}
void freeT(thire* t)
{
	if (t == 0)
		return;
	freeChildrens(t->head);
	free(t);
}
