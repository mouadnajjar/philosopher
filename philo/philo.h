/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:24:39 by monajjar          #+#    #+#             */
/*   Updated: 2025/04/27 16:28:54 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
//--------------------Includes---------------------//
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
//-------------------------------------------------//

//--------------------Macros---------------------//
# ifndef MIN_TIME
#  define MIN_TIME 60
# endif
//-----------------------------------------------//

//--------------------Structers--------------------//
typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				is_full;
	long long		last_meal;
	pthread_t		thread;
	struct s_status	*status;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	meal_protect;
}				t_philo;

typedef struct s_status
{
	int				n_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				times_must_eat;
	int				eat_flag;
	int				stop;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	long long		time_start;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_mutex;
}		t_status;
//------------------------------------------------//

//---------------helper-functions------------------//
int			ft_atoi(char *str);
void		ft_error(void);
void		free_element(t_status *status);
int			get_stop(t_status *status);
void		set_stop(t_status *status);
void		init_var(t_status *status, char **av);
void		set_one(t_philo *philo);
void		set_all(t_philo *philo);
void		init_data(t_status *status, int i);
int			dying_come(t_status *status, long long now, t_philo *philo);
int			everyone_eat(t_status *status, int full);
//-------------------------------------------------//

//----------------simulation-----------------------//
int			init_philosophers(t_status	*status);
int			join_threads(t_status	*status);
int			create_philos(t_status	*status);
long long	get_time_in_ms(void);
void		print_status(t_philo *philo, char *msg);
void		precise_usleep(long long ms);
void		*monitor(void *arg);
//------------------------------------------------//

//----------------routins-------------------------//
void		think(t_philo	*philo);
void		take_forks(t_philo	*philo);
void		eat(t_philo	*philo);
void		put_forks(t_philo	*philo);
void		sleep_philo(t_philo	*philo);
//------------------------------------------------//
//--------------------Parsing-utils----------------//
int			parse_args(int ac, char **av, t_status *status);
//------------------------------------------------//
#endif