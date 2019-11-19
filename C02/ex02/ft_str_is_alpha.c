/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:02:55 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/17 18:15:56 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_alpha(char *str)
{
	int		i;
	int		alpha;
	char	a;

	i = 0;
	alpha = 1;
	if (str[0] == '\0')
		return (alpha);
	while (str[i] != '\0')
	{
		a = str[i];
		if (!(a >= 65 && a <= 90) && !(a >= 97 && a <= 122))
			alpha = 0;
		i++;
	}
	return (alpha);
}
