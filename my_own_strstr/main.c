//
//  main.c
//  my_own_strstr
//
//  Created by Jakub Chojnacki on 20/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *adres(const char *, char *);

int main(int argc, const char * argv[]) {
    
    char *string_1 = "niespodzianka";
    char *string_2 = "pod";
    char * result;
    char * result_strstr;
    
    result = adres(string_1, string_2);
    result_strstr = strstr(string_1, string_2);
    
    puts(result_strstr);                            // rezultat uzyskany gotowa funkcja
    puts(result);                                       // rezultat uzyskany stworzeniem wlasnej funkcji
    
    return 0;
}

char *adres(const char *lancuch_1, char *lancuch_2)
{
    bool found = false;
    while(*lancuch_1 && *lancuch_2 != *lancuch_1)
    {
        lancuch_1 ++;
        if(*lancuch_2 == *lancuch_1)                                // udalo sie znalezc
            found = true;                                               // zmien stan logiczny
    }

    return (char *)(!found ? NULL : lancuch_1 );
}
