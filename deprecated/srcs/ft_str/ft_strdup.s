;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strdup.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/22 16:23:27 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/24 23:36:58 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; char			*ft_strdup(const char *str);
global	ft_strdup
extern	ft_strlen
extern	ft_memcpy
extern	malloc

ft_strdup:
	call	ft_strlen	; get len
	push	rdi			; save rdi
	push	rax			; save len
	mov		rdi, rax
	call	malloc		; malloc
	cmp		rax, 0
	je		.error		; malloc fail
	mov		rdi, rax
	pop		rdx
	pop		rsi			; rdi
	call	ft_memcpy
	ret
.error:
	mov		rax, 0
	ret
