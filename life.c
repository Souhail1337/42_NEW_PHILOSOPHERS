/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:47:46 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/20 11:23:20 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	neass(t_philo *filoxa)
{
	kteb(filoxa, "is Sleeping");
	timer(filoxa->spopo->paramixa->sleept * 1000);
}

void	fkr(t_philo *filoxa)
{
	kteb(filoxa, "Is Thinking");
}

void	*routini(void *filoxa)
{
	t_philo	*philo;

	philo = (t_philo *)filoxa;
	philo->last_meals = wkita();
	while (1)
	{
		koul(philo);
		neass(philo);
		fkr(philo);
	}
}
