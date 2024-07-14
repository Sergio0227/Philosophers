/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:06:57 by sandre-a          #+#    #+#             */
/*   Updated: 2024/07/14 17:09:58 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/time.h>

# define RST "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

struct s_data;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}					t_fork;

typedef struct s_philo
{
	struct s_data	*t;
	int				index;
	pthread_t		pthread_id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				nbr_meals;
	long			last_meal;
	bool			full;

}					t_philo;

typedef struct s_data
{
	long			nbr_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			max_meals;
	long			dinner_time;
	t_fork			*forks;
	t_philo			*philos;
}					t_data;

int					error(char *error);
long				costum_atol(const char *nptr);
int					check_input(char **argv, t_data *t);
int					data_init(t_data *table);

#endif