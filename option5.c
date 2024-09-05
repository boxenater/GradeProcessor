#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

//recalculates the grades of every student
int option5(Node **head, char *name1, char *name2, char *name3, char *name4){
    Node *temp = *head;
    float weights[4] = {0.15, 0.3, 0.2, 0.35};
    //iterating through whole linked list
    while(temp!=NULL){
    float current = 0;
    //iterating through every category
    for(int i = 0;i<4;i++){
        int numOfValid = 0;
        float cumulative = 0;
        //iterating through every score
        for(int j = 0;j<3;j++){
            //assigning and calculating cumulative
            if(temp->student.cat[i].scores[j]>=0){
                cumulative = cumulative + temp->student.cat[i].scores[j];
                ++numOfValid;
            }
        }
        //checks if there are valid scores
        if(numOfValid!=0){
            cumulative = cumulative/numOfValid;
            //backup for if no valid scores
        } else {
            cumulative = -1;
        }
        //storing cumulative
        temp->student.cat[i].cumulative = cumulative;
        }
        //loops for every category and calculates the current student's grade with weights
        for(int i = 0;i<4;i++){
            //if valid scores
        if(temp->student.cat[i].cumulative>=0){
            current = current + ((temp->student.cat[i].cumulative)*weights[i]);
            //if no valid scores
        } else {
            current = current + (100*weights[i]);
        }
        //assigning current grade
        temp->student.current_g = current;
    }
        temp = temp->next;
    }
    
    return -1;
}