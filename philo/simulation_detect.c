/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_detect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:49:52 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 18:09:27 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor_check(t_status *status, int *full)
{
	int			i;
	long long	now;
	t_philo		*philo;

	i = 0;
	while (i < status->n_philo)
	{
		now = get_time_in_ms();
		philo = &status->philos[i];
		pthread_mutex_lock(&philo->meal_protect);
		if (dying_come(status, now, philo))
		{
			pthread_mutex_unlock(&philo->meal_protect);
			return (1);
		}
		if (status->eat_flag && !philo->is_full
			&& philo->meals_eaten >= status->times_must_eat)
		{
			philo->is_full = 1;
			(*full)++;
		}
		pthread_mutex_unlock(&philo->meal_protect);
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_status	*status;
	int			full;

	status = (t_status *)arg;
	full = 0;
	while (!get_stop(status))
	{
		if (monitor_check(status, &full))
			return (NULL);
		if (everyone_eat(status, full))
			return (NULL);
		precise_usleep(50);
	}
	return (NULL);
}
