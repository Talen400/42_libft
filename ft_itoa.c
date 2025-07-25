/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:43:24 by tlavared          #+#    #+#             */
/*   Updated: 2025/07/25 17:17:35 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		num;
	char	*str;
	int		len;

	num = n;
	len = 0;
	while (num && len++)
		num /= 10;
	str = malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len + 1] = '\0';
	while (--len)
	{
		str[len] = n % 10;
		n /= 10;
	}
	return (str);
}
