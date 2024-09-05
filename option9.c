#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

// deletes a node with user inputted id
int option9(Node **top){
    short id;
    printf("enter the student's id:");
    scanf("%d", &id);
    // deleteNode(top, id);
    Node *temp = *top;
    Node *freer;
    //checking if the entire array of nodes is empty
    if(*top==NULL){
        printf("No Students Found\n");
        return -1;
    //checking if the top node needs to be removed
    }else if((*(*top)).student.id==id){
        printf("%s was successfully deleted\n", temp->student.name);
        *top = (*(*top)).next;
        free(temp);
        return 1;
    //checking if there is only 1 node that doesnt need to be deleted
    } else if ((*temp).next==NULL){
        printf("Student not found\n");
        return -1;
    //checking through the linked list to find the student with the matching id number
    } else {
        //iterating with a while loop until the node is found or the list ends
        while(((*temp).next->next!=NULL)&&((*temp).next->next->student.id!=id)){
            temp = temp->next;
        }
        // checking if the end of list was reached
        if((*temp).next->next==NULL){
            printf("Student not found\n");
            return -1;
        //code if the student node was found
        } else {
            //reroutes the nodes around the one to be deleted, so there is a straight line without the removed node, then frees the node's data
            temp = temp->next;
            freer = temp->next;
            (*temp).next = (*freer).next;
            printf("%s was successfully deleted\n", freer->student.name);
            free(freer);
            return 1;
        }
}
}