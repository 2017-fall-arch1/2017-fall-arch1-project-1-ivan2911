#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fptr;
char buffer[32];
char *b = buffer;
size_t bufsize = 32;
size_t characters;

/* read a file */
void readFile(){
    int x;
    fptr = fopen("ListOfEmployees.txt", "r");
    if (fptr) {
    	rintf("\n Reading  \n");
    while ((x = getc(fptr)) != EOF)
        putchar(x);
    	printf("\n");
   		fclose(fptr);
  		printf(" Done Reading \n");
    }
    userInterface();
}

/* writes the First and Last name into the file */
void writeFile(){
    fptr = fopen("ListOfEmployees.txt", "a");
    if (fptr == NULL) {
        printf("check .txt file location");
    }
    else {
        printf("\n Start writing  \n");
        getchar();
        printf("F and L name: \n");
        characters = getline(&b, &bufsize, stdin);
        printf("\n");
        printf("No more writing \n \n");
        const char *text = buffer;
        fprintf(fptr, "%s", text);
        fclose(fptr);
    }
    userInterface();
}

 //countNumberOfLinesInATextFile
int cnoliatf(char* filename){
    int x;
    fptr = fopen("ListOfEmployees.txt", "r");
    int counter = 0;
    if (fptr) {
        printf("\n Counter Begins \n");
        while ((x = getc(fptr)) != EOF)
            if (x == '\n')
                counter++;
        fclose(fptr);
        printf("end counter\n \n");
        return counter;
    }
    return -1;
}

// nol = # lines
void createBST() {
    node *r = NULL;
    FILE *file = fopen("ListOfEmployees.txt", "r");
    int nol = cnoliatf(file);
    printf("\n %s %d %s", "# lines: ", nol, "\n");
    char line[nol][256];
    if (file) {
        printf("\n BST creation \n");
        r = newNode(0);
        int i=0;
        while (fgets(line[i], sizeof(line), file) != 0) {
            insert(r, line[i]);
            i++;
        }
        fclose(file);
        printf(" BST Done \n \n");
        result = log(nol+1)/log(2);
        printTree(r, 1);
        nextState(r);
    }
}

void deleteE(node* r){
    getchar();
    char userInput[256];
    int next;

    printf("name of fired employee\n");
    fgets(userInput, 256, stdin);

    printf("%s %s %s", "you sure?", userInput, "1- Yes \n 2- No \n");

    scanf("%d", &next);
    if(next == 1){
        deleteNode(r, userInput);
        clearTextFile(r);
        addUpdatedEmployees(r);
        printTree(r, result);
    }
    else
        printf("%s %s\n", "make sure next time", userInput);
    userInterface();
}

void nextS(node *r){
	//user input
    int ui;
    printf("Choose: (number) \n 1- Fire \n 2- Quit\n");
    scanf("%d", &ui);
    if(ui == 1){
        deleteEmployee(r);
    }
    if(ui == 2) {
        printf("Later\n");
    }
}

void clearFile(){
    fclose(fopen("ListOfEmployees.txt", "w"));
}

void addE(node *r){
    int i;

    if(r){
        addUpdatedEmployees(r->leftChild);
        char *emp = r->data;
        printf("%s\n", emp);
        writeUpdatedEmployeesInTextFile(emp);
        addUpdatedEmployees(r->rightChild);
    }
}

//write updated employees in text file
void wueitf(char *employee){
    fptr = fopen("ListOfEmployees.txt", "a");
    if (fptr == NULL) {
        printf("Check .txt location");
    }
    else {
        fputs(employee, fptr);
        fclose(fptr);
    }
}

node *newN(char *d){

    node *newN = NULL;
    newN=malloc(sizeof(node));
    if(newN == NULL){
        exit(1);
    }
    newN->data = d;
    newN->leftChild = NULL;
    newN->rightChild = NULL;
    return newN;
}

// data and root
node *insert(node* r, char* d){

    if(!r->data){
        r->data = d;
    }
    else{
        int compare;
        compare = strcmp(d, r->data);

        if(compare == 0) {
            printf("We already have that employee in our system\n");
        }

        else if (compare > 0){
            if(r->leftChild) {
                return insert(r-> leftChild, d);
            }
            else {
                r-> leftChild = newN(d);
            }
        }
        else{
            if(r->rightChild) {
                return insert(r->rightChild, d);
            }
            else {
                r->rightChild = newN(d);
            }
        }
    }
    return r;
}

node *maxN(node* r){
    if(r == NULL){
        return NULL;
    }
    node *temp = r;
    while(temp->rightChild != NULL){
        temp = temp->rightChild;
    }
    return temp;
}

node *deleteN(node* r, char* d){
    node *temp = NULL;

    if(r == NULL) {
        return r;
    }
    int result;
    result = strcmp(r->data, d);
    if(result < 0) {
        r->leftChild = deleteN(r->leftChild, d);
    }
    else if(result > 0){
        r->rightChild = deleteN(r->rightChild, d);
    }
    else{
        if(r->leftChild == NULL && r->rightChild == NULL){
            free(r);
            return NULL;
        }
        else if(r->leftChild == NULL){
            temp = r->rightChild;
            free(r);
            return temp;
        }
        else if(r->rightChild == NULL){
            temp = r->leftChild;
            free(r);
            return temp;
        }
        temp = maxN(r->leftChild);
        r->data = temp->data;
        r->leftChild = deleteN(r->leftChild, temp->data);
    }
    return r;
}

//  height
void printTree(node* r, int h){
    int i;
    if(r){
        printTree(r->leftChild, h+1);
        for(i = 0; i < h; i++)
            printf("             ├──  ");
        printf("%s\n", r->data);
        printTree(r->rightChild, h+1);
    }
}
