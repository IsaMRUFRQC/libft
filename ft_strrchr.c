/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:45:22 by iduval            #+#    #+#             */
/*   Updated: 2022/01/26 11:58:07 by iduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i--;
	}
	if ((char)c == str[0])
		return ((char *)str);
	return (NULL);
}
