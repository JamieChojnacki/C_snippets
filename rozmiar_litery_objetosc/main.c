//
//  main.c
//  rozmiar_litery_objetosc
//
//  Created by Jakub Chojnacki on 26/03/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>                                     // potrzebujemy funkcji strlen()

#define gestosc 28.125                                  // ludzka gestosc w kilogramach na metr szescienny

int main(int argc, const char * argv[]) {
    
    char nazwa[30];                                     // nazwa uzytkownika max 40 znakow
    float objetosc = 0, waga = 0;
    unsigned long rozmiar, litery;
    
    printf("Witaj, podaj swoje imie:\n");
    scanf("%s",nazwa);
    printf("%s, ile kilogramow wazysz?:\n",nazwa); getchar();
    scanf("%f",&waga);
    
    rozmiar = sizeof(nazwa);                            // ile bajtow zajmuje nazwa podana przez uzytkownika
    litery = strlen(nazwa);                            // dlugosc lancucha "nazwa" wpisanego przez uzytkownika
    objetosc = waga/gestosc;
    
    printf("zatem %s,Twoja objetosc wynosi : %2.2f metrow szesciennych \n",nazwa,objetosc);
    printf("ponadto Twoje imie zawiera %ld liter,\n",litery);
    printf("a na jego zapisanie zuzylismy %ld bajtow\n",rozmiar);
    
    fflush(stdout);
    getchar();
    
    return 0;
}
