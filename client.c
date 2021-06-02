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
#include	"minitalk.h"
int	CharTransmit(int c, int pid)
{
	int i;
	
	i = 8;
    while(i)
    {
        if(c & 0x01 == 1)
        {
            if(kill(pid, SIGUSR1) == -1)
                return (-1);
            usleep(TIME);
        }
        else
        {
            if(kill(pid, SIGUSR2) == -1)
                return (-1);
            usleep(TIME);
        }
        c = c >> 1;
        i--;
    }
    return (0);
}

int CheckPid(char *str)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(str);

    while(i < len)
    {
        if(ft_isdigit(str[i]))
            i++;
        else
            return -1;
    }
    return(0);
}

int main(int ac, char **av)
{
    int	pid;
    int	i;

    i = 0;
    if (ac != 3 || CheckPid (av[1]) == -1)
        return (-1);
    pid = ft_atoi(av[1]);
    while(av[2][i])
    {
		if (CharTransmit (av[2][i], pid) == -1)
			return (-1);
		i++;
	}
	if (CharTransmit ('\n', pid) == -1)
		return (-1);
	return (0);
}
