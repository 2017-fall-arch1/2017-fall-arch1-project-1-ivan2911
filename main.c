#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

int input(char *s,int l);

// user input
void userInterface(){
    int ui;
    printf("Pick \n "
                   "1- Read file \n 2- Write file \n 3- Create a BST  \n 4- Quit \n");
    printf("-> ");
    scanf("%d", &ui);
    if(ui == 1){
        readFile();
    }
    else if(ui == 2){
        writeFile();
    }
    else if(ui == 3){
        createBST();
    }
    else if(ui == 4){
        printf(" Thanks! \n");
        return;
    }
}

int main(void) {

    printf("\n Welcome \n");
    userInterface();
    return 0;
}
