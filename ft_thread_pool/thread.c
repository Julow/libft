/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 11:32:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/24 17:04:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_thread_pool.h"

static void		thread_pool_t_exec(t_thread_pool_shared *shared)
{
	t_task_f		task_f;
	uint8_t			task_data[shared->pool->task_manager->task_size];

	if (!shared->pool->task_manager->init_f(shared->pool->task_manager,
			&task_f, task_data))
	{
		shared->flags |= THREAD_POOL_F_ASLEEP;
	}
	else
	{
		shared->working_threads++;
		pthread_mutex_unlock(&shared->lock);
		task_f(task_data);
		pthread_mutex_lock(&shared->lock);
		shared->working_threads--;
		pthread_cond_signal(&shared->join_cond);
	}
}

void			thread_pool_t_work(t_thread_pool_shared *shared)
{
	if (shared->flags & THREAD_POOL_F_ASLEEP)
	{
		pthread_cond_wait(&shared->notify_cond, &shared->lock);
		if (shared->flags & (THREAD_POOL_F_ASLEEP | THREAD_POOL_F_DEAD))
			return ;
	}
	thread_pool_t_exec(shared);
}

void			*thread_pool_t_start(t_thread_pool_shared *shared)
{
	pthread_mutex_lock(&shared->lock);
	while (!(shared->flags & THREAD_POOL_F_DEAD))
		thread_pool_t_work(shared);
	pthread_mutex_unlock(&shared->lock);
	return (NULL);
}
