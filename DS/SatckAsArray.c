/*
 * Manik Sejwal
 * 02111502716
 * */

#include<stdio.h>
#include<stdlib.h>

int r = 0;

void push(int x, int *a) {
    a[r++] = x;
}

void pop() {
    if (r < 0) {
        printf("The stack is empty");
        return;
    }
    r--;
}

int main() {
    int a[50], choice, x, i;
    printf("\nMENU\n1. Insert in stack \n2. Delete from stack \n3. Display \n4. Exit");
    while (1) {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :
                printf("\nEnter the element to be inserted : ");
                scanf("%d", &x);
                push(x, a);
                break;
            case 2 :
                printf("\nDeleting element from stack...");
                pop();
                break;
            case 3 :
                printf("\nNow the stack is : \n");
                for (i = 0; i <= r; i++)
                    printf("%d ", a[i]);
                printf("\n");
                break;
            default :
                return 1;
        }
    }
}

/*
OUTPUT:
MENU
1. Insert in stack
2. Delete from stack
3. Display
4. Exit
Enter your choice : 1 1
1 2
1 3
1 4 3
2 3
1 5 3
2
2
2
2
3

Enter the element to be inserted :
Enter your choice :
Enter the element to be inserted :
Enter your choice :
Enter the element to be inserted :
Enter your choice :
Enter the element to be inserted :
Enter your choice :
Now the stack is :
1 2 3 4 0

Enter your choice :
Deleting element from stack...
Enter your choice :
Now the stack is :
1 2 3 4

Enter your choice :
Enter the element to be inserted :
Enter your choice :
Now the stack is :
1 2 3 5 0

Enter your choice :
Deleting element from stack...
Enter your choice :
Deleting element from stack...
Enter your choice :
Deleting element from stack...
Enter your choice :
Deleting element from stack...
Enter your choice :
Now the stack is :
1

Enter your choice : 4
*/