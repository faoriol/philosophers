/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:48:39 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/10 22:48:39 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	clean_exit(void *data, void *data2, char *msg)
{
	if (data)
		free(data);
	if (data2)
		free(data2);
	if (msg)
		printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	clean_thread(t_thread *thread)
{
	free(thread->infos->forks);
	free(thread->infos->stop);
	free(thread->infos->meal_mutex);
	free(thread->infos);
	free(thread);
}
