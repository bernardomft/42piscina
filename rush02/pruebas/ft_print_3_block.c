/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:44:38 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/20 03:46:01 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int			print_value(char *);
char		*ft_search_key(char **str, char *to_find);

int			ft_char_to_int(char *str, int len, int pos)
{
	int		number;
	int		aux;
	if (len == 1)
	{
		aux = str[pos] - '0';
	}
	if (len == 2)
	{
		aux = (str[pos] - '0') * 10 + (str[pos + 1] - '0');
	}
	else if (len == 3)
	{
		aux = (str[pos] - '0') * 100 + (str[pos +1] - '0')*10 + (str[pos +2] - '0');
	}
	return aux; //esta función ya funciona correctamente.
}

void		ft_print_2_blocks(int number, char *buf)
{
	char	*printable;
	if (number < 10)
	{
		printable[0] = (number%10) + '0';
		print_value(ft_search_key(buf, &printable[0])); //l valor que le pasa es el adecuado
	}
	else if (number <= 20)
	{
		printable[0] = (number/10) + '0';
		printable[1] = (number%10) + '0';
		print_value(ft_search_key(buf, &printable[0]));
	}
	else if (number >20)
	{
		printable[0] = (number/10) + '0';
		printable[1] = '0';
		print_value(ft_search_key(buf, &printable[0]));  //el valor que le pasa es el adecuado
		printable[1] = (number%10) + '0';
		print_value(ft_search_key(buf, &printable[0])); //el valor que le pasa es el adecuado
	}
}

void		ft_print_3_blocks(char *str, char *buf, int pos, int len_block)
{
	int		num;
	int		aux;
	int		len;
	char	number_to_print;
	
	len = 3;
	if (len_block == 1)
		print_value(ft_search_key(buf,&str[pos])); //se le pasa el valor correcto
	if(len_block == 2)
	{
		num = ft_char_to_int(str, 2, pos);
		ft_print_2_blocks(num, buf); //se le pasa el valor correcto
	}
	else if(len_block == 3)
	{
		num = ft_char_to_int(str, len, pos);
		aux = num % (100); // numero de dos cifras a imprimir
		num = num / (100);  //numero de un digito a imprimmir
		number_to_print = num + '0'; // para que pase bien el char tiene que sumar el cero
		print_value(ft_search_key(buf,number_to_print)); //el valor de number to char es el adecuado
		ft_print_2_blocks(aux, buf); 	
	}
}


