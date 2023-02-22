/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sniffer_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:06:51 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/22 13:05:04 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_time_die(t_table *table)
{
	//int	count;
	//struct timeval	t_stop;

	(void)table;
	/*count = 0;
	gettimeofday(&t_stop, NULL);
	while (table->info->max_eat > count)
	{
		if ((t_stop.tv_usec - table->stats[count]->t_last_eat.tv_usec) > table->info->t_die * 1000)
			return (0);
	}*/
	return (1);
}

static void destroy_philo(t_table *table)
{
	int	count;
	
}

void sniffer_philo(t_table *table)
{
	int	i;

	printf("\n\tStart snifer\n");
	while (1)
	{
		i = -1;
		if (check_time_die(table) != 1)
		{
			printf("\nDIE\n");
		}
		else if (table->end == 1)
		{
			printf("\nFIN de commer\n");
			break ;
		}
	}
}
