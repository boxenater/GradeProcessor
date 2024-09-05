#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

//prints out a node
void printNode(Node *n){
    //prints out the name and id
    printf("%17s\t%d\t",(*n).student.name,(*n).student.id);
    //iterates through categories
    for(int i = 0;i<4;i++){
        //iterates through the scores 
        for(int j = 0;j<3;j++){
            //prints out the scores if they arent -1
            float score = (*n).student.cat[i].scores[j];
            if(score<0){
                printf("n/a\t");
            }else{
                printf("%.2f\t",score);
            }
        }
        //prints cumulative if not -1
        float cum = (*n).student.cat[i].cumulative;
        if(cum<0){
            printf("n/a\t");
        }else{
            printf("%.2f\t",cum);
        }
    }
    //prints final if not -1
    printf("%.2f\t",(*n).student.current_g);
    float fin = (*n).student.final_g;
    if(fin<0){
        printf("n/a\n");
    } else{
        printf("%.2f\n", fin);
    }
}