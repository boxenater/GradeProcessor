#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

//takes in the input from the client of part of a name or a full name of one of the students, then prints out the data for that student
int option2(Node **head, char *name1, char *name2, char *name3, char *name4){
    Node *temp = *head;
    char *name[80];
    int optIds[80];
    int numOfStudents = 0;
    //taking in input for the name or name segment
    printf("Enter the student's name: ");
    scanf("%s", name);
    //iterating through the linked list
    while(temp!=NULL&&numOfStudents<79){
        //checking if theres a substring
        if(strstr((const char*)&(temp->student.name), (const char*)(&name))!=NULL){
            //adding the student id to a list of options in case theres multiple
            optIds[numOfStudents] = temp->student.id;
            ++numOfStudents;
            printf("%d: %s\n", numOfStudents, temp->student.name);
        }
        temp = temp->next;
        //checking if no students matched hte name
    }if(numOfStudents==0){
        printf("No students found with that name\n");
        return -1;
        //checking if more than 1 student matched with the name
    } else if (numOfStudents>1){
        char in;
        //getting the desired student name and storing their id number at the front of the list of id numbers
        printf("Multiple options, please input 1-%d to select one:", numOfStudents);
        scanf("%d",&in);
        optIds[0] = optIds[(in)-1];
    }
    //resetting temp and iterating through the list again until the student with the matching id is found
        temp = *head;
        while(temp->student.id!=optIds[0]){
            temp = temp->next;
        }
        //printing out the student's details
        printHeader(name1,name2,name3,name4);
        printNode(temp);
    return -1;
}