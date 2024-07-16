/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:01:45 by sandre-a          #+#    #+#             */
/*   Updated: 2024/07/15 18:06:56 by sandre-a         ###   ########.fr       */
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
	data_init(&table);
	return (0);
}

void    *eat(void *arg)
{
    t_philo *philo;

    philo = (t_philo *) arg;

    return NULL;
}

void	start_dinner(t_data *t)
{
    int i;
    
    i = -1;
	if (t->max_meals == 0)
        return;
    //else if (t->nbr_philo == 1)
    else
        while (i++ < t->nbr_philo)
            pthread_create(&t->philos[i].pthread_id, NULL, eat, NULL);
        
}

void	get_forks(t_philo *philo, t_fork *forks)
{
	int	philo_nbr;

	philo_nbr = philo->t->nbr_philo;
    philo->left_fork = &forks[philo->id - 1];
    if (philo->id == philo_nbr)
        philo->right_fork = &forks[0];
    else
        philo->right_fork = &forks[philo->id];
}

void	philo_init(t_data *t)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < t->nbr_philo)
	{
		philo = t->philos + i;
		philo->t = t;
		philo->id = i + 1;
		philo->full = false;
		philo->nbr_meals = 0;
		get_forks(philo, philo->t->forks);
	}
}

int	data_init(t_data *t)
{
	int	i;

	i = -1;
	t->philos = malloc(sizeof(t_philo) * t->nbr_philo);
	t->forks = malloc(sizeof(t_fork) * t->nbr_philo);
    pthread_mutex_init(&t->lock, NULL);
	while (++i < t->nbr_philo)
	{
		pthread_mutex_init(&t->forks[i].fork, NULL);
		t->forks[i].id = i;
	}
	philo_init(t);
}
