/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:30:28 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/05 05:30:30 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_valid_hex(char *str)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (!(ft_isdigit(str[i])) && (str[i] < 'a' || str[i] > 'f') &&
			(str[i] < 'A' || str[i] > 'F'))
			return (-1);
		i++;
	}
	return (0);
}
