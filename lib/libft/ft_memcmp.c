/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jianisong <jianisong@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/13 16:48:20 by jianisong     #+#    #+#                 */
/*   Updated: 2024/10/13 16:58:01 by jianisong     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*cast_s1;
	const char	*cast_s2;

	cast_s1 = (const char *)s1;
	cast_s2 = (const char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (cast_s1[i] == cast_s2[i] && i < n - 1)
		i++;
	return ((unsigned char)cast_s1[i] - (unsigned char)cast_s2[i]);
}
