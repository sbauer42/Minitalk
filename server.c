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
NEVER USE PRINTF IN A SIGNAL HANDLER PROGRAMM */

void    custom_handler(int signal, siginfo_t *siginfo, void *unused)
{
    static  int bit = 1;
    static  int save = 0;
    static  char c = 0;

    (void)unused;
    (void)siginfo;
    if(signal == SIGUSR1)
    {
        save = save + bit;
        c = save;
    }
    bit = bit * 2;
    if(bit > 128)
    {
        write(1,&c,1);
        bit = 1;
        c = 0;
        save = 0;
    }
}

int main(int ac, char **av)
{
    int pid;
    struct sigaction    sig;

    pid = getpid();
    write(1,"PID == ",7);
    ft_putnbr_fd(pid, 1);
    write(1,"\n",1);
    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = custom_handler;
    if ((sigaction(SIGUSR1, &sig, 0)) == -1)
        return (-1);
    if ((sigaction(SIGUSR2, &sig, 0)) == -1)
        return (-1);
    while(1)
    {
        pause();
    }
    return (0);
}