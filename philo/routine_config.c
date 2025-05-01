/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:53:45 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 16:48:57 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

long long	get_elpased_t(long long start)
{
	return (get_time_in_ms() - start);
}

void	precise_usleep(long long ms)
{
	long long	start;

	start = get_time_in_ms();
	while ((get_time_in_ms() - start) < ms)
		usleep(100);
}

void	print_status(t_philo *philo, char *msg)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->status->print_lock);
	if (get_stop(philo->status))
	{
		pthread_mutex_unlock(&philo->status->print_lock);
		return ;
	}
	timestamp = get_time_in_ms() - philo->status->time_start;
	printf("%lld %d %s\n", timestamp, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->status->print_lock);
}
