/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:41:46 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/05 12:56:15 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush02(int x, int y)
{
	int i;

	int j;
	
	i = 0;
	j = 0;
	while (j++ <= y)
	{
		while (i++ <= x)
		{
			if (j == 1)
			{
				primeraLinea(i, j, x);
			}
			if (j == y && j != 1)
			{
				ultimaLinea(i, j, x);
			}
			if (j > 1 && j < y)
			{
				mitadLinea(i, j, x);
			}
		}
		i=0;
	}
}

void             primeraLinea(int i, int j,int x)
{
    if(i==1 || i==x)
    {
        ft_putchar('A');
        if(i==x)
        {
            ft_putchar('\n');
        }
    }
    if (i>1 && i<x)
    {
        ft_putchar('B');
    }
    
}

void            ultimaLinea(int i, int j, int x)
{
    if(i==1 || i==x)
    {
        ft_putchar('C');
        if(i==x)
        {
            ft_putchar('\n');
        }
    }
    if(i>1 && i<x)
    {
        ft_putchar('B');
    }
}

