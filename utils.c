/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 01:54:20 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/02 04:39:59 by mucelep          ###   ########.fr       */
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
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	is_valid(char *number)
{
	
	if (*number == '+' || *number == '-')
		number++;
	if (!*number)
		return (0);
	while (*number)
	{
		if (*number < '0' || *number > '9')
			return (0);
		number++;
	}
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

void	*ft_memcpy(void *dest, const void *src, size_t n)// split için
{
	size_t	i;

	i = 0;
	if (!dest || !src || n == 0)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
t_list	*new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}
void	error(t_stack *stacks, char **split)
{
	if (split)
		free_split(split);
	if (stacks)
	{
		free_list(stacks->a);
		free_list(stacks->b);
		free(stacks);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	is_duplicate(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		
		lst = lst->next;
	}
	return (0);
}

void	give_index(t_list *a)
{
	int	index;

	index = 0;
	while (a)
	{
		a->index = index;
		index++;
		a = a->next;
	}
}

int is_order(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	cleanup(t_stack *stacks, char **split)
{
	free_split(split);
	free_list(stacks->a);
	free_list(stacks->b);
	free(stacks);
}