//
//  main.c
//  wierszowanie
//
//  Created by Jakub Chojnacki on 09/08/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>


int main(int argc, const char * argv[]) {
    
    char nazwisko[20];
    char imie[20];
    
    unsigned long stri = 0;       //dlugosc imienia
    unsigned long strn = 0;       //dlugosc nazwiska
    unsigned long laczna_dlugosc = 0;
    
    printf("podaj swoje imie i nazwisko\n");
    scanf("%s %s",imie,nazwisko);
    fflush(stdout);
    
    stri=strlen(imie);              //przeliczenie dlugosci poszczegolnych znakow
    strn=strlen(nazwisko);
    laczna_dlugosc = stri+strn;
    
    printf("%s %s\n", imie,nazwisko);
    printf("%*lu %*lu",stri,stri,laczna_dlugosc-stri, laczna_dlugosc);
    
    getchar();
    getchar();
    
    return 0;
}
