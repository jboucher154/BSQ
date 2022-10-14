/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:55:17 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/19 17:58:18 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

long	test_row_col(t_map *map, long row, long col, long *diagonal)
{
	long	temp_y;
	long	temp_x;

	temp_y = row + *diagonal;
	while (temp_y >= row)
	{
		if (map->map[temp_y][col + *diagonal] == map->legend[1])
		{
			*diagonal = (*diagonal - 1);
			return (-1);
		}
		--temp_y;
	}
	temp_x = col + *diagonal;
	while (temp_x >= col)
	{
		if (map->map[row + *diagonal][temp_x] == map->legend[1])
		{
			*diagonal = (*diagonal - 1);
			return (-1);
		}
		--temp_x;
	}
	return (0);
}

long	largest_square(t_map *map, long row, long col)
{
	long	diagonal;
	long	smaller;
	long	ret;

	smaller = map->row;
	if (map->col < map->row)
		smaller = map->col;
	diagonal = 1;
	while (diagonal < smaller)
	{
		if ((row + diagonal) < map->row
			&& (col + diagonal) < map->col)
		{
			ret = test_row_col(map, row, col, &diagonal);
			if (ret == -1)
				return (diagonal);
		}
		else
		{
			return (diagonal - 1);
		}
		++diagonal;
	}
	return (diagonal - 1);
}

t_sofar	solve_map(t_map *map)
{
	long	y;
	long	x;
	t_sofar	the_best;
	long	diagonal_temp;

	set_t_sofar(&the_best, -1, -1, -1);
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (map->map[y][x] == map->legend[0])
			{
				diagonal_temp = largest_square(map, y, x);
				if (diagonal_temp > the_best.diagonal)
				{
					set_t_sofar(&the_best, diagonal_temp, x, y);
				}
			}
			++x;
		}
		++y;
	}
	return (the_best);
}
