;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_throw.asm                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/03/04 23:27:22 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/03/04 23:32:14 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			ft_throw(void *t)
global	ft_throw

ft_throw:
	mov		rbx, [rdi]			; restore all callee saved registers
	mov		rbp, [rdi + 8]
	mov		rsp, [rdi + 16]
	mov		r12, [rdi + 24]
	mov		r13, [rdi + 32]
	mov		r14, [rdi + 40]
	mov		r15, [rdi + 48]
	mov		rax, 1				; return 1 (in ft_try)
	jmp		[rdi + 56]			; jump back
	ret
