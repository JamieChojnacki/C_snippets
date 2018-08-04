//
//  main.c
//  malloc_free
//
//  Created by Jakub Chojnacki on 14/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    double *pointer;
    int max = 0;
    int liczba;
    int i = 0;
    
    puts("podaj maksymalna liczbe elementow typu double :");
    if( scanf("%d", &max) != 1)
    {
        puts("podano niepoprawna liczbe elementow");
        exit(EXIT_FAILURE);
    }
    
    pointer = (double *)malloc(max * sizeof(double) );                      // zadanie przydzielenia pamieci
    
    if(!pointer)
    {
        puts("przydzial pamieci nie powiodl sie");
        exit(EXIT_FAILURE);
    }
    /* wskaznik wskazuje na tablice elementow rowna liczbie max */
    
    puts("podaj elementy, k to koniec");
    while(i < max && scanf("%lf", &pointer[i]) == 1)
        ++i;
    
    printf("liczba wprowadzonych elementow : %d", liczba = i);
    for(i = 0; i < liczba; i ++)
    {
        printf("%7.2lf", *(pointer + i) );
        if(i % 7 == 6)
            putchar(0x0a);
    }
    if(i % 7 != 0)
        putchar(0x0a);
    puts("koniec");
    free(pointer);                      // zwalniamy pamiec
    
    
    return 0;
}
