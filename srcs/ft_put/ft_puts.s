;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_puts.s                                          :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/22 17:14:46 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/04 22:31:40 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_puts(const char *s);
global	ft_puts
extern	ft_putstr
extern	ft_putchar
extern	ft_putlstr

ft_puts:
	cmp		rdi, 0
	jz		.null
	call	ft_putstr
	mov		rdi, 10
	jmp		ft_putchar	; put \n
	ret
.null:
	mov		rdi, null_str
	mov		rsi, null_len
	jmp		ft_putlstr
	ret

section .data
	null_str	db "(null)", 10
	null_len	equ $ - null_str
