/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:44:38 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/20 17:25:29 by bmoran-f         ###   ########.fr       */
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
/*
void		ft_print_2_blocks(int number, char *buf)
{
	char	printable2[2];
	char	number_to_print;
	if (number < 10)
	{
		number_to_print = (number%10) + '0';
		//printf("%c numero  menor que 10 pasado a char que va a imprimir\n", printable2[0]);
		if (ft_search_key(buf, printable2) != NULL)
			ft_print_value(ft_search_key(buf,&number_to_print)); //el valor de printable[0] es el adecuado
	}
	else if (number <= 20 && number >= 10)
	{
		printable2[0] = (number/10) + '0';
		printable2[1] = (number%10) + '0';
		printf("%c%c numero menor que 20 pasado a char para imprimir\n", printable2[0], printable2[1]); //el valor que le pasa es correcto

		if (ft_search_key(buf, printable2) != NULL)
			ft_print_value(ft_search_key(buf, printable2));
		
	}
	else if (number >20)
	{
		printable2[0] = (number/10) + '0';
		printable2[1] = '0';
		//printf("%c%c numero mayor de 20 pasado a char para imprimir\n", printable2[0],printable2[1]);
		ft_print_value(ft_search_key(buf, printable2));  //el valor que le pasa es el adecuado
		number_to_print = (number%10) + '0';
		//printf("%c ultimo numero a imprimir de la cadena de tres digitos\n",number_to_print);
		ft_print_value(ft_search_key(buf, &number_to_print)); //el valor que le pasa es el adecuado
	}
}*/

void		ft_print_3_blocks(char *str, char *buf, int pos, int len_block)
{
	int		num;
	char	aux[2];
	int		len;
	char	number_to_print;
	char	printable[3];
	char	hundred[]="100";

	
	
	len = 3;
	if (len_block == 1)
	{
		//ft_putstr("str = ");
		//ft_putstr(str);
		//write(1, "\n", 1);
		if(ft_search_key(buf, str) != NULL)
			ft_print_value(ft_search_key(buf,str)); //el vaor de str[pos] es el adecuado
		//printf("%c\n" ,str[pos]);
	}
	else if(len_block == 2)
	{
		num = ft_char_to_int(str,22 , 0); //el valor almacenado en num es el correcto
		//printf("%d numero a imprimir de 2 cifras tipo int\n",num);
		//printf("%c%c numero de dos cifras a imprimir\n", str[0],str[1]);
		//ft_print_2_blocks(num, buf);
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
				//printf("%c mmumero de una cifra a imprimir\n", number_to_print);
				//printf("%c%c numero de dos cifras a imprimir", str[0], str[1]);
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
		//printf("pritable:  %s",printable);
		//num = ft_char_to_int(printable,3,0);
		//printf("num: %d", num);
		num = num % 100;
		if (num <= 20)
		{	if (num < 10)
			{
				aux[0] = printable[1];
				aux[1]  = '\0';
				//printf("%c", aux[0]);
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
				//printf("%c mmumero de una cifra a imprimir\n", number_to_print);
				//printf("%c%c numero de dos cifras a imprimir", str[0], str[1]);
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
