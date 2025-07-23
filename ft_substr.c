/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:17:14 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/23 16:10:25 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*str;
	unsigned int	len_sub;
	unsigned int	len_s;

	if (!s)
		return (NULL);
	str = (char *) s;
	len_s = ft_strlen(str);
	if (start >= len_s)
		return (ft_strdup(""));
	len_sub = len_s - start;
	if (len_sub > len)
		len_sub = len;
	sub = malloc ((len_sub + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, str + start, len_sub + 1);
	return (sub);
}
