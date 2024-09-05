#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"


// inserts the given node into the linked list in ascending order by id number
void insertNode(Node** top, Node* data){
    //checking if the node is empty and needs to have the head created
    if(*top==NULL){
        *top = data;
        (*data).next = NULL;
    //checking if the new node should replace the head
    } else if ((*top)->student.id > data->student.id){
        (*data).next = *top;
        *top = data;
    //iterating through the linked list until the end of the list or until the node's id fits in chronologically
    } else {
        Node *temp = *top;
        while((*temp).next != NULL){
            if(temp->next->student.id > data->student.id){
                break;
            }
            temp = (*temp).next; 
        }
        //making the previous node point to the new one and making the new one point to the correct next node
        (*data).next = temp->next;
        (*temp).next = data;
    }
}