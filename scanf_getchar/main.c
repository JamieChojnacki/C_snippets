//
//  main.c
//  scanf_getchar
//
//  Created by Jakub Chojnacki on 20/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
char pobierz_wybor(void);                       // prototypy funkcji
char pobierz_pierwszy(void);
int pobierz_int(void);
void liczenie(void);

int main(int argc, const char * argv[]) {
   
    int wybor;                                                                  // zmienna okreslajaca wybor
    
    while((wybor = pobierz_wybor())!= 'q')                                      // jezeli wybor nie jest q - czyli koniec to
    {
        switch(wybor)
        {
    case 'a':
        printf("kup po taniej sprzedaj po wysokiej\n");
        break;
    case 'b':
        putchar('\a');
        break;
    case 'c':
        liczenie();                                                             // wywolaj funkcje liczenie
        break;
    default:
        printf("blad programu\n");
        break;
        }
    }
    printf("do widzenia\n");
    
    return 0;
}

void liczenie(void)                                                            // funkcja liczy tyle razy ile wpiszemy
{
    int n,i;
    printf("jak dlugo liczyc? podaj liczbe calkowita\n");
    n = pobierz_int();                                                         // wywolanie funkcji pobierz_int
    for (i = 1 ;i <= n ;i++)
        printf("%d\n", i);
    while(getchar()!='\n')                                                    // kazdy znak jest pomijany
        continue;
}

char pobierz_wybor(void)
{
    int sign;
    printf("wpisz wybrana litere:\n");
    printf("a.porada \t b.alarm\n");
    printf("c.liczenie \t q.koniec\n");
    sign = pobierz_pierwszy();                                              // wywolanie funkcji pobierz pierwszy
    
    while((sign < 'a' || sign > 'c') && sign != 'q')                        // powtorz jezeli zostalo zle wpisane
    {
        printf("wpisz a,b,c lub q\n");
        sign = pobierz_pierwszy();                                          // znowu pobierz pierwszy element
    }
    
    return sign;
}


char pobierz_pierwszy(void)
{
    int sign;
    sign = getchar();                                                       // pobierz znak
    while(getchar() != '\n')                                                // jezeli nie jest nowa linia to continue
        continue;
    
    return sign;
}

int pobierz_int(void)
{
    int we;
    char sign;
    
    while(scanf("%d",&we) != 1)                                         // jezeli nie udalo sie pobrac wejscia
        while((sign = getchar() != '\n'))                               // pobierz znak ponownie
        {
            putchar(sign);
            printf("nie jest liczba calkowita.\n Podaj liczbe calkowita");
        }
    
    return we;
}
