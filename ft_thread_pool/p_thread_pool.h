/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_thread_pool.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 11:31:28 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/19 00:40:00 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_THREAD_POOL_H
# define P_THREAD_POOL_H

# include "ft/thread_pool.h"
# include <pthread.h>

typedef struct s_thread_pool_shared	t_thread_pool_shared;

/*
** Shared object between threads
*/
struct			s_thread_pool_shared
{
	t_thread_pool const	*pool;
	pthread_mutex_t		lock;
	pthread_cond_t		join_cond;
	pthread_cond_t		notify_cond;
	uint32_t			working_threads;
	uint32_t			flags;
};

/*
** Prevent threads from trying to start new tasks
*/
# define THREAD_POOL_F_ASLEEP	(1 << 0)

/*
** The thread pool is dead
*/
# define THREAD_POOL_F_DEAD		(1 << 1)

/*
** Get private fields
*/
# define THREAD_POOL_SHARED(P)	(ENDOF(P))
# define THREAD_POOL_THREADS(P)	(ENDOF(P) + sizeof(t_thread_pool_shared))

/*
** Thread's main function (called by pthread)
*/
void			*thread_pool_t_start(t_thread_pool_shared *shared);

/*
** Try to start a new task and execute it
** or falls asleep
** (Should not be called on an asleep thread pool)
** The lock mutex have to be locked before this function
*/
void			thread_pool_t_work(t_thread_pool_shared *shared);

#endif
