;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memcpy.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 17:54:16 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/13 00:14:17 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memcpy(void *dst, const void *src, t_uint len);
global	ft_memcpy
global	ft_memcpy.cpy

;ft_memcpy:
;	cld
;.cpy:
;	mov		r10, rdi		; save rdi
;	cmp		rdx, 400
;	jl		.repb			; len < 400
;.repq:
;	mov		rax, rdx
;	mov		rdx, 0
;	mov		r9, 8
;	div		r9
;	mov		rcx, rax		; rcx = len / 8
;	rep		movsq			; repeat while rcx > 0
;.repb:
;	cmp		rdx, 0
;	jle		.ret			; len <= 0
;	mov		rcx, rdx		; rcx = len % 8
;	rep		movsb			; repeat while rcx > 0
;.ret:
;	mov		rax, r10		; return rdi
;	ret

;ft_memcpy:
;.cpy:
;	mov		r10, rdi		; save rdi
;	add		rdx, rdi		; end = dst + len
;.loop8_init:
;	sub		rdx, 8			; end -= 8
;	cmp		rdi, rdx
;	jg		.loop8_end		; dst < end
;.loop8:
;	mov		rax, [rsi]		; get qword
;	mov		[rdi], rax		; set qword
;	add		rdi, 8			; += 8
;	add		rsi, 8			; += 8
;	cmp		rdi, rdx
;	jl		.loop8			; while dst < end
;.loop8_end:
;	add		rdx, 8			; end += 8
;.loop1_init:
;	cmp		rdi, rdx
;	jz		.ret			; end == dst
;.loop1:
;	mov		al, [rsi]		; get byte
;	mov		[rdi], al		; set byte
;	inc		rdi				; ++
;	inc		rsi				; ++
;	cmp		rdi, rdx
;	jl		.loop1			; while dst < end
;.ret:
;	mov		rax, r10		; return rdi
;	ret

ft_memcpy:
.cpy:
	mov		r10, rdi		; save rdi
	mov		r9, 0			; i = 0
	cmp		rdx, 8
	jl		.loop1_init		; len < 8
.loop8_init;
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
