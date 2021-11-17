#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo
{
    int philo;
    int die;
    int sleept;
    int think;
    int meals;
}   t_philo;

void error();
t_philo *init_zab(t_philo *philo, char **str, int ac);
#endif