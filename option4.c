#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

//gets a single student's grades and recalculates the cumulative and current grades
int option4(Node **head, char *name1, char *name2, char *name3, char *name4){
    Node *temp = *head;
    short *id = (short*)malloc(sizeof(short));
    //getting student id
    printf("Input the student's id:");
    scanf("%d", id);
    //checks if list is empty
    if(*head==NULL){
        printf("No Students Found\n");
        //prints the header and iterates until the end of the list or the correct node is found
    } else{
        printHeader(name1,name2,name3,name4);
        while((temp!=NULL)&&(temp->student.id!=*id)){
            temp = temp->next;
        }
    }
    //checking if the end of hte list was reached
    if(temp!=NULL){
        //iterating for every category
    for(int i = 0;i<4;i++){
        //storing cumulative info
        int numOfValid = 0;
        float cumulative = 0;
        //iterating for every grade
        for(int j = 0;j<3;j++){
            if(temp->student.cat[i].scores[j]>=0){
                //storing the grade and cumulative info if the score isnt negative
                cumulative = cumulative + temp->student.cat[i].scores[j];
                ++numOfValid;
            }
        }
        //checks if there are valid scores
        if(numOfValid!=0){
            cumulative = cumulative/numOfValid;
            //backup in case no valid scores
        } else {
            cumulative = -1;
        }
        //assigns cumulative grade
        temp->student.cat[i].cumulative = cumulative;
    }
    //alerts the user if no student is found
    } else {
        printf("Student Not Found");
    }
    return -1;
}