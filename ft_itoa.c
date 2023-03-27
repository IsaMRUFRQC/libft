/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:50:13 by iduval            #+#    #+#             */
/*   Updated: 2022/01/26 12:56:17 by iduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_len(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char			*str;
	size_t			int_len;
	unsigned int	nbr;

	int_len = ft_int_len(nb);
	str = (char *)malloc(sizeof(char) * (int_len + 1));
	if (!str)
		return (NULL);
	str[int_len] = '\0';
	if (!nb)
		str[0] = '0';
	if (nb < 0)
	{
		nbr = (-1) * nb;
		str[0] = '-';
	}
	else
		nbr = nb;
	while (nbr > 0)
	{
		str[int_len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		int_len --;
	}
	return (str);
}
