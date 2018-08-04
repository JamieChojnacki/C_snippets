// tictactoe
// jedziemy wszystko na wskaznikach

#include <stdio.h>
#include <ctype.h>                      // potrzebne do isdigit

void ground(void);                              // prototyp funkcji pola gry
int check_winner(int *which_player);

int czy_idiota(int *co_wpisal);                             // spradzamy czy grajacy nie jest idiota i umie czytac

char board [3][3] = {                              // rozpisujemy pole gry
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};



int row = 0;
int column = 0;
int line = 0;


int main (void)
{
    int player = 0;
    int winner = 0;
    int choice = 0;
    int stop = 0;
    
    for (int i = 0; i<9 && winner==0; i++)
    {
        
        ground();                                               // wyswietl pole do gry
        player = i%2 + 1;                                           // cykliczna zmiana gracza
        
        do
        {
        step:
            printf("\nGraczu %d, wpisz numer pola "
                   "na ktorym chcesz umiescic %c:\n",
                   player,(player==1)?'X':'O');
            stop = 0;
            scanf("%d", &choice);
            
            if(choice == EOF || choice == 0x0a)             // jezeli jest koncem pliku badz poczatkiem nowej linii
                continue;                                       // to ignoruj
            
            stop = czy_idiota(&choice);                             // pobierz wybor gracza
            
            if (stop == 1)                                              // jezeli wpisal cos innego niz to co trzeba
            {
                printf("jestes skonczonym debilem !, wpisz NUMER pola\n");                // to go opluj
                goto step;                                                                       // idz do ponownego wyboru
                
            }
                
            
            row = --choice/3;
            column = choice%3;
            
        }
        while(choice<0 || choice>9 || board [row][column]>'9');
        
        board[row][column] = (player == 1) ? 'X' : 'O';                             // zmien na kolejnego gracza
        
        winner = check_winner(&player);                                                 // sprawdz czy ktorys z graczy wygral
        
        
    }
    
    ground();                                       // wyswietl pole do gry
    
    if(winner == 0)                     // jezeli nie ma zwyciezcy to remis
        printf("REMIS !\n");
    else
        printf("Gracz %d wygral !\n", winner);
    
    return 0;
}


void ground(void)                               // wyswitlamy gre w postaci  tablicy dwu wymiarowej
{
    printf("\n\n");
    printf(" %c | %c | %c\n", **board, *(*(board)+1), *(*(board)+2) );
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", *(*(board+1)), *(*(board+1)+1), *(*(board+1)+2) );
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", *(*(board+2)), *(*(board+2)+1), *(*(board+2)+2) );
    
}


int check_winner(int *which_player)                     // sprawdzamy czy gracz 1 lub 2 wygral
{
    int result = 0;

    if( ( ((**board) == *(*(board+1)+1) && (**board) == *(*(board+2)+2)) ||                 // sprawdzamy po skosie od lewej do prawej
       ( *((*board)+2) == *(*(board+1)+1) && *((*board)+2) == *(*(board+2)) )) )                // sprawdzamy po skosie od prawej do lewej
        result = *which_player;
    else
        for(line = 0; line <=2; line++)
            if( ( *(*(board + line)) == *(*(board + line)+1) && *(*(board + line)) == *(*(board + line)+2) ) ||            // sprawdzamy pion i poziom
               ( *(*(board)+line) == *(*(board+1) + line) && *(*(board) + line) == *(*(board +2)+line) ))
                result = *which_player;
    
    return result;                                      // zwracamy gracza ktory wygral
}


int czy_idiota(int *co_wpisal)
{
    int moron = 0;

    if (*co_wpisal > 9 || *co_wpisal < 0 )
        moron = 1;
    
    return moron;                        // jezeli jest cyfra to 0 jezeli nie to debil
}

