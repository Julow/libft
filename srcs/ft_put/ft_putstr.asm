;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_putstr.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/23 11:33:04 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/04 22:22:23 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_putstr(const char *str);
global	ft_putstr
extern	ft_strlen
extern	ft_putlstr

ft_putstr:
	push	rdi
	call	ft_strlen
	pop		rdi
	mov		rsi, rax
	jmp		ft_putlstr
	ret
