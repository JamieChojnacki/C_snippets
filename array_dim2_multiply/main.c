//
//  main.c
//  array_dim2_multiply
//
//  Created by Jakub Chojnacki on 30/01/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

#define C_MAX 5

void multiply( int (*p_source)[C_MAX], int (*p_target)[C_MAX], int elements );

int main(int argc, const char * argv[]) {
    
    int c_elements = 3;
   
    int source[][C_MAX] = {
        {15,  15,  30,  30,  50},
        {10,  20,  30,  40,  50},
        {100, 200, 300, 400, 500}
    };
    
    int target[c_elements][C_MAX];
    
    multiply(source, target, c_elements);
    
    for( int i = 0; i < c_elements; i++ )
        for( int j = 0; j < C_MAX; j++ )
            printf("source[%d][%d] = %d\n", i, j, *(*(source + i) + j) );
    
    putchar(0x0a);
    
    for( int k = 0; k < c_elements; k++ )
        for( int l = 0; l < C_MAX; l++ )
            printf("target[%d][%d] = %d\n", k , l, *(*(target + k) + l) );
    
    putchar(0x0a);
    
    return 0;
}


void multiply( int (*p_source)[C_MAX], int (*p_target)[C_MAX], int elements )
{
    for( int row = 0; row < elements; row++ )
        for( int col = 0; col < C_MAX; col++ )
        {
            *(*(p_target + row) + col) = *(*(p_source + row) + col);
            *(*(p_target + row) + col) *= 2;
        }
}
