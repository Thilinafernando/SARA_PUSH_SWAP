/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:18:11 by sel-khao          #+#    #+#             */
/*   Updated: 2025/04/12 14:55:01 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

char	**split_arg(char **av)
{
	char	**mat;
	int		i;

	i = 0;
	mat = ft_split(av[1], 32);
	if(mat == NULL)
		return(NULL);
	while(mat[i])
		i++;
	if(check_two(mat) == 1)
		return (free_mat(mat), mat = NULL, NULL);
	return (mat);
}

void	proccess(t_ps **stack_a, t_ps **stack_b, int i, int argc)
{
	if (argc == 3 || i == 2)
		return (two_sort((stack_a)));
	else if (argc == 4 || i == 3)
		three_args(stack_a);
	else if (argc <= 11 || i <= 10)
		five_algo(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	last(t_ps **stack_a, t_ps **stack_b)
{
	if ((is_sorted((*stack_a)) != 1) || (*stack_b))
	{
		fft_lstclear(stack_a);
		return (write(2, "Not sorted\n", 11), -1);
	}
	fft_lstclear(stack_a);
	fft_lstclear(stack_b);
	return (0);
}

int	checks_main(t_ps **s_a, char **av,int ac, int i)
{
	if (ac == 2)
	{
		i = two_args(s_a, av);
		if (i == -1)
			return ( -1);
		if (i == 42)
			return (42);
	}
	else
	{
		i = more_args(s_a, av, ac);
		if (i == -1)
			return (-1);
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	t_ps	*stack_a;
	t_ps	*stack_b;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (write(2, "Error\n", 6), 1);
	i = checks_main(&stack_a, argv, argc, i);
	if (i == -1)
		return (write(2, "Error\n", 6), 1);
	if (i == 42)
		return (0);
	if (is_sorted(stack_a) == 1)
	{
		fft_lstclear(&stack_a);
		return(0);
	}
	proccess(&stack_a, &stack_b, i, argc);
	if (last(&stack_a, &stack_b) == -1)
		return (write(2, "Error\n", 6), 1);
	return (0);
}

/* void	print_lst(t_ps *swap)
{
	t_ps	*tmp;

	tmp = swap;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			printf("%d\n", tmp -> num);
			break ;
		}
		printf("%d--", tmp -> num);
		tmp = tmp -> next;
	}
} */
