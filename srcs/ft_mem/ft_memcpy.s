;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memcpy.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 17:54:16 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/02 18:48:40 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memcpy(void *dst, const void *src, t_uint len);
global	ft_memcpy
global	ft_memcpy.cpy

ft_memcpy:
	cld
.cpy:
	mov		r10, rdi		; save rdi
	cmp		rdx, 400
	jl		.repb			; len < 400
.repq:
	mov		rax, rdx
	mov		rdx, 0
	mov		r9, 8
	div		r9
	mov		rcx, rax		; rcx = len / 8
	rep		movsq			; repeat while rcx > 0
.repb:
	cmp		rdx, 0
	jle		.ret			; len <= 0
	mov		rcx, rdx		; rcx = len % 8
	rep		movsb			; repeat while rcx > 0
.ret:
	mov		rax, r10		; return rdi
	ret
