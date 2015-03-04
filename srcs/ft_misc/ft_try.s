/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.s                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 23:26:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/04 23:26:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int			ft_try(void *t)
*/
.global	ft_try

ft_try:
	movq	%rbx, (%rdi)
	movq	%rbp, 8(%rdi)
	movq	%rsp, 16(%rdi)
	movq	%r12, 24(%rdi)
	movq	%r13, 32(%rdi)
	movq	%r14, 40(%rdi)
	movq	%r15, 48(%rdi)
	popq	56(%rdi)
	pushq	56(%rdi)
	movq	$0, %rax
	ret
