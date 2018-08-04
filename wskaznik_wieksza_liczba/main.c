//
//  main.c
//  wskaznik_wieksza_liczba
//
//  Created by Jakub Chojnacki on 04/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void compare(double *mniejsza, double *wieksza);                    // prototyp zamieniajacy liczby

int main(int argc, const char * argv[]) {
    
    double value_1;
    double value_2;
    
    value_1 = (rand()%100) + 1;                                      // generalowanie dwoch losowych liczb typu double
    value_2 = (rand()%100) + 1;
    printf("%.3f %.3f\n", value_1, value_2 );
    
    compare(&value_1, &value_2);                                    // pobieramy adresy zmiennych
    
    printf("%.3f %.3f\n", value_1, value_2 );
    
    return 0;
}


void compare(double *mniejsza, double *wieksza)
{
    *mniejsza = (*mniejsza > *wieksza) ? *mniejsza : *wieksza;              // przypisz zmiennej wartosc wiekszej z nich
    *wieksza = (* wieksza > *mniejsza) ? *wieksza : *mniejsza;
}
