/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:42:29 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/16 12:50:11 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*ft_strcapitalize(char *str)
{
	int i;
	int is_lower;

	is_lower = 0;
	i = 0;
	if (str[0] > 96 && str[0] < 123)
		str[i] = str[i] - 32;
	while (str[i] != '\0')
	{
		if (str[i] > 96 && str[i] < 123)
			is_lower = 1;
		else
			is_lower = 0;
		if ((is_lower == 1) && (str[i - 1] > 31 && str[i - 1] < 48))
			str[i] = str[i] - 32;
		if ((is_lower == 1) && (str[i - 1] > 57 && str[i - 1] < 65))
			str[i] = str[i] - 32;
		if ((is_lower == 1) && (str[i - 1] > 90 && str[i - 1] < 97))
			str[i] = str[i] - 32;
		if ((is_lower == 1) && (str[i - 1] > 122 && str[i - 1] <= 126))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
