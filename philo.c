/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:33:04 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/22 13:03:08 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	find_post(int id, int max)
{
	if (id == 0)
		return (max);
	return (id - 1);
}

static void	status_time(t_philo *philo, t_table *table, char *status, int time)
{
	(void) table;
	gettimeofday(&philo->t_end, NULL);
	usleep(time);
	printf("%06d %d %s %d\n", (philo->t_end.tv_usec - table->t_start.tv_usec) ,philo->id_philo, status, philo->n_eat);
}

void	*thread_philo(void *data)
{
	t_philo	*philo;
	t_table	*table;
	int		post;
	int		id;

	table = (t_table *)data;
	id = table->id_tmp;
	philo = table->stats[id];
	philo->id_philo = id;
	philo->n_eat = 0;
	post = find_post(philo->id_philo, table->info->n_philo);
	printf("Philo %d-%d\n", philo->id_philo, post);
	if (philo->id_philo / 2 == 0)
		usleep(40);
	//printf("%06d\n", table->t_start.tv_usec);
	philo->t_last_eat = table->t_start;
	while (table->end == 0)
	{
		pthread_mutex_lock(&table->mutex[philo->id_philo]);
		status_time(philo, table, "has taken a fork", 0);
		pthread_mutex_lock(&table->mutex[post]);
		status_time(philo, table, "has taken a fork", table->info->t_eat);
		status_time(philo, table, "is eating", table->info->t_eat);
		gettimeofday(&philo->t_last_eat, NULL);
		philo->n_eat++;
		pthread_mutex_unlock(&table->mutex[philo->id_philo]);
		pthread_mutex_unlock(&table->mutex[post]);
		status_time(philo, table, "is sleeping", table->info->t_sleep);
		status_time(philo, table, "is thinking", 0);
		if (table->info->max_eat != 0 && table->info->max_eat == philo->n_eat)
			table->end = 1;
	}
	table->end = 1;
	printf("\n \t FIN\n");
	return (NULL);
}
