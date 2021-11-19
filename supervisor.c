/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:51:05 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/19 00:53:33 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eami_lboulisi(t_spopo *spopowa)
{
	int		i;
	t_time	wqitatatay;

	while (1)
	{
		i = 0;
		while (i < spopowa->paramixa->nbr_philo)
		{
			wqitatatay = wkita() - spopowa->filoxat[i].last_meals;
			if (wqitatatay > spopowa->paramixa->die)
				kteb(&spopowa->filoxat[i], "mat mskin (l3o9ba l anass o omar)");
			i++;
		}
	}
}
