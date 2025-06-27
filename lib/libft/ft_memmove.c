/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jianisong <jianisong@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/13 14:37:39 by jianisong     #+#    #+#                 */
/*   Updated: 2024/10/16 21:37:56 by jianisong     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cast_dest;
	const char	*cast_src;

	cast_dest = (char *)dest;
	cast_src = (const char *)src;
	i = 0;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (i < n)
		{
			cast_dest[n - 1 - i] = cast_src[n - 1 - i];
			i++;
		}
	}
	return (dest);
}
