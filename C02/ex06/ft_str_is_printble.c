/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:26:07 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/15 13:38:45 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_printable(char *str)
{
	int		i;
	int		printable;

	i = 0;
	printable = 1;
	if (str[0] == '\0')
		return (printable);
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			printable = 0;
		i++;
	}
	return (printable);
}
