/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:35:12 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/19 00:36:34 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	isdigits(const char *str)
{
	int	i;
	int	signe;

	i = 0;
	signe = 0;
	while (str[i])
	{
		if (!signe && (str[i] == '-' || str[i] == '+' ))
		{
			signe = 1;
			i++;
			continue ;
		}
		else if (!isdigit(str[i]))
			return (0);
		else
			signe = 1;
		i++;
	}
	return (1);
}

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	long			result;
	long			border;
	size_t			i;
	int				sign;

	result = 0;
	border = 4294967295;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-'))
		sign = -1;
	else
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
	{
		if (result > border && sign == 1)
			return (-1);
		else if (result > border && sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)(result * sign));
}
