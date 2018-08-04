//
//  main.c
//  strncmp_znajdz_astro
//
//  Created by Jakub Chojnacki on 04/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define ROZMIAR_LISTY 5

int main(int argc, const char * argv[]) {
    
    const char *lista[ROZMIAR_LISTY] = {
        "astronomia", "asteroida",
        "astronom", "ostroga",
        "asteryzm"
    };
    int licznik = 0;
    
    for(int i = 0; i < ROZMIAR_LISTY; i++ )
        if(strncmp( *(lista + i), "astro", 5) == 0)     // jezeli znaleziono lancuch zaczynajacy sie na "astro"
        {
            printf("znaleziono %s\n", *(lista + i));
            licznik++;
        }
    printf("w liscie znajduja sie %d slowa zaczynajace sie na \"astro\"\n", licznik);
    
    
    return 0;
}

