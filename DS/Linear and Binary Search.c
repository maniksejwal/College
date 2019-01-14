/*
 * Manik Sejwal
 * 02111502716
 * */

#include<stdio.h>

void lSearch(int *, int);

void bSearch(int *, int);

int main() {
    int ch, ch1='1', size;
    int a[1000], i;
    do {
        printf("\n Enter Array size : ");
        scanf("%d", &size);
        printf("\n Enter the array :\n");
        for (i = 0; i < size; i++) {
            scanf("%d", &a[i]);
        }
        printf("\nEnter your choice\n Linear search - 1\n Binary search - 2\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                lSearch(a, size);
                break;
            case 2:
                bSearch(a, size);
                break;
            default:
                printf("\n Wrong input ");
        }
        printf("\n Enter 0 to go again  : ");
        scanf("%d", &ch1);
        if(ch1!=0) break;
    } while (1);
    return 0;
}

void lSearch(int *a, int m) {
    int num, i, f = 0;
    printf("\n Enter no to be search : ");
    scanf("%d", &num);
    for (i = 0; i < m; i++) {
        if (a[i] == num) {
            printf("\n Item found at index %d", i);
            f = 1;
            break;
        }
    }
    if (f == 0)
        printf("\n Item not found!!!");
}

void bSearch(int *b, int n) {
    int beg = 0, num, mid, last;
    last = n - 1;
    printf("\n Enter no. to be search : ");
    scanf("%d", &num);
    mid = (beg + last) / 2;
    while (num != b[mid] && beg <= last) {
        if (num > b[mid])
            beg = mid + 1;
        else
            last = mid - 1;
        mid = (beg + last) / 2;
    }
    if (num == b[mid])
        printf("%d Item found at index %d\n", num, mid);
    if (beg > last)
        printf("%d Item not found!!!\n", num);
}

/*
Enter Array size : 10

 Enter the array :
1 2 3 4 5 6 7 8 9 0

Enter your choice
 Linear search - 1
 Binary search - 2
2

 Enter no. to be search : 5
5 Item found at index 4

 Enter 0 to go again  : 0

 Enter Array size : 10

 Enter the array :
1 2 3 4 5 6 7 8 9 0

Enter your choice
 Linear search - 1
 Binary search - 2
1

 Enter no to be search : 3

 Item found at index 2
 Enter 0 to go again  : 1
*/