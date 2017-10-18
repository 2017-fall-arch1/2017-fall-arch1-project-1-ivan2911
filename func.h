#ifndef func_h
#define func_h


typedef struct node {
    struct node *leftChild;
    struct node *rightChild;
    char *data;
} node;

void readFile();

void writeFile();

int cnoliatf(char *filename);

void createBST();

void deleteE(node* root);

void nextS(node *r);

void clearFile();

void addE(node *r);

void wueitf(char *employee);

struct node *newN(char *d);

struct node *insert(node* r, char* d);

struct node *maxN(node *r);

struct node *deleteN(node* r, char* d);

void printTree(node* r, int h);

void userInterface();

double result;

#endif //func_h
