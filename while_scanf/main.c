//  while z wykorzystaniem bajeranckiej intrukcji scanf
//  main.c
//  while_scanf
//
//  Created by Jakub Chojnacki on 21/08/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    long int number, suma =0L;      // 0L - zero w formacie long, inaczej konwersja auto do int
    int stan;
    printf("podaj liczbe do sumy:\n");
    
    stan = scanf("%ld", &number);
    
    while(stan == 1){       // jezeli uda sie pobrac scanf liczbe to 1 jezeli nie, to 0, dlatego
                            // wpisanie jakiejkolwiek cyfry spowoduje koniec instrukcji
        
        suma = suma + number;           //obecny stan sumy
        
        printf("podaj kolejna liczbe:\n");
        stan = scanf("%ld",&number);            //sprawdzam stan z kazda iteracja petli (b.wazne)
    }
    puts("\n");
    printf("wartosc sumy to %ld: \n", suma );       //suma koncowa
    
    
    
    return 0;
}
