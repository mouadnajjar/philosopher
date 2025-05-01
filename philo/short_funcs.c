/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:36:17 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 17:41:45 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_var(t_status *status, char **av)
{
	status->n_philo = ft_atoi(av[1]);
	status->die_time = ft_atoi(av[2]);
	status->eat_time = ft_atoi(av[3]);
	status->sleep_time = ft_atoi(av[4]);
}

void	set_stop(t_status *status)
{
	pthread_mutex_lock(&status->stop_mutex);
	status->stop = 1;
	pthread_mutex_unlock(&status->stop_mutex);
}

int	get_stop(t_status *status)
{
	int	value;

	pthread_mutex_lock(&status->stop_mutex);
	value = status->stop;
	pthread_mutex_unlock(&status->stop_mutex);
	return (value);
}

void	set_one(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	while (!get_stop(philo->status))
		usleep(100);
	pthread_mutex_unlock(philo->left_fork);
}

void	set_all(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_protect);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_protect);
	while (!get_stop(philo->status))
	{
		take_forks(philo);
		if (get_stop(philo->status))
		{
			put_forks(philo);
			break ;
		}
		eat(philo);
		if (get_stop(philo->status))
		{
			put_forks(philo);
			break ;
		}
		put_forks(philo);
		sleep_philo(philo);
		think(philo);
		if (get_stop(philo->status))
			break ;
	}
}
