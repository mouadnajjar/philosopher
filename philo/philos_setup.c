/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:17:36 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 16:24:21 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philosophers(t_status *status)
{
	int	i;

	status->philos = malloc(sizeof(t_philo) * status->n_philo);
	status->forks = malloc(sizeof(pthread_mutex_t) * status->n_philo);
	if (!status->forks || !status->philos)
		return (1);
	pthread_mutex_init(&status->print_lock, NULL);
	pthread_mutex_init(&status->stop_mutex, NULL);
	i = 0;
	while (i < status->n_philo)
	{
		pthread_mutex_init(&status->forks[i], NULL);
		i++;
	}
	i = 0;
	init_data(status, i);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->status->n_philo == 1)
	{
		set_one(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		precise_usleep(philo->status->eat_time);
	set_all(philo);
	return (NULL);
}

int	create_philos(t_status	*status)
{
	int	i;

	i = 0;
	while (i < status->n_philo)
	{
		if (pthread_create(&status->philos[i].thread, NULL,
				&philo_routine, &status->philos[i]) != 0)
		{
			printf("Error creating thread %d\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}
