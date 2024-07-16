/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:06:25 by sandre-a          #+#    #+#             */
/*   Updated: 2024/07/16 17:58:54 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	costum_atol(const char *nptr)
{
	long	result;

	result = 0;
	while (*nptr == 32 || (*nptr >= 7 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			return (LONG_MIN);
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (LONG_MAX);
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	if (*nptr == 0)
		return (result);
	return (LONG_MAX);
}

int	check_input(char **argv, t_data *t)
{
	t->nbr_philo = costum_atol(argv[1]);
	t->t_die = costum_atol(argv[2]);
	t->t_eat = costum_atol(argv[3]);
	t->t_sleep = costum_atol(argv[4]);
	if (argv[5])
		t->max_meals = costum_atol(argv[5]);
	else
		t->max_meals = -1;
	if (t->nbr_philo > INT_MAX || t->t_die > INT_MAX || t->t_eat > INT_MAX
		|| t->t_sleep > INT_MAX)
		return (error("Invalid input - Not a number or greater than INT_MAX"));
	if (t->nbr_philo <= 0 || t->t_die <= 0 || t->t_eat <= 0 || t->t_sleep <= 0)
		return (error("Negative or null numbers not allowed"));
	if (t->t_die < 60 || t->t_eat < 60 || t->t_sleep < 60)
		return (error("Timestamps need to be greater than 60ms"));
	if (argv[5] && (t->max_meals > INT_MAX || t->max_meals <= 0))
		return (error("Number of meals needs to be greater than 0 and smaller"
						"than INT_MAX"));
	// t->t_die *= 1000;
	// t->t_eat *= 1000;
	// t->t_sleep *= 1000;
	return (0);
}

long	gettime(t_time_code time_code)
{
	struct  timeval tv;
	if (gettimeofday(&tv, NULL))
		error("gettimeofday failed");
	if (time_code == SECOND)
		return (tv.tv_sec + tv.tv_usec / 1000000);
	else if (time_code == MILLISECOND)
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	else if (time_code == MICROSECOND)
		return (tv.tv_sec * 100000 + tv.tv_usec);
	else 
		error("Wrong input to gettime!");
	return (0);
}

int	error(char *error)
{
	printf(RED "❌%s❌\n" RST, error);
	return (1);
}
