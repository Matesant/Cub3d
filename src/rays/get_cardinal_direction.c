/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cardinal_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:33:48 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 19:24:08 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_is_south(float angle)
{
	if (angle > 0 && angle < PI)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_north(float angle)
{
	if (angle > PI && angle < (PI * 2))
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_west(float angle)
{
	if (angle > (PI / 2) && angle < 3 * PI / 2)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_east(float angle)
{
	if (angle < (PI / 2) || angle > 3 * PI / 2)
		return (TRUE);
	return (FALSE);
}
