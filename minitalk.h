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

#ifndef _MINITALK_H
# define _MINITALK_H

#define ABIT 500
#include    <signal.h>
#include    <stdio.h>
#include    <unistd.h>
#include    <stdlib.h>
#include    "libft.c"

int	ft_isdigit(int c);
int	ft_atoi(char *nptr);
int	ft_strlen(char *s);

#endif
