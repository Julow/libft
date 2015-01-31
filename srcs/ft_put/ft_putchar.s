;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_putchar.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/23 11:20:52 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/26 12:18:09 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_putchar(char c);
global	ft_putchar
extern	ft_putlstr

ft_putchar:
	lea		rcx, [rel char]
	mov		[rcx], dil
	mov		rdi, rcx	; char (rdi)
	mov		rsi, 1		; len
	call	ft_putlstr
	ret

section .bss
	char	resb 1
