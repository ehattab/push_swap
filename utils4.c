/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:36:12 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/13 14:52:26 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] != NULL)
		{
			free(res[i]);
			res[i] = NULL;
		}
		i++;
	}
	if (res != NULL)
	{
		free(res);
		res = NULL;
	}
}

int	ft_count_word2(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

int	ft_cpy2(char **res, const char *s, char c)
{
	int	len;
	int	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			res[i] = malloc(len + 1);
			if (!res[i])
				return (0);
			ft_strlcpy(res[i], s, len + 1);
			s += len;
			i++;
		}
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split2(char const *s, char c)
{
	int		mots;
	char	**res;

	if (!s)
		return (NULL);
	mots = ft_count_word2(s, c);
	res = malloc(sizeof(char *) * (mots + 1));
	if (!res)
		return (NULL);
	if (!ft_cpy2(res, s, c))
	{
		ft_free_tab(res);
		return (NULL);
	}
	return (res);
}
