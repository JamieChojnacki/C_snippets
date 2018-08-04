//
//  main.c
//  random_generator
//
//  Created by Jakub Chojnacki on 17/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include "generate.h"
#include <stdio.h>

static MyVariable loops;


int main(int argc, const char * argv[]) {
   
    for(int i = 0; i < OBJECTS; i++)
    {
        ++loops;                                        // licznik iteracji
        
        if( (loops % 100) == 0 )                             // co 100 iteracji zamieniamy ziarno
            change_seed();
        
        gamble();                                                   //losujemy liczby
    }
    
    result();
    putchar(0x0a);
    printf("laczna ilosc iteracji : %d\n", loops);
    
    return 0;
}
