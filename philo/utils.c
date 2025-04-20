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

// void	clean_thread(t_thread *thread)
// {
// 	free(thread->infos->forks);
// 	free(thread->infos->stop_mutex);
// 	free(thread->infos->meal_mutex);
// 	free(thread->infos);
// 	free(thread);
// }

void	mutex_print(t_thread *thread, char *msg, int last_meal)
{
	pthread_mutex_lock(thread->infos->print_mutex);
	printf("%d %d %s\n", get_time() - last_meal, thread->nb, msg);
	pthread_mutex_unlock(thread->infos->print_mutex);
}

void	ft_usleep(t_thread *thread, long time_to)
{
	int	time;

	time = get_time();
	while ((get_time() - time) < (time_to / 1000))
	{
		if (!simulation_check(thread))
			return ;
		else
			usleep(10);
	}
}

void	*safe_alloc(size_t size, bool *check)
{
	void	*data;

	data = malloc(size);
	if (!data)
	{
		(*check) = false;
		return (NULL);
	}
	return (data);
}
