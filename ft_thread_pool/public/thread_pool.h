/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 22:22:55 by juloo             #+#    #+#             */
/*   Updated: 2016/06/29 18:02:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_POOL_H
# define THREAD_POOL_H

# include "libft.h"

typedef struct s_task_manager	t_task_manager;
typedef struct s_thread_pool	t_thread_pool;
typedef void					(*t_task_f)(void *task_data);

/*
** ========================================================================== **
** Thread pool
** -
*/

/*
** The init function
** Called by threads to init a new task
** -
** *f			=> have to be set to the function to call
** data			=> can be used to transfer data to 'f'
** -
** Never called twice asynchronously
** -
** If it return false, the thread pool goes to sleep
*/
typedef bool			(*t_init_f)(t_task_manager *m, t_task_f *f, void *data);

/*
** The task_manager object
** -
** init_f			=> the init function
** task_size		=> size of task_data
*/
struct			s_task_manager
{
	t_init_f		init_f;
	uint32_t		task_size;
};

# define TASK_MANAGER(F,S)	((t_task_manager){V(F), (S)})

/*
** The thread_pool object
** -
** task_manager		=> task manager object
** thread_count		=> number of thread created
** -
** It is safe to change the task_manager
**  when the thread pool is asleep or locked
*/
struct			s_thread_pool
{
	t_task_manager	*task_manager;
	uint32_t		thread_count;
};

/*
** Create a thread pool
** By default, the thread pool is sleeping and locked
** It must be wake up by:
**  ft_thread_pool_notify(p);
**  followed by unlock, wait or join
** -
** If pthread_create() fail, continue with thread_count--
** Return NULL if no thread have been created or an error occured
*/
t_thread_pool	*ft_thread_pool_create(uint32_t thread_count);

/*
** Lock/unlock the thread pool
** -
** lock=true
**  Prevent threads from calling the init_f function
**  Allow safe read/write of task_manager's data
** lock=false
**  If the thread pool is not asleep, threads run in background
** -
** Locking twice from the same thread cause dead lock
** Unlocking without having locked cause an unexpected behavior
*/
void			ft_thread_pool_lock(t_thread_pool *p, bool lock);

/*
** Notify the thread pool there are new tasks available
** Wake up sleeping threads
** -
** Must be called on a locked thread pool
** -
** The notification take effect on the next unlock, wait or join
*/
void			ft_thread_pool_notify(t_thread_pool *p);

/*
** Wait until a task is done
** -
** Must be called on a locked thread pool
** -
** Return false if the thread pool is asleep and all tasks are done
*/
bool			ft_thread_pool_wait(t_thread_pool *p);

/*
** Wait until all the tasks are done
** the current thread temporarily become a working thread
** -
** Must be called on a locked thread pool
*/
void			ft_thread_pool_join(t_thread_pool *p);

/*
** Wait current tasks to finish
** and destroy the thread pool
** -
** Must be called on an unlocked thread pool
*/
void			ft_thread_pool_destroy(t_thread_pool *p);

#endif
