/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:30:13 by matesant          #+#    #+#             */
/*   Updated: 2024/07/18 00:44:20 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_abs_between(int a, int b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}

float	ft_fabs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}
