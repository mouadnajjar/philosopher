/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:33:45 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 16:29:17 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_status	status;
	pthread_t	monitoring;

	if (ac != 5 && ac != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	memset(&status, 0, sizeof(t_status));
	status.time_start = get_time_in_ms();
	if (parse_args(ac, av, &status))
		return (1);
	init_philosophers(&status);
	if (create_philos(&status))
		return (1);
	if (pthread_create(&monitoring, NULL, &monitor, &status) != 0)
		return (1);
	pthread_join(monitoring, NULL);
	if (join_threads(&status))
		return (1);
	free_element(&status);
	return (0);
}
