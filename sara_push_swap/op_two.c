#include "push_swap.h"

void	ft_sa(t_ps **stack_a, int i)
{
	t_ps	*first;
	t_ps	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_ps **stack_b, int i)
{
	t_ps	*first;
	t_ps	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_ps **stack_b, t_ps **stack_a)
{
	if (*stack_a && (*stack_a)->next)
		ft_sa(stack_a, 0);
	if (*stack_b && (*stack_b)->next)
		ft_sb(stack_b, 0);
	write(1, "ss\n", 3);
}

int	find_max_position(t_ps *stack)
{
	t_ps	*tmp;
	int		max;
	int		max_pos;
	int		current_pos;

	tmp = stack;
	max = tmp->num;
	max_pos = 0;
	current_pos = 0;
	while (tmp)
	{
		if (tmp->num > max)
		{
			max = current_pos;
			max = tmp->num;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return (max_pos);
}

int	max_len(int max)
{
	int	len;

	len = 0;
	while(max)
	{
		max >>= 1;
		len++;
	}
	return (len);
}
