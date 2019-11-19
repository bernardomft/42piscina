/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaballe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:02:35 by jcaballe          #+#    #+#             */
/*   Updated: 2019/10/20 14:30:45 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_search_key(char *buf, char *to_find);
void	ft_print_value(char *str);
void	ft_putstr(char *str);
void	ft_print_3_blocks(char *srt, char *buf, int pos, int length_block);

int		l_first_block(char *str)
{
	if (ft_strlen(str) % 3 == 0)
		return (3);
	return (ft_strlen(str) % 3); 
}

void	ft_zeros(int pos, char *buf, char *str)
{
	int i;
	char *zeros;
	
	zeros = malloc((ft_strlen(str) - pos) * sizeof(char));
	i = 0;
	while (str[pos])
	{
		if (i == 0)
			zeros[i] = '1';
		else
			zeros[i] = '0';
		pos++;
		i++;
	}
	zeros[i] = '\0';
	if (ft_search_key(buf, zeros) != NULL)
	{
		write(1, " ", 1);
		ft_print_value(ft_search_key(buf, zeros));
	}
}

void	ft_blocks(char *str, char *buf)
{
	int i;
	int j;
	int length;

	i = 0;
	length = ft_strlen(str);
	while (i < l_first_block(str))
	{
//		write(1, &str[i], 1); //
//		ft_putstr("str to ft_print_3_blocks =  ");
//		ft_putstr(str);
//		printf("l_first_block = %d", l_first_block(str));
//		write(1, "\n", 1);
//		ft_print_3_blocks(str, buf, i, l_first_block(str));
//		ft_zeros(i, buf, str);
		i++;
	}
	if (i > 0)
	{
		ft_print_3_blocks(str, buf, i - 1, l_first_block(str));
		ft_zeros(i - 1, buf, str);
		write(1, "\n", 1);
	}
	while (i < length)
	{
		j = 0;
//		ft_zeros(i, buf, str);
		while (j < 3)
		{
			write(1, &str[i], 1); //
			j++;
			i++;
		}
		if (length - i > 2)
			ft_zeros(i - 1, buf, str);
		write(1, "\n", 1);
	}
}
