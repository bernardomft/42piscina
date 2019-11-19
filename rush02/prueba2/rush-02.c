/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaballe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:03:25 by jcaballe          #+#    #+#             */
/*   Updated: 2019/10/19 20:35:55 by jcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 4096

void	ft_putstr(char *str);
void	ft_putnbr(char nb);
void	*ft_search_key(char *str, char *to_find);
void	ft_print_3_blocks(char *str, char *buf, int pos, int len_block);
void	ft_blocks(char *str, char *buf);
int		ft_strlen(char *str);

void	print_value(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ')
		i++;
	i++;
	while (str[i] != '\n')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (argc == 2)
	{
		fd = open("numbers.dict", O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Error\n");
			return (1);
		}
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		ft_blocks(argv[1], buf);
//		print_value(ft_search_key(buf, argv[1]));
		if (close(fd) == -1)
		{
			ft_putstr("Error\n");
			return (1);
		}
	}
	return (0);
}
