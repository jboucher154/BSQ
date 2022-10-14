/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_structs_and_memory.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:28:53 by tpoho             #+#    #+#             */
/*   Updated: 2022/07/20 19:28:58 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	set_default_map_struct(t_map *map)
{
		map->valid = 0;
		map->row = 0;
		map->col = 0;
		map->map = NULL;
}

void	set_t_sofar(t_sofar *the_best, long diagonal, long x, long y)
{
	the_best->diagonal = diagonal;
	the_best->upl_x = x;
	the_best->upl_y = y;
}

void	free_map_array(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	if (map->map)
		free(map->map);
}
