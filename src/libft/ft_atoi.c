/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:18:56 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/01/22 08:19:05 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\v' || c == '\t' || c == '\r' || c == '\f'
		|| c == '\n');
}

long	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!ft_isdigit(str[i + 1]))
		{
			ft_putstr_fd("Error: Invalid agruments.\n", 2);
			exit(1);
		}
		if (str[i] == '+')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return (res * neg);
}
