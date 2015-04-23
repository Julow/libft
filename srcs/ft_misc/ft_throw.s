;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_throw.s                                         :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/03/04 23:27:22 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/04/24 01:19:22 by juloo            ###   ########.fr       ;;
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
	mov		[rdi + 64], byte 1	; set catch flag
	jmp		[rdi + 56]			; jump back
	ret
