/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:06:12 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 16:39:19 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_num(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_numeric(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_time(t_status *status)
{
	if (status->die_time < MIN_TIME || status->eat_time < MIN_TIME
		|| status->sleep_time < MIN_TIME)
		return (0);
	return (1);
}

int	check_args(t_status *status)
{
	if (status->n_philo <= 0 || status->die_time <= 0
		|| status->eat_time <= 0 || status->sleep_time <= 0
		|| (status->eat_flag && status->times_must_eat <= 0))
		return (1);
	return (0);
}

int	parse_args(int ac, char **av, t_status *status)
{
	if (!check_num(ac, av))
	{
		printf("Error: Invalid argument\n");
		return (1);
	}
	init_var(status, av);
	if (ac == 6)
	{
		status->times_must_eat = atoi(av[5]);
		status->eat_flag = 1;
	}
	else
		status->eat_flag = 0;
	if (check_args(status))
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	if (!check_time(status))
	{
		printf("The timing value must be at least %d ms\n", MIN_TIME);
		return (1);
	}
	return (0);
}
