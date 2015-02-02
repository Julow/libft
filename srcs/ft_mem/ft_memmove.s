;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memmove.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/02/02 14:13:17 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/02 23:07:45 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memmove(void *dst, const void *src, t_uint len);
global	ft_memmove
extern	ft_memcpy.cpy

ft_memmove:
	cmp		rdi, rsi
	jl		.cpy			; rdi > rsi
.move:
	add		rdi, rdx		; += len - 1
	add		rsi, rdx
	dec		rdi
	dec		rsi
	std						; reverse rep
.cpy:
	call	ft_memcpy.cpy
	cld						; clear direction
	ret
