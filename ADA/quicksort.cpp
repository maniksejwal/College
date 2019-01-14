#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int partition(int a[], int l, int r) {
    int p = a[r], i = l - 1;
    for (int j = l; j <= r - 1; j++)
        if (a[j] <= p) swap(&a[++i], &a[j]);

    swap(&a[i + 1], &a[r]);
    return i + 1;
}

void quicksort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
}

int main() {
    int arr[] = {1, 0, 2, 9, 3, 8, 4, 7, 5, 6};
    int l = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, l - 1);
    for (int i = 0; i < l; i++) cout << arr[i];
    return 0;
}