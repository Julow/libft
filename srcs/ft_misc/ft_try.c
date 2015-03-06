/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 17:02:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/06 19:10:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define VASM		asm volatile

int				ft_try(void *t)
{
	VASM("movq	%rbx, (%rdi)\n"
		"popq	8(%rdi)\n"
		"movq	%rsp, 16(%rdi)\n"
		"movq	%r12, 24(%rdi)\n"
		"movq	%r13, 32(%rdi)\n"
		"movq	%r14, 40(%rdi)\n"
		"movq	%r15, 48(%rdi)\n"
		"popq	56(%rdi)\n"
		"pushq	56(%rdi)\n"
		"movq	$0, %rax\n"
		"pushq	8(%rdi)\n");
	(void)t;
	return (0);
}
