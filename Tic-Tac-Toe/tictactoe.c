#include <stdio.h>
#include <stdlib.h>

int won(int[]);
void play(int, int*, int[]);
void updategrid(int, int);

char grid[5][12] = {" 0 | 1 | 2 \n", "-----------\n", " 3 | 4 | 5 \n", "-----------\n", " 6 | 7 | 8 \n" };

int main(){
    int game[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10}, end = 0, turn = 0, count = 0;
    printf("%s", grid);
    while (!end){
        
        play(turn, &end, game);
        if(end) break;
        turn++;
        count++;
        if(count == 5) break;
        play(turn, &end, game);
        if(end) break;
        turn--;
        
    }

    if (count == 5){
        printf("\nIt is a draw.\n");
        return 0;
    }

    printf("\nThe winner is Player%d\n", (turn) ? 2 : 1);
    return 0;
}

void play(int turn, int *end, int game[]){
    int dec, i;
    
    if(!turn) printf("Player1 ");
     else printf("Player2 ");

     printf("insert decision: ");

    do{
        scanf("%d", &dec);
    }while(dec < 0 || dec > 8 || game[dec] == -1 || game[dec] == 1);
    
    updategrid(dec, turn);

    game[dec] = 1 - 2*turn;
    
    if (won(game)) *end = 1;
      
}

int won(int game[9]){
    if(game[0] == game[1] && game[1] == game[2])
        return 1;

    if(game[3] == game[4] && game[4] == game[5])
        return 1;

    if(game[6] == game[7] && game[7] == game[8])
        return 1;

    if(game[0] == game[3] && game[3] == game[6])
        return 1;

    if(game[1] == game[4] && game[4] == game[7])
        return 1; 

    if(game[2] == game[5] &&  game[5] == game[8])
        return 1;
    
    if(game[0] == game[4] && game[4] == game[8])
        return 1;
    
    if(game[2] == game[4] && game[4] ==  game[6])
        return 1;

    return 0;
}

void updategrid(int coordinate, int turn){
    char up;
    if (!turn) up = 'X';
        else up = 'O';

    switch(coordinate){
        case 0: grid[0][1] = up; break;
        case 1: grid[0][5] = up; break;
        case 2: grid[0][9] = up; break;
        case 3: grid[2][1] = up; break;
        case 4: grid[2][5] = up; break;
        case 5: grid[2][9] = up; break;
        case 6: grid[4][1] = up; break;
        case 7: grid[4][5] = up; break;
        case 8: grid[4][9] = up; break;
        default: break;
    }

    printf("%s", grid);
}