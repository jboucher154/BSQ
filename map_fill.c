/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:38:25 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/19 15:08:11 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	invalid_symbol(char to_check, char empty, char obstacle)
{
	if (to_check == empty || to_check == obstacle)
		return (0);
	return (1);
}

void	map_fill(t_map *map, char *input)
{
	long	i;
	long	j;
	long	h;

	i = 0;
	h = 0;
	while (input[h] != '\n')
		h++;
	h++;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (invalid_symbol(input[h], map->legend[0], map->legend[1]))
				map->valid = -1;
			map->map[i][j] = input[h];
			j++;
			h++;
		}
		h++;
		i++;
	}
}
