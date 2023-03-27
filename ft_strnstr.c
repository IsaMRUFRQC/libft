/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:57:44 by iduval            #+#    #+#             */
/*   Updated: 2022/01/26 12:05:40 by iduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *fullstr, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!substr[i])
		return ((char *)fullstr + i);
	while (fullstr[i])
	{
		j = 0;
		while (substr[j] && fullstr[i + j] == substr[j] && (i + j) < len)
		{
			j++;
			if (!substr[j])
				return ((char *)fullstr + i);
		}
		i++;
	}
	return (NULL);
}
