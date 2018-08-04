//
//  cnv.h
//  complex_string_load
//
//  Created by Jakub Chojnacki on 22/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#ifndef cnv_h
#define cnv_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LAYERS 10
// maksymalna ilosc rzedow w tablicy
#define C_MAX 80
// maksymalna ilosc kolumn w tablicy
#define KONIEC 0
// wpisanie 0 powoduje koniec
#define GWIAZDKI "***********************"

int menu(void);
// funkcja pobiera znak od uzytkownika

void wyswietl(char (*p_array)[C_MAX], int );
// funkcja wyswietlajaca zawartosc tablicy

void srtlan(char *ar_string[], int num );
// prototyp funkcji sortujacej lancuchy alfabetycznie

void srtlan_length(char *ar_string[], int num);
// prototyp funkcji sortujacej lancuchy pod wzgledem dlugosci

void sort_ASCII(char *ar_string[], int num);
// prototyp funkcji sortujacej lancuchy ze wzgledu na kod ASCII

void string_to_integar(char (*p_array)[C_MAX], int (*target)[C_MAX] ,int num);
// prototyp zamieniajacy lancuch na liczbe calkowita

char *load(char *target, int bufor);
// funkcja wypelniajaca bufor

#endif /* cnv_h */
