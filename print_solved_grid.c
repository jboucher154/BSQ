/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solved_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:58:55 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/19 18:03:37 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	print_solved_grid(t_map *map, t_sofar best)
{
	long	row;
	long	col;
	char	c;

	row = 0;
	while (row < map->row)
	{
		col = 0;
		while (col < map->col)
		{
			c = map->map[row][col];
			if (row >= best.upl_y && row <= (best.upl_y + best.diagonal)
				&& col >= best.upl_x && col <= (best.upl_x + best.diagonal))
			{
				c = map->legend[2];
			}
			write(1, &c, 1);
			++col;
		}
		write(1, "\n", 1);
		++row;
	}
}
