//
//  main.c
//  copy_tab_dim2
//
//  Created by Jakub Chojnacki on 30/01/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

#define MAX 10

void copy_tab( int (*matrix)[MAX], int (*target)[MAX], int elements );

int main(int argc, const char * argv[]) {
    
    int source[][MAX] = {
        {0,  1,  2,  3,  4,  5,  6,  7,  8,  9},
        {10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
        {20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34, 35, 36, 37, 38, 39},
        {40, 41, 42, 43, 44, 45, 46, 47, 48, 49}
    };
    
    int DATA[5][MAX];
    
    for( int i = 0; i < 5; i++ )                            // tablica source
        for( int j = 0; j < MAX; j++ )
            printf("source[%d][%d] = %d\n",i,j, *(*(source + i) + j) );
    
    putchar(0x0a);
    
    copy_tab(source, DATA, 5);                          // pobrania tablic i wykonanie dzialania
    
    for( int k = 0; k < 5; k++ )                                // wynik dzialania na tablicy DATA
        for( int l = 0; l < MAX; l++ )
            printf("DATA[%d][%d] = %d\n",k,l, *(*(DATA + k) + l) );
    
    putchar(0x0a);
    
    return 0;
}
void copy_tab( int (*matrix)[MAX], int (*target)[MAX], int elements )               // kopiujemy elementy ze zrodla do tablicy DATA
{
    for( int row = 0; row < elements; row++ )
        for( int col = 0; col < MAX; col++ )
            *(*(target + row) + col) = *(*(matrix + row) + col);
}
