/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:01:45 by sandre-a          #+#    #+#             */
/*   Updated: 2024/07/16 19:21:33 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	precise_usleep(long msec)
{
	long	start_time;

	start_time = gettime(MICROSECOND);
	while (gettime(MICROSECOND) - start_time < msec)
		if (gettime(MICROSECOND) - start_time == msec)
			break ;
	return (gettime(MICROSECOND) - start_time);
}
int	main(int argc, char **argv)
{
	t_data	table;
	long	start;

	if (argc == 5 || argc == 6)
		check_input(argv, &table);
	else
		error("Invalid number of arguments passed");
	data_init(&table);
	start_dinner(&table);
	return (0);
}

void	wait_all_threads(t_data *t)
{
	while (!get_bool(&t->lock, &t->threads_ready))
		;
}

void	eat(t_philo *philo)
{
	precise_usleep(philo->t->t_eat);
	philo->last_meal = gettime(MICROSECOND);
	printf("%lu Philo %d has eaten\n", gettime(MICROSECOND) - philo->last_meal,
		philo->id);
}

void	*simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->t);
	while (!philo->t->dinner_end)
	{
		if (philo->full)
			break ;
		eat(philo);
		// sleep(philo);
		// think(philo);
	}
	return (NULL);
}

void	start_dinner(t_data *t)
{
	int	i;

	i = -1;
	if (t->max_meals == 0)
		return ;
	// else if (t->nbr_philo == 1)
	else
	{
		while (++i < t->nbr_philo)
		{
			pthread_create(&t->philos[i].pthread_id, NULL, simulation,
				(void *)&t->philos[i]);
		}
	}
	t->dinner_time = gettime(MILLISECOND);
	set_bool(&t->lock, &t->threads_ready, true);
	i = -1;
	while (++i < t->nbr_philo)
		pthread_join(t->philos[i].pthread_id, NULL);
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
