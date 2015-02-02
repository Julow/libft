;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_memmove.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/02/02 14:13:17 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/02 18:46:50 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_memmove(void *dst, const void *src, t_uint len);
global	ft_memmove
extern	ft_memcpy.cpy

ft_memmove:
	cmp		rdi, rsi
	jl		.cpy			; rdi > rsi
.move:
	add		rdi, rdx		; += len
	add		rsi, rdx
	dec		rdi
	dec		rsi
	std						; reverse rep
.cpy:
	jmp		ft_memcpy.cpy
