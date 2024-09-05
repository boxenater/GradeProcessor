#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"
//prints out a header for columns
void printHeader(char *name1, char *name2, char *name3, char *name4){
    printf("Name\t\t\tID\t%s\t\t\tCUM\t%s\t\tCUM\t%s\t\tCUM\t%s\t\t\tCUM\tCurrent\tFinal\n",name1,name2,name3,name4);
}