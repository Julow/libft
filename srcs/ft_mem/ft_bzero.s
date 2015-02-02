;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_bzero.s                                         :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 17:54:58 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/02/02 22:57:00 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; void			*ft_bzero(void *mem, size_t len);
global	ft_bzero
extern	ft_memset

ft_bzero:
	mov		rdx, rsi
	mov		rsi, 0
	jmp		ft_memset
	ret
