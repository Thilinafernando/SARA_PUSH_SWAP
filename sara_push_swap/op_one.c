#include "push_swap.h"

void	ft_pa(t_ps **stack_a, t_ps **stack_b)
{
	t_ps	*tmp;

	if (*stack_b == NULL)
		return; // Nothing to push
	tmp = *stack_b; // Save the top element of stack_b
	*stack_b = (*stack_b)->next; // Move stack_b to the next element
	tmp->next = *stack_a; // Add the saved element to the top of stack_a
	*stack_a = tmp;
	write(1, "pa\n", 3); // Print the operation
}

void	ft_pb(t_ps **stack_b, t_ps **stack_a)
{
	t_ps	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}

void	ft_rra(t_ps **stack_a, int i)
{
	t_ps *tmp;
	t_ps *second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		second_last = tmp;  // Keep track of the second last node
		tmp = tmp->next;
	}
	second_last->next = NULL;  // Break the link to form a proper ending
	tmp->next = *stack_a;  // Move the last node to the front
	*stack_a = tmp;  // Update the stack to point to the new front node
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_ps **stack_b, int i)
{
	t_ps	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
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
