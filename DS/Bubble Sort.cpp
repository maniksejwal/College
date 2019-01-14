/*
 * Manik Sejwal
 * 02111502716
 * */

#include<stdio.h>

int size, a[100];

void input() {
    int t;
    for (int i = 0; i < size; ++i) {
        scanf("%d", &t);
        a[i] = t;
    }
}

void sort() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                a[j] += a[j + 1];
                a[j + 1] = a[j] - a[j + 1];
                a[j] -= a[j + 1];
            }
        }
    }
}

void output() {
    for (int i = 0; i < size; i++) {
        printf("%d", a[i]);
    }
}

int main() {
    printf("Enter the size of the array\t");
    scanf("%d", &size);
    printf("\nEnter the array\t");
    input();
    sort();
    printf("Sorted array is :");
    output();
}

/*
OUTPUT:
Enter the size of the array	10

Enter the array	1 3 5 7 9 2 4 6 8 0
Sorted array is :0123456789
 */