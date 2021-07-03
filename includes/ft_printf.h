/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:47:48 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/03 17:07:40 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/includes/libft.h"

int		ft_printf(const char *format, ...);

typedef enum e_type {
	is_null,
	is_snum,
	is_unum,
	is_char,
	is_string,
	is_pointer,
	is_wchar,
	is_wstring,
	is_escape,
	num_types
}	t_type;

typedef struct s_flag {
	int	has_minusflag;
	int	has_zeroflag;
	int	has_pointflag;
	int	has_starflag;
	int	has_hashflag;
	int	has_plusflag;
	int	has_spaceflag;
	int	has_dotflag;
	int	has_lflag;
	int	has_hflag;
}	t_flag;

typedef struct s_arg {
	t_type	type;
	t_flag	*flags;
	int		fieldwidth;
	int		precision;
	char	*modifiers;
	int		specifier;
	int		is_invalid;
	int		is_negative;
	int		base;
	void	*data;
	char	*str;
	wchar_t	*wstr;
}	t_arg;

char	*read_str(char **str);
t_arg	read_arg(char *input, va_list *args);

void	free_struct(t_arg *arg_struct);
void	set_struct(char *input, t_arg *arg_struct, va_list *args);
void	init_struct(t_arg *arg);
t_flag	*new_flags(void);

void	set_flags(char **str_block, t_arg *arg_struct);
void	set_width(char **str_block, t_arg *arg_struct, va_list *args);
void	set_precision(char **str_block, t_arg *arg_struct, va_list *args);
void	set_modifiers(char **str_block, t_arg *arg_struct);
void	set_specifier(char **str_block, t_arg *arg_struct);
void	set_type(t_arg *arg_struct);
void	set_data(t_arg *arg_struct, va_list *arg_ptr);
void	set_char(t_arg *arg_struct, va_list *args);
void	set_wstring(t_arg *arg_struct, va_list *args);
void	set_wchar(t_arg *arg_struct, va_list *args);
void	set_string(t_arg *arg_struct, va_list *args);
void	set_is_negative(t_arg *arg_struct, int snum);
void	set_base(t_arg *arg_struct);
void	clean_flags(t_arg *arg_struct);

void	manage_zero_width(t_arg *arg_struct);
void	manage_hash(t_arg *arg_struct);
void	manage_sign(t_arg *arg_struct);
void	apply_widths_and_flags(t_arg *arg_struct);

int		print_c(t_arg *arg_struct);

# define FLAGS "-0*#+lh"
# define DIGITS "0123456789"
# define PRECISION_SEP "."
# define MODIFIERS "hljz"
# define CONVERSIONS "cspdiuxX%nfge"

#endif