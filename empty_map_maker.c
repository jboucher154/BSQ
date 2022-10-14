/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_map_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:20:06 by tpoho             #+#    #+#             */
/*   Updated: 2022/07/20 19:20:14 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	empty_map_maker(t_map *map)
{
	char	**empty_map;
	int		i;

	i = 0;
	empty_map = (char **)malloc(sizeof(char *) * map->row);
	if (empty_map)
	{
		while (i < map->row)
		{
			empty_map[i] = (char *)malloc((sizeof(char) * map->col) + 1);
			if (empty_map[i])
				i++;
		}
		map->map = empty_map;
	}
}
