;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_isprint.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 21:47:15 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/31 23:13:17 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_isprint(int c);
global	ft_isprint
extern	ft_isrange

ft_isprint:
	mov		esi, ' '
	mov		edx, '~'
	jmp		ft_isrange
