;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strcat.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/22 13:36:51 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/03 22:58:11 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; char			*ft_strcat(char *s1, const char *s2);
global	ft_strcat
extern	ft_strlen

ft_strcat:
	push	rdi				; save rdi
	call	ft_strlen
	pop		rdi				; restore rdi
	mov		rcx, rdi
	add		rcx, rax
.loop:
	mov		al, [rsi]		; get char
	mov		[rcx], al		; set char
	cmp		al, 0
	jz		.ret			; break loop
	inc		rcx				; ++
	inc		rsi
	jmp		.loop
.ret:
	mov		rax, rdi		; return rdi
	ret
