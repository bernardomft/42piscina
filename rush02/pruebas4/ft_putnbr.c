/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaballe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:23:18 by jcaballe          #+#    #+#             */
/*   Updated: 2019/10/19 13:41:56 by jcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printnbr(char nb)
{
	write(1, &nb, 1);
}

void	putnbr(int nb)
{
	int		r;
	char	num[11];
	int		i;

	i = 0;
	while (nb != 0)
	{
		r = nb % 10;
		nb = nb / 10;
		num[i] = r + '0';
		i++;
	}
	while (i > 0)
	{
		ft_printnbr(num[i - 1]);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	unsigned char unb;

	unb = (unsigned char)(nb);
	if (unb == 0)
	{
		ft_printnbr('0');
	}
	else
	{
		putnbr(unb);
	}
	write(1, "\n", 1);
}
