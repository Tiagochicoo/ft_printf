/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_and_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:48:57 by tpereira          #+#    #+#             */
/*   Updated: 2021/06/12 15:59:34 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(char **input, t_arg *arg_struct)
{
	while (**input == '-' || **input == '0' || **input == '*')
	{
		if (**input == '-')
			arg_struct->flags->has_minusflag = 1;
		if (**input == '0')
			arg_struct->flags->has_zeroflag = 1;
		if (**input == '*')
			arg_struct->flags->has_starflag = 1;
		(*input)++;
	}
}

void	set_width(char **input, t_arg *arg_struct, va_list *args)
{
	char	num_str[12];
	int		i;
	if (arg_struct->flags->has_starflag)
	{
		i = va_arg(*args, int);
		arg_struct->fieldwidth = i;
	}
	else
	{
		i = 0;
		while (ft_isdigit(**input))
		{
			num_str[i] = **input;
			(*input)++;
			i++;
		}
		num_str[i] = '\0';
		arg_struct->fieldwidth = ft_atoi(num_str);
	}
}

void	set_precision(char **input, t_arg *arg_struct, va_list *args)
{
	char		num_str[12];
	int		i;

	if (**input == '.')
	{
		(*input)++;
		if (ft_isdigit(**input))
		{
			i = 0;
			while (ft_isdigit(**input))
			{
				num_str[i] = **input;
				(*input)++;
				i++;
			}
			num_str[i] = '\0';
			arg_struct->precision = ft_atoi(num_str);		
		}
		else if (**input == '*')
		{
			arg_struct->precision = va_arg(*args, int);
			(*input)++;
		}
		else
			arg_struct->precision = 0;
	}
	while (**input == '.' || ft_isdigit(**input))
		(*input)++;
}

void	clean_flags(t_arg *arg_struct)
{
	if (arg_struct->flags->has_spaceflag && arg_struct->flags->has_plusflag)
		arg_struct->flags->has_spaceflag = 0;
	if (arg_struct->flags->has_zeroflag && arg_struct->flags->has_minusflag)
		arg_struct->flags->has_zeroflag = 0;
	if (arg_struct->flags->has_zeroflag && arg_struct->precision != -1)
		arg_struct->flags->has_zeroflag = 0;
}