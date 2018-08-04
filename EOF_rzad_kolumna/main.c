//
//  main.c
//  EOF_rzad_kolumna
//
//  Created by Jakub Chojnacki on 14/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
void wyswietl(char sign_up, int height, int width);                 // prototyp funkcji

int main(int argc, const char * argv[]) {
   
    int sign;
    int raws,columns;
    
    printf("podaj odpowiednio : znak\t i_rzedow \t i_kolumn\n");
    while((sign = getchar())!= '0x0a')                                // kiedy znak jest rozny od znaku nowej linii
    {
        if(scanf("%d %d", &raws, &columns) != 2)
            break;
        wyswietl(sign, raws, columns);                              // wywolaj funkcje
        printf("podaj kolejny znak i dwie liczby calkowite\n");
        printf("jezeli chcesz zakonczyc wcisnij ctr + d\n");
    }
    
    printf("koniec");
    putchar('\n');
    
    return 0;
}

void wyswietl(char sign_up, int height, int width){

int raw;
int column;

    for(raw = 1; raw <= height; raw ++)                              // zwiekszaj ilosc wierszy o 1
    {
        for (column = 1; column <= width; column ++)                // w wierszu np 1 wypisz ilosc pobranych wierszy z main
            putchar(sign_up);
        putchar('\n');
            }

    }
