#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

//takes in input of a student's id and changing a score 
int option6(Node **head, char *name1, char *name2, char *name3, char *name4){
    Node *temp = *head;
    short *id = (short*)malloc(sizeof(short));
    char *score_num = (char*)malloc(sizeof(char));
    float *newScore = (float*)malloc(sizeof(float));
    //taking in id
    printf("Input the student's id:");
    scanf("%d", id);
    //checks if list empty
    if(*head==NULL){
        printf("No Students Found\n");
        //iterates until end of list or finding node
    } else{
        while((temp!=NULL)&&(temp->student.id!=*id)){
            temp = temp->next;
        }
        //if found end of list
        if(temp==NULL){
            printf("No student found with such id");
            //if the right node was found gathers input of what score to change
        } else {
            printf("Input which category you would like to change the score of;\n%s = 1, %s = 2, %s = 3, %s = 4\nCategory:",name1, name2, name3, name4);
            scanf("%d", id);
            printf("Would you like to change score 1, 2, or 3:");
            scanf("%d", score_num);
            printf("What is the new value:");
            scanf("%.2f", newScore);
            //reassigns the score
            temp->student.cat[(*id)-1].scores[(*score_num)-1] = *newScore;
        }
    }
    //frees id
    free(id);
    return -1;
}