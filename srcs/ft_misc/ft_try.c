/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 17:02:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/24 01:19:15 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_try(t_bp *t)
{
	VASM("jmp .save_state\n"
		".save_backjump:\n"
		"popq	56(%rdi)\n"
		"pushq	56(%rdi)\n"
		"ret\n"
		".save_state:\n"
		"movq	%rbx, (%rdi)\n"
		"movq	%rbp, 8(%rdi)\n"
		"movq	%rsp, 16(%rdi)\n"
		"movq	%r12, 24(%rdi)\n"
		"movq	%r13, 32(%rdi)\n"
		"movq	%r14, 40(%rdi)\n"
		"movq	%r15, 48(%rdi)\n"
		"movb	$0, 64(%rdi)\n"
		"movq	$0, %rax\n"
		"call .save_backjump\n");
	(void)t;
	return (0);
}
