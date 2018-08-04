//
//  main.c
//  slowo_srednia_ilosc_znakow
//
//  Created by Jakub Chojnacki on 15/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
long srednia(void);                                                     // prototyp funkcji

int main(int argc, const char * argv[]) {
    
    long average;
    average = srednia();
    printf("srednia ilosc znakow w slowie to : %ld znakow\n", average);
    putchar('\n');
    return 0;
}

long srednia(void)                                                      // liczy srednia ilosc znakow w slowie
{
    bool new_sentence = false;
    char sign;
    long count_sign = 0;                                                // ilosc znakow (suma)
    long count_sentence = 1;
    float avg_sign = 0;                                                  // srednia ilosc znakow w slowie
    
    
    while((sign = getchar())!= EOF){
        putchar(sign);
        
        if(isalnum(sign))                                               // jezeli jest litera lub cyfra to +1
            count_sign++;
        if(sign == 0x09 || sign == 0x20)                                // jezeli jest znakiem nowej linii badz spacja to nowe slowo
            new_sentence = true;
        if(new_sentence)                                                // jezeli flaga jest true, to zlicz zdanie
            count_sentence++;
        
        new_sentence = false;
    }
    printf("znaki: \t slowa:\n");
    printf("%3ld \t %3ld\n", count_sign, count_sentence);
    
    avg_sign = (count_sign)/(count_sentence);                           // srednia ilosc znakow na slowo
    
    return avg_sign;                                                    // zwroc ilosc znakow
}
