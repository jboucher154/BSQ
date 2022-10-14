/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:18:58 by jebouche          #+#    #+#             */
/*   Updated: 2022/07/05 21:31:19 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_power(int start, char *str);
int	get_sum(char *str, int power, int s_index);

int	ft_atoi(char *str)
{
	int	i;
	int	power;
	int	sum;

	i = 0;
	if (!str[0] || str[0] > 57)
		return (0);
	while (str[i] <= 13 || str[i] == 43 || str[i] == 45 || str[i] == 32)
	{
		if (str[i] == 45 || str[i] == 43)
		{
			if (str[i + 1] < 48 || str[i + 1] > 57)
				return (0);
		}
		i++;
	}
	power = get_power(i, str);
	sum = get_sum(str, power, i);
	if (str[i - 1] == '-')
		return (sum * -1);
	else
		return (sum);
}

int	get_power(int s, char *str)
{
	int	power;

	power = 1;
	while ((str[s + 1] >= 48 && str[s + 1] <= 57))
	{
		power = power * 10;
		s++;
	}
	return (power);
}

int	get_sum(char *str, int pwr, int s_i)
{
	if (pwr == 1)
		return (str[s_i] - 48);
	return ((str[s_i] - 48) * pwr + get_sum(str, pwr / 10, s_i + 1));
}
