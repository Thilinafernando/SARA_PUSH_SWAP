/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:11:41 by sara              #+#    #+#             */
/*   Updated: 2025/04/12 14:56:54 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	two_args(t_ps **stack_a, char **argv)
{
	char	**matrix;
	int		i;
	int		n;

	i = 0;
	if (!argv[1][0])
		return (-1);
	if (are_num(argv[1]) == -1)
		return(-1);
	matrix = split_arg(argv);
	if (!matrix)
		return (-1);
	while(matrix[i])
	{
		n = fft_atoi(matrix[i]);
		fft_lstadd_back(stack_a, fft_lstnew(n));
		i++;
	}
	if (i == 1)
		return (free_mat(matrix) ,fft_lstclear(stack_a), 42);
	free_mat(matrix);
	return (i);
}

int	more_args(t_ps **stack_a, char **argv, int argc)
{
	int	j;
	int	n;

	j = 1;
	if (checkdup(argc, argv) != 0)
		return (-1);
	while (j < argc)
	{
		n = fft_atoi(argv[j]);
		fft_lstadd_back(stack_a, fft_lstnew(n));
		j++;
	}
	return (argc - 1);
}

long	fft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

void	free_mat(char **mat)
{
	int i;

	i = 0;
	if (!mat)
		return (free(mat));
	while (mat[i] != NULL)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int	is_sorted(t_ps *stack)
{
	int		num;
	t_ps	*tmp;

	tmp = stack;
	num = 0;
	while (tmp && tmp->next)
	{
		if (tmp->num < tmp->next->num)
		{
			num = 1;
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (num);
}
