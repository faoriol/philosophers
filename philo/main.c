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

int	main(int argc, char **argv)
{
	t_thread	*thread;
	t_infos		infos;

	collect_infos(argc, argv, &infos);
	thread = malloc(sizeof(t_thread) * infos.nb_philos);
	if (!thread)
		exit(EXIT_FAILURE);
	memset(thread, 0, sizeof(t_thread) * infos.nb_philos);
	thread->infos = &infos;
	init_mutex(thread);
	init_thread(thread);
	// detach_thread(thread);
	free(thread->infos->forks);
	free(thread);
	return (EXIT_SUCCESS);
}
