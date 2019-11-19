/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:25:21 by bmoran-f          #+#    #+#             */
/*   Updated: 2019/10/13 19:33:33 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
bool ft_check_iguality( int  matrix[][])
{
    int i;
    int j;
    bool checking=true;
    
    i=0;
    j=0;
    while(i<=3)
    {
    	if(matrix[i][0] == matrix[i][1] || matrix[i][0]==matrix[i][2] || matrix[i][0]==matrix[i][3] || matrix[i][1]==matrix[i][2] ||  matrix[i][1]==matrix[i][3] || matrix[i][2]==matrix[i][3])
		{
			checking=false;
			return(checking);
		} //comprueba que no se repita ningun elemnto de cada fila
		i++;
	}

	while(j<=3)
	{
		if(matrix[0][j]==matrix[1][j] || matrix[0][j]==matrix[2][j] || matrix[0][j]==matrix[3][j] || matrix[1][j]==matrix[2][j] || matrix[1][j]==matrix[3][j] || matrix[2][j]==matrix[3][j])
		{
			checking=false;
			return(checking);
		} //comprueba que no haya elementos repetidos en las columnas.
		j++;
	}
    return(checking);
}*/


int ft_count_posibilities(int *array1, int *array2, int i)
{
	int conta;

	conta=0; 
	if(array1[i]==1 && array2[i]==2)  
		conta=2;
	if(array1[i]==1 && array2[i]==3)
		conta=3;
	if(array1[i]==1 && array2[i]==4)
		conta=1;
	if(array1[i]==2 && array2[i]==1)
		conta=2;
	if(array1[i]==2 && array2[i]==2)  
		conta=6;
	if(array1[i]==2 && array2[i]==3)  
		conta=3;
	if(array1[i]==3 && array2[i]==1)
		conta=3;
	if(array1[i]==3 && array2[i]==2)
		conta=3;
	if(array1[i]==4 && array2[i]==1)
		conta=1;
	return(conta);

}

int ft_check_vis_for_rc(int **matrix,char *option, int i, int a) 
	// a=0 para filas a=1 para columnas
{
	int j;
	int checking;

	checking=1;
	j=0;
	if(a==0)
	{
		while(j<=3)
		{
			if(matrix[j][i]!=option[j])
				checking=0;
			j++;
		}
	}
	else
	{
		while(j<=3)
		{
			if(matrix[i][j]!=option[j])
				checking=0;
			j++;
		}
	}	
	return(checking);
}

int	ft_check_visibility_row(int **matrix, int *rowleft, int *rowright)
{
	int		checking;
	int		i;
	char	*option;
	int		conta;
	int		j;

	option = malloc(5);
	checking = 1;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		conta = ft_count_posibilities(rowleft, rowright, i);
		while (j < conta)
		{
			*option = get_library(rowleft[i], rowright[i], j);
			checking = ft_check_vis_for_rc(matrix, option, i, 0);
			j++;
			free(option);
			if (checking == 0)
				return (checking);
		}
	}
	return (checking);
}

int	ft_check_visibility_col(int **matrix, int *colup, int *coldown)
{
	int		checking;
	int		i;
	char	*option;
	int		conta;
	int		j;

	option=malloc(5);
	checking = 1;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		conta = ft_count_posibilities(colup, coldown, i);
		while (j < conta)
		{
			*option = get_library(colup[i], coldown[i], j);
			checking = ft_check_vis_for_rc(matrix, option, i, 1);
			j++;
			if (checking == 0)
				return (checking);
		}
	}
	return (checking);
}
