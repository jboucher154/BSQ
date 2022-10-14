/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_from_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:41:03 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/20 20:51:24 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_map	map_fr_file(char *fname)
{
	t_map	map;
	char	*input;
	int		fd;

	fd = (open(fname, O_RDONLY));
	set_default_map_struct(&map);
	if (fd == -1)
		write(2, "No such file or directory\n", 26);
	else
	{
		input = input_reader(fd);
		if (input != NULL)
		{
			get_rows_legend(&map, input);
			get_cols(&map, input);
			empty_map_maker(&map);
			map_fill(&map, input);
			if (close(fd) == -1)
				write(2, "File not closed\n", 16);
			free(input);
		}
		else
			map.valid = -1;
	}
	return (map);
}

void	solve_from_file(char *fname)
{
	t_map	map;
	t_sofar	the_best_solution;

	map = map_fr_file(fname);
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
