//
//  main.c
//  VLA
//
//  Created by Jakub Chojnacki on 14/01/2018.
//  Copyright © 2018 James. All rights reserved.
// to jest przyjlad variable length array


#include <stdio.h>

#define ROWS 3
#define COLUMNS 4

int summ_2d( int row, int column, int array[row][column] );                // deklaracja indeksu zmiennej musi byc przez tablica !!!

/* int summ_2d( int , int , int array[*][*] );                                     prototyp bez nazw zmiennych */

int main(int argc, const char * argv[]) {
    
    int i,j;
    int rw = 3;
    int rk = 10;
    
    int array_1[ROWS][COLUMNS] = {
        {2,4,6,8},
        {3,5,7,9},
        {12,10,8,6}
    };
    
    int array_2[ROWS - 1][COLUMNS +2 ] = {
        {20,30,40,50,60,70},
        {5,6,7,8,9,10},
    };
    
    int array_VLA[rw][rk];                                                  // VLA
    
    for (i = 0; i < rw; i++)                                                        // wypelniamy tablice VLA wartosciami
        for (j = 0; j < rk; j++)
            array_VLA[i][j] = i*j + j;
    
    printf("tablica 3x5\n");
    printf("suma wszystkich elementow = %d\n",
           summ_2d(ROWS, COLUMNS, array_1) );
    putchar(0x0a);
    
    printf("tablica 2x6\n");
    printf("suma wszystkich elementow = %d\n",
           summ_2d(ROWS - 1, COLUMNS + 2, array_2) );
    putchar(0x0a);
    
    printf("tablica VLA 3x10\n");
    printf("suma wszystkich elementow = %d\n",
           summ_2d(rw, rk, array_VLA) );
    putchar(0x0a);
    
    return 0;
}

int summ_2d( int row, int column, int array[row][column] )
{
    int summ = 0;
    int w;
    int k;
    
    for (w = 0; w < row; w++)
        for (k = 0; k < column; k++)
            summ += *(*(array + w)+k);
    
    return summ;
}
