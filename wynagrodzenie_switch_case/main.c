//
//  main.c
//  wynagrodzenie_switch_case
//
//  Created by Jakub Chojnacki on 11/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
                                // mozliwe wynagrodzenie za godzine
const int SALARY_1 = 35;
const int SALARY_2 = 37;
const int SALARY_3 = 40;
const int SALARY_4 = 45;


int main(int argc, const char * argv[]) {
    
    int work_time;                                                                  // ilosc przepracowanych godzin
    long int summ = 0;                                                              // calkowita suma wynagrodzenia
    int choice;
    
    printf("podaj ilosc przepracowanych godzin\n");
    scanf("%d",&work_time);
a:                                                                                  // zacznij od a jezeli nie udalo sie
    printf("wybierz jedna z podanych ponizej opcji\n");
    printf("1. 35 zl/godz.  \t\t\t\t 2. 37 zl/godz.\n");
    printf("3. 40 zl/godz.  \t\t\t\t 4. 45 zl/godz.\n");
    scanf("%d", &choice);
    
    if(choice >= 1 && choice <= 4)                                                  // jezeli liczba jest z zakrecu <1:4> przejdz dalej
    {
    switch(choice)                                                                  // wykonaj zadane polecenie
    {
        case 1:
            summ = 35 * work_time;
            break;
        case 2:
            summ = 37* work_time;
            break;
        case 3:
            summ = 40* work_time;
            break;
        case 4:
            summ = 45* work_time;
            break;
    }
    }
    else                                                                         // jezeli liczba nie byla z zakresu <1:4>
        {
            printf("liczba nie nalezy do zakresu 1-4, sprobuj ponownie\n");
            goto a;                                                              // idz do a
        }
    
    
    printf("Twoje wynagrodzenie  za przepracowanie (%2d) godzin wynosi (%3ld) zl\n",work_time, summ);              // zwroc ilosc zarobionych pieniedzy
    return 0;
}
