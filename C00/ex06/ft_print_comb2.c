/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:06:51 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/07 13:18:42 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_check_comb2(char a, char b, char c, char d)
{
	if (d <= a && c < b)
	{
		ft_putchar(d);
		ft_putchar(c);
		ft_putchar(' ');
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_loop(char a, char b, char c, char d)
{
	while (b <= '9')
	{
		ft_check_comb2(a, b, c, d);
		b++;
	}
}

void	ft_print_comb2(void)
{
	char a;
	char b;
	char c;
	char d;

	a = '0';
	b = '0';
	c = '0';
	d = '0';
	while (d <= '9')
	{
		while (c <= '9')
		{
			while (a <= '9')
			{
				ft_loop(a, b, c, d);
				b = '0';
				a++;
			}
			a = '0';
			c++;
		}
		c = '0';
		d++;
	}
}
