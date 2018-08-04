//
//  main.c
//  argc_*argv
//
//  Created by Jakub Chojnacki on 13/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int i, razy;
    if(argc < 2 || (razy = atoi(argv[1])) < 1)
        printf("sposob uzycia %s, liczba - dodatnia\n", *argv);
    else
        for( i=0; i< razy; i++ )
            puts("witaj przystojniaku");
    
    return 0;
}
