//I had the issue of trying to figure out why my code was segment faulting repeatedly when testing my node constructor.
//After trying repeatedly to get it to work, I couldnt get the faults to disappear. Then I used the gdb breakpoints to
//figure out where my segment faults were coming from. It turns out I had make scanf statements wrong outside of a function call. 
//As well as segment faulting scanf statements inside the function call too so I never noticed when the first problem was fixed.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

// Author: Sam Doerfler
// Program acts as a database for student grades, giving the user many options to read through and edit different scores or calculate current and final grades.
int main(int argc, char *argv[]){
    //initializing variables and pointers
    Node *temp;
    Node **head;
    int (*fp[8])(Node**, char*, char*, char*, char*);
    fp[1] = option1;
    fp[2] = option2;
    fp[3] = option3;
    fp[4] = option4;
    fp[5] = option5;
    fp[6] = option6;
    fp[7] = option7;
    char option;
    //allocating space and opening reading files
    char *name1 = calloc(20,sizeof(char));
    char *name2 = calloc(20,sizeof(char));
    char *name3 = calloc(20,sizeof(char));
    char *name4 = calloc(20,sizeof(char));
    FILE *records = fopen(argv[1], "r");
    temp = (Node*)malloc((18*sizeof(float))+(80*sizeof(char*))+sizeof(short)+sizeof(Node*));
    head = (Node**)malloc(sizeof(sizeof(Node*)));
    //checking that the file can be read first
    if(records!=NULL){
        //storing category names
        fscanf(records, "%s ", name1);
        fscanf(records, "%s ", name2);
        fscanf(records, "%s ", name3);
        fscanf(records, "%s ", name4);
        //creating nodes and inserting them in order
        while(createNode(records, temp)!=-1){
            insertNode(head, temp);
            temp = (Node*)malloc((18*sizeof(float))+(80*sizeof(char*))+sizeof(short)+sizeof(Node*));
        }
        //asking the user for which function they would like to call, then calling the apropriate subfunction
        do{
        printf("Please enter an option from 1-10\n1. Request student information from student id number\n2. Request student information from last name\n3. Print all student information\n4. Recalculate a student's grade\n5. Recalculate all student's grades\n6. Insert a new score for a student\n7. Calculate final grades\n8. Add a new student to the class\n9. Delete a student\n10. Exit the program\nOption:");
        scanf("%d",&option);
        //checking if the function can be called from the array of functions with the same parameters and returns, then checking the other potential function calls
        if(option<=7){
            fp[option](head, name1, name2, name3, name4);
        }else if(option==8){
            option8(head, name1, name2, name3, name4);
        }else if(option==9){
            option9(head);
            // printNode(*head);
        }
        //telling the loop to stop if the user puts in 10
        } while(option!=10);
        //closing the file because no more reading needs to be done
        if(fclose(records)!=0){
        //telling the user if there was a problem closing the file
        printf("fclose failed");
        exit(EXIT_FAILURE);
        }
        //opening the printing file now that the user is done, and printing all the data into the file name put in the command line
        FILE *printy = fopen(argv[2], "w");
        printAndFree(printy,head,name1,name2,name3,name4);
    }
}