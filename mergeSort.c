#include <stdio.h>
#include <stdlib.h>

//############################
//#     MERGE SORT !!!!!!!   #
//############################

void merge(int tab[], int l_side, int middle, int r_side)
{
    int i, j, k;
    int n1 = middle - l_side + 1;
    int n2 = r_side - middle;
    int L_temp[n1], R_temp[n2];


    for (i = 0; i < n1; i++)
    {
        L_temp[i] = tab[l_side + i];
    }

    for (j = 0; j < n2; j++)
    {
        R_temp[j] = tab[middle + 1 + j];
    }


    i = 0;
    j = 0;
    k = l_side;
    while (i < n1 && j < n2)
        {
            if (L_temp[i] <= R_temp[j])
            {
                tab[k] = L_temp[i];
                i++;
            }
            else
            {
                tab[k] = R_temp[j];
                j++;
            }
        k++;
        }


    while (i < n1)
        {
            tab[k] = L_temp[i];
            i++;
            k++;
        }

    while (j < n2)
        {
            tab[k] = R_temp[j];
            j++;
            k++;
        }
}


void mergeSort(int tab[], int l_side, int r_side)
{
    if (l_side < r_side) {

        int middle = l_side + (r_side - l_side) / 2;


        mergeSort(tab, l_side, middle);
        mergeSort(tab, middle + 1, r_side);
        merge(tab, l_side, middle, r_side);
    }
}

int main()
{
    int tab[] = { 4, 13, 5325, 1231, 23, 5, 9, -1 };
    int tab_size = sizeof(tab) / sizeof(tab[0]);

    mergeSort(tab, 0, tab_size - 1);

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)
    {
        printf("%d ", tab[i]);
    }

    return 0;
}
