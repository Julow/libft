;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_bzero.s                                         :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 17:54:58 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/13 15:58:12 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_bzero(void *mem, size_t len);
global	ft_bzero

ft_bzero:
	mov		r10, rdi		; save rdi
	mov		rax, 0
.loop8_init:
	cmp		rsi, 8
	jl		.loop1_init		; if len < 0 .loop1_init
.loop8:
	sub		rsi, 8
	mov		[rdi+rsi], rax	; set qword mem[len]
	cmp		rsi, 8
	jge		.loop8			; while len >= 8 .loop8
.loop1_init:
	cmp		rsi, 0
	jz		.ret			; if len == 0 .ret
.loop1:
	dec		rsi				; len--
	mov		[rdi+rsi], al	; set byte mem[len]
	cmp		rsi, 0
	jg		.loop1			; while len > 0 .loop1
.ret:
	mov		rax, r10		; return saved rdi
	ret
