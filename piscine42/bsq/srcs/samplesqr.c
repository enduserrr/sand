
#include "ft.h"

int minimum(int a, int b, int c)
{
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}

void print_max_square_size(int **max)
{
	int	R, C;
	int i, j;
	int **S;
	int max_of_s, max_i, max_j;

	for (i = 0; i < R; i++)
		S[i][0] = max[i][0];

	for (j = 0; j < C; j++)
		S[0][j] = max[0][j];

	for (i = 1; i < R; i++) {
		for (j = 1; j < C; j++)
		{
			if (max[i][j] == 1)
				S[i][j] = minimum(S[i][j - 1], S[i - 1][j],
							S[i - 1][j - 1])
						+ 1;
			else
				S[i][j] = 0;
		}
	}

	max_of_s = S[0][0];
	max_i = 0;
	max_j = 0;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (max_of_s < S[i][j]) 
			{
				max_of_s = S[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	ft_putstr("Maximum square size is: \n");
	for (i = max_i; i > max_i - max_of_s; i--) 
	{
		for (j = max_j; j > max_j - max_of_s; j--) 
		{
			ft_putnbr(max[i][j]);
		}
		ft_putchar('\n');
	}
}

