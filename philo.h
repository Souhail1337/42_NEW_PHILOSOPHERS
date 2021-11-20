/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:07:40 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/11/20 14:04:41 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <sys/time.h>

typedef unsigned long long	t_time;

typedef struct s_param
{
	int				nbr_philo;
	int				die;
	int				sleept;
	int				t_eat;
	int				meals;
	int				kla;
}					t_param;

typedef struct s_philo
{
	int				id;
	int				left_forks;
	int				right_fork;
	pthread_t		routini;
	pthread_mutex_t	is_eating;
	struct s_spopo	*spopo;
	int				nbr_to_eat;
	int				nbr_meals;
	t_time			last_meals;
}					t_philo;

typedef struct s_spopo
{
	pthread_mutex_t	*forshita;
	struct s_philo	*filoxat;
	struct s_param	*paramixa;
	t_time			start_simul;
	pthread_mutex_t	blati;
}					t_spopo;

int					init_test(t_spopo *philo, char **str, int ac);
t_time				wkita(void);
t_spopo				*init_falasifa(t_spopo *filoxa);
pthread_mutex_t		*initliaz_frashet(t_spopo *philo);
int					ft_atoi(const char *str);
void				*routini(void *filoxa);
void				init_routini(t_spopo *spopowa);
void				eami_lboulisi(t_spopo *spopowa);
void				fkr(t_philo *filoxa);
void				neass(t_philo *filoxa);
void				koul(t_philo *filoxa);
void				kteb(t_philo *filoxa, char *ashdar);
void				timer(int t);

#endif
