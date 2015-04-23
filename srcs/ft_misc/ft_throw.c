/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 17:28:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/24 01:19:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_throw(t_bp *t)
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
		"movb	$1, 64(%rdi)\n"
		"jmpq	*56(%rdi)\n");
	(void)t;
}
