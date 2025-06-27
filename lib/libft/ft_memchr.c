/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jianisong <jianisong@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/13 15:24:44 by jianisong     #+#    #+#                 */
/*   Updated: 2024/10/13 15:32:19 by jianisong     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*cast_s;
	size_t		i;

	i = 0;
	cast_s = (const char *)s;
	while (i < n)
	{
		if (cast_s[i] == (char)c)
			return ((void *)(cast_s + i));
		i++;
	}
	return (NULL);
}
