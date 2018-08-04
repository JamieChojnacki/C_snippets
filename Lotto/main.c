//
//  main.c
//  Lotto
//
//  Created by Jakub Chojnacki on 05/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LUCKY_SIX 6

void losuj(int *array);
void sort(int *source);

int main(int argc, const char * argv[]) {
    
    int Lotto_Array[LUCKY_SIX];
    
    srand( (unsigned int) time(0) );
    
    losuj(Lotto_Array);
    sort(Lotto_Array);
    
    puts("twoje szczesliwe liczby to:");
    for(int index = 0; index < LUCKY_SIX; index++)
    {
        printf("%d\n", *(Lotto_Array + index));
    }
    
    return 0;
}


void losuj(int *array)
{
    bool same = false;
    
    for(int index = 0; index < LUCKY_SIX; index++)
        *(array + index) = (rand() % 48) + 1;
    
    while(1)
    {
        same = false;
    for(int index_seek = 0; index_seek < LUCKY_SIX - 1; index_seek++)
        if(*(array + index_seek) == *(array + index_seek + 1))                          // jezeli jakas liczba sie powtorzy
        {
            *(array + index_seek) =(rand() % 48) + 1;                                       // to wylosuj jeszcze raz
            same = true;
            
        }
        if(!same)
            break;
    }
    
}

void sort(int *source)
{
    bool swapped = false;
    int temp;
    
    while(1)
    {
        swapped = false;                                            // bardzo wazne, zeby czas trwania byl okreslony przez jeden cykl petli
        
        for(int index = 0; index < LUCKY_SIX - 1; index++)
            if( *(source + index) < *(source + index + 1) )
            {
                temp = *(source + index);
                *(source + index) = *(source + index + 1);
                *(source + index + 1) = temp;
                swapped = true;
    }
        if(!swapped)
            break;
}
}
