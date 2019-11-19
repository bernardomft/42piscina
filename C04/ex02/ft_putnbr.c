/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:27:16 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/08 11:58:30 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_insert_in_array(int size, int b, int nb)
{
	char	array[size];
	int		c;
	int		i;
	int		a;

	a = size;
	i = 0;
	c = nb;
	while (a >= 0)
	{
		array[a] = (b % 10) + '0';
		b = b / 10;
		a--;
	}
	while (i <= size)
	{
		if (nb < 0 && i == 0)
			ft_putchar('-');
		ft_putchar(array[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int size;
	int a;
	int b;

	size = 0;
	if (nb < 0)
	{
		a = nb * -1;
		b = nb * -1;
	}
	else
	{
		a = nb;
		b = nb;
	}
	while (a / 10 > 0)
	{
		size++;
		a = a / 10;
	}
	if (nb == 0)
		ft_putchar('0');
	else
		ft_insert_in_array(size, b, nb);
}
