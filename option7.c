#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

//calculates the final grades for every student
int option7(Node **head, char *name1, char *name2, char *name3, char *name4){
    Node *temp = *head;
    //print header
    printHeader(name1, name2, name3, name4);
    float weights[4] = {0.15, 0.3, 0.2, 0.35};
    //iterates through whole list
    while((temp)!=NULL){
        float final;
        //iterates through every category
        for(int i = 0;i<4;i++){
            //calculates final grade
            if(temp->student.cat[i].cumulative>=0){
            final = final + ((temp->student.cat[i].cumulative)*weights[i]);
            }
        }
        //assigns final grade
        temp->student.final_g = final;
        temp = temp->next;
        final = 0;
    }
    //prints out every node
    option3(head, name1, name2, name3, name4);
    return -1;
}