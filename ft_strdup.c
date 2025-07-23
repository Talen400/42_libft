/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:44:14 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/23 15:03:08 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ptr;

	ptr = (char *) s;
	str = malloc((ft_strlen(ptr) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, ptr, ft_strlen(ptr) + 1);
	return (str);
}
