/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:22:48 by tpoho             #+#    #+#             */
/*   Updated: 2022/07/20 20:50:28 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	str_copy(char **dest, char *source, int *total, int *current_size)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (source[i] != '\0')
	{
		if (*total >= *current_size - 1)
		{
			*current_size = (*current_size - 1) * 2 + 1;
			new = (char *)malloc(sizeof(char) * (*current_size));
			while (j < *total)
			{
				new[j] = (*dest)[j];
				j++;
			}
			free(*dest);
			*dest = new;
		}
		(*dest)[*total] = source[i];
		i++;
		(*total)++;
	}
}

char	*input_reader(int fd)
{
	char	*temp;
	char	buffer[BUF_SIZE + 1];
	int		ret;
	int		total;
	int		current_size;

	total = 0;
	current_size = BUF_SIZE * 2 + 1;
	ret = read(fd, buffer, BUF_SIZE);
	if (ret == 0)
	{
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (BUF_SIZE * 2) + 1);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		str_copy(&temp, buffer, &total, &current_size);
		ret = read(fd, buffer, BUF_SIZE);
	}
	temp[total] = '\0';
	return (temp);
}
