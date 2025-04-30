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
	if (!infos)
		return (EXIT_FAILURE);
	memset(infos, 0, sizeof(t_infos));
	if (!collect_infos(argc, argv, infos))
		return (false);
	thread = malloc(sizeof(t_thread) * ft_atol(argv[1]));
	if (!thread)
		return (free_all(NULL, infos, forks, EXIT_FAILURE));
	memset(thread, 0, sizeof(t_thread));
	if (init_mutex(infos, &forks) == false)
		return (free_all(thread, infos, forks, EXIT_FAILURE));
	init_thread(thread, infos, forks, argv);
	if (!start_thread(thread))
		return (free_all(thread, infos, forks, EXIT_FAILURE));
	free_all(thread, infos, forks, 0);
	return (EXIT_SUCCESS);
}
