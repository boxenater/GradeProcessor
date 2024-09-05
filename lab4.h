typedef struct Cat{
    float scores[3];
    float cumulative;
}Cat;

struct Data {
    char *name[80];
    unsigned short id;
    Cat cat[4];
    float current_g;
    float final_g;
};

typedef struct Node {
    struct Data student;
    struct Node *next;
}Node;

void insertNode(Node** top, Node* data);

int deleteNode(Node** top, short id);

int createNode(FILE *records, Node *ret);

void fillCategory(FILE *records, Cat *cat);

void printHeader(char *name1, char *name2, char *name3, char *name4);

void printNode(Node *n);

void printAll(Node **head, char *name1, char *name2, char *name3, char *name4);

int option1(Node **head, char *name1, char *name2, char *name3, char *name4);
int option2(Node **head, char *name1, char *name2, char *name3, char *name4);
int option3(Node **head, char *name1, char *name2, char *name3, char *name4);
int option4(Node **head, char *name1, char *name2, char *name3, char *name4);
int option5(Node **head, char *name1, char *name2, char *name3, char *name4);
int option6(Node **head, char *name1, char *name2, char *name3, char *name4);
int option7(Node **head, char *name1, char *name2, char *name3, char *name4);

void option8(Node **top, char *name1, char *name2, char *name3, char *name4);
int option9(Node **top);

void printAndFree(FILE *printy, Node **head, char *name1, char *name2, char *name3, char *name4);