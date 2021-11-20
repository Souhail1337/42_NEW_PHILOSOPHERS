/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:36:45 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/20 13:57:46 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kteb(t_philo *filoxa, char *ashdar)
{
	t_time	time;

	time = wkita() - filoxa->spopo->start_simul;
	pthread_mutex_lock(&filoxa->spopo->blati);
	printf("[%llu] Philo : %d %s\n", time, filoxa->id, ashdar);
	if (strcmp(ashdar, "Died") == 0)
	{
		usleep(1000);
		exit(0);
	}
	pthread_mutex_unlock(&filoxa->spopo->blati);
}

void	koul(t_philo *filoxa)
{
	pthread_mutex_lock(&filoxa->spopo->forshita[filoxa->left_forks]);
	kteb(filoxa, "Took the left fork");
	pthread_mutex_lock(&filoxa->spopo->forshita[filoxa->right_fork]);
	kteb(filoxa, "took the right fork");
	pthread_mutex_lock(&filoxa->is_eating);
	kteb(filoxa, " is eating");
	filoxa->nbr_to_eat++;
	timer(filoxa->spopo->paramixa->t_eat * 1000);
	pthread_mutex_unlock(&filoxa->is_eating);
	filoxa->last_meals = wkita();
	pthread_mutex_unlock(&filoxa->spopo->forshita[filoxa->left_forks]);
	pthread_mutex_unlock(&filoxa->spopo->forshita[filoxa->right_fork]);
}

int	main(int ac, char **av)
{
	t_spopo	*spopowa;
	t_time	start;

	spopowa = malloc(sizeof(t_spopo));
	start = wkita();
	if (ac == 5 || ac == 6)
	{
		spopowa->paramixa->kla = 0;
		spopowa = init_test(spopowa, av, ac);
		spopowa->forshita = initliaz_frashet(spopowa);
		spopowa = init_falasifa(spopowa);
		init_routini(spopowa);
		eami_lboulisi(spopowa);
	}
	else
		erorixa();
	return (0);
}
