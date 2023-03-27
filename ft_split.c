/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:38:42 by iduval            #+#    #+#             */
/*   Updated: 2022/01/26 13:44:08 by iduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	nb;

	nb = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			nb++;
			while (*s != c && *s)
				s++;
		}
	}
	return (nb);
}

static char	*ft_wordcopy(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	*copy;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	while (j < i)
	{
		copy[j] = s[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	size_t	tab_index;
	char	**tab;

	tab_index = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			tab[tab_index++] = ft_wordcopy(s, c);
			if (!tab[tab_index - 1])
			{
				ft_malloc_error(tab);
				return (NULL);
			}
			s = s + ft_strlen(tab[tab_index -1]);
		}
	}
	tab[tab_index] = NULL;
	return (tab);
}
