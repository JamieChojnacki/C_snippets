//
//  main.c
//  wartosci_pod_adresy
//
//  Created by Jakub Chojnacki on 04/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void compare_rock(double *value_1, double *value_2, double *value_3);                  // prot pobierania 3 wskaznikow
void compare_array(double *value_1, double *value_2, double *value_3);

int main(int argc, const char * argv[]) {
    
    double value1_rock;
    double value2_rock;
    double value3_rock;
    
    double value1;
    double value2;
    double value3;
    
    value1_rock = rand()%10;
    value2_rock = rand()%11;
    value3_rock = rand()%12;
    value1 = rand()%15;
    value2 = rand()%17;
    value3 = rand()%19;
    
    printf("\t%.3f \t\t\t\t %.3f \t\t\t %.3f\n", value1_rock,value2_rock,value3_rock);                                 // wartosci
    printf("%p   |   %p   |   %p\n", &value1_rock,&value2_rock,&value3_rock);                                   // adresy
    putchar('\n');
    compare_rock(&value1_rock, &value2_rock, &value3_rock);                                                        // pobieramy adresy
    
    printf("\t%.3f \t\t\t\t %.3f \t\t\t %.3f\n", value1,value2,value3);                               // wartosci uporzadkowane rosnaco
    printf("%p   |   %p   |   %p\n", &value1_rock,&value2_rock,&value3_rock);
    putchar('\n');
    printf("\t%.3f \t\t\t\t %.3f \t\t\t %.3f\n", value1,value2,value3);                                 // wartosci
    printf("%p   |   %p   |   %p\n", &value1,&value2,&value3);                                   // adresy
    putchar('\n');
    compare_array(&value1, &value2, &value3);                                                        // pobieramy adresy
    
    printf("\t%.3f \t\t\t\t %.3f \t\t\t %.3f\n", value1,value2,value3);                               // wartosci uporzadkowane rosnaco
    printf("%p   |   %p   |   %p\n", &value1,&value2,&value3);
    
    putchar('\n');
    return 0;
}


void compare_rock(double *value_1, double *value_2, double *value_3)                            // wersja lopatologiczna i slaba
{
    double temp;                                                                            // zmienna tymczasowa
    temp = *value_1;                                                                    // przypisanie wartosci pierwszej do tymcz.
    *value_1 = (*value_1 < *value_2) ? *value_1 : *value_2;
    *value_1 = (*value_1 < *value_3) ? *value_1 : *value_3;                                     // magia, sprawdzanie kazdego z kazdym
    *value_2 = ( (*value_2 < *value_3) && (*value_3 != *value_1) ) ? *value_2 : *value_3;
    *value_2 = (*value_2 < temp) ? *value_2 : temp;                                             // za duzo roboty ...
    *value_3 = (*value_3 > temp) ? *value_3 : temp;
}


void compare_array(double *value_1, double *value_2, double *value_3)               // wersja madra i dobra
{
    int swapped;
    double temp = 0.0;
    double array[3] = {*value_1, *value_2, *value_3};
    
    while(1){
    
        swapped = 0;                                                                            // wraz z kazda iteracja zeruj ilosc zmian
        
        for(int i = 0; i < 2; i++) {                                                         // szukamy minimum
            if(array[i+1] < array[i])
            {
            temp = array[i];                                                            // zapisz stara wartosc
            array[i] = array[i+1];
            array[i+1] = temp;
                swapped = 1;                                                        // jezeli udalo sie zamienic to swapped 1
            }
        }
        if(swapped == 0)                                                        // jezeli nie bylo juz zadnych zmian, to zakoncz
            break;
    }
    
    *value_1 = array[0];                                                    // wynik koncowy do wskaznika pod wskazany adres
    *value_2 = array[1];
    *value_3 = array[2];
}


