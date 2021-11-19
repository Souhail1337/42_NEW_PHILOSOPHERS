/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:39:01 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/19 00:50:54 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*initliaz_frashet(t_spopo *spopowa)
{
	pthread_mutex_t	*frashet;
	int				i;

	i = 0;
	frashet = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* spopowa->paramixa->nbr_philo);
	if (!frashet)
		return (NULL);
	while (i < spopowa->paramixa->nbr_philo)
	{
		pthread_mutex_init(&frashet[i], 0);
		i++;
	}
	return (frashet);
}

t_spopo	*init_falasifa(t_spopo *spopowa)
{
	int	i;

	i = 0;
	spopowa->filoxat = malloc(sizeof(t_philo) * spopowa->paramixa->nbr_philo);
	if (!spopowa->filoxat)
		return (NULL);
	while (i < spopowa->paramixa->nbr_philo)
	{
		spopowa->filoxat[i].id = i + 1;
		spopowa->filoxat[i].left_forks = i;
		spopowa->filoxat[i].right_fork = (i + 1) % spopowa->paramixa->nbr_philo;
		spopowa->filoxat[i].last_meals = 0;
		spopowa->filoxat[i].nbr_to_eat = 0;
		pthread_mutex_init(&spopowa->filoxat[i].is_eating, NULL);
		spopowa->filoxat[i].spopo = spopowa;
		i++;
	}
	return (spopowa);
}

t_spopo	*init_zab(t_spopo *spopowa, char **str, int ac)
{
	spopowa->paramixa->nbr_philo = ft_atoi(str[1]);
	spopowa->paramixa->die = ft_atoi(str[2]);
	spopowa->paramixa->think = ft_atoi(str[3]);
	spopowa->paramixa->sleept = ft_atoi(str[4]);
	if (ac == 5)
		spopowa->paramixa->meals = -1;
	if (ac == 6)
	{
		spopowa->paramixa->meals = ft_atoi(str[5]);
		if (spopowa->paramixa->meals < 0)
			error();
	}
	if (spopowa->paramixa->nbr_philo < 0 || spopowa->paramixa->die < 0
		|| spopowa->paramixa->think < 0
		|| spopowa->paramixa->sleept < 0)
		error();
	if (spopowa->paramixa->nbr_philo == 0)
		error_f();
	return (spopowa);
}

void	init_routini(t_spopo *spopowa)
{
	int			i;
	pthread_t	*tmp;

	tmp = malloc(sizeof(pthread_t) * spopowa->paramixa->nbr_philo);
	pthread_mutex_init(&spopowa->blati, NULL);
	spopowa->start_simul = wkita();
	i = 0;
	while (i < spopowa->paramixa->nbr_philo)
	{
		pthread_create(tmp + i, NULL, &routini, spopowa->filoxat + i);
		usleep(300);
		i++;
	}
}
