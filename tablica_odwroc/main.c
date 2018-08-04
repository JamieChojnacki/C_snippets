//
//  main.c
//  tablica_odwroc
//
//  Created by Jakub Chojnacki on 31/10/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int size = 8, offset;
    int tab[size];
    
    for(offset = 0; offset < size; offset ++)       // przypisz losowe liczby do tablicy
        tab[offset] = (rand()%9)+1;
    
    printf("offset: w_tablicy:\n");
    
    for(offset = 0; offset < size; offset ++)       // wypisz przypisane liczby z tablicy
        printf("%4d \t %5d \n",offset, tab[offset]);
    
    printf("offset: w_tablicy:\n");
    
    for (offset = 7; offset >= 0; offset--)         // odwroc offset
        printf("%4d \t %5d \n",offset, tab[offset]);
    
    return 0;
}
