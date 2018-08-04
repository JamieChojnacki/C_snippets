//
//  cnv.c
//  complex_string_load
//
//  Created by Jakub Chojnacki on 22/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include "cnv.h"

/*********************************************************************************************/

int menu(void)
{
    int kod, stan;
    printf("\n%s%s\n", GWIAZDKI, GWIAZDKI);
    puts("co mam zrobic :");
    puts("1.wyswietl wpisane lancuchy");
    puts("2.wyswietl lancuchy uszeregowane alfabetycznie");
    puts("3.wyswietl lancuchy uszeregowane pod kod ASCII");
    puts("4.wyswietl lancuchy uszeregowane pod wzgledem dlugosci");
    puts("5. zastosuj funkcje atoi");
    puts("0. koniec");
    puts("podaj swoj wybor");
    printf("%s%s\n", GWIAZDKI, GWIAZDKI);
    
    while((stan = scanf("%d", &kod)) !=1 || (kod < 0 || kod > 5))       // odpornosc na idiotow zwiekszona
    {
        if(stan != 1)
            scanf("%*s");                                         // odrzucamy wejscie nieliczbowe
        printf("podaj liczbe od 1 do 4\n");
    }
    return kod;                                                        // zwroc wartosc wpisana przez uzytkownika
}

/*********************************************************************************************/

char *load(char *target, int bufor)
{
    char *result;
    char *found;
    
    result = fgets(target, bufor, stdin);               // jezeli nie uda sie pobrac, to result == NULL
    if(result)                                              // wynik rozny od NULL
    {
        found = strchr(target, 0x0a);                           // szukamy znaku nowego wiersza
        if(found)                                                   // jezeli udalo sie znalezc
            *found = 0x0;                                               // to pod adres trafia znak zerowy
        else
            while( getchar() != 0x0a )                          // pomijamy nadmiarowe znaki
                continue;
    }
    
    return result;
    
}

/*********************************************************************************************/

void string_to_integar(char (*p_array)[C_MAX], int (*target)[C_MAX], int layer)
{
    for(int index = 0; index < layer; index++)
        for(int znak = 0; znak < C_MAX; znak++)
            *(*(target + index) + znak) = atoi(*(p_array + index) + znak);          // atoi wypelnia zerami miejsca ktore nie sa liczbami
}

/*********************************************************************************************/

void sort_ASCII(char *ar_string[], int layer)
{
    char *temp;
    int dol, szuk;
    
    for(dol = 0; dol < layer - 1; dol++)
        for(szuk = dol + 1; szuk < layer; szuk++)
            if( (int)(ar_string[dol][0]) > (int)(ar_string[szuk][0]) )                            // szeregujemy od najmniejszego do najwiekszego
            {
                temp = ar_string[dol];                                                          // stosujemy sortowanie babelkowe
                ar_string[dol] = ar_string[szuk];
                ar_string[szuk] = temp;
            }
}

/*********************************************************************************************/

void srtlan(char *ar_string[], int num)
{
    
    char *temp;
    int dol, szuk;
    
    for(dol = 0; dol < num - 1; dol++)
        for(szuk = dol + 1; szuk < num; szuk++)
            if(strcmp(ar_string[dol], ar_string[szuk]) > 0)         // wynik > 0 oznacza,
                                                                        //ze znak w lancuchu 1 wyprzedza znak w lancuchu 2 (ASCII)
            {                                                               // znaki znajdujace sie na tych samych pozycjach w lancuchach
                temp = ar_string[dol];
                ar_string[dol] = ar_string[szuk];
                ar_string[szuk] = temp;
            }
}

/*********************************************************************************************/

void wyswietl(char (*p_array)[C_MAX], int loops)
{
    puts("oto wpisany lancuch");
    for(int i = 0; i < loops; i++)
            puts( *(p_array + i) );
}

/*********************************************************************************************/

void srtlan_length(char *ar_string[], int num)
{
    char *temp;
    int dol, szuk = 0;
    unsigned long rozmiar_dol = 0;
    unsigned long rozmiar_szuk = 0;
    
    for(dol = 0; dol < num - 1; dol++)
    {
        for(szuk = dol + 1; szuk < num; szuk++)
        {
            rozmiar_dol = strlen(*(ar_string + dol));              // rozmiar pierwszego lancucha
            rozmiar_szuk = strlen(*(ar_string + szuk));                     // rozmiar porownywanego lancucha
            
            if(rozmiar_dol < rozmiar_szuk)
            {
                temp = ar_string[dol];
                ar_string[dol] = ar_string[szuk];
                ar_string[szuk] = temp;
            }
        }
    }
}

/*********************************************************************************************/
