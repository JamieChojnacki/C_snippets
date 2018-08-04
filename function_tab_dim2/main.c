//
//  main.c
//  function_tab_dim2
//
//  Created by Jakub Chojnacki on 14/01/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

#define ROWS 3
#define COLUMNS 4

void sumuj_wiersze( int tab[][COLUMNS], int rows);
void sumuj_kolumny( int tab[][COLUMNS], int );              // mozna pominac nazwe
int sumuj_2d( int (*tab)[COLUMNS], int rows);              // notacja wskaznikowa

int main(int argc, const char * argv[]) {
    
    int example[ROWS][COLUMNS] = {
        {2,4,6,8},
        {3,5,7,9},
        {12,10,8,6}
    };
    
    sumuj_wiersze(example, ROWS);
    sumuj_kolumny(example, ROWS);
    printf("suma wszystkich elementow tablicy wynosi %d\n", sumuj_2d(example, ROWS) );                  // suma wszystkich elementow
    
    return 0;
}


void sumuj_wiersze( int tab[][COLUMNS], int rows)
{
    int w;                  // zmienna wewnetrzna dla wierszy
    int k;
    int suma;                   // suma elementow tablicy
    
    for (w = 0; w < rows; w++)
    {
        suma = 0;
        for(k = 0; k < COLUMNS; k++)
            suma += *(*(tab+w)+k);
        printf("wiersz %d : suma = %d\n", w,suma);
    }
}


void sumuj_kolumny( int tab[][COLUMNS], int rows)
{
    int w;                  // zmienna wewnetrzna dla wieszy
    int k;
    int suma;                   // suma elementow tablicy
    
    for (k = 0; k < COLUMNS; k++)
    {
        suma = 0;
        for(w = 0; w < rows; w++)
            suma += *(*(tab+w)+k);
        printf("kolumna %d : suma = %d\n", k,suma);
    }
}


int sumuj_2d( int (*tab)[COLUMNS], int rows)                    // suma wszystkich elementow tablicy example
{                                               // (*tab)[COLUMNS] wskaznik do tablicy jednowymiarowej o rozmiarze 4 int
    int w;
    int k;
    int suma = 0;
    for (w = 0; w < rows; w++)
        for (k = 0; k < COLUMNS; k++)
            suma +=*(*(tab+w)+k);
    
    return suma;
}
    // tab == &tab[0]
    // tab[0] == &tab[0][0]
