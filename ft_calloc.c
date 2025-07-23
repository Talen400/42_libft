/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:12:09 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/23 14:36:32 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	lsize;

	lsize = nmemb * size;
	if (nmemb && size != lsize / nmemb)
		return (NULL);
	ptr = malloc(lsize);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, lsize);
	return (ptr);
}
