/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:37:07 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/13 22:28:56 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_count;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	t_count	count;
	int		bench;
	int		flag;
	int		flagset;
}	t_stack;

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_split(char **split);

void	error(t_stack *stacks, char **split);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
t_list	*new_node(int value);

long	ft_atol(const char *nptr);
int		is_valid(char *number);
int		is_duplicate(t_list *lst);

void	give_index(t_list *a);
int		is_order(t_list *a);
void	cleanup(t_stack *stacks, char **split);
int		ft_strcmp(const char *s1, const char *s2);

void	init_counts(t_stack *stk);
void	parse_flag(t_stack *stacks, char *argv, char **split);
float	disorder(t_list *head);
void	strategy_selector(t_stack *stacks);

void	sa(t_stack *stk);
void	sb(t_stack *stk);
void	ss(t_stack *stk);
void	pa(t_stack *stk);
void	pb(t_stack *stk);
void	ra(t_stack *stk);
void	rb(t_stack *stk);
void	rr(t_stack *stk);
void	rra(t_stack *stk);
void	rrb(t_stack *stk);
void	rrr(t_stack *stk);

#endif