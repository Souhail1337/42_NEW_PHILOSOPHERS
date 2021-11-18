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

typedef struct s_param
{
    int nbr_philo;
    int die;
    int sleept;
    int think;
    int meals;
    pthread_mutex_t *forshita;
}   t_param;

typedef struct s_philo
{
    int id;
    int left_forks;
    int right_fork;
    pthread_t routini;
     /// no fuking mallooc l pthread 7it type opaque
    int nbr_to_eat;
    int last_meals; // akhir mra kla mskin

}   t_philo;


//philo = din
//param = philo

void        error();
t_param     *init_zab(t_param *philo, char **str, int ac);
t_time      wkita();
t_philo     *init_falasifa(int nbr_f);
int         ft_atoi(const char *str);
void        erorixa(void);

#endif