;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memcpy.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 17:54:16 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/31 19:52:32 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memcpy(void *dst, const void *src, size_t len);
global	ft_memcpy

ft_memcpy:
	mov		r10, rdi	; save rdi
	cmp		rdx, 512
	jge		.repq		; len >= 512
	cmp		rdx, 128
	jge		.repb		; len >= 128
	cmp		rdx, 0
	je		.ret		; len == 0
	cmp		rdx, 8
	jl		.loopb		; len < 8
.loopq:
	sub		rdx, 8
	mov		r9, [rsi+rdx]	; get qword
	mov		[rdi+rdx], r9	; set qword
	cmp		rdx, 8
	jge		.loopq		; while rdx >= 8
	cmp		rdx, 0
	je		.ret		; len == 0
.loopb:
	dec		rdx			; --
	mov		r9b, [rsi+rdx]	; get byte
	mov		[rdi+rdx], r9b	; set byte
	cmp		rdx, 0
	jg		.loopb		; while rdx > 0
	jmp		.ret
.repq:
	mov		rax, rdx
	mov		rdx, 0
	mov		r9, 8
	div		r9
	mov		rcx, rax	; rcx = len / 8
	rep		movsq		; repeat while rcx > 0
.repb:
	mov		rcx, rdx	; rcx = len % 8
	rep		movsb		; repeat while rcx > 0
.ret:
	mov		rax, r10	; return rdi
	ret
