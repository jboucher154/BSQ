/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_from_si.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:25:45 by tpoho             #+#    #+#             */
/*   Updated: 2022/07/20 19:25:49 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_map	map_fr_si(void)
{
	t_map	map;
	char	*input;

	set_default_map_struct(&map);
	input = input_reader(0);
	if (input != NULL)
	{
		get_rows_legend(&map, input);
		get_cols(&map, input);
		empty_map_maker(&map);
		map_fill(&map, input);
		free(input);
	}
	else
		map.valid = -1;
	return (map);
}

void	solve_from_si(void)
{
	t_map	map;
	t_sofar	the_best_solution;

	map = map_fr_si();
	if (map.valid != -1)
	{
		the_best_solution = solve_map(&map);
		print_solved_grid(&map, the_best_solution);
	}
	else
	{
		write(1, "map error\n", 10);
	}
	free_map_array(&map);
}
