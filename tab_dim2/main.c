//
//  main.c
//  tab_dim2
//
//  Created by Jakub Chojnacki on 14/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#define raw_max 5
#define col_max 10


int main(int argc, const char * argv[]) {
   
    const float tab[raw_max][col_max] =                                                 // inicjalizacja tablicy dim 2
    {
        {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 1.1},
        {1.1, 2.2, 3.3, [6] = 1.5, 1.5, 1.5, 1.5},                                  // [6] = [7] = [8] = [9] = 1.5
        {[4] = 2.5, 2.5, 2.5, 2.5, 2.5, 2.5},
        {4.5, 4.5, 4.5, 4.5, 5.5, 5.5, 4.5, 4.5, 4.5, 4.5},
        {[8] = 10.5, 10.5}                                                              // [8] = 10.5 [9] = 10.5
    };
    
    int col, row;
    double line_amount, total_amount;
    
    for (row = 0, total_amount = 0; row < raw_max; row++)                   // pierwsza linia
    {
        for (col = 0, line_amount = 0; col < col_max; col++)                    // sumujemy pierwsza linie i wracamy do petli zewnetrznej
            line_amount += tab[row][col];                                           // sumuj elementy
        printf("suma rzedu %d, to %.3f\n", row + 1, line_amount);
        total_amount += line_amount;                                                    // laczna suma wszystkich linii
    }
    printf("laczna suma wynosci %.3f\n", total_amount);
    return 0;
}
