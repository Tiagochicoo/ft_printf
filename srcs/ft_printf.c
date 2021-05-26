/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:22:10 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/25 21:10:31 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_data(char *format_copy, va_list *args)
{
	int		printed_chars;
	char	*input;
	t_arg	arg_struct;

	printed_chars = 0;
	while (1)
	{
		input = read_str(&format_copy);
		if (!input)
			break ;
		if (input[0] == '%')
		{
			arg_struct = read_arg(input, args);
			printed_chars += write_arg(arg_struct);
			free_struct(&arg_struct);
		}
		else
			printed_chars += ft_putstr(input);
		free(input);
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*format_copy;
	int		printed_chars;

	printed_chars = 0;
	if (!format)
		return (0);
	format_copy = ft_strdup(format);
	va_start(args, format);
	printed_chars = print_data(format_copy, &args);
	free(format_copy);
	va_end(args);
		return (printed_chars);
}
