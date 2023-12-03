/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:16:29 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/03 17:25:53 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("%s[ERROR]%s Invalid format\n%s->%s \
./client_bonus <PID> <message>\n", RED, END, GREEN, END);
		return (-1);
	}
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i++]))
		{
			ft_printf("%s[ERROR]%s The PID provided is not number\n%s->%s \
./client_bonus <PID> <message>\n", RED, END, GREEN, END);
			return (-1);
		}
	}
	if (*(av[2]) == '\0')
	{
		ft_printf("%s[ERROR]%s The message provided is empty\n%s->%s \
./client_bonus <PID> <message>\n", RED, END, GREEN, END);
			return (-1);
	}
	return (1);
}

void	send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (check(ac, av) == -1)
		return (1);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send_bits(pid, av[2][i]);
		i++;
	}
	send_bits(pid, '\n');
	return (0);
}
