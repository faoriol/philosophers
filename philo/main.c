/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:03:55 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/10 23:03:55 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detach_thread(t_thread *thread)
{
	int	index;

	index = 0;
	while (index < thread->infos->nb_philos)
	{
		pthread_mutex_destroy(&thread->infos->forks[index]);
		index++;
	}
	index = 0;
	while (index < thread->infos->nb_philos)
	{
		if (pthread_detach(thread[index].philo) != 0)
			printf("bug\n");
		index++;
	}
}

void	start_thread(t_thread *thread)
{
	int	index;

	index = 0;
	while (index < thread->infos->nb_philos)
	{
		if (pthread_create(&thread[index].philo, NULL, &routine, &thread[index]) != 0)
			clean_exit(thread->infos->forks, thread, "error: pthread_create failed");
		index++;
	}
	index = 0;
	while (index < thread->infos->nb_philos)
	{
		if (pthread_join(thread[index].philo, NULL) != 0)
			clean_exit(thread->infos->forks, thread, "error: pthread_create failed");
		index++;
	}
}

int	main(int argc, char **argv)
{
	t_thread	*thread;
	t_infos		*infos;

	infos = malloc(sizeof(t_infos));
	if(!infos)
		exit(EXIT_FAILURE);
	memset(infos, 0, sizeof(t_infos));
	collect_infos(argc, argv, infos);
	thread = malloc(sizeof(t_thread) * infos->nb_philos);
	if (!thread)
		clean_exit(infos, NULL, NULL);
	init_mutex(infos);
	init_thread(thread, infos);
	start_thread(thread);
	// detach_thread(thread);
	free(infos->forks);
	free(infos->dead);
	free(infos);
	free(thread);
	return (EXIT_SUCCESS);
}
