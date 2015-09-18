;; ************************************************************************** ;;
;;                                                                            ;;
;;                                                        :::      ::::::::   ;;
;;   ft_isdigit.s                                       :+:      :+:    :+:   ;;
;;                                                    +:+ +:+         +:+     ;;
;;   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        ;;
;;                                                +#+#+#+#+#+   +#+           ;;
;;   Created: 2015/01/21 14:16:54 by jaguillo          #+#    #+#             ;;
;;   Updated: 2015/01/31 23:13:14 by jaguillo         ###   ########.fr       ;;
;;                                                                            ;;
;; ************************************************************************** ;;

; int			ft_isdigit(int c);
global	ft_isdigit
extern	ft_isrange

ft_isdigit:
	mov		esi, '0'
	mov		edx, '9'
	jmp		ft_isrange
