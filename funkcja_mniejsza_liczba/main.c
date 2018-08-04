//
//  main.c
//  funkcja_mniejsza_liczba
//
//  Created by Jakub Chojnacki on 03/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
double minimum(double liczba_1, double liczba_2 );

int main(int argc, const char * argv[]) {
    
    double liczba1 = (rand()%5);                                                // jakies dwie przypadkowe wartosci typu double
    double liczba2 = (rand()%5);
    double min;
    
    min = minimum(liczba1, liczba2);                                            // pobierz dwie liczby
    printf("mniejsza liczba z %f i %f jest %f\n", liczba1, liczba2, min);
   
    return 0;
}


double minimum(double liczba_1, double liczba_2 )                              // porownaj obie pobrane wartosci
{
    double min = liczba_1;
    if(liczba_2 > min)
        liczba_2 = min;
    
    return min;                                                                 // i zwroc mniejsza z niej
}
