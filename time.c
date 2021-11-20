/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:42:19 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/20 07:31:09 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timer(int t)
{
	t_time	start;
	t_time	time_diff;

	start = wkita() * 1000;
	while (1)
	{
		time_diff = t - (wkita() * 1000 - start);
		if (time_diff < 50)
		{
			usleep(time_diff);
			break ;
		}
		if (time_diff > (uint64_t)t)
			break ;
		usleep(50);
	}
}

t_time	wkita(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + (tv.tv_usec / 1000));
}
