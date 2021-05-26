/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countletter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:41:48 by tpereira          #+#    #+#             */
/*   Updated: 2021/04/21 20:09:26 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_countletter(char *str, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (str)
    {
        while (str[count] != '\0')
        {
            if (str[i] == c)
                count++;
            i++;
        }
    }
    return (count);
}