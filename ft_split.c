/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:33:01 by hchair            #+#    #+#             */
/*   Updated: 2024/07/05 11:03:51 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	word_count(char **s, char c)
{
	int	count;
	int	in_word;
    int j;
    int i;
	
	in_word = 0;
	count = 0;
	i = 0;
    while (s[i])
	{
        j = 0;
        while (s[i][j])
        {
            while (s[i][j] == c)
	    	    j++;
    		if (s[i])
    			count++;
    		while (s[i][j] && s[i][j] != c)
    			j++;
        }
        i++;
	}
	count--;
	ft_printf("this is word count %d\n", count);
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

static	char	**splita(char **s, char **split, char c)
{
	int	i;
	int	j;
	char **s_ptr;

	i = 0;
	s_ptr = s;
	while (*s_ptr)
	{
	    j = 0;
		if (*s_ptr && **s_ptr != c)
		{
			split[i] = malloc_word(*s_ptr, c);
			if (!split[i])
			{
				ft_free(split, i);
				return (NULL);
			}
			i++;
			while (**s_ptr && **s_ptr != c)
				s_ptr++;
		}
		else
			s_ptr++;
		s_ptr++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char **s, char c)
{
	char	**split;

	if (!s || !*s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!split)
		return (NULL);
	split = splita(s, split, c);
	return (split);
}
