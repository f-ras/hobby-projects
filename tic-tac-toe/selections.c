// Project by: Ferry Ras. Git: ferryrs.
// Boter Kaas en Eieren || Tic Tac Toe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	player_select(char *player1, char *player2, int language);
void	continue_or_not_eng(int input[], char *playerX, char *playerO);
void	continue_or_not_nl(int input[], char *playerX, char *playerO);
void	input_yesno_errorcheck(char instr, int language);
void	game_eng(int input[], char *playerX, char *playerO);
void	game_nl(int input[], char *playerX, char *playerO);

int	language_select(int argc, char *argv)
{
	if (argc == 2 && strcasecmp (argv, "eng") == 0)
	{	
		system("clear");
		printf("This is Tic-tac-toe.\n\n");
		return (1);
	}
	else if (argc == 2 && strcasecmp(argv, "nl") == 0)
	{
		system("clear");;
		printf("Dit is boter kaas en eieren.\n\n");
		return (2);
	}
	else if (argc != 2)
	{
		printf("Add one argument to select language.\n");
		printf("Voeg één arument toe om taal te selecteren.\nNL / ENG?\n");
		exit(0);
	}
	else
	{
		printf("Incorrect input - Onjuist invoer.\n");
		printf("Select Language - Selecteer Taal.\nNL / ENG?\n");
		exit(0);
	}
}

void	player_select(char *playerX, char *playerO, int language)
{
	if (language == 1)
	{
		printf("Enter name player 1 (X): ");
		scanf("%s", playerX);
		printf("Enter name player 2 (O): ");
		scanf("%s", playerO);
		system("clear");
		printf("Welcome %s and %s. Have fun! And don't get beated.\n\n",
			playerX, playerO);
	}
	if (language == 2)
	{
		printf("Voer naam in speler 1 (X): ");
		scanf("%s", playerX);
		printf("Voer naam in speler 2 (O): ");
		scanf("%s", playerO);
		system("clear");
		printf("Welkom %s en %s. ", playerX, playerO);
		printf("Veel plezier! En laat je niet kapot maken.\n\n");
	}
}

void	continue_or_not_eng(int input[], char *playerX, char *playerO)
{
	char	yn;

	printf("New game? Y/N: ");
	scanf(" %c", &yn);
	input_yesno_errorcheck(yn, 1);
	if (yn == 'n' || yn == 'N')
	{	
		printf("Thanks for playing. See you! Cheers Ferry.\n");
		exit(0);
	}
	else
		printf("Same players? Y/N: ");
	scanf(" %c", &yn);
	input_yesno_errorcheck(yn, 1);
		system("clear");
	if	(yn == 'y' || yn == 'Y')
		game_nl(input, playerX, playerO);
	else
	{
		player_select(playerX, playerO, 1);
		game_eng(input, playerX, playerO);
	}
}

void	continue_or_not_nl(int input[], char *playerX, char *playerO)
{
	char	yn;

	printf("Nieuw spel? J/N: ");
	scanf(" %c", &yn);
	input_yesno_errorcheck(yn, 2);
	if (yn == 'n' || yn == 'N')
	{	
		printf("Bedankt voor het spelen. Tot ziens! Groet Ferry.\n");
		exit(0);
	}
	else
		printf("Zelfde spelers? J/N: ");
	scanf(" %c", &yn);
	input_yesno_errorcheck(yn, 2);
		system("clear");
	if	(yn == 'j' || yn == 'J')
		game_nl(input, playerX, playerO);
	else
	{
		player_select(playerX, playerO, 2);
		game_nl(input, playerX, playerO);
	}
}