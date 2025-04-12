/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:55:31 by sel-khao          #+#    #+#             */
/*   Updated: 2025/04/12 15:12:01 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
# include "./libft/libft.h"

typedef struct s_lista
{
	int				index;
	int				num;
	struct s_lista	*next;
}		t_ps;

t_ps	*fft_lstnew(int num);
t_ps	*fft_lstlast(t_ps *lst);
int		fft_lstsize(t_ps *head);
void	fft_lstclear(t_ps **lst);
long	fft_atoi(const char *nptr);
void	fft_lstadd_back(t_ps **lst, t_ps *new);

void	ft_sa(t_ps **stack_a, int i);
void	ft_sb(t_ps **stack_b, int i);
void	ft_ss(t_ps **stack_b, t_ps **stack_a);
void	ft_ra(t_ps **stack_a, int i);
void	ft_rb(t_ps **stack_b, int i);
void	ft_rr(t_ps **stack_b, t_ps **stack_a);
void	ft_rra(t_ps **stack_a, int i);
void	ft_rrb(t_ps **stack_b, int i);
void	ft_rrr(t_ps **stack_b, t_ps **stack_a);
void	ft_pa(t_ps **stack_b, t_ps **stack_a);
void	ft_pb(t_ps **stack_b, t_ps **stack_a);

int		are_num(char *arg);
void	three_args(t_ps **a);
char	**split_arg(char **av);
void	two_sort(t_ps **stack);
int		two_args(t_ps **stack_a, char **argv);
int		more_args(t_ps **stack_a, char **argv, int argc);
void	radix_sort(t_ps **stack_a, t_ps **stack_b);
void	five_algo(t_ps **stack_a, t_ps **stack_b);

int		max_len(int max);
int		is_sorted(t_ps *a);
void	free_mat(char **mat);
int		vali_two(char *argv[]);
int		check_two(char **argv);
void	set_index(t_ps **stack);
int		checkdup(int ac, char **argv);
int		vali_num(int ac, char *argv[]);
int 	find_min_position(t_ps *stack);
int		find_max_position(t_ps *stack);

#endif
