;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memcpy.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 17:54:16 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/13 14:39:16 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memcpy(void *dst, const void *src, t_uint len);
global	ft_memcpy

ft_memcpy:
	mov		r10, rdi		; save rdi
	mov		r9, 0			; i = 0
.loop8_init:
	cmp		rdx, 8
	jl		.loop1_init		; len < 8
	sub		rdx, 8			; len -= 8
.loop8:
	mov		rax, [rsi+r9]	; get qword
	mov		[rdi+r9], rax	; set qword
	add		r9, 8			; i += 8
	cmp		r9, rdx
	jl		.loop8			; while i < len
.loop8_end:
	add		rdx, 8			; len += 8
.loop1_init:
	cmp		r9, rdx
	jz		.ret			; i == len
.loop1:
	mov		al, [rsi+r9]	; get byte
	mov		[rdi+r9], al	; set byte
	inc		r9				; i++
	cmp		r9, rdx
	jl		.loop1			; while i < len
.ret:
	mov		rax, r10		; return rdi
	ret
