//                                                                            //
//                                                                  ___ __    //
//                                                                 (_  /__)   //
//                                                                 /  / (     //
//      (                                                                     //
//       )                                                                    //
//      (   ) (                                                               //
//     _______)_                                   drawgame.c                 //
//  .-'---------|                                                             //
// ( C|/\GitHub/|                                                             //
//  '-./\f-ras\/|	E-mail:     ferryras@gmail.com                            //
//    '_________'	LinkedIn:   https://www.linkedin.com/in/ferryras/         //
//     '-------'                                                              //
// Project by: Ferry Ras. Git: f-ras                                          //
// Boter Kaas en Eieren || Tic Tac Toe                                        //

#include <stdio.h>

void    printinstructions(int input[]);

void    draw_game(int input[], char help)
{
    int	i;

    if (help == 'j' || help == 'J' || help == 'y' || help == 'Y')
        printinstructions(input);
    i = 0;
    while (i < 9)
    {
        if (input[i] == 0)
            printf("   ");
        if (input[i] == 1)
            printf(" ✗ ");
        if (input[i] == 2)
            printf(" ❍ ");
        if (i == 2 || i == 5 || i == 8)
            printf("\n");
        if (i == 2 || i == 5)
            printf("━━━╋━━━╋━━━\n");
        else if (i != 8)
            printf("┃");
        i++;
    }
    printf("\n");
}

void    printinstructions(int input[])
{
    int	i;

    i = 0;
    {
        printf("\n");
        while (i < 9)
        {
            if (input[i] == 0)
                printf(" %c ", i + 1 + '0');
            else
                printf("   ");
            if (i == 2 || i == 5 || i == 8)
                printf("\n");
            if (i == 2 || i == 5)
                printf("━━━╋━━━╋━━━\n");
            else if (i != 8)
                printf("┃");
            i++;
        }
        printf("\n");
    }
}