;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_isword.s                                        :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/02/04 22:01:10 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/04 22:03:21 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_isword(int c);
global	ft_isword
extern	ft_isalnum

ft_isword:
	cmp		edi, '_'
	jz		.true			; c == '_'
	jmp		ft_isalnum
	ret
.true:
	mov		rax, 1
	ret
