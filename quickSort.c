#include <stdio.h>
#include <stdlib.h>

// ###################
// #     QUICKSORT   #
// ###################

void quickSort(int tab[], int start_element, int last_element)
{
    if (last_element <= start_element) return;
    int pivot = partitionFunction(tab, start_element, last_element);
    quickSort(tab,start_element, pivot - 1);
    quickSort(tab, pivot + 1, last_element);
}

int partitionFunction(int tab[], int start_element, int last_element)
{
    int i = start_element - 1;
    int pivot = tab[last_element];

    for(int k = start_element; k <= last_element; k++)
        {
        if(tab[k] < pivot)
         {
            i++;
			int temp = tab[i];
			tab[i] = tab[k];
			tab[k] = temp;
         }
        }
        i++;
        int temp = tab[i];
        tab[i] = tab[last_element];
        tab[last_element] = temp;

        return i;
}

int main()
{
    int tab[] = {2, 4, 5, 10, 23, 65, 1000, 13, -982};
    int tab_size = sizeof(tab) / sizeof(tab[0]);

    quickSort(tab,0,tab_size - 1);

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)
    {
        printf("%d ", tab[i]);
    }
    return 0;
}
