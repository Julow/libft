;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_isalnum.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 21:44:21 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/31 23:18:21 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_isalnum(int c);
global	ft_isalnum
extern	ft_isalpha
extern	ft_isdigit

ft_isalnum:
	call	ft_isalpha		; ft_isalpha(c)
	cmp		rax, 1
	je		.ret
	call	ft_isdigit		; ft_isdigit(c)
.ret:
	ret
