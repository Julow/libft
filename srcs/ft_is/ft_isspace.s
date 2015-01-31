;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_isspace.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/22 16:39:31 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/31 23:19:02 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_isspace(int c);
global	ft_isspace
extern	ft_isrange

ft_isspace:
	cmp		edi, ' '		; check space
	jz		.true
	mov		esi, 9			; check \t, \n, \v, \f, \r
	mov		edx, 13
	jmp		ft_isrange
.true:
	mov		rax, 1
	ret
