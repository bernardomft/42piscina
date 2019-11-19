/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:04:59 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/15 13:12:37 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_lowercase(char *str)
{
	int		i;
	int		lower;

	i = 0;
	lower = 1;
	if (str[0] == '\0')
		return (lower);
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
			lower = 0;
		i++;
	}
	return (lower);
}
