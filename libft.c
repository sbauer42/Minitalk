/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 23:39:21 by Sbauer            #+#    #+#             */
/*   Updated: 2020/11/24 10:44:20 by sbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -9 || n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0)
	{
		if (n >= -9)
			ft_putchar_fd('-', fd);
		ft_putchar_fd('0' - (n % 10), fd);
	}
	else
		ft_putchar_fd('0' + (n % 10), fd);
}

int	ft_atoi(char *nptr)
{
	long long int	i;
	long long int	r;
	long long int	n;

	i = 0;
	r = 0;
	n = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\r'
			|| nptr[i] == '\t' || nptr[i] == '\f' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-')
		n = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		r *= 10;
		r += nptr[i] - '0';
		i++;
	}
	return(r * n);
}

int	ft_strlen(char *s)
{
	int x;

	x = 0;
	while (s[x])
	{
		x++;
	}
	return (x);
}
