//
//  funkcje.h
//  laczenie_plikow
//
//  Created by Jakub Chojnacki on 23/11/2017.
//  Copyright © 2017 James. All rights reserved.
//
//  deklaracje wszystkich uzywanych stalych i prototypy funkcji

#define funkcje_h
#define GWIAZDKI "***************************"
#define KONIEC 5
#define HOTEL1 80.00
#define HOTEL2 125.00
#define HOTEL3 155.00
#define HOTEL4 200.00
#define RABAT 0.95
int menu(void);
// pokazuje liste wyborow
int pobierz_noce(void);
//zwraca zadana liczbe nocy
void pokaz_cene(double hotel, int noce);
// oblicza cene i stawke na podstawie ilosci noclegow i wyswietla wynik

