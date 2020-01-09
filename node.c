#include "node.h"
#define ENDWORD '`'




void alloChild(node** childArray)
{
	*childArray = (node*)realloc(*childArray, sizeof(node));
}

node* newNode(char data)
{
	const static node DEFAULT = { .children = { 0 } };
	node *p = (node*)malloc(sizeof(node));
	*p = DEFAULT;
	if (p == 0) {
		printf("Memory allocation failed\n");
		return;
	}
	p->letter = data;
	p->count = 0;

	return p;
}

void addChildrenByPar(node** father, char par,char newLetter)
{
	node* p = *father;
	int  leaf = 0;
	if (newLetter == ENDWORD)
	{
		if (contains((*father), ENDWORD))
		{
			node* leaf = getNode((*father), ENDWORD);
			leaf->count++;
			return;
		}
		else
		{
			leaf = 1;
		}
	}
	node* newItem = newNode(newLetter);
	newItem->count = leaf;
	if (p->count == 0) //if no childrens
	{
		p->children[0] = newItem;
		p->count++;
	}
	else
	{
		if (newLetter - par > 0) 
		{
			int temp2 = newLetter - par; 
			int i = 0;
			while (i<NUM_LETTERS&&p->children[i] != 0)
			{
				int temp1 = p->children[i]->letter - par;
				if (temp1 < 0)
					break;//win
				else {
					if (temp2 < temp1)
						break;
				}
				i++;
			}
			if (p->children[i] == 0)
			{
				p->children[i] = newItem;
			}
			else if (p->children[i]->letter == newLetter)
				return;
			else if (p->children[i]->letter != 0)
			{
				node* newL = newItem;
				node* temp;
				while (i < NUM_LETTERS&&p->children[i]!= 0)
				{
					temp = p->children[i];
					p->children[i] = newL;
					newL = temp;
					i++;
				}
				p->children[i] = newL;
			}
		}
		else
		{
			int temp2 = newLetter - par; //-2
			int i = 0;
			while (i<NUM_LETTERS&&p->children[i] != 0)
			{
				int temp1 = p->children[i]->letter - par;//-3
				if (temp1 > 0)
					break;//win
				else {
					if (temp2 > temp1)
						break;
				}
				i++;
			}
			if (p->children[i] == 0)
			{
				p->children[i] = newItem;
			}
			else if (p->children[i]->letter == newLetter)
				return;
			else if (p->children[i]->letter != 0)
			{
				node* newL = newItem;
				node* temp;
				while (i < NUM_LETTERS&&p->children[i] != 0)
				{
					temp = p->children[i];
					p->children[i] = newL;
					newL = temp;
					i++;
				}
				p->children[i] = newL;
			}
		}
	}
	p->count++;

}
void freeNode(node* n)
{
	if (n == 0)
	{
		return;
	}
	
		node* p = n->children[0];
		for (int i = 0; i < NUM_LETTERS; i++)
		{
			if (p!= 0)
			{
				freeNode(p);
				p = (n->children[i + 1]);
			}
			else
			{
				break;
			}
		}
		free(n);
	
}

int contains(node* n,char c)
{
	if (n == 0)
		return 0;
	if (n->count == 0)
		return 0;

	for (int i = 0; i < n->count; i++)
	{
		if(n->children[i]==0)
			break;
		if (n->children[i]->letter == c)
			return 1;
	}
	return 0;
	
}
node* getNode(node* father, char c)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		if (father->children[i]->letter == 0)
			break;
		else if (father->children[i]->letter == c)
			return father->children[i];
	}
	return 0;
}