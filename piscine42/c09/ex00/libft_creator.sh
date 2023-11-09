# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 19:26:07 by asalo             #+#    #+#              #
#    Updated: 2023/08/30 10:01:38 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
cc -Wall -Wextra -Werror -c ft_putchar.c  ft_putstr.c  ft_strcmp.c  ft_strlen.c  ft_swap.c
ar rc libft.a ft_putchar.o  ft_putstr.o  ft_strcmp.o  ft_strlen.o  ft_swap.o
ranlib libft.a
