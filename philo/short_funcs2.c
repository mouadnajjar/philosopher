/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:45:01 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 17:43:59 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_status *status, int i)
{
	while (i < status->n_philo)
	{
		status->philos[i].id = i;
		status->philos[i].meals_eaten = 0;
		status->philos[i].last_meal = status->time_start;
		status->philos[i].status = status;
		status->philos[i].is_full = 0;
		status->philos[i].right_fork = &status->forks[(i + 1)
			% status->n_philo];
		pthread_mutex_init(&status->philos[i].meal_protect, NULL);
		status->philos[i].left_fork = &status->forks[i];
		i++;
	}
}

int	dying_come(t_status *status, long long now, t_philo *philo)
{
	if ((now - philo->last_meal) > status->die_time)
	{
		pthread_mutex_lock(&status->print_lock);
		if (!get_stop(status))
			printf("%lld %d died \n", now - status->time_start, philo->id + 1);
		set_stop(status);
		pthread_mutex_unlock(&status->print_lock);
		return (1);
	}
	return (0);
}

int	everyone_eat(t_status *status, int full)
{
	if (status->eat_flag && full == status->n_philo)
	{
		pthread_mutex_lock(&status->print_lock);
		set_stop(status);
		printf("all philosophers has eating enough %d", full);
		pthread_mutex_unlock(&status->print_lock);
		return (1);
	}
	return (0);
}
