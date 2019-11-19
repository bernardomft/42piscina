/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:15:41 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/13 17:42:00 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**create_frame(char *string_arg);

int	main(int argc, char **argv)
{
	char	**frame;
	(void)argc;
	(void)argv;
	frame = create_frame(argv[1]);
}


void	bucl(char **frame, char *string_arg)
{
	int 	position;
	int 	count;
	int		var;
	
	position = 0;
	count = 0;
	var = 0;
	while (*string_arg)
	{
		if (position  % 2 == 0)
		{
			frame[count][var] = *string_arg;
			var++;
		}
		if (var == 4)
			var = 0;
		count++;
		string_arg++;
		position++;
	}
}

char	**create_frame(char *string_arg)
{
	char	**frame = malloc(20);

	frame[0] = malloc(5);
	frame[1] = malloc(5);
	frame[2] = malloc(5);
	frame[3] = malloc(5);
	bucl(frame,  string_arg);
	return(frame);
}
