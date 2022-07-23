// Project by: Ferry Ras. Git: ferryrs.
// Boter Kaas en Eieren || Tic Tac Toe

#include <stdio.h>

int		checkwon(int input[])
{
	if((input[0] == 1 && input [1] == 1 && input[2] == 1)
	|| (input[3] == 1 && input [4] == 1 && input[5] == 1)
	|| (input[6] == 1 && input [7] == 1 && input[8] == 1)
	|| (input[0] == 1 && input [3] == 1 && input[6] == 1)
	|| (input[1] == 1 && input [4] == 1 && input[7] == 1)
	|| (input[2] == 1 && input [5] == 1 && input[8] == 1)
	|| (input[0] == 1 && input [4] == 1 && input[8] == 1)
	|| (input[2] == 1 && input [4] == 1 && input[6] == 1))
		return(1);
	if((input[0] == 2 && input [1] == 2 && input[2] == 2)
	|| (input[3] == 2 && input [4] == 2 && input[5] == 2)
	|| (input[6] == 2 && input [7] == 2 && input[8] == 2)
	|| (input[0] == 2 && input [3] == 2 && input[6] == 2)
	|| (input[1] == 2 && input [4] == 2 && input[7] == 2)
	|| (input[2] == 2 && input [5] == 2 && input[8] == 2)
	|| (input[0] == 2 && input [4] == 2 && input[8] == 2)
	|| (input[2] == 2 && input [4] == 2 && input[6] == 2))
		return(2);
	return(0);
}

int		taken_or_outof_scope(int input[], int pos, int language, int ret)
{
	if (language == 1)
	{
		while(input[pos - 1] != 0 || !(pos >= 1 && pos <= 9) || ret == 0)
		{
			while(!(pos >= 1 && pos <= 9) || ret == 0)
			{
				printf("Stop! Choose a correct number (1 - 9): ");
				fflush(stdin);
				ret = scanf(" %d", &pos);
			}
			while(input[pos - 1] != 0 && ret != 0)
			{
				printf("Position taken. Choose again: ");
				ret = scanf(" %d", &pos);
			}
		}
	}
	if (language == 2)
	{
		while(input[pos - 1] != 0 || !(pos >= 1 && pos <= 9) || ret == 0)
		{
			while(!(pos >= 1 && pos <= 9) || ret == 0)
			{
				printf("Stop! Kies een juist getal (1 - 9): ");
				fflush(stdin);
				ret = scanf(" %d", &pos);
			}
			while(input[pos - 1] != 0 && ret != 0)
			{
				printf("Positie bezet. Kies opnieuw: ");
				ret = scanf(" %d", &pos);
			}
		}
	}
	return (pos);
}

void	input_yesno_errorcheck(char yn, int language)
{
	if(language == 1)
	{
		while (yn != 'y' && yn != 'Y' && yn != 'n' && yn  != 'N')
		{
			printf("Totally wrong input. Try again.\n Y/N: ");
			scanf(" %c", &yn);
		}
	}
	if(language == 2)
	{
		while (yn != 'j' && yn != 'J' && yn != 'n' && yn  != 'N')
		{
			printf("Hier klopt niks van. Probeer opnieuw.\n J/N: ");
			scanf(" %c", &yn);
		}
	}
}