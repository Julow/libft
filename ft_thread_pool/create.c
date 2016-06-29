/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 18:02:53 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/29 18:03:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_thread_pool.h"
#include <stdlib.h>

t_thread_pool	*ft_thread_pool_create(uint32_t thread_count)
{
	t_thread_pool			*p;
	t_thread_pool_shared	*shared;
	pthread_t				*threads;
	uint32_t				i;

	p = MALLOC(sizeof(t_thread_pool) + sizeof(t_thread_pool_shared)
			+ S(pthread_t, thread_count));
	*p = (t_thread_pool){NULL, thread_count};
	shared = THREAD_POOL_SHARED(p);
	*shared = (t_thread_pool_shared){p, PTHREAD_MUTEX_INITIALIZER,
			PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, 0,
			THREAD_POOL_F_ASLEEP};
	pthread_mutex_lock(&shared->lock);
	threads = THREAD_POOL_THREADS(p);
	i = 0;
	while (i < p->thread_count)
		if (pthread_create(&threads[i], NULL,
				V(&thread_pool_t_start), shared) != 0)
			p->thread_count--;
		else
			i++;
	if (p->thread_count > 0)
		return (p);
	ft_thread_pool_destroy(p);
	return (NULL);
}

void			ft_thread_pool_destroy(t_thread_pool *p)
{
	pthread_t *const			threads = THREAD_POOL_THREADS(p);
	t_thread_pool_shared *const	shared = THREAD_POOL_SHARED(p);
	uint32_t					i;

	pthread_mutex_lock(&shared->lock);
	shared->flags |= THREAD_POOL_F_DEAD | THREAD_POOL_F_ASLEEP;
	pthread_cond_broadcast(&shared->notify_cond);
	pthread_mutex_unlock(&shared->lock);
	i = 0;
	while (i < p->thread_count)
		pthread_join(threads[i++], NULL);
	pthread_mutex_destroy(&shared->lock);
	pthread_cond_destroy(&shared->notify_cond);
	free(p);
}
