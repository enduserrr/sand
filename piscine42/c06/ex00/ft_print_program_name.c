/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:22:10 by asalo             #+#    #+#             */
/*   Updated: 2023/08/26 12:00:55 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)

{	
	int	i;

	(void)argc;
	i = 0;
	while (argv[0][i])
	{
		ft_putchar(argv[0][i]);
		++i;
	}
	ft_putchar('\n');
}
