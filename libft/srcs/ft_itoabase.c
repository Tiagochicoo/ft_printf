/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 08:53:07 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 09:06:47 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numdigits(long n, int base)
{
	int		len;

	if (n == 0)
		return (1);
	len = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoabase(long n, int base)
{
	char	*rep_str;
	char	*str;
	int		len;

	len = ft_numdigits(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	rep_str = "0123456789abcdef";
	str[len] = '\0';
	str[0] = (n < 0) ? '-' : ' ';
	while (n != 0)
	{
		str[--len] = rep_str[(n % base) * ((n < 0) ? -1 : 1)];
		n /= base;
	}
	return (str);
}