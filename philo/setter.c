/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol < faoriol@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:15:29 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/29 18:29:10 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_waiting_philo(t_thread *thread)
{
	pthread_mutex_lock(&thread->infos->wait_mutex);
	thread->infos->waiting_philo = true;
	pthread_mutex_unlock(&thread->infos->wait_mutex);
}

void	set_dead_mutex(t_thread *thread)
{
	pthread_mutex_lock(&thread->infos->stop_mutex);
	thread->infos->philo_died = true;
	pthread_mutex_unlock(&thread->infos->stop_mutex);
}

void	add_table_meal(t_thread *thread)
{
	pthread_mutex_lock(&thread->infos->table_meal_mutex);
	thread->infos->full_meal++;
	pthread_mutex_unlock(&thread->infos->table_meal_mutex);
}
