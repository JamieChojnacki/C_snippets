//
//  main.c
//  array_pointer_function
//
//  Created by Jakub Chojnacki on 16/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#define MAX 10                                          // max el. tablicy

long summ(int *start, int *end);                            // prototyp funkcji pobierajcej tablice

int main(int argc, const char * argv[]) {
    long wynik = 0l;
    int kulki[MAX] = {[2] = 2,3, [7] = 3,4,5};                  // tablica z 10 elementami
    printf("%d", *(kulki + 9));                                                 // to jest ostatni element tablicy
    wynik = summ(kulki, kulki + MAX);                               // pobieramy &kulki[0] i &kulki[10]
    
    printf("wynik to %ld\n", wynik);
    return 0;
}

long summ(int *start, int *end)
{
    long summ = 0l;
    
    while (start < end)                                                 // wykonaj 10 iteracji
        summ += *(start++);                                                 // za kazdym razej zwieksz adres o 4 bajty i dodaj
                                                                             // start++ == &start[0]++ po pierwszej iteracji
    return summ;
}
