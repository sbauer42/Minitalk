/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:29:25 by sbauer            #+#    #+#             */
/*   Updated: 2020/12/01 15:41:12 by sbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "minitalk.h"
/* SIGURS1 == 1 --- SIGURS2 == 0
NEVER USE PRINTF OR MALLOC IN A SIGNAL HANDLER PROGRAMM */
char	g_str[SIZE];

void	custom_handler(int signal)
{
	static int		bit = 1;
	static int		len = 0;
	static char	 	c = 0;

	if (signal == SIGUSR1)
	{
		c = c | bit;
	}
	bit = bit << 1;
	if (bit > 128)
	{
		g_str[len] = c;
		len++;
		if ((int)c == 0 || c == '\n')
		{
			write(1, g_str, len);
			len = 0;
			g_str[len] = c;
		}
		bit = 1;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	write(1, "PID == ", 7);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, custom_handler);
	signal(SIGUSR2, custom_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
