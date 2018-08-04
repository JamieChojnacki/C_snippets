//
//  main.c
//  funkcja_rzad_znak
//
//  Created by Jakub Chojnacki on 03/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define znak "ch"
void rzad_znak(char sign, int raw, int train);
void rzad_znak_char(char *sign_char[], int raw, int train);

int main(int argc, const char * argv[]) {
    
    char def_sign[4] = "char";
    int raws = 0;
    int trains = 0;
    printf("k: rz:\n");
    scanf("%d,%d", &trains, &raws);
    
    rzad_znak('*', trains, raws);
    putchar('\n');
    rzad_znak_char(&def_sign[4], trains, raws);                              // pobierz teraz char
    putchar('\n');
    return 0;
}

void rzad_znak(char sign, int train, int raw)
{
    for(int i = 0; i < raw; i++)                                           // rzad
    {
        putchar('\n');
        for(int j = 0; j < train; j++)                                     // kolumna
            putchar(sign);
    }
}


void rzad_znak_char(char *sign_char[], int raw, int train)                 // zrob to samo co wyzej, tylko ze z lancuchem znakowym
{
    for(int i = 0; i < raw; i++)
    {
        putchar('\n');
        for(int j = 0; j < train; j++)
            printf("%c",sign_char[3]);
    }
    
}
