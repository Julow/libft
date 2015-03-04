/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw.s                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 23:26:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/04 23:26:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** void			ft_throw(void *t)
*/
.global	ft_throw

ft_throw:
	movq	(%rdi), %rbx
	movq	8(%rdi), %rbp
	movq	16(%rdi), %rsp
	movq	24(%rdi), %r12
	movq	32(%rdi), %r13
	movq	40(%rdi), %r14
	movq	48(%rdi), %r15
	movq	$1, %rax
	jmpq	*56(%rdi)
	ret
