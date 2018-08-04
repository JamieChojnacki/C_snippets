//
//  main.c
//  echo_EOF
//
//  Created by Jakub Chojnacki on 14/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
 
    int sign;
    
    while((sign = getchar())!= EOF)                             // EOF - end of file - przyjmuje wartosc (-1)
        putchar(sign);                                          // aby zakonczyc dzialanie programu wcisnij ( ctr + d )
    
    return 0;
}
