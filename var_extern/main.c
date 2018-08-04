//
//  main.c
//  var_extern
//
//  Created by Jakub Chojnacki on 08/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

extern char array[];                                 // deklaracja nawiazujaca

int main(int argc, const char * argv[]) {
   
    puts(array);
    
    return 0;
}

// zmienna extern musi byc zadeklarowana w drugim pliku .c aby byla widoczna
// w przypadku pominiecia slowa kluczowego EXTERN zostanie ona zaslonieta przez nowa zmienna
