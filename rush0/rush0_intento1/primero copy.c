/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:00:08 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/05 11:14:49 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void				ft_putchar(char);
void 				rush02(int,int);
void 				primeraLinea(int, int,int);
void                ultimaLinea(int, int, int);
void                mitadLinea(int,int,int);

int					main(void)
{
	rush02(5,4);
	return 0;
}

void 				rush02(int x, int y)
{
	int i,j;
    
	i=0;
	j=0;
	while(j++<=y)
	{
		while(i++<=x)
		{
			if(j==1)
			{
				primeraLinea(i,j,x);
			}
            if(j==y && j!=1)
            {
                ultimaLinea(i,j,x);
            }
            if(j>1 && j<y)
            {
                mitadLinea(i,j,x);
            }
		}
        i=0;
	}
}

void 			primeraLinea(int i, int j,int x)
{
	if(i==1 || i==x)
	{
		ft_putchar('A');
		if(i==x)
		{
			ft_putchar('\n');
		}
	}
	if (i>1 && i<x)
	{
		ft_putchar('B');
	}

}

void            ultimaLinea(int i, int j, int x)
{
    if(i==1 || i==x)
    {
        ft_putchar('C');
        if(i==x)
        {
            ft_putchar('\n');
        }
    }
    if(i>1 && i<x)
    {
        ft_putchar('B');
    }
}

void            mitadLinea(int i, int j, int x)
{
    if(i==1 || i==x)
    {
        ft_putchar('B');
        if(i==x)
        {
            ft_putchar('\n');
        }
    }
    if(i>1 && i<x)
    {
        ft_putchar(' ');
    }
}


void ft_putchar(char c)
{
	write(1,&c,1);
}
