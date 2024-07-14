/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:01:45 by sandre-a          #+#    #+#             */
/*   Updated: 2024/07/13 20:49:35 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
    t_data  table;

	if (argc == 5 || argc == 6)
        check_input(argv, &table);
	else
		error("Invalid number of arguments passed");
	return (0);
}

int	error(char *error)
{
	ft_printf(RED "❌-%s-❌\n" RST, error);
    return (1);
}