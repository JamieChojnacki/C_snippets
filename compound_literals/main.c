//
//  main.c
//  compound_literals
//
//  Created by Jakub Chojnacki on 14/01/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

#define COLUMNS 4
int summ_2d( const int array[][COLUMNS], int rows );
int summ( const int array[], int n );

int main(int argc, const char * argv[]) {
    
    int summ_1, summ_2, summ_3;
    int *p_array_1;
    int (*p_array_2)[4];
    
    p_array_1 = (int [2] ) { 10,20 };                                       // iteral zlozony
    
    p_array_2 = (int [2][COLUMNS] ) { {1,2,3,-9}, {4,5,6,-8} };                 // iteral zlozony
    
    summ_1 = summ( p_array_1, 2 );
    summ_2 = summ_2d( p_array_2, 2 );
    summ_3 = summ( (int []){4,4,4,5,5,5}, 6 );
    printf("summ_1 = %d\n", summ_1);
    printf("summ_2 = %d\n", summ_2);
    printf("summ_3 = %d\n", summ_3);
    
    return 0;
}

int summ_2d( const int array[][COLUMNS], int rows )
{
    int summ = 0;
    int w, k;
    
    for (w = 0; w < rows ; w++)
        for (k = 0; k < COLUMNS; k++)
            summ += array[w][k];
    
    return summ;
}

int summ( const int array[], int n )
{
    int suma = 0;
    int i;
    
    for (i = 0; i < n; i ++)
        suma += array[i];
    
        return suma;
}
