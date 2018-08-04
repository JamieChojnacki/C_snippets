//
//  main.c
//  ot_recap
//
//  Created by Jakub Chojnacki on 11/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#define STOP '#'

int main(int argc, const char * argv[]) {
   
    char remember_sign = '\0';                                      // poprzedni znak
    char sign;
    int recap = -1;                                                 // ile powtorzen "OT", nie licz pierwszego ot
    
    while((sign = getchar()) != STOP){                              // 1.begin
        putchar(sign);
        
        if(sign == 'o')                                             // jezeli znak jest "o"
            remember_sign = sign;                                   // zapamietaj znak
        
        if( (sign == 't') && (remember_sign == 'o') )               // jezeli znak to t i poprzedni zapamietany znak jest o
            recap++;
        
        if(sign != 'o')
            remember_sign = 'a';                                    // ustaw wartosc na inna niz 'o'
        
    }                                                               // 1. end
    printf("ilosc powtorzen 'ot' to :%5d",recap);                  // zwroc ilosc powtorzen ot
    putchar('\n');
    return 0;
}
