/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 16:11:42 by jsong         #+#    #+#                 */
/*   Updated: 2024/10/17 16:30:35 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_substr(char const *s, char c);
static char	*ft_extract_substr(char const *s, char c, char **split, int index);

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	split = malloc((ft_count_substr(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			split[i] = ft_extract_substr(s, c, split, i);
			if (!split[i])
				return (NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	split[i] = NULL;
	return (split);
}

static int	ft_count_substr(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_extract_substr(char const *s, char c, char **split, int index)
{
	size_t	substr_len;
	char	*substr;

	substr_len = 0;
	while (s[substr_len] && s[substr_len] != c)
		substr_len++;
	substr = ft_substr(s, 0, substr_len);
	if (!substr)
	{
		while (--index >= 0)
			free(split[index]);
		free(split);
		return (NULL);
	}
	return (substr);
}
