COMPILER = gcc
OPT = -std=c99 -Wreturn-type -Wimplicit-function-declaration -pedantic
all: functions lab4main

lab4main: functions lab4main.o
	$(COMPILER) lab4main.o insertNode.o createNode.o fillCategory.o deleteNode.o printNode.o printHeader.o printAll.o option1.o option2.o option3.o option4.o option5.o option6.o option7.o option8.o option9.o printAndFree.o -o lab4main -g

lab4main.o: lab4main.c
	$(COMPILER) $(OPT) -c lab4main.c -o lab4main.o

lab4main.zip: Makefile lab4main.c insertNode.c createNode.c fillCategory.c deleteNode.c printNode.c printHeader.c printAll.c option1.c option2.c option3.c option4.c option5.c option6.c option7.c option8.c option9.c  printAndFree.c lab4.h
	zip lab4.zip class_records Makefile lab4main.c insertNode.c createNode.c fillCategory.c deleteNode.c printNode.c printHeader.c printAll.c option1.c option2.c option3.c option4.c option5.c option6.c option7.c option8.c option9.c printAndFree.c lab4.h

functions: insertNode.o createNode.o fillCategory.o deleteNode.o printNode.o printHeader.o printAll.o option1.o option2.o option3.o option4.o option5.o option6.o option7.o option8.o option9.o printAndFree.o lab4.h

insertNode.o: lab4.h insertNode.c
	gcc $(OPT) -g -c insertNode.c

createNode.o: lab4.h createNode.c
	gcc $(OPT) -g -c createNode.c

fillCategory.o: lab4.h fillCategory.c
	gcc $(OPT) -g -c fillCategory.c

deleteNode.o: lab4.h deleteNode.c
	gcc $(OPT) -g -c deleteNode.c

printNode.o: lab4.h printNode.c
	gcc $(OPT) -g -c printNode.c

printHeader.o: lab4.h printHeader.c
	gcc $(OPT) -g -c printHeader.c

printAll.o: lab4.h printAll.c
	gcc $(OPT) -g -c printAll.c

option1.o: lab4.h option1.c
	gcc $(OPT) -g -c option1.c

option2.o: lab4.h option2.c
	gcc $(OPT) -g -c option2.c

option3.o: lab4.h option3.c
	gcc $(OPT) -g -c option3.c

option4.o: lab4.h option4.c
	gcc $(OPT) -g -c option4.c

option5.o: lab4.h option5.c
	gcc $(OPT) -g -c option5.c

option6.o: lab4.h option6.c
	gcc $(OPT) -g -c option6.c

option7.o: lab4.h option7.c
	gcc $(OPT) -g -c option7.c

option8.o: lab4.h option8.c
	gcc $(OPT) -g -c option8.c

option9.o: lab4.h option9.c
	gcc $(OPT) -g -c option9.c

printAndFree.o: lab4.h printAndFree.c
	gcc $(OPT) -g -c printAndFree.c

clean:
	rm -rf *.o lab4main lab4main.zip

