/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:37:07 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/28 14:54:38 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int value;
	int index;
	struct s_list *next;
} t_list;

typedef struct s_count
{
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	int total;
} t_count;

typedef struct s_stack
{
	t_list *a;
	t_list *b;
	t_count count;
	float disorder; // karışıklık ornaını tutuyor ör. 0.42
	int bench;
	int flag;
	int flagset; // birden fazla flag girilmesin diye
} t_stack;

void *ft_memcpy(void *dest, const void *src, size_t n);
void ft_lstadd_back(t_list **lst, t_list *new);
void free_split(char **split);

void error(t_stack *stacks, char **split);
char **ft_split(char const *s, char c);
char *ft_strchr(const char *s, int c);
t_list *new_node(int value);

long ft_atol(const char *nptr);
int is_valid(char *number);
int is_duplicate(t_list *lst);

void give_index(t_list *a);
int is_order(t_list *a);
int cleanup(t_stack *stacks, char **split);
int ft_strcmp(const char *s1, const char *s2);

void init_counts(t_stack *stk);
void parse_flag(t_stack *stacks, char *argv, char **split);
float disorder(t_list *head);
void strategy_selector(t_stack *stacks);
void fin_min_index_pos(t_list *a, int *min_index, int *min_pos);

// chunk base
void chunk_base(t_stack *stk);
int push_chunk(t_stack *stk, int stack_size, int chunk_size);
void pull_chunk(t_stack *stk, int stack_size, int chunk_size, int last_chunk);
int calculate_stack_size(t_list *stack);
int calculate_chunk_size(int stack_size);
int find_max_index_pos(t_list *b, int max_index);
void smart_rotate(t_stack *stk, int max_index);

void	bench_press(t_stack *s, float f);
void	disorder_to_integer(int *integer, float f, int *decimal);
void	putstr_fd(char *str, int fd);
void	putnbr_fd(int n, int fd);
void	write_disorder(int integer, int decimal);
void	write_total(int total);
void	write_sa(t_stack *a);
void	write_ra(t_stack *a);

void sa(t_stack *stk);
void sb(t_stack *stk);
void ss(t_stack *stk);
void pa(t_stack *stk);
void pb(t_stack *stk);
void ra(t_stack *stk);
void rb(t_stack *stk);
void rr(t_stack *stk);
void rra(t_stack *stk);
void rrb(t_stack *stk);
void rrr(t_stack *stk);

#endif