/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_0.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/03/31 01:54:20 by username         #+#    #+#              */
/*   Updated: 2026/05/07 02:49:24 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char) * s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) s);
	return (NULL);
}

int	is_valid(char *number) //geçerli bir sayi mi
{
	int	len;

	len = 0;
	if (!*number) //"" " " bos string için
		return (0);
	if (*number == '+' || *number == '-')
		number++;
	if (!*number) // + veya - den sonra sayı yoksa diye kontrol
		return (0);
	while (*number)
	{
		if (*number < '0' || *number > '9')
			return (0);
		len++;
		number++;
	}
	if (len > 10)
		return (0);
	return (1);
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	s;
	long	r;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	s = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	r = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n) // split için
{
	size_t	i;

	i = 0;
	if (!dest || !src || n == 0)
		return (dest);
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((const unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
