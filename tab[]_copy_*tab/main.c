//
//  main.c
//  tab[]_copy_*tab
//
//  Created by Jakub Chojnacki on 22/01/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#define MAX 5

void copy_target(double *formal_source, double *formal_target, int size);
void copy_target_pointer(double *formal_source, double *formal_target, int *size);
void copy_target_pointer_adres(double *formal_source, double *formal_target, double *size);

int main(int argc, const char * argv[]) {
   
    double source[] = { 1.1, 2.2 , 3.3, 4.4 ,5.5 };
    double target_1[MAX];
    double target_2[MAX];
    double target_3[MAX];
    
    int ar_size = sizeof(source)/sizeof(double);
    
    copy_target(source, target_1, MAX);             // notacja tablicowa
    
    for (int i = 0; i < MAX; i ++)
        printf("%lf\n", *(target_1 + i) );
    
    putchar(0x0a);
    
    copy_target_pointer(source, target_2, &ar_size );         // notacja wskaznikowa
    
    for (int j = 0; j < MAX; j ++)
        printf("%lf\n", *(target_2 + j) );
    
    putchar(0x0a);
    
    copy_target_pointer_adres(source, target_3, target_3 + MAX );         // notacja wskaznikowa
    
    for (int k = 0; k < MAX; k ++)
        printf("%lf\n", *(target_3 + k) );
    
    putchar(0x0a);
    
    return 0;
}

void copy_target(double *formal_source, double *formal_target, int size)                // indek
{
    for(int i = 0; i < MAX; i ++)
        formal_target[i] = formal_source[i];
}

void copy_target_pointer(double *formal_source, double *formal_target, int *size)                // wskaznik
{
    double *array_pointer;

    array_pointer = formal_source;                                      // adres pierwszego elementu tablicy jako wskaznik
    
    
    for(int i = 0; i < *size; i ++)
        *(formal_target + i) = *array_pointer++;                                    // glowna operacja ( *   >>  ++ )
}


void copy_target_pointer_adres(double *formal_source, double *formal_target, double *size)           // sztuczka z adres+1
{
    double *array_pointer;
    
    array_pointer = formal_source;
    
    for(; (formal_target) < size; formal_target ++)                         // czary mary riki tiki. Jezeli tablica wyjdzie poza zakres, to koniec
         *(formal_target) = *array_pointer++;
    
}


