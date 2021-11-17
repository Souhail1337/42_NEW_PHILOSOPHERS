#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/time.h>

typedef long long t_time; 

typedef struct s_args
{
    int nbr_philo;
    int die;
    int sleept;
    int think;
    int meals;
}   t_args;

typedef struct s_philo
{
    int id;
    pthread_t routini;
    pthread_mutex_t forshita; /// no fuking mallooc l pthread 7it type opaque
    int nbr_to_eat;
    int last_meals; // akhir mra kla mskin

}   t_philo;

void        error();
t_args     *init_zab(t_args *philo, char **str, int ac);
t_time      wkita();
t_philo     *init_falasifa(int nbr_f);
int         ft_atoi(const char *str);

#endif