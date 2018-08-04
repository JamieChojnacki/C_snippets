//
//  assignMemory.c
//  funcM_return_address
//
//  Created by Jakub Chojnacki on 17/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include "assignMemory.h"

int *stworz_tablice(int elem, int wart)
{
    int *pAddress;
    
    pAddress = (int *)malloc(elem * sizeof(int));                           // zadanie przydzielenia pamieci
    if(!pAddress)
    {
        puts("nie udalo sie przydzielic pamieci");
        exit(EXIT_FAILURE);
    }
    
    for(int index = 0; index < elem; index++)
        *(pAddress + index) = wart;
    
    return pAddress;
}

void pokaz_tablice(const int tab[], int n)
{
    static int loops = 0;
    for(int j = 0; j < n; j++)
    {
        ++loops;
        if( (loops % 8) == 0)
            putchar(0x0a);
        
        printf("%d", *(tab + j));
    }
    putchar(0x0a);
    
}
