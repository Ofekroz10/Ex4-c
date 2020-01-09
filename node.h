#define NUM_LETTERS 26


typedef struct node {
	char letter;
	long unsigned int count;
	struct node* children[NUM_LETTERS];

} node;

node* newNode(char data);
void freeNode(node* p);
void addChildrenByPar(node** father, char par, char newLetter);
int contains(node* n,char c);
node* getNode(node* father, char c);