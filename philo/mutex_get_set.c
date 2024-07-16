/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_get_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:28:53 by sandre-a          #+#    #+#             */
/*   Updated: 2024/07/16 16:22:14 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

bool get_bool(pthread_mutex_t *mutex, bool *value)
{
    bool ret;

	pthread_mutex_lock(mutex);
	ret = *value;
	pthread_mutex_unlock(mutex);
	return (ret);
}
long get_long(pthread_mutex_t *mutex, long *value)
{
	long ret;

    pthread_mutex_lock(mutex);
    ret = *value;
    pthread_mutex_unlock(mutex);
    return (ret);
}

void set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);
}
