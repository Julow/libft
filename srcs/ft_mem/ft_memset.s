;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memset.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 17:54:38 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/02 18:47:27 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memset(void *mem, int c, size_t len);
global	ft_memset

ft_memset:
	mov		r10, rdi		; save rdi
	cmp		rdx, 400
	jl		.repb			; len < 400
.repq:
	mov		rax, rdx
	mov		rdx, 0
	mov		r9, 8
	div		r9				; rcx = len / 8
	mov		rcx, rax
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
	rep		stosq			; repeat while rcx > 0
.repb:
	cmp		rdx, 0
	jle		.ret			; len <= 0
	mov		al, sil
	mov		rcx, rdx		; rcx = len % 8
	rep		stosb			; repeat while rcx > 0
.ret:
	mov		rax, r10		; return rdi
	ret
