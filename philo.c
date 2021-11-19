/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:36:45 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/19 00:59:10 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kteb(t_philo *filoxa, char *ashdar)
{
	t_time	time;

	time = wkita() - filoxa->spopo->start_simul;
	pthread_mutex_lock(&filoxa->spopo->blati);
	printf("[%llu] faylasouf %d %s\n", time, filoxa->id, ashdar);
	if (strcmp(ashdar, "mat mskin (l3o9ba l anass o omar)") == 0)
	{
		usleep(1000);
		exit(0);
	}
	pthread_mutex_unlock(&filoxa->spopo->blati);
}

void	koul(t_philo *filoxa)
{
	pthread_mutex_lock(&filoxa->spopo->forshita[filoxa->left_forks]);
	kteb(filoxa, "shed fourshita lisriya");
	pthread_mutex_lock(&filoxa->spopo->forshita[filoxa->right_fork]);
	kteb(filoxa, "shed fourshita limniya");
	kteb(filoxa, "kiyakoul");
	timer(filoxa->spopo->paramixa->think * 1000);
	filoxa->last_meals = wkita();
	filoxa->nbr_to_eat++;
	pthread_mutex_unlock(&filoxa->spopo->forshita[filoxa->left_forks]);
	pthread_mutex_unlock(&filoxa->spopo->forshita[filoxa->right_fork]);
}

int	main(int ac, char **av)
{
	t_param	*param;
	t_philo	*fibos;
	t_spopo	*spopowa;
	t_time	start;

	spopowa = malloc(sizeof(t_spopo));
	start = wkita();
	if (ac == 5 || ac == 6)
	{
		spopowa = init_zab(spopowa, av, ac);
		spopowa->forshita = initliaz_frashet(spopowa);
		spopowa = init_falasifa(spopowa);
		if (spopowa->forshita == NULL)
			return (0);
		init_routini(spopowa);
	}
	else
		erorixa();
	eami_lboulisi(spopowa);
	while (1)
		;
	return (0);
}
