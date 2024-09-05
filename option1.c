#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

//takes in user input of student id, so that students data can be printed out
int option1(Node **head, char *name1, char *name2, char *name3, char *name4){
    Node *temp = *head;
    short *id = (short*)malloc(sizeof(short));
    //asking for id number
    printf("Input the student's id:");
    scanf("%d", id);
    //checking if there are students in the linked list
    if(*head==NULL){
        printf("No Students Found\n");
    //iterating through the list until the right node is found or the list ends
    } else{
        //print header
        printHeader(name1,name2,name3,name4);
        //iterating through the linked list
        while((temp!=NULL)&&(temp->student.id!=*id)){
            temp = temp->next;
        }
        //checking if the user wasn't found in the linked list
        if(temp==NULL){
            printf("No student found with such id");
        } else {
            //printing node if the right one was found
            printNode(temp);
        }
    }
    //freeing the id pointer and returning
    free(id);
    return -1;
}