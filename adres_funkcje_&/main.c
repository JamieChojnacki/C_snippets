//
//  main.c
//  adres_funkcje_&
//
//  Created by Jakub Chojnacki on 01/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
void zmienne_niezalezne(int);               // prot. funkcja majaca niezalezne zmienne ach i och
void zamien (int *u, int *v);                 // prot. funkcja ingerujaca w zmienne funkcji main

int main(int argc, const char * argv[]) {
    
    int ach = 2;
    int och = 5;
    
    printf("w funkcji main() ach = %3d ma adres : %p\n",ach, &ach);
    printf("w funkcji main() och = %3d ma adres : %p\n",och, &och);
    putchar('\n');
    zmienne_niezalezne(ach);                            // pobierz wartosc ach, czyli 2
    putchar('\n');
    
    int x = 5;
    int y = 10;
    printf("poczatkowo x = %d  y = %d\n",x ,y);
    zamien(&x, &y);                                                 // pobieramy adresy zmiennych x i y przypisanych do funkcji main
    printf("A teraz x = %d  y = %d\n",x ,y);
    putchar('\n');
    return 0;
}


void zmienne_niezalezne(int och)                        // przypisz och wartosc 2
{
    int ach = 10;
    printf("w funkcji zmienne_niezalezne() ach = %3d ma adres : %p\n",ach, &ach);
    printf("w funkcji zmienne_niezalezne() och = %3d ma adres : %p\n",och, &och);
    
    // wiec mozna zauwazyc, ze ach i och to pary dwoch zmiennych o roznych adresach.
    // co oznacza, ze kazda funkcja definiuje swoje zmienne jako niezalezne.
}

// za pomoca funkcji niezaleznej zamienimy wartosci  a i b funkcji main, uzywajac do tego adresow i dereferencji
// void zamien(int *u int *v)


void zamien (int *u, int *v)                     // przypisz adresy wskaznikom i znajdz ich wartosc
{
    
    int temp;                                     // zmienna tymczasowa
    
    temp = *u;                                    // zapamietaj stara wartosc u, czyli 5
    *u = *v;                                      // dereferencja - znajdz wartosc pod danym adresem. wkasujemy na u, zamieniamy wartosci
    *v = temp;                                    // dokoncz zamienianie wartosci
    
}
