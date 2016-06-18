/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 22:22:55 by juloo             #+#    #+#             */
/*   Updated: 2016/06/19 00:45:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_POOL_H
# define THREAD_POOL_H

# include "libft.h"

typedef struct s_thread_pool	t_thread_pool;
typedef void					(*t_task_f)(void *task_data);

/*
** ========================================================================== **
** Thread pool
** -
*/

/*
** The start function
** -
** Called by threads to start a new task
** 	*f			=> have to be set to the function to call
** 	task_data	=> can be used to transfer data to 'f'
** -
** Never called twice in parallel
** -
** If it return false, the thread pool goes to sleep
** Unexpected behavior if '*f' is set to NULL
*/
typedef bool			(*t_start_f)(void *env, t_task_f *f, void *task_data);

/*
** The thread_pool object
** start_f			=> the start function
** env				=> param of the start function
** task_data_size	=> size of task data
** thread_count		=> number of thread created
** -
** 'start_f', 'env' and 'task_data_size' can be modified
*/
struct			s_thread_pool
{
	t_start_f		start_f;
	void			*env;
	uint32_t		task_data_size;
	uint32_t		thread_count;
};

/*
** Create a thread pool
** By default, the thread pool is sleeping and must be wake up by:
**  ft_thread_pool_lock(p, false);
** -
** If pthread_create() fail, continue with thread_count--
** Return NULL if no thread have been created or an error occured
*/
t_thread_pool	*ft_thread_pool_create(uint32_t thread_count,
					uint32_t task_data_size, t_start_f start_f, void *env);

/*
** Lock/unlock the internal mutex
** -
** lock=true
**  Prevent threads from calling the start_f function
**  Allow safe modification of 'env'
** lock=false
**  Notify the thread pool there are new tasks available
**  Wake up sleeping threads
** -
** Locking twice from the same thread cause dead lock
** Unlocking without having locked cause an unexpected behavior
*/
void			ft_thread_pool_lock(t_thread_pool *p, bool lock);

/*
** Wait until all the tasks are done
** the current thread temporarily become a working thread
*/
void			ft_thread_pool_join(t_thread_pool *p);

/*
** Wait current tasks to finish
** and destroy the thread pool
*/
void			ft_thread_pool_destroy(t_thread_pool *p);

#endif
