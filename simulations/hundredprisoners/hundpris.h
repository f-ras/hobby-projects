//                                                                            //
//                                                                  ___ __    //
//                                                                 (_  /__)   //
//                                                                 /  / (     //
//      (                                                                     //
//       )                                                                    //
//      (   ) (                                                               //
//     _______)_                                   hundpris.c                 //
//  .-'---------|	By: Ferry Ras                                             //
// ( C|/\GitHub/|                                                             //
//  '-./\f-ras\/|	E-mail:     ferryras@gmail.com                            //
//    '_________'	LinkedIn:   https://www.linkedin.com/in/ferryras/         //
//     '-------'                                                              //

#ifndef HUNDPRIS_H
# define HUNDPRIS_H

# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <string.h>

# define	_RED		"\e[1;31m"
# define	_GREEN		"\e[1;32m"
# define	_BLUE		"\e[1;34m"
# define	_WHITE		"\e[1;37m"
# define	_RESET		"\e[0m"
# define	RANDOM		1
# define	SEQUENCED	2
# define	PRINT_IT	-1


void	counting_fill(uint8_t *array);
void	random_fill(uint8_t *boxes, size_t times);
void	check_array(char *what, uint8_t check[]);
int		pick_operation(char *string);
int		start_program(int operation_type, int run_times, uint8_t boxes[]);
int		pick_boxes(int operation_type, uint8_t boxes[]);
bool	random_pick(uint8_t prisoner, uint8_t boxes[]);
bool	sequential_pick(uint8_t prisoner, uint8_t boxes[]);
bool	status_output(uint8_t count, uint8_t prisoner, uint8_t box_number, uint8_t boxes[]);
bool	result(uint8_t prisoner, bool status);
void	get_deepest_found(int prisoner);

#endif