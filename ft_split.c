/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:33:01 by hchair            #+#    #+#             */
/*   Updated: 2024/07/04 07:07:12 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	word_count(char **s, char c)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		while (**s)
		{
			if (**s != c && !in_word)
			{
				in_word = 1;
				count++;
			}
			else if (**s == c)
			{
				in_word = 0;
			}
			*(s++);
		}
		s++;
	}
	return (count);
}

static	char	*malloc_word(char *s, char c)
{
	char	*start;
	char	*word;
	int		i;

	start = (char *)s;
	i = 0;
	while (*s && *s != c) 
	{
		s++;
	}
	word = (char *)malloc(s - start + 1);
	if (!word)
		return (NULL);
	while (start < s)
	{
		word[i++] = *start++;
	}
	word[i] = '\0';
	return (word);
}

static	void	ft_free(char **split, int i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
}

static	char	**splita(char *s, char **split, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			split[i] = malloc_word(s, c);
			if (!split[i])
			{
				ft_free(split, i);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char **s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!split)
		return (NULL);
	split = splita(*s, split, c);
	return (split);
}
