/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 02:50:03 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/02 02:50:11 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	wrd_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*copy_word(char const *s, char c)
{
	size_t		len;
	char		*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static char	**free_all(char **r, int j)
{
	while (j--)
		free(r[j]);
	free(r);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		j;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (wrd_count(s, c) + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[j] = copy_word(s, c);
			if (!result[j])
				return (free_all(result, j));
			j++;
		}
		while (*s && *s != c)
			s++;
	}
	result[j] = NULL;
	return (result);
}