#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

void printAndFree(FILE *printy, Node **head, char *name1, char *name2, char *name3, char *name4){
    Node* temp = *head;
    Node *prev;
    fprintf(printy, "%s %s %s %s", name1, name2, name3, name4);
    //prints cat names and frees them
    free(name1);
    free(name2);
    free(name3);
    free(name4);
    //iterates through whole linked list
    while(temp!=NULL){
        //prints out name and id
        fprintf(printy, "%s\n%d\n",temp->student.name,temp->student.id);
        //iterates through every score and category
        for(int i = 0;i<4;i++){
            for(int j =0;j<3;j++){
                //prints out new line every third score
                if(j==2){
                    fprintf(printy,"%.2f\n",temp->student.cat[i].scores[j]);
                } else {
                    fprintf(printy,"%.2f\t",temp->student.cat[i].scores[j]);
                }
            }
        }
        //frees data
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    //closes file
    if(fclose(printy)!=0){
        printf("fclose failed");
        exit(EXIT_FAILURE);
        }
        //frees data
    free(temp);
    free(head);
}