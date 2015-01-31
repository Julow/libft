;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_strlen.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 21:58:53 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/24 16:31:00 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; size_t		ft_strlen(const char *str);
global	ft_strlen

ft_strlen:
	mov		rax, rdi
	mov		cl, [rax] 	; get char
	cmp		cl, 0
	jz		.ret		; len = 0
.loop:
	inc		rax			; ++
	mov		cl, [rax] 	; get char
	cmp		cl, 0
	jnz		.loop		; continue
.ret:
	sub		rax, rdi	; sub pointers
	ret
