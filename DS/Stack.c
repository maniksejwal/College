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

struct Student *head = NULL;

void push() {
    struct Student *node = (struct Student *) malloc(sizeof(struct Student));
    printf("Enter Roll No.\t");
    scanf("%d", &(node->rollNo));
    //printf("Enter name\t");
    //scanf("%s", node->name);
    node->next = NULL;
    if (head == NULL) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }
}

void pop() {
    if (head != NULL) {
        printf("%d", head->rollNo);
        head = head->next;
        return;
    }
    printf("\nThe list is empty");
    exit(1);
}

int main() {
    int decision;
    label:
    printf("\nPress 1 to push, 2 to pop, anything else to exit\t");
    scanf("%d", &decision);
    if (decision == 1) {
        push();
        goto label;
    } else if (decision == 2) {
        pop();
        goto label;
    }
    return 1;
}

/*
OUTPUT:
Press 1 to push, 2 to pop, anything else to exit	1 1
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
Press 1 to push, 2 to pop, anything else to exit	Enter Roll No.
Press 1 to push, 2 to pop, anything else to exit	Enter Roll No.
Press 1 to push, 2 to pop, anything else to exit	Enter Roll No.
Press 1 to push, 2 to pop, anything else to exit	4
Press 1 to push, 2 to pop, anything else to exit	Enter Roll No.
Press 1 to push, 2 to pop, anything else to exit	5
Press 1 to push, 2 to pop, anything else to exit	3
Press 1 to push, 2 to pop, anything else to exit	2
Press 1 to push, 2 to pop, anything else to exit	1
Press 1 to push, 2 to pop, anything else to exit
 */