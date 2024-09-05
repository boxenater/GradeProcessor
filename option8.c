#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

//creates a new node to add to the class and inserts it into the list
void option8(Node **top, char *name1, char *name2, char *name3, char *name4){
    char *name[4] = {name1, name2, name3, name4};
    Node *newNode = (Node*)malloc((18*sizeof(float))+(80*sizeof(char*))+sizeof(short)+sizeof(Node*));
    float current = 0;
    float weights[4] = {0.15, 0.3, 0.2, 0.35};
    newNode->student.final_g = -1;
    //gets name input
    printf("Student Name (Last, First):");
    getchar();
    scanf("%[^\n]s",&(newNode->student.name));
    printf("Student id:");
    //gets id
    scanf("%d", &(newNode->student.id));
    //iterates through categories
    for (int i = 0;i<4;i++){
        int numOfValid = 0;
        float cumulative = 0;
        //iterates through scores
        for(int j = 0;j<3;j++){
            //takes in input 
            printf("Enter %s grade number %d:",name[i],j+1);
            scanf("%f",&(newNode->student.cat[i].scores[j]));
        if(newNode->student.cat[i].scores[j]>=0){
            //assigns cumulative scores
            cumulative = cumulative + newNode->student.cat[i].scores[j];
            ++numOfValid;
        }
    }
    //checks if valid scores
    if(numOfValid!=0){
        cumulative = cumulative/numOfValid;
        //if no valid scores
    } else {
        cumulative = -1;
    }
    //assigns cumulative and calculates current
        newNode->student.cat[i].cumulative = cumulative;
        if(newNode->student.cat[i].cumulative>=0){
            current = current + ((newNode->student.cat[i].cumulative)*weights[i]);
        } else {
            current = current + (100*weights[i]);
        }
    }
    //assigns variables
    newNode->student.current_g = current;
    newNode->next=NULL;
    insertNode(top, newNode);
}