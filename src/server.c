/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:13:07 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/03 16:00:01 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	display_banner(int pid)
{
	printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n", GREEN, END);
	printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s \n", GREEN, END);
	printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s \n", GREEN, END);
	printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n", GREEN, END);
	printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n", GREEN, END);
	printf("%s\n\t\tPID: %d%s\t\t\t%sBy: soelalou%s\n", RED, pid, END,
		BLUE, END);
	printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

void	print(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("%s[ERROR]%s Invalid format\n%s->%s \
./server", RED, END, GREEN, END);
		return (0);
	}
	pid = getpid();
	display_banner(pid);
	while (ac == 1)
	{
		signal(SIGUSR1, print);
		signal(SIGUSR2, print);
		pause();
	}
	return (0);
}
