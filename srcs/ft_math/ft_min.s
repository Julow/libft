;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_min.s                                           :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/24 11:36:33 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/24 11:37:03 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_min(int a, int b);
global	ft_min

ft_min:
	cmp		rdi, rsi
	jl		.l
	mov		rax, rsi
	ret
.l:
	mov		rax, rdi
	ret