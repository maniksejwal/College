/*
 * Manik Sejwal
 * 02111502716
 * */

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[20];
    struct Student *next;
};

struct Student *start = NULL, *end = NULL;

void addAtEnd() {
    struct Student *node = (struct Student *) malloc(sizeof(struct Student));
    printf("Enter Roll No.\t");
    scanf("%d", &(node->rollNo));
    //printf("Enter name\t");
    //scanf("%s", node->name);
    node->next = NULL;
    if (start == NULL) {
        start = node;
        node->next = node;
        end = node;
    } else {
        start->next = node;
        start = node;
        start->next = end;
    }
}

void deleteFromStartAndPrint() {
    if (end != start) {
        printf("%d", end->rollNo);
        end = end->next;
        return;
    }
    end = end ->next;
    printf("%d", end->rollNo);
    end = NULL;
    printf("\nThe list is empty");
    exit(1);
}

int main() {
    int decision;
    do {
        printf("\nPress 1 to add, 2 to delete, anything else to exit\t");
        scanf("%d", &decision);
        if (decision == 1) {
            addAtEnd();
        } else if (decision == 2) {
            deleteFromStartAndPrint();
        }
    } while (decision == 1 || decision == 2);
    return 1;
}
/*
OUTPUT:
Press 1 to add, 2 to delete, anything else to exit	1 1
1 2
1 3
1 4
2
1 5
2
2
2
2
3
Enter Roll No.
Press 1 to add, 2 to delete, anything else to exit	Enter Roll No.
Press 1 to add, 2 to delete, anything else to exit	Enter Roll No.
Press 1 to add, 2 to delete, anything else to exit	Enter Roll No.
Press 1 to add, 2 to delete, anything else to exit	1
Press 1 to add, 2 to delete, anything else to exit	Enter Roll No.
Press 1 to add, 2 to delete, anything else to exit	2
Press 1 to add, 2 to delete, anything else to exit	3
Press 1 to add, 2 to delete, anything else to exit	4
Press 1 to add, 2 to delete, anything else to exit	2
The list is empty
 */