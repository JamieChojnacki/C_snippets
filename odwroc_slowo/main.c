//
//  main.c
//  odwroc_slowo
//
//  Created by Jakub Chojnacki on 29/10/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>

const int size = 10;

int main(int argc, const char * argv[]) {
    
    long index, i;
    char name[size] = {"macbook"};                          // imie podane przez uzytkownika
    
    printf("ilosc znakow to :%lu\n", strlen(name));         // ile mamy znakow?
    
    index = strlen(name);                                    // sprawdz ostatni index       k = 7
    
    for(i = index; i >= 0; --i)                              // od ostatniego indexu do zerowego dekrementuj
    {
        printf("%c", name[i]);                              // wypisz po kolei liczby
    }
    puts("\n");
return 0;
}                                                               // koniec main
