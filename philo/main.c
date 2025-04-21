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
		pthread_detach(thread[index++].philo);
}

bool	start_thread(t_thread *thread)
{
	int	index;

	index = 0;
	while (index < thread->nb_philos)
	{
		if (pthread_create(&thread[index].philo,
				NULL, &routine, &thread[index]) != 0)
			return (false);
		index++;
	}
	index = 0;
	set_waiting_philo(&thread[index]);
	while (index < thread->nb_philos)
	{
		if (pthread_join(thread[index].philo, NULL) != 0)
			return (false);
		index++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_thread	*thread;
	t_fork		*forks;
	t_infos		*infos;

	forks = NULL;
	infos = malloc(sizeof(t_infos));
	memset(infos, 0, sizeof(t_infos));
	if (!infos)
		exit(EXIT_FAILURE);
	collect_infos(argc, argv, infos);
	thread = malloc(sizeof(t_thread) * ft_atol(argv[1]));
	memset(thread, 0, sizeof(t_thread));
	if (!thread)
		return (free_all(NULL, infos, forks, EXIT_FAILURE));
	if (init_mutex(infos, &forks) == false)
		return (EXIT_FAILURE);
	init_thread(thread, infos, forks, argv);
	if (!start_thread(thread))
		return (free_all(thread, infos, forks, EXIT_FAILURE));
	free_all(thread, infos, forks, 0);
	return (EXIT_SUCCESS);
}
