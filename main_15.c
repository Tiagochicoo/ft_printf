/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:32:03 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/07 17:57:39 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./includes/ft_printf.h"
#define INT_MIN -2147483648
#define UINT_MAX 2147483647

// %[flags][width][.precision][length]specifier
int main(void)
{
	int len, len2;

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	len = write(1, "ft_printf:|", 11);
	len = ft_printf(" %-3.2d %10.42d ", 1, -1);
	printf("|\nprintf:   |");
	len2 = printf(" %-3.2d %10.42d ", 1, -1);
	printf("|\n");
	if (len != len2)
	{
		int message = len - len2;
		printf("Lengths differ -> %d\n",message);
		return (1);
	}
	else
		printf("All good! \n");
	return (0);
}
