/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:52:14 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/15 14:52:20 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"
# include "vct.h"

/*
** Enums
*/

// The padding chars corresponding to those parameters identifiers are used as
// indexes during parsing, and directly as characters by our printing function.
//
typedef enum e_ptf_padding {
	pad_right_default = ' ',
	pad_right_zero = '0'
}	t_ptf_padding;

// Same thing for our sign flags and chars, we also added '-' to those,
// for full signedness support. sign_minus overrides all the other flags.
//
typedef enum e_ptf_sign {
	sign_none,
	sign_space = ' ',
	sign_plus = '+',
	sign_minus = '-'
}	t_ptf_sign;

// Enum for our functor array, allowing us to change the order of our functors
// in the array as we wish, making our code more resilient.
//
typedef enum e_ptf_types {
	typ_pct,
	typ_chr,
	typ_str,
	typ_ptr,
	typ_dec,
	typ_int,
	typ_uns,
	typ_lex,
	typ_uex,
	typ_nbc,
	typ_end
}	t_ptf_types;

// The following enums provide length modifiers management
//
typedef enum e_ptf_extend {
	ext_none,
	ext_l,
	ext_ll
}	t_ptf_extend;

typedef enum e_ptf_shorten {
	shrt_none,
	shrt_h,
	shrt_hh
}	t_ptf_shorten;

/*
** Parsing structures
*/

// Separate params struct typedef to establish precedence over the next type.
// The latter is used in that params struct and is also using said struct.
// This catch 22 situation is solved by a two part definition of the params
// struct.
//
typedef struct s_ptf_params	t_ptf_params;

// Functor type : pointing to our converter functions
//
typedef bool				(*t_converter)(t_vctr *vct, va_list args,
							t_ptf_params *params);

// Params structure : retrieving our parsed flags and parameters
//
struct s_ptf_params {
	t_ptf_padding	padding;
	bool			lftpad_toggle;
	t_ptf_sign		sign;
	bool			altform_toggle;
	char			*alt_prfx;
	t_ptf_extend	extend;
	t_ptf_shorten	shorten;
	int				width;
	bool			prec_toggle;
	int				precision;
	t_converter		type;
};

// Structure block to put into an array (of structures) for our functor array
//
typedef struct s_ptf_format {
	char			flag;
	t_converter		fct;
}	t_ptf_format;

/*
** Parsing functions
*/

int		ptf_star_treatment(t_ptf_params *params, va_list args, char mode);
bool	ptf_parse_flags(char **src, t_ptf_params *params);
bool	ptf_typeset(char **src, t_ptf_params *params,
			 va_list args, t_ptf_format *types);
int		ptf_parser(t_vctr *vct, char **src, va_list args);

/*
** Main function
*/

int		ft_printf(const char *src, ...);

#endif
