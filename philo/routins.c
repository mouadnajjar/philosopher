/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:10:21 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 17:24:47 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo	*philo)
{
	print_status(philo, "is thinking");
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	first_fork = philo->right_fork;
	second_fork = philo->left_fork;
	pthread_mutex_lock(first_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);
	print_status(philo, "has taken a fork");
}

void	eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->meal_protect);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_protect);
	print_status(philo, "is eating");
	precise_usleep(philo->status->eat_time);
	pthread_mutex_lock(&philo->meal_protect);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_protect);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_philo(t_philo	*philo)
{
	print_status(philo, "is sleeping");
	precise_usleep(philo->status->sleep_time);
}
