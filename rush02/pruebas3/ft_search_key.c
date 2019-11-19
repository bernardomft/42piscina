/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaballe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:09:00 by jcaballe          #+#    #+#             */
/*   Updated: 2019/10/20 09:32:25 by jcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_key(int n, char *str, char *to_find)
{
	int j;

	j = 0;
	while (to_find[j])
	{
		if (str[n] == to_find[j])
		{
			j++;
			n++;
		}
		else
			return (0);
	}
	if (str[n] == ':')
		return (1);
	return (0);
}

char	*ft_search_key(char *buf, char *to_find)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == to_find[0])
		{
			if (check_key(i, buf, to_find))
				return (buf + i);
		}
		i++;
	}
	return (NULL);
}
