/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 11:32:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/29 18:03:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_thread_pool.h"

void			ft_thread_pool_lock(t_thread_pool *p, bool lock)
{
	t_thread_pool_shared *const	shared = THREAD_POOL_SHARED(p);

	if (lock)
		pthread_mutex_lock(&shared->lock);
	else
		pthread_mutex_unlock(&shared->lock);
}

void			ft_thread_pool_notify(t_thread_pool *p)
{
	t_thread_pool_shared *const	shared = THREAD_POOL_SHARED(p);

	shared->flags &= ~THREAD_POOL_F_ASLEEP;
	pthread_cond_broadcast(&shared->notify_cond);
}

bool			ft_thread_pool_wait(t_thread_pool *p)
{
	t_thread_pool_shared *const	shared = THREAD_POOL_SHARED(p);

	if (shared->flags & (THREAD_POOL_F_ASLEEP | THREAD_POOL_F_DEAD)
		&& shared->working_threads == 0)
		return (false);
	pthread_cond_wait(&shared->join_cond, &shared->lock);
	return (true);
}

void			ft_thread_pool_join(t_thread_pool *p)
{
	t_thread_pool_shared *const	shared = THREAD_POOL_SHARED(p);

	while (!(shared->flags & (THREAD_POOL_F_ASLEEP | THREAD_POOL_F_DEAD)))
		thread_pool_t_work(shared);
	while (shared->working_threads > 0)
		pthread_cond_wait(&shared->join_cond, &shared->lock);
}
