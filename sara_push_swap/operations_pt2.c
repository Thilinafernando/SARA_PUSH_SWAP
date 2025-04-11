
#include "push_swap.h"

void	ft_ss(t_ps **stack_b, t_ps **stack_a)
{
	if (*stack_a && (*stack_a)->next)
		ft_sa(stack_a, 0);
	if (*stack_b && (*stack_b)->next)
		ft_sb(stack_b, 0);
	write(1, "ss\n", 3);
}

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
	{
		last = last->next;
	}
	tmp->next = NULL;
	last->next = tmp;
	if (i == 1)
		write (1, "rb\n", 3);
}

void	ft_rr(t_ps **stack_b, t_ps **stack_a)
{
	if (*stack_b && (*stack_b)->next)
		ft_rb(stack_b, 0);
	if (*stack_a && (*stack_a)->next)
		ft_ra(stack_a, 0);
	write(1, "rr\n", 3);
}

void ft_rra(t_ps **stack_b, int i)
{
    t_ps *tmp;
    t_ps *second_last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    tmp = *stack_b;
    while (tmp->next != NULL)
    {
        second_last = tmp;  // Keep track of the second last node
        tmp = tmp->next;
    }
    second_last->next = NULL;  // Break the link to form a proper ending
    tmp->next = *stack_b;  // Move the last node to the front
    *stack_b = tmp;  // Update the stack to point to the new front node
    if (i == 1)
        write(1, "rrb\n", 4);
}

void	ft_rrr(t_ps **stack_b, t_ps **stack_a)
{
	if (*stack_a && (*stack_a)->next)
		ft_rra(stack_a, 0);
	if (*stack_b && (*stack_b)->next)
		ft_rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
