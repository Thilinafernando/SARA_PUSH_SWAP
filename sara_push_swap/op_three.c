/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:24:28 by sel-khao          #+#    #+#             */
/*   Updated: 2025/04/12 14:42:21 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_ps **stack_b, int i)
{
	t_ps	*tmp;
	t_ps	*last;

	tmp = *stack_b;
	last = *stack_b;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	*stack_b = (*stack_b)->next;
	while (last && last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	if (i == 1)
		write (1, "rb\n", 3);
}

void	ft_ra(t_ps **stack_a, int i)
{
	t_ps	*tmp;
	t_ps	*last;

	tmp = *stack_a;
	last = *stack_a;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	return ;
	*stack_a = (*stack_a)->next;
	while (last && last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	if (i == 1)
		write (1, "ra\n", 3);
}

void	ft_rr(t_ps **stack_b, t_ps **stack_a)
{
	if (*stack_b && (*stack_b)->next)
		ft_rb(stack_b, 0);
	if (*stack_a && (*stack_a)->next)
		ft_ra(stack_a, 0);
	write(1, "rr\n", 3);
}

int	find_min_position(t_ps *stack)
{
	t_ps	*tmp;
	int		min;
	int		min_pos;
	int		current_pos;

	if (!stack)
		return (-1);
	tmp = stack;
	min = tmp->num;
	min_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->num < min)
		{
			min = tmp->num;
			min_pos = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return (min_pos);
}
