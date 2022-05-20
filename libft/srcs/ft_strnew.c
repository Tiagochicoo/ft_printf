/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:45:52 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/18 23:27:23 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The function ft_strnew() allocates with malloc(3) and returns a fresh
** string ending with '\0'. Each character of the string is initialized at
** '\0'. If the allocation fails, the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
	{
		str = (char *)ft_calloc(size, sizeof(*str) * (1));
		return (str);
	}
	return (NULL);
}
