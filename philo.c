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
void error_f()
{
	printf("maymknsh ykoun 0 faylasof wash nta hbil");
	exit(0);
}
pthread_mutex_t *initliaz_frashet(t_param *philo)
{
	pthread_mutex_t *frashet;
	int i;

	i = 0;

	frashet = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->nbr_philo);
	if (!frashet)

		return (NULL);
	while(i < philo->nbr_philo)
	{
		pthread_mutex_init(&frashet[i],0);
		i++;
	}
	return (frashet);
}

t_param *init_zab(t_param *philo, char **str, int ac)
{
	t_philo *fibox;
	fibox = malloc(sizeof(t_philo));
    philo = malloc(sizeof(t_param));
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
	if (philo->nbr_philo == 0)
		error_f();
	
	return (philo);
}

t_param *values(char **str, t_param *philo)
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
	int  i;
	i = 0;

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
	 t_param *filox;

	fibos = zaim;
	while(1)
	{
		printf("%lld Pillo nbr %d is alive\n", wkita(), fibos->id);
		//printf("frashet = %d\n", (int)filox->forshita);
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

void erorixa(void)
{
	printf("Usage: Nbr of philos, Time to die, time to eat, time to sleep\n");
	printf("and nbr of meals\n");
	exit(0);
}

int main(int ac, char **av)
{
    t_param *param;
    t_philo *fibos;
	int f;
	int i;
    if (ac == 5 || ac == 6)
    {
        param = init_zab(param,av,ac);
		param->forshita = initliaz_frashet(param);
		fibos = init_falasifa(param->nbr_philo);
		if (param->forshita == NULL)
			return (NULL);
		lahoakbar(fibos, param->nbr_philo);
    }
	else
		erorixa();
	while(1);
    return (0);
}