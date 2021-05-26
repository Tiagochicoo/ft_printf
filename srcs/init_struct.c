/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:42:52 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/25 22:49:52 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*new_flags(void)
{
	t_flag *flags;

	flags = (t_flag *)malloc(sizeof(t_flag));
	if (!flags)
		return (NULL);
	flags->has_minusflag = 0;
	return (flags);
}

void	init_struct(t_arg *arg)
{
	arg->type = is_null;
	arg->flags = new_flags();
}