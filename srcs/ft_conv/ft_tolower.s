;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_tolower.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 21:52:09 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/22 22:10:12 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_tolower(int c);
global	ft_tolower

ft_tolower:
	mov		rax, rdi
	cmp		rax, 'A'
	jl		.ret
	cmp		rax, 'Z'
	jg		.ret
	add		rax, 32
.ret:
	ret
