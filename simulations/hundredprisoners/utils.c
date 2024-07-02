//                                                                            //
//                                                                  ___ __    //
//                                                                 (_  /__)   //
//                                                                 /  / (     //
//      (                                                                     //
//       )                                                                    //
//      (   ) (                                                               //
//     _______)_                                      utils.c                 //
//  .-'---------|	By: Ferry Ras                                             //
// ( C|/\GitHub/|                                                             //
//  '-./\f-ras\/|	E-mail:     ferryras@gmail.com                            //
//    '_________'	LinkedIn:   https://www.linkedin.com/in/ferryras/         //
//     '-------'                                                              //

#include "hundpris.h"

int		pick_operation(char *string)
{
	if (!strcmp(string, "random"))
		return (RANDOM);
	if (!strcmp(string, "sequenced"))
		return (SEQUENCED);
	printf("error: faulty input (choose random or sequenced)\n");
	return (-1);
	
}

void	counting_fill(uint8_t *array)
{
	uint8_t i;

	i = 0;
	while (i < 100)
	{
		array[i] = i + 1;
		i++;
	}
}

void	random_fill(uint8_t *boxes, size_t times)
{
	uint8_t random1;
	uint8_t random2;
	uint8_t temp;
	size_t 	i;

	i = 0;
	counting_fill(boxes);
	while (i < times)
	{
		random1 = random() % 100;
		random2 = random() % 100;
		temp = boxes[random1];
		boxes[random1] = boxes[random2];
		boxes[random2] = temp;
		i++;
	}
}

void	check_array(char *what, uint8_t check[])
{
	uint8_t i;
	
	i = 0;
	while (i < 100)
	{
		printf("check: %s [%d] = %d\n", what, i, check[i]);
		i++;
	}
}

bool	status_output(uint8_t count, uint8_t prisoner, uint8_t box_number, uint8_t boxes[])
{
	printf("[%d] prisoner %d takes box[%d] and finds number %d\n", count + 1, prisoner, box_number - 1, \
		boxes[box_number - 1]);
	if (boxes[box_number - 1] == prisoner)
	{
		printf(_WHITE "prisoner %d found his box, next prisoner turn\n" _RESET, prisoner);
		return (true);
	}
	return (false);
}

bool	result(uint8_t prisoner, bool status)
{
	if (status == true)
	{
		printf(_GREEN "all prisoners found thier box - prisoners saved\n" _RESET);
		return (true);
	}
	printf(_RED \
			"prisoner %d did not found his box - prisoners executed\n" \
			_RESET, prisoner);
	return (false);
}

void	get_deepest_found(int prisoner)
{
	static uint8_t	most_found;

	if (prisoner == PRINT_IT)
	{
		printf("\n--run completed: deepest found %d--\n\n", most_found);
		return ;
	}
	if (most_found < prisoner)
		most_found = prisoner;
}
