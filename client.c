/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:31:07 by caniseed          #+#    #+#             */
/*   Updated: 2021/08/11 22:08:57 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 128;
		while (j != 0)
		{
			usleep(100);
			if (str[i] & j)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j /= 2;
		}
		if (str[i] == '\0')
		{
			ft_putstr("Message was sent to server!\n");
			break ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
		ft_putstr("Usage: ./client [PID] [message]\n");
	else
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
}
