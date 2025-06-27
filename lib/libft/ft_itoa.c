/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/14 13:32:46 by jsong         #+#    #+#                 */
/*   Updated: 2024/10/16 17:12:36 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_nbr_len(int n);
static void	ft_fill_nbr(char *res, int n, int nbr_len);

char	*ft_itoa(int n)
{
	char	*res;
	int		nbr_len;

	nbr_len = ft_count_nbr_len(n);
	res = malloc(nbr_len);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		ft_fill_nbr(&res[1], n, nbr_len - 1);
	}
	else
		ft_fill_nbr(res, -n, nbr_len);
	return (res);
}

static int	ft_count_nbr_len(int n)
{
	int	nbr_len;

	if (n < 0)
		nbr_len = 3;
	else
		nbr_len = 2;
	while (n / 10)
	{
		nbr_len++;
		n = n / 10;
	}
	return (nbr_len);
}

static void	ft_fill_nbr(char *res, int n, int nbr_len)
{
	int	i;

	i = nbr_len - 1;
	res[i] = '\0';
	i--;
	while (i >= 0)
	{
		res[i] = -(n % 10) + '0';
		n = n / 10;
		i--;
	}
}
