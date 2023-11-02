/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:33:45 by asalo             #+#    #+#             */
/*   Updated: 2023/11/01 15:44:20 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}