/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:51:37 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/19 15:28:20 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# define BUF_SIZE 4096

typedef struct s_map
{
	int		valid;
	long	row;
	long	col;
	char	legend[3];
	char	**map;
}			t_map;

typedef struct s_sofar
{
	long	diagonal;
	long	upl_x;
	long	upl_y;
}			t_sofar;

int		ft_atoi(char *str);
t_map	map_fr_file(char *fname);
char	*input_reader(int fd);
void	get_cols(t_map *map, char *input);
void	get_rows_legend(t_map *map, char *input);
void	empty_map_maker(t_map *map);
void	map_fill(t_map *map, char *input);
void	set_default_map_struct(t_map *map);
t_map	map_fr_si(void);
void	set_t_sofar(t_sofar *the_best, long diagonal, long x, long y);
t_sofar	solve_map(t_map *map);
void	print_solved_grid(t_map *map, t_sofar the_best);
void	free_map_array(t_map *map);
void	solve_from_file(char *fname);
void	solve_from_si(void);

#endif
