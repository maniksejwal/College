/*
 * Manik Sejwal
 * 02111502716
 * */

#include <stdio.h>

int main() {
    int m, n, p, q, c, d, k, sum = 0;
    int first[10][10];                                      //first matrix
    int second[10][10];                                     //second matrix
    int multiply[10][10];                                   //matrix corresponding to the first that is multiplied with first

    printf("Enter the number of rows and columns of first matrix\n");
    scanf("%d%d", &m, &n);
    printf("Enter the elements of first matrix\n");

    for (c = 0; c < m; c++)
        for (d = 0; d < n; d++)
            scanf("%d", &first[c][d]);

    printf("Enter the number of rows and columns of second matrix\n");
    scanf("%d%d", &p, &q);

    if (n != p)
        printf("Matrices with entered orders can't be multiplied with each other.\n");
    else {
        printf("Enter the elements of second matrix\n");

        for (c = 0; c < p; c++)
            for (d = 0; d < q; d++)
                scanf("%d", &second[c][d]);

        for (c = 0; c < m; c++) {
            for (d = 0; d < q; d++) {
                for (k = 0; k < p; k++) {
                    sum = sum + first[c][k] * second[k][d];
                }

                multiply[c][d] = sum;
                sum = 0;
            }
        }

        printf("Product of entered matrices:-\n");

        for (c = 0; c < m; c++) {
            for (d = 0; d < q; d++)
                printf("%d\t", multiply[c][d]);

            printf("\n");
        }
    }
    //Name      : Manik Sejwal
    //Roll no.  : 02111502716
    return 0;
}

/*
OUTPUT:
Enter the number of rows and columns of first matrix
3
3
Enter the elements of first matrix
1 2 3
4 5 6
7 8 9
Enter the number of rows and columns of second matrix
3
3
Enter the elements of second matrix
1 2 3
4 5 6
7 8 9
Product of entered matrices:-
30	36	42
66	81	96
102	126	150
*/