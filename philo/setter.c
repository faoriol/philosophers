/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol < faoriol@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:15:29 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/19 14:17:13 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_waiting_philo(t_thread *thread, int *value)
{
	pthread_mutex_lock(thread->infos.wait_mutex);
	thread->infos.waiting_philo = (*value);
	pthread_mutex_unlock(thread->infos.wait_mutex);
}
