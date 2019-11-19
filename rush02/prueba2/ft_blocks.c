/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaballe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:02:35 by jcaballe          #+#    #+#             */
/*   Updated: 2019/10/20 04:01:14 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *str);
int		ft_print_3_blocks(char *, char *, int , int );

/*int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}*/

int		l_first_block(char *str)
{
	if (ft_strlen(str) % 3 == 0)
		return (3);
	return (ft_strlen(str) % 3); 
}

void	ft_blocks(char *str, char *buf )
{
	int i;
	int j;
	int length;
	int length2;

	i = 0;
	length = ft_strlen(str);
	//printf("Total length: %d\n", length); //
	//printf("First block. Length: %d, Position: %d\n", l_first_block(str), i); //
	length2 = l_first_block(str);
	ft_print_3_blocks(str, buf, i, length2);
	while (i < l_first_block(str))
	{
		//write(1, &str[i], 1); //
		i++;
	}
	//write(1, "\n", 1); //
	while (i < length)
	{
		//printf("Next block. Length: 3, Position: %d\n", i); //
		j = 0;
		ft_print_3_blocks(str, buf, i, 3);
		while (j < 3)
		{
		//	write(1, &str[i], 1); //
			j++;
			i++;
		}
		//write(1, "\n", 1); //
	}
}
