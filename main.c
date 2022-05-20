/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:49:56 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/20 20:09:38 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int main(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 6);
	if (str == NULL)
		return (0);
	str = "Hello";

	ft_printf("this is my ft_printf: %s\n", str);
	printf("this is my string: %s\n", str);
	return (0);
}