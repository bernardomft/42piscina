/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:44:38 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/20 17:54:55 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int			ft_print_value(char *);
char		*ft_search_key(char *, char *);
void		ft_putstr(char *);

int			ft_char_to_int(char *str, int len, int pos)
{
	int		number;
	int		aux;
	if (len == 1)
	{
		aux = str[pos] - '0';
	}
	else if (len == 2)
	{
		aux = (str[pos] - '0') * 10 + (str[pos + 1] - '0');
	}
	else if (len == 3)
	{
		aux = (str[pos] - '0') * 100 + (str[pos +1] - '0')*10 + (str[pos +2] - '0');
	}
	return aux; //esta función ya funciona correctamente.
}


void		ft_print_3_blocks(char *str, char *buf, int pos, int len_block)
{
	int		num;
	char	aux[2];
	int		len;
	char	number_to_print;
	char	printable[3];
	char	hundred[]="100";

	
	//printf("%s cadena a imprimir %d longuitud de la cadena", str, len_block);
	len = 3;
	if (len_block == 1)
	{
		if(ft_search_key(buf, str) != NULL)
			ft_print_value(ft_search_key(buf,str)); //el vaor de str[pos] es el adecuado
	}
	else if(len_block == 2)
	{
		num = ft_char_to_int(str,2 , 0); //el valor almacenado en num es el correcto
		if (num <= 20)
		{
			if(ft_search_key(buf, str) != NULL)
				ft_print_value(ft_search_key(buf,str));
		}
		else if(num > 20)
		{	if (str[1] == '0')
			{
				if(ft_search_key(buf, str) != NULL)
					ft_print_value(ft_search_key(buf,str));
			}
			else
			{
				number_to_print = str[1];
				str[1] = '0';
				if(ft_search_key(buf, str) != NULL)
					ft_print_value(ft_search_key(buf,str));
				str[0] = number_to_print;
				str[1] = '\0';
				write(1, " ",1);
				if(ft_search_key(buf, str) != NULL)
					ft_print_value(ft_search_key(buf,str));
			}
		}
	}
	else if(len_block == 3)
	{	num = ft_char_to_int (str,3,0);
		printable[0] = str[0];
		printable[1] = '\0';
		printable[2] = '\0';
		ft_print_value(ft_search_key(buf,printable));
		write(1, " ",1);
		ft_print_value(ft_search_key(buf,hundred));
		write(1, " ",1);
		printable[0] = str[1];
		printable[1] = str[2];
		printable[2] = '\0';
		num = num % 100;
		if (num <= 20)
		{	if (num < 10)
			{
				aux[0] = printable[1];
				aux[1]  = '\0';
				if(ft_search_key(buf, aux) != NULL)
					ft_print_value(ft_search_key(buf,aux));
			}
			if(ft_search_key(buf, printable) != NULL)
				ft_print_value(ft_search_key(buf,printable));
		}
		else if(num > 20)
		{	if (printable[1] == '0')
			{
				if(ft_search_key(buf, printable) != NULL)
					ft_print_value(ft_search_key(buf,printable));
			}
			else
			{
				number_to_print = printable[1];
				printable[1] = '0';
				if(ft_search_key(buf, printable) != NULL)
					ft_print_value(ft_search_key(buf,printable));
				printable[0] = number_to_print;
				printable[1] = '\0';
				write(1, " ",1);
				if(ft_search_key(buf, printable) != NULL)
					ft_print_value(ft_search_key(buf,printable));
			}
		}
	}
}
