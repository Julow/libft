/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 17:28:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/06 19:10:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define VASM		asm volatile

void			ft_throw(void *t)
{
	VASM("movq	(%rdi), %rbx\n"
		"popq	%rbp\n"
		"movq	8(%rdi), %rbp\n"
		"pushq	%rbp\n"
		"movq	8(%rdi), %rbp\n"
		"movq	16(%rdi), %rsp\n"
		"movq	24(%rdi), %r12\n"
		"movq	32(%rdi), %r13\n"
		"movq	40(%rdi), %r14\n"
		"movq	48(%rdi), %r15\n"
		"movq	$1, %rax\n"
		"jmpq	*56(%rdi)\n");
	(void)t;
}
