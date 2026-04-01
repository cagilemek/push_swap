/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:37:07 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/02 02:58:04 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>

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
	int total;
}	t_count;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	t_count	count;
}	t_stack;

void	ft_lstadd_back(t_list **lst, t_list *new);

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);

int		is_valid(char *number);

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
