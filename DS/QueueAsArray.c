/*
 * Manik Sejwal
 * 02111502716
 * */

#include<stdio.h>
#include<stdlib.h>

int f = -1, r = -1;

void enqueue(int x, int *a) {
    if (r + 1 == f)
        return;
    else if (f == -1 && r == -1) {
        f = 0;
        r = 0;
    } else
        r++;
    a[r] = x;
}

void dequeue(int *a) {
    if (f == -1 && r == -1)
        return;
    else if (f == r) {
        f = -1;
        r = -1;
    } else
        f++;
}

int main() {
    int a[50], choice, x, i;
    printf("\nMENU\n1. Insert in queue \n2. Delete from queue \n3. Display \n4. Exit");
    while (1) {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :
                printf("\nEnter the element to be inserted : ");
                scanf("%d", &x);
                enqueue(x, a);
                break;
            case 2 :
                printf("\nDeleting element from queue...");
                dequeue(a);
                break;
            case 3 :
                printf("\nNow the queue is : \n");
                for (i = f; i <= r; i++)
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
1. Insert in queue
2. Delete from queue
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
Now the queue is :
1 2 3 4

Enter your choice :
Deleting element from queue...
Enter your choice :
Now the queue is :
2 3 4

Enter your choice :
Enter the element to be inserted :
Enter your choice :
Now the queue is :
2 3 4 5

Enter your choice :
Deleting element from queue...
Enter your choice :
Deleting element from queue...
Enter your choice :
Deleting element from queue...
Enter your choice :
Deleting element from queue...
Enter your choice :
Now the queue is :
0
*/