/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_t.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:22:19 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/18 15:35:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_T_H
# define JSON_T_H

# include "ft/ft_vector.h"
# include "ft/json.h"
# include "ft/libft.h"

typedef struct s_json_t_dict			t_json_t_dict;
typedef struct s_json_t_callback		t_json_t_callback;
typedef struct s_json_t_value			t_json_t_value;
typedef struct s_json_t_key				t_json_t_key;

/*
** ========================================================================== **
** Json parser
*/

/*
** keys			=> Keys of the dict
** count		=> Number of key
** data_size	=> Total size of the struct
*/
struct		s_json_t_dict
{
	t_json_t_key const	*keys;
	uint32_t			count;
	uint32_t			data_size;
};

/*
** f			=> Called to parse a value
** destroy		=> Free allocated data (may be NULL)
** param		=> Custom param
** data_size	=> Size of 'data'
*/
struct		s_json_t_callback
{
	bool		(*f)(t_json_parser *p, void *data, void const *param);
	void		(*destroy)(void *data, void const *param);
	void const	*param;
	uint32_t	data_size;
};

/*
** JSON_T_VAL_CALLBACK		Call 'callback'
** JSON_T_VAL_LIST			t_vector
** JSON_T_VAL_DICT			Custom struct
** JSON_T_VAL_STRING		t_sub*
** JSON_T_VAL_INT			int32_t
** JSON_T_VAL_FLOAT			float
** JSON_T_VAL_BOOL			bool
*/
struct		s_json_t_value
{
	enum {
		JSON_T_VAL_CALLBACK,
		JSON_T_VAL_LIST,
		JSON_T_VAL_DICT,
		JSON_T_VAL_STRING,
		JSON_T_VAL_INT,
		JSON_T_VAL_FLOAT,
		JSON_T_VAL_BOOL,
	}				type;
	union {
		t_json_t_callback		callback;
		t_json_t_value const	*list;
		t_json_t_dict			dict;
	};
};

/*
** key				=> key name
** offset			=> offset in 'data'
** val				=> value
*/
struct		s_json_t_key
{
	t_sub			key;
	uint32_t		offset;
	t_json_t_value	val;
};

// TODO: optional key
// TODO: nullable value
// TODO: fixed_list

# define JSON_T_VALUE(T,...)	((t_json_t_value){JSON_T_VAL_##T,{__VA_ARGS__}})

# define _JSON_T_DICT(K,S)	JSON_T_VALUE(DICT,.dict=((t_json_t_dict){K,ARRAY_LEN(K),S}))
# define JSON_T_DICT(S,...)	_JSON_T_DICT(((t_json_t_key const[]){__VA_ARGS__}),(S))

# define JSON_T_LIST(VAL)	JSON_T_VALUE(LIST, .list = &(VAL))

/*
** Parse some json
** Return true on success, false on error
*/
bool		ft_json_parse(t_json_parser *p, t_json_t_value const *t, void *data);

/*
** Free data allocated during parsing
*/
void		ft_json_t_free(t_json_t_value const *t, void *data);

uint32_t	ft_json_t_sizeof(t_json_t_value const *t);

#endif
