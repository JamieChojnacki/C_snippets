//
//  main.c
//  slowa_ASCII
//
//  Created by Jakub Chojnacki on 07/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#define STOP '#'

int main(int argc, const char * argv[]) {
    
    char znak;
    int licznik = 0;
    
    printf("podaj slowo, zakoncz je '#'\n");                                         // podam slowo "Jakub to mistrz#"
    while( (znak = getchar()) != STOP){
        
        if(isprint(znak))                                                            // jezeli jest znakiem drukowanym, to zwieksz licznik
            licznik++;
           
        if( (licznik % 9) == 0)                                                     // jezeli licznik jest 8 16 24 etc. to zacznij od nowej linii
            putchar(0x0a);
        
      putchar(znak);                                                                 // pobrales znak, to go wypisz
      printf(" - %d\t",znak);
        
    }
    putchar('\n');
    return 0;
}
                                                    // wynikiem dzialania programu powinno byc:
                                                    // J   a   k   u   b     t   o
                                                    // 74  97  107 117 98 32 116 111
                                                    //    m   i   s   t   r   z
                                                    // 32 109 105 115 116 114 122
