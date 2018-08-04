//
//  main.c
//  roznica_par
//
//  Created by Jakub Chojnacki on 29/10/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>

double roznica(void);

int main(int argc, const char * argv[]) {
    double cudo;
    cudo = roznica();                                               // wywolaj funkcje roznica
    printf("%lf", cudo);                                            // co ja tutaj dostane ?
    return 0;
}                                                                   // koniec main

double roznica(void)                // DOKONCZ
{
    double value = 0;
    double first, second;
    do{                                                              // poczatek do
    printf("podaj dwie liczby do roznicy : \n");
    scanf("%lf,%lf", &first, &second);                              // podaj dwie liczby
        
    value = first - second;                                         // wykonaj odejmowanie
        
    printf("wartosc to: %lf", value);                              // jaka to wartosc?
        
    scanf("%lf,%lf", &first, &second);                              // pobierz kolejne liczby
    
    }while (scanf("%lf,%lf", &first, &second)!=2);                       // jezeli nie udalo sie pobrac wartosci to skoncz
    printf("Podales zly format!");
    
    return value;                                                         // zwroc wartosc
}                                                                         // koniec funkcji roznica
