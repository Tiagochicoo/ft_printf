/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:32:03 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/27 11:07:29 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./includes/ft_printf.h"

// %[flags][width][.precision][length]specifier
int main(void)
{
	int len, len2;

	len = ft_printf(" -%*c* -%-*c* ", -2, 0, 2, 0);
	printf("\n");
	len2 = printf(" -%*c* -%-*c* ", -2, 0, 2, 0);
	printf("\n");
	if (len != len2)
	{
		printf("Lengths differ. -> %d \n", len - len2);
		return (1);
	}
	return (0);
}
