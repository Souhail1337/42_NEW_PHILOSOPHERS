#include "philo.h"

void error()
{
    printf("Error: Values Are Negative\n");
    exit(0);
}

int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	isdigits(const char *str)
{
	int	i;
	int	signe;

	i = 0;
	signe = 0;
	while (str[i])
	{
		if (!signe && (str[i] == '-' || str[i] == '+' ))
		{
			signe = 1;
			i++;
			continue ;
		}
		else if (!isdigit(str[i]))
			return (0);
		else
			signe = 1;
		i++;
	}
	return (1);
}

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	long			result;
	long			border;
	size_t			i;
	int				sign;

	result = 0;
	border = 4294967295;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-'))
		sign = -1;
	else
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
	{
		if (result > border && sign == 1)
			return (-1);
		else if (result > border && sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)(result * sign));
}

t_args *init_zab(t_args *philo, char **str, int ac)
{
    philo = malloc(sizeof(t_args));
    philo->nbr_philo = ft_atoi(str[1]) ;
    philo->die =  ft_atoi(str[2]);
    philo->think = ft_atoi(str[3]);
    philo->sleept = ft_atoi(str[4]);
    if (ac == 5)
        philo->meals = -1;
    if (ac == 6)
    {
        philo->meals = ft_atoi(str[5]);
        if (philo->meals < 0)
            error();
    }
    if (philo->nbr_philo < 0 || philo->die < 0 || philo->think < 0 || 
        philo->sleept < 0)
            error();
    return (philo);
}

t_args *values(char **str, t_args *philo)
{
    int i = 1;
    while(str[i] != NULL)
    {
        printf("%s\n",str[i]);
        i++;
    }
    return (philo);
}

t_philo *init_falasifa(int nbr_f)
{
	t_philo *fibos;
	fibos = malloc(sizeof(t_philo) * (nbr_f));
	int i;

	i = 0;
	while(i < nbr_f)
	{
		fibos[i].id = i;
		i++;
	}
	while(i < nbr_f)
	{
		printf("PHILO NBR = %d\n",fibos[i].id + 1) ;
		i++;
	}
	return (fibos);
}

t_time wkita()
{
	struct timeval  tv;
	gettimeofday(&tv,NULL);
	return (tv.tv_sec * 1000); // convert to milisecond ;
}

void *hayat(void *zaim)
{
	 t_philo *fibos;

	fibos = zaim;
	while(1)
	{
		printf("%lld Pillo nbr %d is alive\n", wkita(), fibos->id);
		sleep(1);
	}
	
	
	return (zaim);
}

void lahoakbar(t_philo *fibos, int nbr_f)
{
	int i;

	i = 0;
	while (i < nbr_f)
	{
		pthread_create(&(fibos[i].routini), NULL, hayat, &(fibos[i]));
		i++;

	}
}


int main(int ac, char **av)
{
    t_args *args;
    t_philo *fibos;
    if (ac == 5 || ac == 6)
    {
        args = init_zab(args,av,ac);
		fibos = init_falasifa(args->nbr_philo);
		lahoakbar(fibos, args->nbr_philo);
    }
	while(1);
    return (0);
}