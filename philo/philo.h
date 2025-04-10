// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   philo.h                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/01 00:56:42 by faoriol           #+#    #+#             */
// /*   Updated: 2025/02/01 00:56:42 by faoriol          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_infos
{
	int	nb_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
}				t_infos;

typedef enum	e_status
{
	EATING,
	THINKING,
	SLEEPING,
	TAKING,
	DYING
}			t_status;

typedef struct	s_thread
{
	t_status	state;
	pthread_t	philo;
}				t_thread;

long	ft_atol(const char *str);

#endif
