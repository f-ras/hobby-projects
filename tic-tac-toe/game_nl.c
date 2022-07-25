// Project by: Ferry Ras. Git: ferryrs.
// Boter Kaas en Eieren || Tic Tac Toe

#include <stdio.h>
#include <stdlib.h>

void    gamereset(int input[]);
void    draw_game(int input[], char help);
void    taketurns_nl(int input[], char instr, char *playerX, char *playerO);
void    turn_plX_nl(int input[], char *playerX);
void    turn_plO_nl(int input[], char *playerO);
int	    checkwon(int input[]);
void    endgame_nl(int input[], int who_won, char *playerX, char *playerO);
void    continue_or_not_nl(int input[], char *playerX, char *playerO);
int     taken_or_outof_scope(int input[], int pos, int language, int ret);
char    input_yesno_errorcheck(char instr, int language);

void    game_nl(int input[], char *playerX, char *playerO)
{
    char	instr;
    
    printf("Willen jullie een instructie-kaart bij het spel? J/N: ");
    scanf(" %c", &instr);
    instr = input_yesno_errorcheck(instr, 2);
    gamereset(input);
    taketurns_nl(input, instr, playerX, playerO);
    endgame_nl(input, 3, playerX, playerO);
}

void    taketurns_nl(int input[], char instr, char *playerX, char *playerO)
{
    int		turn;

    turn = 0;
    while (turn < 9)
    {
        draw_game(input, instr);
        turn_plX_nl(input, playerX);
        system("clear");
        if(checkwon(input) == 1)
            endgame_nl(input, 1, playerX, playerO);
        turn++;
        draw_game(input, instr);
        if (turn == 9)
            break;
        turn_plO_nl(input, playerO);
        system("clear");
        if(checkwon(input) == 2)
            endgame_nl(input, 2, playerX, playerO);
        turn++;
    }
}
void    turn_plX_nl(int input[], char *playerX)
{
    int		pos;
    int		ret;

    printf("Jij bent %s. Welke positie wil jij jouw X: ", playerX);
    fflush(stdin);
    ret = scanf(" %d", &pos);
    pos = taken_or_outof_scope(input, pos, 2, ret);
    input[pos - 1] = 1;
}
void    turn_plO_nl(int input[], char *playerO)
{
    int		pos;
    int		ret;

    printf("%s jij bent. Welke positie wil jij jouw O: ", playerO);
    fflush(stdin);
    ret = scanf("%d", &pos);
    pos = taken_or_outof_scope(input, pos, 2, ret);
    input[pos - 1] = 2;
}

void    endgame_nl(int input[], int who_won, char *playerX, char *playerO)
{		
    if (who_won == 1)
        printf("\n\n\n\n\n   [ [ [ [    * * * *    %s", playerX);
    if (who_won == 2)
        printf("\n\n\n\n\n   [ [ [ [    * * * *    %s", playerO);
    if (who_won != 3)
    {
        printf(" heeft gewonnen!    * * * *    ] ] ] ]  \n\n\n\n");
        draw_game(input, 'N');
        printf("\n\n\n");
    }
    if (who_won == 3)
    {
        printf("Jullie zijn aan elkaar gewaagd ");
        printf("%s en %s... Gelijk spel!\n\n", playerX, playerO);
    }
    continue_or_not_nl(input, playerX, playerO);
}