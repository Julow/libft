;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memset.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 17:54:38 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/31 19:52:11 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memset(void *mem, int c, size_t len);
global	ft_memset

set_qword:
	mov		al, sil		; { set rax with sil
	shl		rax, 8
	mov		al, sil
	mov		si, ax
	shl		rax, 16
	mov		ax, si
	shl		rax, 16
	mov		ax, si
	shl		rax, 16
	mov		ax, si		; }
	ret

ft_memset:
	mov		r10, rdi	; save rdi
	cmp		rdx, 512
	jge		.repq		; len >= 512
	cmp		rdx, 128
	jge		.repb		; len >= 128
	cmp		rdx, 0
	je		.ret		; len == 0
	cmp		rdx, 8
	jl		.loopb		; len < 8
	call	set_qword
.loopq:
	sub		rdx, 8
	mov		[rdi+rdx], rsi	; set qword
	cmp		rdx, 8
	jge		.loopq
	cmp		rdx, 0
	je		.ret		; len == 0
.loopb:
	dec		rdx			; --
	mov		[rdi+rdx], sil	; set byte
	cmp		rdx, 0
	jg		.loopb		; while rdx > 0
	jmp		.ret
.repq:
	mov		rax, rdx
	mov		rdx, 0
	mov		r9, 8
	div		r9			; rcx = len / 8
	mov		rcx, rax
	call	set_qword
	rep		stosq		; repeat while rcx > 0
	cmp		rdx, 0
	jle		.ret		; len <= 0
.repb:
	mov		rcx, rdx	; rcx = len % 8
	mov		al, sil
	rep		stosb		; repeat while rcx > 0
.ret:
	mov		rax, r10	; return rdi
	ret
