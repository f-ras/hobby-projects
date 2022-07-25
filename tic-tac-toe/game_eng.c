// Project by: Ferry Ras. Git: ferryrs.
// Boter Kaas en Eieren || Tic Tac Toe

#include <stdio.h>
#include <stdlib.h>

void	gamereset(int input[]);
void	draw_game(int input[], char help);
void	taketurns_eng(int input[], char instr, char *playerX, char *playerO);
void	turn_plX_eng(int input[], char *playerX);
void	turn_plO_eng(int input[], char *playerO);
int		checkwon(int input[]);
void	endgame_eng(int input[], int who_won, char *playerX, char *playerO);
void	continue_or_not_eng(int input[], char *playerX, char *playerO);
int		taken_or_outof_scope(int input[], int pos, int language, int ret);
char	input_yesno_errorcheck(char instr, int language);

void    game_eng(int input[], char *playerX, char *playerO)
{
    char    instr;
    
    printf("Do you want an instruction-map in game? Y/N: ");
    scanf(" %c", &instr);
    instr = input_yesno_errorcheck(instr, 1);
    gamereset(input);
    taketurns_eng(input, instr, playerX, playerO);
    endgame_eng(input, 3, playerX, playerO);
}

void    taketurns_eng(int input[], char instr, char *playerX, char *playerO)
{
    int     turn;

    turn = 0;
    while (turn < 9)
    {
        draw_game(input, instr);
        turn_plX_eng(input, playerX);
        system("clear");
        if(checkwon(input) == 1)
            endgame_eng(input, 1, playerX, playerO);
        turn++;
        draw_game(input, instr);
        if (turn == 9)
            break;
        turn_plO_eng(input, playerO);
        system("clear");
        if(checkwon(input) == 2)
            endgame_eng(input, 1, playerX, playerO);
        turn++;
    }
}
void    turn_plX_eng(int input[], char *playerX)
{
    int     pos;
    int     ret;

    printf("You are %s. What position do you want your X: ", playerX);
    fflush(stdin);
    ret = scanf(" %d", &pos);
    pos = taken_or_outof_scope(input, pos, 1, ret);
    input[pos - 1] = 1;
}
void    turn_plO_eng(int input[], char *playerO)
{
    int		pos;
    int     ret;

    printf("%s you are. What position do you want your O: ", playerO);
    fflush(stdin);
    ret = scanf("%d", &pos);
    pos = taken_or_outof_scope(input, pos, 1, ret);
    input[pos - 1] = 2;
}

void    endgame_eng(int input[], int who_won, char *playerX, char *playerO)
{		
    if (who_won == 1)
        printf("\n\n\n\n\n   [ [ [ [    * * * *    %s", playerX);
    if (who_won == 2)
        printf("\n\n\n\n\n   [ [ [ [    * * * *    %s", playerO);
    if (who_won != 3)
    {
        printf(" has won!    * * * *    ] ] ] ]  \n\n\n\n");
        draw_game(input, 'N');
        printf("\n\n\n");
    }
    if (who_won == 3)
    {
        printf("You are well matched ");
        printf("%s en %s... Draw!\n\n", playerX, playerO);
    }
    continue_or_not_eng(input, playerX, playerO);
}