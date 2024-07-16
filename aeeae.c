/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aeeae.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:56:55 by matesant          #+#    #+#             */
/*   Updated: 2024/07/16 17:05:09 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int main(void)
{
	float ra;
	float rrr;
	float atana;

	rrr = 1.0;

	ra = atan(rrr);
	atana = -1 / tan(rrr);
	printf("tan(%.2f) = %.2f\n", rrr, ra);
	printf("atan(%.2f) = %.2f\n", rrr, atana);
	return (0);
}
