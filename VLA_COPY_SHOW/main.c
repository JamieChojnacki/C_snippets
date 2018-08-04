//
//  main.c
//  VLA_COPY_SHOW
//
//  Created by Jakub Chojnacki on 30/01/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

#define C_MAX 5
#define R_MAX 3

void VLA(int N, int M, int (*p_source)[M], int (*p_target)[M] );
void VLA_show(int N, int M, int (*p_target)[M] );

int main(int argc, const char * argv[]) {
    
    int row_max = 3;
    int col_max = 5;
    
    int source[][C_MAX] = {
        {1, 2, 3, 4, 5},
        {0, 3, 5, 7, 9},
        {2, 4, 6, 8, 9}
    };
    
    int target[row_max][col_max];
    
    VLA(row_max, col_max - 2, source, target);                      // tworzymy tablica VLA - target
    VLA_show(row_max, col_max - 2, target);                             // wyswietlamy tablice VLA - target
    
    return 0;
}

void VLA(int N, int M, int (*p_source)[M], int (*p_target)[M] )                 // kopiujemy N/M elementow z source do target
{
    for( int row = 0; row < N; row++)
        for( int col = 0; col < M; col++)
            *(*(p_target + row) + col) = *(*(p_source + row) + col);
}

void VLA_show(int N, int M, int (*p_target)[M] )
{
    for( int row = 0; row < N; row++)
        for( int col = 0; col < M; col++)
            printf("target[%d][%d] = %d\n", row, col, *(*(p_target + row) + col) );
}
