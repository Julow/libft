;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_try.asm                                         :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/03/04 23:27:20 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/03/04 23:32:21 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_try(void *t)
global	ft_try

ft_try:
	mov		[rdi], rbx			; save all callee saved registers
	mov		[rdi + 8], rbp
	mov		[rdi + 16], rsp
	mov		[rdi + 24], r12
	mov		[rdi + 32], r13
	mov		[rdi + 40], r14
	mov		[rdi + 48], r15
	mov		rax, 0				; return 0
	pop		qword [rdi + 56]	; save back jump
	push	qword [rdi + 56]
	ret

