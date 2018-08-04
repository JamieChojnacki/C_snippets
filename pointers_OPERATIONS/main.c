//
//  main.c
//  pointers_OPERATIONS
//
//  Created by Jakub Chojnacki on 16/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int values[5] = {100,200,300,400,500};
    int *p1, *p2, *p3;
    
    p1 = values;                                        // przypisuje adres wskaznikowi
    p2 = &values[2];                                        // jw.
    
    printf("wartosc wskaznika:     wskazywana wartosc:    adres wskaznika:\n");
    printf("p1 = %p,        *p1 = %d,      &p1 = %p\n",
           p1, *p1, &p1);
    
/* <><><><><><><><><><><><><><><><><><><><><><> */
    
    
        // dodawanie wskaznikow
    
    p3 = p1 + 4;
    printf("\ndodanie int do wskaznika:\n");
    printf("p1 + 4 = %p     *(p1 + 3) = %d\n",
           p1 + 4, *(p1 + 3));
    
    
    
/* -------------------------------------------- */
    
    
    
        // inkrementacja wskaznika
    
    p1++;
    printf("\nwartosc po p1++:\n");
    printf("p1 = %p,        *p1 = %d,      &p1 = %p\n",
           p1, *p1, &p1);
    
    
    
/* -------------------------------------------- */
    
    
    
        // dekrementacja wskaznika
    
    p2--;
    printf("\nwartosc po p2--:\n");
    printf("p1 = %p,        *p1 = %d,      &p1 = %p\n",
           p2, *p2, &p2);
    
    
    
/* -------------------------------------------- */
    
    
    
        // przywrocenie wartosci poczatkowych
    
    --p1;
    ++p2;
    printf("\np1 i p2 przywrocone do wartosci poczatkowych:\n");
    printf("p1 = %p,        p2 = %p\n",
           p1, p2);
    
    
    
/* -------------------------------------------- */
    
    
    
         // odejmowanie jednego wskaznika od drugiego
    
    
    printf("\nodejmowanie jednego wskaznika od drugiego:\n");
    printf("p2 = %p,        *p1 = %p,      p2 - p1 = %ld\n",
           p2, p1, p2 - p1);
    
         // odejmowanie wskaznika od stalej
    
    printf("\nodejmowanie wskaznika od stalej:\n");
    printf("p3 = %p,        p3 - 2 = %p\n",
           p3, p3 - 2);
    

/* <><><><><><><><><><><><><><><><><><><><><><> */
    putchar(0x0a);
    return 0;
}
