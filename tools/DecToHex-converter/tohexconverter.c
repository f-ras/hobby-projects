//                                                                            //
//                                                                  ___ __    //
//                                                                 (_  /__)   //
//                                                                 /  / (     //
//      (                                                                     //
//       )                                                                    //
//      (   ) (                                                               //
//     _______)_                             tohexconverter.c                 //
//  .-'---------|	By: Ferry Ras                                             //
// ( C|/\GitHub/|	                                                          //
//  '-./\f-ras\/|	E-mail:		ferryras@gmail.com                            //
//    '_________'	LinkedIn:	https://www.linkedin.com/in/ferryras/         //
//     '-------'                                                              //

#include <stdio.h>

#define ULLONG_MAX (__LONG_LONG_MAX__*2ULL+1ULL)

char	*hexconverter(char *dst, size_t dec)
{
	char	temp[19];
	int		i;
	int		j;
	int		remainder;

	i = 0;
	j = 0;
	if (dec == 0)
		temp[i++] = ('0');
	while (dec > 0)
	{
		remainder = dec % 16;
		if (remainder > 9 && remainder < 16)
			temp[i++] = ('a' + remainder % 10);
		else
			temp[i++] = ('0' + remainder);
		dec /= 16;
	}
	dst[j++] = '0';
	dst[j++] = 'x';
	while (i)
		dst[j++] = temp[i-- -1];
	dst[j] = '\0';
	return (dst);
}

int	main(void)
{	
	char	hex[19];

	for (int i = 0; i < 4096 + 1; i++)
	{
		printf("[%d] - [%s]\n", i, hexconverter(hex, i));
	}
	printf("...");
	printf("[%llu] - [%s]\n", ULLONG_MAX, hexconverter(hex, ULLONG_MAX));
//											 == MAX VALUE (18446744073709551615)
	return (0);
}
