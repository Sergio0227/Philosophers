/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:01:45 by sandre-a          #+#    #+#             */
/*   Updated: 2024/07/14 17:59:42 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	table;

	if (argc == 5 || argc == 6)
		check_input(argv, &table);
	else
		error("Invalid number of arguments passed");
	// data_init(&table);
	return (0);
}

int	error(char *error)
{
	printf(RED "❌%s❌\n" RST, error);
	return (1);
}
void	*start_dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
}

int	philo_init(t_data *t)
{
	int	i;

	i = -1;
	while (++i < t->nbr_philo)
	{
		t->philos[i].t = t;
		t->philos[i].index = i;
		t->philos[i].full = false;
		t->philos[i].nbr_meals = 0;
	}
}

int	data_init(t_data *t)
{
	int	i;

	i = -1;
	t->philos = malloc(sizeof(t_philo) * t->nbr_philo);
	t->forks = malloc(sizeof(t_fork) * t->nbr_philo);
	while (++i < t->nbr_philo)
	{
		pthread_mutex_init(&t->forks[i].fork, NULL);
		t->forks[i].id = i;
	}
}
