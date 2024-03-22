/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:51:33 by asalo             #+#    #+#             */
/*   Updated: 2024/03/22 17:53:53 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minitalk.h"

long	ft_atol(const char *str)
{
	long	n;
	int		is_neg;
	int		i;

	n = 0;
	is_neg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * is_neg);
}


void	str_to_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	if (!s)
		return ;
	c = '\0';
	while (s[i])
	{
		c = s[i];
		write(fd, &c, 1);
		i++;
	}
}

/**
 * 		write(2, "\033[91mError: incorrect format.\033[0m\n", 106);
		write(1, "\033[33mTry: ./client_bonus [PID] [MESSAGE]\033[0m\n", 49);
*/

void	error_exit(e_type type)
{
	if (type == CLEAN_EXIT)
		exit(0);
	if (type == CLIENT_INPUT)
	{
		str_to_fd("\033[91mError: incorrect format.\033[0m\n", 2);
		str_to_fd("Try: ./client <PID> <MESSAGE>\n", 1);
		str_to_fd("(if server isn't initialised, first run the following commnd:\n", 1);
		str_to_fd("-> ./server\n", 1);
		exit(1);
	}
	if (type == SERVER_INPUT)
	{
		str_to_fd("\033[91mError: incorrect format.\033[0m\n", 2);
		str_to_fd("Try: ./server", 1);
		exit (1);
	}

	if (type == SIZE)
	{
		str_to_fd("\033{91mError; incorrect argument size", 2);
		exit(1);
	}
}
