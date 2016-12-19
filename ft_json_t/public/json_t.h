/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_t.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:22:19 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/19 17:59:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_T_H
# define JSON_T_H

# include "ft/ft_vector.h"
# include "ft/json.h"
# include "ft/libft.h"

typedef struct s_json_t_dict			t_json_t_dict;
typedef struct s_json_t_fixed_list		t_json_t_fixed_list;
typedef struct s_json_t_callback		t_json_t_callback;
typedef struct s_json_t_value			t_json_t_value;
typedef struct s_json_t_key				t_json_t_key;
typedef struct s_json_t_item			t_json_t_item;

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
** items		=> Array of item
** count		=> Number of item
** data_size	=> Total size of the struct
*/
struct		s_json_t_fixed_list
{
	t_json_t_item const	*items;
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
** JSON_T_VAL_FIXED_LIST	Custom struct
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
		JSON_T_VAL_FIXED_LIST,
		JSON_T_VAL_STRING,
		JSON_T_VAL_INT,
		JSON_T_VAL_FLOAT,
		JSON_T_VAL_BOOL,
	}				type;
	union {
		t_json_t_callback		callback;
		t_json_t_value const	*list;
		t_json_t_dict			dict;
		t_json_t_fixed_list		fixed_list;
	};
};

/*
** key				=> key name
** offset			=> offset in 'data'
** val				=> value
*/
struct		s_json_t_key
{
	t_sub					key;
	uint32_t				offset;
	t_json_t_value const	*val;
};

/*
** offset			=> offset in 'data'
** val				=> value
*/
struct		s_json_t_item
{
	uint32_t				offset;
	t_json_t_value const	*val;
};

// TODO: optional key
// TODO: nullable value

# define JSON_T_VALUE(T,...)	((t_json_t_value){JSON_T_VAL_##T,{__VA_ARGS__}})

# define JSON_T_CALLBACK(F,D,P,S)	JSON_T_VALUE(CALLBACK,.callback=((t_json_t_callback){(F),(D),(P),(S)}))

# define _JSON_T_DICT(K,S)	JSON_T_VALUE(DICT,.dict=((t_json_t_dict){K,ARRAY_LEN(K),S}))
# define JSON_T_DICT(S,...)	_JSON_T_DICT(((t_json_t_key const[]){__VA_ARGS__}),(S))

# define JSON_T_LIST(VAL)	JSON_T_VALUE(LIST, .list = &(VAL))

# define _JSON_T_FIXED_LIST(I,S)	JSON_T_VALUE(FIXED_LIST,.fixed_list=((t_json_t_fixed_list){I,ARRAY_LEN(I),S}))
# define JSON_T_FIXED_LIST(S,...)	_JSON_T_FIXED_LIST(((t_json_t_item const[]){__VA_ARGS__}),(S))

/*
** Parse a full json document
** Write into 'data' according to 't'
** Return true on success, false on error
** On error, put the error string into 'err' if it is not NULL
*/
bool		ft_json_parse(t_in *in, t_json_t_value const *t,
				void *data, t_dstr *err);

/*
** Free data allocated during parsing
*/
void		ft_json_t_free(t_json_t_value const *t, void *data);

uint32_t	ft_json_t_sizeof(t_json_t_value const *t);

#endif
