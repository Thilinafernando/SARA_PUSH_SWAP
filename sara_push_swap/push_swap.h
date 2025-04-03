/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:55:31 by sel-khao          #+#    #+#             */
/*   Updated: 2025/04/02 18:20:03 by sara             ###   ########.fr       */
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

int		max_len(int max);
int		is_sorted(t_ps *a);
void	three_args(t_ps **a);
void	free_mat(char **mat);
t_ps	*fft_lstnew(int num);
int		vali_two(char *argv[]);
int		check_two(char **argv);
void	set_index(t_ps **stack);
t_ps	*fft_lstlast(t_ps *lst);
int 	fft_lstsize(t_ps *head);
void	fft_lstclear(t_ps **lst);
long	fft_atoi(const char *nptr);
void	ft_ra(t_ps **stack_a, int i);
void	ft_sa(t_ps **stack_a, int i);
int		checkdup(int ac, char **argv);
void	ft_rra(t_ps **stack_a, int i);
int		vali_num(int ac, char *argv[]);
int 	find_min_position(t_ps *stack);
void	ft_pa(t_ps **stack_b, t_ps **stack_a);
void	ft_pb(t_ps **stack_b, t_ps **stack_a);
void	fft_lstadd_back(t_ps **lst, t_ps *new);
void	five_algo(t_ps **stack_a, t_ps **stack_b);
void	radix_sort(t_ps **stack_a, t_ps **stack_b);
int find_max_position(t_ps *stack);
void ft_sb(t_ps **stack_b, int i);
void    two_sort(t_ps **stack);

#endif