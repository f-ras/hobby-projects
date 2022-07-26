//                                                                            //
//                                                                  ___ __    //
//                                                                 (_  /__)   //
//                                                                 /  / (     //
//      (                                                                     //
//       )                                                                    //
//      (   ) (                                                               //
//     _______)_                                       main.c                 //
//  .-'---------|                                                             //
// ( C|/\GitHub/|                                                             //
//  '-./\f-ras\/|   E-mail:     ferryras@gmail.com                            //
//    '_________'   LinkedIn:   https://www.linkedin.com/in/ferryras/         //
//     '-------'                                                              //
// Project by: Ferry Ras. Git: f-ras                                          //
// Boter Kaas en Eieren || Tic Tac Toe                                        //

#include <locale.h>

#define MAX_NAME_SZ		256

int     language_select(void);
void    player_select(char *player1, char *player2, int language);
void    gamereset(int input[]);
void    game_eng(int input[], char *playerX, char *playerO);
void    game_nl(int input[], char *playerX, char *playerO);

int     main(void) 
{
    char    playerX[MAX_NAME_SZ];
    char    playerO[MAX_NAME_SZ];
    int     input[9];
    int     language; // ENG = 1, NL = 2.

    // language = language_select_old(); -- Replaced.
    //                                      Keeping for reference purposes.
    language = language_select();
    player_select(playerX, playerO, language);
    gamereset(input);
    setlocale(LC_ALL, "");
    if (language == 1)
        game_eng(input, playerX, playerO);
    if (language == 2)
        game_nl(input, playerX, playerO);
    return (0);
}

void    gamereset(int input[])
{
    int	i;
    
    i = 0;
    while (i < 9)
        input[i++] = 0;
}
