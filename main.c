#include "Thire.h"
#include <stdio.h>
#define REGULAR 96 //a-1
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <stdbool.h>
#define REVERSE 123 //z+1
#define A_LOWER 97
#define A_UPPER 65
#define Z_LOWER 122
#define Z_UPPER 90
#define SPACE 32

 char* SplitString(char* str, char sep)
{
    char* ret = str;
    for(ret = str; *str != '\0'; ++str)
    {
        if (*str == sep)
        {
            *str = '\001';
        }
    }
    return ret;
}
 
void printArr(int size, node* arr)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d%c%c", i, ' ',arr->letter);
        printf("\n");
        arr++;
    }
}

int main(int argc, char **argv)
 
{
    char a;
    int i = 0;
    char *str =0;
    while ((a = getchar()) != EOF && a!= '\n')
    {
		if(((a>=A_UPPER && a<=Z_UPPER)|| a>=A_LOWER && a<=Z_LOWER)||a ==SPACE)
		{
		if(a>=A_UPPER && a<=Z_UPPER )
		a = a+SPACE;
        str = realloc(str, i + 2);   //1 for character to store, + 1 for '\0' terminating character
        str[i++] = a;
		}
    }
    str[i] = '\0';
   
    char *output, *temp;
    bool done = false;
	 char * field;
     thire* t;
     if(argc<2)
     {
	    t = newThire(REGULAR);
     }
     else
     {
         t = newThire(REVERSE);
     }
     
    output = SplitString(str, ' ');
	field=output;
    int cnt = 1;
    for( temp = field; *output != '\0' && !done; )
    {
        for(temp = output; *temp > '\001'; ++temp) ; 
        if (*temp == '\000') done=true;
        *temp = '\000';
        addWord(t,output,strlen(output));
        output = ++temp;
    }
    char* pre = (char*)malloc(t->level + 1);
    pre[t->level] = '\0';
    printWords(t->head, 0, pre);
	free(pre);
	freeT(t);
	free(str);
    /*
    node* n = newNode('a');
    addChildrenByPar(&n, 'a', 'a');
    addChildrenByPar(&n, 'a', 'c');
    addChildrenByPar(&n, 'a', 'z');
    addChildrenByPar(&n, 'a', 'j');
    addChildrenByPar(&n, 'a', 'h');
    addChildrenByPar(&n, 'a', 'x');
    addChildrenByPar(&n, 'a', 't');
    addChildrenByPar(&n, 'a', 's');
    addChildrenByPar(&n, 'a', 'e');
    addChildrenByPar(&n, 'a', 'd');
    printf("%c", n->children[0]->letter);
    printf("%c", n->children[1]->letter);
    printf("%c", n->children[2]->letter);
    printf("%c", n->children[3]->letter);
    printf("%c", n->children[4]->letter);
    printf("%c", n->children[5]->letter);
    printf("%c", n->children[6]->letter);
    printf("%c", n->children[7]->letter);
    printf("%c", n->children[8]->letter);
    printf("%c", n->children[9]->letter);
    freeNode(n);*/
    /*
    thire* t = newThire(REGULAR);
    char name[] = "an";
    addWord(t,name,(sizeof(name)/sizeof(char))-1);
    char name1[] = "ant";
    addWord(t, name1, (sizeof(name1) / sizeof(char))-1);
    char name2[] = "all";
    addWord(t, name2, (sizeof(name2) / sizeof(char))-1);
    char name3[] = "allot";
    addWord(t, name3, (sizeof(name3) / sizeof(char))-1);
    char name4[] = "alloy";
    addWord(t, name4, (sizeof(name4) / sizeof(char))-1);
    char name5[] = "aloe";
    addWord(t, name5, (sizeof(name5) / sizeof(char))-1);
    char name6[] = "are";
    addWord(t, name6, (sizeof(name6) / sizeof(char))-1);
    char name7[] = "ate";
    addWord(t, name7, (sizeof(name7) / sizeof(char))-1);
    char name8[] = "be";
    addWord(t, name8, (sizeof(name8) / sizeof(char))-1);
    char name9[] = "ate";
    addWord(t, name9, (sizeof(name9) / sizeof(char)) - 1);
    char* pre = (char*)malloc(t->level+1);
    pre[t->level] = '\0';
    printWords(t->head,0,pre);
    int x = 0;
    scanf_s("%d", &x);
    */
    return 0;
}