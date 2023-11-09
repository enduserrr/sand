/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:58:50 by asalo             #+#    #+#             */
/*   Updated: 2023/08/20 17:58:56 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c);
void    ft_putnbr(int nb);
void    grid_display(int tab[4][4]);

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    unsigned int nbr;

    if (nb < 0)
    {
        ft_putchar('-');
        nbr = nb * -1;
    }
    else
        nbr = nb;
    if (nbr / 10 != 0)
        ft_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + 48);
}

void    grid_display(int grid[4][4])

{
    int row;
    int col;

    row = -1;
    while (++row < 4)
    {
        col = -1;
        while (++col < 4)
        {
            ft_putnbr(grid[row][col]);
            ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}

int main(void) 

{
    int grid[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };

    int value = 1;
    int row = 0;
    while (row < 4) 
    {
        int col = 0;
        while (col < 4) 
        {
            grid[row][col] = value;
            value++;
            col++;
            
        }
        row++;
    }    
}
