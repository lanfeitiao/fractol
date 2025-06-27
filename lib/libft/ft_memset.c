/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 10:31:51 by jsong         #+#    #+#                 */
/*   Updated: 2024/10/11 14:36:28 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	byte;
	char			*cast_s;
	size_t			i;

	byte = (unsigned char)c;
	cast_s = (char *)s;
	i = 0;
	while (i < n)
	{
		cast_s[i] = byte;
		i++;
	}
	return (s);
}
