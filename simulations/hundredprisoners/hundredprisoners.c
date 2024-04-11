#include "hundpris.h"

int	main(int argc, char **argv)
{
	unsigned long	seed;
	uint8_t			boxes[100];
	int				run_times;
	int				won_times;
	int				operation;
	
	operation = pick_operation(argv[1]);
	if (argc != 3 || operation == -1)
		return (EXIT_FAILURE);
	run_times = atoi(argv[2]);
	seed = time(NULL);
	srandom(seed);
	won_times = start_program(operation, run_times, boxes);
	get_deepest_found(PRINT_IT);
	printf(_BLUE "[%s-mode] succeeded simulation %d times out of %d runs\n", \
		argv[1], won_times, run_times);
	printf("prisoners won %.3f times in total\n" _RESET, \
		(float)won_times/run_times);
	printf("seed: %ld\n", seed);
	return (EXIT_SUCCESS);
}

int		start_program(int operation_type, int run_times, uint8_t boxes[])
{
	int		won_times;

	won_times = 0;
	while (run_times--)
	{
		random_fill(boxes, 1024);
		check_array("box", boxes);
		won_times += pick_boxes(operation_type, boxes);
	}
	return (won_times);
}

int		pick_boxes(int operation_type, uint8_t boxes[])
{
	uint8_t			prisoner;
	
	prisoner = 1;
	while (prisoner <= 100)
	{
		if (operation_type == RANDOM)
			if (!random_pick(prisoner, boxes))
				return(result(prisoner, false));
		if (operation_type == SEQUENCED)
			if (!sequential_pick(prisoner, boxes))
				return(result(prisoner, false));
		get_deepest_found(prisoner);
		if (prisoner == 100)
			return(result(prisoner, true));
		prisoner++;
	}
	printf("\e[1;37m" "error: something unexpected happened\n");
	return (-1);
}


bool	random_pick(uint8_t prisoner, uint8_t boxes[])
{
	bool	found;
	uint8_t random_takes[100];
	uint8_t i;

	i = 0;
	found = false;
	random_fill(random_takes, 1024);
	while (i < 50 && !found)
	{
		found = status_output(i, prisoner, random_takes[i], boxes);
		if (found)
			return (true);
		i++;
	}
	return (false);
}


bool		sequential_pick(uint8_t prisoner, uint8_t boxes[])
{
	bool	found;
	uint8_t pick_number;
	uint8_t i;

	i = 0;
	found = false;
	pick_number = prisoner;
	while (i < 50 && !found)
	{
		found = status_output(i, prisoner, pick_number, boxes);
		if (found)
			return (true);
		pick_number = boxes[pick_number - 1];
		i++;
	}
	return (false);
}