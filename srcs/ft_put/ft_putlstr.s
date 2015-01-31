;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_putlstr.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/24 17:59:24 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/25 00:05:38 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_putlstr(const char *str, size_t len);
global	ft_putlstr

ft_putlstr:
%ifdef LINUX
	push	rbx			; save rbx
	mov		rdx, rsi	; len
	mov		rcx, rdi	; str
	mov		rbx, 1		; fd
	mov		rax, 4		; write interrupt
	int		0x80
	pop		rbx			; restore rbx
%else
	mov		rdx, rsi	; len
	mov		rsi, rdi	; str
	mov		rdi, 1		; fd
	mov		rax, 0x2000004	; write syscall
	syscall
%endif
	mov		rax, 0		; return 0
	ret
