#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"
//prints the data for every node
void printAll(Node **head, char *name1, char *name2, char *name3, char *name4){
    Node *temp = *head;
    printHeader(name1, name2, name3, name4);
    //iterates through the whole linked list
    while((temp)!=NULL){
        printNode(temp);
        temp = temp->next;
    }
}