#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

// Reads in student information from a file and creates a Node struct with the information, returns -1 if the file has ended.
int createNode(FILE *records, Node *ret){
    // initializing variables
    Node *newNode;
    newNode = (Node*)malloc((18*sizeof(float))+(80*sizeof(char*))+sizeof(short)+sizeof(Node*));
    float current = 0;
    float weights[4] = {0.15, 0.3, 0.2, 0.35};
    newNode->student.final_g = -1;
    // setting name of the new node and checking if the reading file is empty
    if(fscanf(records,"%[^\n]s",newNode->student.name)==EOF){
        return -1;
    }
    //populating the node with new scores in a for loop
    fscanf(records,"%d\n",&(newNode->student.id));
    for(int i = 0;i<4;i++){
        fillCategory(records, &(newNode->student.cat[i]));
        //calculating the current grade weighted from every category
        if(newNode->student.cat[i].cumulative>=0){
            current = current + ((newNode->student.cat[i].cumulative)*weights[i]);
        } else {
            current = current + (100*weights[i]);
        }
    }
    //assigning current grade to the new node, and assigning the new node to the inputted pointer
    newNode->student.current_g = current;
    newNode->next=NULL;
    *ret = *newNode;
    return 0;
}