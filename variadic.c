/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:12:50 by asalo             #+#    #+#             */
/*   Updated: 2023/12/16 13:18:46 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ('0' <= str[i]) && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

float average(int n, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, n);
	total = 0;
	i = 0;
	while ( i < n)
	{
		total = total + va_arg(ap, int);
		++i;
	}
	return ((float)total / n);
}

int main(int argc, char *argv[])
{
	int		sample_size;
	int		*ages;
	float	avg_age; /*float instead of int to enable printing fractional part of the devision too*/
	int 	i;

	i = 0;
	ages = NULL;
	if (argc < 2)
		return (0);
	sample_size = argc - 1;
	ages = (int *)malloc(sample_size * sizeof(int));
	if (!ages)
		return (0);
	while (i < sample_size)
	{
		ages[i] = ft_atoi(argv[i + 1]);
		++i;
	}
	avg_age = average(sample_size, ages[0], ages[1], ages[2]);
	printf("The average age of the sample set is: %.1f\n", avg_age);
	free(ages);
	return (0);
}
