/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:44:38 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/20 12:54:45 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//int			print_value(char *);
//char		*ft_search_key(char *, char *);

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
	char	printable2[2];
	char	number_to_print;
	if (number < 10)
	{
		printable2[0] = (number%10) + '0';
		printf("%c numero  menor que 10 pasado a char que va a imprimir\n", printable2[0]);
		//print_value(ft_search_key(buf,&printable2[0])); //el valor de printable[0] es el adecuado
	}
	else if (number <= 20)
	{
		printable2[0] = (number/10) + '0';
		printable2[1] = (number%10) + '0';
		printf("%c%c numero menor que 20 pasado a char para imprimir", printable2[0], printable2[1]); //el valor que le pasa es correcto

		//print_value(ft_search_key(buf, printable));
	}
	else if (number >20)
	{
		printable2[0] = (number/10) + '0';
		printable2[1] = '0';
		printf("%c%c numero mayor de 20 pasado a char para imprimir\n", printable2[0],printable2[1]);
		//print_value(ft_search_key(buf, printable2));  //el valor que le pasa es el adecuado
		number_to_print = (number%10) + '0';
		printf("%c ultimo numero a imprimir de la cadena de tres digitos\n",number_to_print);
		//print_value(ft_search_key(buf, number_to_print)); //el valor que le pasa es el adecuado
	}
}

void		ft_print_3_blocks(char *str, char *buf, int pos, int len_block)
{
	int		num;
	int		aux;
	int		len;
	char	number_to_print;
	char	printable[2];
	
	len = 3;
	if (len_block == 1)
		//print_value(ft_search_key(buf,&str[pos])); //el vaor de str[pos] es el adecuado
		printf("%c\n" ,str[pos]);
	if(len_block == 2)
	{
		num = ft_char_to_int(str, 2, pos); //el valor almacenado en num es el correcto
		printf("%d\n",num);
		ft_print_2_blocks(num, buf);
	}
	else if(len_block == 3)
	{
		num = ft_char_to_int(str, len, pos);
		printf("%d num \n ", num);
		aux = num % (100); // numero de dos cifras a imprimir
		printf("%d aux numero de dos cifras a imprimir\n", aux);
		num = num / (100);  //numero de un digito a imprimmir
		printf("%d num que se va aimprimir de un digito\n",num);
		number_to_print = num + '0'; // para que pase bien el char tiene que sumar el cero
		printf("%c number to print pasado a char\n", number_to_print);
		//print_value(ft_search_key(buf,number_to_print)); //el valor de number to char es el adecuado
			//printable[0] = (aux / 10) + '0';
			//printf("%c\n", printable[0]); //esta parte no ha falta, a ft_printf_2_blocs se le pasa el int aux
			//printable[1] = (aux % 10) + '0';
			//printf("%c\n", printable[1]);
	   		//printf("%c\n", printable[2]); 	
			//printf("%s\n", printable);
		ft_print_2_blocks(aux, buf); 	//el valor de aux es el adecuado
	}
}
/*
int main (void)
{
	char a[]="129";
	char *b;
	ft_print_3_blocks(a,b,0,3);
}
*/
