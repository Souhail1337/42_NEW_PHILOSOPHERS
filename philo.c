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

t_philo *init_zab(t_philo *philo, char **str, int ac)
{
    philo = malloc(sizeof(t_philo));
    philo->philo = ft_atoi(str[1]) ;
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
    if (philo->philo < 0 || philo->die < 0 || philo->think < 0 || 
        philo->sleept < 0)
            error();
    return (philo);
}

t_philo *values(char **str, t_philo *philo)
{
    int i = 1;
    while(str[i] != NULL)
    {
        printf("%s\n",str[i]);
        i++;
    }
    return (philo);
}


int main(int ac, char **av)
{
    t_philo *philo;
    
    if (ac == 5 || ac == 6)
    {
        philo = init_zab(philo,av, ac);

    }
    return (0);
}