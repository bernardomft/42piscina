/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:36:13 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/17 12:34:39 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <unistd.h>
#include <stdio.h>

void				ft_dec_to_hex( char *str, int i)
{
	int decimal;
	int mod;
	char hex;

	decimal = str[i];
	hex = "\\0";
	write(1,&hex,1);
	while (decimal >  10)
	{
		mod = decimal % 16;
		decimal = decimal / 10;
		if (mod < 10)
			hex = mod + '0';
		else if (mod == 10)
			hex = 'a';
		else if (mod == 11)
			hex =  'b';
		else if (mod == 12)
			hex = 'c';
		else if (mod == 13)
			hex = 'd';
		else if (mod == 14)
			hex = 'e';
		else if (mod == 15)
			hex = 'f';
		write(1,&hex,1);
	}
}

void			ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_dec_to_hex(str, i);	
		}
		else 
		{
			write(1,&str[i],1);
		}
		i++;
	}
}

int main(void)
{
	char c[]="Buenas\n¿que tal estas?";
	int i = 0;
	char a = '\n';
	while(c[i]!= '\0')
	{
		write(1,&c[i],1);
		i++;
	}
	write(1,&a,1);
	ft_putstr_non_printable(c);
	return (0);

}


