//
//  main.c
//  litera_numer_w_alfabecie
//
//  Created by Jakub Chojnacki on 06/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int ASCII_alfabet(char *sign_alfabet);                                 // zamiana na ASCII
int nr_alfabet(char sign_buff);                                     // wyswietl numer w alfabecie a - 1, b - 2 etc

int main(int argc, const char * argv[]) {
    
    int ile_liter = 0, number, nr_alf;
    char sign;
    bool work = false;                                              // zmienna logiczna do zliczania ilosc liter
    
    printf("podaj litere, badz szereg liter:\n");
    
    while((sign = getchar()) != EOF)                                        // jezeli udalo sie pobrac char lub string
    {
    
        work = true;                                                        // wartosc logiczna 1
        
        if (work)
            ile_liter++;                                                    // jezeli true to dodaj ilosc liter
    
    if(sign == '\n')                                             // jezeli napotkasz znak nowej linii
    {
        work = false;                                               // to wartosc logiczna false
        printf("ilosc liter w zdaniu : %d\n", ile_liter - 1);           //wypisz ilosc liter
        ile_liter = 0;                                                       // wyzeruj ilosc liter
        continue;                                                                // i kontynuuj
    }
        //ASCII_alfabet(&sign);                                                          // pobierz adres znaku
        printf("%d", number = ASCII_alfabet(&sign));                                       // wypisz numer w kodzie ASCII
        
        putchar('\n');
        
        // nr_alfabet(&sign);
        printf("numer w alfabecie to : %d", nr_alf = nr_alfabet(sign));
        
        putchar('\n');
        
        if (number == -1){                                                                      // jezeli nie byla to litera to -1 i koniec
            printf("podales zla wartosc !");
            break;
            
            
        }
    }

    putchar('\n');
    
    return 0;
}


int ASCII_alfabet(char *sign_alfabet)                    // zwracamy wartosc w kodzie ASCII
{
    int number;
        
    if(isalpha(*sign_alfabet) || isspace(*sign_alfabet))                        // sprawdz czy jest litera badz znakiem drukowanym
       number = (int)*sign_alfabet;                                                 // rzutowanie char na (int)
    else
        number = -1;

    return number;                                      // zwraca numer w alfabecie albo -1
}


int nr_alfabet(char sign_buff)
{
    int wynik;
    if(isalpha(sign_buff))                               // a to 95 w ascii
    {
        if(islower(sign_buff))                             // jezeli jest mala litera
                wynik = ((int)sign_buff) - 96;                // to w ascii zaczyna sie od 97
        else
       wynik = ((int)sign_buff) - 64;                           // zacznij od A rownego 1 w ascii
    }
    else
    {
        printf("%c nie nalezy do alfabetu!\n", sign_buff);
        wynik = -1;
    }
    
    return wynik;
}
