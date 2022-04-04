#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{

   // operacje na tablicach - wykorzystujac wskazniki!
   int tab[5] = {52,100,4,23,4};
   int *pointer = tab;

    printf("%d \n", *(tab)); // ???
    printf("%d \n", *(tab+1)); // ???
    printf("%d \n", *(tab)+1); // ???
    printf("%d \n", *pointer); // ???
    printf("%d \n", *pointer+1); // ???
    printf("%d \n", &tab); // ???
    printf("%d \n", &tab[1]); // ???
    printf("%d \n", &tab[3]); // ???
    printf("%d \n", tab[0]); // ???
    printf("%d \n", pointer); // ???
    printf("%d \n", &pointer); // ???


    // operacje na zmiennych - wykorzystujac wskazniki
    int zmienna = 3;
    int *wskaznik;
    wskaznik = &zmienna;

    //printf("%d \n", wskaznik);
    //printf("%d \n", *wskaznik);

    //(*wskaznik)++;
    //printf("%d \n", *wskaznik);



   // reczna alokacja pamieci

   int *tab = (int *) malloc(sizeof(int)*10);
   for(int i=0; i<10; i++){
    *(tab+i) = i;
   }

   for(int i=0; i <10; i++){
        printf("%d ", &(*(tab+i)));
   }
   printf("\n");
     for(int i=0; i <10; i++){
        printf("%d ", *(tab+i));
     }
free(tab);

}
