/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:20:49 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/19 15:31:41 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	increment(int *i, long *col_check)
{
	(*i)++;
	(*col_check)++;
}

void	get_cols(t_map *map, char *input)
{
	int		i;
	long	col_check;
	long	row_check;

	i = 0;
	row_check = 0;
	while (input[i] != '\n')
		i++;
	i++;
	while (input[i] != '\0')
	{
		col_check = 0;
		while (input[i] != '\n' && input[i] != '\0')
			increment(&i, &col_check);
		i++;
		row_check++;
		if (map->col == 0)
			map->col = col_check;
		else if (col_check != map->col)
			map->valid = -1;
	}
	if (row_check != map->row || map->row == 0)
		map->valid = -1;
}

void	get_rows_legend(t_map *map, char *input)
{
	long	rows;
	int		i;

	i = 0;
	while (input[i] != '\n')
		i++;
	map->legend[2] = input[i - 1];
	map->legend[1] = input[i - 2];
	map->legend[0] = input[i - 3];
	input[i - 3] = '\0';
	rows = ft_atoi(input);
	map->row = rows;
}
