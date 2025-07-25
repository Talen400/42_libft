/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:19:33 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/25 20:12:08 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		count++;
	}
	return (count);
}

static char	*ft_sub_ma(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**str;

	len = ft_count_words(s, c);
	str = malloc((len + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	while (*s && i < len)
	{
		while (*s == c)
			s++;
		str[i] = ft_sub_ma(s, c);
		if (!str[i])
		{
			while (--i >= 0)
				free(str[i]);
			free(str);
			return (NULL);
		}
		s += ft_strlen(str[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
