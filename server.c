/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 21:37:59 by caniseed          #+#    #+#             */
/*   Updated: 2021/08/10 21:53:46 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_message(int signal)
{
	static int	symbol;
	static int	j;
	static int	i;

	if (j == 0)
		j = 128;
	if (signal == SIGUSR1)
		j /= 2, i++;
	else if (signal == SIGUSR2)
	{
		symbol += j;
		j /= 2;
		i++;
	}
	if (i == 8)
	{
		if (symbol != 0)
			write(1, &symbol, 1);
		else
			write(1, "\n", 1);
		i = 0;
		j = 0;
		symbol = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Server is up and running! PID is ");
	ft_putnbr(pid);
	ft_putstr(".\n");
	while (1)
	{
		signal(SIGUSR2, print_message);
		signal(SIGUSR1, print_message);
		pause();
	}
}
