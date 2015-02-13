;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memmove.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/02/02 14:13:17 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/13 15:51:57 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memmove(void *dst, const void *src, t_uint len);
global	ft_memmove
global	ft_memrcpy
extern	ft_memcpy

ft_memmove:
	cmp		rdi, rsi
	jle		ft_memcpy
ft_memrcpy:
.rev:
	mov		r10, rdi		; save dst
.loop8_init:
	cmp		rdx, 8
	jl		.loop1_init		; if len < 0 .loop1_init
.loop8:
	sub		rdx, 8			; len -= 8
	mov		rax, [rsi+rdx]	; get qword src[len]
	mov		[rdi+rdx], rax	; set qword dst[len]
	cmp		rdx, 8
	jge		.loop8			; while len >= 8 .loop8
.loop1_init:
	cmp		rdx, 0
	jz		.ret			; if len == 0 .ret
.loop1:
	dec		rdx				; len--
	mov		al, [rsi+rdx]	; get byte
	mov		[rdi+rdx], al	; set byte
	cmp		rdx, 0
	jg		.loop1			; while len > 0 .loop1
.ret:
	mov		rax, r10		; return saved dst
	ret
