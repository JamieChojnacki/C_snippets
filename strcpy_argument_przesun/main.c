//
//  main.c
//  strcpy_argument_przesun
//
//  Created by Jakub Chojnacki on 05/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define SLOWO "cukier"
#define ROZMIAR 40

int main(int argc, const char * argv[]) {
    
    const char *source = SLOWO;
    char kopia[ROZMIAR] = "podaj mnie do sadu";
    char *wl;
    puts(source);
    puts(kopia);
    wl = strcpy(kopia + 6, SLOWO);      // pierwszym argumentem jest kopia + 6, dlatego wl wyswietli tylko lancuch od tego miejsca
    puts(kopia);                            // "podaj cukier"
    puts(wl);                                   // "cukier"
    
    return 0;
}
