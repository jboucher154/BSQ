/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:05:02 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/19 19:33:31 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			solve_from_file(argv[i]);
			if (argv[i + 1])
				write(1, "\n", 1);
			i++;
		}
	}
	else
	{
		solve_from_si();
	}
	return (0);
}
