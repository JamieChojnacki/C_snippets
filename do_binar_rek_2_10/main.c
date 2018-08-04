//
//  main.c
//  do_binar_rek_2_10
//
//  Created by Jakub Chojnacki on 07/12/2017.
//  Copyright © 2017 James. All rights reserved.
//  

#include <stdio.h>
void do_binar(unsigned long value, int base);
void print(unsigned long conv_check, int base_check);

int main(int argc, const char * argv[]) {
  
    unsigned long value_dec = 0;
    int base_dec = 0;
    
    printf("podaj liczbe oraz podstawe binarna :\n");
   while( scanf("%lu,%d", &value_dec, &base_dec) == 2)
   {
       if(base_dec < 2 || base_dec > 10)                                            // zamiana jedynie w granicach 2 do 10
       {
           printf("podales zla wartosc bazy (2 do 10), zacznij od poczatku\n");
           continue;
       }
       
       printf("odpowiednik w systemie %d\n", base_dec);
       do_binar(value_dec,base_dec);
       putchar('\n');
   }
    return 0;
}



void do_binar(unsigned long value, int base)                // zamienia dec na odpowiednik base
{
    unsigned long conv;
    
    conv = value % base;
    if(value >= base)
    do_binar(value/base, base);                     // rekurencja koncowa
    print(conv, base);                                  // sprawdzanie i wypisywanie po rekurencji koncowej

}

void print(unsigned long conv_check, int base_check)            // sprawdza base i wypisuje liczbe w odpowiedniku base
{
    
    if(base_check == 2)                                                 // dla base = 2
        putchar(conv_check == 0 ? '0' : '1');
    if(base_check == 8)
        putchar(conv_check == 0 ? '0' : '2');
    if(base_check == 10)
        printf("%lu", conv_check);
}
