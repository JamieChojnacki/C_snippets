//
//  main.c
//  swap_dot_to_!
//
//  Created by Jakub Chojnacki on 09/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '#'
#define EXCL_MARK '!'
#define DOT '.'

int main(int argc, const char * argv[]) {
    
    char sign;
    bool CHANGE_SUCCESS = false;                                // flaga zmiany
    int SUCCESS = 0;                                            // ilosc dokonanych zmian
    
    while((sign = getchar())!= STOP){                           // jezeli udalo sie pobrac znak ...
        
        if(sign == DOT || sign == EXCL_MARK)                    // jezeli jest kropka lub wykrzyknikiem
        {
            sign = (sign == DOT) ? EXCL_MARK : DOT;             // zamien na wykrzyknik jezeli jest kropka, a jezeli to pozostaw wykrzyknikiem
            CHANGE_SUCCESS = true;                                    // udalo sie dokonac zmiany
            putchar(sign);                                      // wypisz zmieniony znak
        }
        else                                                    // w innym wypadku wypisz znak
            putchar(sign);
        
        if(CHANGE_SUCCESS)                                      // jezeli flaga jest 1 to ilosc zmian +1
            SUCCESS++;
        
        CHANGE_SUCCESS = false;                                 // ustaw flage znowu na falsz
    }
    
    putchar('\n');
    
    printf("ilosc udanych zmian:\n");
    printf("%5d \n", SUCCESS);
    
    putchar('\n');
    
    return 0;
}
