/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   selections.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: )                                            +#+                     */
/*                                                   +#+                      */
/*   Created: Invalid date        by               #+#    #+#                 */
/*   Updated: 2023/04/24 17:06:48 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//     '-------'                                                              //
// Project by: Ferry Ras. Git: f-ras                                          //
// Boter Kaas en Eieren || Tic Tac Toe                                        //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_NAME_SZ		256
#define	_CLEARSCREEN	"\e[H\e[J"

void    player_select(char *player1, char *player2, int language);
void    continue_or_not_eng(int input[], char *playerX, char *playerO);
void    continue_or_not_nl(int input[], char *playerX, char *playerO);
char    input_yesno_errorcheck(char instr, int language);
void    game_eng(int input[], char *playerX, char *playerO);
void    game_nl(int input[], char *playerX, char *playerO);

int     language_select(void)
{
    char input[128];

    printf(_CLEARSCREEN);
    printf("Choose your language. || ");
    printf("Kies een taal.\nNL / ENG?\n\n");
    fflush(stdin);
    fgets(input, 128, stdin);
    while (strcasecmp(input, "eng\n") != 0 && strcasecmp(input, "nl\n") != 0)
    {
        printf(_CLEARSCREEN);
        printf("Incorrect input - Onjuist invoer.\n");
        printf("Select Language - Selecteer Taal.\n\nNL / ENG?\n\n");
        fflush(stdin);
        fgets(input, 128, stdin);
    }
    if (strcasecmp(input, "eng\n") == 0)
    {
        printf(_CLEARSCREEN);
        printf("This is Tic-tac-toe.\n\n");
        return (1);
    }
    if (strcasecmp(input, "nl\n") == 0)
    {
        printf(_CLEARSCREEN);
        printf("Dit is boter kaas en eieren.\n\n");
        return (2);
    }
    return 0;
}

void    player_select(char *playerX, char *playerO, int language)
{
    if (language == 1)
    {
        printf("Enter name player 1 (X): ");
        fflush(stdin);
        fgets(playerX, MAX_NAME_SZ, stdin);
        playerX[strlen (playerX) - 1] = '\0';
        printf("Enter name player 2 (O): ");
        fflush(stdin);
        fgets(playerO, MAX_NAME_SZ, stdin);
        playerO[strlen (playerO) - 1] = '\0';
        printf(_CLEARSCREEN);
        printf("Welcome %s and %s. Have fun! And don't get beated.\n\n",
            playerX, playerO);
    }
    if (language == 2)
    {
        printf("Voer naam in speler 1 (X): ");
        fflush(stdin);
        fgets(playerX, MAX_NAME_SZ, stdin);
        playerX[strlen (playerX) - 1] = '\0';
        printf("Voer naam in speler 2 (O): ");
        fflush(stdin);
        fgets(playerO, MAX_NAME_SZ, stdin);
        playerO[strlen (playerO) - 1] = '\0';
        printf(_CLEARSCREEN);
        printf("Welkom %s en %s. ", playerX, playerO);
        printf("Veel plezier! En laat je niet kapot maken.\n\n");
    }
}

void    continue_or_not_eng(int input[], char *playerX, char *playerO)
{
    char	yn;

    printf("New game? Y/N: ");
    scanf(" %c", &yn);
    yn = input_yesno_errorcheck(yn, 1);
    if (yn == 'n' || yn == 'N')
    {	
        printf(_CLEARSCREEN);
        printf("Thanks for playing. See you! Cheers Ferry.\n");
        system("read -n 1 -s -p \"Press any key to exit...\"");
        printf(_CLEARSCREEN);
        exit(0);
        exit(0);
    }
    else
        printf("Same players? Y/N: ");
    scanf(" %c", &yn);
    yn = input_yesno_errorcheck(yn, 1);
        printf(_CLEARSCREEN);
    if	(yn == 'y' || yn == 'Y')
        game_eng(input, playerX, playerO);
    else
    {
        player_select(playerX, playerO, 1);
        game_eng(input, playerX, playerO);
    }
}

void    continue_or_not_nl(int input[], char *playerX, char *playerO)
{
    char	yn;

    printf("Nieuw spel? J/N: ");
    scanf(" %c", &yn);
    yn = input_yesno_errorcheck(yn, 2);
    if (yn == 'n' || yn == 'N')
    {
        printf(_CLEARSCREEN);
        printf("Bedankt voor het spelen. Tot ziens! Groet Ferry.\n");
        system("read -n 1 -s -p \"Druk op een toets om te sluiten...\"");
        printf(_CLEARSCREEN);
        exit(0);
    }
    else
        printf("Zelfde spelers? J/N: ");
    scanf(" %c", &yn);
    yn = input_yesno_errorcheck(yn, 2);
        printf(_CLEARSCREEN);
    if (yn == 'j' || yn == 'J')
        game_nl(input, playerX, playerO);
    else
    {
        player_select(playerX, playerO, 2);
        game_nl(input, playerX, playerO);
    }
}