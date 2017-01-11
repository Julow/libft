/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_t.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:22:19 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 15:05:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_T_H
# define JSON_T_H

# include "ft/ft_vector.h"
# include "ft/json.h"
# include "ft/libft.h"

# include <stddef.h>

typedef struct s_json_t_dict			t_json_t_dict;
typedef struct s_json_t_fixed_list		t_json_t_fixed_list;
typedef struct s_json_t_callback		t_json_t_callback;
typedef struct s_json_t_enum			t_json_t_enum;
typedef struct s_json_t_value			t_json_t_value;
typedef struct s_json_t_key				t_json_t_key;
typedef struct s_json_t_item			t_json_t_item;
typedef struct s_json_t_const			t_json_t_const;

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
** values		=> Array of enum value
** count		=> Number of value
** data_size	=> Total size of the struct
*/
struct		s_json_t_enum
{
	t_json_t_const const	*values;
	uint32_t				count;
	uint32_t				data_size;
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
** JSON_T_VAL_STRING		t_sub*			JSON_T_VALUE(STRING)
** JSON_T_VAL_INT			int32_t			JSON_T_VALUE(INT)
** JSON_T_VAL_FLOAT			float			JSON_T_VALUE(FLOAT)
** JSON_T_VAL_BOOL			bool			JSON_T_VALUE(BOOL)
** 			Simple value
** -
** JSON_T_VAL_LIST			t_vector		JSON_T_LIST(json_t_value)
** 			List of any size, each elemets have the same type
** -
** JSON_T_VAL_DICT			Custom struct	JSON_T_DICT(struct name,
** 												(key_name, struct_member, json_t_value),
** 												...
** 											)
** 			Map a c-struct
** -
** JSON_T_VAL_FIXED_LIST	Custom struct	JSON_T_FIXED_LIST(struct name,
** 												(struct_member, json_t_value),
** 												...
** 											)
** 			Like a dict with unamed and ordered members
** -
** JSON_T_VAL_ENUM			Custom			JSON_T_ENUM(type,
** 												(value_name, value),
** 												...
** 											)
** 			Enum
** -
** JSON_T_VAL_CALLBACK		Call 'callback'
*/

struct		s_json_t_value
{
	enum {
		JSON_T_VAL_CALLBACK,
		JSON_T_VAL_LIST,
		JSON_T_VAL_DICT,
		JSON_T_VAL_FIXED_LIST,
		JSON_T_VAL_ENUM,
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
		t_json_t_enum			_enum;
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

/*
** name				=> value name
** value			=> value data
*/
struct		s_json_t_const
{
	t_sub		name;
	void const	*data;
};

// TODO: optional key
// TODO: nullable value

# define JSON_T_VALUE(T,...)	((t_json_t_value){JSON_T_VAL_##T,{__VA_ARGS__}})

# define JSON_T_CALLBACK(F,D,P,S)	JSON_T_VALUE(CALLBACK,.callback=((t_json_t_callback){(F),(D),(P),(S)}))

# define __JSON_T_KEY(K,T)	{SUBC(ARG_1 K),offsetof(T,ARG_2 K),&ARG_3 K},
# define _JSON_T_KEY(T,...)	((t_json_t_key[]){FOR_EACH(__JSON_T_KEY,,T,##__VA_ARGS__)})
# define _JSON_T_DICT(K,S)	JSON_T_VALUE(DICT,.dict=((t_json_t_dict){K,ARRAY_LEN(K),S}))
# define JSON_T_DICT(T,...)	_JSON_T_DICT(_JSON_T_KEY(T,##__VA_ARGS__),sizeof(T))

# define JSON_T_LIST(VAL)	JSON_T_VALUE(LIST, .list = &(VAL))

# define __JSON_T_ITEM(I,T)		{offsetof(T,ARG_1 I),&ARG_2 I},
# define _JSON_T_ITEM(T,...)	((t_json_t_item[]){FOR_EACH(__JSON_T_ITEM,,T,##__VA_ARGS__)})
# define _JSON_T_FLIST(I,S)		JSON_T_VALUE(FIXED_LIST,.fixed_list=((t_json_t_fixed_list){I,ARRAY_LEN(I),S}))
# define JSON_T_FIXED_LIST(T,...)	_JSON_T_FLIST(_JSON_T_ITEM(T,##__VA_ARGS__),sizeof(T))

# define __JSON_T_CONST(C,T)	{SUBC(ARG_1 C),&(T){ARG_2 C}},
# define _JSON_T_CONST(T,...)	((t_json_t_const[]){FOR_EACH(__JSON_T_CONST,,T,##__VA_ARGS__)})
# define _JSON_T_ENUM(V,S)		JSON_T_VALUE(ENUM,._enum=((t_json_t_enum){V,ARRAY_LEN(V),S}))
# define JSON_T_ENUM(T,...)		_JSON_T_ENUM(_JSON_T_CONST(T,##__VA_ARGS__),sizeof(T))

/*
** Parse a full json document
** Write into 'data' according to 't'
** Return true on success, false on error
** On error, put the error string into 'err' if it is not NULL
*/
bool		ft_json_parse(t_in *in, t_json_t_value const *t,
				void *data, t_dstr *err);

/*
** Parse some json according to 't'
*/
bool		ft_json_t_next(t_json_parser *p, t_json_t_value const *t,
				void *data);

/*
** Free data allocated during parsing
*/
void		ft_json_t_free(t_json_t_value const *t, void *data);

uint32_t	ft_json_t_sizeof(t_json_t_value const *t);

#endif
