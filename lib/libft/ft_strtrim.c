/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:18:58 by jsong         #+#    #+#                 */
/*   Updated: 2024/10/16 20:37:22 by jianisong     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	size_t	trimmed_len;
	char	*res;

	start_index = 0;
	end_index = ft_strlen(s1) - 1;
	while (ft_is_in_set(s1[start_index], set))
		start_index++;
	if (s1[start_index] == '\0')
		return (ft_strdup(""));
	while (end_index > start_index && ft_is_in_set(s1[end_index], set))
		end_index--;
	trimmed_len = end_index - start_index + 1;
	res = ft_substr(s1, start_index, trimmed_len);
	if (!res)
		return (NULL);
	return (res);
}

static int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
