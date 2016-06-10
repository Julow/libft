/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_impl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 19:44:40 by jaguillo          #+#    #+#             */
/*   Updated: 2016/06/10 19:46:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PP_IMPL_H
# define PP_IMPL_H

/*
** ========================================================================== **
** Variant
*/

# define _VARIANT_S(TYPE)			struct s_VARIANT_##TYPE
# define _VARIANT_INIT(TYPE, A, V)	{ .e = _VARIANT_ATTR(A, TYPE), .u.A = (V) }

# define _VARIANT_T0(...)	_VARIANT_T1(__VA_ARGS__) _VARIANT_T3(__VA_ARGS__)
# define _VARIANT_T1(...)	enum { _VARIANT_T2(__VA_ARGS__) } e;
# define _VARIANT_T2(N,...)	FOR_EACH2(_VARIANT_ENUM_FOR, , N, __VA_ARGS__)
# define _VARIANT_T3(...)	union { _VARIANT_T4(__VA_ARGS__) } u;
# define _VARIANT_T4(N,...)	FOR_EACH2(_VARIANT_UNION_FOR, , N, __VA_ARGS__)

# define _VARIANT_ENUM_FOR(ATTR,TYPE,NAME)	_VARIANT_ATTR(ATTR, NAME),
# define _VARIANT_UNION_FOR(ATTR,TYPE,NAME)	TYPE ATTR;

# define _VARIANT_ATTR(ATTR, NAME)	_VARIANT_##NAME##_##ATTR

/*
** ========================================================================== **
** Sub
*/

# define _SUB_EQU(A,B)	(ft_memcmp((A).str, (B).str, (A).length) == 0)

/*
** ========================================================================== **
** Assert
*/

# define _ASSERT_LOCATION	__FILE__ ":" TO_STR(__LINE__) " "
# define _ASSERT_CODE(C)	"[\033[31m" C "\033[39m] "
# define _ASSERT_MIN(C)		_ASSERT_CODE(C) _ASSERT_LOCATION "\033[90m"
# define _ASSERT_FULL(C,V)	_ASSERT_CODE(C) V " \033[90m" _ASSERT_LOCATION
# define _ASSERT_ERR(C,V)	(sizeof(V)==1)?_ASSERT_MIN(C):_ASSERT_FULL(C,V)
# define _ASSERT_CALL(C,V)	ft_assert(_ASSERT_ERR(C, V), __func__)
# define _ASSERT_HCALL(C,V)	ft_assert_hard(_ASSERT_ERR(C, V), __func__)
# define _ASSERT_DCALL(C,V)	!ft_assert(_ASSERT_ERR("\033[32m" C, V), __func__)
# define _ASSERT_TRACE(V)	ft_assert(_ASSERT_ERR("\033[33mTRACE",V),__func__)
# define _ASSERT_DEBUG(C,V)	_ASSERT_DCALL(C, V) || _ASSERT_CALL(C, V)

/*
** ========================================================================== **
** Utils
*/

# define _CAT(A,B)		A##B

# define _ARG_COUNT(...)			_ARG_COUNT_N(__VA_ARGS__)

# define _ARG_COUNT_N(E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,n,...) n
# define _ARG_COUNT_L	21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

/*
** ========================================================================== **
** For each
*/

# define _FOR_EACH_S(F, ...)		CAT(_F_EACH##F##_,ARG_COUNT(__VA_ARGS__))

# define _F_EACH_0(F, S, P)
# define _F_EACH_1(F, S, P, A)		F(A,P)

# define _F_EACH2_0(F, S, P)
# define _F_EACH2_2(F, S, P, A, B)	F(A, B, P)

/*
** ?omg
** out("\n")
** for i in range(2, 22):
** 	out(("# define _F_EACH_%d(F,S,P,A,...)	" +
** 		"F(A,P) S _F_EACH_%d(F,S,P,__VA_ARGS__)\n")
** 		% (i, i - 1))
** out("\n")
** for i in range(4, 22, 2):
** 	out(("# define _F_EACH2_%d(F,S,P,A,B,...)	" +
** 		"F(A,B,P) S _F_EACH2_%d(F,S,P,__VA_ARGS__)\n")
** 		% (i, i - 2))
** out("\n")
*/

