//
//  main.c
//  suma_parzyste_nieparzyste
//
//  Created by Jakub Chojnacki on 07/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#define END 0
const int size = 20;
int main(int argc, const char * argv[]) {
    
    int add_odd = 0;
    int add_even = 0;
    int offset_even;
    int offset_odd;
    int value;
    int odd[size];
    int even[size];
    int summ_odd = 0;
    int summ_even = 0;
    int extern_odd;                                                             // tymczasowo stworzona zmienna by nie zaklocac dzialania petli
    int extern_even;                                                            // --- || ---
    
    printf("podaj liczbe, podanie 0 konczy program\n");
    
    while(scanf("%d",&value) == 1){                                             // 1.begin
        if(value == 0)
        {
            printf("podales '0' - koniec programu\n");
            putchar('\n');
            break;
        }
        
        /*if( (isdigit(value)) )                                             // jezeli argument nie jest cyfra, to kontynuuj
        {
            printf("podales zly format!\n podaj liczbe:\n");
            continue;
        }*/
        if( (value%2) == 0)                                                     // jezeli dzieli sie przez 2 bez reszty to jest parzyste
        {                                                                       // 2.begin
            add_even++;
            for(offset_even = (add_even -1) ;offset_even < 20;offset_even++)    // wykonuj petla tak dlugo jak offset i suma sa takie same
                even[offset_even] = value;
        }                                                                       // 2.end
        else                                                                    // w przeciwnym wypadku jest nieparzyste
            {                                                                   // 3.begin
                add_odd++;
                for(offset_odd = (add_odd -1) ;offset_odd < 20 ;offset_odd++)        // wykonuj petle tak dlugo jak offset i suma sa takie same
                odd[offset_odd] = value;
            }                                                                   // 3.end

    }                                                                           // 1.end
    printf("liczby nieparzyste:\n");
    for(offset_odd = 0;offset_odd < add_odd ;offset_odd++)                      // petla wyswietla podane liczby nieparzyste
        printf("%3d",odd[offset_odd]);
    putchar('\n');
    putchar('\n');
    
    printf("liczby parzyste:\n");
    for(offset_even = 0;offset_even < add_even ;offset_even++)                  // petla wyswietla podane liczby parzyste
        printf("%3d",even[offset_even]);
    putchar('\n');
    putchar('\n');
    
    extern_odd = add_odd;                                                             // zmienna dodatkowa wykorzystywana w petli
    for(offset_odd = 0 ;extern_odd >0 ;extern_odd--, offset_odd++)                    // wykonujemy dodawanie nieparzystych
        summ_odd += odd[offset_odd];
    extern_even = add_even;                                                           // zmienna dodatkowa wykorzystywana w petli
    for(offset_even = 0 ;extern_even >0 ;extern_even--, offset_even++)                // wykonujemy dodawanie parzystych
        summ_even += even[offset_even];
    
    printf("suma nieparzystych to: \t suma parzystych to: \n");
    printf("\t %7d \t \t \t \t %7d", summ_odd, summ_even);
    putchar('\n');
    putchar('\n');
    
    return 0;
}

