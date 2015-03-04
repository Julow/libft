;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_isalpha.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 21:21:17 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/31 23:17:34 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_isalpha(int c);
global	ft_isalpha
extern	ft_isrange

ft_isalpha:
	mov		esi, 'a'
	mov		edx, 'z'
	call	ft_isrange		; ft_isrange(c, 'a', 'z')
	cmp		rax, 1
	je		.ret			; if is range
	mov		esi, 'A'
	mov		edx, 'Z'
	call	ft_isrange		; ft_isrange(c, 'A', 'Z')
.ret:
	ret
