#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

//reads input from a file and populates a node's grades with the data;
void fillCategory(FILE *records, Cat *cat){
    int numOfValid = 0;
    float cumulative = 0;
    //iterating for all 3 grades in current category
    for(int i = 0;i<3;i++){
        //checking if a new break line will be used instead of a tab, and setting the scores into the Node's student data
        if(i==2){
            fscanf(records,"%f\n",&((*cat).scores[i]));
        } else {
            fscanf(records,"%f\t",&((*cat).scores[i]));
        }
        // checking if the inputted score is valid to be used in the cumulative for this category
        if((*cat).scores[i]>=0){
            cumulative = cumulative + (*cat).scores[i];
            ++numOfValid;
        }
    }
    //calculating the cumulative based on number of valid grades and current cumulative sum
    if(numOfValid!=0){
        cumulative = cumulative/numOfValid;
    //assigning -1 to cumulative if there are no valid grades.+
    } else {
        cumulative = -1;
    }
    //setting the node's cumulative score for this category
    (*cat).cumulative = cumulative;

}
