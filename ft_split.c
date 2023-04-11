/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:48:03 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 00:08:38 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	s_cut(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (j);
}

static char	*news_copy(char *newstr, const char *s, int index, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		newstr[i] = s[index - len];
		len--;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static void	*news_split(char **newstr, char const *s, char c, int count)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (i < count)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		while (s[j] != '\0' && s[j] != c)
		{
			j++;
			len++;
		}
		newstr[i] = (char *)malloc(sizeof(char) * len + 1);
		if (!newstr[i])
			return (NULL);
		news_copy(newstr[i], s, j, len);
		i++;
		len = 0;
	}
	newstr[i] = NULL;
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	int		s_say;
	char	**newstr;

	if (s != NULL)
	{
		s_say = s_cut(s, c);
		newstr = (char **)malloc(sizeof(char *) * (s_say + 1));
		if (!newstr)
			return (NULL);
		newstr = news_split(newstr, s, c, s_say);
		return (newstr);
	}
	return (0);
}
