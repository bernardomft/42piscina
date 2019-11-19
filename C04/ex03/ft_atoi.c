/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:43:05 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/24 18:41:49 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int		i;
	int		controller;
	int		number;

	controller = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			controller = controller * -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		number = number + (str[i] - '0');
		if (str[i + 1] > 47 && str[i + 1] < 58)
			number = number * 10;
		i++;
	}
	number = number * controller;
	return (number);
}
