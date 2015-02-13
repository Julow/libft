;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memmove.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/02/02 14:13:17 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/13 14:55:20 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memmove(void *dst, const void *src, t_uint len);
global	ft_memmove
extern	ft_memcpy

ft_memmove:
	cmp		rdi, rsi
	jle		ft_memcpy
.rev:
	mov		r10, rdi		; save dst
	mov		r9, rdx			; i = len
.loop8_init:
	cmp		r9, 8
	jl		.loop1_init		; if i < 0 .loop1_init
.loop8:
	sub		r9, 8
	mov		rax, [rsi+r9]	; get qword
	mov		[rdi+r9], rax	; set qword
	cmp		r9, 8
	jge		.loop8			; while i >= 8 .loop8
.loop1_init:
	cmp		r9, 0
	jz		.ret			; if i == 0 .ret
.loop1:
	dec		r9				; i--
	mov		al, [rsi+r9]	; get byte
	mov		[rdi+r9], al	; set byte
	cmp		r9, 0
	jg		.loop1			; while i > 0 .loop1
.ret:
	mov		rax, r10		; return saved dst
	ret
