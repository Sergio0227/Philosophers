/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:06:25 by sandre-a          #+#    #+#             */
/*   Updated: 2024/07/14 13:18:02 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *nptr)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 7 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	result *= sign;
	return (result);
}

int	check_input(char **argv, t_data *t)
{
	t->nbr_philo = ft_atol(argv[1]);
	t->t_die = ft_atol(argv[2]);
	t->t_eat = ft_atol(argv[3]);
	t->t_sleep = ft_atol(argv[4]);
	if (argv[5])
		t->max_meals = ft_atol(argv[5]);
	if (t->nbr_philo > INT_MAX || t->t_die > INT_MAX || t->t_eat > INT_MAX
		|| t->t_sleep > INT_MAX)
		return (error("Invalid input - INT_MAX is the limit"));
	if (t->nbr_philo <= 0 || t->t_die <= 0 || t->t_eat <= 0 || t->t_sleep <= 0)
		return (error("Negative numbers not allowed"));
	if (argv[5] && (t->max_meals > INT_MAX || t->max_meals <= 0))
		return (error("Number of meals needs to be greater than INT_MAX"));
	t->t_die *= 1000;
	t->t_eat *= 1000;
	t->t_sleep *= 1000;
	if (t->t_die < 60000 || t->t_eat < 60000 || t->t_sleep < 60000)
		return (error("Timestamps need to be greater than 60ms"));
	return (0);
}
