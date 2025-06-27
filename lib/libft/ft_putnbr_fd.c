/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 11:24:35 by jsong         #+#    #+#                 */
/*   Updated: 2024/10/18 12:09:13 by jianisong     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_positive(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == INT_MIN)
		{
			ft_putnbr_positive(-(n / 10), fd);
			ft_putnbr_positive(-(n % 10), fd);
		}
		else
			ft_putnbr_positive(-n, fd);
	}
	else
	{
		ft_putnbr_positive(n, fd);
	}
}

static void	ft_putnbr_positive(int n, int fd)
{
	int	head;
	int	tail;

	head = n / 10;
	tail = n % 10;
	if (head == 0)
		ft_putchar_fd(tail + '0', fd);
	else
	{
		ft_putnbr_positive(head, fd);
		ft_putchar_fd(tail + '0', fd);
	}
}
