;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memcmp.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/25 23:14:47 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/25 23:46:15 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_memcmp(const void *mem1, const void *mem2, size_t len);
global	ft_memcmp

ft_memcmp:
	mov		rax, 0
	mov		r8, 0
	cmp		rdx, 0
	jz		.ret		; len == 0
	cmp		rdx, 8
	jl		.loop1_ini	; len < 8
.loop8:
	mov		rax, [rdi]
	mov		r8, [rsi]
	cmp		rax, r8
	jne		.loop1_ini
	sub		rdx, 8		; -= 8
	add		rdi, 8		; += 8
	add		rsi, 8
	cmp		rdx, 8
	jge		.loop8		; while len >= 8
.loop1_ini:
	cmp		rdx, 0
	jz		.ret		; len == 0
	mov		rax, 0
	mov		r8, 0
.loop1:
	mov		al, [rdi]
	mov		r8b, [rsi]
	cmp		al, r8b
	jne		.ret
	dec		rdx			; --
	inc		rdi			; ++
	inc		rsi
	cmp		rdx, 0
	jg		.loop1		; while len > 0
.ret:
	sub		eax, r8d	; cmp
	ret
