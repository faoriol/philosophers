/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol < faoriol@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:25:40 by faoriol           #+#    #+#             */
/*   Updated: 2025/05/08 15:20:49 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_is_w_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	long	r;
	int		sign;

	sign = 1;
	r = 0;
	i = 0;
	while (ft_is_w_space(str[i]) == 0)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		r = r * 10 + str[i++] - 48;
	}
	if (((r * sign) > INT_MAX || (r * sign) < INT_MIN)
		&& ft_strlen(str) > 11)
		return (-1);
	return (r * sign);
}
