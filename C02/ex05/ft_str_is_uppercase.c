/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:14:47 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/15 13:24:07 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_uppercase(char *str)
{
	int		i;
	int		upper;

	i = 0;
	upper = 1;
	if (str[0] == '\0')
		return (upper);
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
			upper = 0;
		i++;
	}
	return (upper);
}
