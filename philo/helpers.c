/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:08:47 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 16:40:56 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	write(2, "Error\n", 7);
	exit (1);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	res = 0;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (INT_MAX - (str[i] - '0')) / 10)
			ft_error();
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

void	free_element(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->n_philo)
	{
		pthread_mutex_destroy(&status->forks[i]);
		pthread_mutex_destroy(&status->philos[i].meal_protect);
		i++;
	}
	pthread_mutex_destroy(&status->stop_mutex);
	pthread_mutex_destroy(&status->print_lock);
	if (status->philos)
		free(status->philos);
	if (status->forks)
		free(status->forks);
}

int	join_threads(t_status	*status)
{
	int	i;

	i = 0;
	while (i < status->n_philo)
	{
		if (pthread_join(status->philos[i].thread, NULL) != 0)
		{
			printf("Error : failed to join the thread : %d!\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}
