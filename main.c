#include <stdio.h>
#include <stdlib.h>


void merge(int tab[], int l_side, int middle, int r_side)
{
    int i, j, k;
    int n1 = middle - l_side + 1;
    int n2 = r_side - middle;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = tab[l_side + i];
    for (j = 0; j < n2; j++)
        R[j] = tab[middle + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l_side; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            i++;
        }
        else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int tab[], int l_side, int r_side)
{
    if (l_side < r_side) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int middle = l_side + (r_side - l_side) / 2;

        // Sort first and second halves
        mergeSort(tab, l_side, middle);
        mergeSort(tab, middle + 1, r_side);

        merge(tab, l_side, middle, r_side);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver code */
int main()
{
    int tab[] = { 4, 13, 5325, 1231, 23, 5, 9, -1 };
    int arr_size = sizeof(tab) / sizeof(tab[0]);

    printf("Given array is \n");
    printArray(tab, arr_size);

    mergeSort(tab, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(tab, arr_size);
    return 0;
}
