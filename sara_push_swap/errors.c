/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:33:07 by sel-khao          #+#    #+#             */
/*   Updated: 2025/04/12 14:45:21 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	vali_num(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') &&((argv[i][j] != '+' && argv[i][j] != '-') ||
				(j == 0 && (!(argv[i][j + 1] >= '0' || argv[i][j + 1] <= '9'))) ||
				!(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')))
				return (1);
			j++;
		}
		if (fft_atoi(argv[i]) > INT_MAX || fft_atoi(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	checkdup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (vali_num(argc, argv) == 1)
		return (1);
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (fft_atoi(argv[i]) == fft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	vali_two(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') &&((argv[i][j] != '+' && argv[i][j] != '-') ||
				(j == 0 && (!(argv[i][j + 1] >= '0' || argv[i][j + 1] <= '9'))) ||
				!(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')))
				return (1);
			j++;
		}
		if (fft_atoi(argv[i]) > INT_MAX || fft_atoi(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_two(char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (vali_two(argv) == 1)
		return (1);
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (fft_atoi(argv[i]) == fft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	are_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] >= '0' && arg[i] <= '9'))
			return (1);
		i++;
	}
	return (-1);
}
