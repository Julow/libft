;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memset.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 17:54:38 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/13 16:27:12 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memset(void *mem, int c, size_t len);
global	ft_memset

ft_memset:
	mov		r10, rdi		; save rdi
.loop8_init:
	cmp		rdx, 8
	jl		.loop1_init		; if len < 0 .loop1_init
	mov		al, sil			; { fill rax with sil
	shl		rax, 8
	mov		al, sil
	mov		si, ax
	shl		rax, 16
	mov		ax, si
	shl		rax, 16
	mov		ax, si
	shl		rax, 16
	mov		ax, si			; }
.loop8:
	sub		rdx, 8			; len -= 8
	mov		[rdi+rdx], rax	; set qword mem[len]
	cmp		rdx, 8
	jge		.loop8			; while len >= 8 .loop8
.loop1_init:
	cmp		rdx, 0
	jz		.ret			; if len == 0 .ret
.loop1:
	dec		rdx				; len--
	mov		[rdi+rdx], sil	; set byte
	cmp		rdx, 0
	jg		.loop1			; while len > 0 .loop1
.ret:
	mov		rax, r10		; return saved rdi
	ret
