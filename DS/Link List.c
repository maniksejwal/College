/*
 * Manik Sejwal
 * 02111502716
 * */

#include<stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[20];
    struct Student *next;
} s1;

struct Student *head = NULL;

void makeList() {
    int n;
    printf("Enter size of the list: ");
    scanf("%d", &n);
    struct Student *ptr = head;
    //while (ptr != NULL && ptr->next != NULL) ptr = ptr->next;
    for (; n > 0; n--) {
        struct Student *node = (struct Student *) malloc(sizeof(struct Student));
        printf("Enter Roll No.\t");
        scanf("%d", &(node->rollNo));
        printf("Enter name\t");
        scanf("%s", node->name);
        node->next = NULL;
        if (head == NULL) {
            head = node;
            ptr = node;
        } else {
            ptr->next = node;
            ptr = ptr->next;
        }
    }
}

void print() {
    struct Student *temp = head;
    printf("\n");
    while (temp != NULL) {
        printf("%d", temp->rollNo);
        printf("%s", temp->name);
        temp = temp->next;
    }
}

void insert() {//incomplete
    struct Student *node = (struct Student *) malloc(sizeof(struct Student)), *ptr = head, *prev = head;
    node->next = NULL;
    printf("\nEnter new student\nEnter Roll No.\t");
    scanf("%d", &(node->rollNo));
    printf("Enter name\t");
    scanf("%s", node->name);
    node->next = NULL;
    if (ptr->rollNo == node->rollNo) {
        node->next = head;
        head = node;
        return;
    }
    while ((ptr != NULL) && (node->rollNo != ptr->rollNo)) {
        prev = ptr;
        ptr = ptr->next;
    }
    node->next = prev->next;
    prev->next = node;
}

void delete() {
    struct Student *ptr = head, *prev = head;
    int rollNo;
    printf("\nEnter roll number to be deleted\t");
    scanf("%d", &rollNo);
    if (head->rollNo==rollNo) {
        head=head->next;
        return;
    }
    while (ptr != NULL && ptr->rollNo != rollNo) {
        prev=ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("\nThe student doesn't exist");
        return;
    }
    prev->next = ptr->next;
}


int main() {
    makeList();
    //print();
    printf("\n");
    insert();
    print();
    delete();
    print();
    return 0;
}

/*
OUTPUT:
Enter size of the list: 5
Enter Roll No.	1
Enter name	A
Enter Roll No.	2
Enter name	3
Enter Roll No.	3
Enter name	B
Enter Roll No.	4
Enter name	C
Enter Roll No.	5
Enter name	D

1A233B4C5D

Enter new student
Enter Roll No.	8
Enter name	H

1A233B4C5D8H
Enter roll number to be deleted	2

1A3B4C5D8H
 */