;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_isspace.asm                                     :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/22 16:39:31 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/03/09 17:35:08 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_isspace(int c);
global	ft_isspace

ft_isspace:
	cmp		edi, ' '		; check space
	jz		.true
	cmp		edi, 9			; check \t
	jz		.true
	mov		rax, 0
	ret
.true:
	mov		rax, 1
	ret
