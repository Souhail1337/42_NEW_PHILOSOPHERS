/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:51:05 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/20 12:56:30 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_are_fat(t_spopo *spopowa)
{
	int	i;
	int	size;

	i = 0;
	size = spopowa->paramixa->nbr_philo;
	while (i < size)
	{
		if (spopowa->filoxat[i].nbr_to_eat < spopowa->paramixa->meals)
			return (0);
		i++;
	}
	return (1);
}

void	eami_lboulisi(t_spopo *spopowa)
{
	int		i;
	t_time	wqitatatay;

	while (1)
	{
		i = 0;
		if (spopowa->paramixa->meals != -1 && all_are_fat(spopowa))
			break ;
		while (i < spopowa->paramixa->nbr_philo)
		{
			wqitatatay = wkita() - spopowa->filoxat[i].last_meals;
			if (wqitatatay >= (t_time)spopowa->paramixa->die)
				kteb(&spopowa->filoxat[i], "Died");
			i++;
		}
	}
}
