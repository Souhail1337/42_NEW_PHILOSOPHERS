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
pthread_mutex_t *initliaz_frashet(t_spopo *spopowa)
{
	pthread_mutex_t	*frashet;
	int	i;

	i = 0;
	frashet = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
	 * spopowa->paramixa->nbr_philo);
	if (!frashet)
		return (NULL);
	while(i < spopowa->paramixa->nbr_philo)
	{
		pthread_mutex_init(&frashet[i],0);
		i++;
	}
	return (frashet);
}
void	timer(int t)
{
	t_time	start;
	t_time	time_diff;

	start = wkita() * 1000;
	while (1)
	{
		time_diff = t - (wkita() * 1000 - start);
		if (time_diff < 50)
		{
			usleep(time_diff);
			break ;
		}
		if (time_diff > (uint64_t)t)
			break ;
		usleep(50);
	}
}

t_spopo *init_zab(t_spopo *spopowa, char **str, int ac)
{

    spopowa->paramixa->nbr_philo = ft_atoi(str[1]) ;
    spopowa->paramixa->die =  ft_atoi(str[2]);
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
	|| spopowa->paramixa->think < 0 || 
        spopowa->paramixa->sleept < 0)
            error();
	if (spopowa->paramixa->nbr_philo == 0)
		error_f();
	return (spopowa);
}



t_spopo *init_falasifa(t_spopo *spopowa)
{
	int	i;

	i = 0;
	spopowa->filoxat = malloc(sizeof(t_philo) * spopowa->paramixa->nbr_philo);
	while(i < spopowa->paramixa->nbr_philo)
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

t_time wkita()
{
	struct timeval  tv;
	gettimeofday(&tv,NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000); // convert to milisecond ;
}

void erorixa(void)
{
	printf("Usage: Nbr of philos, Time to die, time to eat, time to sleep\n");
	printf("and nbr of meals\n");
	exit(0);
}

void	kteb(t_philo *filoxa, char *ashdar)
{
	t_time time;

	time = wkita() - filoxa->spopo->start_simul;
	pthread_mutex_lock(&filoxa->spopo->blati);
	printf("[%llu] faylasouf %d %s\n", time, filoxa->id, ashdar);
	if (strcmp(ashdar , "mat mskin (l3o9ba l anass o omar)") == 0)
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
	t_philo *philo;

	philo = (t_philo *)filoxa;
	while (1)
	{
		koul(philo);
		neass(philo);
		fkr(philo);
	}
}

void	init_routini(t_spopo *spopowa)
{
	int	i;
	pthread_t *tmp;

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
void eami_lboulisi(t_spopo *spopowa)
{
	int	i;
	t_time wqitatatay;

	while (1)
	{
		i = 0;
		while (i < spopowa->paramixa->nbr_philo)
		{
			wqitatatay = wkita() - spopowa->filoxat[i].last_meals;
			if (wqitatatay > spopowa->paramixa->die)
			{
				kteb(&spopowa->filoxat[i], "mat mskin (l3o9ba l anass o omar)");
			}
			i++;
		}
	}
}

int main(int ac, char **av)
{
    t_param *param;
    t_philo *fibos;
	t_spopo *spopowa;
	spopowa = malloc(sizeof(t_spopo));
	int f;
	int i;
    if (ac == 5 || ac == 6)
    {
		spopowa = init_zab(spopowa,av,ac);
		spopowa->forshita = initliaz_frashet(spopowa);
		spopowa = init_falasifa(spopowa);
		if (spopowa->forshita == NULL)
			return (0);
		
			t_time start = wkita();
		init_routini(spopowa);
    }
	else
		erorixa();
	
	eami_lboulisi(spopowa);
	while(1)
		;
    return (0);
}