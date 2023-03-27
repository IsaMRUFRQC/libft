/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:47:07 by iduval            #+#    #+#             */
/*   Updated: 2022/01/20 12:55:44 by iduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size > dest_len)
	{
		while (src[i] && i < (size - 1 - dest_len))
		{
			dest[i + dest_len] = src[i];
			i++;
		}
		dest[i + dest_len] = '\0';
		return (dest_len + src_len);
	}
	else
		return (size + src_len);
}
