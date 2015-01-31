;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_cat.s                                           :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/22 17:30:19 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/26 12:15:49 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			ft_cat(int fd);
global	ft_cat
extern	ft_putlstr

ft_cat:
	push	rbx			; save rbx
	mov		rbx, rdi	; save rdi
.read:
%ifdef LINUX
	mov		rdx, buff_size
	mov		rcx, buff
	mov		rax, 3		; read interrupt
	int		0x80
%else
	mov		rdx, buff_size
	lea		rsi, [rel buff]
	mov		rdi, rbx
	mov		rax, 0x2000003	; read syscall
	syscall
	jc		.ret		; error break loop
%endif
	cmp		rax, 0
	jle		.ret		; eof break loop
.write:
	mov		rsi, rax
	lea		rdi, [rel buff]
	call	ft_putlstr
	jmp		.read
.ret:
	pop		rbx			; restore rbx
	ret

section .bss
	buff		resb 192
	buff_size	equ $ - buff
