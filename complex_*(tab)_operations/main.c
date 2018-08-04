//
//  main.c
//  complex_*(tab)_operations
//
//  Created by Jakub Chojnacki on 24/01/2018.
//  Copyright © 2018 James. All rights reserved.
//
// kompleksowy program wykonujacy dzialania na tablicach dim 1

#include <stdio.h>
#include <stdbool.h>

double max(double *check, int size);                                 // znajdujemy najwieksza wartosc
double m_index(const double *check_const, int size);                    // znajduje indeks tablicy z najwieksza wartoscia
double diff(double *diff_const, int size);                            // roznica miedzy najwiekszym i najmniejszym elementem
void swapp(double *swapp, int size);                               // zamieniamy elementy miejscami
double find_max(double *array_max, double *size);                                // znajdujemy max metoda adresow
double find_min(double *array_min, double *size);                                   // znajdujemy min metoda adresow

int main(int argc, const char * argv[]) {
    
    int ar_1;
    int ar_2;
    int ar_3;
    int ar_4;
    double max_value;                               // maksymalna wartosc w tablicy
    int maximal_index;                              // index minimalny
    double difference = 0l;                         // roznica max i min
    
    double array_1[] = {1.5, 2.5, 3.5, 4,5, 216, 7, 18, 999};
    double array_swapp[] = {1.5, 2.5, 3.5, 4, 5, 16, 17, 18, 19};
    double array_diff[] = {150, 2, 22.5, 3.5, 7,5, 16, 17, 18, 55, 100, 1.5, 0.5, 33.5};
    const double array_2[] = {1.5, 2.5 ,15, [7] = 12, 9};
    
    
    ar_1 = sizeof(array_1)/sizeof(double);                      // ilosc elementow tablicy 1
    ar_2 = sizeof(array_2)/sizeof(double);                          // ilosc elementow tablicy 2
    ar_3 = sizeof(array_swapp)/sizeof(double);                          // ilosc elementow tablicy do odwrocenia
    ar_4 = sizeof(array_diff)/sizeof(double);                               // rozmiar tablicy do roznicy max i min
    
    for(int k = 0; k < ar_2; k++)
        printf("%lf\t", *(array_2+k) );
    
    putchar(0x0a);
    
    printf("ar_1 = %d \nar_2 = %d\nar_3 = %d \nar_4 = %d\n", ar_1, ar_2, ar_3, ar_4);
    
    putchar(0x0a);
    
    max_value = max(array_1, ar_1);
    
    printf("max value found in array_1 is %.3lf\n", max_value);                 // max wartosc w tablicy
    
    putchar(0x0a);
    
    maximal_index = m_index(array_2, ar_2);                                         // indeks posiadajacy najwieksza wartosc
    
    printf("max index found in array_2 is %d\n", maximal_index);
    
    putchar(0x0a);
    
    for(int i = 0; i < ar_3; i ++)                                                      // tablica oryginalne
    {
        printf("index : %d wartosc %f\n", i, *(array_swapp + i) );
    }
    
    putchar(0x0a);
    
    swapp(array_swapp, ar_3);                                                       // zamieniamy elementy tablicy
    
    for(int j = 0; j < ar_3; j ++)                                                      // tablica po odwroceniu
    {
        printf("index : %d wartosc %f\n", j, *(array_swapp + j) );
    }
    
    putchar(0x0a);
    
    difference = diff(array_diff, ar_4);                                         // roznica miedzy max i min
    
    printf("roznica miedzy wartoscia max a min to : %.3lf\n", difference);
    
    putchar(0x0a);
    
    return 0;
}

/* ------------------------------------------------------------------------------------------------ */
double max(double *check, int size)         // funkcja do znajdowania maxiumum tablicy
{
    double maximum = 0;
    bool swapped = false;
    int temp = 0;
    
    while(1)
    {
        swapped = false;
        
            for (int i = 0; i < size - 1; i++)                   // sprawdz dla wszystkich indekswo
            {
                if( *(check + (i + 1) ) > *(check + i) )
                {
                    swapped = true;                                     // jezeli jeszcze cos zamieniles to kontunuuj dzialanie petli i sprawdz dalej
                    temp = *(check + i);
                    *(check + i) = *(check + (i + 1) );
                    *(check + (i + 1) ) = temp;
            
                }
            }
        
        if (!swapped)                                               // jezeli elementy sa juz ulozone, to przerwij petle
        {
            maximum = *check;
            break;
        }
    }
    
    
    return maximum;
}

/* ------------------------------------------------------------------------------------------------ */
double m_index(const double *check_const, int size)
{                                                           // [ 1.5,  2.5,  15,  0,  0,  0,  0,  0,  8,  9 ]
    int found_index = 0;
    int goal = 0;
    double temp = *(check_const);
    
    
        for (int j = 0; j < size-1; j++)                   // sprawdz dla wszystkich indekswo
        {
            if( (*(check_const + (j + 1) ) > *(check_const + j) ) && (*(check_const + (j + 1) ) > temp ) )
            {
                goal = (j+1);
                temp = *(check_const + (j+1) );
            }
        }
    found_index = goal;
    return found_index;
}


/* ------------------------------------------------------------------------------------------------ */
double diff(double *diff, int size)                                                                                 // roznica pomiedzy max i min
{
    double difference = 0;
    
    difference = find_max(diff, diff + size) - find_min(diff, diff + size);                                             // zagniezdzamy mniejsze funkcje
    
    return difference;
}


/* ------------------------------------------------------------------------------------------------ */
void swapp(double *swapp, int size)                                                                             // odwracamy tablice
{
    double temp = 0;
    
    for(int i = 0; i < (size - 1) / 2; i ++)                                                                        // odbicie lustrzane, wiec dzielimy rozmiar na 2
    {
        temp = *(swapp + i);
        *(swapp + i) = *(swapp + (size - (i + 1)));
        *(swapp + (size - (i + 1))) = temp;
    }
    
}


/* ------------------------------------------------------------------------------------------------ */
double find_max(double *array_max, double *size)                                                                    // szukamy max
{
    double max = 0l;
    double temp = *array_max;
    
    while(array_max++ < size - 1)                                                                                   // dodajemy element tablocy az do momentu kiedy wyjdzie poza adres
    {
        if( (*(array_max) > *array_max - 1) && *(array_max) > temp )
            temp = *(array_max);                                                            // zmieniamy wartosc tymczasowa
    }
    max = temp;
    return max;
}


/* ------------------------------------------------------------------------------------------------ */
double find_min(double *array_min, double *size)                                                                    // szukamy min tablicy
{
    double min = 0;
    double temp = *array_min;
    
    while(array_min++ < size - 1)
    {
        if( ((*(array_min) < *(array_min - 1)) && (*(array_min) < temp )) )
            temp = *(array_min);
    }
    min = temp;

    return min;
}




