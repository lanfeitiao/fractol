/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/14 10:03:28 by jsong         #+#    #+#                 */
/*   Updated: 2024/10/16 15:05:49 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	size_t			str_len;
	size_t			substr_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		substr_len = 0;
	else if (start + len >= str_len)
		substr_len = str_len - start;
	else
		substr_len = len;
	substring = malloc(substr_len + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (substr_len > 0 && s[start + i] && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
