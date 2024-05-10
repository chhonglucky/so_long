/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:58:24 by chanhhon          #+#    #+#             */
/*   Updated: 2023/10/25 19:06:07 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t			i;
	int				value_sign;
	unsigned int	value;

	i = 0;
	value_sign = 1;
	value = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			value_sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = 10 * value + str[i] - '0';
		i++;
	}
	return (value_sign * value);
}
