/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:47:46 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/19 00:49:47 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	neass(t_philo *filoxa)
{
	kteb(filoxa, "n3ass");
	timer(filoxa->spopo->paramixa->sleept * 1000);
}

void	fkr(t_philo *filoxa)
{
	kteb(filoxa, "kikhamem");
}

void	*routini(void *filoxa)
{
	t_philo	*philo;

	philo = (t_philo *)filoxa;
	while (1)
	{
		koul(philo);
		neass(philo);
		fkr(philo);
	}
}
