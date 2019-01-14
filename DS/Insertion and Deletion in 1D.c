/*
 * Manik Sejwal
 * 02111502716
 * */

#include <stdio.h>

int main() {
    int array[100], position, c, n, value;

    printf("Enter number of elements in array\n");
    scanf("%d", &n);

    printf("Enter %d elements\n", n);

    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    printf("Enter the position where you wish to insert an element\n");
    scanf("%d", &position);

    printf("Enter the value to insert\n");
    scanf("%d", &value);

    for (c = n - 1; c >= position - 1; c--)
        array[c + 1] = array[c];

    array[position - 1] = value;

    printf("Resultant array is\n");

    for (c = 0; c <= n; c++) printf("%d\n", array[c]);
    return 0;
}
/*
OUTPUT:
Enter number of elements in array
10
Enter 10 elements
1 2 3 4 5 6 7 8 9 0
Enter the position where you wish to insert an element
3
Enter the value to insert
8
Resultant array is
1
2
8
3
4
5
6
7
8
9
0
*/