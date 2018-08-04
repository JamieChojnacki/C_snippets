//
//  main.c
//  silnia_rekurencja_petla
//
//  Created by Jakub Chojnacki on 22/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
long loop(int num);                                         // prototyp funkcji petla
long recursion(int num);                                    // prototyp funkcji rekurencyjnej

int main(int argc, const char * argv[]) {
    int value;                                              // wartosc podawana przez uzytkownika
    printf("podaj wartosc od 1 do 12\n");
    
    while(scanf("%d", &value) == 1)                         // jezeli udalo sie pobrac wartosc idz dalej
    {
        if (value < 0)
            printf("podano ujemna liczbe\n");
        else if(value > 12)
            printf("za duza wartosc max 12.\n");
        else
        {
            printf("petla: %d silnia: %ld\n", value,loop(value));               // obie funkcje pobieraja value
            printf("rekurencja: %d silnia: %ld\n", value,recursion(value));
        }
    }
    return 0;
}

long loop(int num)                                          // definicja funkcji obslugujacej petle
{
    long out;
    
    for (out = 1; num > 1; num --)                          // wzor na wykonanie silni n! = (n-1)*(n-2)*(n-3) * ... * 1
        out *= num;
    
    return out;                                             // zwroc wynik
}



long recursion(int num)
{
    long out;
    if (num > 0)                                            // warunek konca rekurencji
        out = num * recursion(num - 1);                     // funkcja przyjmuje calkowite wartosci dla kolejnych dekrementacji tj
        else                                                // 5,4,3,2,1 oraz 0 ktore konczy petle
            out = 1;                                        // jezeli jest 0 to wynik jest rowny 1 i rekurencja = 0
    
    return out;                                             // zwroc wynik
}
