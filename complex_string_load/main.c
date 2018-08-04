//
//  main.c
//  complex_string_load
//
//  Created by Jakub Chojnacki on 22/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include "cnv.h"

int main(int argc, const char * argv[]) {
    
    
    char array[LAYERS][C_MAX];
    int array_atoi[LAYERS][C_MAX];
    char *p_array[LAYERS];
    int choice;
    int licz = 0;
    
    puts("wprowadz lancuchy :");
    while(licz < LAYERS && load(array[licz], C_MAX) && array[licz][0] != 0x0)
    {
        p_array[licz] = array[licz];
        licz++;
    }
    
    while( (choice = menu())!= KONIEC)
    {
        switch(choice)
        {
            case 1:
                wyswietl(array, licz);
                break;
            case 2:
                srtlan(p_array, licz);
                for(int k = 0; k < licz; k++)
                    puts(p_array[k]);
                break;
            case 3:
                sort_ASCII(p_array, licz);
                for(int m = 0; m < licz; m++)
                    puts(p_array[m]);
                break;
            case 4:
                srtlan_length(p_array, licz);
                for(int l = 0; l < licz; l++)
                    puts(p_array[l]);
                break;
            case 5:
                string_to_integar(array, array_atoi, licz);
                for(int i = 0; i < licz; i++)
                    for(int j = 0; j < C_MAX; j++)
                        printf("%d", array_atoi[i][j]);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