# define _F_EACH_2(F,S,P,A,...)	F(A,P) S _F_EACH_1(F,S,P,__VA_ARGS__)
# define _F_EACH_3(F,S,P,A,...)	F(A,P) S _F_EACH_2(F,S,P,__VA_ARGS__)
# define _F_EACH_4(F,S,P,A,...)	F(A,P) S _F_EACH_3(F,S,P,__VA_ARGS__)
# define _F_EACH_5(F,S,P,A,...)	F(A,P) S _F_EACH_4(F,S,P,__VA_ARGS__)
# define _F_EACH_6(F,S,P,A,...)	F(A,P) S _F_EACH_5(F,S,P,__VA_ARGS__)
# define _F_EACH_7(F,S,P,A,...)	F(A,P) S _F_EACH_6(F,S,P,__VA_ARGS__)
# define _F_EACH_8(F,S,P,A,...)	F(A,P) S _F_EACH_7(F,S,P,__VA_ARGS__)
# define _F_EACH_9(F,S,P,A,...)	F(A,P) S _F_EACH_8(F,S,P,__VA_ARGS__)
# define _F_EACH_10(F,S,P,A,...)	F(A,P) S _F_EACH_9(F,S,P,__VA_ARGS__)
# define _F_EACH_11(F,S,P,A,...)	F(A,P) S _F_EACH_10(F,S,P,__VA_ARGS__)
# define _F_EACH_12(F,S,P,A,...)	F(A,P) S _F_EACH_11(F,S,P,__VA_ARGS__)
# define _F_EACH_13(F,S,P,A,...)	F(A,P) S _F_EACH_12(F,S,P,__VA_ARGS__)
# define _F_EACH_14(F,S,P,A,...)	F(A,P) S _F_EACH_13(F,S,P,__VA_ARGS__)
# define _F_EACH_15(F,S,P,A,...)	F(A,P) S _F_EACH_14(F,S,P,__VA_ARGS__)
# define _F_EACH_16(F,S,P,A,...)	F(A,P) S _F_EACH_15(F,S,P,__VA_ARGS__)
# define _F_EACH_17(F,S,P,A,...)	F(A,P) S _F_EACH_16(F,S,P,__VA_ARGS__)
# define _F_EACH_18(F,S,P,A,...)	F(A,P) S _F_EACH_17(F,S,P,__VA_ARGS__)
# define _F_EACH_19(F,S,P,A,...)	F(A,P) S _F_EACH_18(F,S,P,__VA_ARGS__)
# define _F_EACH_20(F,S,P,A,...)	F(A,P) S _F_EACH_19(F,S,P,__VA_ARGS__)
# define _F_EACH_21(F,S,P,A,...)	F(A,P) S _F_EACH_20(F,S,P,__VA_ARGS__)

# define _F_EACH2_4(F,S,P,A,B,...)	F(A,B,P) S _F_EACH2_2(F,S,P,__VA_ARGS__)
# define _F_EACH2_6(F,S,P,A,B,...)	F(A,B,P) S _F_EACH2_4(F,S,P,__VA_ARGS__)
# define _F_EACH2_8(F,S,P,A,B,...)	F(A,B,P) S _F_EACH2_6(F,S,P,__VA_ARGS__)
# define _F_EACH2_10(F,S,P,A,B,...)	F(A,B,P) S _F_EACH2_8(F,S,P,__VA_ARGS__)
# define _F_EACH2_12(F,S,P,A,B,...)	F(A,B,P) S _F_EACH2_10(F,S,P,__VA_ARGS__)
# define _F_EACH2_14(F,S,P,A,B,...)	F(A,B,P) S _F_EACH2_12(F,S,P,__VA_ARGS__)
# define _F_EACH2_16(F,S,P,A,B,...)	F(A,B,P) S _F_EACH2_14(F,S,P,__VA_ARGS__)
# define _F_EACH2_18(F,S,P,A,B,...)	F(A,B,P) S _F_EACH2_16(F,S,P,__VA_ARGS__)
# define _F_EACH2_20(F,S,P,A,B,...)	F(A,B,P) S _F_EACH2_18(F,S,P,__VA_ARGS__)

/*
** ?end
*/

#endif
